//Вариант 6
//После ./ ввести через пробел числа для массива
#include <stdio.h>
#include <stdlib.h>


char *function(int *arr, int len);


int main(int argc, char *argv[])  {

    if (argc < 2) {
        printf("No arguments\n");
        return -1;
    }

    int n = argc - 1;

    int *pArr = malloc(n * sizeof(int));

    if (pArr == NULL) {
        printf("No memory in main()\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        *(pArr + i) = atoi(*(argv + i + 1));
    }

    char *answer = function(pArr, n);

    if (answer == NULL) {
        printf("No answer\n");
        free(pArr);
	pArr = NULL;
        return -1;
    }

    printf("%s\n", answer);

    free(pArr);
    free(answer);

    pArr = NULL;
    answer = NULL;

    return 0;
}

char *function(int *arr, int len) {
    int zeroCount = 0;
    int multiple = 1;

    for (int i = 0; i < len; i++) {
        if (*(arr + i) == 0) zeroCount++;
        else multiple *= *(arr + i);
    }

    int space = 100;
    char *answer = malloc(space);

    if (answer == NULL) {
        printf("No memory in function()\n");
        return NULL;
    }

    snprintf(
        answer,
        space,
        "Zeros count = %d, Multiplication not null = %d\n",
        zeroCount,
        multiple
    );

    return answer;
}
