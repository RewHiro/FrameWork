#include "ResourceTitle.h"

ResourceTitle::ResourceTitle()
{
	texture_list.emplace("bg", Texture(TexturePath() + "game_bg.png"));
	
	std::vector<Texture>textures = {
		Texture(TexturePath() + "miku_1.png"),
		Texture(TexturePath() + "miku_2.png"),
		Texture(TexturePath() + "miku_3.png"),
		Texture(TexturePath() + "miku_4.png"),
		Texture(TexturePath() + "miku_5.png"),
		Texture(TexturePath() + "miku_6.png")
	};

	animation_list.emplace("miku", textures);
	bgm_list.emplace("title", Media(SoundPath() + "title_bgm.wav"));
	se_list.emplace("hit", Media(SoundPath() + "hit.wav"));
}