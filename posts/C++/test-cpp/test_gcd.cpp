#include<bits/stdc++.h>
#include<numeric>
#include <sys/time.h>


using namespace std;
typedef long long ll;


inline int mygcd(int a, int b) {
    return b == 0? a: mygcd(b, a %b);
}

int main() {
    srand((int)time(0));
    struct timeval start;
    struct timeval end;
    int MAXN = 1000000;
    ll sum = 0;
    gettimeofday(&start,NULL);
    for(int i = 0; i < MAXN; i++) {
        int a = rand() % 1000000;
        int b = rand() % 1000000;
        sum += gcd(a, b);        
    }
    gettimeofday(&end,NULL);
    double time_use_gcd=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec); //微秒
    time_use_gcd /= 1000;

    printf("%lld, time_use_gcd is %.2lf ms\n",sum, time_use_gcd);

    gettimeofday(&start,NULL);
    for(int i = 0; i < MAXN; i++) {
        int a = rand() % 1000000;
        int b = rand() % 1000000;
        sum += mygcd(a, b);        
    }
    gettimeofday(&end,NULL);
    double time_use_mygcd=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec); //微秒
    time_use_mygcd /= 1000;
    printf("%lld, time_use_mygcd is %.2lf ms\n",sum, time_use_mygcd);


    return 0;
}