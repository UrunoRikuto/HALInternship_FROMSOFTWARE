/*＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
* 
* @file InteractiveList.h
* @brief 双方向リストのヘッダーファイル
* 
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝*/

#pragma once

// @brief 双方向リストのデータクラス
// @typeparam T 保存するデータの型
template<typename T>
struct InteractiveNode
{
	// @brief コンストラクタ
	InteractiveNode(const T& In_Value)
		:m_Data(In_Value)
		, m_pPrevData(nullptr)
		, m_pNextData(nullptr)
	{
	}

	// @brief データ
	T m_Data;
	// @brief 前のデータ
	InteractiveNode* m_pPrevData;
	// @brief 次のデータ
	InteractiveNode* m_pNextData;
};

// @brief 双方向リスト用イテレーター
// @typeparam T 保存するデータの型
template<typename T>
class InteractiveIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveIterator<T>;

	// @brief コンストラクタ
	InteractiveIterator(Node* node) : m_pCurrent(node) {}

	// @brief 前置インクリメント
	Self& operator++() {
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
	const T& operator*() {
		return m_pCurrent->m_Data;
	}

	// @brief 代入演算子
	Self& operator=(const Self& other) {
		if (this != &other) {
			m_pCurrent = other.m_pCurrent;
		}
		return *this;
	}

	// @brief ポインタアクセス
	const T* operator->() {
		return &(m_pCurrent->m_Data);
	}

	// @brief 比較演算子
	const bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}

	// @brief 不等比較演算子
	const bool operator!=(const Self& other) {
		return !(*this == other);
	}

private:
	Node* m_pCurrent;

};

// @brief 双方向リストクラス
// @typeparam T 保存するデータの型
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
	~InteractiveList() { clear(); }

	// @brief リストのデータの総数を取得
	// @return データの総数
	const size_t getSize() { return m_Size; }

	// @brief リストが空かどうかを取得
	const bool isEmpty() { return m_Size == 0; }

	// @brief リストをクリア
	void clear() {
		// データがなくなるまで先頭のデータを削除
		while (!isEmpty()) {
			popFront();
		}
	}

	// @brief 先頭データを取得
	// @return 先頭データ
	const InteractiveNode<T>* getFront() { return m_pHead; }

	// @brief 末尾データを取得
	// @return 末尾データ
	const InteractiveNode<T>* getBack() { return m_pTail; }

	// @brief 先頭にデータを追加
	// @param In_Value 追加するデータ
	void pushFront(const T& In_Value) {
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// リストが空の場合
		if (isEmpty()) {
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
		if (isEmpty()) {
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
		if (isEmpty()) return;
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
		if (isEmpty()) return;
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
