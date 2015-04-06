#pragma once
#include "Uncopyable.h"
#include "Resource.h"
#include "Scene.h"
#include <memory>

class ResourceFactory : private Uncopyable
{
	ResourceFactory() = default;
public:
	static ResourceFactory& GetInstance();
	std::shared_ptr<Resource> Create(const SceneType type);
};

