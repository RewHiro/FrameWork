#pragma once
#include "Uncopyable.h"
#include <unordered_map>
#include <memory>

class Component;

//
//�@�R���|�[�l���g���
//

class ComponentInfo :
	private Uncopyable
{
	std::unordered_map<std::string, std::shared_ptr<Component>>component_list;
public:
	ComponentInfo();

	//�@�ǉ�
	void Add(std::shared_ptr<Component>component);

	//�@����
	const std::shared_ptr<Component> Find(const std::string& name)const;
};

