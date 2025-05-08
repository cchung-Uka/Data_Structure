#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* curA = headA, * curB = headB;
    int lenA = 1, lenB = 1;

    while (curA->next)
    {
        lenA++;
        curA = curA->next;
    }

    while (curB->next)
    {
        lenB++;
        curB = curB->next;
    }

    if (curA != curB)
    {
        return NULL;
    }

    int n = abs(lenA - lenB);
    struct ListNode* longList = headA, * shortList = headB;
    if (lenB > lenA)
    {
        longList = headB;
        shortList = headA;
    }

    while (n--)
    {
        longList = longList->next;
    }

    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }

    return longList;
}