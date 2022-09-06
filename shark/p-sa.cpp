#include <bits/stdc++.h>
using namespace std;

#ifdef SHARK
#define BOLDGREEN "\033[1m\033[32m"
#define debug(...) cout << BOLDGREEN <<  "[DEBUG] " << __LINE__ << ": " << __VA_ARGS__ << endl;
#define v(x) #x << "(" << x << ") "
#else
#define debug(...)
#define v(x)
#endif

#define MP(a, b) make_pair(a, b)

typedef long long ll;
template<class T> inline bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T b) { if (a>b) { a=b; return 1; } return 0; }
typedef pair<int, int>  PII;
typedef pair<ll, ll>    PLL;
typedef map<int, ll>    MIL;
typedef map<string, ll> MSL;

template <typename T> using Max_Q = priority_queue<T, vector<T>, less<T> >;
template <typename T> using Min_Q = priority_queue<T, vector<T>, greater<T> >;


const int MOD     = 1e9+7;
const int INF     = 0x3f3f3f3f;
const ll  LLINF   = 0x3f3f3f3f3f3f3f3f;
const int MAXN    = 500005;
const int MAXM    = 2000005;

ll a[MAXN], b[MAXN], vis[MAXN];
int n, m;

int main(){

    return 0;
}

