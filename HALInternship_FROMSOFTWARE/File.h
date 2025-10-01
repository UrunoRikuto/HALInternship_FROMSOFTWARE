/*＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
* 
* @file File.h
* @brief ファイル操作に関するヘッダーファイル
* 
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝*/

#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "InteractiveList.h"

// @brief データ構造体
struct DataParam
{
	// @brief スコア
	int m_nScore = 0;
	// @brief 名前
	std::string m_Name = "";
};

// @brief ファイルからデータを読み込み、リストに格納
// @param In_FileName 読み込むファイルパス
// @param Out_List 格納するリスト
// @return ファイル操作が成功したらtrue,失敗したらfalse
template<typename T>
bool LoadFile(const std::string& In_FileName, InteractiveList<T>& Out_List) {
	// ファイルを開く
	std::ifstream inputFile(In_FileName);
	if (!inputFile.is_open()) return false;

	std::string line;
	// 1行ずつ読み込み
	while (std::getline(inputFile, line)) {
		// DataParam型の場合のみ処理
		if (typeid(T) == typeid(DataParam)) {
			// 行をストリームに変換
			std::istringstream iss(line);

			// タブ区切りで分割
			std::string idStr, name;
			if (!std::getline(iss, idStr, '\t')) continue;
			if (!std::getline(iss, name)) continue;

			// データ構造体を作成
			DataParam data;
			// 文字列を整数に変換して格納
			data.m_nScore = std::stoi(idStr);
			// 名前を格納
			data.m_Name = name;

			// リストにデータを追加
			Out_List.pushBack(data);
		}
		else {
			// 対応していない型の場合ファイルを閉じる
			inputFile.close();
			// 処理失敗
			return false;
		}
	}

	// ファイルを閉じる
	inputFile.close();

	// 処理成功
	return true;
}