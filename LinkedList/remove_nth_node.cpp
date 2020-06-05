// Remove Nth Node from List End
//
// Given a linked list, remove the nth node from the end of list and return its head.
// If n is greater than the size of the list, remove the first node of the list.

// 2 Solutions in this file

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A==NULL)
        return NULL;

    ListNode* trav = A;
    int len = 1;

    while(trav->next != NULL)
    {
        len++;
        trav = trav->next;
    }

    int upto = len - B;

    if(B > len || upto==0)
        return A->next;

    trav = A;

    while(upto > 1)
    {
        trav = trav->next;
        upto--;
    }

    if(trav->next->next == NULL)
    {
        trav->next = NULL;
        return A;
    }
    else
    {
        trav->next = trav->next->next;
        return A;
    }
}

// Solution1 (above) - traverse the list, find the length and then go to appropriate element to delete it
// Solution2 (below) - two pointers, make the first pointer go B steps ahead, keep second pointer at start. Now keep moving the first pointer ahead
// and the second one at the start one step at a time. Now when the first one becomes null, delete element pointed to by the second pointer

ListNode* Solution::removeNthFromEnd2(ListNode* A, int B) {
    if(A==NULL)
        return NULL;

    ListNode* trav = A;
    while(B>0)
    {
        trav = trav->next;
        B--;

        if(trav==NULL)
            return A->next;
    }

    ListNode* trav1 = A;
    ListNode* prev = NULL;

    while(trav!=NULL)
    {
        prev = trav1;
        trav1 = trav1->next;
        trav = trav->next;
    }

    if(prev==NULL)
        return A->next;

    prev->next = trav1->next;
    return A;
}
