#include "pch.h"
#include "/HAL/HALInternship_FROMSOFTWARE/HALInternship_FROMSOFTWARE/InteractiveList.h"

// ���X�g�̃e�X�g
namespace List
{
	//=================================== �f�[�^���̎擾 ===================================//
	// ���@�ځF���X�g����̏ꍇ�̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, 0)
	{
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF���X�g�����ւ̑}�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, 1)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF���X�g�����ւ̑}�������s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, 2)
	{
		// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̑}�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, 3)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.insert(it, 1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF�f�[�^�̑}�������s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, 4)
	{
		// "�}�����s"�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, 5)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̍폜�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, 6)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.end();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, 7)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�R���p�C�����ʂ�ΐ���
	TEST(ListDataSize, 8)
	{
		const InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
}