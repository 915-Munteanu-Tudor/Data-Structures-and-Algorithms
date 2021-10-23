#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
#include <bits/stdc++.h>

TComp *newArray;
using namespace std;

SortedBag::SortedBag(Relation r) {
    if (this->capacity <= 0){
        throw exception();
    }
    this->relation=r;
    this->capacity= 2;
    this->nrElements=0;
    this->elements= new TComp [this->capacity];
    //AC=BC=WC=THETA(1)

}

void SortedBag::resize() {
    if (this->capacity <= this->nrElements) {
        newArray = new TComp[this->nrElements * 2];
        for (int i = 0; i < this->nrElements; i++)
            newArray[i] = this->elements[i];
        delete[] this->elements;
        this->elements = newArray;
        this->capacity = 2 * this->nrElements;
    }
    //AC=BC=WC=THETA(this->nrElems)
}

void SortedBag::add(TComp e){

    resize();
    int index = 0;
    if (this->nrElements !=0){
        for(index=this->nrElements; !this->relation(this->elements[index - 1], e); --index) {
            this->elements[index] = this->elements[index - 1];
            if (index == 1) {
                index = 0;
                break;
            }
        }
    }
    this->elements[index] = e;
    this->nrElements++;
    //BC=THETA(1) when the added number is the greatest or the dynamic array is empty or doesn't need a resize
    //WC= =THETA(this->nrElems) when we resize the container and/or add the smallest number
    //AC=THETA(n) n*(n+1)/n - aprox n
    //Total complexity is O(this.nrElems)

}

void SortedBag::addOccurrences(int nr, TComp elem){
    int index=0;
    if (nr < 0){
        throw std::runtime_error("negative");
    }
    this->nrElements=this->nrElements+nr;
    resize();
    if (this->nrElements !=0){
        for(index=this->nrElements; !this->relation(this->elements[index - 1], elem); --index) {
            this->elements[index] = this->elements[index - 1];
            if (index == 1) {
                index = 0;
                break;
            }
        }
    }
    for (int i = index; i < index + nrElements; i++) {
        this->elements[index] = elem;
    }

}

int SortedBag::removeOccurrences(int nr, TComp elem){
    if (nr < 0){
        throw std::runtime_error("negative");
    }
    int found=0;
    int contor=0;
    int app=0;
    for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i] == elem){
            found=1;
            contor=i;
            //app++;
            break;
        }
    }
    if (found == 1){
        while (this->elements[contor] == elem){
            contor++;
            app++;
        }

    }

    if (nr > app){
        for (int j = contor-app+1; j < this->nrElements-app ; j++) {
            this->elements[j] = this->elements[j+app];
        }
        this->nrElements=this->nrElements-app;
        return app;
    }
    else{
        for (int j = contor-nr+1; j < this->nrElements-nr ; j++) {
            this->elements[j] = this->elements[j+nr];
        }
        this->nrElements= this->nrElements-nr;
        return nr;
    }
    //BC=THETA(1) WHEN NR<=0
    //WC=AC=THETA(NR.ELEMS)
    //Total complexity O(n)

}

bool SortedBag::remove(TComp e) {
    int ok=0;
    //deletes a specific element from the array
    for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i] == e){
            for (int j = i; j < this->nrElements-1 ; j++) {
                this->elements[j] = this->elements[j+1];
            }
            ok=1;
            this->nrElements--;
            break;
        }
    }
    if (ok==1){
        return true;
    }
    else
        return false;
    //BC=WC=AC=THETA(this->nrElems) whichever would be the searched elem to be removed there are executed n or n-1 steps
}


bool SortedBag::search(TComp elem) const {
    int ok=0;
    for (int i = 0; i < nrElements; i++) {
        if (this->elements[i] == elem){
            ok=1;
            break;
        }
    }
    if (ok == 0)
	    return false;
    else
        return true;
    //BC=THETA(1) when the first element is the searched one
    //WC=Theta(n) when the last element is the searched one
    //AC=Theta(n) n*(n+1)/n
    //Total complexity is O(n)
}


int SortedBag::nrOccurrences(TComp elem) const {
    int contor=0;
    for (int i = 0; i < this->nrElements; i++) {
        if(this->elements[i] == elem)
            contor++;
    }
	return contor;
    //BC=WC=AC=THETA(this->nrElements) because the dynamic array is always parsed to it's last element
}



int SortedBag::size() const {
    return this->nrElements;
    //BC=WC=AC=THETA(1)
}


bool SortedBag::isEmpty() const {
    if (this->nrElements >0)
	    return false;
    else
        return true;
    //BC=WC=AC=THETA(1)
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
    //BC=WC=AC=THETA(this.nrElems)
}


SortedBag::~SortedBag() {
	delete[] this->elements;
    //BC=WC=AC=THETA(1)
}
