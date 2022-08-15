#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
int a[MAX_N+5], n;

int handle(int x) {
    int L = 0, R = n-1, ret = -1;
    while(L <= R) {
        int mid = L + R >> 1;   // 标记1
        if(a[mid] <= x) {
            ret = mid;
            L = mid + 1;   
        } else {
            R = mid - 1;
        }
    }
    return ret + 1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i] += a[i-1];
    
    int x; cin >> x;
    cout << handle(x) << endl;
    return 0;
}

/**
 
handle 函数的复杂度是

当a数组中存在负数时，handle函数能会死循环。

当输入是 "10 10 9 8 7 6 5 4 3 2 1 40"时，程序输出"6"

当输入的数字$a_i$都在int范围内且都是正数时，a数组是递增的。

当输入的数字超出int范围时，handle函数可能会出现越界错误。

标记1处的代码，将会先执行右移运算后执行加法运算。
 */