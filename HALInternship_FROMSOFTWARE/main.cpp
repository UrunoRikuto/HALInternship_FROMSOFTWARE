#include <iostream>
#include "InteractiveList.h"
#include "File.h"

#define FILE_PATH  "Assets/Data/Scores.txt"

int main(void)
{
	// �o�������X�g�̍쐬
	InteractiveList<DataParam> list;

	// �t�@�C���ǂݍ���
	if (!LoadFile<DataParam>(FILE_PATH, list))
	{
		std::cout << "�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
	}

	// ���X�g�̓��e��\��
	for(auto& data : list)
	{
		std::cout << "Score: " << data.m_nScore << ", Name: " << data.m_Name << std::endl;
	}


	return 0;
}