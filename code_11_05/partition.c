#define _CRT_SECURE_NO_WARNINGS 1

/*
struct ListNode {
    int val;
    struct ListNode* next;
};*/

//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。 
ListNode* partition(ListNode* pHead, int x) 
{
    struct ListNode* head1, * tail1, * head2, * tail2;
    head1 = tail1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2 = tail2 = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* cur = pHead;
    while (cur)
    {
        if (cur->val < x)
        {
            tail1->next = cur;
            tail1 = tail1->next;
        }
        else
        {
            tail2->next = cur;
            tail2 = tail2->next;
        }

        cur = cur->next;
    }

    tail1->next = head2->next;
    tail2->next = NULL;
    pHead = head1->next;

    free(head1);
    head1 = NULL;

    free(head2);
    head2 = NULL;

    return pHead;
}