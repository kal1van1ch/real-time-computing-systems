//После ./pr5_p3 необходимо указать число элементов массива
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])  {

    if (argc < 2){
	printf("No arguments\n");
	return -1;
    }

    int n = atoi(*(argv + 1));
    int *pArr = malloc(n * sizeof(int));

    if (pArr == NULL){
	printf("No memory in main()\n");
	return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("pArr[%d] = %p\n", i, (pArr + i));
    }

    free(pArr);
    pArr = NULL;

    return 0;
}
