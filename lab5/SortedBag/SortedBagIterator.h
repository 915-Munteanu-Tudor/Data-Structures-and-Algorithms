#pragma once
#include "SortedBag.h"
#include <stack>

using namespace std;

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
    Node* current;
    stack<Node*> stack;
    //int current_freq;

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

