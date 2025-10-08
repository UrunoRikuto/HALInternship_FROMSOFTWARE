/*��������������������������������������������������������������
*
* @file InteractiveList.inl
* @brief �o�������X�g�̃C�����C���t�@�C��
*
��������������������������������������������������������������*/
#include "InteractiveList.h"

// @brief �R���X�g���N�^
template<typename T>
InteractiveList<T>::InteractiveList() 
	:m_Size(0) 
{
	m_Dummy.m_pNextData = m_Dummy.m_pPrevData = &m_Dummy;
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
inline const InteractiveList<T>::InteractiveConstIterator<T> InteractiveList<T>::cbegin() const
{
	return const_Iterator(m_Dummy.m_pNextData, this);
}

// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
// @return �擪�̃C�e���[�^�[
template<typename T>
inline InteractiveList<T>::InteractiveIterator<T> InteractiveList<T>::begin()
{
	return Iterator(m_Dummy.m_pNextData, this);
}

// @brief ������const�ŃC�e���[�^�[�̎擾
// @return �����̃R���X�g�C�e���[�^�[
template<typename T>
inline const InteractiveList<T>::InteractiveConstIterator<T> InteractiveList<T>::cend() const
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
inline InteractiveList<T>::InteractiveIterator<T> InteractiveList<T>::end()
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
inline const InteractiveList<T>::InteractiveConstIterator<T> InteractiveList<T>::crbegin() const
{
	return const_Iterator(m_Dummy.m_pPrevData, this);
}

// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
// @return �t�����̐擪�̃C�e���[�^�[
template<typename T>
inline InteractiveList<T>::InteractiveIterator<T> InteractiveList<T>::rbegin()
{
	return Iterator(m_Dummy.m_pPrevData, this);
}

// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
// @return �t�����̖����̃R���X�g�C���[�^�[
template<typename T>
inline const InteractiveList<T>::InteractiveConstIterator<T> InteractiveList<T>::crend() const
{
	if (!isEmpty())
	{
		return const_Iterator(m_Dummy.m_pNextData, this);
	}
	return const_Iterator(&m_Dummy, this);
}

template<typename T>
inline InteractiveList<T>::InteractiveIterator<T> InteractiveList<T>::rend()
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
