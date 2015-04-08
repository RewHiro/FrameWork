#include "ResourceTitle.h"
#include "picojson.h"
#include <fstream>

ResourceTitle::ResourceTitle()
{
	std::ifstream load("res/json/scene.json");
	std::stringstream json_str;
	json_str << load.rdbuf();

	picojson::value json;
	picojson::parse(json, json_str.str());
	picojson::object& texture = json.get<picojson::object>()["title"].get<picojson::object>()["texture"].get<picojson::object>();
	picojson::object& sound = json.get<picojson::object>()["title"].get<picojson::object>()["sound"].get<picojson::object>();

	texture_list.emplace("bg", Texture(texture["background"].get<std::string>()));

	picojson::array& players = texture["player"].get<picojson::array>();
	std::vector<Texture>textures;
	for (auto it = players.begin(); it != players.end();it++){
		auto& tmp_texture = it->get<picojson::object>();
		textures.emplace_back(tmp_texture["array"].get<std::string>());
	}

	animation_list.emplace("miku", textures);
	bgm_list.emplace("title", Media(sound["bgm01"].get<std::string>()));
	se_list.emplace("hit", Media(sound["hit"].get<std::string>()));
}