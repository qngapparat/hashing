#include <stdio.h>
#include <stdlib.h>

const int CHAR_BIT = 8;

int hash(char string[], int string_length){
    int h = 0;
    for(int i = 0; i < string_length; i++){
        h = (h << 5) | (h >> (sizeof(h)*CHAR_BIT - 5));
        h += (int)string[i];
    }

    return h;
}



int main(int argc, char const *argv[]) {

    char str1[] = "memelolnicehaha";
    char str2[] = "boat";
    char str3[] = "boat";


    int int1 = hash(str1, (int) sizeof(str1) / sizeof(char));
    int int2 = hash(str2, (int) sizeof(str2) / sizeof(char));
    int int3 = hash(str3, (int) sizeof(str3) / sizeof(char));

    printf("%s: %d\n%s: %d\n%s: %d\n", str1, int1, str2, int2, str3, int3);



    return EXIT_SUCCESS;
}
