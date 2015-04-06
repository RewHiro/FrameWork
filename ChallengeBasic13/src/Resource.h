#pragma once
#include "Uncopyable.h"
#include "lib\texture.hpp"
#include "lib\audio.hpp"
#include <vector>
#include <unordered_map>

//
//　リソース(抽象クラス)
//　

class Resource : private Uncopyable
{
protected:
	std::unordered_map<std::string, Texture> texture_list;
	std::unordered_map<std::string, std::vector<Texture>>animation_list;
	std::unordered_map<std::string, Media>bgm_list;
	std::unordered_map<std::string, Media>se_list;

	static std::string TexturePath(){
		static std::string texture_path = "res/texture/";
		return texture_path;
	}
	static std::string SoundPath(){
		static std::string sound_path = "res/sound/";
		return sound_path;
	}

public:
	Resource() = default;
	virtual ~Resource(){
		//texture_list.clear();
		//animation_list.clear();
		//bgm_list.clear();
		//se_list.clear();
	}

	//　テクスチャを取得
	const Texture& TextureFind(const std::string& name)const{
		return texture_list.find(name)->second;
	}

	//　アニメーション(テクスチャの配列)を取得
	const std::vector<Texture>& AnimationFind(const std::string& name)const{
		return animation_list.find(name)->second;
	}

	//　アニメーション(番号)を取得
	const Texture& AnimationFind(const std::string& name,int animation_num)const{
		return animation_list.find(name)->second.at(animation_num);
	}

	//　BGMを取得
	const Media& BGMFind(const std::string& name)const {
		return bgm_list.find(name)->second;
	}

	//　SEを取得
	const Media& SEFind(const std::string& name)const {
		return se_list.find(name)->second;
	}
};

using TEXTURE_MAP = std::unordered_map<std::string, Texture>;
using ANIMATION_MAP = std::unordered_map < std::string, std::vector<Texture> > ;
using BGM_MAP = std::unordered_map < std::string, Media > ;
using SE_MAP = std::unordered_map < std::string, Media > ;
