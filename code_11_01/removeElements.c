#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            struct ListNode* next = cur->next;
//
//            if (prev)
//                prev->next = next;
//            else
//                head = next;
//
//            free(cur);
//            cur = next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//
//    return head;
//}

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* newhead = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        if (cur->val != val)
        {
            if (tail == NULL)
            {
                newhead = cur;
                tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }

            cur = cur->next;
        }
        else
        {
            struct ListNode* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }

    if (tail)
        tail->next = NULL;

    return newhead;
}