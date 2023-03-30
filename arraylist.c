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
  if(l->size==l->capacity){
    l->capacity=l->capacity*2;
    l->data=realloc(l->data,sizeof(void)*l->capacity);
  }
  l->data[l->size]=data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;
  if(l->size==l->capacity){
    l->capacity=l->capacity*2;
    l->data=realloc(l->data,sizeof(void)*l->capacity);    
  }
  for(int j=l->size; j>=i; j--){
    l->data[j]=l->data[j-1];
  }
  l->data[i]=data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  void *dato=l->data[i];
  for(int j=i;j< l->size ; j++){
    l->data[j+1]=l->data[j];
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
    
}
