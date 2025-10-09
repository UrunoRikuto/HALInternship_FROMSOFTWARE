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

	// リストのソート
	list.sort(SortAlgorithm::QuickSort, SortOrder::Ascending,
		[](const DataParam& d) {return d.m_nScore; });

	// リストの内容を表示
	InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	itEnd++;
	// イテレーターを使ってリストの各要素にアクセス
	for (auto it = list.cbegin(); it != itEnd; ++it)
	{
		const DataParam& data = *it;
		std::cout <<
			"Score: " << data.m_nScore
			<< ", " <<
			"Name: " << data.m_Name 
			<< std::endl;
	}

	// プログラム終了
	return 0;
}