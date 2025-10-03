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
// @typeparam T 保存するデータの型
template<typename T>
class InteractiveConstIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveConstIterator<T>;

	// @brief コンストラクタ
	InteractiveConstIterator(Node* node) : m_pCurrent(node) {
	}

	// @brief コピーコンストラクタ
	InteractiveConstIterator(const Self& other) : m_pCurrent(other.m_pCurrent) {
	}

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

	// @brief ノード本体へのアクセス(const版)
	Node* operator*() const {
		return m_pCurrent;
	}

	// @brief 代入演算子
	Self& operator=(const Self& other) {
		if (this != &other) {
			m_pCurrent = other.m_pCurrent;
		}
		return *this;
	}

	// @brief ポインタアクセス
	T* operator->() const {
		return &(m_pCurrent->m_Data);
	}

	// @brief 比較演算子
	const bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}
	const bool operator==(const Node& other) const {
		return m_pCurrent == other;
	}

	// @brief 不等比較演算子
	const bool operator!=(const Self& other) {
		return !(*this == other);
	}
	const bool operator!=(const Node& other) const {
		return m_pCurrent != other;
	}

private:
	// @brief 現在のノード
	Node* m_pCurrent;

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
	InteractiveIterator(Node* node) : m_pCurrent(node) {
	}
	
	// @brief コピーコンストラクタ
	InteractiveIterator(const Self& other) : m_pCurrent(other.m_pCurrent) {
	}

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

	// @brief データへの参照(非const版)
	T& operator->() {
		return m_pCurrent->m_Data;
	}

	// @brief ノード本体へのアクセス(非const版)
	Node* operator* () {
		return m_pCurrent;
	}

	// @brief 比較演算子
	bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}

	// @brief 不等比較演算子
	bool operator!=(const Self& other) {
		return !(*this == other);
	}

private:
	// @brief コンストラクタ
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

	// @brief ディープコピーコンストラクタ
	// @param other コピー元のリスト
	InteractiveList(const InteractiveList<T>& other)
		:m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_Size(0)
	{
		// 他のリストのデータをすべてコピー
		for (const auto& value : other) {
			pushBack(value->m_Data);
		}
	}

	// @brief デストラクタ
	~InteractiveList() {
		clear(); 
	}

	// @brief リストのデータの総数を取得
	// @return データの総数
	const size_t getSize() const {
		return m_Size; }

	// @brief リストが空かどうかを取得
	bool isEmpty() const {
		return m_Size == 0; 
	}

	// @brief リストをクリア
	void clear() {
		// データがなくなるまで先頭のデータを削除
		while (!isEmpty()) {
			popFront();
		}
	}

	// @brief 先頭にデータを追加
	// @param In_Value 追加するデータ
	void pushFront(const T& In_Value) {
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(In_Value);
		// メモリ確保失敗時は処理しない
		if (!newNode) return;
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
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(In_Value);
		// メモリ確保に失敗した場合は処理しない
		if (!newNode) return;
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

	// const版イテレーター関連
	using const_Iterator = InteractiveConstIterator<T>;
	// 非const版イテレーター関連
	using Iterator = InteractiveIterator<T>;

	// @brief 先頭のconst版イテレーターの取得
	const_Iterator begin() const {
		return const_Iterator(m_pHead); 
	}
	// @brief 先頭の非const版イテレーターの取得
	Iterator begin() {
		return Iterator(m_pHead); 
	}

	// @brief 末尾のconst版イテレーターの取得
	const_Iterator end() const {
		return const_Iterator(nullptr); 
	}
	// @brief 末尾の非const版イテレーターの取得
	Iterator end() {
		return Iterator(nullptr); 
	}

	// @brief 逆方向の先頭のconst版イテレーターの取得
	const_Iterator rbegin() const {
		return const_Iterator(m_pTail); 
	}
	// @brief 逆方向の先頭の非const版イテレーターの取得
	Iterator rbegin() {
		return Iterator(m_pTail); 
	}

	// @brief 逆方向の末尾のconst版イテレーターの取得
	const_Iterator rend() const {
		return const_Iterator(nullptr); 
	}
	// @brief 逆方向の末尾の非const版イテレーターの取得
	Iterator rend() {
		return Iterator(nullptr); 
	}

	// @brief 要素の削除
	Iterator erase(Iterator pos) {
		// リストが空の場合は処理しない
		if (isEmpty()) return pos;
		// 削除するノードを取得
		InteractiveNode<T>* nodeToDelete = (*pos);
		if (!nodeToDelete) return pos;
		// ノードの前後のノードを取得
		InteractiveNode<T>* prevNode = nodeToDelete->m_pPrevData;
		InteractiveNode<T>* nextNode = nodeToDelete->m_pNextData;
		// 前のノードが存在する場合、その次のノードを更新
		if (prevNode) {
			prevNode->m_pNextData = nextNode;
		}
		else {
			// 削除するノードが先頭の場合、先頭を更新
			m_pHead = nextNode;
		}
		// 次のノードが存在する場合、その前のノードを更新
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// 削除するノードが末尾の場合、末尾を更新
			m_pTail = prevNode;
		}
		// ノードを削除
		delete nodeToDelete;
		m_Size--;
		// 次のノードへのイテレーターを返す
		return Iterator(nextNode);
	}
	const_Iterator erase(const_Iterator pos) {
		// リストが空の場合は処理しない
		if (isEmpty()) return pos;
		InteractiveList<T>* nonConstList = const_cast<InteractiveList<T>*>(this);
		// 削除するノードを取得
		InteractiveNode<T>* nodeToDelete = (*pos);
		if (!nodeToDelete) return pos;
		// ノードの前後のノードを取得
		InteractiveNode<T>* prevNode = nodeToDelete->m_pPrevData;
		InteractiveNode<T>* nextNode = nodeToDelete->m_pNextData;
		// 前のノードが存在する場合、その次のノードを更新
		if (prevNode) {
			prevNode->m_pNextData = nextNode;
		}
		else {
			// 削除するノードが先頭の場合、先頭を更新
			nonConstList->m_pHead = nextNode;
		}
		// 次のノードが存在する場合、その前のノードを更新
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// 削除するノードが末尾の場合、末尾を更新
			nonConstList->m_pTail = prevNode;
		}
		// ノードを削除
		delete nodeToDelete;
		nonConstList->m_Size--;
		// 次のノードへのイテレーターを返す
		return const_Iterator(nextNode);
	}

	// @brief 要素の挿入
	Iterator insert(Iterator pos, const T& value) {
		// 無効なイテレーターの場合は処理しない
		if (pos == end() && pos != begin() || pos == rend() && pos != rbegin()) return pos;
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(value);
		// メモリ確保に失敗した場合は処理しない
		if (!newNode) return pos;
		// 挿入位置がnullptrの場合、リストの末尾に挿入
		if (!(*pos)) {
			pushBack(value);
			m_Size--; // pushBackで増えた分を戻す
		}
		else {
			// 挿入位置のノードを取得
			InteractiveNode<T>* currentNode = (*pos);

			// 挿入位置の前に新しいノードを挿入
			newNode->m_pNextData = currentNode;
			newNode->m_pPrevData = currentNode->m_pPrevData;
			// 前のノードが存在する場合、その次のノードを新しいノードに更新
			if (currentNode->m_pPrevData) {
				currentNode->m_pPrevData->m_pNextData = newNode;
			}
			else {
				// 挿入位置が先頭の場合、先頭を更新
				m_pHead = newNode;
			}
			// 挿入位置の前のノードを新しいノードに更新
			currentNode->m_pPrevData = newNode;
		}
		// データ数を増やす
		m_Size++;
		// 新しいノードへのイテレーターを返す
		return Iterator(newNode);
	}
	const_Iterator insert(const_Iterator pos, const T& value) {

		const InteractiveList<T>& const_List = *this;

		// 無効なイテレーターの場合は処理しない
		if (pos == const_List.end() && pos != const_List.begin()
			|| pos == const_List.rend() && pos != const_List.rbegin()) return pos;
		// 新しいノードを作成
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(value);
		// メモリ確保に失敗した場合は処理しない
		if (!newNode) return pos;
		// 挿入位置がnullptrの場合、リストの末尾に挿入
		if (!(*pos)) {
			pushBack(value);
			m_Size--; // pushBackで増えた分を戻す
		}
		else {
			// 挿入位置のノードを取得
			InteractiveNode<T>* currentNode = (*pos);
			// 挿入位置の前に新しいノードを挿入
			newNode->m_pNextData = currentNode;
			newNode->m_pPrevData = currentNode->m_pPrevData;
			// 前のノードが存在する場合、その次のノードを新しいノードに更新
			if (currentNode->m_pPrevData) {
				currentNode->m_pPrevData->m_pNextData = newNode;
			}
			else {
				// 挿入位置が先頭の場合、先頭を更新
				m_pHead = newNode;
			}
			// 挿入位置の前のノードを新しいノードに更新
			currentNode->m_pPrevData = newNode;
		}
		// データ数を増やす
		m_Size++;
		// 新しいノードへのイテレーターを返す
		return const_Iterator(newNode);
	}
	
private:
	// @brief 先頭のデータ
	InteractiveNode<T>* m_pHead;
	// @brief 末尾のデータ
	InteractiveNode<T>* m_pTail;
	// @brief データ総数
	size_t m_Size;
};