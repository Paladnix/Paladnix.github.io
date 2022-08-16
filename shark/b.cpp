#include <bits/stdc++.h>
using namespace std;

#define BOLDGREEN "\033[1m\033[32m"
template <typename T>
void debug_(T a ...) {
    cout << BOLDGREEN <<  "[DEBUG] " << __LINE__ << " 行: ";
    cout << a << endl;    
}

#ifdef SHARK
#define debug(...) \
#define v(x) #x << "(" << x << ") "
#else
#define debug(...)
#define v(x)
#endif

#define MP(a, b) make_pair(a, b);

typedef long long ll;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> using Max_Q = priority_queue<T, vector<T>, less<T>>;
template <typename T> using Min_Q = priority_queue<T, vector<T>, greater<T>>;

const int MOD     = 1e9+7;
const int INF     = 0x3f3f3f3f;
const ll  LLINF   = 0x3f3f3f3f3f3f3f3f;
const int MAXN    = 500005;
const int MAXM    = 2000005;

ll a[MAXN], b[MAXN], vis[MAXN];
int n, m;

int main(){
    
    int T; cin >> T; while (T--) {
        int a = 3, b = 5;

        debug(a);
        debug(v(a) << v(b));
    }
    return 0;
}

