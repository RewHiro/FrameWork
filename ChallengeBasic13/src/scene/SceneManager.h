#pragma once
#include "Scene.h"

//
//�@�V�[���Ǘ�(�V���O���g�[��)
//

class SceneManager : private Uncopyable
{
	SceneManager();

	SceneType type;
	std::shared_ptr<Resource>resource;
	std::unique_ptr<Scene> scene;
	
	//�@�V�[���̐���
	std::unique_ptr<Scene> Create(const SceneType type);
public:
	//�@�C���X�^���X�̎擾
	static SceneManager& SceneManager::GetInstance(){
		static SceneManager scene_manager;
		return scene_manager;
	}

	//�@���\�[�X�̎擾
	const Resource& GetResource()const{
		return *resource.get();
	}

	//�@�V�[���̃^�C�v���擾
	SceneType GetType()const{
		return type;
	}

	//�@�X�V
	void Update();
private:
};