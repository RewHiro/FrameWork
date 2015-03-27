#include "ResourceTitle.h"


ResourceTitle::ResourceTitle()
{
	std::unordered_map<std::string, Texture>add_texture_list = {
		{
			"bg",
			Texture(TEXTURE_PATH + "game_bg.png")
		}
	};


	std::vector<Texture>textures = {
		Texture(TEXTURE_PATH + "miku_1.png"),
		Texture(TEXTURE_PATH + "miku_2.png"),
		Texture(TEXTURE_PATH + "miku_3.png"),
		Texture(TEXTURE_PATH + "miku_4.png"),
		Texture(TEXTURE_PATH + "miku_5.png"),
		Texture(TEXTURE_PATH + "miku_6.png")
	};

	std::unordered_map<std::string, std::vector<Texture>>add_animation_list = {
		{
			"miku",
			textures
		}
	};

	std::unordered_map<std::string, Media>add_se_list = {
		{
			"hit",
			Media(SOUND_PATH + "hit.wav")
		}
	};

	std::unordered_map<std::string, Media>add_bgm_list = {
		{
			"title",
			Media(SOUND_PATH + "title_bgm.wav")
		}
	};

	texture_list = add_texture_list;
	animation_list = add_animation_list;
	bgm_list = add_bgm_list;
	se_list = add_se_list;
}