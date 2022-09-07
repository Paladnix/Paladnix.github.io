#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN], b[MAXN], c[MAXN];
int n, m, T;

int solve() {
    for(int i = 1; i <= n; i++) {
        b[a[i]] ++;
        T = max(T, a[i]);
    }
    for(int i = 1; i <= T; i++) b[i] += b[i-1];
    for(int i = n; i >= 1; i--) {
        c[i] = b[a[i]]--;
    }
    return c[m];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cout << solve() << endl;
    return 0;
}


/*
当输入的数字均不超过100000时。回答下列问题。

MAXN 最小可以赋值为100001才不会出现越界错误。

输出的结果可能是负数

b数组是int类型，存在数据溢出风险，需要设为long long类型。


当输入“7 4 9 2 1 2 3 1 5”时，输出

当输入n=10，m=3时。下列输出的结果最大的是

1,2,2,4,3,9,1,2,8,10
1,1,1,1,1,1,1,1,1,1
8 0 9 1 4 2 4 2 2 3
2 4 2 2 4 8 0 9 1 4





*/
