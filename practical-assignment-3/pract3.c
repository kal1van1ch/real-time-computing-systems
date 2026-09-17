#include <stdio.h>
#include <unistd.h>

int main(){
    int practNum = 3;
    
    printf("Hello from pract%d\n", practNum);
    
    int fNum =     9;
    int sNum =    11;
    int result =  20;
    
    printf(
        "Result of %d + %d is %d\n", 
        fNum, 
        sNum, 
        result
    );
    
    return 0;
}

