#include <iostream>
#include <string>
#include <time.h>


/// <summary>
/// ���\��
/// </summary>
/// <param name="number">�Ȃ�̒i���̐���</param>
void MultiplicationTable(const int& number);

/// <summary>
/// �p�^�[���`��
/// </summary>
/// <param name="maxCell">�ő�Z����</param>
void PatternDrawing(const int& maxCell);


/// <summary>
/// ����񂯂�Q�[��
/// </summary>
void RockPaperScissorsGame();


/// <summary>
/// �����̔��@
/// </summary>
void VendingMachine();

/// <summary>
/// �O�p�`����
/// </summary>
void CreateTriangle();


int main()
{
	
	// �v���O�������K
	enum class Practice
	{
		// ���K���1
		Act_1,
		// ���K���2
		Act_2,
		// ���K���3
		Act_3,
		// ���K���4
		Act_4,
		// ���K���5
		Act_5,
	};


	// ���K�ԍ�
	const Practice practice = Practice::Act_1;


	switch (practice)
	{
	case Practice::Act_1:

		//�ۑ�@
		
		//���}�̂悤�ȋ��̕\�𐶐�����v���O�������쐬���Ă��������B

		//	1  2  3  4  5  6  7  8  9
		//	2  4  6  8 10 12 14 16 18
		//	3  6  9 12 15 18 21 24 27
		//	4  8 12 16 20 24 28 32 36
		//	5 10 15 20 25 30 35 40 45
		//	6 12 18 24 30 36 42 48 54
		//	7 14 21 28 35 42 49 56 63
		//	8 16 24 32 40 48 56 64 72
		//	9 18 27 36 45 54 63 72 81


		// ���̒i�`��
		for (int i = 1; i <= 9; i++)
		{

			MultiplicationTable(i);
		}


		break;
	case Practice::Act_2:

		//�ۑ�A

		//���}�̂悤�Ȑ}�`�𐶐�����v���O�������쐬���Ă��������B

		//	������������������
		//	������������������
		//	������������������
		//	������������������
		//	������������������
		//	������������������
		//	������������������
		//	������������������
		//	������������������



		// �p�^�[���`��
		PatternDrawing(5);

		break;
	case Practice::Act_3:

		//�ۑ�B

		//���肪��l�̂Ƃ��̂���񂯂������v���O�������쐬���Ă��������B


		// ����񂯂�Q�[��
		RockPaperScissorsGame();


		break;
	case Practice::Act_4:

		//�ۑ�C

		//�����̔��@������B�R�[����180�~�A�X�|�[�c�h�����N��140�~�A����110�~�Ŕ����Ă���B
		//���������Ĉ��ݕ��𔃂������ɏo��d�݂Ǝ����̖������o�͂���v���O�������쐬���Ă��������B


		// ���̋@
		VendingMachine();


		break;
	case Practice::Act_5:

		//�ۑ�D

		//N�{�̖_������A3�{�I��ŎO�p�`������B���̖_���g���Ăł���O�p�`�̎��̒����̍ő�l���o�͂���v���O�������쐬���Ă��������B
		//�������A�O�p�`���ł��Ȃ��ꍇ�͎��̒������O�Ƃ��邱�ƁB

		// �O�p�`����
		CreateTriangle();

		break;
	default:

		// ���̒i�`��
		for (int i = 1; i <= 9; i++)
		{

			MultiplicationTable(i);
		}

		break;
	}


	// �����I��
	return 0;
}

void MultiplicationTable(const int& number)
{
	for (int i = 1; i <= 9; i++)
	{
		// �v�Z
		const int result = number * i;

		// �v�Z���ʕ`��
		std::cout << result << " ";


	}

	std::cout << "\n";

}

void PatternDrawing(const int& maxCell)
{
	// �J�E���g
	int count = 0;

	// �����؂�ւ��t���O
	bool isFlag = false;


	// �Z���`��
	for (int y = 1; y <= maxCell; y++)
	{
		// �Z���̔����̍ő�l���Ay�̒l���傫����Ώ�����ύX����
		isFlag = (maxCell / 2) < y;


		int num = 0;

		// �����ύX�t���O��true�Ȃ�΁Anum��1��������
		if (isFlag)
		{
			num = 1;
		}

		// �ő�l�ƍŏ��l�����߂�
		const int min = count + num;
		const int max = maxCell - min;


		// �Z���`��t���O
		bool isDrawCell = false;


		for (int x = 1; x <= maxCell; x++)
		{
			if (!isFlag)

			{
				isDrawCell = !(x <= min || x > max);
			}
			else
			{
				isDrawCell = !(x > min || x <= max);
			}

			if (isDrawCell)
			{
				std::cout << "�� ";
			}
			else
			{
				std::cout << "�� ";
			}




		}

		std::cout << "\n";

		count++;
	}

}
void RockPaperScissorsGame()
{
	std::cout << "����񂯂�Q�[��\n"
		<< "g:�O�[, c:�`���L, p:�p�[\n\n";


	std::string str = "";


	while (true)
	{
		// ���͎�t
		std::cout << "���́�";
		std::cin >> str;


		if (str == "g" || str == "G" || str == "��" || str == "�f" ||
			str == "c" || str == "C" || str == "��" || str == "�b" ||
			str == "p" || str == "P" || str == "��" || str == "�o")
		{
			std::cout << "���͐����I\n";

			break;
		}
		else
		{
			std::cout << "���͎��s...\n";
		}
	}

	// ����񂯂�񋓌^
	enum class RockPaperScissors
	{
		// �O�[
		Rock,
		// �p�[
		Paper,
		// �`���L
		Scissors,
	};


	// ����񂯂�
	enum class Judgement
	{
		// ����
		Win,
		// ����
		Lose,
		// ��������
		Draw,
	};



	// �v���C���[�̎�
	RockPaperScissors playerHand = RockPaperScissors::Paper;



	// �����̎�����߂�
	if (str == "g" || str == "G" || str == "��" || str == "�f")
	{
		playerHand = RockPaperScissors::Rock;
	}
	else if (str == "c" || str == "C" || str == "��" || str == "�b")
	{
		playerHand = RockPaperScissors::Scissors;
	}
	else
	{
		playerHand = RockPaperScissors::Paper;
	}


	// ����̎�����߂�
	const RockPaperScissors enemyHand = static_cast<RockPaperScissors>(rand() % 3);


	// ���s����
	Judgement judgement = Judgement::Draw;



	if (playerHand == RockPaperScissors::Rock && enemyHand == RockPaperScissors::Scissors ||
		playerHand == RockPaperScissors::Scissors && enemyHand == RockPaperScissors::Paper ||
		playerHand == RockPaperScissors::Paper && enemyHand == RockPaperScissors::Rock)
	{
		judgement = Judgement::Win;
	}
	else
	{
		judgement = Judgement::Lose;
	}

	if (playerHand == enemyHand)
	{
		judgement = Judgement::Draw;
	}


	switch (judgement)
	{
	case Judgement::Win:
		std::cout << "���񂽂̏�����ŁI�I�I\n";
		break;
	case Judgement::Lose:
		std::cout << "���O�̕�������������\n" << "�Ȃ�ŕ��������l���Ƃ��Ă�����������������\n";
		break;
	case Judgement::Draw:
		std::cout << "��������������...���傤����\n";
		break;
	default:
		break;
	}

}
void VendingMachine()
{

	std::cout << "���̋@\n"
		<< "�R�J�E�R�[��:180�~, �|�J���X�G�b�g:140�~, ����͂�:110�~\n\n";


	// �h�����N
	int cola = 0;	// �R�[��
	int pocari = 0;	// �|�J��
	int irohasu = 0;// ����͂�

	// ���͎�t
	std::cout << "�R�J�E�R�[�����F";
	std::cin >> cola;

	// ���͎�t
	std::cout << "\n�|�J���X�G�b�g���F";
	std::cin >> pocari;

	// ���͎�t
	std::cout << "\n����͂����F";
	std::cin >> irohasu;



	// ���v���z
	int total = (cola * 180) + (pocari * 140) + (irohasu * 110);

	// �e�����̒l�i��`��
	std::cout << "\n�R�J�E�R�[���F" << cola * 180 << "�~";
	std::cout << "\n�|�J���X�G�b�g�F" << pocari * 140 << "�~";
	std::cout << "\n����͂��F" << irohasu * 110 << "�~";
	std::cout << "\n\n���v�F" << total << "�~\n\n";



	// �ꖜ�~�D�̖��������߂�
	const int tenThousandYenBills = total / 10000;
	total -= tenThousandYenBills * 10000;

	// �ܐ�~�D�̖��������߂�
	const int fiveThousandYenBill = total / 5000;
	total -= fiveThousandYenBill * 5000;

	// ��~�D�̖��������߂�
	const int thousandYenBill = total / 1000;
	total -= thousandYenBill * 1000;




	// �ܕS�~�ʂ̖��������߂�
	const int fiveHundredYen = total / 500;
	total -= fiveHundredYen * 500;

	// �S�~�ʂ̖��������߂�
	const int hundredYen = total / 100;
	total -= hundredYen * 100;

	// �܏\�~�ʂ̖��������߂�
	const int fifteYen = total / 50;
	total -= fifteYen * 50;

	// �\�~�ʂ̖��������߂�
	const int tenYen = total / 10;
	total -= tenYen * 10;


	// ���D�̖��������߂�
	const int bill = tenThousandYenBills + fiveThousandYenBill + thousandYenBill;

	// ���K�̖��������߂�
	const int coin = fiveHundredYen + hundredYen + fifteYen + tenYen;

	// ���D�Ə��K�̖�����`��
	std::cout << "���D:" << bill << "��  ";
	std::cout << "���K:" << coin << "��  ";

}

void CreateTriangle()
{

	int num = 0;
	int oneSideLength = 0;


	// �{���擾
	std::cout << "�O�p�`�𐶐�����ہA���{�̖_���g�p���邩:";
	std::cin >> num;

	// �����擾
	std::cout << "��{�̖_�̒���:";
	std::cin >> oneSideLength;


	// �O�p�`������
	const int createTriangleNum = num / 3;

	// �O�p�`�̎��̒���
	const int triangleRoundLength = oneSideLength * 3;

	std::cout << "\n�O�p�`������:" << createTriangleNum << "��\n";
	std::cout << "�O�p�`�̎��̒���:" << triangleRoundLength << "\n";
}