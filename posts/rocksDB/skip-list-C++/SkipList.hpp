#pragma once

#include <iostream>
#include "Node.hpp"


template<typename K, typename V>
class SkipList {
public:

    SkipList();
    SkipList(int max_level);
    ~SkipList();

    bool    insert(const K &key, const V &value);
    Node<K, V>* find(const K &key);
    bool    remove(const K &key);

private: 
    int randomLevel();

private:    
    int         _MAX_LEVEL;          // Max level of index
    Node<K, V>* _root;               // head of top level
    int         _size;               // count of the value node
    std::mt19937 _rng;
    std::uniform_int_distribution<> _uni_int;
};


template<typename K, typename V>
SkipList<K, V>::SkipList() {
    SkipList(16);
    _rng = *(new std::mt19937(std::random_device{}()));
    _uni_int = *(new std::uniform_int_distribution<>(1, 2));
}

template<typename K, typename V>
SkipList<K, V>::SkipList(int max_level) {
    _MAX_LEVEL = max_level;
    _root = new Node<K, V>();
    Node<K, V>* cur = _root;
    for(int i = _MAX_LEVEL - 1; i >= 0; i--) {
        cur->setDown(new Node<K, V>());
        cur = cur->getDown();
    }
    _size = 0;
}

template<typename K, typename V>
SkipList<K, V>::~SkipList() {
    Node<K, V>* cur = _root->getDown();
    for(int i = _MAX_LEVEL - 1; i >= 0; i--) {
        Node<K, V>* head = cur->getNext();
        while(head != nullptr) {
            Node<K, V>* tmp = head;
            head = head->getNext();
            tmp->~Node();
        }
        head = cur;
        cur = cur->getDown();
        head->~Node();
    }

}

template<typename K, typename V>
Node<K, V>* SkipList<K, V>::find(const K &key) {
    #ifdef DEBUG
        std::cout << "find" << std::endl;
    #endif

    Node<K, V>* slow = _root->getDown();
    Node<K, V>* fast = slow->getNext();

    for(int i = _MAX_LEVEL - 1; i >= 0; i--) {
        while(fast != nullptr && *(fast->getKey()) < key) {
            slow = fast;
            fast = fast->getNext();
        }
        if(fast != nullptr && *(fast->getKey()) == key) {
            return fast;
        }
        if(slow != nullptr) {
            slow = slow->getDown();
        }
        if(slow != nullptr) {
            fast = slow->getNext();
        }
    }
    return nullptr;
}


template<typename K, typename V>
bool SkipList<K, V>::insert(const K &key, const V &value) {
    #ifdef DEBUG
        std::cout << "insert" << std::endl;
    #endif
    
    // 创建一个value的拷贝
    K* key_ = (K*)malloc(sizeof(K));
    V* value_ = (V*)malloc(sizeof(V));
    *key_ = key;
    *value_ = value;

    // 获取随机层级
    int level = randomLevel();
    // 查找并插入
    Node<K, V>* slow = _root->getDown();
    Node<K, V>* fast = slow->getNext();
    Node<K, V>* upLevelNode = nullptr;
    for(int i = _MAX_LEVEL - 1; i >= 0; i--) {
        while(fast != nullptr && *fast->getKey() < key) {
            slow = fast;
            fast = fast->getNext();
        }

        if(fast != nullptr && *fast->getKey() == key) {
            // 直接修改value即可， 不需要插入
            // 释放原本的value
            free(fast->getValue());
            free(key_);
            fast->setValue(value_);
            while((fast = fast->getDown()) != nullptr) {
                fast->setValue(value_);
            }
            return true;
        }
        if (i <= level) {
            // 新建一个Node
            Node<K, V>* newNode = new Node<K, V>(key_, value_);
            newNode->setNext(fast);
            if (upLevelNode != nullptr) {
                upLevelNode->setDown(newNode);
            }
            upLevelNode = newNode;
        }
        if(slow != nullptr) {
            slow = slow->getDown();
        }
        if(slow != nullptr) {
            fast = slow->getNext();
        }
    }
    return true;   
}

template<typename K, typename V>
bool SkipList<K, V>::remove(const K &key) {
    #ifdef DEBUG
        std::cout << "remove" << std::endl;
    #endif

    Node<K, V>* slow = _root->getDown();
    Node<K, V>* fast = slow->getNext();

    for(int i = _MAX_LEVEL - 1; i >= 0; i--) {
        while(fast != nullptr && *(fast->getKey()) < key) {
            slow = fast;
            fast = fast->getNext();
        }
        if(fast != nullptr && *(fast->getKey()) == key) {
            // 删除key 和 value对象
            slow->setNext(fast->getNext());
            free(fast->getKey());
            free(fast->getValue());
            Node<K, V>* down;
            while(fast != nullptr) {
                down = fast->getDown();
                fast->~Node();
                fast = down;
            } 
            return true;
        }
        if(slow != nullptr) {
            slow = slow->getDown();
        }
        if(slow != nullptr) {
            fast = slow->getNext();
        }
    }
    return true;
}

template<typename K, typename V>
int SkipList<K, V>::randomLevel() {
    int level = 1;
    while(_uni_int(_rng) == 2 && level < _MAX_LEVEL - 1) {
        level ++;
    }
    return level;
}

