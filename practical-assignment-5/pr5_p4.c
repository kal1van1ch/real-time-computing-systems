//После ./pr5_p4 необходимо ввести числов строк и столбцов (одно число) будущего массива
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])  {

    if (argc < 2){
	printf("No arguments\n");
	return -1;
    }

    int n = atoi(*(argv+ 1));

    int **pParr = malloc(n * sizeof(int *));

    if (pParr == NULL){
	printf("No memory in main()\n");
	return -1;
    }

    for (int i = 0; i < n; i++) {
        *(pParr + i) = malloc(n * sizeof(int));
	
	if (*(pParr + i) == NULL){
	    printf("No memory in main() in pParr\n");

	    for (int j = 0; j < i; j++){
		free(*(pParr + j));
		*(pParr + j) = NULL;
	    }
	    free(pParr);
	    pParr = NULL;
	    
	    return -1;
	}
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("pParr[%d][%d] = %p\n", i, j, (void *)(*(pParr + i) + j));
        }
	printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(*(pParr + i));
	*(pParr + i) = NULL;
    }
    free(pParr);
    pParr = NULL;

    return 0;
}
