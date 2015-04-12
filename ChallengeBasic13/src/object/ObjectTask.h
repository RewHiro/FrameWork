#pragma once
#include "utility/Uncopyable.h"
#include <forward_list>
#include <memory>
#include <stack>

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
	void Add(const std::string& name, const std::shared_ptr<Object>& object);

	//　更新
	void Update()const;

	//　描画
	void Draw()const;

	//　オブジェクト一覧の全削除
	void Clear();

	//　削除
	void Erase();

	//　オブジェクト破壊リスト取得
	std::stack<std::shared_ptr<Object>>& GetDeleteList(){
		static std::stack<std::shared_ptr<Object>>delete_list;
		return delete_list;
	}

};

