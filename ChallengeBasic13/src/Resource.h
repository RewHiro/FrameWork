#pragma once
#include "Uncopyable.h"
#include "lib\texture.hpp"
#include "lib\audio.hpp"
#include <vector>
#include <unordered_map>

class Resource : private Uncopyable
{
protected:
	std::unordered_map<std::string, Texture>texture_list;
	std::unordered_map<std::string, std::vector<Texture>>animation_list;
	std::unordered_map<std::string, Media>bgm_list;
	std::unordered_map<std::string, Media>se_list;
	const std::string TEXTURE_PATH = "res/texture/";
	const std::string SOUND_PATH = "res/sound/";
public:
	Resource() = default;
	virtual ~Resource() = default;

	Texture TextureFind(const std::string& name)const{
		return texture_list.find(name)->second;
	}

	std::vector<Texture> AnimationFind(const std::string& name)const{
		return animation_list.find(name)->second;
	}

	Texture AnimationFind(const std::string& name,int animation_num)const{
		return animation_list.find(name)->second.at(animation_num);
	}

	Media BGMFind(const std::string& name)const {
		return bgm_list.find(name)->second;
	}

	Media SEFind(const std::string& name)const {
		return se_list.find(name)->second;
	}
};

