/*
459. Repeated Substring Pattern
Easy

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.



Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:

Input: s = "aba"
Output: false

Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.



Constraints:

    1 <= s.length <= 104
    s consists of lowercase English letters.


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    /*
    You can uncomment the cout statements to see the working of the program but don't submit the code while the cout statements are uncommented otherwise you will get Output limit exceeded error
    */
    bool repeatedSubstringPattern(string s)
    {
        int len = s.size();
        string temp, compare_string;
        // cout<<len<<endl;
        int multiple = 0;
        for (int i = len / 2; i >= 1; i--)
        {
            compare_string = "";
            if (len % i != 0)
                continue;
            // cout<<"Value of i is: "<<i<<endl;
            multiple = len / i;
            temp = s.substr(0, i);
            // cout<<"Value of temp"<<endl;
            // cout<<temp<<endl;
            for (int j = 0; j < multiple; j++)
            {
                compare_string += temp;
                // cout<<"Value of compare string:"<<endl;
                // cout<<compare_string<<endl;
            }
            if (compare_string == s)
                return true;
        }
        return false;
    }
};
int main()
{
}