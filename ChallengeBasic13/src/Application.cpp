#include "Application.h"
#include <iostream>

Application::Application()
{
	Env();
	SceneManager::GetInstance();
}

//�@�A�v���P�[�V���������擾
AppEnv& Application::Env(){
	static AppEnv env(512, 512, false, true);
	return env;
}

//�@�A�v���P�[�V�������擾
Application& Application::GetInstance(){
	static Application app;
	return app;
}

//�@�X�V
void Application::Update(){
	while(Env().isOpen()){
		Env().setupDraw();
		SceneManager::GetInstance().Update();
		Env().update();
	}
}

//�@�w�i�F��ύX
void Application::bgColor(const Color& color){
	Env().bgColor(color);
}

//�@����(�L�[���{�^��)�̍ď�����
void Application::flushInput(){
	Env().flushInput();
}

//�@window�̃T�C�Y���擾
Vec2f Application::viewSize(){
	return Env().viewSize();
}

//�@�}�E�X�̈ʒu���擾
Vec2f Application::mousePositon(){
	return Env().mousePosition();
}

//�@����������Ă��邩�擾
u_int Application::getPushedKey(){
	return Env().getPushedKey();
}

bool Application::isPressButton(int button){
	return Env().isPressButton(button);
}

bool Application::isPushButton(int button){
	return Env().isPushButton(button);
}

bool Application::isPullButton(int button){
	return Env().isPullButton(button);
}

bool Application::isPressKey(int key){
	return Env().isPressKey(key);
}

bool Application::isPushKey(int key){
	return Env().isPushKey(key);
}

bool Application::isPullKey(int key){
	return Env().isPullKey(key);
}