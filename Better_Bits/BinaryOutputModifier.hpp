#pragma once

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

			// Count the number of bytes necessary to output.
			// This is used for making sure we don't display
			// more bytes than are used and for formatting.
			size_t bytesInUse = 0;
			for (size_t bytes = 0; bytes < sizeof(unsigned); bytes++) {
				if (((data >> bytes * CHAR_BIT) & 0xff) != 0) {
					bytesInUse++;
				}
			}

			for (size_t bit = bytesInUse * CHAR_BIT; bit > 0; bit--) {
				if (bit % CHAR_BIT == 0 && bit != bytesInUse * CHAR_BIT) {
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