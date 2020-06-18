#pragma once

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
	unsigned int flip(T byte_value) {
		if (!std::is_unsigned<T>::value && byte_value > UCHAR_MAX) {
			throw("SPLIT::VALUE_WAS_INVALID");
		}

		byte_value = (byte_value & 0xF0) >> 4 | (byte_value & 0x0F) << 4;
		byte_value = (byte_value & 0xCC) >> 2 | (byte_value & 0x33) << 2;
		byte_value = (byte_value & 0xAA) >> 1 | (byte_value & 0x55) << 1;

		return byte_value;
	}
}