#include <stdio.h>
#include <time.h>

unsigned long long fibonacci(int n) {
	if(n<=1) {
		return n;
	}

	return fibonacci(n-1) + fibonacci(n-2);
}

unsigned long long fibonacciBetter(int n, unsigned long long *fiboArray) {
	if( n <= 1) {
		return n;
	}
	if(fiboArray[n] != -1) {
		return fiboArray[n];
	}
	fiboArray[n] = fibonacciBetter(n-1, fiboArray) + fibonacciBetter(n-2, fiboArray);
	return fiboArray[n];
}

void main() {
	unsigned long long tableau[101];

	for(int i = 0; i<101; i++) {
		tableau[i] = -1;
	}
	clock_t begin2 = clock();
	printf("résultat de la suite de fibonacci : %lli \n", fibonacciBetter(100, tableau));
	clock_t end2 = clock();

	unsigned long millis2 = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("Finished 2 in %ld ms\n", millis2);
}
