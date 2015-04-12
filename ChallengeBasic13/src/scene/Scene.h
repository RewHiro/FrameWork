#pragma once
#include "utility/Uncopyable.h"
#include <memory>

class Resource;

//　シーンの種類
enum class SceneType{
	TITLE,
	STAGE,
	RESULT,
};

//
//　シーン(抽象クラス)
//
class Scene : private Uncopyable
{
	SceneType type;
protected:
	//　現在のシーンの種類を取得
	SceneType Type()const{ return type; }
	const Resource& resource;
public:
	Scene();
	virtual ~Scene();

	//　更新
	virtual SceneType Update() = 0;

	//　描画
	virtual void Draw() = 0;

	//　シーンを遷移する
	void LoadScene(const SceneType type){ this->type = type; }
};

