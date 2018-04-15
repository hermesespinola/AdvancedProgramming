#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define HASH_DEBUG "HASH_DEBUG"

void printDebug(char *msg) {
  char *hashDebug = getenv(HASH_DEBUG);
  if (hashDebug != NULL && strcmp(hashDebug, "y") == 0) {
    printf("%s\n", msg);
  }
}

int doHash(int x, unsigned size) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % size;
}

void hashInit(HashInt *hash, unsigned size) {
  hash->size = size;
  hash->data = (HashElement *)calloc(size, sizeof(HashElement));
};

static void hashDoInsert(HashInt *hash, int key, int value) {
  printDebug("dohash");
  unsigned index = doHash(key, hash->size);
  printDebug("dohash2");
  HashElement *currentHashElement = &(hash->data[index]);
  if (currentHashElement->elements == NULL) {
    printDebug("CHECKING DATA");
    currentHashElement->elements = (Element *)malloc(2 * sizeof(Element));
    currentHashElement->count = 0;
    currentHashElement->length = 2;
  }

  if (currentHashElement->length == currentHashElement->count) {
    currentHashElement->length *= 2;
    currentHashElement->elements = (Element *)realloc(currentHashElement->elements,
                                    currentHashElement->length * sizeof(Element));
  }
  printDebug("Assigning");
  currentHashElement->elements[currentHashElement->count].key = key;
  currentHashElement->elements[currentHashElement->count].value = value;
  currentHashElement->count += 1;
  printDebug("Completed");
}

static void hashDoUpdate(HashInt *hash, int key, int value) {
 int pos = doHash(key, hash->size);
 int i;

 Element *currentElements = hash->data[pos].elements;
 int currentElementsLength = hash->data[pos].count;
 for (i = 0; i < currentElementsLength; i++) {
   if (key == currentElements[i].key) {
     currentElements[i].value = value;
     break;
   }
  }
}

void hashInsert(HashInt *hash, int key, int value) {
  int *oldValue = hashGet(hash, key);
  if (oldValue == NULL) {
    hashDoInsert(hash, key, value);
  } else {
    hashDoUpdate(hash,key,value);
  }
}

int *hashGet(HashInt *hash, int key) {
  int pos = doHash(key, hash->size);
  int i;

  Element *currentElements = hash->data[pos].elements;
  int currentElementsLength = hash->data[pos].count;
  int *value = NULL;

  for (i = 0; i < currentElementsLength; i++) {
    if (key == currentElements[i].key) {
      value = (int *)malloc(sizeof(int));
      *value = currentElements[i].value;
      break;
    }
  }
  return value;
}

void printHash(HashInt *hash) {
  for (int i = 0; i < hash->size; i++) {
    Element *currentElements = hash->data[i].elements;
    int currentElementsLength = hash->data[i].count;

    for (int j = 0; j < currentElementsLength; j++) {
      printf("%d -> %d\n", currentElements[j].key, currentElements[j].value);
    }
  }
};
