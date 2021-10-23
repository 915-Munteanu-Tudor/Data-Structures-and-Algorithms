#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <iostream>

using namespace std;

SortedBagIterator::SortedBagIterator(SortedBag& b) : bag(b) {
    array=new TElem[b.capacity];
	size=0;

	for(int i=0;i< b.capacity; i++)
	    if(b.t[i]!=NULL_TCOMP) {
            array[size] = b.t[i];
            size++;

	    }

	for(int i=0;i<size-1;i++) {

        for (int j = i + 1; j < size; j++)
        {
            if (!b.relation(array[i], array[j])) {
                TComp aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
	}


	index=0;

}

//wc=bc=theta(capacity) =>O(m)


TComp SortedBagIterator::getCurrent() {
	if(!valid())
	    throw std::exception();
	return array[index];
}
//theta(1)

bool SortedBagIterator::valid() {
	return index<size;

}
//theta(1)

void SortedBagIterator::next() {
    if(!valid())
        throw std::exception();
   index++;
}
//theta(1)

void SortedBagIterator::first() {
    index=0;
}
//theta(1)

