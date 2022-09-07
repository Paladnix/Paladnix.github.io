#include <bits/stdc++.h>
using namespace std;

string Manachar(string s) {
	string t = "$#";
	for(int i=0; i < s.size(); ++i) t+=s[i], t+='#';

	vector<int> p(t.size(),0);

	int mx = 0, id = 0, resLen = 0, resCenter = 0;
	for(int i = 1; i < t.size(); ++i) {
		p[i] = mx > i ? min( p[2*id-i] , mx-i ) : 1 ;
		while( t[i+p[i]] ) ++p[i];x
		if( mx < i+p[i] ) {
			mx = i+p[i];
			id = i;
		}
		if( resLen < p[i] ) {
			resLen = p[i];
			resCenter = i;
		}
	}
	return s.substr( (resCenter-resLen)/2 , resLen-1 );
} 

int main(){
    string s;
    cin >> s;
    cout << Manachar(s) << endl;

    return 0;
}


/* 

第4行参数s和主函数中声明的s指向内存中相同的一段地址。

变量p存储在内存的堆空间中。

输出的字符串长度一定大于等于3


Manachar 算法的复杂度是

$O(n)$
$O(nlogn)$
$O(n^2)$
$O(n\sqrt(n))$

输入"manachar" 输出的结果是？

输入"ccfcfc cfc" 输出的结果是？



