#pragma once
#include "SortedBag.h"


class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(SortedBag& b);


    TElem *array;
    int index=0;
    int size;

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

