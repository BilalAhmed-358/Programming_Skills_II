/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"



Constraints:

    1 <= num1.length, num2.length <= 200
    num1 and num2 consist of digits only.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int size1 = num1.size(), size2 = num2.size();
        int *ans = new int[size1 + size2]();
        string str_ans, str_num1, str_num2;
        // num1= 123 (in the i loop)
        // num2= 456 (in the j loop)
        for (int i = 0; i < size1; i++)
        {
            int catch_ = 0;
            str_num1 = num1[size1 - i - 1];
            int temp1 = stoi(str_num1);
            // cout<<temp1<<endl;

            for (int j = 0; j < size2; j++)
            {
                int mul = 0;
                str_num2 = num2[size2 - 1 - j];
                int temp2 = stoi(str_num2);
                // cout<<temp2<<endl;
                mul = temp1 * temp2;
                // cout<<"Value of Mul is "<<mul<<endl;
                // cout<<"Value of before ans[i+j]="<<ans[i+j]<<endl;
                ans[i + j] += (mul) % 10;
                ans[i + j + 1] += (mul) / 10;
                ans[i + j + 1] += (ans[i + j]) / 10;
                ans[i + j] = (ans[i + j]) % 10;
                // cout<<"Value of after ans[i+j]="<<ans[i+j]<<endl;
                // cout<<"Value of ans[i+j+1]="<<ans[i+j+1]<<endl;
            }
        }
        ReverseArray(ans, size1 + size2);
        // PrintArray(ans,size1+size2);
        converter(str_ans, ans, size1 + size2);
        return str_ans;
    }

    void converter(string &str_ans, int ans[], int n)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 && ans[i] != 0)
            {
                // cout<<ans[i]<<endl;
                str_ans += to_string(ans[i]);
                flag = true;
                continue;
            }
            else if (flag == true)
            {
                // cout<<ans[i]<<endl;
                str_ans += to_string(ans[i]);
            }
            if (i + 1 < n && ans[i + 1] != 0 && flag == false)
            {
                flag = true;
                continue;
            }
        }
    }

    void ReverseArray(int array[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(array[i], array[n - 1 - i]);
        }
    }

    void PrintArray(int array[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << array[i] << " ";
    }
};
int main()
{
}