/*
The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.



Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021



Constraints:

    1 <= num.length <= 104
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 104


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> temp = num;
        reverse(temp.begin(), temp.end());
        int carry = 0, count = 0, holder = k;
        while (holder != 0)
        {
            count++;
            holder /= 10;
        }
        holder = k;
        cout << temp.size() << " " << holder << endl;
        if (temp.size() < count)
        {
            for (int i = 0; i < temp.size(); i++, holder /= 10)
            {
                if (carry != 0)
                {
                    temp[i]++;
                    carry--;
                }
                temp[i] += (holder % 10);
                if (temp[i] > 9)
                {
                    carry = temp[i] / 10;
                    temp[i] %= 10;
                }
            }
            while (holder != 0)
            {
                int pushed = 0;
                if (carry != 0)
                {
                    pushed++;
                    carry--;
                }
                pushed += (holder % 10);
                if (pushed > 9)
                {
                    carry = pushed / 10;
                    pushed %= 10;
                }
                temp.push_back(pushed);
                holder /= 10;
            }
            if (carry != 0)
            {
                temp.push_back(carry);
            }
        }
        else
        {
            for (int i = 0; i < temp.size(); i++, holder /= 10)
            {
                if (carry != 0)
                {
                    temp[i]++;
                    carry--;
                }
                temp[i] += (holder % 10);
                if (temp[i] > 9)
                {
                    carry = temp[i] / 10;
                    temp[i] %= 10;
                }
            }
            if (carry != 0)
            {
                temp.push_back(carry);
            }
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};
int main()
{
}