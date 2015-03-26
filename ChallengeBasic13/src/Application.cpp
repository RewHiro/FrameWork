#include "Application.h"
#include <iostream>

Application::Application()
{
	Env();
	SceneManager::GetInstance();
}

//　アプリケーション環境を取得
AppEnv& Application::Env(){
	static AppEnv env(512, 512, false, true);
	return env;
}

//　アプリケーションを取得
Application& Application::GetInstance(){
	static Application app;
	return app;
}

//　更新
void Application::Update(){
	while(Env().isOpen()){
		Env().setupDraw();
		SceneManager::GetInstance().Update();
		Env().update();
	}
}

//　背景色を変更
void Application::bgColor(const Color& color){
	Env().bgColor(color);
}

//　入力(キー＆ボタン)の再初期化
void Application::flushInput(){
	Env().flushInput();
}

//　windowのサイズを取得
Vec2f Application::viewSize(){
	return Env().viewSize();
}

//　マウスの位置を取得
Vec2f Application::mousePositon(){
	return Env().mousePosition();
}

//　何が押されているか取得
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