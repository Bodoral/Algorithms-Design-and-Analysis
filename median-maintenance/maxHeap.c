#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

//#define LCHILD(x) 2 * x + 1
//#define RCHILD(x) 2 * x + 2
//#define PARENT(x) (x - 1) / 2
//
//
//typedef struct node {
//    int data ;
//} node ;
//
//typedef struct maxHeap {
//    int size ;
//    node *elem ;
//} maxHeap ;


/*
 
 Max-Heap functions
 
 */

void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}


maxHeap initMaxHeap(int size) {
    maxHeap hp ;
    hp.size = 5003 ;
    hp.elem = malloc(size * sizeof(node)) ;
    return hp ;
}


void heapifyM(maxHeap *hp, int i) {
    int largest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].data > hp->elem[i].data) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].data > hp->elem[largest].data) {
        largest = RCHILD(i) ;
    }
    if(largest != i) {
        swap(&(hp->elem[i]), &(hp->elem[largest])) ;
        heapifyM(hp, largest) ;
    }
}



void buildMaxHeap(maxHeap *hp, int *arr, int size) {
    int i ;
    
    // Insertion into the heap without violating the shape property
    for(i = 0; i < size; i++) {
        if(hp->size) {
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
        } else {
            hp->elem = malloc(sizeof(node)) ;
        }
        node nd ;
        nd.data = arr[i] ;
        hp->elem[(hp->size)++] = nd ;
    }
    
    // Making sure that heap property is also satisfied
    for(i = (hp->size - 1) / 2; i >= 0; i--) {
        heapifyM(hp, i) ;
    }
}



void insertNodeM(maxHeap *hp, int data) {
    node nd ;
    nd.data = data ;
    
    int i = (hp->size)++ ;
    while(i && nd.data > hp->elem[PARENT(i)].data) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}



void deleteNodeM(maxHeap *hp) {
    if(hp->size) {
        printf("Deleting node %d\n\n", hp->elem[0].data) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        heapifyM(hp, 0) ;
    } else {
        printf("\nMax Heap is empty!\n") ;
        free(hp->elem) ;
    }
}

int getMinNode(maxHeap *hp, int i) {
    if(LCHILD(i) >= hp->size) {
        return hp->elem[i].data ;
    }
    
    int l = getMinNode(hp, LCHILD(i)) ;
    int r = getMinNode(hp, RCHILD(i)) ;
    
    if(l <= r) {
        return l ;
    } else {
        return r ;
    }
}

void deleteMaxHeap(maxHeap *hp) {
    free(hp->elem) ;
}
