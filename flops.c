#include <stdio.h>
#include <sys/time.h> // to use gettimeofday :15,17
#include "mondai.c" // to use mondai() :16

int main(void) {

	int count = 0, rensyu; // countは正解数、rensyuは練習するかのフラグ。
	struct timeval start, end; // to use gettimeofday()

	printf("スパコンと計算能力比べ!!!\n");

	for (;;) {
		printf("練習をするためには１、測定をするためには２を入力してください。＞");
		scanf("%1d", &rensyu);
		while(getchar() != '\n') { }
		if(rensyu == 1) {
			printf("練習は４問です。\n");
			printf("練習を開始するためにはエンターキーを押してください。＞");
			rewind(stdin);
			getchar();
			mondai(4);
			printf("これで練習は終了です。\n");
		}
		else if(rensyu == 2) break;
		else printf("もう一度入力してください。\n");
	}

	printf("測定は１０問です。\n");
	printf("測定を開始するためにはエンターキーを押してください。＞");
	rewind(stdin);
	getchar();

	gettimeofday(&start, NULL); // 始めた時間取得
	count = mondai(10); // in mondai.c １０問の問題作成。
	gettimeofday(&end, NULL); // 終わった時間取得

	printf("これで測定は終了です。\n");
	printf("正解数　%d問！！\n", count);
	printf("時間　%.15lf秒\n", ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)); // countで正解数表示。時間は秒単位でもマイクロ秒単位でもそれぞれ終わった時間から始めた時間を引いて,それぞれを足す。マイクロ秒の方の*1.0E-6は意味不明。
	printf("あなたのFLOPS　%.15lfFLOPS！！\n", ((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)); // １秒あたりの正解数　＝　FLOPS
	if (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6) != 0) {
		printf("東北大のスーパーコンピューターの1/%ld\n", (long)(707000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)))); // 東北大のスパコンとの比較
		printf("京の1/%ld\n", (long)(10000000000000000 / (((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6)))); // 京との比較
	} else printf("あなたのFLOPSが０のため、スーパーコンピューターと比較できません。\n");

	return 0;
}

