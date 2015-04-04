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
}