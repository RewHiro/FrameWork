#pragma once
#include "Uncopyable.h"
#include "Resource.h"
#include "Scene.h"
#include <memory>

class ResourceFactory :
	private Uncopyable
{
public:
	ResourceFactory() = default;
	std::shared_ptr<Resource> Create(const SceneType type);
};

