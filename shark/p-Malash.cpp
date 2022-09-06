#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXM = 10000;

struct Node {
    int v, w, nxt;
    Node(){}

    Node(int v, int w, int nxt):v(v), w(w), nxt(nxt){}
}G[MAXM << 1];

int head[MAXN+1], tot = 0;
int deg[MAXN+1], dp[MAXN+1];

void init() {
    memset(head, 0xff, sizeof(head));
    tot = 0;
}

void add(int u, int v, int w) {
    G[tot] = Node(v, w, head[u]);
    head[u] = tot++;
}


int LongestPath(int n) {
    queue<int> Q;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) Q.push(i), cnt++;
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].v;
            dp[v] = max(dp[v], dp[u] + G[i].w);
            deg[v] --;
            if(deg[v] == 0) {
                Q.push(v);
                cnt++;
            }
        }
    }
    if(cnt == n) return 1;
    else return 0;
}

int main(){
    init();
    int n, m;
    cin >> n >> m;

    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        deg[v]++;
    }
    
    int ret = LongestPath(n);
    if(ret) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    } else {
        cout << "Not DAG." << endl;
    }

    return 0;
}

