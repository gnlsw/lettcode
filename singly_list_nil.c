/**********************************
Function : 单链表，在头节点处增加一个哨兵
Date     : 2016.05.30
Author   : gnlsw
***********************************/

#include <stdio.h>
#include <stdlib.h>

#define VOS_ERR 1
#define VOS_OK  0
#define VOS_NULL_PTR 0


struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 4

int addListNodeToTail(struct ListNode *pHead, int val);
int addListNodeToHead(struct ListNode *pHead, int val);
struct ListNode *initListNode();
int printListNode(struct ListNode *pHead);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main()
{
    struct ListNode *pList_1;
    struct ListNode *pList_2;
    struct ListNode *pResult;
    int    nums[ARRAY_SIZE] = {1, 2, 3, 4};
    int    i;

    pList_1 = initListNode();
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        addListNodeToTail(pList_1, nums[i]);
    }

    pList_2 = initListNode();
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        addListNodeToHead(pList_2, nums[i]);
    }

    printListNode(pList_1);
    printListNode(pList_2);

    pResult = addTwoNumbers(pList_1, pList_2);
    printListNode(pResult);

    return 0;
}

struct ListNode *initListNode()
{
    struct ListNode *pNode;

    pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(VOS_NULL_PTR == pNode)
    {
        return VOS_NULL_PTR;
    }
    pNode->next = VOS_NULL_PTR;

    return pNode;
}

int addListNodeToHead(struct ListNode *pHead, int val)
{
    struct ListNode *pNewNode;

    if(VOS_NULL_PTR == pHead)
    {
        printf("null list\n");
        return VOS_ERR;
    }

    pNewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(VOS_NULL_PTR == pNewNode)
    {
        return VOS_ERR;
    }
    pNewNode->val = val;
    pNewNode->next = pHead->next;
    pHead->next = pNewNode;

    return VOS_OK;
}

int addListNodeToTail(struct ListNode *pHead, int val)
{
    struct ListNode *pNode;
    struct ListNode *pNewNode;

    pNode = pHead;

    while(VOS_NULL_PTR != pNode->next)
    {
        pNode = pNode->next;
    }

    pNewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(VOS_NULL_PTR == pNewNode)
    {
        return VOS_ERR;
    }
    pNewNode->val  = val;
    pNewNode->next = 0;

    pNode->next = pNewNode;

    return VOS_OK;
}

int printListNode(struct ListNode *pHead)
{
    struct ListNode *pNode;
    pNode = pHead->next;
    while(VOS_NULL_PTR != pNode)
    {
        printf("%d ", pNode->val);
        pNode = pNode->next;
    }

    printf("\n");
    
    return VOS_OK;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *pLeftNode  = l1->next;
    struct ListNode *pRightNode = l2->next;
    struct ListNode *pResult    = VOS_NULL_PTR;
    struct ListNode *pNode      = VOS_NULL_PTR;
    struct ListNode *pNewNode   = VOS_NULL_PTR;
    int carrier = 0;
    int val;

    pResult = initListNode();
    pNode   = pResult;

    while((VOS_NULL_PTR != pLeftNode) && (VOS_NULL_PTR != pRightNode))
    {
        val     = (pLeftNode->val + pRightNode->val + carrier) % 10;
        carrier = (pLeftNode->val + pRightNode->val + carrier) / 10;
        pNewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNewNode->val = val;
        pNewNode->next = VOS_NULL_PTR;
        pNode->next = pNewNode;
        pNode = pNewNode;

        pLeftNode  = pLeftNode->next;
        pRightNode = pRightNode->next;
    }

    return pResult;
}


















