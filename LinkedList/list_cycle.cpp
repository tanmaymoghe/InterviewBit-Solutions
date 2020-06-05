List Cycle

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* hare = A;
    ListNode* tortoise = A;
    bool no_cycle = true;

    while(tortoise && hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise==hare)
        {
            no_cycle = false;
            break;
        }
    }

    if(no_cycle)
        return NULL;

    while(A)
    {
        if(A==tortoise)
            return A;

        A = A->next;
        tortoise = tortoise->next;
    }

    return NULL;
}

// SOLUTION 
// Use the floyd cycle detection algorithm
