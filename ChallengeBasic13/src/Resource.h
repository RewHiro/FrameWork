#pragma once
#include "Uncopyable.h"
class Resource : private Uncopyable
{
public:
	Resource() = default;
	virtual ~Resource() = default;
};

