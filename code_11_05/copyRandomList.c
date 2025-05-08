#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    // 1.拷贝结点，并插入到原结点的后面
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));

        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;

        cur = cur->next->next;
    }

    // 2.处理copy结点的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }

        cur = cur->next->next;
    }

    // 3.解copy结点，尾插
    cur = head;
    struct Node* newhead = NULL, * tail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;

        if (tail == NULL)
        {
            newhead = tail = copy;
        }
        else
        {
            tail->next = copy;
            tail = tail->next;
        }

        cur->next = copy->next;
        cur = cur->next;
    }

    return newhead;
}