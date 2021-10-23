#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	Node *n = bag.root;
    while (n != nullptr) {
        this->stack.push(n);
        n = n->left;
    }
    if (this->stack.empty())
        this->current = nullptr;
    else
        this->current = this->stack.top();
}
// Best case: Theta(1) height of the tree is 1
// Worst case: Theta(h) h being the height of the tree
// Total => O(h)

TComp SortedBagIterator::getCurrent() {
    if (this->current == nullptr)
        throw exception();
    return this->current->info;
}
// Theta(1)

bool SortedBagIterator::valid() {
	if (this->current == nullptr)
        return false;
    return true;
}
// Theta(1)

void SortedBagIterator::next() {
    if (this->current == nullptr)
        throw exception();

    Node *n = this->stack.top();
    this->stack.pop();
    if (n->right != nullptr){
        n = n->right;
        while (n != nullptr) {
            this->stack.push(n);
            n = n->left;
        }
    }
    if (this->stack.empty())
        this->current = nullptr;
    else
        this->current = this->stack.top();

}
// best case : Theta(1) we iterate through identical elements
//worst case complexity Theta(n) n being the nr of nodes
// total O(n)

void SortedBagIterator::first() {
    while (!this->stack.empty())
        this->stack.pop();

    Node *n = bag.root;
    while (n != nullptr) {
        this->stack.push(n);
        n = n->left;
    }
    if (this->stack.empty())
        this->current = nullptr;
    else
        this->current = this->stack.top();
}
// Best case: Theta(1) height of the tree is 1
// Worst case: Theta(h) h being the height of the tree
// Total => O(h)

