
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#include "a1_library.h"

#define MAXCHAR 128
#define ONECHAR 1
#define TWOCHAR 2
#define THREECHAR 3
#define FOURCHAR 4
#define SIXCHAR 6
#define TENCHAR  10
#define TWELVECHAR 12
#define READBUFFER 512
#define COMMA ','
/*#define QUOTE '"'*/

typedef struct {
  char id[TENCHAR + 1];
  char sex[ONECHAR + 1];
  char age[THREECHAR + 1];
  char height[THREECHAR + 1];
  char weight[THREECHAR + 1];
  char teamName[MAXCHAR + 1];
  char NOC[THREECHAR + 1];
  char games[TWELVECHAR + 1];
  char year[FOURCHAR + 1];
  char season[SIXCHAR + 1];
  char city[MAXCHAR + 1];
  char sport[MAXCHAR + 1];
  char event[MAXCHAR + 1];
  char medal[SIXCHAR + 1];
} data_t;

typedef struct node node_t;
struct node {
  char key[MAXCHAR + 1];
  data_t data;
  node_t *left;
  node_t *right;
};

typedef struct {
  node_t *root;
} dic_t;

void printInOrderTraversal(node_t *root);
dic_t *createEmptyDict();
dic_t *makeDict(dic_t *dictionary, char *filename);
node_t *populateNode(char record[READBUFFER], node_t *emptyNode);
node_t *recInsert(node_t *root, node_t *newNode);
//void recSearch(node_t *root, char *lookup);*/
//*****************************************************************************
int
main(int argc, char **argv) {
  dic_t *mydict;
  mydict = createEmptyDict();
    printf("%s", argv[1]);
    
    makeDict(mydict, argv[1]);
  //printInOrderTraversal(mydict->root);
  return 0;
}
//*****************************************************************************
dic_t *createEmptyDict() {
  dic_t *dictionary;
  dictionary = (dic_t *)malloc(sizeof(dic_t));
  assert(dictionary != NULL);
  dictionary->root = NULL;
  return dictionary;
}

node_t *createEmptyNode() {
  node_t *emptyNode;
  emptyNode = (node_t *)malloc(sizeof(node_t));
  assert(emptyNode != NULL);
  emptyNode->left = NULL;
  emptyNode->right = NULL;
  return emptyNode;
}

node_t *populateNode(char record[READBUFFER], node_t *newNode) {
  int i, lenItem, separatorCounter = 0, nelements = 0/*, quoteCounter = 0*/;
  int lenRecord = strlen(record);
  for(i = 0; i < lenRecord; i++) {
    /*if(record[i] == QUOTE) {
      //printf("Quotation mark when i = %d\n", i);
      quoteCounter++;
    }*/
    if(record[i] == COMMA /*&& (quoteCounter % 2) != 0*/) {
        printf("%d\n", i);
      nelements++;
      lenItem = i - separatorCounter;
      if(nelements == 1) {
        strncpy(newNode->data.id, record + separatorCounter, lenItem);
        newNode->data.id[lenItem] = '\0';
      } else if(nelements == 2) {
          strncpy(newNode->key, record + separatorCounter, lenItem);
          newNode->key[lenItem] = '\0';
      } else if(nelements == 3) {
          strncpy(newNode->data.sex, record + separatorCounter, lenItem);
          newNode->data.sex[lenItem] = '\0';
      } else if(nelements == 4) {
          strncpy(newNode->data.age, record + separatorCounter, lenItem);
          newNode->data.age[lenItem] = '\0';
      } else if(nelements == 5) {
          strncpy(newNode->data.height, record + separatorCounter, lenItem);
          newNode->data.height[lenItem] = '\0';
      } else if(nelements == 6) {
          strncpy(newNode->data.weight, record + separatorCounter, lenItem);
          newNode->data.weight[lenItem] = '\0';
      } else if(nelements == 7) {
          strncpy(newNode->data.teamName, record + separatorCounter, lenItem);
          newNode->data.teamName[lenItem] = '\0';
      } else if(nelements == 8) {
          strncpy(newNode->data.NOC, record + separatorCounter, lenItem);
          newNode->data.NOC[lenItem] = '\0';
      } else if(nelements == 9) {
          strncpy(newNode->data.games, record + separatorCounter, lenItem);
          newNode->data.games[lenItem] = '\0';
      } else if(nelements == 10) {
          strncpy(newNode->data.year, record + separatorCounter, lenItem);
          newNode->data.year[lenItem] = '\0';
      } else if(nelements == 11) {
          strncpy(newNode->data.season, record + separatorCounter, lenItem);
          newNode->data.season[lenItem] = '\0';
      } else if(nelements == 12) {
          strncpy(newNode->data.city, record + separatorCounter, lenItem);
          newNode->data.city[lenItem] = '\0';
      } else if(nelements == 13) {
          strncpy(newNode->data.sport, record + separatorCounter, lenItem);
          newNode->data.sport[lenItem] = '\0';
      } else if(nelements == 14) {
          strncpy(newNode->data.event, record + separatorCounter, lenItem);
          newNode->data.event[lenItem] = '\0';
      } else {
          break;
      }
      separatorCounter = i + 1;
      
      //printf("quote counter = %d\n", quoteCounter);
    }
  }
    lenItem = strlen(record) - separatorCounter;
    strncpy(newNode->data.medal, record + separatorCounter, lenItem);
    newNode->data.medal[lenItem] = '\0';
  printf("newNode->data.id: %s\n", newNode->data.id);
  printf("newNode->key: %s\n", newNode->key);
  printf("newNode->data.sex: %s\n", newNode->data.sex);
  printf("newNode->data.age: %s\n", newNode->data.age);
  printf("newNode->data.height: %s\n", newNode->data.height);
  printf("newNode->data.weight: %s\n", newNode->data.weight);
  printf("newNode->data.teamName: %s\n", newNode->data.teamName);
  printf("newNode->data.NOC: %s\n", newNode->data.NOC);
  printf("newNode->data.games: %s\n", newNode->data.games);
  printf("newNode->data.year: %s\n", newNode->data.year);
  printf("newNode->data.season: %s\n", newNode->data.season);
  printf("newNode->data.city: %s\n", newNode->data.city);
  printf("newNode->data.sport: %s\n", newNode->data.sport);
  printf("newNode->data.event: %s\n", newNode->data.event);
  printf("newNode->data.medal: %s", newNode->data.medal);
  return newNode;
}

/*MAKE A DICT BASED ON A CSV FILE*/
dic_t *makeDict(dic_t *dictionary, char *filename) {
  FILE *file = fopen(filename, "r");
  if (! file) {
    printf("Oops! file: --%s-- not found.\n", filename);
  } else {
    printf("File --%s-- opened.\n", filename);
  }
  char record[READBUFFER];
  fgets(record, READBUFFER, file); //read ALL the file
    
    printf("%s\n", record);
  node_t *newRecord;
  newRecord = createEmptyNode();
  populateNode(record, newRecord);
//  newRecord = recInsert(dictionary->root, newRecord);
//  printf("Key of the root: %s\n", dictionary->root->key);
  return dictionary;
}

node_t *recInsert(node_t *root, node_t *newNode) {
  if(root == NULL) {
    return newNode;
  }
  int compOutcome = strcmp(root->key, newNode->key);
  if(compOutcome <= 0) {
    root->left = recInsert(root->left, newNode);
  } else {
    root->right = recInsert(root->right, newNode);
  }
  return root;
}

/*void printInOrderTraversal(node_t *root) {
  if(root == NULL) {
    return;
  }
  else {
    printInOrderTraversal(root->left);
    printf("KEY: %s\n", root->key);
    printf("Data: %s\n\n", root->data.id);
    printInOrderTraversal(root->right);
  }
}*/
