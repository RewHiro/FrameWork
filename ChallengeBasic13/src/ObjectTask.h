#pragma once
#include "Uncopyable.h"
#include <forward_list>
#include <memory>
#include <stack>

class Object;

//
//�@�I�u�W�F�N�g�^�X�N
//

class ObjectTask : private Uncopyable
{
	std::forward_list<std::shared_ptr<Object>>objects;
public:
	ObjectTask();
	//�@�ǉ�
	void Add(const std::string& name, std::shared_ptr<Object>object);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�I�u�W�F�N�g�ꗗ�̑S�폜
	void Clear();

	//�@�폜
	void Erase();

	//�@�I�u�W�F�N�g�j�󃊃X�g�擾
	std::stack<std::shared_ptr<Object>>& GetDeleteList(){
		static std::stack<std::shared_ptr<Object>>delete_list;
		return delete_list;
	}

};

