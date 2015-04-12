#pragma once

//�@�R�s�[�֎~�N���X
class Uncopyable
{
	//�@�|�C���^�ŃR�s�[���Ȃ��ƃT�C�Y���傫���Ȃ��Ă��܂����ߋ֎~
protected:
	Uncopyable() = default;
private:
	explicit Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;
};

