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
		InteractiveNode();

		// @brief �R���X�g���N�^
		InteractiveNode(const T& In_Value);
		
		// @brief �f�X�g���N�^
		~InteractiveNode();

		// @brief �f�[�^
		T m_Data;
		// @brief �O�̃f�[�^
		InteractiveNode* m_pPrevData;
		// @brief ���̃f�[�^
		InteractiveNode* m_pNextData;
	};

	// @brief �o�������X�g�p�R���X�g�C�e���[�^�[
	class InteractiveConstIterator
	{
		// ���X�g�N���X���t�����h�ɐݒ�
		friend class InteractiveList<T>;

	private:
		// �^�G�C���A�X
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveConstIterator;
	public:

		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveConstIterator();

		// @brief �R���X�g���N�^
		// @param node �m�[�h�|�C���^
		// @param owner �������郊�X�g�|�C���^
		InteractiveConstIterator(const Node* node, const List* owner);

		// @brief �R�s�[�R���X�g���N�^
		// @param other �R�s�[���̃C�e���[�^�[
		InteractiveConstIterator(const Self& other);


		// @brief �O�u�C���N�������g
		Self& operator++();

		// @brief ��u�C���N�������g
		Self operator++(int);

		// @brief �O�u�f�N�������g
		Self& operator--();

		// @brief ��u�f�N�������g
		Self operator--(int);

		// @brief �f�[�^�ւ̎Q��(const��)
		const T& operator*() const;

		// @brief �|�C���^�A�N�Z�X
		const T* operator->() const;

		// @brief ������Z�q
		// @param other ������̃C�e���[�^�[
		const Self& operator=(const Self& other);

		// @brief ��r���Z�q
		// @param other ��r����C�e���[�^�[
		bool operator==(Self& other);
		// @brief ��r���Z�q(const��)
		// @param other ��r����C�e���[�^�[
		bool operator==(const Self& other) const;

		// @brief �s����r���Z�q
		// @param other ��r����C�e���[�^�[
		bool operator!=(Self& other);
		// @brief �s����r���Z�q(const��)
		// @param other ��r����C�e���[�^�[
		bool operator!=(const Self& other) const;

		// @brief �������郊�X�g���擾
		const List* owner()const;
	protected:
		// @brief ���݂̃m�[�h
		Node* m_pCurrent;
		// @brief �������郊�X�g
		List* m_pOwner;
	};

	// @brief �o�������X�g�p�C�e���[�^�[
	class InteractiveIterator : public InteractiveConstIterator
	{
		// ���X�g�N���X���t�����h�ɐݒ�
		friend class InteractiveList<T>;

	private:
		// �^�G�C���A�X
		using Node = InteractiveNode;
		using List = InteractiveList<T>;
		using Self = InteractiveIterator;
		using Base = InteractiveConstIterator;
	public:

		// @brief �f�t�H���g�R���X�g���N�^
		InteractiveIterator();

		// @brief �R���X�g���N�^
		// @param node �m�[�h�|�C���^
		// @param owner �������郊�X�g�|�C���^
		InteractiveIterator(Node* node, List* owner);

		// @brief �R�s�[�R���X�g���N�^
		InteractiveIterator(const Self& other);


		// @brief �f�[�^�ւ̎Q��(��const��)
		T& operator* ();

		// @brief �f�[�^�ւ̎Q��(��const��)
		T* operator->();
	};

public:
	// �^�G�C���A�X
	using Node = InteractiveNode;
	using Iterator = InteractiveIterator;
	using const_Iterator = InteractiveConstIterator;

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
	// @param pos �폜����v�f�̃C�e���[�^�[
	// @return �폜�ɐ���������true,���s������false
	bool erase(const_Iterator pos);

	// @brief �v�f�̑}��
	// @param pos �}������ʒu�̃C�e���[�^�[
	// @param value �}������f�[�^
	// @return �}���ɐ���������true,���s������false
	bool insert(const_Iterator pos, const T& value);
	
	// @brief �m�[�h�̃f�[�^������
	// @param NodeA ��������m�[�hA�̃C�e���[�^�[
	// @param NodeB ��������m�[�hB�̃C�e���[�^�[
	void swap(const_Iterator NodeA, const_Iterator NodeB);

public:
	// @brief �\�[�g�̏���
	enum class SortOrder
	{
		Ascending,	// ����
		Descending, // �~��
	};
	// @brief �\�[�g�A���S���Y���̎��
	enum class SortAlgorithm
	{
		QuickSort,	// �N�C�b�N�\�[�g
	};
	// @brief ���X�g���\�[�g
	template<typename U>
	void sort(SortAlgorithm type, SortOrder order);
private:

	// @brief 2�̃f�[�^���r���Aa��b��菬�������ǂ����𔻒�
	// @param a ��r����f�[�^
	// @param b ��r����f�[�^
	// @return a��b��菬�����ꍇtrue,�����łȂ��ꍇfalse
	template<typename U>
	bool _isLess(const T& a, const T& b);

	// @brief �s�|�b�g�l����Ƀ��X�g�̃m�[�h�����E�ɕ�������
	// @param start �p�[�e�B�V�����̊J�n�C�e���[�^�[
	// @param end �p�[�e�B�V�����̏I���C�e���[�^�[
	// @return �V�����s�{�b�g�̃C�e���[�^�[
	template<typename U>
	const_Iterator _partition(const_Iterator start, const_Iterator end);

	// @brief �N�C�b�N�\�[�g�̎���
	// @param start �\�[�g����͈͂̊J�n�C�e���[�^�[
	// @param end �\�[�g����͈͂̏I���C�e���[�^�[
	template<typename U>
	void _quickSort(const_Iterator start, const_Iterator end);

	// @brief ���X�g�𔽓]
	void _reverse();
private:
	// @brief �_�~�[�m�[�h
	Node m_Dummy;
	// @brief �f�[�^����
	size_t m_Size;
};

// �C�����C���t�@�C���̃C���N���[�h
#include "InteractiveList.inl"