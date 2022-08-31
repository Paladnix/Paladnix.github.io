
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b; 
    cin >> a >> b;
    int t = gcd(a, b);
    a /= t;
    b /= t;
    cout << a << ' ' << b << endl;
    return 0;
}

/*
输入 24 92, 输出：

输出的结果中，a可能大于b。

*/
