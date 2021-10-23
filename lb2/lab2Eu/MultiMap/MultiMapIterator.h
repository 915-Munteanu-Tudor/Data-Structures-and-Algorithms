#pragma once

#include "MultiMap.h"

class MultiMap;

class MultiMapIterator {
    friend class MultiMap;

private:
    MultiMap &col;

    //DO NOT CHANGE THIS PART
    MultiMapIterator(MultiMap &c);

    MultiMap::Node *current;

public:
    TElem getCurrent() const;

    bool valid() const;

    void next();

    void first();

    TElem remove();
};

