#include <stdio.h>
#include <string.h>



int main(){
    

    char str5[15] = "Hello, world!";
    char str6[15] = "H[llo, world!";
    int result2 = memcmp(str5, str6, 5);
    printf("memcmp result:  %d\n", result2);


    return 0;
}