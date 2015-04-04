#pragma once

#include "lib\vector.hpp"

class Transform2D 
{
	Vec2f pos = Vec2f::Zero();
	Vec2f size = Vec2f::Zero();
	Vec2f scale = Vec2f::Ones();
	float rotate = .0f;

	Vec2f Affine(Vec2f& translate = Vec2f(0, 0)){
		Eigen::Translation2f pre_traslation(pos);
		Eigen::Translation2f traslation(translate);
		Eigen::DiagonalMatrix<float, 2>scaling = Eigen::Scaling(scale);
		Eigen::Rotation2Df rotation(rotate);
		return pre_traslation * scaling * rotation * traslation * Vec2f::Zero();
	}

public:

	Transform2D(const Vec2f& pos, const Vec2f& size) :
		pos(pos),
		size(size)
	{}
	Transform2D() = default;

	Vec2f& Position(){ return pos; }
	Vec2f& Size(){ return size; }
	Vec2f Scale()const{ return scale; }
	float Rotate()const{ return rotate; }
	float& PosX(){ return pos.x(); }
	float& PosY(){ return pos.y(); }
	float& SizeX(){ return size.x(); }
	float& SizeY(){ return size.y(); }
	Vec2f Center()const{ return size.array() * .5f; }

	void LocalTranslate(Vec2f& translate){
		pos = Affine(translate);
	}

	void Translate(Vec2f& translate){
		pos += translate;
	}

	void Rotation(float rotate){
		this->rotate += rotate;
		pos = Affine();
	}

	void Scaling(Vec2f& scale){
		this->scale += scale;
		pos = Affine();
	}
	void Scaling(float scale){
		this->scale.array() += scale;
		pos = Affine();
	}
};

