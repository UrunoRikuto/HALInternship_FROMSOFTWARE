#if !defined ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
#define      ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___

//--------------------------------------------------------------------------------
// マクロ定義
//--------------------------------------------------------------------------------
// コンパイル関連手動テスト(リスト)

/* constのメソッドであるか
※コンパイルが通れば成功*/
//#define TT_TEST_GET_DATA_SIZE_IS_CONST

/* 非constのメソッドであるか(挿入)
* ※コンパイルが通らなければ成功*/
//#define TT_TEST_INSERT_WHEN_CONST

/* 非constのメソッドであるか(削除)
* ※コンパイルが通らなければ成功*/
//#define TT_TEST_ERASE_WHEN_CONST

/* const版リストでconst版イテレーター以外のイテレーターで値の取得ができないか
* ※コンパイルが通らなければ成功*/
//#define TT_TEST_BEGIN_WHEN_CONST_LIST

/* constのメソッドであるか(const版先頭イテレーター)
* ※コンパイルが通れば成功*/
//#define TT_TEST_CONST_BEGIN_WHEN_CONST

/* const版リストでconst版イテレーター以外のイテレーターで値の取得ができないか
* ※コンパイルが通らなければ成功*/
//#define TT_TEST_END_WHEN_CONST_LIST

/* constのメソッドであるか(const版末尾イテレーター)
* ※コンパイルが通れば成功*/
//#define TT_TEST_CONST_END_WHEN_CONST

#endif // ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___