#include "ComponentTask.h"
#include "Component.h"

ComponentTask::ComponentTask()
{
}

void ComponentTask::Start(){
	for (auto& component : components){
		component->Start();
	}
}
void ComponentTask::Update(){
	for (auto& component : components){
		component->Update();
	}
}

void ComponentTask::Add(std::shared_ptr<Component>component){
	components.emplace_back(component);
	component_list.emplace(component->Name(), component);
}

const std::shared_ptr<Component> ComponentTask::Find(const std::string& name)const{
	return component_list.find(name)->second;
}