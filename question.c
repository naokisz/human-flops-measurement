#include <stdio.h>
#include <stdlib.h>
#include <math.h> // to use fabs

/* int question

引数　int型　問題数
返り値　int型　回答数

答えが0や10にならないように、整数部分は一の位、
小数部分は小数第一位までの数(0.1~4.9)を乱数で作って、問題を出し、正解数を数える。

*/

int question(int numof_question) { 

	int i_question, numof_correct_answers = 0; 
	double computer_add1, computer_add2, player_input = 0; 

	/* 乱数の種まき　mainでやるべきだろうけれど面倒だからここに書いた。*/
	srand(time(NULL)); 

	/* numof_questionの分だけ問題作成*/
	for (i_question = 0; i_question < numof_question; i_question++) { 

		/*答えを１０や０にしたくないから1から４９までの乱数に制限。*/
		computer_add1 = rand()%49+1;
		computer_add2 = rand()%49+1;

		computer_add1 /= 10; 
		computer_add2 /= 10;

		printf("%.1lf+%.1lf=", computer_add1, computer_add2); 
		scanf("%3lf", &player_input); 
		while(getchar() != '\n') {  } // 余計な値捨て

		/* 答えとプレイヤーの入力が丸め込み誤差の１０倍より小さかったら正解とする。
			本当はa+b = player_inputとしたかった。*/
		if(fabs( (computer_add1 + computer_add2) - player_input) < 0.00000000000001 )
			numof_correct_answers++; 
	}

	return numof_correct_answers; 
}