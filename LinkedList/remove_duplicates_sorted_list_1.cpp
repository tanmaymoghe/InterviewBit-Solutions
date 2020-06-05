// Remove Duplicates from Sorted List
//
// Given a sorted linked list, delete all duplicates such that each element appear only once.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;

    ListNode* trav = A;
    ListNode* temp = A->next;

    while(temp!=NULL)
    {
        if(temp->val == trav->val)
            trav->next = temp->next;

        else
            trav = trav->next;

        temp = temp->next;
    }

    return A;
}
