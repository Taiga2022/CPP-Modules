#!/bin/sh

set -eu

PROGRAM=${1:-./phonebook}
passed=0
failed=0
tmp_dir=$(mktemp -d "${TMPDIR:-/tmp}/phonebook-test.XXXXXX")

cleanup()
{
	rm -rf "$tmp_dir"
}
trap cleanup EXIT HUP INT TERM

pass()
{
	printf 'ok - %s\n' "$1"
	passed=$((passed + 1))
}

fail()
{
	printf 'not ok - %s\n' "$1"
	shift
	for message in "$@"; do
		printf '  %s\n' "$message"
	done
	failed=$((failed + 1))
}

run_phonebook()
{
	name=$1
	input=$2
	output="$tmp_dir/$name.out"

	if printf '%s' "$input" | "$PROGRAM" >"$output" 2>&1; then
		RUN_OUTPUT=$output
		return 0
	fi
	fail "$name exits successfully" "see output: $output"
	RUN_OUTPUT=$output
	return 1
}

assert_contains()
{
	name=$1
	expected=$2
	if grep -F -- "$expected" "$RUN_OUTPUT" >/dev/null; then
		pass "$name"
	else
		fail "$name" "missing: <$expected>" "output: $RUN_OUTPUT"
	fi
}

assert_not_contains()
{
	name=$1
	unexpected=$2
	if grep -F -- "$unexpected" "$RUN_OUTPUT" >/dev/null; then
		fail "$name" "unexpected: <$unexpected>" "output: $RUN_OUTPUT"
	else
		pass "$name"
	fi
}

if [ ! -x "$PROGRAM" ]; then
	printf 'error: executable not found: %s\n' "$PROGRAM" >&2
	printf 'usage: %s [path/to/phonebook]\n' "$0" >&2
	exit 2
fi

# EXIT must work immediately on a fresh phone book.
if run_phonebook exit 'EXIT
'; then
	pass 'EXIT terminates the program successfully'
fi

# ADD followed by SEARCH must list the contact and show all five fields.
if run_phonebook add_search 'ADD
Ada
Lovelace
Enchantress
123-456-789
Analytical Engine
SEARCH
0
EXIT
'; then
	assert_contains 'SEARCH lists the first name' 'Ada'
	assert_contains 'SEARCH lists the last name' 'Lovelace'
	assert_contains 'SEARCH lists the nickname' 'Enchantress'
	assert_contains 'valid index shows the phone number' '123-456-789'
	assert_contains 'valid index shows the darkest secret' 'Analytical Engine'
fi

# The row below checks width 10, right alignment, separators, and truncation.
if run_phonebook table_format 'ADD
12345678901
Li
N
42
secret
SEARCH
0
EXIT
'; then
	assert_contains \
		'SEARCH formats and truncates all columns correctly' \
		'         0|123456789.|        Li|         N'
fi

# Whether an implementation re-prompts or cancels ADD, an empty field must not
# result in the partially entered contact being searchable.
if run_phonebook empty_field 'ADD
EmptyFirst
EmptyLast
EmptyNick
EmptyPhone

SEARCH
0
EXIT
'; then
	assert_not_contains 'ADD does not save a contact with an empty field' 'EmptyFirst'
fi

# Invalid indices must not terminate the command loop.  The second SEARCH proves
# that the program is still responsive and that the original contact is intact.
if run_phonebook invalid_indices 'ADD
Grace
Hopper
AmazingGrace
555
Compiler pioneer
SEARCH
abc
SEARCH
8
SEARCH
-1
SEARCH
0
EXIT
'; then
	assert_contains 'invalid SEARCH indices do not terminate the program' 'Compiler pioneer'
fi

# A ninth ADD overwrites the oldest of the eight contacts.  Slot 0 should now
# contain NewestFirst while slots 1 through 7 remain present.
if run_phonebook capacity 'ADD
OldestFirst
Last0
Nick0
Phone0
Secret0
ADD
First1
Last1
Nick1
Phone1
Secret1
ADD
First2
Last2
Nick2
Phone2
Secret2
ADD
First3
Last3
Nick3
Phone3
Secret3
ADD
First4
Last4
Nick4
Phone4
Secret4
ADD
First5
Last5
Nick5
Phone5
Secret5
ADD
First6
Last6
Nick6
Phone6
Secret6
ADD
First7
Last7
Nick7
Phone7
Secret7
ADD
NewestFirst
NewestLast
NewestNick
NewestPhone
NewestSecret
SEARCH
0
EXIT
'; then
	assert_not_contains 'the ninth contact removes the oldest contact' 'OldestFirst'
	assert_contains 'the ninth contact is stored' 'NewestFirst'
	assert_contains 'the ninth contact overwrites index 0' '         0|NewestFir.|NewestLast|NewestNick'
	assert_contains 'an existing contact remains after overwrite' 'First7'
fi

# Commands other than ADD, SEARCH and EXIT are ignored.
if run_phonebook unknown_command 'UNKNOWN
add
SEARCHING
ADD
Alan
Turing
Prof
101
Enigma
SEARCH
0
EXIT
'; then
	assert_contains 'unknown commands are ignored and the loop continues' 'Enigma'
fi

# End-of-file should be handled cleanly instead of leaving an infinite loop.
if run_phonebook eof ''; then
	pass 'EOF terminates the program successfully'
fi

printf '%d passed, %d failed\n' "$passed" "$failed"

[ "$failed" -eq 0 ]
