#include <bits/stdc++.h>
#include <sys/time.h>
#include <numeric>
#include "SkipList.hpp"

using namespace std;

const int MAXN = 1e6;
int KV[MAXN][2];
void init_KV() {
    srand((int)time(0));
    for(int i = 0; i < MAXN; i++) {
        KV[i][0] = rand() % 1000000;
        KV[i][1] = rand() % 1000000;
    }
}

map<int, int> M;    
void test_map_Speed() {
    struct timeval start;
    struct timeval end;
    gettimeofday(&start,NULL);
    for(int i = 0; i < MAXN; i++) {
        M[KV[i][0]] = KV[i][1];
    }
    gettimeofday(&end,NULL);
    double time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec); //微秒
    time_use /= 1000;
    printf("time_use_map is %.2lf ms\n", time_use);

}

SkipList<int, int> skipList(25);
void test_SkipList_Speed() {

    struct timeval start;
    struct timeval end;
    gettimeofday(&start,NULL);
    for(int i = 0; i < MAXN; i++) {
        skipList.insert(KV[i][0], KV[i][1]);
    }
    gettimeofday(&end,NULL);
    double time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec); //微秒
    time_use /= 1000;
    printf("time_use_skiplist is %.2lf ms\n", time_use);

}

void base_test() {

    SkipList<int, int> skipList(6);

    std::cout << "Start Test" << std::endl;
    skipList.insert(5, 1);
    Node<int, int>* res = skipList.find(2);
    if(res != nullptr) {
        std::cout << res->getKey() << " " << res->getValue() << std::endl;
    } else {
        std::cout << "Not found key of 2" << std::endl;
    }
    res = skipList.find(5);
    if(res != nullptr) {
        std::cout << *res->getKey() << " " << *res->getValue() << std::endl;
    } else {
        std::cout << "Not found key of 5" << std::endl;
    }
    skipList.remove(5);
}

int main() {
    init_KV();
    // test_map_Speed();
    test_SkipList_Speed();
    return 0;
}