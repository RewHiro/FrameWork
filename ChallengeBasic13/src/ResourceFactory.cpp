#include "ResourceFactory.h"
#include "ResourceTitle.h"
#include "ResourceStage.h"
#include <unordered_map>
#include <functional>

std::shared_ptr<Resource> ResourceFactory::Create(const SceneType type){
	static const std::unordered_map<SceneType, std::function<std::shared_ptr<Resource>()>> resource_list = {
		{
			SceneType::TITLE,
			[]{return std::make_shared<ResourceTitle>(); }
		},
		{
			SceneType::STAGE,
			[]{return std::make_shared<ResourceStage>(); }
		}
	};
	return (resource_list.find(type))->second();
}