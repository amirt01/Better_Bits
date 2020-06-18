#include <iostream>

#include "BetterBits.hpp"

int main()
{
	std::cout << "Demo:\n";
	std::cout << "Original: " << bb::bin << 166U << '\n';
	std::cout << "Reversed: " << bb::bin << bb::reverse(166U) << '\n';
	std::cout << "Flipped: " << bb::bin << bb::flip(166U) << '\n';
	std::cout << "Hex: " << bb::hex << 166U << '\n';
	std::cout << "ULONG_MAX in binary: " << bb::bin << ULONG_MAX << '\n';
}