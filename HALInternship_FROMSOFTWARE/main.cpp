#include <iostream>
#include "InteractiveList.h"
#include "File.h"

#define FILE_PATH  "Assets/Data/Scores.txt"

int main(void)
{
	// 双方向リストの作成
	InteractiveList<DataParam> list;

	// ファイル読み込み
	if (!LoadFile<DataParam>(FILE_PATH, list))
	{
		std::cout << "ファイルの読み込みに失敗しました。" << std::endl;
	}

	// リストの内容を表示
	for(auto& data : list)
	{
		std::cout << "Score: " << data.m_nScore << ", Name: " << data.m_Name << std::endl;
	}


	return 0;
}