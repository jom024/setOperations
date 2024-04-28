#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setops.h"

void main(){
    Set A = NULL;
    Set B = NULL;
    Set unionC = NULL;
    Set intersectC = NULL;


    int setA[] = {2, 1, 3};
    int setB[] = {1, 4, 2, 6, 3};

    populate(&A, setA, sizeof(setA)/sizeof(int));
    populate(&B, setB, sizeof(setB)/sizeof(int));

    //sort(&A);
    //sort(&B);
    //unionC = unionSorted(A, B);

    //unionC = unionSet(A, B);

    //display(A, B, unionC); 

    intersectC = intersectionSet(A, B);

    display(A, B, intersectC);
}