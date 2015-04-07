#pragma once
#include "Uncopyable.h"
#include "lib\texture.hpp"
#include "lib\audio.hpp"
#include <vector>
#include <unordered_map>

//
//�@���\�[�X(���ۃN���X)
//�@

class Resource : private Uncopyable
{
protected:
	std::unordered_map<std::string, Texture> texture_list;
	std::unordered_map<std::string, std::vector<Texture>>animation_list;
	std::unordered_map<std::string, Media>bgm_list;
	std::unordered_map<std::string, Media>se_list;

public:
	Resource() = default;
	virtual ~Resource() = default;

	//�@�e�N�X�`�����擾
	const Texture& TextureFind(const std::string& name)const{
		return texture_list.find(name)->second;
	}

	//�@�A�j���[�V����(�e�N�X�`���̔z��)���擾
	const std::vector<Texture>& AnimationFind(const std::string& name)const{
		return animation_list.find(name)->second;
	}

	//�@�A�j���[�V����(�ԍ�)���擾
	const Texture& AnimationFind(const std::string& name,int animation_num)const{
		return animation_list.find(name)->second.at(animation_num);
	}

	//�@BGM���擾
	const Media& BGMFind(const std::string& name)const {
		return bgm_list.find(name)->second;
	}

	//�@SE���擾
	const Media& SEFind(const std::string& name)const {
		return se_list.find(name)->second;
	}
};

using TEXTURE_MAP = std::unordered_map<std::string, Texture>;
using ANIMATION_MAP = std::unordered_map < std::string, std::vector<Texture> > ;
using BGM_MAP = std::unordered_map < std::string, Media > ;
using SE_MAP = std::unordered_map < std::string, Media > ;
