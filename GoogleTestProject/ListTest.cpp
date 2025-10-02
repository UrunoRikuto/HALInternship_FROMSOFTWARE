#include "pch.h"
#include "/HAL/HALInternship_FROMSOFTWARE/HALInternship_FROMSOFTWARE/InteractiveList.h"

// リストのテスト
namespace List
{
	//=================================== データ数の取得 ===================================//
	// 項　目：リストが空の場合の戻り値
	// 理　想：0
	TEST(ListDataSize, 0)
	{
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：リスト末尾への挿入を行った際の戻り値
	// 理　想：1
	TEST(ListDataSize, 1)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// 項　目：リスト末尾への挿入が失敗した際の戻り値
	// 理　想：0
	TEST(ListDataSize, 2)
	{
		// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：データの挿入を行った際の戻り値
	// 理　想：1
	TEST(ListDataSize, 3)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.insert(it, 1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// 項　目：データの挿入が失敗した際の戻り値
	// 理　想：0
	TEST(ListDataSize, 4)
	{
		// "挿入失敗"はメモリ確保失敗時のためここではスキップ
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：データの削除を行った際の戻り値
	// 理　想：0
	TEST(ListDataSize, 5)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：データの削除が失敗した際の戻り値
	// 理　想：1
	TEST(ListDataSize, 6)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.end();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 1);
	}
	// 項　目：リストが空である場合に、データの削除を行った際の戻り値
	// 理　想：0
	TEST(ListDataSize, 7)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// 項　目：constのメソッドであるか
	// 理　想：コンパイルが通れば成功
	TEST(ListDataSize, 8)
	{
		const InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
}