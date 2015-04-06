#pragma once
#include "lib\appEnv.hpp"
#include "Uncopyable.h"
#include "SceneManager.h"


//
//　主にインプットの機能(マウスやキーの入力など)
//　シングルトーン
//
class Application : private Uncopyable
{
	static AppEnv& Env();
	Application();
public:
	//　使用禁止
	static Application& GetInstance();
	void Update();

	//　イベント
	static void bgColor(const Color& color);
	static void flushInput();
	static Vec2f viewSize();
	static Vec2f mousePositon();
	static u_int getPushedKey();
	static bool isPressButton(int button);
	static bool isPushButton(int button);
	static bool isPullButton(int button);
	static bool isPressKey(int key);
	static bool isPushKey(int key);
	static bool isPullKey(int key);
};