#include <stdio.h>
#include <time.h>
#include <stdbool.h>

unsigned long long nbPremier(unsigned long long n) {
    unsigned long long np = 0;

    for(int i = 2; i<n; i++) {
        int numberOfDivFori = 0;
        for (int j = 2; j*j <=i; j++) {
            if(i%j == 0) {
                numberOfDivFori++;
            }
        }

        if(numberOfDivFori == 0) {
            printf("%i est premier \n", i);
            np++;
        }
    }

    return np;
}

unsigned long long nbPremier_siev(unsigned long long n) {
    bool premier[n + 1];
    for (int i = 0; i <= n; i++) {
        premier[i] = true;
    }

    premier[0] = false;
    premier[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (premier[i]) {
            for (int j = i * i; j <= n; j += i) {
                premier[j] = false;
            }
        }
    }
    
    unsigned long long np = 0;

    for (int i = 2; i <= n; i++) {
        if (premier[i]) {
            np++;
        }
    }

    return np;
}

void main() {
	clock_t begin2 = clock();
	printf("nombre de nombres premiers : %lli \n", nbPremier(50));
	clock_t end2 = clock();

    unsigned long millis2 = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("Finished 2 in %ld ms\n", millis2);

    clock_t begin = clock();
	printf("nombre de nombres premiers : %lli \n", nbPremier_siev(50));
	clock_t end = clock();

    unsigned long millis = (end - begin) * 1000 / CLOCKS_PER_SEC;
	printf("Finished 2 in %ld ms\n", millis);
}
