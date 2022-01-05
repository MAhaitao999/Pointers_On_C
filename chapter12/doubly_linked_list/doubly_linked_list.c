#include "doubly_linked_list.h"

/**
 * @brief 把一个值插入到一个双链表.
 * 
 * @param rootp 一个指向根节点的指针.
 * @param value 待插入的新值.
 * @return int 成功返回0, 否则返回-1.
 */
int dll_insert1(doubleNode *rootp, int value)
{
    doubleNode *this;
    doubleNode *next;
    doubleNode *new_node;

    /*
    ** 查看value是否已经存在于链表中, 如果是就返回.
    ** 否则, 为新值创建一个新节点("new_node"将指向它)
    ** "this"将指向应该在新节点之前的那个节点,
    ** "next"将指向应该在新节点之后的那个节点.
    */
    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = (doubleNode *)malloc(sizeof(doubleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /* 把新节点添加到链表中. */
    if (next != NULL) /* 情况1或2: 并非位于链表尾部 */
    {
        if (this != rootp) /* 情况1: 并非位于链表起始位置 */
        {
            new_node->fwd = next;
            this->fwd = new_node;
            new_node->bwd = this;
            next->bwd = new_node;
        }
        else /* 情况2: 位于链表起始位置 */
        {
            new_node->fwd = next;
            rootp->fwd = new_node;
            new_node->bwd = NULL;
            next->bwd = new_node;
        }
    }
    else /* 情况3或4: 位于链表尾部 */
    {
        if (this != rootp) /* 情况3: 并非位于链表的起始位置 */
        {
            new_node->fwd = NULL;
            this->fwd = new_node;
            new_node->bwd = this;
            rootp->bwd = new_node;
        }
        else /* 情况4: 位于链表的起始位置 */
        {
            new_node->fwd = NULL;
            rootp->fwd = new_node;
            new_node->bwd = NULL;
            rootp->bwd = new_node;
        }
    }

    return 0;
}

/**
 * @brief 把一个值插入到一个双链表.(版本1的插入逻辑进行优化)
 * 
 * @param rootp 一个指向根节点的指针.
 * @param value 待插入的新值.
 * @return int 成功返回0, 否则返回-1.
 */
int dll_insert2(doubleNode *rootp, int value)
{
    doubleNode *this;
    doubleNode *next;
    doubleNode *new_node;

    /*
    ** 查看value是否已经存在于链表中, 如果是就返回.
    ** 否则, 为新值创建一个新节点("new_node"将指向它)
    ** "this"将指向应该在新节点之前的那个节点,
    ** "next"将指向应该在新节点之后的那个节点.
    */
    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = (doubleNode *)malloc(sizeof(doubleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /* 把新节点添加到链表中. */
    if (next != NULL) /* 情况1或2: 并非位于链表尾部 */
    {
        new_node->fwd = next;
        if (this != rootp) /* 情况1: 并非位于链表起始位置 */
        {
            this->fwd = new_node;
            new_node->bwd = this;
        }
        else /* 情况2: 位于链表的起始位置 */
        {
            rootp->fwd = new_node;
            new_node->bwd = NULL;
        }
        next->bwd = new_node;
    }
    else /* 情况3或4: 位于链表尾部 */
    {
        new_node->fwd = NULL;
        if (this != rootp) /* 情况3: 并非位于链表的起始位置 */
        {
            this->fwd = new_node;
            new_node->bwd = this;
        }
        else /* 情况4: 位于链表的起始位置 */
        {
            rootp->fwd = new_node;
            new_node->bwd = NULL;
        }
        rootp->bwd = new_node;
    }

    return 0;
}

/**
 * @brief 把一个值插入到一个双链表.(版本2的插入逻辑进一步提炼)
 * 
 * @param rootp 一个指向根节点的指针.
 * @param value 待插入的新值.
 * @return int 成功返回0, 否则返回-1.
 */
int dll_insert3(doubleNode *rootp, int value)
{
    doubleNode *this;
    doubleNode *next;
    doubleNode *new_node;

    /*
    ** 查看value是否已经存在于链表中, 如果是就返回.
    ** 否则, 为新值创建一个新节点("new_node"将指向它)
    ** "this"将指向应该在新节点之前的那个节点,
    ** "next"将指向应该在新节点之后的那个节点.
    */
    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = (doubleNode *)malloc(sizeof(doubleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /* 把新节点添加到链表中. */
    if (this != rootp)
    {
        this->fwd = new_node;
        new_node->bwd = this;
    }
    else
    {
        rootp->fwd = new_node;
        new_node->bwd = NULL;
    }

    if (next != NULL)
    {
        next->bwd = new_node;
    }
    else
    {
        rootp->bwd = new_node;
    }

    return 0;
}

/**
 * @brief 把一个值插入到一个双链表.(最终简化版)
 * 
 * @param rootp 一个指向根节点的指针.
 * @param value 待插入的新值.
 * @return int 成功返回0, 否则返回-1.
 */
int dll_insert4(register doubleNode *rootp, int value)
{
    register doubleNode *this;
    register doubleNode *next;
    register doubleNode *new_node;

    /*
    ** 查看value是否已经存在于链表中, 如果是就返回.
    ** 否则, 为新值创建一个新节点("new_node"将指向它)
    ** "this"将指向应该在新节点之前的那个节点,
    ** "next"将指向应该在新节点之后的那个节点.
    */
    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = (doubleNode *)malloc(sizeof(doubleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /* 把新节点添加到链表中. */
    new_node->fwd = next;
    this->fwd = new_node;

    if (this != rootp)
    {
        new_node->bwd = this;
    }
    else
    {
        new_node->bwd = NULL;
    }

    if (next != NULL)
    {
        next->bwd = new_node;
    }
    else
    {
        rootp->bwd = new_node;
    }

    return 0;
}

/**
 * @brief 把一个值插入到一个双链表.(最终简化版v4的代码精简一下)
 * 
 * @param rootp 一个指向根节点的指针.
 * @param value 待插入的新值.
 * @return int 成功返回0, 否则返回-1.
 */
int dll_insert5(register doubleNode *rootp, int value)
{
    register doubleNode *this;
    register doubleNode *next;
    register doubleNode *new_node;

    /*
    ** 查看value是否已经存在于链表中, 如果是就返回.
    ** 否则, 为新值创建一个新节点("new_node"将指向它)
    ** "this"将指向应该在新节点之前的那个节点,
    ** "next"将指向应该在新节点之后的那个节点.
    */
    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = (doubleNode *)malloc(sizeof(doubleNode));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /* 把新节点添加到链表中. */
    new_node->fwd = next;
    this->fwd = new_node;

    /* 不推荐这样写, 因为代码可读性变差 */
    new_node->bwd = this != rootp ? this : NULL;
    (next != NULL ? next : rootp)->bwd = new_node;

    return 0;
}