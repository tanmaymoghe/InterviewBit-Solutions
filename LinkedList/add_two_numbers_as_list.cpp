// Add Two Numbers as Lists
//
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//
// Make sure there are no trailing zeros in the output list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ret = NULL;
    ListNode* ret_trav = ret;
    int carry = 0;  // Check after adding both numbers, if it is 1 then one more digit has to be added to the resultant list
    int sum;

    while(A!=NULL && B!=NULL)
    {
        sum = A->val + B->val + carry;
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;

        ListNode* temp = new ListNode(sum);
        if(ret==NULL)
        {
            ret = temp;
            ret_trav = temp;
        }
        else
        {
            ret_trav->next = temp;
            ret_trav = ret_trav->next;
        }

        A = A->next;
        B = B->next;
    }

    if(A==NULL && B==NULL)
    {
        if(carry == 1)
        {
            ListNode* temp = new ListNode(carry);
            ret_trav->next = temp;
        }

        return ret;
    }

    ListNode* remain;
    if(A==NULL)
        remain = B;
    else
        remain = A;

    while(remain!=NULL)
    {
        sum = remain->val + carry;
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;

        ListNode* temp = new ListNode(sum);
        if(ret==NULL)
        {
            ret = temp;
            ret_trav = temp;
        }
        else
        {
            ret_trav->next = temp;
            ret_trav = ret_trav->next;
        }

        remain = remain->next;
    }

    if(carry==1)
    {
        ListNode* temp = new ListNode(carry);
        ret_trav->next = temp;
    }

    return ret;
}

// SOLUTION - Normal long addition
// Edge Cases -
// 1) One list shorter than other
// 2) Extra Digit (carry == 1 at the end)

// Much Cleaner and Shorter Code below

ListNode* Solution::addTwoNumbers2(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;

    ListNode* ret = NULL;
    ListNode* ret_trav = ret;
    int carry = 0;
    int sum;

    while(A || B || carry)
    {
        sum = (A?A->val:0) + (B?B->val:0) + carry;
        carry = (sum>=10)?1:0;
        sum = sum%10;

        if(ret==NULL)
        {
            ret = new ListNode(sum);
            ret_trav = ret;
        }
        else
        {
            ret_trav->next = new ListNode(sum);
            ret_trav = ret_trav->next;
        }

        if(A) A = A->next;
        if(B) B = B->next;
    }

    return ret;
}
