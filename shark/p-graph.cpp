#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int vis[MAXN];
int n, m;

vector<int> G[MAXN];

queue<int> Q;
bool handle(int s) {
    while(!Q.empty()) Q.pop(); // 标记1
    Q.push(s);
    vis[s] = 1;    // 标记2
    while(!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(vis[v] == vis[u]) return true;
            if(____(1)____) continue;
            vis[v] = 1 - vis[u];  // 标记3
            Q.push(v);
        }
    }
    return false;
}

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    _____(2)_____
    bool flag = false;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == -1) {
            if(handle(i)) {
                flag = true;
                break;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}

/*

   1. (多选题) 以下选项不能写入（1）处的代码是

   !vis[v]
   ~vis[v]
   1-vis[v]
   1+vis[v]



   2. (2)处的代码是
   memset(vis, 0, sizeof(vis));
   memset(vis, 1, sizeof(vis));
   memset(vis, 0x3f, sizeof(vis));
   memset(vis, -1, sizeof(vis));


   3. 标记1处的代码可有可无

   4. 如果将标记2处的代码改为`vis[i] = 0;` 并不影响程序的结果。

   5. 以下代码同样可以作为标记3处右值的是
   vis[u] ^ vis[v]
   vis[u] ^ 1
   vis[u] ^ 0

   6. 程序的复杂度是

   7. 上述代码可以用于判断一个图中是否有奇环。

   8. 如果给的数据中$n > m$ 则程序无法正确判断出是否为二分图。


   其他家族的间谍兔子，这些兔子和家族中的两个党派信仰都不相同。请你判断一下这些兔子中是否一定存在间谍兔。
*/
