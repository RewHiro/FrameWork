#pragma once
#include "utility/Uncopyable.h"
#include "Resource.h"
#include "scene/Scene.h"
#include <memory>

class ResourceFactory : private Uncopyable
{
	ResourceFactory() = default;
public:
	static ResourceFactory& GetInstance();
	std::shared_ptr<Resource> Create(const SceneType type);
};

