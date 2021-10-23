#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP (-11111)
#define DELETED (-22222)

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;

private:
	int capacity=17;
    TComp* t=new TElem[capacity];
	Relation relation;
	int elements=0;


public:
	//constructor
	SortedBag(Relation r);

    int hashFunction3(int k) const;
    int hashFunction2(int k) const;
	int hashFunction1(TElem e, int i)const;
	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an eleent was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() ;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();


    void resize();

    static int prim(int x);

    int removeOccurrences(int nr, TComp elem);
};