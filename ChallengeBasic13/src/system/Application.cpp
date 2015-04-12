#include "Application.h"

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

// 当該ボタンが押されているならtrueを返す
// button Mouse::LEFT
//        Mouse::Right
bool Application::isPressButton(int button){
	return Env().isPressButton(button);
}

// 当該ボタンが押された瞬間trueを返す
// button Mouse::LEFT
//        Mouse::RIGHT
bool Application::isPushButton(int button){
	return Env().isPushButton(button);
}

// 当該ボタンが離された瞬間trueを返す
// button Mouse::LEFT
//        Mouse::RIGHT
bool Application::isPullButton(int button){
	return Env().isPullButton(button);
}

// 当該キーが押されているならtrueを返す
// key 'A'とか'7'とか
// SOURCE:include/GLFW/glfw3.h 271〜396
bool Application::isPressKey(int key){
	return Env().isPressKey(key);
}

// 当該キーが押された瞬間trueを返す
// key 'A'とか'7'とか
// SOURCE:include/GLFW/glfw3.h 271〜396
bool Application::isPushKey(int key){
	return Env().isPushKey(key);
}

// 当該キーが離された瞬間trueを返す
bool Application::isPullKey(int key){
	return Env().isPullKey(key);
}