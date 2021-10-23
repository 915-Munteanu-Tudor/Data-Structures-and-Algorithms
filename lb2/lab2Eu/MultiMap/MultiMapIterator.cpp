#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(MultiMap &c) : col(c) {

    this->current = c.head;

}
//BC=WC=AC= THETA(1)

TElem MultiMapIterator::getCurrent() const {

    if (this->valid())
        return this->current->value;
    else {
        throw std::exception();
    }
}
//BC=WC=AC= THETA(1)

bool MultiMapIterator::valid() const {

    return this->current != nullptr;
}
//BC=WC=AC= THETA(1)

void MultiMapIterator::next() {
    if (this->valid())
        this->current = this->current->next;
    else {
        throw std::exception();
    }
}
//BC=WC=AC= THETA(1)

void MultiMapIterator::first() {

    this->current = this->col.head;
}
//BC=WC=AC= THETA(1)

TElem MultiMapIterator::remove() {
    if (!this->valid()) {
        throw std::exception();
    }
    auto copy = this->current->value;
    auto eq = this->current->next;
    this->col.remove(this->current->value.first, this->current->value.second);
    this->current = eq;
    return copy;
}
//BC=THETA(1) WHEN THE ELEMENT TO BE REMOVED IS THE FIRST IN THE LIST
//WC=THETA(NR ELEMS) WHEN THE ELEMENT TO BE REMOVED IS THE LAST IN THE LIST
//AC=THETA(N)
//TOTAL COMPLEXITY IS O(NR ELEMS)

