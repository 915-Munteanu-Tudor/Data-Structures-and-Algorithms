#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cmath>
#include <iostream>
SortedBag::SortedBag(Relation r) {

    for (int i = 0; i < capacity; i++) {
        t[i] = NULL_TCOMP;
    }
    relation=r;
}
//Theta(capacity)

int SortedBag::hashFunction1(TElem e,int i) const
{
    return (hashFunction2(abs(e))+i*hashFunction3(abs(e))) % capacity;
}
//Theta(1)

int  SortedBag::hashFunction2(int k) const {
    return k % capacity;
}
//Theta(1)

int  SortedBag::hashFunction3(int k) const {
    return 1+(k%(capacity - 1));
}
//Theta(1)

void SortedBag::add(TComp e) {
	int i=0;
	int pos=hashFunction1(e,i);
	while (i < capacity and t[pos] != NULL_TCOMP )
    {
	    i++;
	    pos=hashFunction1(e,i);
    }
	if(i == capacity) {
        resize();
        add(e);
    }
	else {

        t[pos] = e;
        elements++;
	}
}
//best case:Theta(1), wc:Theta(n)=> O(n)

int SortedBag::prim(int x){
    int ok=1;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x%i==0){
            ok=0;
            break;
        }
    }
    if (ok ==0)
        return false;
    return true;
}
//best case: theta(1), wc:theta(x) => O(x)

int SortedBag::removeOccurrences(int nr, TComp elem)
{   int i=0;
    int nrRemoved=0;
    int y= nrOccurrences(elem);
    if(nr<0)
        throw std::exception();
    int poz=hashFunction1(elem,i);
    while(i < capacity and nrRemoved < nr)
    {
        if(t[poz]==elem)
        {
            t[poz]=DELETED;
            nrRemoved++;
            if (y == nrRemoved)
                break;
        }
        i++;
        poz=hashFunction1(elem,i);
    }
    elements=elements-nrRemoved;
    return nrRemoved;
}
//bc:Theta(1),wc:theta(capacity)->average O(capacity)

void SortedBag::resize() {
    int old_m=capacity;
    int new_m= capacity + 6;
    while(prim(new_m) == false){
        new_m= new_m+6;
    }
    this->capacity = new_m;
    auto* t_new=new TElem[capacity];
    for(int i=0; i < capacity; i++)
        t_new[i]=NULL_TCOMP;

    for(int i = 0;i<old_m;i++)
    {
        int k=0;
        bool found=false;

        do{
            int h=hashFunction1(t[i],k);
            if(t_new[h]==NULL_TCOMP ) {
                t_new[h] = t[i];
                found=true;
            }
            else ++k;
        } while(k < capacity && !found);
    }


    delete[] t;
    t=t_new;
}
//wc=bc=theta(capacity) => O(capacity)

bool SortedBag::remove(TComp e) {
	int i=0;
	int poz=hashFunction1(e,i);
	while(i < capacity)
    {
	    if(t[poz]==e)
        {
	        t[poz]=DELETED;
	        elements--;
	        return true;
        }
	    i++;
	    poz=hashFunction1(e,i);
    }
	return false;
}
//wc=theta(capacity), bc=theta(1) => O(capacity)

bool SortedBag::search(TComp elem) const {
	int i=0;
	int pos=hashFunction1(elem,i);
	while(i < capacity and t[pos] != NULL_TCOMP and t[pos] != elem)
    {
	    i++;
	    pos=hashFunction1(elem,i);
    }
	if(i < capacity and t[pos] == elem)
	    return true;
	else
	    return false;
}
//wc=theta(capacity), bc=theta(1) => O(capacity)

int SortedBag::nrOccurrences(TComp elem) const{
	int i=0;
	int nr=0;
	int pos=hashFunction1(elem,i);

	while(i < capacity and t[pos] != NULL_TCOMP )
    {
	    if(t[pos]==elem)
	        nr++;
	    i++;
	    pos=hashFunction1(elem,i);
    }

    return nr;
}
//wc=theta(capacity), bc=theta(1) => O(capacity)


int SortedBag::size() const {
	return this->elements;
}
//theta(1)


bool SortedBag::isEmpty() const {
	return elements==0;
}
//theta(1)

SortedBagIterator SortedBag::iterator()  {
	return SortedBagIterator(*this);
}
//theta(1)

SortedBag::~SortedBag() {
	delete[] t;
}
//theta(1)

