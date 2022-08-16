#include<bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, r;
    Node(){}
    Node(int x, int y, int r):x(x), y(y), r(r){}
};

bool check_intersect(Node a, Node b) {
    double len = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if(len - (a.r + b.r) > 0) return false;
    if(b.r - len - a.r > 0) return false;
    if(a.r - len - b.r > 0) return false;
    return true;
}

int main() {
    Node c1, c2;
    cin >> c1.x >> c1.y >> c1.r;
    cin >> c2.x >> c2.y >> c2.r;
    if(check_intersect(c1, c2)) {
        cout << "Happy CSP2022!" << endl;
    } else  {
        cout << "You see see you, One day day de." << endl;
    }
    return 0;
}
