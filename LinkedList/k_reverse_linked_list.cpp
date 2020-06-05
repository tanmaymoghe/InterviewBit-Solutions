// K reverse linked list
//
// Given a singly linked list and an integer K, reverses the nodes of the
// list K at a time and returns modified linked list.
// NOTE : The length of the list is divisible by K
//
// Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
// You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL || A->next==NULL || B==1)
        return A;

    int len = 1;
    ListNode* trav = A;
    while(trav->next!=NULL)
    {
        trav = trav->next;
        len++;
    }

    int times = len/B;

    ListNode* start;
    ListNode* end;
    ListNode* ret = NULL; // start of linked list to be returned
    ListNode* prev_end = NULL;
    trav = A;

    for(int i = 0; i<times;i++)
    {
        start = trav;
        int j = 1;
        while(j<B)
        {
            trav = trav->next;
            j++;
        }
        end = trav;
        trav = trav->next;

        ListNode* trav1 = start->next;
        ListNode* prev = start;
        ListNode* temp;
        while(trav1 != end) // loop to reverse the links
        {
            temp = trav1->next;
            trav1->next = prev;
            prev = trav1;
            trav1 = temp;
        }

        if(end->next == NULL) // to take care of last partition as loop will end after this (setting prev_end for hypothetical next loop run)
            start->next = NULL;
        end->next = prev;

        if(prev_end != NULL) // will set next pointer of end of previous partition
            prev_end->next = end;
        prev_end = start;

        if(i==0)
            ret = end;
    }

    return ret;
}

// Solution -
// 1) Find length of the linked List
// 2) Find how many times to reverse
// 3) reverse each partition and set start and end pointers appropriately
// 4) maintain pointer of end of previous partition and set it's next pointer to the start of the reversed current partition
