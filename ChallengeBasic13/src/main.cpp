//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "Application.h"


//TODO
//当たり判定
//パーティクル機能
//最後にコメントを書く
//整理
//エラー確認
//親子の関係

//当たり判定一覧
//点と点
//点と線
//点と四角
//点と円
//円と円
//四角と四角

//Utility一覧
//2点間の距離
//なす角
//clamp

// 
// メインプログラム
// 
int main(){
	//　メモリーリークの確認
	//　メモリーリークしていたらデバッグ出力に表示される
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Application::GetInstance().Update();
}
