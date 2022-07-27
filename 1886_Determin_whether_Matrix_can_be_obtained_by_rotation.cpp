/*
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.



Example 1:

Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

Example 2:

Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.

Example 3:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.



Constraints:

    n == mat.length == target.length
    n == mat[i].length == target[i].length
    1 <= n <= 10
    mat[i][j] and target[i][j] are either 0 or 1.


*/

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> temp;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
                temp = Rotation(mat);
            else
                temp = Rotation(temp);
            if (temp == target)
                return true;
        }
        return false;
    }
    vector<vector<int>> Rotation(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> temp;
        for (int i = 0; i < rows; i++)
        {
            temp.push_back(vector<int>());
            for (int j = columns - 1; j >= 0; j--)
            {
                temp[i].push_back(matrix[j][i]);
            }
        }
        return temp;
    }
};

int main()
{
}