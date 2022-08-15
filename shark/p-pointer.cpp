#include<bits/stdc++.h>
using namespace std;


struct Node {

    int x;
    Node *next;

    Node() { next = nullptr; }
    Node(int x):x(x){ next = nullptr; }
    Node(int x, Node *next):x(x), next(next) {}
};

bool check_ring(Node *head) {
    
    Node *slow = head;
    Node *fast = head;
    while(1) {
        if(fast->next == nullptr) return false;
        fast = fast->next->next;
        if(fast == nullptr) return false;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}


int main() {
    Node *head = new Node();
    int n;
    cin >> n;
    return 0;
}
