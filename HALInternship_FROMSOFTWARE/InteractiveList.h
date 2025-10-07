/*��������������������������������������������������������������
* 
* @file InteractiveList.h
* @brief �o�������X�g�̃w�b�_�[�t�@�C��
* 
��������������������������������������������������������������*/

#pragma once
#include <cassert>

// @brief �o�������X�g�N���X
// @typeparam T �ۑ�����f�[�^�̌^
template<typename T>
class InteractiveList
{
private:
	// @brief �o�������X�g�̃f�[�^�N���X
	template<typename T>
	struct InteractiveNode
	{
		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveNode()
			: m_pPrevData(nullptr)
			, m_pNextData(nullptr)
			, m_Data()
		{

		}

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
		// ���X�g�N���X���t�����h�ɐݒ�
		friend class InteractiveList<T>;

	private:
		// �^�G�C���A�X
		using Node = InteractiveNode<T>;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator<T>;
	public:

		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveConstIterator() : m_pCurrent(nullptr), m_pOwner(nullptr) {
		}

		// @brief �R���X�g���N�^
		InteractiveConstIterator(const Node* node, const List* owner){
			m_pCurrent = const_cast<Node*>(node);
			m_pOwner = const_cast<List*>(owner);
		}

		// @brief �R�s�[�R���X�g���N�^
		InteractiveConstIterator(const Self& other) {
			m_pCurrent = other.m_pCurrent;
			m_pOwner = other.m_pOwner;
		}


		// @brief �O�u�C���N�������g
		Self& operator++() {
			// �A�T�[�g�`�F�b�N
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// ���̃m�[�h�ֈړ�
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
			// �A�T�[�g�`�F�b�N
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// �O�̃m�[�h�ֈړ�
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
			// �A�T�[�g�`�F�b�N
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// �f�[�^��Ԃ�
			return m_pCurrent->m_Data;
		}

		// @brief �|�C���^�A�N�Z�X
		const T* operator->() const {
			// �A�T�[�g�`�F�b�N
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != m_pOwner->m_pDummy);
			// �f�[�^��Ԃ�
			return &(m_pCurrent->m_Data);
		}

		// @brief ������Z�q
		const Self& operator=(const Self& other) {
			// �������g�ւ̑���łȂ����Ƃ��m�F
			if (this != &other) {
				m_pCurrent = other.m_pCurrent;
			}
			return *this;
		}

		// @brief ��r���Z�q
		bool operator==(Self& other) {
			return m_pCurrent == other.m_pCurrent;
		}
		// @brief ��r���Z�q(const��)
		bool operator==(const Self& other) const {
			return m_pCurrent == other.m_pCurrent;
		}

		// @brief �s����r���Z�q
		bool operator!=(Self& other) {
			return !(*this == other);
		}
		// @brief �s����r���Z�q(const��)
		bool operator!=(const Self& other) const {
			return !(*this == other);
		}

		// @brief �������郊�X�g���擾
		const List* owner()const {
			return m_pOwner;
		}
	protected:
		// @brief ���݂̃m�[�h
		Node* m_pCurrent;
		// @brief �������郊�X�g
		List* m_pOwner;
	};

	// @brief �o�������X�g�p�C�e���[�^�[
	template<typename T>
	class InteractiveIterator : public InteractiveConstIterator<T>
	{
		// ���X�g�N���X���t�����h�ɐݒ�
		friend class InteractiveList<T>;

	private:
		// �^�G�C���A�X
		using Node = InteractiveNode<T>;
		using List = InteractiveList<T>;
		using Self = InteractiveIterator<T>;
		using Base = InteractiveConstIterator<T>;
	public:

		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveIterator() : Base() {
		}

		// @brief �R���X�g���N�^
		InteractiveIterator(Node* node, List* owner) : Base(node, owner) {
		}

		// @brief �R�s�[�R���X�g���N�^
		InteractiveIterator(const Self& other) : Base(other) {
		}


		// @brief �f�[�^�ւ̎Q��(��const��)
		T& operator* () {
			// �A�T�[�g�`�F�b�N
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != Base::m_pOwner->m_pDummy);
			// �f�[�^��Ԃ�
			return Base::m_pCurrent->m_Data;
		}

		// @brief �f�[�^�ւ̎Q��(��const��)
		T* operator->() {
			// �A�T�[�g�`�F�b�N
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != Base::m_pOwner->m_pDummy);
			// �f�[�^��Ԃ�
			return &(Base::m_pCurrent->m_Data);
		}
	};

public:
	// �^�G�C���A�X
	using Node = InteractiveNode<T>;
	using Iterator = InteractiveIterator<T>;
	using const_Iterator = InteractiveConstIterator<T>;

	// @brief �R���X�g���N�^
	InteractiveList() :m_Size(0){
		// �_�~�[�m�[�h���쐬
		m_pDummy = new Node();
		m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
	}

	// @brief �R���X�g���N�^(�R�s�[�R���X�g���N�^)
	InteractiveList(const InteractiveList& other) :m_Size(0){
		// �_�~�[�m�[�h���쐬
		m_pDummy = other.m_pDummy;
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
		// �擪�Ɩ�����m_pDummy�ɐݒ�
		m_pDummy = new Node();
		m_pDummy->m_pNextData = m_pDummy;
		m_pDummy->m_pPrevData = m_pDummy;
		m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
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
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = newNode;
		}
		// ���X�g�Ƀf�[�^������ꍇ
		else {
			// �ǉ��O�̐擪�f�[�^��V�����m�[�h�̎��̃f�[�^�ɐݒ�
			newNode->m_pNextData = m_pDummy->m_pNextData;
			// �ǉ��O�̐擪�f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
			newNode->m_pPrevData = m_pDummy;
			// �ǉ��O�̐擪�f�[�^�̑O�̃f�[�^��V�����m�[�h�ɐݒ�
			m_pDummy->m_pNextData->m_pPrevData = newNode;
			// �擪�f�[�^��V�����m�[�h�ɐݒ�
			m_pDummy->m_pNextData = newNode;
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
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = newNode;
		}
		// ���X�g�Ƀf�[�^������ꍇ
		else {
			// �ǉ��O�̖����f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
			newNode->m_pPrevData = m_pDummy->m_pPrevData;
			// �ǉ��O�̖����f�[�^��V�����m�[�h�̑O�̃f�[�^�ɐݒ�
			newNode->m_pNextData = m_pDummy;
			// �ǉ��O�̖����f�[�^�̎��̃f�[�^��V�����m�[�h�ɐݒ�
			m_pDummy->m_pPrevData->m_pNextData = newNode;
			// �����f�[�^��V�����m�[�h�ɐݒ�
			m_pDummy->m_pPrevData = newNode;
		}
		// �f�[�^���𑝂₷
		m_Size++;
	}

	// @brief �擪�̃f�[�^���폜
	void popFront() {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return;
		// �擪�f�[�^���ꎞ�ۑ�
		Node* tempNode = m_pDummy->m_pNextData;
		// �f�[�^�̑�����1�̏ꍇ
		if (m_Size == 1) {
			//�擪�Ɩ�����nullptr�ɐݒ�
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
		}
		// �f�[�^�̑����������̏ꍇ
		else {
			// �擪�f�[�^�����̃f�[�^�ɐݒ�
			m_pDummy->m_pNextData = m_pDummy->m_pNextData->m_pNextData;
			// �V�����擪�f�[�^�̑O�̃f�[�^��nullptr�ɐݒ�
			m_pDummy->m_pNextData->m_pPrevData = m_pDummy;
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
		Node* tempNode = m_pDummy->m_pPrevData;
		// �f�[�^�̑�����1�̏ꍇ
		if (m_Size == 1) {
			//�擪�Ɩ�����nullptr�ɐݒ�
			m_pDummy->m_pNextData = m_pDummy->m_pPrevData = m_pDummy;
		}
		// �f�[�^�̑����������̏ꍇ
		else {
			// �����f�[�^��O�̃f�[�^�ɐݒ�
			m_pDummy->m_pPrevData = m_pDummy->m_pPrevData->m_pPrevData;
			// �V���������f�[�^�̎��̃f�[�^��nullptr�ɐݒ�
			m_pDummy->m_pPrevData->m_pNextData = m_pDummy;
		}
		// �ꎞ�ۑ����Ă��������f�[�^���폜
		delete tempNode;
		// �f�[�^�������炷
		m_Size--;
	}

	// @brief �擪��const�ŃC�e���[�^�[�̎擾
	const const_Iterator cbegin() const {
		return const_Iterator(m_pDummy->m_pNextData, this);
	}
	// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator begin() {
		return Iterator(m_pDummy->m_pNextData, this); 
	}

	// @brief ������const�ŃC�e���[�^�[�̎擾
	const const_Iterator cend() const {
		return const_Iterator(m_pDummy, this);
	}
	// @brief �����̔�const�ŃC�e���[�^�[�̎擾
	Iterator end() {
		return Iterator(m_pDummy, this);
	}

	// @brief �t�����̐擪��const�ŃC�e���[�^�[�̎擾
	const const_Iterator crbegin() const {
		return const_Iterator(m_pDummy->m_pPrevData, this);
	}
	// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator rbegin() {
		return Iterator(m_pDummy->m_pPrevData, this); 
	}

	// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
	const const_Iterator crend() const {
		return const_Iterator(m_pDummy, this);
	}
	// @brief �t�����̖����̔�const�ŃC�e���[�^�[�̎擾
	Iterator rend() {
		return Iterator(m_pDummy, this);
	}

	// @brief �v�f�̍폜
	bool erase(const_Iterator pos) {
		// ���X�g����̏ꍇ�͏������Ȃ�
		if (isEmpty()) return false;

		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
		if (pos.owner() != this) return false;

		//�@�C�e���[�^�[��nullptr�������ꍇ�͏������Ȃ�
		if (pos == end())return false;

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
			m_pDummy->m_pNextData = nextNode;
		}
		// ���̃m�[�h�����݂���ꍇ�A���̑O�̃m�[�h���X�V
		if (nextNode) {
			nextNode->m_pPrevData = prevNode;
		}
		else {
			// �폜����m�[�h�������̏ꍇ�A�������X�V
			m_pDummy->m_pPrevData = prevNode;
		}
		// �m�[�h���폜
		delete pos.m_pCurrent;
		m_Size--;
		// ���̃m�[�h�ւ̃C�e���[�^�[��Ԃ�
		return true;
	}

	// @brief �v�f�̑}��
	bool insert(const_Iterator pos, const T& value) {
		// �������郊�X�g���قȂ�ꍇ�͏������Ȃ�
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
			m_pDummy->m_pNextData = newNode;
		}
		// �}���ʒu�̃m�[�h�̑O�̃m�[�h��V�����m�[�h�ɐݒ�
		pos.m_pCurrent->m_pPrevData = newNode;
		// �f�[�^���𑝂₷
		m_Size++;
		return true;
	}
	
private:
	// @brief �_�~�[�m�[�h
	Node* m_pDummy;
	// @brief �f�[�^����
	size_t m_Size;
};