#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *lista;
  lista=malloc(sizeof(ArrayList));
  lista->capacity=2;
  lista->data=malloc(lista->capacity * sizeof(void));
  return lista;
}

void append(ArrayList * l, void * data){
  if(l->data[l->size]==l->data[l->capacity]){
    l->capacity=l->capacity*2;
    l->data=realloc(l->data,sizeof(void)*l->capacity);
  }
  l->data[l->size]=data;
  //l->size++;
  

}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
