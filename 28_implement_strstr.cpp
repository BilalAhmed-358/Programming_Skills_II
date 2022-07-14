/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1



Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    // uncomment all the cout statements to better understand the working of the program
    int strStr(string haystack, string needle)
    {
        int found = -1, size_of_found_needle = 0;
        // cout<<"Size of needle is "<<needle.size()<<endl;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                // cout<<"Found the first letter in haystack at"<<i<<endl;
                found = i;
                // if the needle has only 1 size then the loop will break here and return the value of i
                if (needle.size() == 1)
                {
                    // cout<<"Needle found completely breaking the loop (because needle had only 1 size)"<<endl;
                    size_of_found_needle = i + 1;
                    break;
                }
                // This secondary for loop will try to find the needle comppletely if the needle is found it will break the loop and return the index where first letter of the needle was found
                for (int j = 1, k = i + 1; j < needle.size(); j++, k++)
                {
                    // Checking each letter of the needle and contiuing each iteation
                    if (haystack[k] == needle[j])
                    {
                        // cout<<"Found another letter in the haystack"<<endl;
                        if (j + 1 == needle.size())
                        {
                            // cout<<"Needle found completely breaking the loop"<<endl;
                            size_of_found_needle = j + 1;
                            break;
                        }
                        continue;
                    }
                    // If at some place btw finding the needle there is an unrecognized letter then found will be set at -1 again and the for loop will break, then the needle will have to be found again from the start
                    else
                    {
                        found = -1;
                        break;
                    }
                }
                if (size_of_found_needle == needle.size())
                    break;
            }
        }
        return found;
    }
};
int main()
{
}