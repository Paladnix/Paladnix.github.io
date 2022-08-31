
#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 1e5+5;
int a[MAX_N+5];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for(int i = 2; i <= n; i++) if(a[i] < a[i-1]) flag = false;
    if(!flag) {
        sort(a+1, a + n + 1);   // 标记1
    }
    int m = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[m]) {
            a[++m] = a[i];
        }
    }
    // 标记2
    for(int i = 1; i <= m; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}


/**
 
 代码中的排序函数(标记1)是对a数组从a[1] 开始到a[n+1] 位置共n+1个数字升序排序。

 如果输入的是一个升序序列，那么输出的序列将和输入一致。

 如果输入的序列中不包含相同的数字，那么输出的序列将和输入一致。

 输入"5 4 5 4 2 3", 则输出的结果是"2 3 4 5"

 上述代码的最优复杂度和最坏复杂度分别是

 程序运行到标记2时，a数组中从a[1]~a[n] 的数字是非降序的。

 */
























