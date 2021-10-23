#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

using namespace std;



ListIterator::ListIterator(const IteratedList& list) : list(list) {

	this->current = list.head;
    //BC=WC=AC= THETA(1)
}

void ListIterator::first() {

	this->current = list.head;
    //BC=WC=AC= THETA(1)
}

void ListIterator::next() {

	if (this->current == -1){
		throw exception();
	}
	this->current = this->list.nodes[this->current].getNext();
    //BC=WC=AC= THETA(1)

}


bool ListIterator::valid() const {

	if (this->current == -1) {
		return false;
	}
	return  true;
    //BC=WC=AC= THETA(1)
}

TElem ListIterator::getCurrent() const {

	if (this->current == -1) {
		throw exception();
	}
	return this->list.nodes[this->current].getInfo();
    //BC=WC=AC= THETA(1)
}

const IteratedList &ListIterator::getList() const {
    return list;
}



