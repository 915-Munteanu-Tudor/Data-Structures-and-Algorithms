#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>
#include <algorithm>

using namespace std;


MultiMap::MultiMap() : head{nullptr}, tail{nullptr}, length{0} {

}


void MultiMap::add(TKey c, TValue v) {
    auto *newNode = new Node();
    newNode->value.first = c;
    newNode->value.second = v;
    newNode->next = nullptr;
    newNode->previous = tail;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    this->length++;
}
//BC=WC=AC= THETA(1)


bool MultiMap::remove(TKey c, TValue v) {
    auto *currentNode = head;
    while (currentNode != nullptr and currentNode->value != std::make_pair(c,v)) {
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
        return false;
    if (currentNode == head) {

        if (currentNode == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->previous = nullptr;
        }
    }
    else if (currentNode == tail) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        currentNode->next->previous = currentNode->previous;
        currentNode->previous->next = currentNode->next;
    }
    delete currentNode;
    this->length--;
    return true;
}
//BC=THETA(1) WHEN THE ELEMENT TO BE REMOVED IS THE FIRST IN THE LIST
//WC=THETA(NR ELEMS) WHEN THE ELEMENT TO BE REMOVED IS THE LAST IN THE LIST
//AC=THETA(N)
//TOTAL COMPLEXITY IS O(NR ELEMS)


//TElem MultiMap::removeExtra(TElem) {
//    if (this.)
//}

vector<TValue> MultiMap::search(TKey c) const {
    auto v = vector<TValue>();
    auto currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->value.first == c)
            v.push_back(currentNode->value.second);
        currentNode = currentNode->next;
    }
    return v;
}
//BC=WC=AC= THETA(NR KEYS)


int MultiMap::size() const {
    return this->length;
}
//BC=WC=AC= THETA(1)

bool MultiMap::isEmpty() const {
    if (this->length == 0)
        return true;
    else
        return false;
}
//BC=WC=AC= THETA(1)

MultiMapIterator MultiMap::iterator() {
    return MultiMapIterator(*this);
}
//BC=WC=AC= THETA(1)


MultiMap::~MultiMap() = default;
//BC=WC=AC= THETA(1)

