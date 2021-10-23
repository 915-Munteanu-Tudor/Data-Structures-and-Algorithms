#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"
#include <cassert>



using namespace std;


int main() {
    MultiMap m;
    m.add(1, 0);
    m.add(2, 0);
    m.add(3, 0);
    MultiMapIterator it = m.iterator();
    it.first();

    assert(it.remove() == TElem(1,0));
    assert(m.search(1).empty());
    assert(it.valid());
    //cout<<it.remove().first;
    assert(it.remove() == TElem(2,0));
    assert(it.getCurrent() == TElem(3,0));

    assert(m.search(2).empty());
    assert(it.valid());

    assert(it.remove() == TElem (3, 0));
    assert(m.search(3).empty());
    assert(!it.valid());
    try {
        it.getCurrent();
        assert(false);
    } catch (std::exception &ex) {
        assert(true);
    }

    try {
        it.remove();
        assert(false);
    } catch (std::exception &ex) {
        assert(true);
    }
    std::cout << "iterator remove tests over\n";
    testAll();
    testAllExtended();
    cout << "End" << endl;
    system("pause");

}
