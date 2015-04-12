#pragma once

//　コピー禁止クラス
class Uncopyable
{
	//　ポインタでコピーしないとサイズが大きくなってしまうため禁止
protected:
	Uncopyable() = default;
private:
	explicit Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;
};

