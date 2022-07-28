/*
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"



Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        char temp;
        int carry = 0, digit1 = 0, digit2 = 0, total = 0;
        string temp1 = a;
        string temp2 = b;
        reverse(temp1.begin(), temp1.end());
        reverse(temp2.begin(), temp2.end());
        for (int i = 0; i < max(temp1.size(), temp2.size()); i++)
        {
            if (i < temp1.size())
                digit1 = int(temp1[i]) - int('0');
            else
                digit1 = 0;
            if (i < temp2.size())
                digit2 = int(temp2[i]) - int('0');
            else
                digit2 = 0;

            total = digit1 + digit2 + carry;
            temp = char((total % 2) + 48);
            ans += temp;
            carry = total / 2;
        }
        if (carry != 0)
        {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}