#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mondai(int mondaisu) {

	int n, count;
	double a, b, player;

	srand(time(NULL));

	for (n = 0; n < mondaisu; n++) {

		a = rand()%49+1;
		b = rand()%49+1;

		a /= 10;
		b /= 10;

		printf("%.1lf+%.1lf=", a, b);
		scanf("%3lf", &player);
		while(getchar() != '\n') {  }

		if(fabs( (a + b) - player) < 0.00000000000001 ) count++;
	}

	return count;
}

