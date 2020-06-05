// Palindrome List

// Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

// Expected solution is linear in time and constant in space.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A==NULL || A->next == NULL)
        return 1;

    ListNode* trav = A;
    int len = 1;

    while(trav->next != NULL)
    {
        len++;
        trav = trav->next;
    }

    int upto = len/2;
    int i = 1;
    trav = A;

    while(i<upto)
    {
        i++;
        trav = trav->next;
    }

    ListNode* second;
    second = trav->next;
    trav->next = NULL;

    if(len%2!=0)
      second = second->next;

    ListNode* temp = second->next;
    second->next = NULL;

    ListNode* p;
    while(temp!=NULL)
    {
        p = temp->next;
        temp->next = second;
        second = temp;
        temp = p;
    }

    for(int i = 0; i<upto;i++)
    {
        if(A->val != second->val)
            return 0;

        A = A->next;
        second = second->next;
    }

    return 1;
}

// Solution Hint - Reverse the linked list after the midpoint and then compare
