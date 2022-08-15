/**
 * 游程编码 (RLE) 是一种简单的无损数据压缩形式，它在具有相同值连续多次出现的序列上运行。它将序列编码为仅存储单个值及其计数。
 */

#include<bits/stdc++.h>

using namespace std;

string int2string(int x) {
    string s = "";
    while(x) {
        s += x % 10 + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

struct LinkListNode {
    char c;
    int cnt;
    LinkListNode* next;

    LinkListNode(){}
    LinkListNode(char c, int cnt): c(c), cnt(cnt){
        next = nullptr;
    }
};

struct LinkedList {
    LinkListNode *head;
    LinkListNode *tail;
    unsigned int size;

    LinkedList(){
        cout << "Create new LinkedList." << endl;
        head = new LinkListNode(0, 0);
        tail = head;
        size = 0;
    }

    ~LinkedList() {
        cout << "Delete LinkedList." << endl;
        while(head->next != nullptr) {
            LinkListNode *tmp = head->next;
            free(head);
            head = tmp;
        }
    }

    void push_back(LinkListNode *a) {
        tail->next = a;
        tail = tail->next;
        size++;
    }

    void encode(const string &s) {
        if(s.length() == 0) return ;
        push_back(new LinkListNode(s[0], 1));
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                tail->cnt ++;
            }
            else {
               push_back(new LinkListNode(s[i], 1)); 
            }
        }
    }

    string getEncodeString() {
        string s = "";
        LinkListNode* t = head;
        while(t->next != nullptr) {
            t = t->next;
            s += t->c;
            s += int2string(t->cnt);
        }
        return s; 
    }

    string decode() {
        string s = "";
        LinkListNode* t = head;
        while(t->next != nullptr) {
            t = t->next;
            s += string(t->cnt, t->c);
        }
        return s;
    }

};



int main() {
    string s;
    cin >> s;
    
    LinkedList *linkedList = new LinkedList();
    linkedList->encode(s);
    string t = linkedList->getEncodeString();    // tag 1
    string s1 = linkedList->decode();            // tag 2

    cout << s << "\n" << t << "\n" << s1 << endl;

    delete(linkedList);
    return 0;
}

/*

当输入数据全是数字的时候，程序没有输出。()

标记1处的字符串t的长度，始终比输入的字符串s长度短。()

当输入一个长度为100的字符串时，t的长度不可能小于4。()

当输入一个长度为100的字符串时，t的长度不可能大于199。()

输入的字符串越长，则压缩后的字符串越短，压缩效率越高。()

输入字符串"JI_KE_CHENG_VERRRRRRRRRRY_WELL" 则输出的字符串t为()

JIKECHENGVERRRRRRRRRRYWELL
J1I1_1K1E1_1C1H1E1N1G1_1V1E1R10Y1_1W1E1L2
JI_KE_CHENG_VERY_WEL
JI_KE_CHENG_VER9Y_WEL1

以下最适合使用游程编码算法来进行压缩的数据是：

- 英文文本
- 拼音文本
- 黑白图片
- 彩色图片

*/

