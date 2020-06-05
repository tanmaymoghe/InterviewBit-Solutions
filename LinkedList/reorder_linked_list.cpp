// Reorder List
//
// Given a singly linked list
// L: L0 → L1 → … → Ln-1 → Ln,
// reorder it to:
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// You must do this in-place without altering the nodes’ values.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;

    int len = 1;
    ListNode* trav = A;
    while(trav->next != NULL)
    {
        trav = trav->next;
        len++;
    }

    int midlen = len/2 + 1;

    ListNode* mid = A;
    ListNode* prev = NULL;
    int i = 1;
    while(i!=midlen)
    {
        prev = mid;
        mid = mid->next;
        i++;
    }

    prev->next = NULL;

    prev = mid;
    ListNode* curr = mid->next;
    ListNode* temp;

    mid->next = NULL;
    while(curr!=NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    ListNode* B = prev;
    ListNode* temp1;

    trav = A;
    while(trav!=NULL)
    {
        temp = trav->next;
        temp1 = B->next;

        if(temp==NULL && temp1!=NULL) // The case of odd length list
        {
            trav->next = B;
            break;
        }

        trav->next = B;
        B->next = temp;
        trav = temp;
        B = temp1;
    }

    return A;
}

// SOLUTION
// 1) Find the middle point (tortoise and hare method or 1 and half traversals - both take the same time)
// 2) Split the linked list into two halves using found middle point in step 1.
// 3) Reverse the second half.
// 4) Do alternate merge of first and second halves.
