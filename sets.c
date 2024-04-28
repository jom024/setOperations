#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setops.h"

void main(){
    Set A = NULL;
    Set B = NULL;
    Set C = NULL;


    int setA[] = {2, 1, 3};
    int setB[] = {1, 4, 2, 6, 3};

    populate(&A, setA, sizeof(setA)/sizeof(int));
    populate(&B, setB, sizeof(setB)/sizeof(int));

    C = intersectionSet(A, B);

    display(A, B, C);

    //sort(&A);
    //sort(&B);
    //C = unionSorted(A, B);
    
    printf("\n\n");

    C = unionSet(A, B);

    display(A, B, C);
}