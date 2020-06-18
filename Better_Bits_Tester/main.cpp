#include <iostream>
#include <iomanip>

#include "BetterBits.hpp"

int main()
{
	std::cout << "Demo:\n";
	std::cout << std::setw(14) << std::left << "Original: " << bb::bin << 166U << '\n';
	std::cout << std::setw(14) << std::left << "Left nibble: " << bb::bin << bb::split(166U).left << '\n';
	std::cout << std::setw(18) << std::left << "Right nibble: " << bb::bin << bb::split(166U).right << '\n';
	std::cout << std::setw(14) << std::left << "Reversed: " << bb::bin << bb::reverse(166U) << '\n';
	std::cout << std::setw(14) << std::left << "Flipped: " << bb::bin << bb::flip(166U) << '\n';
	std::cout << "Hex: " << bb::hex << 166U << '\n';
	std::cout << '\n';
	std::cout << "9999:\n";
	std::cout << "bytes in use: " << bb::bytesInUse(9999U) << '\n';
	std::cout << std::setw(15) << std::left << "(unlocked):" << bb::bin << 9999U << '\n';
	std::cout << std::setw(15) << std::left << "(locked-bit):    " << bb::bin_b << 9999U << '\n';
	std::cout << std::setw(15) << std::left << "(locked-byte): " << bb::bin_B << 9999U << '\n';
	std::cout << std::setw(15) << std::left << "1st Byte: " << bb::bin_B << bb::nthByte(9999U, 1) << '\n';
	std::cout << std::setw(24) << std::left << "2nd Byte: " << bb::bin_B << bb::nthByte(9999U, 2) << '\n';
	std::cout << '\n';
	std::cout << "ULONG_MAX in binary: " << bb::bin << ULONG_MAX << '\n';
	std::cout << "ULONG_MAX in hex: " << bb::hex << ULONG_MAX << '\n';
}