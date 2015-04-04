#pragma once
#include "Uncopyable.h"
#include <vector>
#include <unordered_map>
#include <memory>

class Component;

class ComponentTask : private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
public:
	ComponentTask();

	void Start();
	void Update();

	void Add(std::shared_ptr<Component>component);

};

