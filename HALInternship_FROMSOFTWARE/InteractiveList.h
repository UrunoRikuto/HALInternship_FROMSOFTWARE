/*��������������������������������������������������������������
* 
* @file InteractiveList.h
* @brief �o�������X�g�̃w�b�_�[�t�@�C��
* 
��������������������������������������������������������������*/

#pragma once

// �v���g�^�C�v�錾
template<typename>
class InteractiveIterator;

template<typename>
class InteractiveConstIterator;

template<typename>
class InteractiveList;

// @brief �o�������X�g�̃f�[�^�N���X
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
template<typename T>
class InteractiveConstIterator 
{
public:
	using Node = InteractiveNode<T>;
	using List = InteractiveList<T>;
	using Self = InteractiveConstIterator<T>;

	// @brief �f�t�H���g�R���X�g���N�^
	InteractiveConstIterator() : m_pCurrent(nullptr),m_pOwner(nullptr) {
	}

	// @brief �R���X�g���N�^
	InteractiveConstIterator(const Node* node,const List* owner) : m_pCurrent(node), m_pOwner(owner) {
	}

	// @brief �R�s�[�R���X�g���N�^
	InteractiveConstIterator(const Self& other) : m_pCurrent(other.m_pCurrent), m_pOwner(other.m_pOwner) {
	}

	// InteractiveIterator ����̕ϊ��R���X�g���N�^

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
	const T& operator*() const {
		return m_pCurrent->m_Data;
	}

	// @brief �|�C���^�A�N�Z�X
	const T* operator->() const {
		return &(m_pCurrent->m_Data);
	}

	// @brief ������Z�q
	const Self& operator=(const Self& other) {
		if (this != &other) {
			m_pCurrent = other.m_pCurrent;
		}
		return *this;
	}

	// @brief ��r���Z�q
	bool operator==(Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}
	bool operator==(std::nullptr_t) {
		return m_pCurrent == nullptr;
	}

	// @brief �s����r���Z�q
	bool operator!=(Self& other) {
		return !(*this == other);
	}

	// @brief �������郊�X�g���擾
	const List* owner()const{
		return m_pOwner;
	}

private:
	// @brief ���݂̃m�[�h
	const Node* m_pCurrent;
	// @brief �������郊�X�g
	const List* m_pOwner;

};

// @brief �o�������X�g�p�C�e���[�^�[
template<typename T>
class InteractiveIterator
{
public:
	using Node = InteractiveNode<T>;
	using List = InteractiveList<T>;
	using Self = InteractiveIterator<T>;

	// @brief �f�t�H���g�R���X�g���N�^
	InteractiveIterator() : m_pCurrent(nullptr),m_pOwner(nullptr) {
	}

	// @brief �R���X�g���N�^
	InteractiveIterator(Node* node,List* owner) : m_pCurrent(node),m_pOwner(owner) {
	}
	
	// @brief �R�s�[�R���X�g���N�^
	InteractiveIterator(const Self& other) : m_pCurrent(other.m_pCurrent),m_pOwner(other.m_pOwner) {
	}

	// @brief �O�u�C���N�������g
	Self& operator++() {
		if (m_pCurrent && m_pCurrent->m_pNextData) m_pCurrent = m_pCurrent->m_pNextData;
		else m_pCurrent = nullptr;
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
		if (m_pCurrent && m_pCurrent->m_pPrevData) m_pCurrent = m_pCurrent->m_pPrevData;
		else m_pCurrent = nullptr;
		return *this;
	}

	// @brief ��u�f�N�������g
	Self operator--(int) {
		Self temp = *this;
		--(*this);
		return temp;
	}

	// @brief �f�[�^�ւ̎Q��(��const��)
	T& operator* () {
		return m_pCurrent->m_Data;
	}

	// @brief �f�[�^�ւ̎Q��(��const��)
	T* operator->() {
		return &(m_pCurrent->m_Data);
	}

	// @brief ��r���Z�q
	bool operator==(Self& other) {
		return m_pCurrent == other.m_pCurrent;
	}
	bool operator==(std::nullptr_t) {
		return m_pCurrent == nullptr;
	}

	// @brief �s����r���Z�q
	bool operator!=(Self& other) {
		return !(*this == other);
	}

	// @brief �������郊�X�g���擾
	List* owner(){
		return m_pOwner;
	}

private:
	// @brief ���݂̃m�[�h
	Node* m_pCurrent;
	// @brief �������郊�X�g
	List* m_pOwner;
};

// @brief �o�������X�g�N���X
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
class InteractiveList
{
public:
	using Node = InteractiveNode<T>;
	using Iterator = InteractiveIterator<T>;
	using const_Iterator = InteractiveConstIterator<T>;

	// @brief �R���X�g���N�^
	InteractiveList()
		:m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_Size(0)
	{
	}

	// @brief �R���X�g���N�^(�R�s�[�R���X�g���N�^)
	InteractiveList(const InteractiveList& other)
	{
		m_pHead = m_pTail = nullptr;
		m_Size = 0;
		for (auto it = other.begin(); it != other.end(); ++it) {
			pushBack((*it)->m_Data);
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
		Node* newNode = new(std::nothrow) Node(In_Value);
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
		Node* newNode = new(std::nothrow) Node(In_Value);
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
		Node* tempNode = m_pHead;
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
		Node* tempNode = m_pTail;
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

	// @brief �擪��const�ŃC�e���[�^�[�̎擾
	const_Iterator cbegin() const {
		return const_Iterator(m_pHead, this);
	}
	// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator begin() {
		return Iterator(m_pHead, this); 
	}

	// @brief ������const�ŃC�e���[�^�[�̎擾
	const_Iterator cend() const {
		return const_Iterator(nullptr, this);
	}
	// @brief �����̔�const�ŃC�e���[�^�[�̎擾
	Iterator end() {
		return Iterator(nullptr, this);
	}

	// @brief �t�����̐擪��const�ŃC�e���[�^�[�̎擾
	const_Iterator crbegin() const {
		return const_Iterator(m_pTail, this);
	}
	// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator rbegin() {
		return Iterator(m_pTail, this); 
	}

	// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
	const_Iterator crend() const {
		return const_Iterator(nullptr, this); 
	}
	// @brief �t�����̖����̔�const�ŃC�e���[�^�[�̎擾
	Iterator rend() {
		return Iterator(nullptr, this); 
	}

	// @brief �v�f�̍폜
	bool erase(Iterator pos) {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return false;

		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
		if (pos.owner() != this) return false;

		// �폜����m�[�h���擾
		Node* nodeToDelete = new(std::nothrow) Node(*pos);
		if (!nodeToDelete) return false;
		// �m�[�h�̑O��̃m�[�h���擾
		Node* prevNode = nodeToDelete->m_pPrevData;
		Node* nextNode = nodeToDelete->m_pNextData;
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
		return true;
	}
	bool erase(const_Iterator pos) {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return false;

		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
		if (pos.owner() != this) return false;

		// �폜����m�[�h���擾
		Node* nodeToDelete = new(std::nothrow) Node((*pos));
		if (!nodeToDelete) return false;
		// �m�[�h�̑O��̃m�[�h���擾
		Node* prevNode = nodeToDelete->m_pPrevData;
		Node* nextNode = nodeToDelete->m_pNextData;
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
		return true;
	}

	// @brief �v�f�̑}��
	bool insert(Iterator pos, const T& value) {
		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
		if (pos.owner() != this) return false;

		// �����ȃC�e���[�^�[�̏ꍇ�͏������Ȃ�
		if (pos != end() && pos != rend() && pos != begin() && pos != rbegin() && pos == nullptr) return false;

		// �}������m�[�h���쐬
		Node* newNode = new(std::nothrow) Node(value);
		if (!newNode) return false;
		// �}���ʒu�̃m�[�h���擾
		Node* currentNode = new(std::nothrow) Node(*pos);
		if (!currentNode) {
			// �}���ʒu�������̏ꍇ�ApushBack���g�p
			pushBack(value);
			return true;
		}
		// �}���ʒu�̑O�̃m�[�h���擾
		Node* prevNode = currentNode->m_pPrevData;
		// �V�����m�[�h�̑O��̃m�[�h��ݒ�
		newNode->m_pPrevData = prevNode;
		newNode->m_pNextData = currentNode;
		// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h��V�����m�[�h�ɐݒ�
		if (prevNode) {
			prevNode->m_pNextData = newNode;
		}
		else {
			// �}���ʒu���擪�̏ꍇ�A�擪��V�����m�[�h�ɍX�V
			m_pHead = newNode;
		}
		// �}���ʒu�̃m�[�h�̑O�̃m�[�h��V�����m�[�h�ɐݒ�
		currentNode->m_pPrevData = newNode;
		// �f�[�^���𑝂₷
		m_Size++;
		return true;
	}
	bool insert(const_Iterator pos, const T& value) {
		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
		if (pos.owner() != this) return false;

		// �����ȃC�e���[�^�[�̏ꍇ�͏������Ȃ�
		if (pos != cend() && pos != crend() && pos != cbegin() && pos != crbegin() && pos == nullptr) return false;

		
		// �}������m�[�h���쐬
		Node* newNode = new(std::nothrow) Node(value);
		if (!newNode) return false;
		// �}���ʒu�̃m�[�h���擾
		Node* currentNode = new(std::nothrow) Node((*pos));
		if (!currentNode) {
			// �}���ʒu�������̏ꍇ�ApushBack���g�p
			pushBack(value);
			return true;
		}
		// �}���ʒu�̑O�̃m�[�h���擾
		Node* prevNode = currentNode->m_pPrevData;
		// �V�����m�[�h�̑O��̃m�[�h��ݒ�
		newNode->m_pPrevData = prevNode;
		newNode->m_pNextData = currentNode;
		// �O�̃m�[�h�����݂���ꍇ�A���̎��̃m�[�h��V�����m�[�h�ɐݒ�
		if (prevNode) {
			prevNode->m_pNextData = newNode;
		}
		else {
			// �}���ʒu���擪�̏ꍇ�A�擪��V�����m�[�h�ɍX�V
			m_pHead = newNode;
		}
		// �}���ʒu�̃m�[�h�̑O�̃m�[�h��V�����m�[�h�ɐݒ�
		currentNode->m_pPrevData = newNode;
		// �f�[�^���𑝂₷
		m_Size++;
		return true;
	}
	
private:
	// @brief �擪�̃f�[�^
	Node* m_pHead;
	// @brief �����̃f�[�^
	Node* m_pTail;
	// @brief �f�[�^����
	size_t m_Size;
};