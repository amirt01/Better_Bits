#pragma once

#include "Constants.hpp"
#include "Counters.hpp"

namespace bb {
	struct BinCreator {
		enum class Modes {
			UNLOCKED = 0,
			LOCKED_BIT,
			LOCKED_BYTE
		} mode;
	};

	extern BinCreator bin;
	extern BinCreator bin_b;
	extern BinCreator bin_B;

	struct BinProxy {
	private:
		BinCreator::Modes mode;
		std::ostream& os;

	public:
		BinProxy(BinCreator::Modes mode, std::ostream& os);

		template<typename T>
		friend std::ostream& operator<<(BinProxy const& proxy, T data) {
			// Dump if data is not unsigned
			if (!std::is_unsigned<T>::value) {
				return proxy.os << data;
			}

			// Only output one nibble if the size of data is
			// less than or equal to the maximum size of one
			// nibble and the user wants to have the output
			// adjust automatically or locked to one nibble
			// in length.
			if (proxy.mode == BinCreator::Modes::UNLOCKED && data <= NIBBLE_MAX) {
				for (size_t bit = NIBBLE_BIT; bit > 0; bit--) {
					proxy.os << ((data >> (bit - 1)) & 1);
				}
			}
			else if (proxy.mode == BinCreator::Modes::LOCKED_BIT) {
				for (size_t bit = bb::bitsInUse<T>(data); bit > 0; bit--) {
					if (bit % CHAR_BIT == 0 && bit != bb::bitsInUse<T>(data)) {
						proxy.os << ' ';
					}
					proxy.os << ((data >> (bit - 1)) & 1);
				}
			}
			else if (proxy.mode == BinCreator::Modes::UNLOCKED || proxy.mode == BinCreator::Modes::LOCKED_BYTE) {
				for (size_t byte = bb::bytesInUse<T>(data) * CHAR_BIT; byte > 0; byte--) {
					if (byte % CHAR_BIT == 0 && byte != bb::bytesInUse<T>(data) * CHAR_BIT) {
						proxy.os << ' ';
					}
					proxy.os << ((data >> (byte - 1)) & 1);
				}
			}
			return proxy.os;
		}
	};

	BinProxy operator<<(std::ostream& os, BinCreator);
}