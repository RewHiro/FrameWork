#pragma once
#include "Uncopyable.h"
#include <vector>
#include <memory>

class Component;

//　
//　コンポーネントタスク
//
class ComponentTask : private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
public:
	ComponentTask();

	void Start();
	void Update();

	//　追加
	void Add(const std::shared_ptr<Component>& component);

};

