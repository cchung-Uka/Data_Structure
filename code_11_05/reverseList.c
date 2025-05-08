#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//
//    return prev;
//}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;

        // 头插
        cur->next = newhead;
        newhead = cur;

        cur = next;
    }

    return newhead;
}