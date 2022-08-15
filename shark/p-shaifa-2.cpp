#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
int vis[MAXN + 5], p[MAXN + 5], pcnt;
int minF[MAXN + 5];

void  handle(int n) {
    for(int i = 2; i <= n; i++) {
        if(vis[i]) continue;
        p[pcnt ++] = i;
        minF[i] = i;
        for(int j = 0; j < pcnt; j++) {
            vis[i*p[j]] = 1;
            minF[i*p[j]] = i;
            if(i % p[j] == 0) break;
        }
    }
}

void print(int m) {
    while(m > 1) {
        cout << minF[m] << ' ';
        m /= minF[m];
    }
}

int main() {
    int n;
    cin >> n;
    handle(n);
    int m;
    cin >> m;
    print(m);
    return 0;
}

/**
 

 handle函数的复杂度是

 当输入的m是34时，输出多少

 print() 函数的最坏复杂度和最优复杂度分别是
 
 */