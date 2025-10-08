#include "pch.h"
#include "InteractiveList.h"
#include "ListTest.h"

// ���X�g�̃e�X�g
namespace List
{
	//=================================== �f�[�^���̎擾 ===================================//
	// ���@�ځF���X�g����̏ꍇ�̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(0, list.getSize());
	}
	// ���@�ځF���X�g�����ւ̑}�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, TestGetDataSizeIsPushBackToTRUE)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����Ƀf�[�^��}��
		list.pushBack(1);
		// �f�[�^����1�ł��邱�Ƃ��m�F
		EXPECT_EQ(1,list.getSize());
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
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^��}��
		list.insert(it, 1);
		// �f�[�^����1�ł��邱�Ƃ��m�F
		EXPECT_EQ(1, list.getSize());
	}
	// ���@�ځF�f�[�^�̑}�������s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsInsertToFALSE)
	{
		// "�}�����s"�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		//InteractiveList<int> list;
		//InteractiveList<int>::Iterator it = list.begin();
		//list.insert(it, 1);
		//EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEraseToTRUE)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �f�[�^��}��
		list.pushBack(1);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^���폜
		list.erase(it);
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(0, list.getSize());
	}
	// ���@�ځF�f�[�^�̍폜�����s�����ۂ̖߂�l
	// ���@�z�F1
	TEST(ListDataSize, TestGetDataSizeIsEraseToFALSE)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �f�[�^��}��
		list.pushBack(1);
		// �����̌�̃C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		it++;
		// �f�[�^���폜
		list.erase(it);
		// �f�[�^����1�ł��邱�Ƃ��m�F
		EXPECT_EQ(1, list.getSize());
	}
	// ���@�ځF���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
	// ���@�z�F0
	TEST(ListDataSize, TestGetDataSizeIsEraseWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^���폜
		list.erase(it);
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(0, list.getSize());
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListDataSize, TestGetDataSizeConst)
	{	
#if defined TT_TEST_GET_DATA_SIZE_IS_CONST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(0, list.getSize());
#endif //TT_TEST_GET_DATA_SIZE_WHEN_CONST
		SUCCEED();
	}

	//=================================== �f�[�^�̑}�� ===================================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
	// ���@�z�F�擪�C�e���[�^�[�Ɩ����C�e���[�^�[�̂ǂ���ōs���Ă�����
	TEST(ListInsert, TestInsertWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_begin = list.begin();
		/// �擪�C�e���[�^�[ ///
		// �擪�ɑ}��
		ASSERT_TRUE(list.insert(it_begin, 1));
		// �f�[�^����1�ł��邱�Ƃ��m�F
		EXPECT_EQ(1, list.getSize());

		// ���X�g����ɂ���
		list.clear();
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_end = list.end();
		
		/// �����C�e���[�^�[ ///
		// �����ɑ}��
		ASSERT_TRUE(list.insert(it_end, 1));
		// �f�[�^����1�ł��邱�Ƃ��m�F
		EXPECT_EQ(1, list.getSize());
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�擪�ɑ}������Č��X�̃f�[�^�����ɂ����
	TEST(ListInsert, TestInsertWhenHaveDataToBegin)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_begin = list.begin();
		// �擪�ɑ}��
		ASSERT_TRUE(list.insert(it_begin, 1));

		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();

		// �f�[�^��1,2,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�����C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�����ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenHaveDataToEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;

		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(3);

		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_end = list.end();

		// �����ɑ}��
		ASSERT_TRUE(list.insert(it_end, 2));

		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^��1,2,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�w�肵���ʒu�ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenHaveDataToMiddle)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾����1�i�߂�
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		// 2��}��
		ASSERT_TRUE(list.insert(it, 2));
		// �C�e���[�^�[��擪�ɖ߂�
		it = list.begin();
		// �f�[�^��1,2,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// ���@�ځFConst�ŃC�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�C�e���[�^�[�̎����ʒu�ɑ}������Č��X�̃f�[�^�͂��̂܂�
	TEST(ListInsert, TestInsertWhenConstIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;

		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(3);

		// Const�ŃC�e���[�^�[���擾����1�i�߂�
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;

		// 2��}��
		list.insert(const_it, 2);

		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();

		// �f�[�^��1,2,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ(1,(*it));
		it++;
		EXPECT_EQ(2,(*it));
		it++;
		EXPECT_EQ(3,(*it));
	}
	// ���@�ځF�s���ȃC�e���[�^�[��n���đ}�������ۂ̋���
	// ���@�z�F�}���Ɏ��s���ăf�[�^���͑����Ȃ�
	TEST(ListInsert, TestInsertWhenInvalidIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �ŏ��̃��X�g�Ƃ͕ʂ̃��X�g���쐬���ăC�e���[�^�[���擾
		InteractiveList<int> list2;
		// ���X�g�Ƀf�[�^��}��
		list2.pushBack(3);
		// �擪�C�e���[�^�[���擾����1�i�߂�
		InteractiveList<int>::Iterator it = list2.begin();
		it++;
		// �}���Ɏ��s���邱�Ƃ��m�F
		ASSERT_FALSE(list.insert(it, 4));
		// �f�[�^����2�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 2);

		// ���X�g�Q�Ƃ̂Ȃ��C�e���[�^�[���쐬
		InteractiveList<int>::Iterator it_nullptr;
		// �}���Ɏ��s���邱�Ƃ��m�F
		ASSERT_FALSE(list.insert(it_nullptr, 4));
		// �f�[�^����2�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 2);
	}
	// ���@�ځF��const�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListInsert, TestInsertWhenConst)
	{
#if defined TT_TEST_INSERT_WHEN_CONST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �}���Ɏ��s���邱�Ƃ��m�F
		list.insert(it, 1); // �����ŃR���p�C���G���[�ɂȂ�
#endif //TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

	//=================================== �f�[�^�̍폜 ===================================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̋���
	// ���@�z�F�����N����Ȃ�
	TEST(ListErase, TestEraseWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^���폜
		ASSERT_FALSE(list.erase(it));
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 0);
		// �����C�e���[�^�[
		it = list.end();
		// �f�[�^���폜
		list.erase(it);
		// �f�[�^����0�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 0);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�擪�̃f�[�^���폜����āA2�Ԗڈȍ~�̃f�[�^���O�ɂ����
	TEST(ListErase, TestEraseWhenHaveDataToBegin)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_begin = list.begin();
		// �擪�̃f�[�^���폜
		ASSERT_TRUE(list.erase(it_begin));
		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^��2,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ((*it), 2);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�����C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�����̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenHaveDataToEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_end = list.end();
		// �����̃f�[�^���폜
		ASSERT_TRUE(list.erase(it_end));
		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^��1,2�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 2);
	}
	// ���@�ځF���X�g�ɕ����̃f�[�^������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�w�肵���ʒu�̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenHaveDataToMiddle)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾����1�i�߂�
		InteractiveList<int>::Iterator it = list.begin();
		it++;
		// 2���폜
		ASSERT_TRUE(list.erase(it));
		// �C�e���[�^�[��擪�ɖ߂�
		it = list.begin();
		// �f�[�^��1,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځFConst�ŃC�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�w�肵���ʒu�̃f�[�^���폜����āA���X�̃f�[�^�͂��̂܂�
	TEST(ListErase, TestEraseWhenConstIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// Const�ŃC�e���[�^�[���擾����1�i�߂�
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		const_it++;
		// 2���폜
		ASSERT_TRUE(list.erase(const_it));
		// �C�e���[�^�[��擪�ɖ߂�
		InteractiveList<int>::Iterator it = list.begin();
		// �f�[�^��1,3�̏��ł��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
		it++;
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځF�s���ȃC�e���[�^�[��n���č폜�����ۂ̋���
	// ���@�z�F�폜�Ɏ��s���ăf�[�^���͑����Ȃ�
	TEST(ListErase, TestEraseWhenInvalidIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �ŏ��̃��X�g�Ƃ͕ʂ̃��X�g���쐬���ăC�e���[�^�[���擾
		InteractiveList<int> list2;
		// ���X�g�Ƀf�[�^��}��
		list2.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list2.begin();
		// �폜�Ɏ��s���邱�Ƃ��m�F
		ASSERT_FALSE(list.erase(it));
		// �f�[�^����2�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 2);

		// ���X�g�Q�Ƃ̂Ȃ��C�e���[�^�[���쐬
		InteractiveList<int>::Iterator it_nullptr;
		// �폜�Ɏ��s���邱�Ƃ��m�F
		ASSERT_FALSE(list.erase(it_nullptr));
		// �f�[�^����2�ł��邱�Ƃ��m�F
		EXPECT_EQ(list.getSize(), 2);
	}
	// ���@�ځF��const�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListErase, TestEraseWhenConst)
	{
#if defined TT_TEST_ERASE_WHEN_CONST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();//�����ŃG���[
		// �f�[�^���폜
		list.erase(it);//�����ŃG���[
#endif //TT_TEST_ERASE_WHEN_CONST
		SUCCEED();
	}

	//============================= �擪�C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �_�~�[�m�[�h���w���C�e���[�^�[���擾
		InteractiveList<int>::Iterator dummy = list.end();
		// �擪�C�e���[�^�[�ƃ_�~�[�m�[�h���w���C�e���[�^�[�����������Ƃ��m�F
		EXPECT_EQ(it, dummy);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenHaveOneData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginAfterInsert)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// 1��}��
		list.insert(it, 1);
		// �擪�C�e���[�^�[���Ď擾
		it = list.begin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListBegin, TestBeginAfterErase)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(2);
		list.pushBack(1);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// 1���폜
		list.erase(it);
		// �擪�C�e���[�^�[���Ď擾
		it = list.begin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځFconst�̃��X�g����Const�ŃC�e���[�^�[�łȂ��擪�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListBegin, TestBeginWhenConstList)
	{
#if defined TT_TEST_BEGIN_WHEN_CONST_LIST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();//�����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_CONST_LIST
		SUCCEED();
	}
	
	//============================= �擪�R���X�g�C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// �_�~�[�m�[�h���w���C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator dummy = list.cend();
		// �擪�R���X�g�C�e���[�^�[�ƃ_�~�[�m�[�h���w���C�e���[�^�[�����������Ƃ��m�F
		EXPECT_EQ(it, dummy);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenHaveOneData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// �擪�R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�擪�R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginAfterInsert)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(2);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// 1��}��
		list.insert(it, 1);
		// �擪�R���X�g�C�e���[�^�[���Ď擾
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*const_it), 1);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�擪�R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�擪�̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstBegin, TestConstBeginAfterErase)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(2);
		list.pushBack(1);
		list.pushBack(3);
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// 1���폜
		list.erase(it);
		// �擪�R���X�g�C�e���[�^�[���Ď擾
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// �擾�����C�e���[�^�[���擪�̗v�f���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*const_it), 1);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListConstBegin, TestConstBeginWhenConst)
	{
#if defined TT_TEST_CONST_BEGIN_WHEN_CONST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �擪�R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cbegin();
		// �_�~�[�m�[�h���w���C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator dummy = list.cend();
		// �擪�R���X�g�C�e���[�^�[�ƃ_�~�[�m�[�h���w���C�e���[�^�[�����������Ƃ��m�F
		EXPECT_EQ(it, dummy);
#endif //TT_TEST_CONST_BEGIN_WHEN_CONST
		SUCCEED();
	}

	//============================= �����C�e���[�^�[=============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// �_�~�[�m�[�h���w���C�e���[�^�[���擾
		InteractiveList<int>::Iterator dummy = list.rend();
		// �����C�e���[�^�[�ƃ_�~�[�m�[�h���w���C�e���[�^�[�����������Ƃ��m�F
		EXPECT_EQ(it, dummy);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenHaveOneData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndAfterInsert)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// 2��}��
		list.insert(it, 2);
		// �����C�e���[�^�[���Ď擾
		it = list.end();

		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�����C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListEnd, TestEndAfterErase)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// 3���폜
		list.erase(it);
		// �����C�e���[�^�[���Ď擾
		it = list.end();
		
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 2);
	}
	// ���@�ځFconst�̃��X�g����Const�ŃC�e���[�^�[�łȂ������C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�}�N����`���ăR���p�C���G���[�ɂȂ�ΐ���
	TEST(ListEnd, TestEndWhenConstList)
	{
#if defined TT_TEST_END_WHEN_CONST_LIST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();//�����ŃG���[
#endif //TT_TEST_END_WHEN_CONST_LIST
		SUCCEED();
	}
	
	// ============================= Const�Ŗ����C�e���[�^�[ =============================//
	// ���@�ځF���X�g����ł���ꍇ�ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�_�~�[�m�[�h���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenEmpty)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
		// �_�~�[�m�[�h���w���C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator dummy = list.crend();
		// �����R���X�g�C�e���[�^�[�ƃ_�~�[�m�[�h���w���C�e���[�^�[�����������Ƃ��m�F
		EXPECT_EQ(it, dummy);
	}
	// ���@�ځF���X�g�ɗv�f�������ꍇ�ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F���̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenHaveOneData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// �����R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 1);
	}
	// ���@�ځF���X�g�ɕ����̗v�f������ꍇ�ɁA�����R���X�g�C���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*it), 3);
	}
	// ���@�ځF�f�[�^�̑}�����s������ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndAfterInsert)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
		// 2��}��
		list.insert(it, 2);
		// �����R���X�g�C�e���[�^�[���Ď擾
		InteractiveList<int>::const_Iterator const_it = list.cend();
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*const_it), 3);
	}
	// ���@�ځF�f�[�^�̍폜���s������ɁA�����R���X�g�C�e���[�^�[���擾�����ۂ̋���
	// ���@�z�F�����̗v�f���w���C�e���[�^�[���Ԃ�
	TEST(ListConstEnd, TestConstEndAfterErase)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
		// 3���폜
		list.erase(it);
		// �����R���X�g�C�e���[�^�[���Ď擾
		InteractiveList<int>::const_Iterator const_it = list.cend();
		// �擾�����C�e���[�^�[�̎����v�f�������̗v�f�Ɠ��������Ƃ��m�F
		EXPECT_EQ((*const_it), 2);
	}
	// ���@�ځFconst�̃��\�b�h�ł��邩
	// ���@�z�F�}�N����`���ăR���p�C�����ʂ�ΐ���
	TEST(ListConstEnd, TestConstEndWhenConst)
	{
#if defined TT_TEST_CONST_END_WHEN_CONST
		// const�Ń��X�g���쐬
		const InteractiveList<int> list;
		// �����R���X�g�C�e���[�^�[���擾
		InteractiveList<int>::const_Iterator it = list.cend();
#endif //TT_TEST_CONST_END_WHEN_CONST
		SUCCEED();
	}

}// ���X�g�̃e�X�g

// �C�e���[�^�[�̃e�X�g
namespace Iterator
{
	// ============================= �C�e���[�^�[�̎����v�f���擾 =============================//
	// ���@�ځF���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����Ƃ��̋���
	// ���@�z�FAssert����
	TEST(IteratorGetData, TestGetDataWhenNoList)
	{
		// ���X�g�Q�ƂȂ��C�e���[�^�[���쐬
		InteractiveList<int>::Iterator it;
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF�C�e���[�^�[����擾�����v�f�ɑ΂��Ēl�̑�����s���邩�`�F�b�N
	// ���@�z�F����ł���
	TEST(IteratorGetData, TestGetDataAssign)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// �C�e���[�^�[���擾���Ēl��ύX
		InteractiveList<int>::Iterator it = list.begin();
		// �l����
		(*it) = 2;
		// �C�e���[�^�[��擪�ɖ߂��Ēl���m�F
		it = list.begin();
		// �ύX����Ă��邱�Ƃ��m�F
		EXPECT_EQ(2, (*it));
	}
	// ���@�ځFConst�ŃC�e���[�^�[����擾�����v�f�ɑ΂��Ēl�̑�����s���Ȃ����`�F�b�N
	// ���@�z�F�R���p�C���G���[�ɂȂ�
	TEST(IteratorGetData, TestGetDataWhenConstIterator)
	{
#if defined TT_TEST_GET_DATA_WHEN_CONST_ITERATOR
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// Const�ŃC�e���[�^�[���擾���Ēl��ύX
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// �l����
		(*const_it) = 2;//�����ŃG���[
#endif //TT_TEST_GET_DATA_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// ���@�ځF���X�g����̍ۂɐ擪�C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorGetData, TestGetDataWhenEmptyToBegin)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g����̍ۂɖ����C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorGetData, TestGetDataWhenEmptyToEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			(*it);
			}, "Assertion failed.*");
#endif // _DEBUG
	}

	// ============================ �C�e���[�^�[�𖖔��Ɍ������Ĉ�i�߂� =============================//
	// ���@�ځF���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����Ƃ��̋���
	// ���@�z�FAssert����
	TEST(IteratorIncrement, TestIncrementWhenNoList)
	{
		// ���X�g�Q�ƂȂ��C�e���[�^�[���쐬
		InteractiveList<int>::Iterator it;
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			it++;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g����̍ۂɐ擪�C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorIncrement, TestIncrementWhenEmptyToBegin)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			it++;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g����̍ۂɖ����C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorIncrement, TestIncrementWhenEmptyToEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
	it++;
			}, "Assertion failed.*");

#endif // _DEBUG
	}
	// ���@�ځF���X�g�ɕ����̗v�f������Ƃ��ɌĂяo�����Ƃ��̋���
	// ���@�z�F�C�e���[�^�[����i��
	TEST(IteratorIncrement, TestIncrementWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}
	// ���@�ځF�O�u�C���N�������g���s�����ۂ̋���
	// ���@�z�F�C�e���[�^�[����i��
	TEST(IteratorIncrement, TestIncrementWhenPre)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		++it;
		EXPECT_EQ(2, (*it));
		++it;
		EXPECT_EQ(3, (*it));
	}
	// ���@�ځF��u�C���N�������g���s�����ۂ̋���
	// ���@�z�F�C�e���[�^�[����i��
	TEST(IteratorIncrement, TestIncrementWhenPost)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �����܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.begin();
		EXPECT_EQ(1, (*it));
		it++;
		EXPECT_EQ(2, (*it));
		it++;
		EXPECT_EQ(3, (*it));
	}

	//============================= �C�e���[�^�[��擪�Ɍ������Ĉ�i�߂� =============================//
	// ���@�ځF���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����Ƃ��̋���
	// ���@�z�FAssert����
	TEST(IteratorDecrement, TestDecrementWhenNoList)
	{
		// ���X�g�Q�ƂȂ��C�e���[�^�[���쐬
		InteractiveList<int>::Iterator it;
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g����̍ۂɖ����C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorDecrement, TestDecrementWhenEmptyToBegin)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.end();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g����̍ۂɐ擪�C�e���[�^�[�ɑ΂��ČĂяo�����ۂ̋���
	// ���@�z�FAssert����
	TEST(IteratorDecrement, TestDecrementWhenEmptyToEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// Assert�������m�F
#ifdef _DEBUG
		EXPECT_DEATH({
			it--;
			}, "Assertion failed.*");
#endif // _DEBUG
	}
	// ���@�ځF���X�g�ɕ����̗v�f������Ƃ��ɌĂяo�����Ƃ��̋���
	// ���@�z�F�C�e���[�^�[����߂�
	TEST(IteratorDecrement, TestDecrementWhenHaveMultipleData)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		it--;
		EXPECT_EQ(2, (*it));
		it--;
		EXPECT_EQ(1, (*it));
	}
	// ���@�ځF�O�u�f�N�������g���s�����ۂ̋���
	// ���@�z�F�C�e���[�^�[����߂�
	TEST(IteratorDecrement, TestDecrementWhenPre)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		--it;
		EXPECT_EQ(2, (*it));
		--it;
		EXPECT_EQ(1, (*it));
	}
	// ���@�ځF��u�f�N�������g���s�����ۂ̋���
	// ���@�z�F�C�e���[�^�[����߂�
	TEST(IteratorDecrement, TestDecrementWhenPost)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		// �擪�܂Ŋm�F����
		InteractiveList<int>::Iterator it = list.end();
		EXPECT_EQ(3, (*it));
		it--;
		EXPECT_EQ(2, (*it));
		it--;
		EXPECT_EQ(1, (*it));
	}

	//============================= �C�e���[�^�[�̃R�s�[ =============================//
	// ���@�ځF�R���X�g�C�e���[�^�[����C�e���[�^�[���R�s�[�R���X�g���N�g�����ۂ̋���
	// ���@�z�F�R���p�C���G���[�ɂȂ�
	TEST(IteratorCopy, TestCopyWhenConstIterator)
	{
#if defined TT_TEST_COPY_WHEN_CONST_ITERATOR
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// Const�ŃC�e���[�^�[���擾
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// �C�e���[�^�[���R�s�[�R���X�g���N�g
		InteractiveList<int>::Iterator it = const_it;//�����ŃG���[
#endif //TT_TEST_COPY_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// ���@�ځF�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ����ł��邩
	// ���@�z�F�����ł���
	TEST(IteratorCopy, TestCopyValue)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// �R�s�[�R���X�g���N�g
		InteractiveList<int>::Iterator it2 = it;
		// �R�s�[���ƃR�s�[�悪�����l���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), (*it2));
	}

	//============================= �C�e���[�^�[�̑�� =============================//
	// ���@�ځF�C�e���[�^�[�ɃR���X�g�ŃC�e���[�^�[���������ۂ̋���
	// ���@�z�F�R���p�C���G���[�ɂȂ�
	TEST(IteratorAssign, TestAssignWhenConstIterator)
	{
#if defined TT_TEST_ASSIGN_WHEN_CONST_ITERATOR
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		// Const�ŃC�e���[�^�[���擾
		InteractiveList<int>::const_Iterator const_it = list.cbegin();
		// �C�e���[�^�[�ɑ��
		InteractiveList<int>::Iterator it;
		it = const_it;//�����ŃG���[
#endif //TT_TEST_ASSIGN_WHEN_CONST_ITERATOR
		SUCCEED();
	}
	// ���@�ځF�����̒l��������Ɠ����ł��邩
	// ���@�z�F�����ł���
	TEST(IteratorAssign, TestAssignValue)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		// ���
		InteractiveList<int>::Iterator it2;
		it2 = it;
		(*it2) = 5;
		// ������Ƒ���悪�����l���w���Ă��邱�Ƃ��m�F
		EXPECT_EQ((*it), 5);
	}

	//============================= ��̃C�e���[�^�[������̂��̂ł��邩��r =============================//
	// ���@�ځF���X�g����̏�ԂŐ擪�C�e���[�^�[�Ɩ����C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�����ł���(TRUE)
	TEST(IteratorCompare, TestCompareWhenEmptyToBeginAndEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[�Ɩ����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_begin = list.begin();
		InteractiveList<int>::Iterator it_end = list.end();
		// �����ł��邱�Ƃ��m�F
		EXPECT_TRUE(it_begin == it_end);
	}
	// ���@�ځF����̃C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�����ł���(TRUE)
	TEST(IteratorCompare, TestCompareWhenSameIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		// �����ł��邱�Ƃ��m�F
		EXPECT_TRUE(it == it2);
	}
	// ���@�ځF�قȂ�C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�قȂ���̂ł���(FALSE)
	TEST(IteratorCompare, TestCompareWhenDifferentIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �قȂ�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		it2++;
		// �قȂ���̂ł��邱�Ƃ��m�F
		EXPECT_FALSE(it == it2);
	}
	
	//============================= ��̃C�e���[�^�[���قȂ���̂ł��邩��r =============================//
	// ���@�ځF���X�g����̏�ԂŐ擪�C�e���[�^�[�Ɩ����C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�����ł���(FALSE)
	TEST(IteratorNotCompare, TestNotCompareWhenEmptyToBeginAndEnd)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// �擪�C�e���[�^�[�Ɩ����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it_begin = list.begin();
		InteractiveList<int>::Iterator it_end = list.end();
		// �����ł��邱�Ƃ��m�F
		EXPECT_FALSE(it_begin != it_end);
	}
	// ���@�ځF����̃C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�����ł���(FALSE
	TEST(IteratorNotCompare, TestNotCompareWhenSameIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �����C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		// �����ł��邱�Ƃ��m�F
		EXPECT_FALSE(it != it2);
	}
	// ���@�ځF�قȂ�C�e���[�^�[���r�����ۂ̋���
	// ���@�z�F�قȂ���̂ł���(TRUE)
	TEST(IteratorNotCompare, TestNotCompareWhenDifferentIterator)
	{
		// ���X�g���쐬
		InteractiveList<int> list;
		// ���X�g�Ƀf�[�^��}��
		list.pushBack(1);
		list.pushBack(2);
		// �قȂ�C�e���[�^�[���擾
		InteractiveList<int>::Iterator it = list.begin();
		InteractiveList<int>::Iterator it2 = list.begin();
		it2++;
		// �قȂ���̂ł��邱�Ƃ��m�F
		EXPECT_TRUE(it != it2);
	}

}// �C�e���[�^�[�̃e�X�g