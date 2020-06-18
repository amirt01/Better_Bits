#pragma once

#include "Constants.hpp"

namespace bb {
	struct bin_proxy {
	private:
		std::ostream& os;

	public:
		bin_proxy(std::ostream& os);

		template<typename T>
		friend std::ostream& operator<<(bin_proxy const& proxy, T data) {
			// Dump if data is not unsigned
			if (!std::is_unsigned<T>::value) {
				return proxy.os << data;
			}

			// Check if the size of the data fits in one Nibble.
			// Count the number of nibbles necessary to output.
			// This is used for making sure we don't display
			// more bytes than are used and for formatting.
			size_t nibblesInUse = 0;
			for (size_t nibbles = 0; nibbles < sizeof(unsigned) * 2; nibbles++) {
				if (((data >> nibbles * NIBBLE_MAX) & 0xf) != 0) {
					nibblesInUse++;
				}
			}

			for (size_t bit = nibblesInUse * NIBBLE_MAX; bit > 0; bit--) {
				if (bit % CHAR_BIT == 0 && bit != nibblesInUse * NIBBLE_MAX) {
					proxy.os << ' ';
				}
				proxy.os << ((data >> (bit - 1)) & 1);
			}
			return proxy.os;
		}
	};

	struct bin_creator {};
	extern bin_creator bin;

	bin_proxy operator<<(std::ostream& os, bin_creator);
}