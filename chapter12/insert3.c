#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct NODE {
    struct NODE *link;
    int         value;
} Node;

#define FALSE 0
#define TRUE  1

int sll_insert1(Node *current, int new_value)
{
    Node *previous;
    Node *new;

    /* 寻找正确的插入位置, 方法是按顺序访问链表, 直到到达其值大于或等于新插入值的节点. */
    while (current->value < new_value)
    {
        previous = current;
        current = current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回FALSE. */
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        return FALSE;
    }
    new->value = new_value;

    /* 把新节点插入到链表中, 并返回True */
    new->link = current;
    previous->link = new;
    return TRUE;
}

int sll_insert2(Node **rootp, int new_value)
{
    Node *current;
    Node *previous;
    Node *new;

    /* 得到指向第一个节点的指针 */
    current = *rootp;
    previous = NULL;

    /* 寻找正确的插入位置, 方法是按序访问链表, 直到到达一个其值大于或等于新值的节点 */
    while (current != NULL && current->value < new_value)
    {
        previous = current;
        current = current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回FALSE */
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        return FALSE;
    }
    new->value = new_value;

    /* 把新节点插入到链表中, 并返回True */
    new->link = current;
    if (previous == NULL)
    {
        *rootp = new;
    }
    else 
    {
        previous->link = new;
    }
    return TRUE;
}



int sll_insert3(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    /* 寻找正确的插入位置, 方法是按顺序访问链表, 直到到达一个其值大于或等于新值的节点*/
    while ((current = *linkp) != NULL && current->value < new_value)
    {
        linkp = &current->link;
    }

    /* 为新节点分配内存, 并把新值存储到新节点中, 如果内存分配失败, 函数返回FALSE */
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        return FALSE;
    }
    new->value = new_value;

    /* 在链表中插入新节点, 并返回TRUE */
    new->link = current;
    *linkp = new;

    return TRUE;
}

int main(int argc, char *argv[])
{

    return 0;
}