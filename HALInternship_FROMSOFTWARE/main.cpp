#include <iostream>
#include "InteractiveList.h"
#include "File.h"

// �t�@�C���p�X
#define FILE_PATH  "Assets/Data/Scores.txt"

// ���C���֐�
int main(void)
{
	// �o�������X�g�̍쐬
	InteractiveList<DataParam> list;

	//// �t�@�C���ǂݍ���
	//if (!LoadFile(FILE_PATH, list))
	//{
	//	std::cout << "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
	//}

	//// ���X�g�̃\�[�g
	//list.sort(SortAlgorithm::QuickSort, std::less<>(),
	//	[](const DataParam& d) {return d.m_nScore; });

	//// ���X�g�̓��e��\��
	//InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	//itEnd++;
	//// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	//std::cout << "�����������N�C�b�N�\�[�g�u�X�R�A(����)�v����������" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name 
	//		<< std::endl;
	//}

	//// ���X�g�̃\�[�g
	//list.sort(SortAlgorithm::QuickSort, std::greater<>(),
	//	[](const DataParam& d) {return d.m_nScore; });

	//// ���X�g�̓��e��\��
	//itEnd = list.cend();
	//itEnd++;
	//// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	//std::cout << "�����������N�C�b�N�\�[�g�u�X�R�A(�~��)�v����������" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}

	//// ���X�g�̃\�[�g
	//list.sort(SortAlgorithm::QuickSort, std::less<>(),
	//	[](const DataParam& d) {return d.m_Name; });

	//// ���X�g�̓��e��\��
	//itEnd = list.cend();
	//itEnd++;
	//// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	//std::cout << "�����������N�C�b�N�\�[�g�u���O(����)�v����������" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}

	//// ���X�g�̃\�[�g
	//list.sort(SortAlgorithm::QuickSort, std::greater<>(),
	//	[](const DataParam& d) {return d.m_Name; });

	//// ���X�g�̓��e��\��
	//itEnd = list.cend();
	//itEnd++;
	//// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	//std::cout << "�����������N�C�b�N�\�[�g�u���O(�~��)�v����������" << std::endl;
	//for (auto it = list.cbegin(); it != itEnd; ++it)
	//{
	//	const DataParam& data = *it;
	//	std::cout <<
	//		"Score: " << data.m_nScore
	//		<< ", " <<
	//		"Name: " << data.m_Name
	//		<< std::endl;
	//}


	list.pushBack({ 300, "Alice" });
	list.pushBack({ 150, "Bob" });
	list.pushBack({ 450, "Charlie" });
	list.pushBack({ 200, "Diana" });
	list.pushBack({ 400, "Eve" });


	list.sort(SortAlgorithm::QuickSort, std::less<>(),
		[](const DataParam& d) {return d.m_nScore; });

	// ���X�g�̓��e��\��
	InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	itEnd++;
	// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	std::cout << "�����������N�C�b�N�\�[�g�u�X�R�A(����)�v����������" << std::endl;
	for (auto it = list.cbegin(); it != itEnd; ++it)
	{
		const DataParam& data = *it;
		std::cout <<
			"Score: " << data.m_nScore
			<< ", " <<
			"Name: " << data.m_Name
			<< std::endl;
	}

	// �v���O�����I��
	return 0;
}