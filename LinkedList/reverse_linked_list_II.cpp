// Reverse Link List II
//
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list. Note 2:
// Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL || A->next==NULL || B==C)
        return A;

    ListNode* prev = NULL;
    ListNode* trav = A;

    int len=1;
    while(trav->next != NULL)
    {
        if(len==B)
            break;

        len++;
        prev = trav;
        trav = trav->next;
    }

    ListNode* prev1 = trav;
    ListNode* trav1 = trav->next;
    ListNode* next = trav->next->next;
    len++;

    while(len<=C)
    {
        trav1->next = prev1;
        prev1 = trav1;
        trav1 = next;
        if(next!=NULL)
            next = next->next;
        len++;
    }

    trav->next = trav1;
    if(prev==NULL)
        return prev1;
    else
    {
        prev->next = prev1;
        return A;
    }
}

// Solution - In pass, reversing the appropriate links 
