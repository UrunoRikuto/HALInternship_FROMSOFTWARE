/*＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
* 
* @file InteractiveList.h
* @brief 双方向リストのヘッダーファイル
* 
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝*/

#pragma once

/// <summary>
/// 双方向リストのデータクラス
/// </summary>
/// <typeparam name="T">保存するデータの型</typeparam>
template<typename T>
class InteractiveNode
{
	// 関数
public:
	// @brief コンストラクタ
	InteractiveNode(const T& In_Value)
		:m_Data(In_Value)
		, m_pPrevData(nullptr)
		, m_pNextData(nullptr)
	{
	}

	// 変数
public:
	// @brief データ
	T m_Data;
	// @brief 前のデータ
	InteractiveNode* m_pPrevData;
	// @brief 次のデータ
	InteractiveNode* m_pNextData;
};

/// <summary>
/// 双方向リスト用イテレーター
/// </summary>
template<typename T>
class InteractiveIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveIterator<T>;

	InteractiveIterator(Node* node) : m_Current(node) {}

	// 前置インクリメント
	Self& operator++() {
		if (m_Current) m_Current = m_Current->m_pNextData;
		return *this;
	}

	// 後置インクリメント
	Self operator++(int) {
		Self temp = *this;
		++(*this);
		return temp;
	}

	// 前置デクリメント
	Self& operator--() {
		if (m_Current) m_Current = m_Current->m_pPrevData;
		return *this;
	}

	// 後置デクリメント
	Self operator--(int) {
		Self temp = *this;
		--(*this);
		return temp;
	}

	// データへの参照
	T& operator*() const {
		return m_Current->m_Data;
	}

	// ポインタアクセス
	T* operator->() const {
		return &(m_Current->m_Data);
	}

	// 比較演算子
	bool operator==(const Self& other) const {
		return m_Current == other.m_Current;
	}

	bool operator!=(const Self& other) const {
		return !(*this == other);
	}

private:
	Node* m_Current;

};

/// <summary>
/// 双方向リストクラス
/// </summary>
/// <typeparam name="T">リストに保存する型</typeparam>
template<typename T>
class InteractiveList
{
public:
	// @brief コンストラクタ
	InteractiveList()
		:m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_Size(0)
	{
	}

	// @brief デストラクタ
	~InteractiveList() { Clear(); }

	// @brief リストのデータの総数を取得
	// @return データの総数
	const size_t GetListSize() { return m_Size; }

	// @brief リストが空かどうかを取得
	const bool IsEmpty() { return m_Size == 0; }

	// @brief 先頭データを取得
	// @return 先頭データ
	const InteractiveNode<T>* GetFront() { return m_pHead; }

	// @brief 末尾データを取得
	// @return 末尾データ
	const InteractiveNode<T>* GetBack() { return m_pTail; }

	// @brief リストをクリア
	void Clear() {
		// データがなくなるまで先頭のデータを削除
		while (!IsEmpty()) {
			popFront();
		}
	}

	// @brief 先頭にデータを追加
	// @param In_Value 追加するデータ
	void pushFront(const T& In_Value) {
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// リストが空の場合
		if (IsEmpty()) {
			// 先頭と末尾を新しいノードに設定
			m_pHead = m_pTail = newNode;
		}
		// リストにデータがある場合
		else {
			// 追加前の先頭データを新しいノードの次のデータに設定
			newNode->m_pNextData = m_pHead;
			// 追加前の先頭データの前のデータを新しいノードに設定
			m_pHead->m_pPrevData = newNode;
			// 先頭データを新しいノードに設定
			m_pHead = newNode;
		}
		// データ数を増やす
		m_Size++;
	}

	// @brief 末尾にデータを追加
	// @param In_Value 追加するデータ
	void pushBack(const T& In_Value) {
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// リストが空の場合
		if (IsEmpty()) {
			// 先頭と末尾を新しいノードに設定
			m_pHead = m_pTail = newNode;
		}
		// リストにデータがある場合
		else {
			// 追加前の末尾データを新しいノードの前のデータに設定
			newNode->m_pPrevData = m_pTail;
			// 追加前の末尾データの次のデータを新しいノードに設定
			m_pTail->m_pNextData = newNode;
			// 末尾データを新しいノードに設定
			m_pTail = newNode;
		}
		// データ数を増やす
		m_Size++;
	}

	// @brief 先頭のデータを削除
	void popFront() {
		// リストが空の場合は処理しない
		if (IsEmpty()) return;
		// 先頭データを一時保存
		InteractiveNode<T>* tempNode = m_pHead;
		// データの総数が1つの場合
		if (m_Size == 1) {
			//先頭と末尾をnullptrに設定
			m_pHead = m_pTail = nullptr;
		}
		// データの総数が複数の場合
		else {
			// 先頭データを次のデータに設定
			m_pHead = m_pHead->m_pNextData;
			// 新しい先頭データの前のデータをnullptrに設定
			m_pHead->m_pPrevData = nullptr;
		}
		// 一時保存していた先頭データを削除
		delete tempNode;
		// データ数を減らす
		m_Size--;
	}

	// @brief 末尾のデータを削除
	void popBack() {
		// リストが空の場合は処理しない
		if (IsEmpty()) return;
		// 末尾データを一時保存
		InteractiveNode<T>* tempNode = m_pTail;
		// データの総数が1つの場合
		if (m_Size == 1) {
			//先頭と末尾をnullptrに設定
			m_pHead = m_pTail = nullptr;
		}
		// データの総数が複数の場合
		else {
			// 末尾データを前のデータに設定
			m_pTail = m_pTail->m_pPrevData;
			// 新しい末尾データの次のデータをnullptrに設定
			m_pTail->m_pNextData = nullptr;
		}
		// 一時保存していた末尾データを削除
		delete tempNode;
		// データ数を減らす
		m_Size--;
	}

	// イテレーター関連
	using Iterator = InteractiveIterator<T>;
	Iterator begin() { return Iterator(m_pHead); }
	Iterator end() { return Iterator(nullptr); }
	Iterator rbegin() { return Iterator(m_pTail); }
	Iterator rend() { return Iterator(nullptr); }


private:
	// @brief 先頭のデータ
	InteractiveNode<T>* m_pHead;
	// @brief 末尾のデータ
	InteractiveNode<T>* m_pTail;
	// @brief データ総数
	size_t m_Size;
};