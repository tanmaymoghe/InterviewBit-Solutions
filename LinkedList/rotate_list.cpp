// Rotate List
//
// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;

    ListNode* trav = A;
    int len = 1;                //Need to calculate the length as k can be greater than the length (k%len)
    while(trav->next!=NULL)
    {
        len++;
        trav = trav->next;
    }

    ListNode* end = trav;
    ListNode* prev = NULL;

    B = B%len;

    if(B==0)
        return A;

    trav = A;
    int upto = len-B;
    while(upto>0)
    {
        prev = trav;
        trav = trav->next;
        upto--;
    }

    prev->next = NULL;
    end->next = A;
    return trav;
}
