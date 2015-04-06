#pragma once
#include "lib\appEnv.hpp"
#include "Uncopyable.h"
#include "SceneManager.h"


//
//�@��ɃC���v�b�g�̋@�\(�}�E�X��L�[�̓��͂Ȃ�)
//�@�V���O���g�[��
//
class Application : private Uncopyable
{
	static AppEnv& Env();
	Application();
public:
	//�@�g�p�֎~
	static Application& GetInstance();
	void Update();

	//�@�C�x���g
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