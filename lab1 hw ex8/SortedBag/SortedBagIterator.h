#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	explicit SortedBagIterator(const SortedBag& b);
	int current;

public:
	TComp getCurrent() const;
	bool valid() const;
	void next();
	void first();
};

