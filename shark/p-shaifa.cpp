#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
int vis[MAXN + 5], p[MAXN], pcnt;
vector<int> X[MAXN];

void  handle(int n) {
    for(int i = 2; i <= n; i++) {
        if(vis[i]) continue;  // 标记1
        if(!vis[i]) {
            p[pcnt ++] = i;
            X[i].push_back(i);
        }
        for(int j = i+i; j <= n; j+=i) {
            vis[j] = 1;
            X[j].push_back(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    handle(n);
    int m;
    cin >> m;
    cout << X[m].size() << endl;
    for(int x: X[m]) cout << x << endl;
    return 0;
}

/* 

handle算法的复杂度是多少？

- $n*n$
- $n\sqrt{n}$
- $nln(n)$
- $2*n$

(提高组) 在删除标记1处的代码 复杂度是。

当输入m等于2022时，输出是多少？

删除标记1处的代码，输入2022时，输出时多少？


*/