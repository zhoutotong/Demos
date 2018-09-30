
#include "chaintable.h"

ChainTable* initializationChainTable()
{
    ChainTable *ct = (ChainTable*)malloc(sizeof(ChainTable));
    ct->head = NULL;
    ct->tail = NULL;
    
    return ct;
}
Node* addNodeToTail(ChainTable *ct, Node *node)
{
    if((ct->head == NULL) && (ct->tail == NULL))
    {
        // 链表为空链表
        ct->head = node;
        ct->tail = node;
        node->next = NULL;
    }else{
        // 链表不为空链表时，将链表最后一个节点的next指针指向新加入的节点，随后将tail指向新加入的节点
		ct->tail->next = node;
        ct->tail = node;
        node->next = NULL;
    }
    return node;
}
Node* addDataToTail(ChainTable *ct, DataSet *data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    copyDataAToDataB(data, &node->data);
    addNodeToTail(ct, node);
    return addNodeToTail(ct, node);
}
Node* addNodeToHead(ChainTable *ct, Node *node)
{
    if(ct->head == NULL && ct->tail == NULL)
    {
        // 链表为空链表
        ct->head = node;
        ct->tail = node;
        node->next = NULL;
    }else{
        // 链表不为空链表时，将新节点next指针指向当前链表的头，随后将链表的head指针指向新节点
        node->next = ct->head;
        ct->head = node;
    }
}

Node* addDataToHead(ChainTable *ct, DataSet *data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    copyDataAToDataB(data, &node->data);
    addNodeToHead(ct, node);
    return node;
}

Node* deleteNodeFromTail(ChainTable *ct)
{
    Node *pnode = ct->head;
    while(pnode->next != ct->tail)
    {
        pnode = pnode->next;
    }

    free(pnode->next);
    ct->tail = pnode;
    pnode->next = NULL;  
    return pnode;
}

void releaseChainTable(ChainTable *ct)
{
    Node *pnode = ct->head;
    Node *freenode;
    while(pnode != NULL)
    {
        freenode = pnode;
        pnode = pnode->next;
        free(freenode);
    }
    free(ct);
}

void copyDataAToDataB(DataSet *A, DataSet *B)
{
    unsigned int i, size = sizeof(DataSet);
    // 逐字节拷贝数据
    for(i = 0; i < size; i++)
    {
        BYTE(B, i) = BYTE(A, i);
    }
}
