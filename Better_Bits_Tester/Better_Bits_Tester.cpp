#include <iostream>

#include "BetterBits.hpp"
#include "BinaryOutputModifier.hpp"

int main()
{
	std::cout << "Left nibble flipped: " << bb::bin << bb::flip(bb::split(0xff).right) << '\n';
	std::cout << "100 in binary: " << bb::bin << 100U << '\n';
}