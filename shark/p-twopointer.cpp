/* 从给定的字符串中，找出最短的一段，使得它包含这个字符串中的每一种字符。输出这一段，有相同长度的输出最靠左侧的一段 */

#include<bits/stdc++.h>
using namespace std;
string s;

bool check(int *a, int *b, int n) {
    for(int i = 0; i < n; i++) {
        if(a[i] == 0 && b[i] > 0 ) return false;
    }    
    return true;
}

int flag[256], bucket[256];  // 标记1

int main() {
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        bucket[s[i]] = 1;
    }
    // 标记 2
    int L=0, R=0, len = 0;
    for(int i = 0, j = 0; i < s.length(); i++) {
        while(j < s.length() && !check(flag, bucket, 256)) { // 标记3
            flag[s[j++]] ++;
        }
        if(check(flag, bucket, 256) && j - i < len) {
            len = j - i;
            L = i;
            R = j;
        }
        flag[s[i]] --;
    }
    for(int i = L; i < R; i++) cout << s[i];
    cout << endl;
    return 0;
}

/**
 * 
 
该程序的时间复杂度是

- n
- 256*n
- n*n
- 256*n*n

交换标记3处两个条件语句，程序会出现越界错误。

将标记1处的代码换到标记2处，程序依然可以正确输出结果。

如果将L和R的初始值变成0和s.length()-1，对程序没有任何影响。

当输入是"ccf_csp_2022"时程序不能正确输出结果，因为其中包含了特殊字符。

*/