#pragma once

namespace bb {
	struct hex_proxy {
	private:
		std::ostream& os;

	public:
		hex_proxy(std::ostream& os);

		template<typename T>
		friend std::ostream& operator<<(hex_proxy const& proxy, T data) {
			// Dump if data is not unsigned
			if (!std::is_unsigned<T>::value) {
				return proxy.os << data;
			}

			proxy.os << std::hex << "0x" << data;

			return proxy.os;
		}
	};

	struct hex_creator {};
	extern hex_creator hex;

	hex_proxy operator<<(std::ostream& os, hex_creator);
}