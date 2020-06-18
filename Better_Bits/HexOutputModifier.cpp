#include "pch.h"
#include "HexOutputModifier.h"

namespace bb {
	hex_proxy::hex_proxy(std::ostream& os) : os(os)
	{}

	hex_creator hex{};

	hex_proxy operator<<(std::ostream& os, hex_creator)
	{
		return hex_proxy(os);
	}
}