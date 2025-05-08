#define _CRT_SECURE_NO_WARNINGS 1

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

// 1.找中间节点
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
// 2.逆置链表后半部分
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        struct ListNode* next = cur->next;

        cur->next = newhead;
        newhead = cur;

        cur = next;
    }

    return newhead;
}

bool chkPalindrome(ListNode* head) 
{
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);

    while (rhead)
    {
        // 不需要考虑奇偶个结点，前半部分最后一个结点仍然指向它的next，所以不影响对比
        if (head->val != rhead->val)
        {
            return false;
        }

        head = head->next;
        rhead = rhead->next;
    }

    return true;
}