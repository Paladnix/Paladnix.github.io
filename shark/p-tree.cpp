/*
 * 以下代码模拟了n个节点所能构成的所有不同形态二叉树的数量。
 */

#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;

int ans = 0, dp[MAXN], t = 0;

int build(int n) {
    t ++;
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != 0) return dp[n]; // 标记1
    int cnt = 2*build(n - 1);
    for(int i = 1; i < n-1; i++) {
        cnt += build(i) * build(n - i-1);
    }
    dp[n] = cnt;  // 标记2
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << build(n) << endl;
    cout << t << endl;
    return 0;
}


/*

build 算法的复杂度是 

去掉标记1和标记2处的代码，程序的结果不受影响，但是复杂度将会变大。

去掉标记1和标记2处的代码，复杂度是（）级别

输入n=5，结果是多少？

输入n=4，结果是多少？


*/