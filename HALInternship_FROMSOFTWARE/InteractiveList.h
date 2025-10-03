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
	// @brief �f�X�g���N�^
	~InteractiveNode() = default;

	// @brief �f�[�^
	T m_Data;
	// @brief �O�̃f�[�^
	InteractiveNode* m_pPrevData;
	// @brief ���̃f�[�^
	InteractiveNode* m_pNextData;
};

// @brief �o�������X�g�p�R���X�g�C�e���[�^�[
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
class InteractiveConstIterator 
{
public:
	using Node = InteractiveNode<T>;
	using Self = InteractiveConstIterator<T>;

	// @brief �R���X�g���N�^
	InteractiveConstIterator(Node* node) : m_pCurrent(node) {
	}

	// @brief �R�s�[�R���X�g���N�^
	InteractiveConstIterator(const Self& other) : m_pCurrent(other.m_pCurrent) {
	}

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

	// @brief �m�[�h�{�̂ւ̃A�N�Z�X(const��)
	Node* operator*() const {
		return m_pCurrent;
	}

	// @brief ������Z�q
	Self& operator=(const Self& other) {
		if (this != &other) {
			m_pCurrent = other.m_pCurrent;
		}
		return *this;
	}

	// @brief �|�C���^�A�N�Z�X
	T* operator->() const {
		return &(m_pCurrent->m_Data);
	}

	// @brief ��r���Z�q
	const bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}
	const bool operator==(const Node& other) const {
		return m_pCurrent == other;
	}

	// @brief �s����r���Z�q
	const bool operator!=(const Self& other) {
		return !(*this == other);
	}
	const bool operator!=(const Node& other) const {
		return m_pCurrent != other;
	}

private:
	// @brief ���݂̃m�[�h
	Node* m_pCurrent;

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
	InteractiveIterator(Node* node) : m_pCurrent(node) {
	}
	
	// @brief �R�s�[�R���X�g���N�^
	InteractiveIterator(const Self& other) : m_pCurrent(other.m_pCurrent) {
	}

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

	// @brief �f�[�^�ւ̎Q��(��const��)
	T& operator->() {
		return m_pCurrent->m_Data;
	}

	// @brief �m�[�h�{�̂ւ̃A�N�Z�X(��const��)
	Node* operator* () {
		return m_pCurrent;
	}

	// @brief ��r���Z�q
	bool operator==(const Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}

	// @brief �s����r���Z�q
	bool operator!=(const Self& other) {
		return !(*this == other);
	}

private:
	// @brief �R���X�g���N�^
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

	// @brief �f�B�[�v�R�s�[�R���X�g���N�^
	// @param other �R�s�[���̃��X�g
	InteractiveList(const InteractiveList<T>& other)
		:m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_Size(0)
	{
		// ���̃��X�g�̃f�[�^�����ׂăR�s�[
		for (const auto& value : other) {
			pushBack(value->m_Data);
		}
	}

	// @brief �f�X�g���N�^
	~InteractiveList() {
		clear(); 
	}

	// @brief ���X�g�̃f�[�^�̑������擾
	// @return �f�[�^�̑���
	const size_t getSize() const {
		return m_Size; }

	// @brief ���X�g���󂩂ǂ������擾
	bool isEmpty() const {
		return m_Size == 0; 
	}

	// @brief ���X�g���N���A
	void clear() {
		// �f�[�^���Ȃ��Ȃ�܂Ő擪�̃f�[�^���폜
		while (!isEmpty()) {
			popFront();
		}
	}

	// @brief �擪�Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushFront(const T& In_Value) {
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(In_Value);
		// �������m�ێ��s���͏������Ȃ�
		if (!newNode) return;
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
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(In_Value);
		// �������m�ۂɎ��s�����ꍇ�͏������Ȃ�
		if (!newNode) return;
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

	// const�ŃC�e���[�^�[�֘A
	using const_Iterator = InteractiveConstIterator<T>;
	// ��const�ŃC�e���[�^�[�֘A
	using Iterator = InteractiveIterator<T>;

	// @brief �擪��const�ŃC�e���[�^�[�̎擾
	const_Iterator begin() const {
		return const_Iterator(m_pHead); 
	}
	// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator begin() {
		return Iterator(m_pHead); 
	}

	// @brief ������const�ŃC�e���[�^�[�̎擾
	const_Iterator end() const {
		return const_Iterator(nullptr); 
	}
	// @brief �����̔�const�ŃC�e���[�^�[�̎擾
	Iterator end() {
		return Iterator(nullptr); 
	}

	// @brief �t�����̐擪��const�ŃC�e���[�^�[�̎擾
	const_Iterator rbegin() const {
		return const_Iterator(m_pTail); 
	}
	// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator rbegin() {
		return Iterator(m_pTail); 
	}

	// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
	const_Iterator rend() const {
		return const_Iterator(nullptr); 
	}
	// @brief �t�����̖����̔�const�ŃC�e���[�^�[�̎擾
	Iterator rend() {
		return Iterator(nullptr); 
	}

	// @brief �v�f�̍폜
	Iterator erase(Iterator pos) {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return pos;
		// �폜����m�[�h���擾
		InteractiveNode<T>* nodeToDelete = (*pos);
		if (!nodeToDelete) return pos;
		// �m�[�h�̑O��̃m�[�h���擾
		InteractiveNode<T>* prevNode = nodeToDelete->m_pPrevData;
		InteractiveNode<T>* nextNode = nodeToDelete->m_pNextData;
		// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h���X�V
		if (prevNode) {
			prevNode->m_pNextData = nextNode;
		}
		else {
			// �폜����m�[�h���擪�̏ꍇ�A�擪���X�V
			m_pHead = nextNode;
		}
		// ���̃m�[�h�����݂���ꍇ�A���̑O�̃m�[�h���X�V
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// �폜����m�[�h�������̏ꍇ�A�������X�V
			m_pTail = prevNode;
		}
		// �m�[�h���폜
		delete nodeToDelete;
		m_Size--;
		// ���̃m�[�h�ւ̃C�e���[�^�[��Ԃ�
		return Iterator(nextNode);
	}
	const_Iterator erase(const_Iterator pos) {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return pos;
		InteractiveList<T>* nonConstList = const_cast<InteractiveList<T>*>(this);
		// �폜����m�[�h���擾
		InteractiveNode<T>* nodeToDelete = (*pos);
		if (!nodeToDelete) return pos;
		// �m�[�h�̑O��̃m�[�h���擾
		InteractiveNode<T>* prevNode = nodeToDelete->m_pPrevData;
		InteractiveNode<T>* nextNode = nodeToDelete->m_pNextData;
		// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h���X�V
		if (prevNode) {
			prevNode->m_pNextData = nextNode;
		}
		else {
			// �폜����m�[�h���擪�̏ꍇ�A�擪���X�V
			nonConstList->m_pHead = nextNode;
		}
		// ���̃m�[�h�����݂���ꍇ�A���̑O�̃m�[�h���X�V
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// �폜����m�[�h�������̏ꍇ�A�������X�V
			nonConstList->m_pTail = prevNode;
		}
		// �m�[�h���폜
		delete nodeToDelete;
		nonConstList->m_Size--;
		// ���̃m�[�h�ւ̃C�e���[�^�[��Ԃ�
		return const_Iterator(nextNode);
	}

	// @brief �v�f�̑}��
	Iterator insert(Iterator pos, const T& value) {
		// �����ȃC�e���[�^�[�̏ꍇ�͏������Ȃ�
		if (pos == end() && pos != begin() || pos == rend() && pos != rbegin()) return pos;
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(value);
		// �������m�ۂɎ��s�����ꍇ�͏������Ȃ�
		if (!newNode) return pos;
		// �}���ʒu��nullptr�̏ꍇ�A���X�g�̖����ɑ}��
		if (!(*pos)) {
			pushBack(value);
			m_Size--; // pushBack�ő���������߂�
		}
		else {
			// �}���ʒu�̃m�[�h���擾
			InteractiveNode<T>* currentNode = (*pos);

			// �}���ʒu�̑O�ɐV�����m�[�h��}��
			newNode->m_pNextData = currentNode;
			newNode->m_pPrevData = currentNode->m_pPrevData;
			// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h��V�����m�[�h�ɍX�V
			if (currentNode->m_pPrevData) {
				currentNode->m_pPrevData->m_pNextData = newNode;
			}
			else {
				// �}���ʒu���擪�̏ꍇ�A�擪���X�V
				m_pHead = newNode;
			}
			// �}���ʒu�̑O�̃m�[�h��V�����m�[�h�ɍX�V
			currentNode->m_pPrevData = newNode;
		}
		// �f�[�^���𑝂₷
		m_Size++;
		// �V�����m�[�h�ւ̃C�e���[�^�[��Ԃ�
		return Iterator(newNode);
	}
	const_Iterator insert(const_Iterator pos, const T& value) {

		const InteractiveList<T>& const_List = *this;

		// �����ȃC�e���[�^�[�̏ꍇ�͏������Ȃ�
		if (pos == const_List.end() && pos != const_List.begin()
			|| pos == const_List.rend() && pos != const_List.rbegin()) return pos;
		// �V�����m�[�h���쐬
		InteractiveNode<T>* newNode = new(std::nothrow) InteractiveNode<T>(value);
		// �������m�ۂɎ��s�����ꍇ�͏������Ȃ�
		if (!newNode) return pos;
		// �}���ʒu��nullptr�̏ꍇ�A���X�g�̖����ɑ}��
		if (!(*pos)) {
			pushBack(value);
			m_Size--; // pushBack�ő���������߂�
		}
		else {
			// �}���ʒu�̃m�[�h���擾
			InteractiveNode<T>* currentNode = (*pos);
			// �}���ʒu�̑O�ɐV�����m�[�h��}��
			newNode->m_pNextData = currentNode;
			newNode->m_pPrevData = currentNode->m_pPrevData;
			// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h��V�����m�[�h�ɍX�V
			if (currentNode->m_pPrevData) {
				currentNode->m_pPrevData->m_pNextData = newNode;
			}
			else {
				// �}���ʒu���擪�̏ꍇ�A�擪���X�V
				m_pHead = newNode;
			}
			// �}���ʒu�̑O�̃m�[�h��V�����m�[�h�ɍX�V
			currentNode->m_pPrevData = newNode;
		}
		// �f�[�^���𑝂₷
		m_Size++;
		// �V�����m�[�h�ւ̃C�e���[�^�[��Ԃ�
		return const_Iterator(newNode);
	}
	
private:
	// @brief �擪�̃f�[�^
	InteractiveNode<T>* m_pHead;
	// @brief �����̃f�[�^
	InteractiveNode<T>* m_pTail;
	// @brief �f�[�^����
	size_t m_Size;
};