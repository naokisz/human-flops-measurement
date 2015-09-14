#include <stdio.h>
#include <sys/time.h> // to use gettimeofday :33,35
#include "question.c" // to use question() :34,21

int main(void) {

	int numof_correct_answers = 0, if_practice; // numof_correct_answersは正解数。
	struct timeval start_ms, end_ms; // to use gettimeofday()

	printf("スーパーコンピューターと計算能力比べ!!!\n");

	for (;;) {

		printf("練習をするためには１、測定をするためには２を入力してください。＞");
		scanf("%1d", &if_practice);
		while(getchar() != '\n') { } // 余計な値捨て

		if(if_practice == 1) { 
			printf("練習は４問です。\n");
			printf("練習を開始するためにはエンターキーを押してください。＞");
			rewind(stdin);
			getchar();

			question(4); // in question.c 4問問題作成

			printf("これで練習は終了です。\n");
		}
		else if(if_practice == 2) break; 

		else printf("もう一度入力してください。\n"); 
	}

	printf("測定は１０問です。\n");
	printf("測定を開始するためにはエンターキーを押してください。＞");
	rewind(stdin);
	getchar();

	gettimeofday(&start_ms, NULL); // 始めた時間取得
	numof_correct_answers = question(10); // in question.c １０問の問題作成。
	gettimeofday(&end_ms, NULL); // 終わった時間取得

	printf("これで測定は終了です。\n");

	printf("正解数　%d問！！\n", numof_correct_answers);

	/*時間は秒単位でもマイクロ秒単位でもそれぞれ終わった時間から始めた時間を引いて,それぞれを足す。マイクロ秒の方の*1.0E-6は意味不明。*/
	printf("時間　%.15lf秒！！\n", 
		((end_ms.tv_sec - start_ms.tv_sec) + (end_ms.tv_usec - start_ms.tv_usec)*1.0E-6)); 

	/*１秒あたりの正解数　＝　FLOPS*/
	printf("あなたのFLOPS　%.15lfFLOPS！！\n", 
		((double)numof_correct_answers) / ((end_ms.tv_sec - start_ms.tv_sec) + (end_ms.tv_usec - start_ms.tv_usec)*1.0E-6)); 

	/*0除算例外処理のため*/
	if (((double)numof_correct_answers) / ((end_ms.tv_sec - start_ms.tv_sec) + (end_ms.tv_usec - start_ms.tv_usec)*1.0E-6) != 0) {

		/*東北大のスパコンとの比較*/
		/*TODO:この辺りprintfの引数などが横に長く連なっているので修正したい。*/
		printf("東北大のスーパーコンピューターの1/%ld\n", 
			(long)(707000000000000 / (((double)numof_correct_answers) / ((end_ms.tv_sec - start_ms.tv_sec) + (end_ms.tv_usec - start_ms.tv_usec)*1.0E-6))));

		/* 京との比較*/
		printf("京の1/%ld\n", 
			(long)(10000000000000000 / (((double)numof_correct_answers) / ((end_ms.tv_sec - start_ms.tv_sec) + (end_ms.tv_usec - start_ms.tv_usec)*1.0E-6)))); 

	} else printf("あなたのFLOPSが0のため、スーパーコンピューターと比較できません。\n"); // 0除算の例外処理

	return 0;
}

