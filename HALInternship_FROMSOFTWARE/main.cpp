#include <iostream>
#include "InteractiveList.h"
#include "File.h"

// �t�@�C���p�X
#define FILE_PATH  "Assets/Data/Scores.txt"

// ���C���֐�
int main(void)
{
	using DataList = InteractiveList<DataParam>;

	// �o�������X�g�̍쐬
	DataList list;

	// �t�@�C���ǂݍ���
	if (!LoadFile(FILE_PATH, list))
	{
		std::cout << "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
	}

	// ���X�g�̓��e��\��
	//  const�ŃC�e���[�^�[���擾
	const DataList Iterator = list;
	// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	for(auto& data : Iterator)
	{
		// �X�R�A�Ɩ��O��\��
		std::cout << 
			"Score: " << data.m_nScore
			<< ", " << 
			"Name: " << data.m_Name 
			<< std::endl;
	}


	// �v���O�����I��
	return 0;
}