
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
        sort(a+1, a + n + 1);
    }
    int m = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[m]) {
            a[++m] = a[i];
        }
    }
    cout << m << endl;
    for(int i = 1; i <= m; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}