#include "Fixed.hpp"
#include <cassert>

static void	testOperators(void)
{
	Fixed	counter;

	Fixed a(1.5f);
	Fixed b(2);
	Fixed same(1.5f);
	assert(a < b);
	assert(b > a);
	assert(a <= b);
	assert(b >= a);
	assert(a <= same);
	assert(a >= same);
	assert(a == same);
	assert(a != b);
	assert(!(a > b));
	assert(!(a >= b));
	assert(!(b < a));
	assert(!(b <= a));
	assert(!(a == b));
	assert(!(a != same));
	assert(a + b == Fixed(3.5f));
	assert(a - b == Fixed(-0.5f));
	assert(a * b == Fixed(3));
	assert(a / b == Fixed(0.75f));
	assert((++counter).getRawBits() == 1);
	assert(counter.getRawBits() == 1);
	assert((counter++).getRawBits() == 1);
	assert(counter.getRawBits() == 2);
	assert((--counter).getRawBits() == 1);
	assert(counter.getRawBits() == 1);
	assert((counter--).getRawBits() == 1);
	assert(counter.getRawBits() == 0);
	assert(&(++counter) == &counter);
	assert(&(--counter) == &counter);
	assert(&Fixed::min(a, b) == &a);
	assert(&Fixed::max(a, b) == &b);
	const Fixed c(3);
	const Fixed d(4);
	assert(&Fixed::min(c, d) == &c);
	assert(&Fixed::max(c, d) == &d);
	std::cout << "All tests passed." << std::endl;
}

int	main(int argc, char **argv)
{
	Fixed	a;

	(void)argv;
	if (argc > 1)
	{
		testOperators();
		return (0);
	}
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}
