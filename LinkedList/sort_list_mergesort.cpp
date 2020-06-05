Sort List

Sort a linked list in O(n log n) time using constant space complexity.
Recursive Merge Sort - O(n) space complexity
Iterative Merge Sort - O(1) space complexity

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* sortList1(ListNode* start, ListNode* end);
void printList(ListNode* list);

ListNode* Solution::sortList(ListNode* A) {
    ListNode* end = A;
    while(end->next) end = end->next;
    return sortList1(A,end);
}

ListNode* sortList1(ListNode* start, ListNode* end)
{
    if(start==end)
        return start;

    ListNode* one = start;
    ListNode* two = start->next;

    while(two!=NULL)
    {
        two = two->next;
        if(two==NULL)
            break;
        two = two->next;
        one = one->next;
    } // after this loop, now one will point to the midpoint
    // if its a two member list, one will point to the start and not the end

    ListNode* temp = one->next;
    one->next = NULL; // in order to make the two halves separate
    ListNode* sorted_list_1 = sortList1(start,one); // first half sorted
    ListNode* sorted_list_2 = sortList1(temp,end); // second half sorted
    ListNode* ret = NULL; // current node of linked list to be returned
    ListNode* start_ret = NULL; // head of linked list to be returned

    while(sorted_list_1 || sorted_list_2)
    {
        if(sorted_list_1==NULL)  // sorted_list_1 has gone empty
        {
            ret->next = sorted_list_2;
            ret = ret->next;
            sorted_list_2 = sorted_list_2->next;
            continue;
        }

        if(sorted_list_2==NULL) // sorted_list_2 has gone empty
        {
            ret->next = sorted_list_1;
            ret = ret->next;
            sorted_list_1 = sorted_list_1->next;
            continue;
        }

        if(sorted_list_1->val < sorted_list_2->val)
        {
            if(ret)
            {
                ret->next = sorted_list_1;
                ret = ret->next;
            }
            else // first node
            {
                ret = sorted_list_1;
                start_ret = ret;
            }
            sorted_list_1 = sorted_list_1->next;
        }
        else
        {
            if(ret)
            {
                ret->next = sorted_list_2;
                ret = ret->next;
            }
            else // first node
            {
                ret = sorted_list_2;
                start_ret = ret;
            }
            sorted_list_2 = sorted_list_2->next;
        }
    }

    return start_ret;
}

// SOLUTION
// Recursive merge sort has been implemented (complexity is O(n) if stack space is considered)
// For O(1) space complexity, use iterative merge sort (TODO)
