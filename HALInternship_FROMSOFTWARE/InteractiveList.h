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
	struct InteractiveNode
	{
		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveNode(): m_pPrevData(nullptr), m_pNextData(nullptr), m_Data(){
		}

		// @brief �R���X�g���N�^
		InteractiveNode(const T& In_Value):m_Data(In_Value), m_pPrevData(nullptr), m_pNextData(nullptr){
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
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator<T>;
	public:

		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveConstIterator() : m_pCurrent(nullptr), m_pOwner(nullptr){
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
			assert(m_pCurrent != &m_pOwner->m_Dummy);
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
			assert(m_pCurrent != &m_pOwner->m_Dummy);
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
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// �f�[�^��Ԃ�
			return m_pCurrent->m_Data;
		}

		// @brief �|�C���^�A�N�Z�X
		const T* operator->() const {
			// �A�T�[�g�`�F�b�N
			assert(m_pCurrent != nullptr);
			assert(m_pCurrent != &m_pOwner->m_Dummy);
			// �f�[�^��Ԃ�
			return &(m_pCurrent->m_Data);
		}

		// @brief ������Z�q
		const Self& operator=(const Self& other) {
			// �������g�ւ̑���łȂ����Ƃ��m�F
			if (this != &other) {
				m_pCurrent = other.m_pCurrent;
				m_pOwner = other.m_pOwner;
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
		using Node = InteractiveNode;
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
			assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
			// �f�[�^��Ԃ�
			return Base::m_pCurrent->m_Data;
		}

		// @brief �f�[�^�ւ̎Q��(��const��)
		T* operator->() {
			// �A�T�[�g�`�F�b�N
			assert(Base::m_pCurrent != nullptr);
			assert(Base::m_pCurrent != &Base::m_pOwner->m_Dummy);
			// �f�[�^��Ԃ�
			return &(Base::m_pCurrent->m_Data);
		}
	};

public:
	// �^�G�C���A�X
	using Node = InteractiveNode;
	using Iterator = InteractiveIterator<T>;
	using const_Iterator = InteractiveConstIterator<T>;

	// @brief �R���X�g���N�^
	InteractiveList();

	// @brief �R���X�g���N�^(�R�s�[�R���X�g���N�^)
	InteractiveList(const InteractiveList& other);

	// @brief �f�X�g���N�^
	~InteractiveList();

	// @brief ���X�g�̃f�[�^�̑������擾
	// @return �f�[�^�̑���
	const size_t getSize() const;

	// @brief ���X�g���󂩂ǂ������擾
	bool isEmpty() const;

	// @brief ���X�g���N���A
	void clear();

	// @brief �擪�Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushFront(const T& In_Value);

	// @brief �����Ƀf�[�^��ǉ�
	// @param In_Value �ǉ�����f�[�^
	void pushBack(const T& In_Value);

	// @brief �擪�̃f�[�^���폜
	void popFront();

	// @brief �����̃f�[�^���폜
	void popBack();

	// @brief �擪��const�ŃC�e���[�^�[�̎擾
	const const_Iterator cbegin() const;
	// @brief �擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator begin();

	// @brief ������const�ŃC�e���[�^�[�̎擾
	const const_Iterator cend() const;
	// @brief �����̔�const�ŃC�e���[�^�[�̎擾
	Iterator end();

	// @brief �t�����̐擪��const�ŃC�e���[�^�[�̎擾
	const const_Iterator crbegin() const;
	// @brief �t�����̐擪�̔�const�ŃC�e���[�^�[�̎擾
	Iterator rbegin();

	// @brief �t�����̖�����const�ŃC�e���[�^�[�̎擾
	const const_Iterator crend() const;
	// @brief �t�����̖����̔�const�ŃC�e���[�^�[�̎擾
	Iterator rend();

	// @brief �v�f�̍폜
	bool erase(const_Iterator pos);

	// @brief �v�f�̑}��
	bool insert(const_Iterator pos, const T& value);
	
private:
	// @brief �_�~�[�m�[�h
	Node m_Dummy;
	// @brief �f�[�^����
	size_t m_Size;
};

// �C�����C���t�@�C���̃C���N���[�h
#include "InteractiveList.inl"