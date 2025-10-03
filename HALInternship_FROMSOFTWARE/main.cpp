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
	//  const�ŃC�e���[�^�[���擾
	const InteractiveList<DataParam> const_list = list;

	InteractiveList<DataParam>::const_Iterator const_Itr= const_list.begin();

	const DataParam newData{ 200, "New_Player" };
	const_Itr++;
	list.insert(const_Itr, newData);

	// �C�e���[�^�[���g���ă��X�g�̊e�v�f�ɃA�N�Z�X
	for (const auto& data : list)
	{
		// �X�R�A�Ɩ��O��\��
		std::cout << 
			"Score: " << data->m_Data.m_nScore
			<< ", " << 
			"Name: " << data->m_Data.m_Name 
			<< std::endl;
	}

	list.clear();

	// �v���O�����I��
	return 0;
}