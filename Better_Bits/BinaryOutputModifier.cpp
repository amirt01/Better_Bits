#include "pch.h"
#include "BinaryOutputModifier.hpp"

namespace bb {
	bin_proxy::bin_proxy(std::ostream& os) : os(os)
	{}

	bin_creator bin{};

	bin_proxy operator<<(std::ostream& os, bin_creator)
	{
		return bin_proxy(os);
	}
}