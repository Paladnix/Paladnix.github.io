#include<iostream>
#include<string>
using namespace std;

void multi(int *a,int *b,int *c,int an,int bn,int &cn){ 
    for(int i = ____(1)____; i >= 0; i--) {                  
        int weight=0;
        for(int j= __(2)___; j >= 0; j--) {
            int p = ___(3)____;
            int q = ___(4)____;
            int tmp=(c[p+q]+a[i]*b[j] + weight)/10;
            ___(5)___ =(c[p+q]+a[i]*b[j] + weight)%10;
            weight=tmp;
        }
        if(weight){
            c[_____(6)______] = weight; 
            cn = an - i + bn;
        }
    }
}

int a[100], b[100], c[10005];

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    for(int i = 0; i < str1.size(); i++) a[i] = str1[i] - '0';
    for(int i = 0; i < str2.size(); i++) b[i] = str2[i] - '0';
    int len = 0;
    multi(a,b,c, str1.size(), str2.size(), len);
    for(int i = len-1; i >=0 ; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}