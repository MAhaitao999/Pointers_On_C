#include "singly_linked_list.h"

/**
 * @brief 插入一个新节点到一个有序的单链表中(第一个版本).
 * 
 * @param current 指向第一个节点的指针
 * @param new_value 需要插入的值
 * @return int 成功返回0, 否则返回-1
 */
int sll_insert1(singleNode *current, int new_value)
{
    singleNode *previous;
    singleNode *new_node;

    /* 寻找正确的插入位置, 方法是按顺序访问链表, 直到到达其值大于或等于新插入值的节点. */
    while (current->value < new_value)
    {
        previous = current;
        current = current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回-1. */
    new_node = (singleNode *)malloc(sizeof(singleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = new_value;

    /* 把新节点插入到链表中, 并返回0 */
    new_node->link = current;
    previous->link = new_node;
    return 0;
}

/**
 * @brief 插入一个新节点到一个有序的单链表中(第二个版本).
 * 
 * @param rootp 指向链表根指针的指针
 * @param new_value 需要插入的新值
 * @return int 成功返回0, 否则返回-1
 */
int sll_insert2(singleNode **rootp, int new_value)
{
    singleNode *current;
    singleNode *previous;
    singleNode *new_node;

    /* 得到指向第一个节点的指针 */
    current = *rootp;
    previous = NULL;

    /* 寻找正确的插入位置, 方法是按序访问链表, 直到到达一个其值大于或等于新值的节点 */
    while (current != NULL && current->value < new_value)
    {
        previous = current;
        current = current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回-1 */
    new_node = (singleNode *)malloc(sizeof(singleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = new_value;

    /* 把新节点插入到链表中, 并返回0 */
    new_node->link = current;
    if (previous == NULL)
    {
        *rootp = new_node;
    }
    else 
    {
        previous->link = new_node;
    }
    return 0;
}

/**
 * @brief 插入一个新节点到一个有序的单链表中(最终版本).
 * 
 * @param linkp 指向链表第一个节点的指针
 * @param new_value 需要插入的新值
 * @return int 成功返回0, 否则返回-1
 */
int sll_insert3(register singleNode **linkp, int new_value)
{
    register singleNode *current;
    register singleNode *new_node;

    /* 寻找正确的插入位置, 方法是按顺序访问链表, 直到到达一个其值大于或等于新值的节点*/
    while ((current = *linkp) != NULL && current->value < new_value)
    {
        linkp = &current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回-1 */
    new_node = (singleNode *)malloc(sizeof(singleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = new_value;

    /* 在链表中插入新节点, 并返回0 */
    new_node->link = current;
    *linkp = new_node;

    return 0;
}