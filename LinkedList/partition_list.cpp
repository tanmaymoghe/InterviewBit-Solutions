// Partition List
//
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;

    ListNode* smaller_list = NULL;
    ListNode* bigger_list = NULL;
    ListNode* small_head = NULL;
    ListNode* big_head = NULL;
    ListNode* trav = A;

    while(trav!=NULL)
    {
        if(trav->val < B)
        {
            if(smaller_list==NULL)
            {
                smaller_list = trav;
                small_head = trav;
            }
            else
            {
                smaller_list->next = trav;
                smaller_list = trav;
            }
        }
        else
        {
            if(bigger_list==NULL)
            {
                bigger_list = trav;
                big_head = trav;
            }
            else
            {
                bigger_list->next = trav;
                bigger_list = trav;
            }
        }

        trav = trav->next;
    }

    if(bigger_list) bigger_list->next = NULL;
    else
    {
        smaller_list->next = NULL;
        return small_head;
    }

    if(smaller_list)
    {
        smaller_list->next = big_head;
        return small_head;
    }
    else return big_head;
}

// SOLUTION
// Maintain two lists (for elements either smaller or greater)
// Edge Cases:
// 1) NULL input
// 2) one of the two lists empty
