#include "pch.h"
#include "/HAL/HALInternship_FROMSOFTWARE/HALInternship_FROMSOFTWARE/InteractiveList.h"
#include "ListTest.h"

// ���X�g�̃e�X�g
namespace List
{
	//=================================== �f�[�^���̎擾 ===================================//
	// ���@�ځF���X�g����̏ꍇ�̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEmpty)
	{
		InteractiveList<int> list;
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF���X�g�����ւ̑}�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, TestGetDataSizeIsPushBackToTRUE)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF���X�g�����ւ̑}�������s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsPushBackToFALSE)
	{
		// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		//InteractiveList<int> list;
		//ASSERT_FALSE(list.pushBack(1));
		//EXPECT_EQ(0, list.getSize());
	}
	// ���@�ځF�f�[�^�̑}�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, TestGetDataSizeIsInsertToTRUE)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.insert(it, 1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF�f�[�^�̑}�������s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsInsertToFALSE)
	{
		// "�}�����s"�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		//InteractiveList<int> list;
		//auto it = list.begin();
		//list.insert(it, 1);
		//EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEraseToTRUE)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̍폜�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, TestGetDataSizeIsEraseToFALSE)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.end();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEraseWhenEmpty)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListDataSize, TestGetDataSizeConst)
	{
#if defined TT_TEST_GET_DATA_SIZE_WHEN_CONST
		const InteractiveList<int> list;
		EXPECT_EQ(0, list.getSize());
#endif //TT_TEST_GET_DATA_SIZE_WHEN_CONST
		SUCCEED();
	}

	//=================================== �f�[�^�̑}�� ===================================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
	// ���@�z�F�擪�C�e���[�^�[�Ɩ����C�e���[�^�[�̂ǂ���ōs���Ă�����
	TEST(ListInsert, TestInsertWhenEmpty)
	{
		InteractiveList<int> list;
		auto it_begin = list.begin();
		auto it_end = list.end();
		/* �擪�C�e���[�^�[ */
		list.insert(it_begin, 1);
		EXPECT_EQ(list.getSize(), 1);
		list.clear();
		/* �����C�e���[�^�[ */
		list.insert(it_end, 1);
		EXPECT_EQ(list.getSize(), 1);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�擪�ɑ}������Č��X�̃f�[�^�����ɂ����
	TEST(ListInsert, TestInsertWhenHaveDataToBegin)
	{
		InteractiveList<int> list;
		list.pushBack(2);
		list.pushBack(3);
		auto it_begin = list.begin();
		list.insert(it_begin, 1);

		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
		it++;
		EXPECT_EQ((*it)->m_Data, 2);
		it++;
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�����C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�����ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenHaveDataToEnd)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(3);
		auto it_end = list.rbegin();
		list.insert(it_end, 2);

		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
		it++;
		EXPECT_EQ((*it)->m_Data, 2);
		it++;
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�w�肵���ʒu�ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenHaveDataToMiddle)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(3);
		auto it = list.begin();
		it++;
		list.insert(it, 2);

		it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
		it++;
		EXPECT_EQ((*it)->m_Data, 2);
		it++;
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځFConst�ŃC�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�C�e���[�^�[�̎����ʒu�ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenConstIterator)
	{
		//InteractiveList<int> list;

		//// �擪�ɑ}��
		//list.pushBack(1);
		//list.pushBack(3);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.begin();
		//const_it++;
		//list.insert(const_it, 2);
		//auto it = list.begin();
		//it = list.begin();
		//EXPECT_EQ((*it)->m_Data, 1);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 2);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF�s���ȃC�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�}���Ɏ��s���ăf�[�^���͑����Ȃ�
	TEST(ListInsert, TestInsertWhenInvalidIterator)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		auto it = list.end();
		it++;
		list.insert(it, 3);
		EXPECT_EQ(list.getSize(), 2);
	}
	// ���@�ځF��const�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListInsert, TestInsertWhenConst)
	{
#if defined TT_TEST_INSERT_WHEN_CONST
		const InteractiveList<int> list;
		auto it = list.begin();
		list.insert(it, 1);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

	//=================================== �f�[�^�̍폜 ===================================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̋���
	// ���@�z�F�����N����Ȃ�
	TEST(ListErase, TestEraseWhenEmpty)
	{
		InteractiveList<int> list;
		auto it = list.begin();
		list.erase(it);
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�擪�̃f�[�^���폜����āA2�Ԗڈȍ~�̃f�[�^���O�ɂ����
	TEST(ListErase, TestEraseWhenHaveDataToBegin)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it_begin = list.begin();
		list.erase(it_begin);
		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 2);
		it++;
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�����C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�����̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenHaveDataToEnd)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it_end = list.rbegin();
		list.erase(it_end);
		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
		it++;
		EXPECT_EQ((*it)->m_Data, 2);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�w�肵���ʒu�̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenHaveDataToMiddle)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.begin();
		it++;
		list.erase(it);
		it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
		it++;
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځFConst�ŃC�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�w�肵���ʒu�̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenConstIterator)
	{
		//InteractiveList<int> list;
		//list.pushBack(1);
		//list.pushBack(2);
		//list.pushBack(3);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.begin();
		//const_it++;
		//list.erase(const_it);
		//auto it = list.begin();
		//EXPECT_EQ((*it)->m_Data, 1);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF�s���ȃC�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�폜�Ɏ��s���ăf�[�^���͑����Ȃ�
	TEST(ListErase, TestEraseWhenInvalidIterator)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		auto it = list.end();
		it++;
		list.erase(it);
		EXPECT_EQ(list.getSize(), 2);
	}
	// ���@�ځF��const�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListErase, TestEraseWhenConst)
	{
#if defined TT_TEST_ERASE_WHEN_CONST
		const InteractiveList<int> list;
		auto it = list.begin();
		list.erase(it);//�����ŃG���[
#endif //TT_TEST_ERASE_WHEN_CONST
		SUCCEED();
	}

	//============================= �擪�C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenEmpty)
	{
		//InteractiveList<int> list;
		//auto it = list.begin();
		//auto end_it = list.end();
		//EXPECT_EQ(it, end_it);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F���̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginAfterInsert)
	{
		InteractiveList<int> list;
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.begin();
		list.insert(it, 1);
		it = list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.begin();
		list.erase(it);
		it = list.begin();
		EXPECT_EQ((*it)->m_Data, 2);
	}
	// ���@�ځFconst�̃��X�g����Const�ŃC�e���[�^�[�łȂ��擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListBegin, TestBeginWhenConstList)
	{
#if defined TT_TEST_BEGIN_WHEN_CONST_LIST
		const InteractiveList<int> list;
		auto it = list.begin();//�����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_CONST_LIST
		SUCCEED();
	}

	//============================= �擪�R���X�g�C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenEmpty)
	{
		//InteractiveList<int> list;
		//const InteractiveList<int> const_list = list;
		//auto it = const_list.begin();
		//auto end_it = const_list.end();
		//EXPECT_EQ(it, end_it);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F���̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		const InteractiveList<int> const_list = list;
		auto it = const_list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		const InteractiveList<int> const_list = list;
		auto it = const_list.begin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�擪�R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginAfterInsert)
	{
		//InteractiveList<int> list;
		//list.pushBack(2);
		//list.pushBack(3);
		//auto it = list.begin();
		//list.insert(it, 1);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.begin();
		//EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�擪�R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginAfterErase)
	{
		//InteractiveList<int> list;
		//list.pushBack(1);
		//list.pushBack(2);
		//list.pushBack(3);
		//auto it = list.begin();
		//list.erase(it);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.begin();
		//EXPECT_EQ((*it)->m_Data, 2);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListConstBegin, TestConstBeginWhenConst)
	{
#if defined TT_TEST_CONST_BEGIN_WHEN_CONST
		const InteractiveList<int> list;
		auto it = list.begin();
		EXPECT_EQ(it, list.end());
#endif //TT_TEST_CONST_BEGIN_WHEN_CONST
		SUCCEED();
	}

	//============================= �����C�e���[�^�[=============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenEmpty)
	{
		//InteractiveList<int> list;
		//auto it = list.end();
		//auto begin_it = list.begin();
		//EXPECT_EQ(it, begin_it);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F���̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		auto it = list.rbegin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.rbegin();
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndAfterInsert)
	{
		//InteractiveList<int> list;
		//list.pushBack(1);
		//list.pushBack(2);
		//auto it = list.rbegin();
		//list.insert(it, 3);
		//it = list.rbegin();
		//EXPECT_EQ((*it)->m_Data, 2);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 3);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndAfterErase)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		auto it = list.rbegin();
		list.erase(it);
		it = list.rbegin();
		EXPECT_EQ((*it)->m_Data, 2);
	}
	// ���@�ځFconst�̃��X�g����Const�ŃC�e���[�^�[�łȂ������C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListEnd, TestEndWhenConstList)
	{
#if defined TT_TEST_END_WHEN_CONST_LIST
		const InteractiveList<int> list;
		auto it = list.end();//�����ŃG���[
#endif //TT_TEST_END_WHEN_CONST_LIST
		SUCCEED();
	}
	// ============================= Const�Ŗ����C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenEmpty)
	{
		//InteractiveList<int> list;
		//const InteractiveList<int> const_list = list;
		//auto it = const_list.end();
		//auto begin_it = const_list.begin();
		//EXPECT_EQ(it, begin_it);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F���̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenHaveOneData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		const InteractiveList<int> const_list = list;
		auto it = const_list.rbegin();
		EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�����R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenHaveMultipleData)
	{
		InteractiveList<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		const InteractiveList<int> const_list = list;
		auto it = const_list.rbegin();
		EXPECT_EQ((*it)->m_Data, 3);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	TEST(ListConstEnd, TestConstEndAfterInsert)
	{
		//InteractiveList<int> list;
		//list.pushBack(1);
		//list.pushBack(2);
		//auto it = list.rbegin();
		//list.insert(it, 3);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.rbegin();
		//EXPECT_EQ((*it)->m_Data, 2);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 3);
		//it++;
		//EXPECT_EQ((*it)->m_Data, 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndAfterErase)
	{
		//InteractiveList<int> list;
		//list.pushBack(1);
		//list.pushBack(2);
		//list.pushBack(3);
		//auto it = list.rbegin();
		//list.erase(it);
		//const InteractiveList<int> const_list = list;
		//auto const_it = const_list.rbegin();
		//EXPECT_EQ((*it)->m_Data, 2);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListConstEnd, TestConstEndWhenConst)
	{
#if defined TT_TEST_CONST_END_WHEN_CONST
		const InteractiveList<int> list;
		auto it = list.end();
		EXPECT_EQ(it, list.begin());
#endif //TT_TEST_CONST_END_WHEN_CONST
		SUCCEED();
	}
}