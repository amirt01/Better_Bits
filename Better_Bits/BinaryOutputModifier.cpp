#include "pch.h"
#include "BinaryOutputModifier.hpp"

namespace bb {
	BinCreator bin{ BinCreator::Modes::UNLOCKED };
	BinCreator bin_b{ BinCreator::Modes::LOCKED_BIT };
	BinCreator bin_B{ BinCreator::Modes::LOCKED_BYTE };

	BinProxy::BinProxy(BinCreator::Modes mode, std::ostream& os) : mode(mode), os(os) {}

	BinProxy operator<<(std::ostream& os, BinCreator creator) {
		return BinProxy(creator.mode, os);
	}
}