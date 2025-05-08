#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    struct ListNode* cur1 = list1, * cur2 = list2;
    struct ListNode* head = NULL, * tail = NULL;

    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            // 尾插
            if (tail == NULL)
            {
                head = tail = cur1;
            }
            else
            {
                tail->next = cur1;
                tail = tail->next;
            }
            cur1 = cur1->next;
        }
        else
        {
            if (tail == NULL)
            {
                head = tail = cur2;
            }
            else
            {
                tail->next = cur2;
                tail = tail->next;
            }
            cur2 = cur2->next;
        }
    }

    if (cur1)
        tail->next = cur1;

    if (cur2)
        tail->next = cur2;

    return head;
}