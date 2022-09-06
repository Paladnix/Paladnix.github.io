#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXM = 1e4;

struct Node {
    int v, w, nxt;
    Node(){}

    Node(int v, int w, int nxt):v(v), w(w), nxt(nxt){}
}G[MAXM << 1];

int head[MAXN+5], tot = 0;

void init() {
    memset(head, 0xff, sizeof(head));
    tot = 0;
}

void add(int u, int v, int w) {
    G[tot] = Node(v, w, head[u]);
    head[u] = tot++;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    
    


    return 0;
}

