#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

bool hasCycle(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}