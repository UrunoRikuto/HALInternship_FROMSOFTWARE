/*＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
* 
* @file InteractiveList.h
* @brief 双方向リストのヘッダーファイル
* 
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝*/

#pragma once
#include <cassert>

// @brief 双方向リストクラス
// @typeparam T 保存するデータの型
template<typename T>
class InteractiveList
{
private:
	// @brief 双方向リストのデータクラス
	struct InteractiveNode
	{
		// @brief デフォルトコンストラクタ
		InteractiveNode();

		// @brief コンストラクタ
		InteractiveNode(const T& In_Value);
		
		// @brief デストラクタ
		~InteractiveNode();

		// @brief データ
		T m_Data;
		// @brief 前のデータ
		InteractiveNode* m_pPrevData;
		// @brief 次のデータ
		InteractiveNode* m_pNextData;
	};

	// @brief 双方向リスト用コンストイテレーター
	class InteractiveConstIterator
	{
		// リストクラスをフレンドに設定
		friend class InteractiveList<T>;

	private:
		// 型エイリアス
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator;
	public:

		// @brief デフォルトコンストラクタ
		InteractiveConstIterator();

		// @brief コンストラクタ
		// @param node ノードポインタ
		// @param owner 所属するリストポインタ
		InteractiveConstIterator(const Node* node, const List* owner);

		// @brief コピーコンストラクタ
		// @param other コピー元のイテレーター
		InteractiveConstIterator(const Self& other);


		// @brief 前置インクリメント
		Self& operator++();

		// @brief 後置インクリメント
		Self operator++(int);

		// @brief 前置デクリメント
		Self& operator--();

		// @brief 後置デクリメント
		Self operator--(int);

		// @brief データへの参照(const版)
		const T& operator*() const;

		// @brief ポインタアクセス
		const T* operator->() const;

		// @brief 代入演算子
		// @param other 代入元のイテレーター
		const Self& operator=(const Self& other);

		// @brief 比較演算子
		// @param other 比較するイテレーター
		bool operator==(Self& other);
		// @brief 比較演算子(const版)
		// @param other 比較するイテレーター
		bool operator==(const Self& other) const;

		// @brief 不等比較演算子
		// @param other 比較するイテレーター
		bool operator!=(Self& other);
		// @brief 不等比較演算子(const版)
		// @param other 比較するイテレーター
		bool operator!=(const Self& other) const;

		// @brief 所属するリストを取得
		const List* owner()const;
	protected:
		// @brief 現在のノード
		Node* m_pCurrent;
		// @brief 所属するリスト
		List* m_pOwner;
	};

	// @brief 双方向リスト用イテレーター
	class InteractiveIterator : public InteractiveConstIterator
	{
		// リストクラスをフレンドに設定
		friend class InteractiveList<T>;

	private:
		// 型エイリアス
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveIterator;
		using Base = InteractiveConstIterator;
	public:

		// @brief デフォルトコンストラクタ
		InteractiveIterator();

		// @brief コンストラクタ
		// @param node ノードポインタ
		// @param owner 所属するリストポインタ
		InteractiveIterator(Node* node, List* owner);

		// @brief コピーコンストラクタ
		InteractiveIterator(const Self& other);


		// @brief データへの参照(非const版)
		T& operator* ();

		// @brief データへの参照(非const版)
		T* operator->();
	};

public:
	// 型エイリアス
	using Node = InteractiveNode;
	using Iterator = InteractiveIterator;
	using const_Iterator = InteractiveConstIterator;

	// @brief コンストラクタ
	InteractiveList();

	// @brief コンストラクタ(コピーコンストラクタ)
	InteractiveList(const InteractiveList& other);

	// @brief デストラクタ
	~InteractiveList();

	// @brief リストのデータの総数を取得
	// @return データの総数
	const size_t getSize() const;

	// @brief リストが空かどうかを取得
	bool isEmpty() const;

	// @brief リストをクリア
	void clear();

	// @brief 先頭にデータを追加
	// @param In_Value 追加するデータ
	void pushFront(const T& In_Value);

	// @brief 末尾にデータを追加
	// @param In_Value 追加するデータ
	void pushBack(const T& In_Value);

	// @brief 先頭のデータを削除
	void popFront();

	// @brief 末尾のデータを削除
	void popBack();

	// @brief 先頭のconst版イテレーターの取得
	const const_Iterator cbegin() const;
	// @brief 先頭の非const版イテレーターの取得
	Iterator begin();

	// @brief 末尾のconst版イテレーターの取得
	const const_Iterator cend() const;
	// @brief 末尾の非const版イテレーターの取得
	Iterator end();

	// @brief 逆方向の先頭のconst版イテレーターの取得
	const const_Iterator crbegin() const;
	// @brief 逆方向の先頭の非const版イテレーターの取得
	Iterator rbegin();

	// @brief 逆方向の末尾のconst版イテレーターの取得
	const const_Iterator crend() const;
	// @brief 逆方向の末尾の非const版イテレーターの取得
	Iterator rend();

	// @brief 要素の削除
	// @param pos 削除する要素のイテレーター
	// @return 削除に成功したらtrue,失敗したらfalse
	bool erase(const_Iterator pos);

	// @brief 要素の挿入
	// @param pos 挿入する位置のイテレーター
	// @param value 挿入するデータ
	// @return 挿入に成功したらtrue,失敗したらfalse
	bool insert(const_Iterator pos, const T& value);
	
	// @brief ノードのデータを交換
	// @param NodeA 交換するノードAのイテレーター
	// @param NodeB 交換するノードBのイテレーター
	void swap(const_Iterator NodeA, const_Iterator NodeB);

public:
	// @brief ソートの順序
	enum class SortOrder
	{
		Ascending,	// 昇順
		Descending, // 降順
	};
	// @brief ソートアルゴリズムの種類
	enum class SortAlgorithm
	{
		QuickSort,	// クイックソート
	};
	// @brief リストをソート
	template<typename U>
	void sort(SortAlgorithm type, SortOrder order);
private:

	// @brief 2つのデータを比較し、aがbより小さいかどうかを判定
	// @param a 比較するデータ
	// @param b 比較するデータ
	// @return aがbより小さい場合true,そうでない場合false
	template<typename U>
	bool _isLess(const T& a, const T& b);

	// @brief ピポット値を基準にリストのノードを左右に分割する
	// @param start パーティションの開始イテレーター
	// @param end パーティションの終了イテレーター
	// @return 新しいピボットのイテレーター
	template<typename U>
	const_Iterator _partition(const_Iterator start, const_Iterator end);

	// @brief クイックソートの実装
	// @param start ソートする範囲の開始イテレーター
	// @param end ソートする範囲の終了イテレーター
	template<typename U>
	void _quickSort(const_Iterator start, const_Iterator end);

	// @brief リストを反転
	void _reverse();
private:
	// @brief ダミーノード
	Node m_Dummy;
	// @brief データ総数
	size_t m_Size;
};

// インラインファイルのインクルード
#include "InteractiveList.inl"