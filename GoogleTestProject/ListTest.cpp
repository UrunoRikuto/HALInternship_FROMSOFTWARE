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
		InteractiveList<int> list;
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：リスト末尾への挿入を行った際の戻り値
	// 理　想：1
	TEST(ListDataSize, TestGetDataSizeIsPushBackToTRUE)
	{
		InteractiveList<int> list;
		list.pushBack(1);
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
		InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();
		list.insert(it, 1);
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
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::Iterator it = list.begin();
		list.erase(it);
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：データの削除が失敗した際の戻り値
	// 理　想：1
	TEST(ListDataSize, TestGetDataSizeIsEraseToFALSE)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::Iterator it = list.end();
		it++;
		list.erase(it);
		EXPECT_EQ(1, list.getSize());
	}
	// 項　目：リストが空である場合に、データの削除を行った際の戻り値
	// 理　想：0
	TEST(ListDataSize, TestGetDataSizeIsEraseWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();
		list.erase(it);
		EXPECT_EQ(0, list.getSize());
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListDataSize, TestGetDataSizeConst)
	{
#if defined TT_TEST_GET_DATA_SIZE_WHEN_CONST
		const InteractiveList<int> list;
		EXPECT_EQ(0, list.getSize());
#endif //TT_TEST_GET_DATA_SIZE_WHEN_CONST
		SUCCEED();
	}

	//=================================== データの挿入 ===================================//
	// 項　目：リストが空である場合に、挿入した際の挙動
	// 理　想：先頭イテレーターと末尾イテレーターのどちらで行っても成功
	TEST(ListInsert, TestInsertWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::Iterator it_begin = list.begin();
		InteractiveList<int>::Iterator it_end = list.rbegin();
		/// 先頭イテレーター ///
		ASSERT_TRUE(list.insert(it_begin, 1));
		EXPECT_EQ(1, list.getSize());

		list.clear();
		
		/// 末尾イテレーター ///
		ASSERT_TRUE(list.insert(it_end, 1));
		EXPECT_EQ(1, list.getSize());
	}
	// 項　目：リストに複数のデータがある場合に、先頭イテレーターを渡して挿入した際の挙動
	// 理　想：先頭に挿入されて元々のデータが後ろにずれる
	TEST(ListInsert, TestInsertWhenHaveDataToBegin)
	{
		InteractiveList<int> list;
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it_begin = list.begin();
		ASSERT_TRUE(list.insert(it_begin, 1));

		InteractiveList<int>::Iterator it = list.begin();

	
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
		InteractiveList<int> list;
		list.clear();

		list.pushBack(1);
		list.pushBack(3);
		InteractiveList<int>::Iterator it_end = list.rbegin();
		ASSERT_TRUE(list.insert(it_end, 2));

		InteractiveList<int>::Iterator it = list.begin();
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
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		ASSERT_TRUE(list.insert(it, 2));

		it = list.begin();
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
		InteractiveList<int> list;

		list.pushBack(1);
		list.pushBack(3);
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;
		list.insert(const_it, 2);
		InteractiveList<int>::Iterator it = list.begin();
		it = list.begin();
		EXPECT_EQ(1,(*it));
		it++;
		EXPECT_EQ(2,(*it));
		it++;
		EXPECT_EQ(3,(*it));
	}
	// 項　目：不正なイテレーターを渡して挿入した際の挙動
	// 理　想：挿入に失敗してデータ数は増えない
	TEST(ListInsertXX, TestInsertWhenInvalidIterator)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		InteractiveList<int> list2;
		list2.pushBack(3);
		InteractiveList<int>::Iterator it = list2.begin();
		it++;
		ASSERT_FALSE(list.insert(it, 4));
		EXPECT_EQ(list.getSize(), 2);
	}
	// 項　目：非constのメソッドであるか
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListInsert, TestInsertWhenConst)
	{
#if defined TT_TEST_INSERT_WHEN_CONST
		const InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();
		list.insert(it, 1);
#endif //TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

	/*
	//=================================== データの削除 ===================================//
	// 項　目：リストが空である場合に、データの削除を行った際の挙動
	// 理　想：何も起こらない
	TEST(ListErase, TestEraseWhenEmpty)
	{
		InteractiveList<int> list;
		// 先頭イテレーター
		InteractiveList<int>::Iterator it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
		// 末尾イテレーター
		it = list.rbegin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：リストに複数のデータがある場合に、先頭イテレーターを渡して削除した際の挙動
	// 理　想：先頭のデータが削除されて、2番目以降のデータが前にずれる
	TEST(ListErase, TestEraseWhenHaveDataToBegin)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it_begin = list.begin();
		list.erase(it_begin);
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ((*it), 2);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：リストに複数のデータがある場合に、末尾イテレーターを渡して削除した際の挙動
	// 理　想：末尾のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenHaveDataToEnd)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it_end = list.rbegin();
		list.erase(it_end);
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 2);
	}
	// 項　目：リストに複数のデータがある場合に、先頭でも末尾でもないイテレーターを渡して削除した際の挙動
	// 理　想：指定した位置のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenHaveDataToMiddle)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		list.erase(it);
		it = list.begin();
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：Const版イテレーターを渡して削除した際の挙動
	// 理　想：指定した位置のデータが削除されて、元々のデータはそのまま
	TEST(ListErase, TestEraseWhenConstIterator)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;
		list.erase(const_it);
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// 項　目：不正なイテレーターを渡して削除した際の挙動
	// 理　想：削除に失敗してデータ数は増えない
	TEST(ListErase, TestEraseWhenInvalidIterator)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		InteractiveList<int> list2;
		list2.pushBack(3);
		InteractiveList<int>::Iterator it = list2.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 2);
	}
	// 項　目：非constのメソッドであるか
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListErase, TestEraseWhenConst)
	{
#if defined TT_TEST_ERASE_WHEN_CONST
		const InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();//ここでエラー
		list.erase(it);//ここでエラー
#endif //TT_TEST_ERASE_WHEN_CONST
		SUCCEED();
	}

	//============================= 先頭イテレーター =============================//
	// 項　目：リストが空である場合に、先頭イテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(it, nullptr);
	}
	// 項　目：リストに要素が一つある場合に、先頭イテレーターを取得した際の挙動
	// 理　想：その要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの挿入を行った後に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginAfterInsert)
	{
		InteractiveList<int> list;
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		list.insert(it, 1);
		it = list.begin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの削除を行った後に、先頭イテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListBegin, TestBeginAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		list.erase(it);
		it = list.begin();
		EXPECT_EQ((*it), 2);
	}
	// 項　目：constのリストからConst版イテレーターでない先頭イテレーターを取得した際の挙動
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListBegin, TestBeginWhenConstList)
	{
#if defined TT_TEST_BEGIN_WHEN_CONST_LIST
		const InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.begin();//ここでエラー
#endif //TT_TEST_BEGIN_WHEN_CONST_LIST
		SUCCEED();
	}

	//============================= 先頭コンストイテレーター =============================//
	// 項　目：リストが空である場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::const_Iterator const_beginit = list.cbegin();
		EXPECT_EQ(const_beginit, nullptr);
	}
	// 項　目：リストに要素が一つある場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：その要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::const_Iterator it = list.cbegin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、先頭コンストイテレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::const_Iterator it = list.cbegin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの挿入を行った後に、先頭コンストイレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginAfterInsert)
	{
		InteractiveList<int> list;
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		list.insert(it, 1);
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		EXPECT_EQ((*const_it), 1);
	}
	// 項　目：データの削除を行った後に、先頭コンストイレーターを取得した際の挙動
	// 理　想：先頭の要素を指すイテレーターが返る
	TEST(ListConstBegin, TestConstBeginAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.begin();
		list.erase(it);
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		EXPECT_EQ((*const_it), 2);
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListConstBegin, TestConstBeginWhenConst)
	{
#if defined TT_TEST_CONST_BEGIN_WHEN_CONST
		const InteractiveList<int> list;
		InteractiveList<int>::const_Iterator it = list.cbegin();
		EXPECT_EQ(it, nullptr);
#endif //TT_TEST_CONST_BEGIN_WHEN_CONST
		SUCCEED();
	}

	//============================= 末尾イテレーター=============================//
	// 項　目：リストが空である場合に、末尾イテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListEnd, TestEndWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.rbegin();
		EXPECT_EQ(it, nullptr);
	}
	// 項　目：リストに要素が一つある場合に、末尾イテレーターを取得した際の挙動
	// 理　想：その要素を指すイテレーターが返る
	TEST(ListEnd, TestEndWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.rbegin();
		EXPECT_EQ((*it), 3);
	}
	// 項　目：データの挿入を行った後に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndAfterInsert)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.rbegin();
		list.insert(it, 2);
		it = list.rbegin();
		EXPECT_EQ((*it), 3);
		it--;
		EXPECT_EQ((*it), 2);
		it--;
		EXPECT_EQ((*it), 1);
	}
	// 項　目：データの削除を行った後に、末尾イテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListEnd, TestEndAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.rbegin();
		list.erase(it);
		it = list.rbegin();
		EXPECT_EQ((*it), 2);
		it--;
		EXPECT_EQ((*it), 1);
	}
	// 項　目：constのリストからConst版イテレーターでない末尾イテレーターを取得した際の挙動
	// 理　想：マクロ定義してコンパイルエラーになれば成功
	TEST(ListEnd, TestEndWhenConstList)
	{
#if defined TT_TEST_END_WHEN_CONST_LIST
		const InteractiveList<int> list;
		InteractiveList<int>::Iterator it = list.rbegin();//ここでエラー
#endif //TT_TEST_END_WHEN_CONST_LIST
		SUCCEED();
	}
	// ============================= Const版末尾イテレーター =============================//
	// 項　目：リストが空である場合に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：ダミーノードを指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenEmpty)
	{
		InteractiveList<int> list;
		InteractiveList<int>::const_Iterator it = list.crbegin();
		EXPECT_EQ(it, nullptr);
	}
	// 項　目：リストに要素が一つある場合に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：その要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		InteractiveList<int>::const_Iterator it = list.crbegin();
		EXPECT_EQ((*it), 1);
	}
	// 項　目：リストに複数の要素がある場合に、末尾コンストイレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::const_Iterator it = list.crbegin();
		EXPECT_EQ((*it), 3);
	}
	// 項　目：データの挿入を行った後に、末尾コンストイテレーターを取得した際の挙動
	TEST(ListConstEnd, TestConstEndAfterInsert)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.rbegin();
		list.insert(it, 2);
		InteractiveList<int>::const_Iterator const_it = list.crbegin();
		EXPECT_EQ((*const_it), 3);
		const_it--;
		EXPECT_EQ((*const_it), 2);
		const_it--;
		EXPECT_EQ((*const_it), 1);
	}
	// 項　目：データの削除を行った後に、末尾コンストイテレーターを取得した際の挙動
	// 理　想：末尾の要素を指すイテレーターが返る
	TEST(ListConstEnd, TestConstEndAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		InteractiveList<int>::Iterator it = list.rbegin();
		list.erase(it);
		InteractiveList<int>::const_Iterator const_it = list.crbegin();
		EXPECT_EQ((*const_it), 2);
		const_it--;
		EXPECT_EQ((*const_it), 1);
	}
	// 項　目：constのメソッドであるか
	// 理　想：マクロ定義してコンパイルが通れば成功
	TEST(ListConstEnd, TestConstEndWhenConst)
	{
#if defined TT_TEST_CONST_END_WHEN_CONST
		const InteractiveList<int> list;
		InteractiveList<int>::const_Iterator it = list.crbegin();
		EXPECT_EQ(it, nullptr);
#endif //TT_TEST_CONST_END_WHEN_CONST
		SUCCEED();
	}
	*/
}