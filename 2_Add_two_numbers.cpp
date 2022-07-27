/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]



Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.


*/
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, l1_size = 0, l2_size = 0;
        ListNode *temp1;
        ListNode *temp2;
        temp1 = l1;
        while (temp1 != NULL)
        {
            l1_size++;
            temp1 = temp1->next;
        }
        temp1 = l2;
        while (temp1 != NULL)
        {
            l2_size++;
            temp1 = temp1->next;
        }

        if (l1_size >= l2_size)
        {
            temp1 = l1;
            temp2 = l2;
            while (temp2 != NULL)
            {
                int temp_val = 0;
                if (carry == 1)
                {
                    temp_val++;
                    carry--;
                }
                temp_val += temp1->val + temp2->val;
                cout << temp1->val << " " << temp2->val << endl;
                cout << temp_val << endl;
                if (temp_val > 9)
                {
                    carry = 1;
                }
                temp2 = temp2->next;
                temp1->val = temp_val % 10;
                temp1 = temp1->next;
            }
            while (temp1 != NULL)
            {
                int temp_val = 0;
                if (carry == 1)
                {
                    temp_val++;
                    carry--;
                }
                temp_val += temp1->val;
                cout << temp_val << endl;
                if (temp_val > 9)
                {
                    carry = 1;
                }
                temp1->val = temp_val % 10;
                temp1 = temp1->next;
            }
            if (carry == 1)
            {
                temp1 = l1;
                while (temp1->next != NULL)
                    temp1 = temp1->next;
                ListNode *node = new ListNode;
                node->val = 1;
                cout << "The value of newly created node is " << node->val << endl;
                temp1->next = node;
            }
            return l1;
        }
        else
        {
            temp2 = l2;
            temp1 = l1;
            while (temp1 != NULL)
            {
                int temp_val = 0;
                if (carry == 1)
                {
                    temp_val++;
                    carry--;
                }
                temp_val += temp2->val + temp1->val;
                cout << temp2->val << " " << temp1->val << endl;
                cout << temp_val << endl;
                if (temp_val > 9)
                {
                    carry = 1;
                }
                temp1 = temp1->next;
                temp2->val = temp_val % 10;
                temp2 = temp2->next;
            }
            while (temp2 != NULL)
            {
                int temp_val = 0;
                if (carry == 1)
                {
                    temp_val++;
                    carry--;
                }
                temp_val += temp2->val;
                cout << temp_val << endl;
                if (temp_val > 9)
                {
                    carry = 1;
                }
                temp2->val = temp_val % 10;
                temp2 = temp2->next;
            }
            if (carry == 1)
            {
                temp2 = l2;
                while (temp2->next != NULL)
                    temp2 = temp2->next;
                ListNode *node = new ListNode;
                node->val = 1;
                cout << "The value of newly created node is " << node->val << endl;
                temp2->next = node;
            }
            return l2;
        }
        return l1;
    }
};
int main()
{
}