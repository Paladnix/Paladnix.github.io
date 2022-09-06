#include <bits/stdc++.h>
using namespace std;

ll a[MAXN], b[MAXN], c[MAXN];
int n, m;

bool check(double x) {
    for(int i = 1; i <= n; i++) {
        b[i] = a[i] - x;
        c[i] = c[i-1] + b[i];
    }

    for(int i = 1; i <= m; i++) dp[m] += b[i];
    if(dp[m] >= 0) return true;
    for(int i = m+1; i <= n; i++) {
        dp[i] = max(b[i] + dp[i-1], c[i] - c[i-m]);
        if(dp[i] >= 0) return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    double L = 0, R = 1e18;
    while(abs(L-R) >= 1e-8) {
        double mid = (L+R) / 2;
        if(check(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    
    cout << L << endl;

    return 0;
}

