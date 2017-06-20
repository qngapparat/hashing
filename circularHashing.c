#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int TABLE_SIZE = 5;
const int CHAR_BIT = 8;


int hash(char string[], int string_length){
    int h = 0;
    for(int i = 0; i < string_length; i++){
        h = (h << 5) | (h >> (sizeof(h)*CHAR_BIT - 5));
        h += (int)string[i];
    }

    return h;
}

//input: int hash and desired table size
//output: index of hash in compressed hashtable
int compress(int hash, int N){

    //lazy approach to generate prime. Not optimal in some cases collision-wise
    int prime = (int) pow((double) 2, (double) 11) + 1;

    //scale and shift for scale*k + shift
    int scale = rand()%7;
    int shift = rand()%9;

    //formula for c(h(k)). scale, shift, prime randomly chosen.
    return (((scale*hash + shift) % prime) % N);
}


int main(int argc, char const *argv[]) {

    srand(time(NULL));


    char str1[] = "Boot";
    char str2[] = "Boat";
    char str3[] = "Tom";
    char str4[] = "Neurology";


    int int1 = hash(str1, (int) sizeof(str1) / sizeof(char));
    int int2 = hash(str2, (int) sizeof(str2) / sizeof(char));
    int int3 = hash(str3, (int) sizeof(str3) / sizeof(char));
    int int4 = hash(str4, (int) sizeof(str4) / sizeof(char));

    printf("%s: %d\n%s: %d\n%s: %d\n%s: %d\n", str1, int1, str2, int2, str3, int3, str4, int4);

    int comp1 = compress(int1, TABLE_SIZE);
    int comp2 = compress(int2, TABLE_SIZE);
    int comp3 = compress(int3, TABLE_SIZE);
    int comp4 = compress(int4, TABLE_SIZE);

    printf("compressed table with (((ak+b)mod p) mod N) : \n%d\n%d\n%d\n%d\n", comp1, comp2, comp3, comp4);

    return EXIT_SUCCESS;
}
