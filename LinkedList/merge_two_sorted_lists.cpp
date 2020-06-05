#include <bits/stdc++.h>
// Merge Two Sorted Lists
//
// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* travA;
    ListNode* travB;
    ListNode* start;

    if(A==NULL)
        return B;
    if(B==NULL)
        return A;

    if(A->val > B->val)
    {
        start = B;
        travA = A;
        travB = B->next;
    }
    else
    {
        start = A;
        travA = A->next;
        travB = B;
    }

    ListNode* current = start;

    while(travA!=NULL && travB!=NULL)
    {
        if(travA->val > travB->val)
        {
            current->next = travB;
            travB = travB->next;
        }
        else
        {
            current->next = travA;
            travA = travA->next;
        }

        current = current->next;
    }

    if(travA==NULL)
        current->next = travB;
    else
        current->next = travA;

    return start;
}

// Modify next pointers, do not create a new list
// Corner Case - while comparing, one list ends, add remaining other list as it is
// Corner Case - one list empty
