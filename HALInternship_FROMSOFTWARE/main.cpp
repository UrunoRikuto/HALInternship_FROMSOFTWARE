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

	//// ファイル読み込み
	//if (!LoadFile(FILE_PATH, list))
	//{
	//	std::cout << "ファイルの読み込みに失敗しました。" << std::endl;
	//}

	//// リストのソート
	//list.sort(SortAlgorithm::QuickSort, std::less<>(),
	//	[](const DataParam& d) {return d.m_nScore; });

	//// リストの内容を表示
	//InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	//itEnd++;
	//// イテレーターを使ってリストの各要素にアクセス
	//std::cout << "＝＝＝＝＝クイックソート「スコア(昇順)」＝＝＝＝＝" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name 
	//		<< std::endl;
	//}

	//// リストのソート
	//list.sort(SortAlgorithm::QuickSort, std::greater<>(),
	//	[](const DataParam& d) {return d.m_nScore; });

	//// リストの内容を表示
	//itEnd = list.cend();
	//itEnd++;
	//// イテレーターを使ってリストの各要素にアクセス
	//std::cout << "＝＝＝＝＝クイックソート「スコア(降順)」＝＝＝＝＝" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}

	//// リストのソート
	//list.sort(SortAlgorithm::QuickSort, std::less<>(),
	//	[](const DataParam& d) {return d.m_Name; });

	//// リストの内容を表示
	//itEnd = list.cend();
	//itEnd++;
	//// イテレーターを使ってリストの各要素にアクセス
	//std::cout << "＝＝＝＝＝クイックソート「名前(昇順)」＝＝＝＝＝" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}

	//// リストのソート
	//list.sort(SortAlgorithm::QuickSort, std::greater<>(),
	//	[](const DataParam& d) {return d.m_Name; });

	//// リストの内容を表示
	//itEnd = list.cend();
	//itEnd++;
	//// イテレーターを使ってリストの各要素にアクセス
	//std::cout << "＝＝＝＝＝クイックソート「名前(降順)」＝＝＝＝＝" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}


	list.pushBack({ 300, "Alice" });
	list.pushBack({ 150, "Bob" });
	list.pushBack({ 450, "Charlie" });
	list.pushBack({ 200, "Diana" });
	list.pushBack({ 400, "Eve" });


	list.sort(SortAlgorithm::QuickSort, std::less<>(),
		[](const DataParam& d) {return d.m_nScore; });

	// リストの内容を表示
	InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	itEnd++;
	// イテレーターを使ってリストの各要素にアクセス
	std::cout << "＝＝＝＝＝クイックソート「スコア(昇順)」＝＝＝＝＝" << std::endl;
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