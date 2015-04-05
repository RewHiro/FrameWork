#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include "ObjectInfo.h"
#include <vector>
class ObjectTask :
	private Uncopyable
{
	std::vector<std::shared_ptr<Object>>objects;
public:
	ObjectTask();
	~ObjectTask();
	void Add(const std::string& name, std::shared_ptr<Object>object);
	void Awake();
	void Start();
	void Update();
	void Draw();
	void Clear();
};

