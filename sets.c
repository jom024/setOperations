#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setops.h"

void main(){
    Set A = NULL;
    Set B = NULL;
    Set C = NULL;

    int setA[] = {0, 1, 8, 7};
    int setB[] = {1, 2};

    populate(&A, setA, sizeof(setA)/sizeof(int));
    populate(&B, setB, sizeof(setB)/sizeof(int));

    sort(&A);

    C = unionSorted(A, B);

    display(A, B, C);
}