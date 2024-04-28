#ifndef SETOPS_H_INCLUDED
#define SETOPS_H_INCLUDED

typedef struct cell{
    int elem;
    struct cell* link;
}*Set;

void insertLast(Set*S, int newElem){
    Set temp = (Set)malloc(sizeof(struct cell));
    temp->elem = newElem;
    temp->link = NULL;

    Set *trav;
    for(trav = S; *trav!=NULL; trav = &(*trav)->link){}

    *trav = temp;
}

void sort(Set*S){
    int min, temp;
    Set *trav, *trav2;

    for(trav = S; *trav != NULL; trav = &(*trav)->link){
        int min = (*trav)->elem;
        for(trav2 = &(*trav)->link; *trav2 != NULL; trav2 = &(*trav2)->link){
            min = ((*trav2)->elem < min) ? (*trav2)->elem : min ;
        } 

        if(min != (*trav)->elem){
            for(trav2 = &(*trav)->link; *trav2 != NULL && (*trav2)->elem != min; trav2 = &(*trav2)->link);

            temp = (*trav)->elem;
            (*trav)->elem = min;
            (*trav2)->elem = temp;
        }
    }
}

Set unionSorted(Set A, Set B){
    Set C = NULL;
    
    while(A!=NULL && B !=NULL){
        if(A->elem < B -> elem){
            insertLast(&C, A->elem);
            A = A->link;
        } else if (A->elem == B->elem){
            insertLast(&C, A->elem);
            A = A->link;
            B = B->link;
        } else {
            insertLast(&C, B->elem);
            B = B->link;
        }
    }

    while((A!=NULL && B==NULL) || (A==NULL && B !=NULL)){
        if(A!=NULL){
            insertLast(&C, A->elem);
            A = A->link;
        } 

        if(B!=NULL){
            insertLast(&C, B->elem);
            B = B->link;
        }
    }

    return C;
}

Set unionSet(Set A, Set B){
    Set C = NULL;
    Set *trav;

    while(A!=NULL){
        insertLast(&C, A->elem);
        A = A->link;
    }

    while(B!=NULL){
        for(trav = &C; *trav != NULL && B->elem != (*trav)->elem; trav = &(*trav)->link);      //checks if element exists in C
        if(*trav == NULL){ 
            insertLast(&C, B->elem);    //only inserts element if it does not exist in C just yet
        }
        B = B->link;
    }

    return C;
}

Set intersectionSet(Set A, Set B){
    Set *trav, C = NULL;
    while(A!=NULL){
        for(trav = &B; *trav!=NULL && A->elem != (*trav)->elem; trav = &(*trav)->link);   //checks if A element exists in B element
        if(*trav!=NULL){
            insertLast(&C, A->elem);
        }
        A = A->link;
    }

    return C;
}

void populate(Set* S, int* elements, int size){
    int i = 0;
    while(i < size){
        insertLast(S, elements[i++]);
    }
}

void display(Set A, Set B, Set C){
    
    Set trav;
    
    if(A!=NULL){
        printf("\nSet A = ");
        for(trav = A; trav!=NULL; trav=trav->link){
            printf("%d ", trav->elem);
        }
    }
    
    if(B!=NULL){
        printf("\nSet B = ");
        for(trav = B; trav!=NULL; trav=trav->link){
            printf("%d ", trav->elem);
        }
    }
    
    if(C!=NULL){
        printf("\nSet C = ");
        for(trav = C; trav!=NULL; trav=trav->link){
            printf("%d ", trav->elem);
        }
    }
}

#endif