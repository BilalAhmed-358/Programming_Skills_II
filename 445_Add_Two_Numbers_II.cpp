/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]



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
        ListNode *temp1;
        ListNode *temp2;
        vector<int> ans;
        temp1 = l1;
        temp2 = l2;
        stack<int> s1;
        stack<int> s2;
        int val1 = 0, val2 = 0, sum = 0, carry = 0;
        int list1_size = 0, list2_size = 0;
        while (temp1 != NULL)
        {
            list1_size++;
            s1.push(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            list2_size++;
            s2.push(temp2->val);
            temp2 = temp2->next;
        }

        while (!s1.empty() || !s2.empty())
        {
            val1 = 0;
            val2 = 0;
            sum = 0;
            if (carry != 0)
            {
                sum += carry;
                carry--;
            }
            if (!s1.empty())
            {
                val1 = s1.top();
                s1.pop();
            }
            else
                val1 = 0;
            if (!s2.empty())
            {
                val2 = s2.top();
                s2.pop();
            }
            else
                val2 = 0;

            sum += val1 + val2;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        ListNode *ll_anshead = new ListNode;
        ll_anshead->val = ans[0];
        for (int i = 1; i < ans.size(); i++)
        {
            Insert(ll_anshead, ans[i]);
        }
        return ll_anshead;
    }
    void Insert(ListNode *head, int value)
    {
        ListNode *temp = new ListNode;
        temp->val = value;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
    void PrintVec(vector<int> a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
}