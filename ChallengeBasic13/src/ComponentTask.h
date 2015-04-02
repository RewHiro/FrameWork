#pragma once
#include "Uncopyable.h"
#include <vector>
#include <unordered_map>
#include <memory>

class Component;

class ComponentTask : private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
	std::unordered_map<std::string, std::shared_ptr<Component>>component_list;
public:
	ComponentTask();

	void Start();
	void Update();

	void Add(std::shared_ptr<Component>component);

	const std::shared_ptr<Component> Find(const std::string& name)const;
};

