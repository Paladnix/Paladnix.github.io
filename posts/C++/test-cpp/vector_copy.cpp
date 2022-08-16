/**
 *  验证vector pus_back 使用的是默认拷贝函数，即浅拷贝。
 * 
 */

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    Node *nxt;
    
    Node(){}
    Node(int _x) {
        x = _x;
        nxt = nullptr;
    }
    Node(int x, Node *nxt): x(x), nxt(nxt) {}

};

vector<Node> A;

int main() {
    {
        Node x1(5);
        Node x2(4, &x1);
        Node x3(3, &x2);
        A.push_back(x1);
        A.push_back(x2);
        A.push_back(x3);
        for(auto it : A) {
            cout << it.nxt << endl;
        }
    }
    for(auto it : A) {
        cout << it.nxt << endl;
    }
    cout << A[2].nxt->x << endl;
    return 0;
}