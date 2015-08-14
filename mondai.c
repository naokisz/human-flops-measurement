#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* int mondai

引数　int型　問題数
返り値　int型　回答数

小数第一位の数を乱数で作って、問題を出し、正解数を数える。

*/

int mondai(int mondaisu) { // 問題数を引数として持つ。

	int n, count; // nはforのカウント、countは正解数。
	double a, b, player; // a、bは問題。playerは入力されたもの。

	srand(time(NULL)); // 乱数の種まき　mainでやるべきだろうけれど面倒だからここに書いた。

	for (n = 0; n < mondaisu; n++) { // mondaisuの分だけ問題作成

		a = rand()%49+1; // 乱数を作る。答えを１０や０にしたくないから０．１〜４．９までの乱数に制限。
		b = rand()%49+1;

		a /= 10; // 小数にするため１０で割る
		b /= 10;

		printf("%.1lf+%.1lf=", a, b); // 問題表示
		scanf("%3lf", &player); // プレイヤー答え入力
		while(getchar() != '\n') {  } // 余計な値捨て

		if(fabs( (a + b) - player) < 0.00000000000001 ) count++; // 答えとプレイヤーの入力が丸め込み誤差の１０倍より小さかったら正解とする。本当はa+b = playerとしたかった。
	}

	return count; // 正解数を返り値として返す。
}

