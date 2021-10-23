#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <queue>

SortedBag::SortedBag(Relation r) {
	this->root = nullptr;
	this->nr_elems = 0;
	this->rel = r;
}
// Theta(1)

int SortedBag::elementsWithMinimumFrequency() const{

    if (this->isEmpty())
        return 0;

    int min_freq = 99999999;
    int nr_elms = 0;

    SortedBagIterator it = this->iterator();
    while (it.valid()){
        if (nrOccurrences(it.getCurrent()) < min_freq) {
            min_freq = nrOccurrences(it.getCurrent());
        }
        it.next();
    }

    it.first();
    while (it.valid()){
        if (nrOccurrences(it.getCurrent()) == min_freq) {
            nr_elms++;
        }
        it.next();
    }

    return nr_elms;
}
//WC=BC= THETA(N^N)
//TOTAL O(N^N)


void SortedBag::add(TComp e) {
    Node *new_n = new Node;
    new_n->info = e;
    new_n->left = nullptr; new_n->right = nullptr;

    Node *current = this->root;
    Node *prev = nullptr;
    while (current != nullptr) {
        prev = current;

        if (this->rel(current->info, e))
            current = current->right;
        else
            current = current->left;
        }

    if (prev == nullptr)
        this->root = new_n;
    else if (this->rel(prev->info, e))
        prev->right = new_n;
    else
        prev->left = new_n;

    this->nr_elems +=1;
}
// BC Theta(1) we set the root of our BST
// WC Theta(n) n being the number of elements in the bag
// Total => O(n)

bool SortedBag::remove(TComp e) {
	Node* current = this->root;
	Node* prev = nullptr;

    while (current != nullptr and current->info != e){
        prev = current;
        if (this->rel(current->info, e))
            current = current->right;
        else
            current = current->left;
    }
    if (current == nullptr)
        return false;

    if (current->left == nullptr or current->right == nullptr) {
        Node* n_curr;
        if (current->left == nullptr)
            n_curr = current->right;
        else
            n_curr = current->left;

        if (prev == nullptr) {
            delete current;
            this->root = n_curr;
            this->nr_elems -= 1;
            return true;
        }

        if (current == prev->left)
            prev->left = n_curr;
        else
            prev->right = n_curr;
        this->nr_elems -=1;
        delete current;
        return true;
    }
    else {
        Node* p = nullptr;
        Node* temp;

        temp = current->right;
        while (temp->left != nullptr) {
            p = temp;
            temp = temp->left;
        }
        if (p != nullptr)
            p->left = temp->right;
        else
            current->right = temp->right;
        current->info = temp->info;
        delete temp;
        this->nr_elems -=1;
        return true;
    }
}
// Best case: Theta(1) we want to delete the root and height of the tree is 1
// Worst case: Theta(n) n is height of binary search tree.
// Total => O(n)

bool SortedBag::search(TComp elem) const {
	Node* current = this->root;
	bool found = false;
	while (current != nullptr and !found) {
        if (current->info == elem)
            found = true;
        else if (this->rel(current->info, elem))
            current = current->right;
        else
            current = current->left;
	}
    return found;
}
// Best case: Theta(1) the element we search is the root
// Worst case: Theta(n) n is height of binary search tree. In worst case the height is equal to number of nodes.
// Total => O(n)

int SortedBag::nrOccurrences(TComp elem) const {
    Node* current = this->root;
    int app=0;
    while (current != nullptr) {
        if (current->info == elem)
            app++;
        if (this->rel(current->info, elem))
            current = current->right;
        else
            current = current->left;
    }
    return app;
}
// Best case: Theta(1) the element we search is the root
// Worst case: Theta(n) n is height of binary search tree. In worst case the height is equal to number of nodes.
// Total => O(n)

int SortedBag::size() const {
	return this->nr_elems;
}
// Theta(1)

bool SortedBag::isEmpty() const {
    if (this->nr_elems == 0)
        return true;
    return false;
}
// Theta(1)

SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
// Theta(1)

SortedBag::~SortedBag() {
    SortedBag::delete_tree(this->root);
}

void SortedBag::delete_tree(Node *r) {
    if (r == nullptr)
        return;
    SortedBag::delete_tree(r->left);
    SortedBag::delete_tree(r->right);
    delete r;
}
// Theta(n) n being the height of the tree


