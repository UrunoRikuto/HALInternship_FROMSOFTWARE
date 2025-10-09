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

	// �t�@�C���ǂݍ���
	if (!LoadFile(FILE_PATH, list))
	{
		std::cout << "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
	}

	// ���X�g�̃\�[�g
	list.sort(SortAlgorithm::QuickSort, SortOrder::Ascending,
		[](const DataParam& d) {return d.m_nScore; });

	// ���X�g�̓��e��\��
	InteractiveList<DataParam>::const_Iterator itEnd = list.cend();
	itEnd++;
	// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
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