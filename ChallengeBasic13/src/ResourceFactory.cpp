#include "ResourceFactory.h"
#include "ResourceTitle.h"
#include "ResourceStage.h"
#include <unordered_map>
#include <functional>

std::unique_ptr<Resource> ResourceFactory::Create(const SceneType type){
	static const std::unordered_map<SceneType,std::function<std::unique_ptr<Resource>()>> resource_list = {
		{
			SceneType::TITLE,
			[]{return std::make_unique<ResourceTitle>(); }
		},
		{
			SceneType::STAGE,
			[]{return std::make_unique<ResourceStage>(); }
		}
	};
	return std::move((resource_list.find(type))->second());
}