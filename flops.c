#include <stdio.h>
#include <sys/time.h> // to use gettimeofday :16,37
#include "mondai.c"

int main(void) {

	int count = 0; // nはforのカウント、countは正解数
	struct timeval start, end;

	printf("スパコンと計算能力比べ!!!\n");
	printf("測定を開始するためにはエンターキーを押してください。＞");
	rewind(stdin);
	getchar();

	gettimeofday(&start, NULL); // 始めた時間取得
	count = mondai(10);
	gettimeofday(&end, NULL); // 終わった時間取得

	printf("正解数　%d問！！\n時間　%.15lf秒\nあなたのflops　%.15lfFLOPS！！\n東北大のスパコンの1/%ld\n京の1/%ld\n", 
		count,((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6), // countで正解数表示。時間は秒単位でもマイクロ秒単位でもそれぞれ終わった時間から始めた時間を引いて,それぞれを足す。マイクロ秒の方の*1.0E-6は意味不明。
		((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6), // １秒あたりの正解数　＝　FLOPS
		(long)(707000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6))), // 東北大のスパコンとの比較
		(long)(10000000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)))); // 京との比較

	return 0;
}

