#pragma once

namespace bb {
	template <typename T>
	constexpr size_t bytesInUse(T data) {
		size_t bytesInUse = sizeof(T);
		for (size_t bytes = sizeof(T); bytes > 0; bytes--) {
			if (((data >> bytes * CHAR_BIT) & UCHAR_MAX) == 0) {
				bytesInUse--;
			}
		}
		return bytesInUse;
	}

	template <typename T>
	constexpr size_t bitsInUse(T data) {
		size_t bitsInUse = sizeof(T) * CHAR_BIT;
		for (size_t bits = sizeof(T) * CHAR_BIT; bits > 0; bits--) {
			if (((data >> bits) & UCHAR_MAX) == 0) {
				bitsInUse--;
			}
		}
		return bitsInUse;
	}
}