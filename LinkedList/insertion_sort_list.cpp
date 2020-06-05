// Insertion Sort List
//
// Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;

    ListNode* trav = A->next; // the node to be inserted in the sorted list
    ListNode* start = A; // start of sorted list
    ListNode* end = A; // end of sorted list
    ListNode* temp;

    while(trav!=NULL)
    {
        end->next = trav->next;

        if(trav->val >= end->val)   // value of node greated than last value of sorted list
        {                           // hence, insert node at end of sorted list
            temp = end->next;
            end->next = trav;
            trav->next = temp;
            end = trav;
            trav = trav->next;
            continue;
        }

        else if(trav->val <= start->val)    // value of node less than first value of sorted list
        {                                   // hence, insert node at beginning of sorted list
            temp = trav->next;
            trav->next = start;
            start = trav;
            trav = temp;
            continue;
        }

        else // have to traverse the sorted list and insert the node in between
        {
            ListNode* temp_trav = start;

            while(temp_trav != end)
            {
                temp = temp_trav->next;
                if(trav->val<=temp->val && trav->val>=temp_trav->val)
                {
                    temp_trav->next = trav;
                    trav->next = temp;
                    break;
                }
                else
                    temp_trav = temp_trav->next;
            }

            trav = end->next;
        }
    }

    return start;
}

// SOLUTION - Normal insertion sort followed
// Remove the node to be inserted from the list and insert it into the part of the list which is sorted.
// Take care of the end pointer of the sorted list after the node to be inserted is removed.

// A better way would be to make a function which inserts a node in a sorted lsit and call it repeatedly
