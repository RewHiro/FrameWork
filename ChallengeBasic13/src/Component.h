#pragma once
class Component
{
protected:
	bool is_active = true;
public:
	Component() = default;
	virtual ~Component() = default;

	virtual void Update(){}
};

