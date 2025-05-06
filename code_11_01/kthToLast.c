#define _CRT_SECURE_NO_WARNINGS 1

int kthToLast(struct ListNode* head, int k)
{
    // struct ListNode* cur = head;
    // int count = 0;

    // while(cur)
    // {
    //     cur = cur->next;
    //     count++;
    // }

    // cur = head;

    // k = count - k;
    // while(k--)
    // {
    //     cur = cur->next;
    // }

    // return cur->val;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // fast先走k步，此时slow，fast距离为k
    while (k--)
    {
        // k大于链表长度
        if (fast == NULL)
            return NULL;

        fast = fast->next;
    }

    // 一起走，fast过尾结点跳出，slow指向倒数第k个结点
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;
}