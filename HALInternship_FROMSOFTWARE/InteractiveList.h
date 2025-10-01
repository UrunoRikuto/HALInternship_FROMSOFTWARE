/*��������������������������������������������������������������
* 
* @file InteractiveList.h
* @brief �o�������X�g�̃w�b�_�[�t�@�C��
* 
��������������������������������������������������������������*/

#pragma once

/// <summary>
/// �o�������X�g�̃f�[�^�N���X
/// </summary>
/// <typeparam name="T">�ۑ�����f�[�^�̌^</typeparam>
template<typename T>
class InteractiveNode
{
	// �֐�
public:
	// @brief �R���X�g���N�^
	InteractiveNode(const T& In_Value)
		:m_Data(In_Value)
		, m_pPrevData(nullptr)
		, m_pNextData(nullptr)
	{
	}

	// �ϐ�
public:
	// @brief �f�[�^
	T m_Data;
	// @brief �O�̃f�[�^
	InteractiveNode* m_pPrevData;
	// @brief ���̃f�[�^
	InteractiveNode* m_pNextData;
};

/// <summary>
/// �o�������X�g�p�C�e���[�^�[
/// </summary>
template<typename T>
class InteractiveIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveIterator<T>;

	InteractiveIterator(Node* node) : m_Current(node) {}

	// �O�u�C���N�������g
	Self& operator++() {
		if (m_Current) m_Current = m_Current->m_pNextData;
		return *this;
	}

	// ��u�C���N�������g
	Self operator++(int) {
		Self temp = *this;
		++(*this);
		return temp;
	}

	// �O�u�f�N�������g
	Self& operator--() {
		if (m_Current) m_Current = m_Current->m_pPrevData;
		return *this;
	}

	// ��u�f�N�������g
	Self operator--(int) {
		Self temp = *this;
		--(*this);
		return temp;
	}

	// �f�[�^�ւ̎Q��
	T& operator*() const {
		return m_Current->m_Data;
	}

	// �|�C���^�A�N�Z�X
	T* operator->() const {
		return &(m_Current->m_Data);
	}

	// ��r���Z�q
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
/// �o�������X�g�N���X
/// </summary>
/// <typeparam name="T">���X�g�ɕۑ�����^</typeparam>
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
	~InteractiveList() { Clear(); }

	// @brief ���X�g�̃f�[�^�̑������擾
	// @return �f�[�^�̑���
	const size_t GetListSize() { return m_Size; }

	// @brief ���X�g���󂩂ǂ������擾
	const bool IsEmpty() { return m_Size == 0; }

	// @brief �擪�f�[�^���擾
	// @return �擪�f�[�^
	const InteractiveNode<T>* GetFront() { return m_pHead; }

	// @brief �����f�[�^���擾
	// @return �����f�[�^
	const InteractiveNode<T>* GetBack() { return m_pTail; }

	// @brief ���X�g���N���A
	void Clear() {
		// �f�[�^���Ȃ��Ȃ�܂Ő擪�̃f�[�^���폜
		while (!IsEmpty()) {
			popFront();
		}
	}

	// @brief �擪�Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushFront(const T& In_Value) {
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new InteractiveNode<T>(In_Value);
		// ���X�g����̏ꍇ
		if (IsEmpty()) {
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
		if (IsEmpty()) {
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
		if (IsEmpty()) return;
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
		if (IsEmpty()) return;
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