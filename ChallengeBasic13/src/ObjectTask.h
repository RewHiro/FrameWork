#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include "ObjectInfo.h"
#include <forward_list>
class ObjectTask :
	private Uncopyable
{
	std::forward_list<std::shared_ptr<Object>>objects;
public:
	ObjectTask();
	~ObjectTask();
	void Add(const std::string& name, std::shared_ptr<Object>object);
	void Awake();
	void Start();
	void Update();
	void Draw();
	void Clear();
	void Erase();
};

