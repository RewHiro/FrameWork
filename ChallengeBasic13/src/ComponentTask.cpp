#include "ComponentTask.h"
#include "Component.h"

ComponentTask::ComponentTask()
{
}

void ComponentTask::Start(){
	for (auto& component : components){
		component->Start();
		component->GetUpdateState() = UpdateState::UPDATE;
	}
}
void ComponentTask::Update(){

	for (auto& component : components){
		switch(component->GetUpdateState()){
		case UpdateState::UPDATE:
			component->Update();
			break;
		case UpdateState::START:
			component->Start();
			component->GetUpdateState() = UpdateState::UPDATE;
			break;
		}
	}
}

void ComponentTask::Add(std::shared_ptr<Component>component){
	components.emplace_back(component);
}