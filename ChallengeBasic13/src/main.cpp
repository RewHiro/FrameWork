//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "Application.h"


//TODO
//当たり判定->Utility
//Erase機能(objectやcomponetnを削除する機能)
//resouceが引数に入っててめんどいのをどうにかする
//パーティクル機能
//最後にコメントを書く

// 
// メインプログラム
// 
int main() {
	Application::GetInstance().Update();
}
