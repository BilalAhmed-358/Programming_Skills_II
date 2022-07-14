/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true



Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104


*/
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Logic Explained:
Basically I will inorderly traverse the whole binary tree and at each node check the condition of the balanced binary treeinsie the Inorder function using the helper function which returns the deepest root at a node from its left and right subtree.
I will also maintain a vector of ans which will save the record at each node whether it satifies the condition of the balanced binary tree or not.
After the tree has been traversed completely, a for loop is used to check through the vector of answers, if there is a single false case then that means that the binary tree is not a balanced binary tree and the function will return false, but if all entries are true inside the vector of answer then the tree is a balanced  binary tree and the function will return true.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<bool> ans;
    bool isBalanced(TreeNode *root)
    {
        bool decision = true;
        if (root == NULL)
            Inorder_trav(root, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == false)
            {
                decision = false;
                break;
            }
        }
        return decision;
    }

    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(helper(root->left), helper(root->right));
    }

    void Inorder_trav(TreeNode *root, vector<bool> &ans)
    {
        if (root == NULL)
            return;
        Inorder_trav(root->left, ans);
        if (helper(root->left) - helper(root->right) == 1 || helper(root->right) - helper(root->left) == 1 || helper(root->left) == helper(root->right))
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
        Inorder_trav(root->right, ans);
    }
};
int main()
{
}