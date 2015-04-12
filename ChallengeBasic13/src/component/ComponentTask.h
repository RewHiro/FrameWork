#pragma once
#include "utility/Uncopyable.h"
#include <vector>
#include <memory>

class Component;

//�@
//�@�R���|�[�l���g�^�X�N
//
class ComponentTask : private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
public:
	ComponentTask();

	void Start()const;
	void Update()const;

	//�@�ǉ�
	void Add(const std::shared_ptr<Component>& component);

};

