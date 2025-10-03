#include <iostream>
#include "InteractiveList.h"
#include "File.h"

// ファイルパス
#define FILE_PATH  "Assets/Data/Scores.txt"

// メイン関数
int main(void)
{
	// 双方向リストの作成
	InteractiveList<DataParam> list;

	// ファイル読み込み
	if (!LoadFile(FILE_PATH, list))
	{
		std::cout << "ファイルの読み込みに失敗しました。" << std::endl;
	}

	// リストの内容を表示
	// イテレーターを使ってリストの各要素にアクセス
	for (const auto& data : list)
	{
		// スコアと名前を表示
		std::cout << 
			"Score: " << data->m_Data.m_nScore
			<< ", " << 
			"Name: " << data->m_Data.m_Name 
			<< std::endl;
	}

	list.clear();

	// プログラム終了
	return 0;
}