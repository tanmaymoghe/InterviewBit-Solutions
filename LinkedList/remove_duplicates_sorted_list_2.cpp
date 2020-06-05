// Remove Duplicates from Sorted List II
//
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

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

    ListNode* back = A;
    ListNode* front = A->next;

    if(front->next == NULL)
    {
        if(back->val == front->val)
            return NULL;
        else
            return A;
    }

    ListNode* backback = NULL;
    ListNode* trav;
    while(true)
    {
        if(back->val == front->val)
        {
            trav = front->next;
            while(trav!=NULL)
            {
                if(trav->val == front->val)
                    trav = trav->next;
                else
                    break;
            }

            if(trav==NULL)
            {
                if(backback == NULL)
                    return NULL;
                else
                {
                    backback->next = NULL;
                    return A;
                }
            }

            if(backback!=NULL)
                backback->next = trav;

            back = trav;
            front = trav->next;

            if(front==NULL)
                return A;
        }

        else
        {
            if(backback==NULL)
                A = back;

            backback = back;
            back = front;
            front = front->next;
            if(front==NULL)
                return A;
        }
    }
}

// Solution Hint - Maintain two nodes for checking - current and next. Also maintain a previous node. if curr.val == next.val, go forward until
// duplicates end and then point at next one

// Corner Cases -
// 1> Repetitions at beginning
// 2> Repetitions at end
// 3> 0,1,2 element lists
