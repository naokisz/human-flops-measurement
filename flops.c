#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // to use gettimeofday :16,37
#include <math.h> // to use fabs :33

int main(void) {

	int n, count = 0; // nはforのカウント、countは正解数
	double a, b, player[10]; // a,bは問題、playerは入力されたもの
	struct timeval start, end;

	srand(time(NULL)); // 乱数の種まき

	printf("スパコンと計算能力比べ!!!\n");

	printf("測定を開始するためにはエンターキーを押してください。＞");
	rewind(stdin);
	getchar();

	gettimeofday(&start, NULL); // 始めた時間取得


	for(n = 0 ;n < 10 ;n++ ) { // １０問作成

		a = rand()%49+1; // 乱数を作る。答えを１０や０にしたくないから0.1~4.9までの乱数に制限
		b = rand()%49+1;

		a /= 10.0; // 小数にするため１０で割る
		b /= 10.0;

		printf("%.1lf+%.1lf=" ,a, b); // 問題表示

		scanf("%3lf", &player[n]); // プレイヤー答え入力
		while(getchar() != '\n') { } // 余計な値捨て

		if(fabs( (a + b) - player[n]) < 0.00000000000001 ) count++; // 答えとプレイヤーの入力が丸め込み誤差の１０倍より小さかったら正解とする。本当はa+b = player[n]としたかった。

	}

	gettimeofday(&end, NULL); // 終わった時間取得

	printf("正解数　%d問！！\n時間　%.15lf秒\nあなたのflops　%.15lfFLOPS！！\n東北大のスパコンの1/%ld\n京の1/%ld倍\n", 
		count,((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6), // countで正解数表示。時間は秒単位でもマイクロ秒単位でもそれぞれ終わった時間から始めた時間を引いて,それぞれを足す。マイクロ秒の方の*1.0E-6は意味不明。
		((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6), // １秒あたりの正解数　＝　FLOPS
		(long)(707000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6))), // 東北大のスパコンとの比較
		(long)(10000000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)))); // 京との比較
	return 0;
}

