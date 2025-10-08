#include "pch.h"
#include "InteractiveList.h"
#include "ListTest.h"

// リストのテスト
namespace List
{
	//=================================== データ数の取得 ===================================//
	// 項　目：リストが空の場合の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// データ数が0であることを確認
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：リスト末尾への挿入を行った際の戻り値
	// 理　想：1
	TEST(ListDataSize, TestGetDataSizeIsPushBackToTRUE)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾にデータを挿入
		list.pushBack(1);
		// データ数が1であることを確認
		EXPECT_EQ(1,list.getSize());
	}
	// 項　目：リスト末尾への挿入が失敗した際の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsPushBackToFALSE)
	{
		// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
		//InteractiveList<int> list;
		//ASSERT_FALSE(list.pushBack(1));
		//EXPECT_EQ(0, list.getSize());
	}
	// 項　目：データの挿入を行った際の戻り値
	// 理　想：1
	TEST(ListDataSize, TestGetDataSizeIsInsertToTRUE)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// データを挿入
		list.insert(it, 1);
		// データ数が1であることを確認
		EXPECT_EQ(1, list.getSize());
	}
	// 項　目：データの挿入が失敗した際の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsInsertToFALSE)
	{
		// "挿入失敗"はメモリ確保失敗時のためここではスキップ
		//InteractiveList<int> list;
		//InteractiveList<int>::Iterator it = list.begin();
		//list.insert(it, 1);
		//EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：データの削除を行った際の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsEraseToTRUE)
	{
		// リストを作成
		InteractiveList<int> list;
		// データを挿入
		list.pushBack(1);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// データを削除
		list.erase(it);
		// データ数が0であることを確認
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：データの削除が失敗した際の戻り値
	// 理　想：1
	TEST(ListDataSize, TestGetDataSizeIsEraseToFALSE)
	{
		// リストを作成
		InteractiveList<int> list;
		// データを挿入
		list.pushBack(1);
		// 末尾の後のイテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		it++;
		// データを削除
		list.erase(it);
		// データ数が1であることを確認
		EXPECT_EQ(1, list.getSize());
	}
	// 項　目：リストが空である場合に、データの削除を行った際の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsEraseWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// データを削除
		list.erase(it);
		// データ数が0であることを確認
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListDataSize, TestGetDataSizeConst)
	{	
#if defined TT_TEST_GET_DATA_SIZE_IS_CONST
		// const版リストを作成
		const InteractiveList<int> list;
		// データ数が0であることを確認
		EXPECT_EQ(0, list.getSize());
#endif //TT_TEST_GET_DATA_SIZE_WHEN_CONST
		SUCCEED();
	}

	//=================================== データの挿入 ===================================//
	// 項　目：リストが空である場合に、挿入した際の挙動
	// 理　想：先頭イテレーターと末尾イテレーターのどちらで行っても成功
	TEST(ListInsert, TestInsertWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it_begin = list.begin();
		/// 先頭イテレーター ///
		// 先頭に挿入
		ASSERT_TRUE(list.insert(it_begin, 1));
		// データ数が1であることを確認
		EXPECT_EQ(1, list.getSize());

		// リストを空にする
		list.clear();
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it_end = list.end();
		
		/// 末尾イテレーター ///
		// 末尾に挿入
		ASSERT_TRUE(list.insert(it_end, 1));
		// データ数が1であることを確認
		EXPECT_EQ(1, list.getSize());
	}
	// 項　目：リストに複数のデータがある場合に、先頭イテレーターを渡して挿入した際の挙動
	// 理　想：先頭に挿入されて元々のデータが後ろにずれる
	TEST(ListInsert, TestInsertWhenHaveDataToBegin)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it_begin = list.begin();
		// 先頭に挿入
		ASSERT_TRUE(list.insert(it_begin, 1));

		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();

		// データが1,2,3の順であることを確認
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// 項　目：リストに複数のデータがある場合に、末尾イテレーターを渡して挿入した際の挙動
	// 理　想：末尾に挿入されて元々のデータはそのまま
	TEST(ListInsert, TestInsertWhenHaveDataToEnd)
	{
		// リストを作成
		InteractiveList<int> list;

		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(3);

		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it_end = list.end();

		// 末尾に挿入
		ASSERT_TRUE(list.insert(it_end, 2));

		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();
		// データが1,2,3の順であることを確認
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// 項　目：リストに複数のデータがある場合に、先頭でも末尾でもないイテレーターを渡して挿入した際の挙動
	// 理　想：指定した位置に挿入されて元々のデータはそのまま
	TEST(ListInsert, TestInsertWhenHaveDataToMiddle)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(3);
		// 先頭イテレーターを取得して1つ進める
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		// 2を挿入
		ASSERT_TRUE(list.insert(it, 2));
		// イテレーターを先頭に戻す
		it = list.begin();
		// データが1,2,3の順であることを確認
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// 項　目：Const版イテレーターを渡して挿入した際の挙動
	// 理　想：イテレーターの示す位置に挿入されて元々のデータはそのまま
	TEST(ListInsert, TestInsertWhenConstIterator)
	{
		// リストを作成
		InteractiveList<int> list;

		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(3);

		// Const版イテレーターを取得して1つ進める
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;

		// 2を挿入
		list.insert(const_it, 2);

		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();

		// データが1,2,3の順であることを確認
		EXPECT_EQ(1,(*it));
		it++;
		EXPECT_EQ(2,(*it));
		it++;
		EXPECT_EQ(3,(*it));
	}
	// 項　目：不正なイテレーターを渡して挿入した際の挙動
	// 理　想：挿入に失敗してデータ数は増えない
	TEST(ListInsert, TestInsertWhenInvalidIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 最初のリストとは別のリストを作成してイテレーターを取得
		InteractiveList<int> list2;
		// リストにデータを挿入
		list2.pushBack(3);
		// 先頭イテレーターを取得して1つ進める
		InteractiveList<int>::Iterator it = list2.begin();
		it++;
		// 挿入に失敗することを確認
		ASSERT_FALSE(list.insert(it, 4));
		// データ数が2であることを確認
		EXPECT_EQ(list.getSize(), 2);

		// リスト参照のないイテレーターを作成
		InteractiveList<int>::Iterator it_nullptr;
		// 挿入に失敗することを確認
		ASSERT_FALSE(list.insert(it_nullptr, 4));
		// データ数が2であることを確認
		EXPECT_EQ(list.getSize(), 2);
	}
	// 項　目：非constのメソッドであるか
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListInsert, TestInsertWhenConst)
	{
#if defined TT_TEST_INSERT_WHEN_CONST
		// const版リストを作成
		const InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 挿入に失敗することを確認
		list.insert(it, 1); // ここでコンパイルエラーになる
#endif //TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

	//=================================== データの削除 ===================================//
	// 項　目：リストが空である場合に、データの削除を行った際の挙動
	// 理　想：何も起こらない
	TEST(ListErase, TestEraseWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーター
		InteractiveList<int>::Iterator it = list.begin();
		// データを削除
		ASSERT_FALSE(list.erase(it));
		// データ数が0であることを確認
		EXPECT_EQ(list.getSize(), 0);
		// 末尾イテレーター
		it = list.end();
		// データを削除
		list.erase(it);
		// データ数が0であることを確認
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：リストに複数のデータがある場合に、先頭イテレーターを渡して削除した際の挙動
	// 理　想：先頭のデータが削除されて、2番目以降のデータが前にずれる
	TEST(ListErase, TestEraseWhenHaveDataToBegin)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it_begin = list.begin();
		// 先頭のデータを削除
		ASSERT_TRUE(list.erase(it_begin));
		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();
		// データが2,3の順であることを確認
		EXPECT_EQ((*it), 2);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：リストに複数のデータがある場合に、末尾イテレーターを渡して削除した際の挙動
	// 理　想：末尾のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenHaveDataToEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it_end = list.end();
		// 末尾のデータを削除
		ASSERT_TRUE(list.erase(it_end));
		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();
		// データが1,2の順であることを確認
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 2);
	}
	// 項　目：リストに複数のデータがある場合に、先頭でも末尾でもないイテレーターを渡して削除した際の挙動
	// 理　想：指定した位置のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenHaveDataToMiddle)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得して1つ進める
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		// 2を削除
		ASSERT_TRUE(list.erase(it));
		// イテレーターを先頭に戻す
		it = list.begin();
		// データが1,3の順であることを確認
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：Const版イテレーターを渡して削除した際の挙動
	// 理　想：指定した位置のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenConstIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// Const版イテレーターを取得して1つ進める
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;
		// 2を削除
		ASSERT_TRUE(list.erase(const_it));
		// イテレーターを先頭に戻す
		InteractiveList<int>::Iterator it = list.begin();
		// データが1,3の順であることを確認
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：不正なイテレーターを渡して削除した際の挙動
	// 理　想：削除に失敗してデータ数は増えない
	TEST(ListErase, TestEraseWhenInvalidIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 最初のリストとは別のリストを作成してイテレーターを取得
		InteractiveList<int> list2;
		// リストにデータを挿入
		list2.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list2.begin();
		// 削除に失敗することを確認
		ASSERT_FALSE(list.erase(it));
		// データ数が2であることを確認
		EXPECT_EQ(list.getSize(), 2);

		// リスト参照のないイテレーターを作成
		InteractiveList<int>::Iterator it_nullptr;
		// 削除に失敗することを確認
		ASSERT_FALSE(list.erase(it_nullptr));
		// データ数が2であることを確認
		EXPECT_EQ(list.getSize(), 2);
	}
	// 項　目：非constのメソッドであるか
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListErase, TestEraseWhenConst)
	{
#if defined TT_TEST_ERASE_WHEN_CONST
		// const版リストを作成
		const InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();//ここでエラー
		// データを削除
		list.erase(it);//ここでエラー
#endif //TT_TEST_ERASE_WHEN_CONST
		SUCCEED();
	}

	//============================= 先頭イテレーター =============================//
	// 項　目：リストが空である場合に、先頭イテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// ダミーノードを指すイテレーターを取得
		InteractiveList<int>::Iterator dummy = list.end();
		// 先頭イテレーターとダミーノードを指すイテレーターが等しいことを確認
		EXPECT_EQ(it, dummy);
	}
	// 項　目：リストに要素が一つある場合に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenHaveOneData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの挿入を行った後に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginAfterInsert)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 1を挿入
		list.insert(it, 1);
		// 先頭イテレーターを再取得
		it = list.begin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの削除を行った後に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginAfterErase)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(2);
		list.pushBack(1);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 1を削除
		list.erase(it);
		// 先頭イテレーターを再取得
		it = list.begin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：constのリストからConst版イテレーターでない先頭イテレーターを取得した際の挙動
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListBegin, TestBeginWhenConstList)
	{
#if defined TT_TEST_BEGIN_WHEN_CONST_LIST
		// const版リストを作成
		const InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();//ここでエラー
#endif //TT_TEST_BEGIN_WHEN_CONST_LIST
		SUCCEED();
	}
	
	//============================= 先頭コンストイテレーター =============================//
	// 項　目：リストが空である場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// ダミーノードを指すイテレーターを取得
		InteractiveList<int>::const_Iterator dummy = list.cend();
		// 先頭コンストイテレーターとダミーノードを指すイテレーターが等しいことを確認
		EXPECT_EQ(it, dummy);
	}
	// 項　目：リストに要素が一つある場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenHaveOneData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// 先頭コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの挿入を行った後に、先頭コンストイレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginAfterInsert)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(2);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 1を挿入
		list.insert(it, 1);
		// 先頭コンストイテレーターを再取得
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*const_it), 1);
	}
	// 項　目：データの削除を行った後に、先頭コンストイレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginAfterErase)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(2);
		list.pushBack(1);
		list.pushBack(3);
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 1を削除
		list.erase(it);
		// 先頭コンストイテレーターを再取得
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// 取得したイテレーターが先頭の要素を指していることを確認
		EXPECT_EQ((*const_it), 1);
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListConstBegin, TestConstBeginWhenConst)
	{
#if defined TT_TEST_CONST_BEGIN_WHEN_CONST
		// const版リストを作成
		const InteractiveList<int> list;
		// 先頭コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// ダミーノードを指すイテレーターを取得
		InteractiveList<int>::const_Iterator dummy = list.cend();
		// 先頭コンストイテレーターとダミーノードを指すイテレーターが等しいことを確認
		EXPECT_EQ(it, dummy);
#endif //TT_TEST_CONST_BEGIN_WHEN_CONST
		SUCCEED();
	}

	//============================= 末尾イテレーター=============================//
	// 項　目：リストが空である場合に、末尾イテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListEnd, TestEndWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// ダミーノードを指すイテレーターを取得
		InteractiveList<int>::Iterator dummy = list.rend();
		// 末尾イテレーターとダミーノードを指すイテレーターが等しいことを確認
		EXPECT_EQ(it, dummy);
	}
	// 項　目：リストに要素が一つある場合に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndWhenHaveOneData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 3);
	}
	// 項　目：データの挿入を行った後に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndAfterInsert)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// 2を挿入
		list.insert(it, 2);
		// 末尾イテレーターを再取得
		it = list.end();

		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 3);
	}
	// 項　目：データの削除を行った後に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndAfterErase)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// 3を削除
		list.erase(it);
		// 末尾イテレーターを再取得
		it = list.end();
		
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 2);
	}
	// 項　目：constのリストからConst版イテレーターでない末尾イテレーターを取得した際の挙動
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListEnd, TestEndWhenConstList)
	{
#if defined TT_TEST_END_WHEN_CONST_LIST
		// const版リストを作成
		const InteractiveList<int> list;
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();//ここでエラー
#endif //TT_TEST_END_WHEN_CONST_LIST
		SUCCEED();
	}
	
	// ============================= Const版末尾イテレーター =============================//
	// 項　目：リストが空である場合に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenEmpty)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
		// ダミーノードを指すイテレーターを取得
		InteractiveList<int>::const_Iterator dummy = list.crend();
		// 末尾コンストイテレーターとダミーノードを指すイテレーターが等しいことを確認
		EXPECT_EQ(it, dummy);
	}
	// 項　目：リストに要素が一つある場合に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：その要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenHaveOneData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// 末尾コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、末尾コンストイレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*it), 3);
	}
	// 項　目：データの挿入を行った後に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndAfterInsert)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
		// 2を挿入
		list.insert(it, 2);
		// 末尾コンストイテレーターを再取得
		InteractiveList<int>::const_Iterator const_it = list.cend();
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*const_it), 3);
	}
	// 項　目：データの削除を行った後に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndAfterErase)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾イテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
		// 3を削除
		list.erase(it);
		// 末尾コンストイテレーターを再取得
		InteractiveList<int>::const_Iterator const_it = list.cend();
		// 取得したイテレーターの示す要素が末尾の要素と等しいことを確認
		EXPECT_EQ((*const_it), 2);
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListConstEnd, TestConstEndWhenConst)
	{
#if defined TT_TEST_CONST_END_WHEN_CONST
		// const版リストを作成
		const InteractiveList<int> list;
		// 末尾コンストイテレーターを取得
		InteractiveList<int>::const_Iterator it = list.cend();
#endif //TT_TEST_CONST_END_WHEN_CONST
		SUCCEED();
	}

}// リストのテスト

// イテレーターのテスト
namespace Iterator
{
	// ============================= イテレーターの示す要素を取得 =============================//
	// 項　目：リストの参照がない状態で呼び出したときの挙動
	// 理　想：Assert発生
	TEST(IteratorGetData, TestGetDataWhenNoList)
	{
		// リスト参照なしイテレーターを作成
		InteractiveList<int>::Iterator it;
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：イテレーターから取得した要素に対して値の代入を行えるかチェック
	// 理　想：代入できる
	TEST(IteratorGetData, TestGetDataAssign)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// イテレーターを取得して値を変更
		InteractiveList<int>::Iterator it = list.begin();
		// 値を代入
		(*it) = 2;
		// イテレーターを先頭に戻して値を確認
		it = list.begin();
		// 変更されていることを確認
		EXPECT_EQ(2, (*it));
	}
	// 項　目：Const版イテレーターから取得した要素に対して値の代入を行えないかチェック
	// 理　想：コンパイルエラーになる
	TEST(IteratorGetData, TestGetDataWhenConstIterator)
	{
#if defined TT_TEST_GET_DATA_WHEN_CONST_ITERATOR
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// Const版イテレーターを取得して値を変更
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// 値を代入
		(*const_it) = 2;//ここでエラー
#endif //TT_TEST_GET_DATA_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// 項　目：リストが空の際に先頭イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorGetData, TestGetDataWhenEmptyToBegin)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストが空の際に末尾イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorGetData, TestGetDataWhenEmptyToEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}

	// ============================ イテレーターを末尾に向かって一つ進める =============================//
	// 項　目：リストの参照がない状態で呼び出したときの挙動
	// 理　想：Assert発生
	TEST(IteratorIncrement, TestIncrementWhenNoList)
	{
		// リスト参照なしイテレーターを作成
		InteractiveList<int>::Iterator it;
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			it++;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストが空の際に先頭イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorIncrement, TestIncrementWhenEmptyToBegin)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			it++;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストが空の際に末尾イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorIncrement, TestIncrementWhenEmptyToEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
	it++;
			}, "Assertion failed.*");

#endif // _DEBUG
	}
	// 項　目：リストに複数の要素があるときに呼び出したときの挙動
	// 理　想：イテレーターが一つ進む
	TEST(IteratorIncrement, TestIncrementWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾まで確認する
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// 項　目：前置インクリメントを行った際の挙動
	// 理　想：イテレーターが一つ進む
	TEST(IteratorIncrement, TestIncrementWhenPre)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾まで確認する
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		++it;
		EXPECT_EQ(2, (*it));
		++it;
		EXPECT_EQ(3, (*it));
	}
	// 項　目：後置インクリメントを行った際の挙動
	// 理　想：イテレーターが一つ進む
	TEST(IteratorIncrement, TestIncrementWhenPost)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 末尾まで確認する
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}

	//============================= イテレーターを先頭に向かって一つ進める =============================//
	// 項　目：リストの参照がない状態で呼び出したときの挙動
	// 理　想：Assert発生
	TEST(IteratorDecrement, TestDecrementWhenNoList)
	{
		// リスト参照なしイテレーターを作成
		InteractiveList<int>::Iterator it;
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストが空の際に末尾イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorDecrement, TestDecrementWhenEmptyToBegin)
	{
		// リストを作成
		InteractiveList<int> list;
		// 末尾イテレーターを取得
		InteractiveList<int>::Iterator it = list.end();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストが空の際に先頭イテレーターに対して呼び出した際の挙動
	// 理　想：Assert発生
	TEST(IteratorDecrement, TestDecrementWhenEmptyToEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// Assert発生を確認
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// 項　目：リストに複数の要素があるときに呼び出したときの挙動
	// 理　想：イテレーターが一つ戻る
	TEST(IteratorDecrement, TestDecrementWhenHaveMultipleData)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭まで確認する
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		it--;
		EXPECT_EQ(2, (*it));
		it--;
		EXPECT_EQ(1, (*it));
	}
	// 項　目：前置デクリメントを行った際の挙動
	// 理　想：イテレーターが一つ戻る
	TEST(IteratorDecrement, TestDecrementWhenPre)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭まで確認する
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		--it;
		EXPECT_EQ(2, (*it));
		--it;
		EXPECT_EQ(1, (*it));
	}
	// 項　目：後置デクリメントを行った際の挙動
	// 理　想：イテレーターが一つ戻る
	TEST(IteratorDecrement, TestDecrementWhenPost)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// 先頭まで確認する
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		it--;
		EXPECT_EQ(2, (*it));
		it--;
		EXPECT_EQ(1, (*it));
	}

	//============================= イテレーターのコピー =============================//
	// 項　目：コンストイテレーターからイテレーターをコピーコンストラクトした際の挙動
	// 理　想：コンパイルエラーになる
	TEST(IteratorCopy, TestCopyWhenConstIterator)
	{
#if defined TT_TEST_COPY_WHEN_CONST_ITERATOR
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// Const版イテレーターを取得
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// イテレーターをコピーコンストラクト
		InteractiveList<int>::Iterator it = const_it;//ここでエラー
#endif //TT_TEST_COPY_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// 項　目：コピーコンストラクト後の値がコピー元と同じであるか
	// 理　想：同じである
	TEST(IteratorCopy, TestCopyValue)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// コピーコンストラクト
		InteractiveList<int>::Iterator it2 = it;
		// コピー元とコピー先が同じ値を指していることを確認
		EXPECT_EQ((*it), (*it2));
	}

	//============================= イテレーターの代入 =============================//
	// 項　目：イテレーターにコンスト版イテレーターを代入した際の挙動
	// 理　想：コンパイルエラーになる
	TEST(IteratorAssign, TestAssignWhenConstIterator)
	{
#if defined TT_TEST_ASSIGN_WHEN_CONST_ITERATOR
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		// Const版イテレーターを取得
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// イテレーターに代入
		InteractiveList<int>::Iterator it;
		it = const_it;//ここでエラー
#endif //TT_TEST_ASSIGN_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// 項　目：代入後の値が代入元と同じであるか
	// 理　想：同じである
	TEST(IteratorAssign, TestAssignValue)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// イテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		// 代入
		InteractiveList<int>::Iterator it2;
		it2 = it;
		(*it2) = 5;
		// 代入元と代入先が同じ値を指していることを確認
		EXPECT_EQ((*it), 5);
	}

	//============================= 二つのイテレーターが同一のものであるか比較 =============================//
	// 項　目：リストが空の状態で先頭イテレーターと末尾イテレーターを比較した際の挙動
	// 理　想：同じである(TRUE)
	TEST(IteratorCompare, TestCompareWhenEmptyToBeginAndEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターと末尾イテレーターを取得
		InteractiveList<int>::Iterator it_begin = list.begin();
		InteractiveList<int>::Iterator it_end = list.end();
		// 同じであることを確認
		EXPECT_TRUE(it_begin == it_end);
	}
	// 項　目：同一のイテレーターを比較した際の挙動
	// 理　想：同じである(TRUE)
	TEST(IteratorCompare, TestCompareWhenSameIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 同じイテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		// 同じであることを確認
		EXPECT_TRUE(it == it2);
	}
	// 項　目：異なるイテレーターを比較した際の挙動
	// 理　想：異なるものである(FALSE)
	TEST(IteratorCompare, TestCompareWhenDifferentIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 異なるイテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		it2++;
		// 異なるものであることを確認
		EXPECT_FALSE(it == it2);
	}
	
	//============================= 二つのイテレーターが異なるものであるか比較 =============================//
	// 項　目：リストが空の状態で先頭イテレーターと末尾イテレーターを比較した際の挙動
	// 理　想：同じである(FALSE)
	TEST(IteratorNotCompare, TestNotCompareWhenEmptyToBeginAndEnd)
	{
		// リストを作成
		InteractiveList<int> list;
		// 先頭イテレーターと末尾イテレーターを取得
		InteractiveList<int>::Iterator it_begin = list.begin();
		InteractiveList<int>::Iterator it_end = list.end();
		// 同じであることを確認
		EXPECT_FALSE(it_begin != it_end);
	}
	// 項　目：同一のイテレーターを比較した際の挙動
	// 理　想：同じである(FALSE
	TEST(IteratorNotCompare, TestNotCompareWhenSameIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 同じイテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		// 同じであることを確認
		EXPECT_FALSE(it != it2);
	}
	// 項　目：異なるイテレーターを比較した際の挙動
	// 理　想：異なるものである(TRUE)
	TEST(IteratorNotCompare, TestNotCompareWhenDifferentIterator)
	{
		// リストを作成
		InteractiveList<int> list;
		// リストにデータを挿入
		list.pushBack(1);
		list.pushBack(2);
		// 異なるイテレーターを取得
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		it2++;
		// 異なるものであることを確認
		EXPECT_TRUE(it != it2);
	}

}// イテレーターのテスト