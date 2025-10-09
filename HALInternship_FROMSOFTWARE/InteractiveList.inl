/*��������������������������������������������������������������
*
* @file InteractiveList.inl
* @brief �o�������X�g�̃C�����C���t�@�C��
*
��������������������������������������������������������������*/
#include "InteractiveList.h"
#include "File.h"

/***************************************************************
*	
* InteractiveNode�\���̂̃����o�֐�
* 
****************************************************************/

// @brief InteractiveNode�̃f�t�H���g�R���X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveNode::InteractiveNode()
	: m_pPrevData(nullptr)
	, m_pNextData(nullptr)
	, m_Data() 
{
}

// @brief InteractiveNode�̃R���X�g���N�^
// @param In_Value �m�[�h�Ɋi�[����f�[�^
template<typename T>
inline InteractiveList<T>::InteractiveNode::InteractiveNode(const T& In_Value)
	:m_Data(In_Value)
	, m_pPrevData(nullptr)
	, m_pNextData(nullptr)
{
}

// @brief InteractiveNode�̃f�X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveNode::~InteractiveNode()
{
	m_pPrevData = nullptr;
	m_pNextData = nullptr;
}

/***************************************************************
* 
* InteractiveConstIterator�N���X�̃����o�֐�
* 
***************************************************************/

// @brief �f�t�H���g�R���X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator()
	: m_pCurrent(nullptr)
	, m_pOwner(nullptr)
{
}

// @brief �R���X�g���N�^
// @param node �m�[�h�|�C���^
// @param owner �������郊�X�g�|�C���^
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator(const Node* node, const List* owner)
{
	m_pCurrent = const_cast<Node*>(node);
	m_pOwner = const_cast<List*>(owner);
}

// @brief �R�s�[�R���X�g���N�^
// @param other �R�s�[���̃C�e���[�^�[
template<typename T>
inline InteractiveList<T>::InteractiveConstIterator::InteractiveConstIterator(const Self& other)
{
	m_pCurrent = other.m_pCurrent;
	m_pOwner = other.m_pOwner;
}

// @brief �O�u�C���N�������g
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator++()
{
	// �A�T�[�g�`�F�b�N
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// ���̃m�[�h�ֈړ�
	if (m_pCurrent) m_pCurrent = m_pCurrent->m_pNextData;
	return *this;
}

// @brief ��u�C���N�������g
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self InteractiveList<T>::InteractiveConstIterator::operator++(int)
{
	Self temp = *this;
	++(*this);
	return temp;
}

// @brief �O�u�f�N�������g
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator--()
{
	// �A�T�[�g�`�F�b�N
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// �O�̃m�[�h�ֈړ�
	if (m_pCurrent) m_pCurrent = m_pCurrent->m_pPrevData;
	return *this;
}

// @brief ��u�f�N�������g
template<typename T>
inline typename InteractiveList<T>::InteractiveConstIterator::Self InteractiveList<T>::InteractiveConstIterator::operator--(int)
{
	Self temp = *this;
	--(*this);
	return temp;
}

// @brief �f�[�^�ւ̎Q��(const��)
template<typename T>
inline const T& InteractiveList<T>::InteractiveConstIterator::operator*() const
{
	// �A�T�[�g�`�F�b�N
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// �f�[�^��Ԃ�
	return m_pCurrent->m_Data;
}

// @brief �|�C���^�A�N�Z�X
template<typename T>
inline const T* InteractiveList<T>::InteractiveConstIterator::operator->() const
{
	// �A�T�[�g�`�F�b�N
	assert(m_pCurrent != nullptr);
	assert(m_pCurrent != &m_pOwner->m_Dummy);
	// �f�[�^��Ԃ�
	return &(m_pCurrent->m_Data);
}

// @brief ������Z�q
template<typename T>
inline const typename InteractiveList<T>::InteractiveConstIterator::Self& InteractiveList<T>::InteractiveConstIterator::operator=(const Self& other)
{
	// �������g�ւ̑���łȂ����Ƃ��m�F
	if (this != &other) {
		m_pCurrent = other.m_pCurrent;
		m_pOwner = other.m_pOwner;
	}
	return *this;
}

// @brief �������Z�q
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator==(Self& other)
{
	return m_pCurrent == other.m_pCurrent;
}

// @brief �������Z�q(const��)
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator==(const Self& other) const
{
	return m_pCurrent == other.m_pCurrent;
}

// @brief �s����r���Z�q
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator!=(Self& other)
{
	return !(*this == other);
}

// @brief �s����r���Z�q(const��)
template<typename T>
inline bool InteractiveList<T>::InteractiveConstIterator::operator!=(const Self& other) const
{
	return !(*this == other);
}

// @brief �������郊�X�g���擾
template<typename T>
inline const typename InteractiveList<T>::InteractiveConstIterator::List* InteractiveList<T>::InteractiveConstIterator::owner() const
{
	return m_pOwner;
}

/***************************************************************
* 
* InteractiveIterator�N���X�̃����o�֐�
* 
***************************************************************/

// @brief �f�t�H���g�R���X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator()
	: Base()
{
}

// @brief �R���X�g���N�^
// @param node �m�[�h�|�C���^
// @param owner �������郊�X�g�|�C���^
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator(Node* node, List* owner)
	: Base(node, owner)
{
}

// @brief �R�s�[�R���X�g���N�^
// @param other �R�s�[���̃C�e���[�^�[
template<typename T>
inline InteractiveList<T>::InteractiveIterator::InteractiveIterator(const Self& other)
	: Base(other)
{
}

// @brief �f�[�^�ւ̎Q��(��const��)
template<typename T>
inline T& InteractiveList<T>::InteractiveIterator::operator*()
{
	// �A�T�[�g�`�F�b�N
	assert(Base::m_pCurrent != nullptr);
	assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
	// �f�[�^��Ԃ�
	return Base::m_pCurrent->m_Data;
}

// @brief �f�[�^�ւ̎Q��(��const��)
template<typename T>
inline T* InteractiveList<T>::InteractiveIterator::operator->()
{
	// �A�T�[�g�`�F�b�N
	assert(Base::m_pCurrent != nullptr);
	assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
	// �f�[�^��Ԃ�
	return &(Base::m_pCurrent->m_Data);
}

/***************************************************************
*
* InteractiveList<T>�N���X�̃����o�֐�
*
***************************************************************/

// @brief �R���X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveList()
	:m_Size(0)
{
	m_Dummy.m_pNextData = &m_Dummy;
	m_Dummy.m_pPrevData = &m_Dummy;
}

// @brief �R�s�[�R���X�g���N�^
template<typename T>
inline InteractiveList<T>::InteractiveList(const InteractiveList& other)
	:m_Size(0)
{
	// �_�~�[�m�[�h���쐬
	m_Dummy = other.m_Dummy;
}

// @brief �f�X�g���N�^
template<typename T>
inline InteractiveList<T>::~InteractiveList()
{
	clear();
}

// @brief ���X�g�̃f�[�^�̑������擾
// @return �f�[�^�̑���
template<typename T>
inline const size_t InteractiveList<T>::getSize() const
{
	return m_Size;
}

// @brief ���X�g���󂩂ǂ������擾
// @return ��Ȃ�true,��łȂ����false
template<typename T>
inline bool InteractiveList<T>::isEmpty() const
{
	return m_Size == 0;
}

// @brief ���X�g���N���A
template<typename T>
inline void InteractiveList<T>::clear()
{
	// �f�[�^���Ȃ��Ȃ�܂Ő擪�̃f�[�^���폜
	while (!isEmpty()) {
		popFront();
	}
	// �擪�Ɩ�����m_Dummy�ɐݒ�
	m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
}

// @brief �擪�Ƀf�[�^��ǉ�
// @param In_Value �ǉ�����f�[�^
template<typename T>
inline void InteractiveList<T>::pushFront(const T& In_Value)
{
	// �V�����m�[�h���쐬
	Node* newNode = new(std::nothrow) Node(In_Value);
	// �������m�ێ��s���͏������Ȃ�
	if (!newNode) return;
	// ���X�g����̏ꍇ
	if (isEmpty()) {
		// �擪�Ɩ�����V�����m�[�h�ɐݒ�
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = newNode;
	}
	// ���X�g�Ƀf�[�^������ꍇ
	else {
		// �ǉ��O�̐擪�f�[�^��V�����m�[�h�̎��̃f�[�^�ɐݒ�
		newNode->m_pNextData = m_Dummy.m_pNextData;
		// �ǉ��O�̐擪�f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
		newNode->m_pPrevData = &m_Dummy;
		// �ǉ��O�̐擪�f�[�^�̑O�̃f�[�^��V�����m�[�h�ɐݒ�
		m_Dummy.m_pNextData->m_pPrevData = newNode;
		// �擪�f�[�^��V�����m�[�h�ɐݒ�
		m_Dummy.m_pNextData = newNode;
	}
	// �f�[�^���𑝂₷
	m_Size++;
}

// @brief �����Ƀf�[�^��ǉ�
// @param In_Value �ǉ�����f�[�^
template<typename T>
inline void InteractiveList<T>::pushBack(const T& In_Value)
{
	// �V�����m�[�h���쐬
	Node* newNode = new(std::nothrow) Node(In_Value);
	// �������m�ۂɎ��s�����ꍇ�͏������Ȃ�
	if (!newNode) return;
	// ���X�g����̏ꍇ
	if (isEmpty()) {
		// �擪�Ɩ�����V�����m�[�h�ɐݒ�
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = newNode;
	}
	// ���X�g�Ƀf�[�^������ꍇ
	else {
		// �ǉ��O�̖����f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
		newNode->m_pPrevData = m_Dummy.m_pPrevData;
		// �ǉ��O�̖����f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
		newNode->m_pNextData = &m_Dummy;
		// �ǉ��O�̖����f�[�^�̎��̃f�[�^��V�����m�[�h�ɐݒ�
		m_Dummy.m_pPrevData->m_pNextData = newNode;
		// �����f�[�^��V�����m�[�h�ɐݒ�
		m_Dummy.m_pPrevData = newNode;
	}
	// �f�[�^���𑝂₷
	m_Size++;
}

// @brief �擪�̃f�[�^���폜
template<typename T>
inline void InteractiveList<T>::popFront()
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return;
	// �擪�f�[�^���ꎞ�ۑ�
	Node* tempNode = m_Dummy.m_pNextData;
	// �f�[�^�̑�����1�̏ꍇ
	if (m_Size == 1) {
		//�擪�Ɩ�����nullptr�ɐݒ�
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
	}
	// �f�[�^�̑����������̏ꍇ
	else {
		// �擪�f�[�^�����̃f�[�^�ɐݒ�
		m_Dummy.m_pNextData = m_Dummy.m_pNextData->m_pNextData;
		// �V�����擪�f�[�^�̑O�̃f�[�^��nullptr�ɐݒ�
		m_Dummy.m_pNextData->m_pPrevData = &m_Dummy;
	}
	// �ꎞ�ۑ����Ă����擪�f�[�^���폜
	delete tempNode;
	// �f�[�^�������炷
	m_Size--;
}

// @brief �����̃f�[�^���폜
template<typename T>
inline void InteractiveList<T>::popBack()
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return;
	// �����f�[�^���ꎞ�ۑ�
	Node* tempNode = m_Dummy.m_pPrevData;
	// �f�[�^�̑�����1�̏ꍇ
	if (m_Size == 1) {
		//�擪�Ɩ�����nullptr�ɐݒ�
		m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
	}
	// �f�[�^�̑����������̏ꍇ
	else {
		// �����f�[�^��O�̃f�[�^�ɐݒ�
		m_Dummy.m_pPrevData = m_Dummy.m_pPrevData->m_pPrevData;
		// �V���������f�[�^�̎��̃f�[�^��nullptr�ɐݒ�
		m_Dummy.m_pPrevData->m_pNextData = &m_Dummy;
	}
	// �ꎞ�ۑ����Ă��������f�[�^���폜
	delete tempNode;
	// �f�[�^�������炷
	m_Size--;
}

// @brief �擪��const�ŃC�e���[�^�[�̎擾
// @return �擪�̃R���X�g�C���[�^�[
template<typename T>
inline  const typename InteractiveList<T>::const_Iterator InteractiveList<T>::cbegin() const
{
	return const_Iterator(m_Dummy.m_pNextData, this);
}

// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
// @return �擪�̃C�e���[�^�[
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::begin()
{
	return Iterator(m_Dummy.m_pNextData, this);
}

// @brief ������const�ŃC�e���[�^�[�̎擾
// @return �����̃R���X�g�C�e���[�^�[
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::cend() const
{
	if (!isEmpty())
	{
		return const_Iterator(m_Dummy.m_pPrevData, this);
	}
	return const_Iterator(&m_Dummy, this);
}

// @brief �����̔�const�ŃC�e���[�^�[�̎擾
// @return �����̃C�e���[�^�[
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::end()
{
	if (!isEmpty())
	{
		return Iterator(m_Dummy.m_pPrevData, this);
	}
	return Iterator(&m_Dummy, this);
}

// @brief �t�����̐擪��const�ŃC�e���[�^�[�̎擾
// @return �t�����̐擪�̃R���X�g�C�e���[�^�[
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::crbegin() const
{
	return const_Iterator(m_Dummy.m_pPrevData, this);
}

// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
// @return �t�����̐擪�̃C�e���[�^�[
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::rbegin()
{
	return Iterator(m_Dummy.m_pPrevData, this);
}

// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
// @return �t�����̖����̃R���X�g�C���[�^�[
template<typename T>
inline const typename InteractiveList<T>::const_Iterator InteractiveList<T>::crend() const
{
	if (!isEmpty())
	{
		return const_Iterator(m_Dummy.m_pNextData, this);
	}
	return const_Iterator(&m_Dummy, this);
}

// @brief �t�����̖����̔�const�ŃC�e���[�^�[�̎擾
// @return �t�����̖����̃C�e���[�^�[
template<typename T>
inline typename InteractiveList<T>::Iterator InteractiveList<T>::rend()
{
	if (!isEmpty())
	{
		return Iterator(m_Dummy.m_pNextData, this);
	}
	return Iterator(&m_Dummy, this);
}

// @brief �v�f�̍폜
// @param pos �폜����v�f�̃C�e���[�^�[
// @return �폜�ɐ���������true,���s������false
template<typename T>
inline bool InteractiveList<T>::erase(const_Iterator pos)
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return false;

	// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
	if (pos.owner() != this) return false;

	//�@�C�e���[�^�[��nullptr�������ꍇ�͏������Ȃ�
	if (pos == const_Iterator(&m_Dummy, this))return false;

	// �폜����m�[�h���擾
	if (!pos.m_pCurrent) return false;
	// �m�[�h�̑O��̃m�[�h���擾
	Node* prevNode = pos.m_pCurrent->m_pPrevData;
	Node* nextNode = pos.m_pCurrent->m_pNextData;
	// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h���X�V
	if (prevNode) {
		prevNode->m_pNextData = nextNode;
	}
	else {
		// �폜����m�[�h���擪�̏ꍇ�A�擪���X�V
		m_Dummy.m_pNextData = nextNode;
	}
	// ���̃m�[�h�����݂���ꍇ�A���̑O�̃m�[�h���X�V
	if (nextNode) {
		nextNode->m_pPrevData = prevNode;
	}
	else {
		// �폜����m�[�h�������̏ꍇ�A�������X�V
		m_Dummy.m_pPrevData = prevNode;
	}
	// �m�[�h���폜
	delete pos.m_pCurrent;
	m_Size--;
	// ���̃m�[�h�ւ̃C�e���[�^�[��Ԃ�
	return true;
}

// @brief �v�f�̑}��
// @param pos �}������ʒu�̃C�e���[�^�[
// @param value �}������f�[�^
// @return �}���ɐ���������true,���s������false
template<typename T>
inline bool InteractiveList<T>::insert(const_Iterator pos, const T& value)
{
	// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
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

	// �}������m�[�h���쐬
	Node* newNode = new(std::nothrow) Node(value);
	if (!newNode) return false;
	// �}���ʒu�̃m�[�h���擾
	if (!pos.m_pCurrent)return false;

	// �}���ʒu�̑O�̃m�[�h���擾
	Node* prevNode = pos.m_pCurrent->m_pPrevData;
	// �V�����m�[�h�̑O��̃m�[�h��ݒ�
	newNode->m_pPrevData = prevNode;
	newNode->m_pNextData = pos.m_pCurrent;
	// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h��V�����m�[�h�ɐݒ�
	if (prevNode) {
		prevNode->m_pNextData = newNode;
	}
	else {
		// �}���ʒu���擪�̏ꍇ�A�擪��V�����m�[�h�ɍX�V
		m_Dummy.m_pNextData = newNode;
	}
	// �}���ʒu�̃m�[�h�̑O�̃m�[�h��V�����m�[�h�ɐݒ�
	pos.m_pCurrent->m_pPrevData = newNode;
	// �f�[�^���𑝂₷
	m_Size++;
	return true;
}

// @brief �m�[�h�̓���ւ�
// @param NodeA �m�[�hA�̃C�e���[�^�[
// @param NodeB �m�[�hB�̃C�e���[�^�[
template<typename T>
inline void InteractiveList<T>::swap(const_Iterator NodeA, const_Iterator NodeB)
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return;

	// �A�T�[�g�`�F�b�N
	// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
	if (NodeA.owner() != this) return;
	if (NodeB.owner() != this) return;
	// �C�e���[�^�[���_�~�[�m�[�h���w���Ă���ꍇ�͏������Ȃ�
	if (NodeA == const_Iterator(&m_Dummy, this)) return;
	if (NodeB == const_Iterator(&m_Dummy, this)) return;
	// �����m�[�h���w���Ă���ꍇ�͏������Ȃ�
	if (NodeA == NodeB) return;

	// �m�[�hA�ƃm�[�hB�̃f�[�^������
	T tempData = NodeA.m_pCurrent->m_Data;
	NodeA.m_pCurrent->m_Data = NodeB.m_pCurrent->m_Data;
	NodeB.m_pCurrent->m_Data = tempData;
}

/***************************************************************
*
* �\�[�g�v���O�����̎���
*
* [�Q�l�ɂ��Ă���T�C�g]
* https://www.geeksforgeeks.org/dsa/cpp-program-for-quicksort-on-doubly-linked-list/
* https://stackoverflow.com/questions/1382273/sorting-a-doubly-linked-list-c
* https://qiita.com/seriru13/items/0605c17a162828b31e11
*
***************************************************************/

// @brief �\�[�g
// @param type �\�[�g�A���S���Y��
// @param order �\�[�g��
// @param key �\�[�g�L�[���擾����֐��I�u�W�F�N�g
template<typename T>
template<typename KeySelector>
inline void InteractiveList<T>::sort(SortAlgorithm type, SortOrder order, KeySelector key)
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return;

	// �\�[�g�A���S���Y���ɂ���ď����𕪊�
	switch (type)
	{
	case SortAlgorithm::QuickSort:
		// �N�C�b�N�\�[�g�����s
		_quickSort(cbegin(), cend(), key);
		break;
	default:
		break;
	}

	// �~���̏ꍇ�̓��X�g�𔽓]
	if (order == SortOrder::Descending)
	{
		// ���X�g�𔽓]
		_reverse();
	}
}

// @brief 2�̃f�[�^���r���Aa��b��菬�������ǂ����𔻒�
// @param a ��r����f�[�^1
// @param b ��r����f�[�^2
// @param key ��r�L�[���擾����֐��I�u�W�F�N�g
// @return a��b��菬�����ꍇ��true,�����łȂ����false
template<typename T>
template<typename KeySelector>
inline constexpr auto InteractiveList<T>::_isLess(const T& a, const T& b, KeySelector key)
-> decltype(key(a) < key(b), bool())
{
	return key(a) < key(b);
}

// @brief �p�[�e�B�V����
// @param start �p�[�e�B�V�����̊J�n�C�e���[�^�[
// @param end �p�[�e�B�V�����̏I���C�e���[�^�[
// @param key �\�[�g�L�[���擾����֐��I�u�W�F�N�g
// @return �s�{�b�g�̈ʒu�̃C�e���[�^�[
template<typename T>
template<typename KeySelector>
inline typename InteractiveList<T>::const_Iterator InteractiveList<T>::_partition(const_Iterator start, const_Iterator end, KeySelector key)
{
	// �s�{�b�g���擾
	T pivot = (*end);
	// �J�n�C�e���[�^�[�̃m�[�h���擾
	Node* startNode = start.m_pCurrent;
	// �I���C�e���[�^�[�̃m�[�h���擾
	Node* endNode = end.m_pCurrent;
	// i���J�n�C�e���[�^�[�̑O�̃m�[�h�ɐݒ�
	Node* i = startNode->m_pPrevData;

	// j���J�n�C�e���[�^�[����I���C�e���[�^�[�܂Ń��[�v
	for (Node* j = startNode; j != endNode; j = j->m_pNextData)
	{
		// j�̃f�[�^���s�{�b�g��菬�����ꍇ
		if (_isLess(j->m_Data, pivot, key))
		{
			// i��1�i�߂�
			i = (i == nullptr) ? startNode : i->m_pNextData;
			swap(const_Iterator(i, this), const_Iterator(j, this));
		}
	}

	// i��1�i�߂�
	i = (i == nullptr) ? startNode : i->m_pNextData;
	swap(const_Iterator(i, this), end);

	// �s�{�b�g�̈ʒu�̃C�e���[�^�[��Ԃ�
	return const_Iterator(i, this);
}

// @brief �N�C�b�N�\�[�g
// @param start �\�[�g�̊J�n�C�e���[�^�[
// @param end �\�[�g�̏I���C�e���[�^�[
// @param key �\�[�g�L�[���擾����֐��I�u�W�F�N�g
template<typename T>
template<typename KeySelector>
inline void InteractiveList<T>::_quickSort(const_Iterator start, const_Iterator end, KeySelector key)
{
	// �J�n�ʒu�ƏI���ʒu�̃C�e���[�^�[���������郊�X�g���قȂ�ꍇ�͏������Ȃ�
	if (start.owner() != this || end.owner() != this) return;
	// �C�e���[�^�[���_�~�[�m�[�h���w���Ă���ꍇ�͏������Ȃ�
	if (start == const_Iterator(&m_Dummy, this) || end == const_Iterator(&m_Dummy, this)) return;
	// �m�[�h��nullptr�̏ꍇ�A�܂��͊J�n�ʒu�ƏI���ʒu�������ꍇ�͏������Ȃ�
	if (!start.m_pCurrent || !end.m_pCurrent || start == end) return;

	// �J�n�m�[�h�ƏI���m�[�h���擾
	Node* startNode = start.m_pCurrent;
	Node* endNode = end.m_pCurrent;

	// �J�n�m�[�h���I���m�[�h�̎��̃m�[�h�łȂ����菈���𑱍s
	if (startNode != endNode->m_pNextData)
	{
		// �p�[�e�B�V���������s���A�s�{�b�g�̈ʒu���擾
		Node* pivotNode = _partition(start, end, key).m_pCurrent;
		// �s�{�b�g�̑O��ōċA�I�ɃN�C�b�N�\�[�g�����s
		if (pivotNode && pivotNode->m_pPrevData)
			_quickSort(start, const_Iterator(pivotNode->m_pPrevData, this), key);
		if (pivotNode && pivotNode->m_pNextData)
			_quickSort(const_Iterator(pivotNode->m_pNextData, this), end, key);
	}
}

// @brief ���X�g�𔽓]
template<typename T>
inline void InteractiveList<T>::_reverse()
{
	// ���X�g����̏ꍇ�͏������Ȃ�
	if (isEmpty()) return;

	// �擪�C�e���[�^�[�Ɩ����C�e���[�^�[���擾
	Iterator left = begin();
	Iterator right = end();
	// left��right�̑O�̃m�[�h�łȂ����菈���𑱍s
	while (left.m_pCurrent != right.m_pCurrent && left.m_pCurrent != right.m_pCurrent->m_pNextData)
	{
		// left��right�̃f�[�^������
		swap(left, right);
		// left��1�i�߂�
		++left;
		// right��1�߂�
		--right;
	}

}