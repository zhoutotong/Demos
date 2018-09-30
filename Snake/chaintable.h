#ifndef _CHAINTABLE_H_
#define _CHAINTABLE_H_
#include <stdlib.h>
typedef char uint8_t;


#define BYTE(data, n) (*((uint8_t*)data + n))

typedef struct _Point{
	int x;
	int y;
}Point;
typedef Point DataSet;

typedef struct _Node{
    DataSet data;
    struct _Node *next;
}Node;

typedef struct _ChainTable{
    Node *head;
    Node *tail;
}ChainTable;

// data tools
void copyDataAToDataB(DataSet *A, DataSet *B);

ChainTable* initializationChainTable();
Node* addNodeToTail(ChainTable *ct, Node *node);
Node* addDataToTail(ChainTable *ct, DataSet *data);
Node* addNodeToHead(ChainTable *ct, Node *node);
Node* addDataToHead(ChainTable *ct, DataSet *node);
Node* deleteNodeFromTail(ChainTable *ct);
void releaseChainTable(ChainTable *ct);

#endif
