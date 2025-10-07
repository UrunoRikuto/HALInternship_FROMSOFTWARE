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
	template<typename T>
	struct InteractiveNode
	{
		// @brief デフォルトコンストラクタ
		InteractiveNode()
			: m_pPrevData(nullptr)
			, m_pNextData(nullptr)
			, m_Data()
		{

		}

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
	template<typename T>
	class InteractiveConstIterator
	{
		// リストクラスをフレンドに設定
		friend class InteractiveList<T>;

	private:
		// 型エイリアス
		using Node = InteractiveNode<T>;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator<T>;
	public:

		// @brief デフォルトコンストラクタ
		InteractiveConstIterator() : m_pCurrent(nullptr), m_pOwner(nullptr) {
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
			assert(m_pCurrent != m_pOwner->m_pDummy);
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
			assert(m_pCurrent != m_pOwner->m_pDummy);
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
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// データを返す
			return m_pCurrent->m_Data;
		}

		// @brief ポインタアクセス
		const T* operator->() const {
			// アサートチェック
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// データを返す
			return &(m_pCurrent->m_Data);
		}

		// @brief 代入演算子
		const Self& operator=(const Self& other) {
			// 自分自身への代入でないことを確認
			if (this != &other) {
				m_pCurrent = other.m_pCurrent;
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
		using Node = InteractiveNode<T>;
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
			assert(Base::m_pCurrent != Base::m_pOwner->m_pDummy);
			// データを返す
			return Base::m_pCurrent->m_Data;
		}

		// @brief データへの参照(非const版)
		T* operator->() {
			// アサートチェック
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != Base::m_pOwner->m_pDummy);
			// データを返す
			return &(Base::m_pCurrent->m_Data);
		}
	};

public:
	// 型エイリアス
	using Node = InteractiveNode<T>;
	using Iterator = InteractiveIterator<T>;
	using const_Iterator = InteractiveConstIterator<T>;

	// @brief コンストラクタ
	InteractiveList() :m_Size(0){
		// ダミーノードを作成
		m_pDummy = new Node();
		m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
	}

	// @brief コンストラクタ(コピーコンストラクタ)
	InteractiveList(const InteractiveList& other) :m_Size(0){
		// ダミーノードを作成
		m_pDummy = other.m_pDummy;
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
		// 先頭と末尾をm_pDummyに設定
		m_pDummy = new Node();
		m_pDummy->m_pNextData = m_pDummy;
		m_pDummy->m_pPrevData = m_pDummy;
		m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
	}

	// @brief 先頭にデータを追加
	// @param In_Value 追加するデータ
	void pushFront(const T& In_Value) {
		// 新しいノードを作成
		Node* newNode = new(std::nothrow) Node(In_Value);
		// メモリ確保失敗時は処理しない
		if (!newNode) return;
		// リストが空の場合
		if (isEmpty()) {
			// 先頭と末尾を新しいノードに設定
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = newNode;
		}
		// リストにデータがある場合
		else {
			// 追加前の先頭データを新しいノードの次のデータに設定
			newNode->m_pNextData = m_pDummy->m_pNextData;
			// 追加前の先頭データを新しいノードの前のデータに設定
			newNode->m_pPrevData = m_pDummy;
			// 追加前の先頭データの前のデータを新しいノードに設定
			m_pDummy->m_pNextData->m_pPrevData = newNode;
			// 先頭データを新しいノードに設定
			m_pDummy->m_pNextData = newNode;
		}
		// データ数を増やす
		m_Size++;
	}

	// @brief 末尾にデータを追加
	// @param In_Value 追加するデータ
	void pushBack(const T& In_Value) {
		// 新しいノードを作成
		Node* newNode = new(std::nothrow) Node(In_Value);
		// メモリ確保に失敗した場合は処理しない
		if (!newNode) return;
		// リストが空の場合
		if (isEmpty()) {
			// 先頭と末尾を新しいノードに設定
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = newNode;
		}
		// リストにデータがある場合
		else {
			// 追加前の末尾データを新しいノードの前のデータに設定
			newNode->m_pPrevData = m_pDummy->m_pPrevData;
			// 追加前の末尾データを新しいノードの前のデータに設定
			newNode->m_pNextData = m_pDummy;
			// 追加前の末尾データの次のデータを新しいノードに設定
			m_pDummy->m_pPrevData->m_pNextData = newNode;
			// 末尾データを新しいノードに設定
			m_pDummy->m_pPrevData = newNode;
		}
		// データ数を増やす
		m_Size++;
	}

	// @brief 先頭のデータを削除
	void popFront() {
		// リストが空の場合は処理しない
		if (isEmpty()) return;
		// 先頭データを一時保存
		Node* tempNode = m_pDummy->m_pNextData;
		// データの総数が1つの場合
		if (m_Size == 1) {
			//先頭と末尾をnullptrに設定
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
		}
		// データの総数が複数の場合
		else {
			// 先頭データを次のデータに設定
			m_pDummy->m_pNextData = m_pDummy->m_pNextData->m_pNextData;
			// 新しい先頭データの前のデータをnullptrに設定
			m_pDummy->m_pNextData->m_pPrevData = m_pDummy;
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
		Node* tempNode = m_pDummy->m_pPrevData;
		// データの総数が1つの場合
		if (m_Size == 1) {
			//先頭と末尾をnullptrに設定
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
		}
		// データの総数が複数の場合
		else {
			// 末尾データを前のデータに設定
			m_pDummy->m_pPrevData = m_pDummy->m_pPrevData->m_pPrevData;
			// 新しい末尾データの次のデータをnullptrに設定
			m_pDummy->m_pPrevData->m_pNextData = m_pDummy;
		}
		// 一時保存していた末尾データを削除
		delete tempNode;
		// データ数を減らす
		m_Size--;
	}

	// @brief 先頭のconst版イテレーターの取得
	const const_Iterator cbegin() const {
		return const_Iterator(m_pDummy->m_pNextData, this);
	}
	// @brief 先頭の非const版イテレーターの取得
	Iterator begin() {
		return Iterator(m_pDummy->m_pNextData, this); 
	}

	// @brief 末尾のconst版イテレーターの取得
	const const_Iterator cend() const {
		return const_Iterator(m_pDummy, this);
	}
	// @brief 末尾の非const版イテレーターの取得
	Iterator end() {
		return Iterator(m_pDummy, this);
	}

	// @brief 逆方向の先頭のconst版イテレーターの取得
	const const_Iterator crbegin() const {
		return const_Iterator(m_pDummy->m_pPrevData, this);
	}
	// @brief 逆方向の先頭の非const版イテレーターの取得
	Iterator rbegin() {
		return Iterator(m_pDummy->m_pPrevData, this); 
	}

	// @brief 逆方向の末尾のconst版イテレーターの取得
	const const_Iterator crend() const {
		return const_Iterator(m_pDummy, this);
	}
	// @brief 逆方向の末尾の非const版イテレーターの取得
	Iterator rend() {
		return Iterator(m_pDummy, this);
	}

	// @brief 要素の削除
	bool erase(const_Iterator pos) {
		// リストが空の場合は処理しない
		if (isEmpty()) return false;

		// 所属するリストが異なる場合は処理しない
		if (pos.owner() != this) return false;

		//　イテレーターがnullptrだった場合は処理しない
		if (pos == end())return false;

		// 削除するノードを取得
		if (!pos.m_pCurrent) return false;
		// ノードの前後のノードを取得
		Node* prevNode = pos.m_pCurrent->m_pPrevData;
		Node* nextNode = pos.m_pCurrent->m_pNextData;
		// 前のノードが存在する場合、その次のノードを更新
		if (prevNode) {
			prevNode->m_pNextData = nextNode;
		}
		else {
			// 削除するノードが先頭の場合、先頭を更新
			m_pDummy->m_pNextData = nextNode;
		}
		// 次のノードが存在する場合、その前のノードを更新
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// 削除するノードが末尾の場合、末尾を更新
			m_pDummy->m_pPrevData = prevNode;
		}
		// ノードを削除
		delete pos.m_pCurrent;
		m_Size--;
		// 次のノードへのイテレーターを返す
		return true;
	}

	// @brief 要素の挿入
	bool insert(const_Iterator pos, const T& value) {
		// 所属するリストが異なる場合は処理しない
		if (pos.owner() != this) return false;

		
		if (pos.m_pCurrent == m_pDummy)
		{
			pushBack(value);
			return true;
		}
		else if (pos == begin())
		{
			pushFront(value);
			return true;
		}
		else if (pos == end())
		{
			return false;
		}

		// 挿入するノードを作成
		Node* newNode = new(std::nothrow) Node(value);
		if (!newNode) return false;
		// 挿入位置のノードを取得
		if (!pos.m_pCurrent)return false;
		
		// 挿入位置の前のノードを取得
		Node* prevNode = pos.m_pCurrent->m_pPrevData;
		// 新しいノードの前後のノードを設定
		newNode->m_pPrevData = prevNode;
		newNode->m_pNextData = pos.m_pCurrent;
		// 前のノードが存在する場合、その次のノードを新しいノードに設定
		if (prevNode) {
			prevNode->m_pNextData = newNode;
		}
		else {
			// 挿入位置が先頭の場合、先頭を新しいノードに更新
			m_pDummy->m_pNextData = newNode;
		}
		// 挿入位置のノードの前のノードを新しいノードに設定
		pos.m_pCurrent->m_pPrevData = newNode;
		// データ数を増やす
		m_Size++;
		return true;
	}
	
private:
	// @brief ダミーノード
	Node* m_pDummy;
	// @brief データ総数
	size_t m_Size;
};