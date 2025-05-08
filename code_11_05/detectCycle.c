#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            struct ListNode* meet = head;
            // 一个指针从链表起始位置运行，一个指针从相遇点位置绕环，最后在入口点相遇。
            while (meet != slow)
            {
                meet = meet->next;
                slow = slow->next;
            }

            return meet;
        }
    }

    return NULL;
}