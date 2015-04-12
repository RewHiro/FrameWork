#pragma once
#include "utility/Uncopyable.h"
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
		assert(texture_list.count(name) != 0);
		return texture_list.find(name)->second;
	}

	//�@�A�j���[�V����(�e�N�X�`���̔z��)���擾
	const std::vector<Texture>& AnimationFind(const std::string& name)const{
		assert(animation_list.count(name) != 0);
		return animation_list.find(name)->second;
	}

	//�@�A�j���[�V����(�ԍ�)���擾
	const Texture& AnimationFind(const std::string& name,unsigned int animation_num)const{
		assert(animation_list.count(name) != 0);
		assert(animation_list.find(name)->second.size() < animation_num);
		return animation_list.find(name)->second.at(animation_num);
	}

	//�@BGM���擾
	const Media& BGMFind(const std::string& name)const {
		assert(bgm_list.count(name) != 0);
		return bgm_list.find(name)->second;
	}

	//�@SE���擾
	const Media& SEFind(const std::string& name)const {
		assert(se_list.count(name) != 0);
		return se_list.find(name)->second;
	}
};

using TEXTURE_MAP = std::unordered_map<std::string, Texture>;
using ANIMATION_MAP = std::unordered_map < std::string, std::vector<Texture> > ;
using BGM_MAP = std::unordered_map < std::string, Media > ;
using SE_MAP = std::unordered_map < std::string, Media > ;
