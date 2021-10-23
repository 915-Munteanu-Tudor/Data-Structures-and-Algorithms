#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->current = 0;
    //BC=WC=AC=THETA(1)
}

TComp SortedBagIterator::getCurrent() const {
    if (!this->valid())
        throw exception();
    return this->bag.elements[current];
    //BC=WC=AC=THETA(1)
}

bool SortedBagIterator::valid() const {
    if (this->current < this->bag.nrElements)
        return true;
    return false;
    //BC=WC=AC=THETA(1)
}

void SortedBagIterator::next() {
    if (this->valid())
        this->current++;
    else
        throw exception();
    //BC=WC=AC=THETA(1)
}

void SortedBagIterator::first() {
	this->current = 0;
    //BC=WC=AC=THETA(1)
}

