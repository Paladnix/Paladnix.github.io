/**
 *
 * 最小表示法是从一个字符串的所有循环同构字符串中选择字典序最小的一个同构串来表示原串的方法。
 *
 * "abcd" 的循环同构串有4种，分别是"abcd"、"bcda"、"cdab"、"dabc"， 其中最小的是"abcd"
 * 请你补全下列代码实现这个算法。 如果有相同的两个字符串都最小，则取首位最靠前的一种。
 *
 * 函数返回最小表示法开头字符的下标
 *
 */


#include <bits/stdc++.h>
using namespace std;

int getMin(string s) {
    int i = 0,j = 1,k = 0, t, n = s.length();
    while(i < n && j < n && k < n) {
        t = s[__①___] - s[__②__];
        if(!t) k++;
        else {
            if(t>0) i+=k+1;
            else j+=___③____;
            
            if(i==j) j++;

            k=0;
        }
    }
    return i < j ? i : j;
}


int main() {
    string s;
    cout << getMin() << endl;
    return 0;
}

