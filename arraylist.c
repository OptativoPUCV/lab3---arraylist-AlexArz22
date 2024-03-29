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
  lista->size=0;
  lista->data=malloc(lista->capacity * sizeof(void*));
  return lista;
}

void append(ArrayList * l, void * data){
  if(l->size==l->capacity){
    l->capacity=l->capacity*2;
    l->data=(void *)realloc(l->data,sizeof(void*)*l->capacity);
    if(l->data==NULL) return exit(EXIT_FAILURE);
  }
  l->data[l->size]=data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;
  if(l->size==l->capacity){
    l->capacity=l->capacity*2;
    l->data=(void *) realloc(l->data,sizeof(void*)*l->capacity);
    if(l->data==NULL) return exit(EXIT_FAILURE);
  }
  for(int j=l->size; j>i; j--){
    l->data[j]=l->data[j-1];
  }
  l->data[i]=data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if(l->size==0) return NULL;
  if(i<0){
    i=l->size+i;
  }
  void *dato=l->data[i];
  for(int j=i; j < l->size-1 ; j++){
    l->data[j]=l->data[j+1];
  }
  l->size--;
  return dato;
}

void* get(ArrayList * l, int i){
  if(i>=l->size) return NULL;  
  if(i<0){
    i=l->size+i;
  }
  void *dato=l->data[i];
  return dato;
}

int get_size(ArrayList * l){
  return l->size;
}

//remove elements
void clean(ArrayList * l){
  for(int i=0; i<l->size; i++){
    free(l->data[i]);
  }
  free(l);
  l=createList();
  /*l->size=0;
  l->capacity=2;
  l->data=malloc(l->capacity*sizeof(void));*/
}
