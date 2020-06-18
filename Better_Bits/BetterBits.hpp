#pragma once

#include "Constants.hpp"
#include "BinaryOutputModifier.hpp"
#include "HexOutputModifier.h"

namespace bb {
	struct Nibbles {
	public:
		unsigned int left : 4;
		unsigned int right : 4;
	};

	template <typename T>
	Nibbles split(T byte_value) {
		if (!std::is_unsigned<T>::value && byte_value > UCHAR_MAX) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		return Nibbles{ static_cast<unsigned int>(byte_value >> 4), static_cast<unsigned int>(byte_value & 0xF) };
	}

	template <typename T>
	T reverse(T byte_value) {
		if (!std::is_unsigned<T>::value && byte_value > UCHAR_MAX) {
			throw("REVERSE::VALUE_WAS_INVALID");
		}

		byte_value = (byte_value & 0xF0) >> 4 | (byte_value & 0x0F) << 4;
		byte_value = (byte_value & 0xCC) >> 2 | (byte_value & 0x33) << 2;
		byte_value = (byte_value & 0xAA) >> 1 | (byte_value & 0x55) << 1;

		return byte_value;
	}

	template <typename T>
	T flip(T byte_value) {
		if (!std::is_unsigned<T>::value) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		// Count the number of bytes necessary to output.
		// This is used for making sure we don't display
		// more bytes than are used and for formatting.
		size_t bytesInUse = 0;
		for (size_t bytes = 0; bytes < sizeof(unsigned) * 2; bytes++) {
			if (((byte_value >> bytes * UCHAR_MAX) & 0xf) != 0) {
				bytesInUse++;
			}
		}

		for (size_t i = 0; i < bytesInUse * CHAR_BIT; i++) {
			byte_value ^= (T(1) << i);
		}

		return byte_value;
	}
}