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
		InteractiveNode(): m_pPrevData(nullptr), m_pNextData(nullptr), m_Data(){
		}

		// @brief コンストラクタ
		InteractiveNode(const T& In_Value):m_Data(In_Value), m_pPrevData(nullptr), m_pNextData(nullptr){
		}
		
		// @brief デストラクタ
		~InteractiveNode() = default;

		// @brief データ
		T m_Data;
		// @brief 前のデータ
		InteractiveNode* m_pPrevData;
		// @brief 次のデータ
		InteractiveNode* m_pNextData;
	};

	// @brief 双方向リスト用コンストイテレーター
	template<typename T>
	class InteractiveConstIterator
	{
		// リストクラスをフレンドに設定
		friend class InteractiveList<T>;

	private:
		// 型エイリアス
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator<T>;
	public:

		// @brief デフォルトコンストラクタ
		InteractiveConstIterator() : m_pCurrent(nullptr), m_pOwner(nullptr){
		}	

		// @brief コンストラクタ
		InteractiveConstIterator(const Node* node, const List* owner){
			m_pCurrent = const_cast<Node*>(node);
			m_pOwner = const_cast<List*>(owner);
		}

		// @brief コピーコンストラクタ
		InteractiveConstIterator(const Self& other) {
			m_pCurrent = other.m_pCurrent;
			m_pOwner = other.m_pOwner;
		}


		// @brief 前置インクリメント
		Self& operator++() {
			// アサートチェック
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// 次のノードへ移動
			if (m_pCurrent) m_pCurrent = m_pCurrent->m_pNextData;
			return *this;
		}

		// @brief 後置インクリメント
		Self operator++(int) {
			Self temp = *this;
			++(*this);
			return temp;
		}

		// @brief 前置デクリメント
		Self& operator--() {
			// アサートチェック
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// 前のノードへ移動
			if (m_pCurrent) m_pCurrent = m_pCurrent->m_pPrevData;
			return *this;
		}

		// @brief 後置デクリメント
		Self operator--(int) {
			Self temp = *this;
			--(*this);
			return temp;
		}

		// @brief データへの参照(const版)
		const T& operator*() const {
			// アサートチェック
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// データを返す
			return m_pCurrent->m_Data;
		}

		// @brief ポインタアクセス
		const T* operator->() const {
			// アサートチェック
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// データを返す
			return &(m_pCurrent->m_Data);
		}

		// @brief 代入演算子
		const Self& operator=(const Self& other) {
			// 自分自身への代入でないことを確認
			if (this != &other) {
				m_pCurrent = other.m_pCurrent;
				m_pOwner = other.m_pOwner;
			}
			return *this;
		}

		// @brief 比較演算子
		bool operator==(Self& other) {
			return m_pCurrent == other.m_pCurrent;
		}
		// @brief 比較演算子(const版)
		bool operator==(const Self& other) const {
			return m_pCurrent == other.m_pCurrent;
		}

		// @brief 不等比較演算子
		bool operator!=(Self& other) {
			return !(*this == other);
		}
		// @brief 不等比較演算子(const版)
		bool operator!=(const Self& other) const {
			return !(*this == other);
		}

		// @brief 所属するリストを取得
		const List* owner()const {
			return m_pOwner;
		}
	protected:
		// @brief 現在のノード
		Node* m_pCurrent;
		// @brief 所属するリスト
		List* m_pOwner;
	};

	// @brief 双方向リスト用イテレーター
	template<typename T>
	class InteractiveIterator : public InteractiveConstIterator<T>
	{
		// リストクラスをフレンドに設定
		friend class InteractiveList<T>;

	private:
		// 型エイリアス
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveIterator<T>;
		using Base = InteractiveConstIterator<T>;
	public:

		// @brief デフォルトコンストラクタ
		InteractiveIterator() : Base() {
		}

		// @brief コンストラクタ
		InteractiveIterator(Node* node, List* owner) : Base(node, owner) {
		}

		// @brief コピーコンストラクタ
		InteractiveIterator(const Self& other) : Base(other) {
		}


		// @brief データへの参照(非const版)
		T& operator* () {
			// アサートチェック
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
			// データを返す
			return Base::m_pCurrent->m_Data;
		}

		// @brief データへの参照(非const版)
		T* operator->() {
			// アサートチェック
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
			// データを返す
			return &(Base::m_pCurrent->m_Data);
		}
	};

public:
	// 型エイリアス
	using Node = InteractiveNode;
	using Iterator = InteractiveIterator<T>;
	using const_Iterator = InteractiveConstIterator<T>;

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
	bool erase(const_Iterator pos);

	// @brief 要素の挿入
	bool insert(const_Iterator pos, const T& value);
	
private:
	// @brief ダミーノード
	Node m_Dummy;
	// @brief データ総数
	size_t m_Size;
};

// インラインファイルのインクルード
#include "InteractiveList.inl"