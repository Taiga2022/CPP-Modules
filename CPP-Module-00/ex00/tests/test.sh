#!/bin/sh

set -eu

PROGRAM=${1:-./megaphone}
passed=0
failed=0

check_output()
{
	name=$1
	expected=$2
	shift 2
	actual=$($PROGRAM "$@")

	if [ "$actual" = "$expected" ]; then
		printf 'ok - %s\n' "$name"
		passed=$((passed + 1))
	else
		printf 'not ok - %s\n' "$name"
		printf '  expected: <%s>\n' "$expected"
		printf '  actual:   <%s>\n' "$actual"
		failed=$((failed + 1))
	fi
}

check_output \
	'no arguments prints feedback noise' \
	'* LOUD AND UNBEARABLE FEEDBACK NOISE *'
check_output \
	'official single-argument example' \
	'SHHHHH... I THINK THE STUDENTS ARE ASLEEP...' \
	'shhhhh... I think the students are asleep...'
check_output \
	'official multiple-argument example' \
	'DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.' \
	'Damnit' ' ! ' 'Sorry students, I thought this thing was off.'
check_output \
	'digits and punctuation are preserved' \
	'42!? CPP' \
	'42!? cpp'
check_output \
	'empty argument produces an empty line' \
	'' \
	''

if "$PROGRAM" >/dev/null 2>&1; then
	printf 'ok - program exits successfully\n'
	passed=$((passed + 1))
else
	printf 'not ok - program exits successfully\n'
	failed=$((failed + 1))
fi

printf '%d passed, %d failed\n' "$passed" "$failed"

[ "$failed" -eq 0 ]

