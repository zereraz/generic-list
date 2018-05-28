#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fati_b {
  void *val;
  char* format;
};

struct Fati {
  struct Fati_b **list;
  int len;
};

struct Fati_b* createItem(void *val, char* format) {
  struct Fati_b* fati_b;
  fati_b = malloc(sizeof(*fati_b));
  fati_b->val = val;
  fati_b->format = format;
  return fati_b;
}

struct Fati* createGenericList() {
  struct Fati *fati;
  fati = malloc(sizeof(fati));

  fati->len = 0;
  fati->list = malloc(sizeof(struct Fati_b*));
  return fati;
}

char* concat(char* str1, char* str2) {
  char* finalStr = malloc(strlen(str1) + strlen(str2) + 1);
  strcpy(finalStr, str1);
  strcat(finalStr, str2);
  return finalStr;
}

void insertToList(struct Fati *genericList, struct Fati_b* item) {
  genericList->list[genericList->len] = item;
  genericList->len++;
  genericList->list = realloc(genericList->list, genericList->len * 1.5 * sizeof(struct Fati_b*));
}

void displayList(struct Fati *genericList) {
  for(int i = 0; i < genericList->len; i++) {
    char* c = concat("\nval : ", genericList->list[i]->format);
    printf(c, genericList->list[i]->val);
  }
}

int main() {
  struct Fati* genericList = createGenericList();
  insertToList(genericList, createItem("testing", "%s"));
  insertToList(genericList, createItem("def",  "%s"));
  insertToList(genericList, createItem(1024, "%d"));

  displayList(genericList);


  return 0;
}
