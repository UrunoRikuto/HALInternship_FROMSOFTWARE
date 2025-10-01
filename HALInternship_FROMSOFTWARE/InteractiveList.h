/*��������������������������������������������������������������
* 
* @file InteractiveList.h
* @brief �o�������X�g�̃w�b�_�[�t�@�C��
* 
��������������������������������������������������������������*/

#pragma once

// @brief �o�������X�g�̃f�[�^�N���X
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
struct InteractiveNode
{
	// @brief �R���X�g���N�^
	InteractiveNode(const T& In_Value)
		:m_Data(In_Value)
		, m_pPrevData(nullptr)
		, m_pNextData(nullptr)
	{
	}

	// @brief �f�[�^
	T m_Data;
	// @brief �O�̃f�[�^
	InteractiveNode* m_pPrevData;
	// @brief ���̃f�[�^
	InteractiveNode* m_pNextData;
};

// @brief �o�������X�g�p�C�e���[�^�[
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
class InteractiveIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveIterator<T>;

	// @brief �R���X�g���N�^
	InteractiveIterator(Node* node) : m_pCurrent(node) {}

	// @brief �O�u�C���N�������g
	Self& operator++() {
		if (m_pCurrent) m_pCurrent = m_pCurrent->m_pNextData;
		return *this;
	}

	// @brief ��u�C���N�������g
	Self operator++(int) {
		Self temp = *this;
		++(*this);
		return temp;
	}

	// @brief �O�u�f�N�������g
	Self& operator--() {
		if (m_pCurrent) m_pCurrent = m_pCurrent->m_pPrevData;
		return *this;
	}

	// @brief ��u�f�N�������g
	Self operator--(int) {
		Self temp = *this;
		--(*this);
		return temp;
	}

	// @brief �f�[�^�ւ̎Q��(const��)
	const T& operator*() {
		return m_pCurrent->m_Data;
	}

	// @brief ������Z�q
	Self& operator=(const Self& other) {
		if (this != &other) {
			m_pCurrent = other.m_pCurrent;
		}
		return *this;
	}

	// @brief �|�C���^�A�N�Z�X
	const T* operator->() {
		return &(m_pCurrent->m_Data);
	}

	// @brief ��r���Z�q
	const bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}

	// @brief �s����r���Z�q
	const bool operator!=(const Self& other) {
		return !(*this == other);
	}

private:
	Node* m_pCurrent;

};

// @brief �o�������X�g�N���X
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
class InteractiveList
{
public:
	// @brief �R���X�g���N�^
	InteractiveList()
		:m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_Size(0)
	{
	}

	// @brief �f�X�g���N�^
	~InteractiveList() { clear(); }

	// @brief ���X�g�̃f�[�^�̑������擾
	// @return �f�[�^�̑���
	const size_t getSize() { return m_Size; }

	// @brief ���X�g���󂩂ǂ������擾
	const bool isEmpty() { return m_Size == 0; }

	// @brief ���X�g���N���A
	void clear() {
		// �f�[�^���Ȃ��Ȃ�܂Ő擪�̃f�[�^���폜
		while (!isEmpty()) {
			popFront();
		}
	}

	// @brief �擪�f�[�^���擾
	// @return �擪�f�[�^
	const InteractiveNode<T>* getFront() { return m_pHead; }

	// @brief �����f�[�^���擾
	// @return �����f�[�^
	const InteractiveNode<T>* getBack() { return m_pTail; }

	// @brief �擪�Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushFront(const T& In_Value) {
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// ���X�g����̏ꍇ
		if (isEmpty()) {
			// �擪�Ɩ�����V�����m�[�h�ɐݒ�
			m_pHead = m_pTail = newNode;
		}
		// ���X�g�Ƀf�[�^������ꍇ
		else {
			// �ǉ��O�̐擪�f�[�^��V�����m�[�h�̎��̃f�[�^�ɐݒ�
			newNode->m_pNextData = m_pHead;
			// �ǉ��O�̐擪�f�[�^�̑O�̃f�[�^��V�����m�[�h�ɐݒ�
			m_pHead->m_pPrevData = newNode;
			// �擪�f�[�^��V�����m�[�h�ɐݒ�
			m_pHead = newNode;
		}
		// �f�[�^���𑝂₷
		m_Size++;
	}

	// @brief �����Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushBack(const T& In_Value) {
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// ���X�g����̏ꍇ
		if (isEmpty()) {
			// �擪�Ɩ�����V�����m�[�h�ɐݒ�
			m_pHead = m_pTail = newNode;
		}
		// ���X�g�Ƀf�[�^������ꍇ
		else {
			// �ǉ��O�̖����f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
			newNode->m_pPrevData = m_pTail;
			// �ǉ��O�̖����f�[�^�̎��̃f�[�^��V�����m�[�h�ɐݒ�
			m_pTail->m_pNextData = newNode;
			// �����f�[�^��V�����m�[�h�ɐݒ�
			m_pTail = newNode;
		}
		// �f�[�^���𑝂₷
		m_Size++;
	}

	// @brief �擪�̃f�[�^���폜
	void popFront() {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return;
		// �擪�f�[�^���ꎞ�ۑ�
		InteractiveNode<T>* tempNode = m_pHead;
		// �f�[�^�̑�����1�̏ꍇ
		if (m_Size == 1) {
			//�擪�Ɩ�����nullptr�ɐݒ�
			m_pHead = m_pTail = nullptr;
		}
		// �f�[�^�̑����������̏ꍇ
		else {
			// �擪�f�[�^�����̃f�[�^�ɐݒ�
			m_pHead = m_pHead->m_pNextData;
			// �V�����擪�f�[�^�̑O�̃f�[�^��nullptr�ɐݒ�
			m_pHead->m_pPrevData = nullptr;
		}
		// �ꎞ�ۑ����Ă����擪�f�[�^���폜
		delete tempNode;
		// �f�[�^�������炷
		m_Size--;
	}

	// @brief �����̃f�[�^���폜
	void popBack() {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return;
		// �����f�[�^���ꎞ�ۑ�
		InteractiveNode<T>* tempNode = m_pTail;
		// �f�[�^�̑�����1�̏ꍇ
		if (m_Size == 1) {
			//�擪�Ɩ�����nullptr�ɐݒ�
			m_pHead = m_pTail = nullptr;
		}
		// �f�[�^�̑����������̏ꍇ
		else {
			// �����f�[�^��O�̃f�[�^�ɐݒ�
			m_pTail = m_pTail->m_pPrevData;
			// �V���������f�[�^�̎��̃f�[�^��nullptr�ɐݒ�
			m_pTail->m_pNextData = nullptr;
		}
		// �ꎞ�ۑ����Ă��������f�[�^���폜
		delete tempNode;
		// �f�[�^�������炷
		m_Size--;
	}

	// �C�e���[�^�[�֘A
	using Iterator = InteractiveIterator<T>;
	Iterator begin() { return Iterator(m_pHead); }
	Iterator end() { return Iterator(nullptr); }
	Iterator rbegin() { return Iterator(m_pTail); }
	Iterator rend() { return Iterator(nullptr); }

private:
	// @brief �擪�̃f�[�^
	InteractiveNode<T>* m_pHead;
	// @brief �����̃f�[�^
	InteractiveNode<T>* m_pTail;
	// @brief �f�[�^����
	size_t m_Size;
};
