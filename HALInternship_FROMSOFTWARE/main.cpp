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

	// ���X�g�̓��e��\��
	// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	for (const auto& data : list)
	{
		std::cout <<
			"Score: " << data.m_nScore
			<< ", " <<
			"Name: " << data.m_Name 
			<< std::endl;
	}

	list.clear();

	// �v���O�����I��
	return 0;
}