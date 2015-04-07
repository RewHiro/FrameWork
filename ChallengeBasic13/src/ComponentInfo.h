#pragma once
#include "Uncopyable.h"
#include <unordered_map>
#include <memory>

class Component;

//
//　コンポーネント情報
//

class ComponentInfo :
	private Uncopyable
{
	std::unordered_map<std::string, std::shared_ptr<Component>>component_list;
public:
	ComponentInfo();

	//　追加
	void Add(std::shared_ptr<Component>component);

	//　検索
	const std::shared_ptr<Component> Find(const std::string& name)const;
};

