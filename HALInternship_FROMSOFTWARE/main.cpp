#include <iostream>
#include "InteractiveList.h"
#include "File.h"

// ファイルパス
#define FILE_PATH  "Assets/Data/Scores.txt"

// メイン関数
int main(void)
{
	using DataList = InteractiveList<DataParam>;

	// 双方向リストの作成
	DataList list;

	// ファイル読み込み
	if (!LoadFile(FILE_PATH, list))
	{
		std::cout << "ファイルの読み込みに失敗しました。" << std::endl;
	}

	// リストの内容を表示
	//  const版イテレーターを取得
	const DataList Iterator = list;
	// イテレーターを使ってリストの各要素にアクセス
	for(auto& data : Iterator)
	{
		// スコアと名前を表示
		std::cout << 
			"Score: " << data.m_nScore
			<< ", " << 
			"Name: " << data.m_Name 
			<< std::endl;
	}


	// プログラム終了
	return 0;
}