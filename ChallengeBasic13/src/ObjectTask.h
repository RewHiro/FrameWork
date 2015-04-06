#pragma once
#include "Uncopyable.h"
#include <forward_list>
#include <memory>

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

	//�@Start�֐������s����O�Ɏ��s�����
	void Awake();

	//�@Update�֐������s����O�Ɏ��s�����
	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�I�u�W�F�N�g�ꗗ�̑S�폜
	void Clear();

	//�@�폜
	void Erase();
};

