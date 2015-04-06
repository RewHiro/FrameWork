#pragma once
#include "Uncopyable.h"
#include <memory>

class Resource;

//�@�V�[���̎��
enum class SceneType{
	TITLE,
	STAGE,
	RESULT,
};

//
//�@�V�[��(���ۃN���X)
//
class Scene : private Uncopyable
{
	SceneType type;
protected:
	//�@���݂̃V�[���̎�ނ��擾
	SceneType Type()const{ return type; }
	std::shared_ptr<Resource>resource;
public:
	Scene();
	virtual ~Scene();

	//�@�X�V
	virtual SceneType Update() = 0;

	//�@�`��
	virtual void Draw() = 0;

	//�@�V�[����J�ڂ���
	void LoadScene(const SceneType type){ this->type = type; }

	//�@�g�p�֎~
	void Load(const SceneType type);
};

