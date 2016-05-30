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

#define ARRAY_SIZE_1 4
#define ARRAY_SIZE_2 4

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
    int    nums_1[ARRAY_SIZE_1] = {1, 2, 3, 4};
    int    nums_2[ARRAY_SIZE_2] = {8, 7, 5, 6};
    int    i;

    pList_1 = initListNode();
    for(i = 0; i < ARRAY_SIZE_1; i++)
    {
        addListNodeToTail(pList_1, nums_1[i]);
    }

    pList_2 = initListNode();
    for(i = 0; i < ARRAY_SIZE_2; i++)
    {
        addListNodeToHead(pList_2, nums_2[i]);
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

int deleteListNodeFromHead(struct ListNode *pHead)
{
    struct ListNode *pNode = VOS_NULL_PTR;
    if(VOS_NULL_PTR == pHead)
    {
        /* 增加枚举定义，区分返回值 */
        return VOS_ERR;
    }
    if(VOS_NULL_PTR == pHead->next)
    {
        return VOS_ERR;
    }

    pNode = pHead->next;
    pHead->next = pNode->next;
    free(pNode);

    return VOS_OK;
}

int deleteListNodeFromTail()
{
    struct ListNode *pNode = VOS_NULL_PTR;
    if(VOS_NULL_PTR == pHead)
    {
        /* 增加枚举定义，区分返回值 */
        return VOS_ERR;
    }
    if(VOS_NULL_PTR == pHead->next)
    {
        return VOS_ERR;
    }

    pNode = pHead;
    while(VOS_NULL_PTR != pNode->next->next)
    {
        pNode = pNode->next;
    }

    pDeleteNode = pNode->next;
    pNode->next = VOS_NULL_PTR;
    free(pDeleteNode);

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
    int dwLeftVal;
    int dwRightVal;
    int val;

    pResult = initListNode();
    pNode   = pResult;

    while((VOS_NULL_PTR != pLeftNode) && (VOS_NULL_PTR != pRightNode))
    {
        if(VOS_NULL_PTR == pLeftNode)
        {
            dwLeftVal = 0;
        }
        else
        {
            dwLeftVal = pLeftNode->val;
            pLeftNode = pLeftNode->next;
        }

        if(VOS_NULL_PTR == pRightNode)
        {
            dwRightVal = 0;
        }
        else
        {
            dwRightVal = pRightNode->val;
            pRightNode = pRightNode->next;
        }

        val     = (dwLeftVal + dwRightVal + carrier) % 10;
        carrier = (dwLeftVal + dwRightVal + carrier) / 10;
        pNewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNewNode->val = val;
        pNewNode->next = VOS_NULL_PTR;
        pNode->next = pNewNode;
        pNode = pNewNode;
    }

    if(0 != carrier)
    {
        pNewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNewNode->val = carrier;
        pNewNode->next = VOS_NULL_PTR;
        pNode->next = pNewNode;
    }


    return pResult;
}


















