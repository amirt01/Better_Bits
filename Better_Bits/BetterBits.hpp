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
	constexpr Nibbles split(T data) {
		if (!std::is_unsigned<T>::value && data > UCHAR_MAX) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		return Nibbles{ static_cast<unsigned int>(data >> 4), static_cast<unsigned int>(data & 0xF) };
	}

	template <typename T>
	constexpr T reverse(T data) {
		if (!std::is_unsigned<T>::value && data > UCHAR_MAX) {
			throw("REVERSE::VALUE_WAS_INVALID");
		}

		data = (data & 0xF0) >> 4 | (data & 0x0F) << 4;
		data = (data & 0xCC) >> 2 | (data & 0x33) << 2;
		data = (data & 0xAA) >> 1 | (data & 0x55) << 1;

		return data;
	}

	template <typename T>
	constexpr T flip(T data) {
		if (!std::is_unsigned<T>::value) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		for (size_t i = 0; i < bytesInUse<T>(data) * CHAR_BIT; i++) {
			data ^= (T(1) << i);
		}

		return data;
	}

	template<typename T>
	constexpr unsigned nthByte(T data, size_t position) {
		if (!std::is_unsigned<T>::value) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		return (data >> (position - 1) * CHAR_BIT) & UCHAR_MAX;
	}
}