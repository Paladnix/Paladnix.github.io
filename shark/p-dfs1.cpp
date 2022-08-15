#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int a[maxn], n;
int quick_select(int L, int R, int k) {
    int pivot = a[L];
    int i = L, j = R;
    while(i < j) {
        while(i < j && a[j] >= pivot) j--;
        if(i < j) {
            a[i] = a[j];
            i++;
        }
        while(i < j && a[i] < pivot) i++;
        if(i < j) {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = pivot;
    int left = i - L + 1;
    if(left == k) return a[i];
    if(left < k) return quick_select(i+1, R, k - left);
    else return quick_select(L, i-1, k);
}

int main() {
    cin >> n;
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << quick_select(1, n, k) << endl;
    return 0;
}
