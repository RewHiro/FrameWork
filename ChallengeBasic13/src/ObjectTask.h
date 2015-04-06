#pragma once
#include "Uncopyable.h"
#include <forward_list>
#include <memory>

class Object;

//
//　オブジェクトタスク
//

class ObjectTask : private Uncopyable
{
	std::forward_list<std::shared_ptr<Object>>objects;
public:
	ObjectTask();
	//　追加
	void Add(const std::string& name, std::shared_ptr<Object>object);

	//　Start関数が実行する前に実行される
	void Awake();

	//　Update関数が実行する前に実行される
	void Start();

	//　更新
	void Update();

	//　描画
	void Draw();

	//　オブジェクト一覧の全削除
	void Clear();

	//　削除
	void Erase();
};

