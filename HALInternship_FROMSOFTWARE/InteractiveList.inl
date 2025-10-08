/*＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
*
* @file InteractiveList.inl
* @brief 双方向リストのインラインファイル
*
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝*/
#include "InteractiveList.h"

/***************************************************************
*	
* InteractiveNode構造体のメンバ関数
* 
****************************************************************/

// @brief InteractiveNodeのデフォルトコンストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveNode::InteractiveNode()
	: m_pPrevData(nullptr)
	, m_pNextData(nullptr)
	, m_Data() 
{
}

// @brief InteractiveNodeのコンストラクタ
// @param In_Value ノードに格納するデータ
template<typename T>
inline InteractiveList<T>::InteractiveNode::InteractiveNode(const T& In_Value)
	:m_Data(In_Value)
	, m_pPrevData(nullptr)
	, m_pNextData(nullptr)
{
}

// @brief InteractiveNodeのデストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveNode::~InteractiveNode()
{
	m_pPrevData = nullptr;
	m_pNextData = nullptr;
}

/***************************************************************
* 
* InteractiveConstIteratorクラスのメンバ関数
* 
***************************************************************/

// @brief デフォルトコンストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator()
	: m_pCurrent(nullptr)
	, m_pOwner(nullptr)
{
}

// @brief コンストラクタ
// @param node ノードポインタ
// @param owner 所属するリストポインタ
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator(const Node* node, const List* owner)
{
	m_pCurrent = const_cast<Node*>(node);
	m_pOwner = const_cast<List*>(owner);
}

// @brief コピーコンストラクタ
// @param other コピー元のイテレーター
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator(const Self& other)
{
	m_pCurrent = other.m_pCurrent;
	m_pOwner = other.m_pOwner;
}

// @brief 前置インクリメント
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator++()
{
	// アサートチェック
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// 次のノードへ移動
	if (m_pCurrent) m_pCurrent = m_pCurrent->m_pNextData;
	return *this;
}

// @brief 後置インクリメント
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self InteractiveList<T>::InteractiveConstIterator::operator++(int)
{
	Self temp = *this;
	++(*this);
	return temp;
}

// @brief 前置デクリメント
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator--()
{
	// アサートチェック
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// 前のノードへ移動
	if (m_pCurrent) m_pCurrent = m_pCurrent->m_pPrevData;
	return *this;
}

// @brief 後置デクリメント
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self InteractiveList<T>::InteractiveConstIterator::operator--(int)
{
	Self temp = *this;
	--(*this);
	return temp;
}

// @brief データへの参照(const版)
template<typename T>
inline const T& InteractiveList<T>::InteractiveConstIterator::operator*() const
{
	// アサートチェック
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// データを返す
	return m_pCurrent->m_Data;
}

// @brief ポインタアクセス
template<typename T>
inline const T* InteractiveList<T>::InteractiveConstIterator::operator->() const
{
	// アサートチェック
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// データを返す
	return &(m_pCurrent->m_Data);
}

// @brief 代入演算子
template<typename T>
inline const typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator=(const Self& other)
{
	// 自分自身への代入でないことを確認
	if (this != &other) {
		m_pCurrent = other.m_pCurrent;
		m_pOwner = other.m_pOwner;
	}
	return *this;
}

// @brief 等価演算子
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator==(Self& other)
{
	return m_pCurrent == other.m_pCurrent;
}

// @brief 等価演算子(const版)
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator==(const Self& other) const
{
	return m_pCurrent == other.m_pCurrent;
}

// @brief 不等比較演算子
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator!=(Self& other)
{
	return !(*this == other);
}

// @brief 不等比較演算子(const版)
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator!=(const Self& other) const
{
	return !(*this == other);
}

// @brief 所属するリストを取得
template<typename T>
inline const typename InteractiveList<T>::InteractiveConstIterator::List* InteractiveList<T>::InteractiveConstIterator::owner() const
{
	return m_pOwner;
}

/***************************************************************
* 
* InteractiveIteratorクラスのメンバ関数
* 
***************************************************************/

// @brief デフォルトコンストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator()
	: Base()
{
}

// @brief コンストラクタ
// @param node ノードポインタ
// @param owner 所属するリストポインタ
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator(Node* node, List* owner)
	: Base(node, owner)
{
}

// @brief コピーコンストラクタ
// @param other コピー元のイテレーター
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator(const Self& other)
	: Base(other)
{
}

// @brief データへの参照(非const版)
template<typename T>
inline T& InteractiveList<T>::InteractiveIterator::operator*()
{
	// アサートチェック
	assert(Base::m_pCurrent != nullptr);
	assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
	// データを返す
	return Base::m_pCurrent->m_Data;
}

// @brief データへの参照(非const版)
template<typename T>
inline T* InteractiveList<T>::InteractiveIterator::operator->()
{
	// アサートチェック
	assert(Base::m_pCurrent != nullptr);
	assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
	// データを返す
	return &(Base::m_pCurrent->m_Data);
}

/***************************************************************
*
* InteractiveList<T>クラスのメンバ関数
*
***************************************************************/

// @brief コンストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveList()
	:m_Size(0)
{
	m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
}

// @brief コピーコンストラクタ
template<typename T>
inline InteractiveList<T>::InteractiveList(const InteractiveList& other)
	:m_Size(0)
{
	// ダミーノードを作成
	m_Dummy = other.m_Dummy;
}

// @brief デストラクタ
template<typename T>
inline InteractiveList<T>::~InteractiveList()
{
	clear();
}

// @brief リストのデータの総数を取得
// @return データの総数
template<typename T>
inline const size_t InteractiveList<T>::getSize() const
{
	return m_Size;
}

// @brief リストが空かどうかを取得
// @return 空ならtrue,空でなければfalse
template<typename T>
inline bool InteractiveList<T>::isEmpty() const
{
	return m_Size == 0;
}

// @brief リストをクリア
template<typename T>
inline void InteractiveList<T>::clear()
{
	// データがなくなるまで先頭のデータを削除
	while (!isEmpty()) {
		popFront();
	}
	// 先頭と末尾をm_Dummyに設定
	m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
}

// @brief 先頭にデータを追加
// @param In_Value 追加するデータ
template<typename T>
inline void InteractiveList<T>::pushFront(const T& In_Value)
{
	// 新しいノードを作成
	Node* newNode = new(std::nothrow) Node(In_Value);
	// メモリ確保失敗時は処理しない
	if (!newNode) return;
	// リストが空の場合
	if (isEmpty()) {
		// 先頭と末尾を新しいノードに設定
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = newNode;
	}
	// リストにデータがある場合
	else {
		// 追加前の先頭データを新しいノードの次のデータに設定
		newNode->m_pNextData = m_Dummy.m_pNextData;
		// 追加前の先頭データを新しいノードの前のデータに設定
		newNode->m_pPrevData = &m_Dummy;
		// 追加前の先頭データの前のデータを新しいノードに設定
		m_Dummy.m_pNextData->m_pPrevData = newNode;
		// 先頭データを新しいノードに設定
		m_Dummy.m_pNextData = newNode;
	}
	// データ数を増やす
	m_Size++;
}

// @brief 末尾にデータを追加
// @param In_Value 追加するデータ
template<typename T>
inline void InteractiveList<T>::pushBack(const T& In_Value)
{
	// 新しいノードを作成
	Node* newNode = new(std::nothrow) Node(In_Value);
	// メモリ確保に失敗した場合は処理しない
	if (!newNode) return;
	// リストが空の場合
	if (isEmpty()) {
		// 先頭と末尾を新しいノードに設定
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = newNode;
	}
	// リストにデータがある場合
	else {
		// 追加前の末尾データを新しいノードの前のデータに設定
		newNode->m_pPrevData = m_Dummy.m_pPrevData;
		// 追加前の末尾データを新しいノードの前のデータに設定
		newNode->m_pNextData = &m_Dummy;
		// 追加前の末尾データの次のデータを新しいノードに設定
		m_Dummy.m_pPrevData->m_pNextData = newNode;
		// 末尾データを新しいノードに設定
		m_Dummy.m_pPrevData = newNode;
	}
	// データ数を増やす
	m_Size++;
}

// @brief 先頭のデータを削除
template<typename T>
inline void InteractiveList<T>::popFront()
{
	// リストが空の場合は処理しない
	if (isEmpty()) return;
	// 先頭データを一時保存
	Node* tempNode = m_Dummy.m_pNextData;
	// データの総数が1つの場合
	if (m_Size == 1) {
		//先頭と末尾をnullptrに設定
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
	}
	// データの総数が複数の場合
	else {
		// 先頭データを次のデータに設定
		m_Dummy.m_pNextData = m_Dummy.m_pNextData->m_pNextData;
		// 新しい先頭データの前のデータをnullptrに設定
		m_Dummy.m_pNextData->m_pPrevData = &m_Dummy;
	}
	// 一時保存していた先頭データを削除
	delete tempNode;
	// データ数を減らす
	m_Size--;
}

// @brief 末尾のデータを削除
template<typename T>
inline void InteractiveList<T>::popBack()
{
	// リストが空の場合は処理しない
	if (isEmpty()) return;
	// 末尾データを一時保存
	Node* tempNode = m_Dummy.m_pPrevData;
	// データの総数が1つの場合
	if (m_Size == 1) {
		//先頭と末尾をnullptrに設定
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
	}
	// データの総数が複数の場合
	else {
		// 末尾データを前のデータに設定
		m_Dummy.m_pPrevData = m_Dummy.m_pPrevData->m_pPrevData;
		// 新しい末尾データの次のデータをnullptrに設定
		m_Dummy.m_pPrevData->m_pNextData = &m_Dummy;
	}
	// 一時保存していた末尾データを削除
	delete tempNode;
	// データ数を減らす
	m_Size--;
}

// @brief 先頭のconst版イテレーターの取得
// @return 先頭のコンストイレーター
template<typename T>
inline  const typename InteractiveList<T>::const_Iterator InteractiveList<T>::cbegin() const
{
	return const_Iterator(m_Dummy.m_pNextData, this);
}

// @brief 先頭の非const版イテレーターの取得
// @return 先頭のイテレーター
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::begin()
{
	return Iterator(m_Dummy.m_pNextData, this);
}

// @brief 末尾のconst版イテレーターの取得
// @return 末尾のコンストイテレーター
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::cend() const
{
	if (!isEmpty())
	{
		return const_Iterator(m_Dummy.m_pPrevData, this);
	}
	return const_Iterator(&m_Dummy, this);
}

// @brief 末尾の非const版イテレーターの取得
// @return 末尾のイテレーター
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::end()
{
	if (!isEmpty())
	{
		return Iterator(m_Dummy.m_pPrevData, this);
	}
	return Iterator(&m_Dummy, this);
}

// @brief 逆方向の先頭のconst版イテレーターの取得
// @return 逆方向の先頭のコンストイテレーター
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::crbegin() const
{
	return const_Iterator(m_Dummy.m_pPrevData, this);
}

// @brief 逆方向の先頭の非const版イテレーターの取得
// @return 逆方向の先頭のイテレーター
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::rbegin()
{
	return Iterator(m_Dummy.m_pPrevData, this);
}

// @brief 逆方向の末尾のconst版イテレーターの取得
// @return 逆方向の末尾のコンストイレーター
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::crend() const
{
	if (!isEmpty())
	{
		return const_Iterator(m_Dummy.m_pNextData, this);
	}
	return const_Iterator(&m_Dummy, this);
}

// @brief 逆方向の末尾の非const版イテレーターの取得
// @return 逆方向の末尾のイテレーター
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::rend()
{
	if (!isEmpty())
	{
		return Iterator(m_Dummy.m_pNextData, this);
	}
	return Iterator(&m_Dummy, this);
}

// @brief 要素の削除
// @param pos 削除する要素のイテレーター
// @return 削除に成功したらtrue,失敗したらfalse
template<typename T>
inline bool InteractiveList<T>::erase(const_Iterator pos)
{
	// リストが空の場合は処理しない
	if (isEmpty()) return false;

	// 所属するリストが異なる場合は処理しない
	if (pos.owner() != this) return false;

	//　イテレーターがnullptrだった場合は処理しない
	if (pos == const_Iterator(&m_Dummy, this))return false;

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
		m_Dummy.m_pNextData = nextNode;
	}
	// 次のノードが存在する場合、その前のノードを更新
	if (nextNode) {
		nextNode->m_pPrevData = prevNode;
	}
	else {
		// 削除するノードが末尾の場合、末尾を更新
		m_Dummy.m_pPrevData = prevNode;
	}
	// ノードを削除
	delete pos.m_pCurrent;
	m_Size--;
	// 次のノードへのイテレーターを返す
	return true;
}

// @brief 要素の挿入
// @param pos 挿入する位置のイテレーター
// @param value 挿入するデータ
// @return 挿入に成功したらtrue,失敗したらfalse
template<typename T>
inline bool InteractiveList<T>::insert(const_Iterator pos, const T& value)
{
	// 所属するリストが異なる場合は処理しない
	if (pos.owner() != this) return false;


	if (pos.m_pCurrent == &m_Dummy)
	{
		pushBack(value);
		return true;
	}
	else if (pos == begin())
	{
		pushFront(value);
		return true;
	}
	else if (pos == const_Iterator(&m_Dummy, this))
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
		m_Dummy.m_pNextData = newNode;
	}
	// 挿入位置のノードの前のノードを新しいノードに設定
	pos.m_pCurrent->m_pPrevData = newNode;
	// データ数を増やす
	m_Size++;
	return true;
}