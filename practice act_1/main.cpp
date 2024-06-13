#include <iostream>
#include <string>
#include <time.h>


/// <summary>
/// 九九表示
/// </summary>
/// <param name="number">なんの段かの数字</param>
void MultiplicationTable(const int& number);

/// <summary>
/// パターン描画
/// </summary>
/// <param name="maxCell">最大セル数</param>
void PatternDrawing(const int& maxCell);


/// <summary>
/// じゃんけんゲーム
/// </summary>
void RockPaperScissorsGame();


/// <summary>
/// 自動販売機
/// </summary>
void VendingMachine();

/// <summary>
/// 三角形生成
/// </summary>
void CreateTriangle();


int main()
{
	
	// プログラム練習
	enum class Practice
	{
		// 練習問題1
		Act_1,
		// 練習問題2
		Act_2,
		// 練習問題3
		Act_3,
		// 練習問題4
		Act_4,
		// 練習問題5
		Act_5,
	};


	// 練習番号
	const Practice practice = Practice::Act_1;


	switch (practice)
	{
	case Practice::Act_1:

		//課題①
		
		//下図のような九九の表を生成するプログラムを作成してください。

		//	1  2  3  4  5  6  7  8  9
		//	2  4  6  8 10 12 14 16 18
		//	3  6  9 12 15 18 21 24 27
		//	4  8 12 16 20 24 28 32 36
		//	5 10 15 20 25 30 35 40 45
		//	6 12 18 24 30 36 42 48 54
		//	7 14 21 28 35 42 49 56 63
		//	8 16 24 32 40 48 56 64 72
		//	9 18 27 36 45 54 63 72 81


		// 九九の段描画
		for (int i = 1; i <= 9; i++)
		{

			MultiplicationTable(i);
		}


		break;
	case Practice::Act_2:

		//課題②

		//下図のような図形を生成するプログラムを作成してください。

		//	■■■■■■■■■
		//	□■■■■■■■□
		//	□□■■■■■□□
		//	□□□■■■□□□
		//	□□□□■□□□□
		//	□□□■■■□□□
		//	□□■■■■■□□
		//	□■■■■■■■□
		//	■■■■■■■■■



		// パターン描画
		PatternDrawing(5);

		break;
	case Practice::Act_3:

		//課題③

		//相手が一人のときのじゃんけんをするプログラムを作成してください。


		// じゃんけんゲーム
		RockPaperScissorsGame();


		break;
	case Practice::Act_4:

		//課題④

		//自動販売機がある。コーラが180円、スポーツドリンクが140円、水が110円で売られている。
		//お金を入れて飲み物を買った時に出る硬貨と紙幣の枚数を出力するプログラムを作成してください。


		// 自販機
		VendingMachine();


		break;
	case Practice::Act_5:

		//課題⑤

		//N本の棒があり、3本選んで三角形をつくる。この棒を使ってできる三角形の周の長さの最大値を出力するプログラムを作成してください。
		//ただし、三角形ができない場合は周の長さを０とすること。

		// 三角形生成
		CreateTriangle();

		break;
	default:

		// 九九の段描画
		for (int i = 1; i <= 9; i++)
		{

			MultiplicationTable(i);
		}

		break;
	}


	// 処理終了
	return 0;
}

void MultiplicationTable(const int& number)
{
	for (int i = 1; i <= 9; i++)
	{
		// 計算
		const int result = number * i;

		// 計算結果描画
		std::cout << result << " ";


	}

	std::cout << "\n";

}

void PatternDrawing(const int& maxCell)
{
	// カウント
	int count = 0;

	// 処理切り替えフラグ
	bool isFlag = false;


	// セル描画
	for (int y = 1; y <= maxCell; y++)
	{
		// セルの半分の最大値より、yの値が大きければ処理を変更する
		isFlag = (maxCell / 2) < y;


		int num = 0;

		// 処理変更フラグがtrueならば、numに1を代入する
		if (isFlag)
		{
			num = 1;
		}

		// 最大値と最小値を求める
		const int min = count + num;
		const int max = maxCell - min;


		// セル描画フラグ
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
				std::cout << "■ ";
			}
			else
			{
				std::cout << "□ ";
			}




		}

		std::cout << "\n";

		count++;
	}

}
void RockPaperScissorsGame()
{
	std::cout << "じゃんけんゲーム\n"
		<< "g:グー, c:チョキ, p:パー\n\n";


	std::string str = "";


	while (true)
	{
		// 入力受付
		std::cout << "入力→";
		std::cin >> str;


		if (str == "g" || str == "G" || str == "ｇ" || str == "Ｇ" ||
			str == "c" || str == "C" || str == "ｃ" || str == "Ｃ" ||
			str == "p" || str == "P" || str == "ｐ" || str == "Ｐ")
		{
			std::cout << "入力成功！\n";

			break;
		}
		else
		{
			std::cout << "入力失敗...\n";
		}
	}

	// じゃんけん列挙型
	enum class RockPaperScissors
	{
		// グー
		Rock,
		// パー
		Paper,
		// チョキ
		Scissors,
	};


	// じゃんけん
	enum class Judgement
	{
		// 勝ち
		Win,
		// 負け
		Lose,
		// 引き分け
		Draw,
	};



	// プレイヤーの手
	RockPaperScissors playerHand = RockPaperScissors::Paper;



	// 自分の手を決める
	if (str == "g" || str == "G" || str == "ｇ" || str == "Ｇ")
	{
		playerHand = RockPaperScissors::Rock;
	}
	else if (str == "c" || str == "C" || str == "ｃ" || str == "Ｃ")
	{
		playerHand = RockPaperScissors::Scissors;
	}
	else
	{
		playerHand = RockPaperScissors::Paper;
	}


	// 相手の手を決める
	const RockPaperScissors enemyHand = static_cast<RockPaperScissors>(rand() % 3);


	// 勝敗判定
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
		std::cout << "あんたの勝ちやで！！！\n";
		break;
	case Judgement::Lose:
		std::cout << "お前の負けｗｗｗｗｗ\n" << "なんで負けたか考えといてくださいｗｗｗｗｗ\n";
		break;
	case Judgement::Draw:
		std::cout << "引き分けっすね...しょうもな\n";
		break;
	default:
		break;
	}

}
void VendingMachine()
{

	std::cout << "自販機\n"
		<< "コカ・コーラ:180円, ポカリスエット:140円, いろはす:110円\n\n";


	// ドリンク
	int cola = 0;	// コーラ
	int pocari = 0;	// ポカリ
	int irohasu = 0;// いろはす

	// 入力受付
	std::cout << "コカ・コーラ個数：";
	std::cin >> cola;

	// 入力受付
	std::cout << "\nポカリスエット個数：";
	std::cin >> pocari;

	// 入力受付
	std::cout << "\nいろはす個数：";
	std::cin >> irohasu;



	// 合計金額
	int total = (cola * 180) + (pocari * 140) + (irohasu * 110);

	// 各飲料の値段を描画
	std::cout << "\nコカ・コーラ：" << cola * 180 << "円";
	std::cout << "\nポカリスエット：" << pocari * 140 << "円";
	std::cout << "\nいろはす：" << irohasu * 110 << "円";
	std::cout << "\n\n合計：" << total << "円\n\n";



	// 一万円札の枚数を求める
	const int tenThousandYenBills = total / 10000;
	total -= tenThousandYenBills * 10000;

	// 五千円札の枚数を求める
	const int fiveThousandYenBill = total / 5000;
	total -= fiveThousandYenBill * 5000;

	// 千円札の枚数を求める
	const int thousandYenBill = total / 1000;
	total -= thousandYenBill * 1000;




	// 五百円玉の枚数を求める
	const int fiveHundredYen = total / 500;
	total -= fiveHundredYen * 500;

	// 百円玉の枚数を求める
	const int hundredYen = total / 100;
	total -= hundredYen * 100;

	// 五十円玉の枚数を求める
	const int fifteYen = total / 50;
	total -= fifteYen * 50;

	// 十円玉の枚数を求める
	const int tenYen = total / 10;
	total -= tenYen * 10;


	// お札の枚数を求める
	const int bill = tenThousandYenBills + fiveThousandYenBill + thousandYenBill;

	// 小銭の枚数を求める
	const int coin = fiveHundredYen + hundredYen + fifteYen + tenYen;

	// お札と小銭の枚数を描画
	std::cout << "お札:" << bill << "枚  ";
	std::cout << "小銭:" << coin << "枚  ";

}

void CreateTriangle()
{

	int num = 0;
	int oneSideLength = 0;


	// 本数取得
	std::cout << "三角形を生成する際、何本の棒を使用するか:";
	std::cin >> num;

	// 長さ取得
	std::cout << "一本の棒の長さ:";
	std::cin >> oneSideLength;


	// 三角形生成数
	const int createTriangleNum = num / 3;

	// 三角形の周の長さ
	const int triangleRoundLength = oneSideLength * 3;

	std::cout << "\n三角形生成数:" << createTriangleNum << "個\n";
	std::cout << "三角形の周の長さ:" << triangleRoundLength << "\n";
}