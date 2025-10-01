/*��������������������������������������������������������������
* 
* @file File.h
* @brief �t�@�C������Ɋւ���w�b�_�[�t�@�C��
* 
��������������������������������������������������������������*/

#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "InteractiveList.h"

// @brief �f�[�^�\����
struct DataParam
{
	// @brief �X�R�A
	int m_nScore = 0;
	// @brief ���O
	std::string m_Name = "";
};

// @brief �t�@�C������f�[�^��ǂݍ��݁A���X�g�Ɋi�[
// @param In_FileName �ǂݍ��ރt�@�C���p�X
// @param Out_List �i�[���郊�X�g
// @return �t�@�C�����삪����������true,���s������false
template<typename T>
bool LoadFile(const std::string& In_FileName, InteractiveList<T>& Out_List) {
	// �t�@�C�����J��
	std::ifstream inputFile(In_FileName);
	if (!inputFile.is_open()) return false;

	std::string line;
	// 1�s���ǂݍ���
	while (std::getline(inputFile, line)) {
		// DataParam�^�̏ꍇ�̂ݏ���
		if (typeid(T) == typeid(DataParam)) {
			// �s���X�g���[���ɕϊ�
			std::istringstream iss(line);

			// �^�u��؂�ŕ���
			std::string idStr, name;
			if (!std::getline(iss, idStr, '\t')) continue;
			if (!std::getline(iss, name)) continue;

			// �f�[�^�\���̂��쐬
			DataParam data;
			// ������𐮐��ɕϊ����Ċi�[
			data.m_nScore = std::stoi(idStr);
			// ���O���i�[
			data.m_Name = name;

			// ���X�g�Ƀf�[�^��ǉ�
			Out_List.pushBack(data);
		}
		else {
			// �Ή����Ă��Ȃ��^�̏ꍇ�t�@�C�������
			inputFile.close();
			// �������s
			return false;
		}
	}

	// �t�@�C�������
	inputFile.close();

	// ��������
	return true;
}