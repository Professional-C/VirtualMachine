#pragma once
#include "Ops.h"
#include <memory>
#include <vector>

class Machine
{
public:
	Machine();

private:
	std::vector<std::shared_ptr<Op>> mOps;
};
