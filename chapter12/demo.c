#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"
#include "doubly_linked_list.h"

void test_sll_insert1(void);

void test_sll_insert2(void);

void test_sll_insert3(void);

int main(int argc, char *argv[])
{
    test_sll_insert1();

    test_sll_insert2();

    test_sll_insert3();
    return 0;
}

void test_sll_insert1(void)
{
    singleNode n0;
    singleNode n1;
    singleNode n2;
    singleNode *root;
    // singleNode **root_p = &root;
    n0.value = 5;
    n1.value = 10;
    n2.value = 15;
    n0.link = &n1;
    n1.link = &n2;
    n2.link = NULL;
    root = &n0;
    int status = sll_insert1(root, 12);
    if (status == 0)
    {
        printf("sll insert1 PASS!\n");
        while (root != NULL)
        {
            printf("value is: %d\n", root->value);
            root = root->link;
        }
    }
    else 
    {
        printf("sll insert1 FAILED!");
    }
}

void test_sll_insert2(void)
{
    singleNode n0;
    singleNode n1;
    singleNode n2;
    singleNode *root;
    singleNode **root_p = &root;
    n0.value = 5;
    n1.value = 10;
    n2.value = 15;
    n0.link = &n1;
    n1.link = &n2;
    n2.link = NULL;
    root = &n0;
    int status = sll_insert2(root_p, 20);
    if (status == 0)
    {
        printf("sll insert2 PASS!\n");
        while (root != NULL)
        {
            printf("value is: %d\n", root->value);
            root = root->link;
        }
    }
    else 
    {
        printf("sll insert2 FAILED!");
    }
}

void test_sll_insert3(void)
{
    singleNode n0;
    singleNode n1;
    singleNode n2;
    singleNode *root;
    singleNode **root_p = &root;
    n0.value = 5;
    n1.value = 10;
    n2.value = 15;
    n0.link = &n1;
    n1.link = &n2;
    n2.link = NULL;
    root = &n0;
    int status = sll_insert3(root_p, -1);
    status = sll_insert3(root_p, 17);
    status = sll_insert3(root_p, 99);

    if (status == 0)
    {
        printf("sll insert3 PASS!\n");
        while (root != NULL)
        {
            printf("value is: %d\n", root->value);
            root = root->link;
        }
    }
    else 
    {
        printf("sll insert3 FAILED!");
    }   
}
