#include <stdio.h>
#include <iostream>

using namespace std;

template <typename E>
class SNode { // singly linked list node
private:
E elem; // linked list element value
SNode<E>* next; // next item in the list
SNode<E>* prev; // previus item in the list
friend class SLinkedList<E>; // provide SLinkedList access
};

template <typename E>
class SLinkedList { // a singly linked list
public:
SLinkedList(); // empty list constructor
˜SLinkedList(); // destructor
bool empty() const; // is list empty?
const E& front() const; // return front element
const E& back() const;
void addFront(const E& e); // add to front of list
void addBack(const E&e);
void removeFront(); // remove front item list
void removeBack();
private:
SNode<E>* head; // head of the list
SNode<E>* tail; // tail of the list
};

template <typename E>
SLinkedList<E>::SLinkedList() // constructor
        : head(NULL) {
}
template <typename E>
bool SLinkedList<E>::empty() const // is list empty?
{
        return head == NULL;
}
template <typename E>
const E& SLinkedList<E>::front() const // return front element
{
        return head−>elem;
}
template <typename E>
const E& SLinkedList<E>::back() const // return front element
{
        return tail−>elem;
}
template <typename E>
SLinkedList<E>::˜SLinkedList() // destructor
{
        while (!empty()) removeFront();
}
template <typename E>
void SLinkedList<E>::addFront(const E& e) { // add to front of list
        SNode<E>* v = new SNode<E>; // create new node
        v−>elem = e; // store data
        v−>next = head; // head now follows v
        head = v; // v is now the head
}
void SLinkedList<E>::addBack(const E& e) { // add to front of list
        SNode<E>* v = new SNode<E>; // create new node
        v−>elem = e; // store data
        v−>next = tail; // tail now follows v
        tail = v; // v is now the head
}
template <typename E>
void SLinkedList<E>::removeFront() { // remove front item
        SNode<E>* old = head; // save current head
        head = old−>next; // skip over old head
        delete old; // delete the old head
}
void SLinkedList<E>::removeBack() { // remove front item
        SNode<E>* old = tail; // save current head
        tail = old−>next; // skip over old head
        delete old; // delete the old head
}
int main(int argc, char const *argv[]) {
  SNode<char> test;
  cin >> test.
  return 0;
}