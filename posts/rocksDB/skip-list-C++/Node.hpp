#pragma once

#include <iostream>

template<typename K, typename V>
class Node {

public:
    Node();

    Node(K* key, V* value);
    ~Node();

    K*          getKey();
    V*          getValue();
    Node<K, V>* getNext();
    Node<K, V>* getDown();

    void setValue(V* value);
    void setNext(Node<K, V>* next);
    void setDown(Node<K, V>* down);


private: 
    Node<K, V>* _down;
    Node<K, V>* _next;
    K*    _key;
    V*    _value;
};

template<typename K, typename V>
Node<K, V>::Node() {
    _next = nullptr;
    _down = nullptr;
    _key  = nullptr;
    _value = nullptr;
}

template<typename K, typename V>
Node<K, V>::Node(K *key, V *value) {
    _next = nullptr;
    _down = nullptr;
    _key = key;
    _value = value;
}

template<typename K, typename V>
Node<K, V>::~Node() {
}

template<typename K, typename V>
K* Node<K, V>::getKey() {
    return _key;
}

template<typename K, typename V>
V* Node<K, V>::getValue() {
    return _value;
}

template<typename K, typename V>
Node<K, V>* Node<K, V>::getNext() {
    return _next;
}

template<typename K, typename V>
Node<K, V>* Node<K, V>::getDown() {
    return _down;
}

template<typename K, typename V>
void Node<K, V>::setValue(V* value) {
    _value = value;
}

template<typename K, typename V>
void Node<K, V>::setNext(Node<K, V>* next) {
     _next = next;
}

template<typename K, typename V>
void Node<K, V>::setDown(Node<K, V>* down) {
    _down = down;
}
