#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int main(void) {

	int n, count = 0;
	double a, b, answer[10], player[10], flops;
	struct timeval start, end;

	srand(time(NULL));

	printf("スパコンと計算能力比べ!!!\n");

	gettimeofday(&start, NULL);


	for(n = 0 ;n < 10 ;n++ ) {

		a = rand()%49+1;
		b = rand()%49+1;

		a /= 10.0;
		b /= 10.0;

		answer[n] = a + b;
		printf("%.1lf+%.1lf=" ,a, b);

		scanf("%3lf", &player[n]);
		while(getchar() != '\n') { }

		if(fabs( answer[n] - player[n]) < 0.00000000000001 ) count++;

	}

	gettimeofday(&end, NULL);

	printf("正解数　%d問！！\n時間　%.15lf秒\nあなたのflops　%.15lfFLOPS！！\n", 
		count,((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6),
		((double)count) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6));

	return 0;
}

