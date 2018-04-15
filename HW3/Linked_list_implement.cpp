#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class StringNode {
private:
string elem;
StringNode* next;
friend class StringList;
};
class StringList {
public:
StringList();
~StringList();
bool empty() const;
void printelem();
const string& front() const;
void addFront(const string& e);
void removeFront();

private:
StringNode* head;
};

StringList::StringList(){
  head = NULL;
}
StringList::~StringList(){
        while (!empty()) {
                removeFront();
        }
}
bool StringList::empty() const {
        return head == NULL;
}
const string& StringList::front() const
{
        return head->elem;
}
void StringList::addFront(const string& e){
        StringNode* v = new StringNode;
        v->elem = e;
        v->next = head;
        head = v;

}
void StringList::removeFront(){
        StringNode* old = head;
        head = old->next;
        delete old;
}
void StringList::printelem(){
        while (!empty()) {
                cout << front() <<endl;
                removeFront();
        }
}




template <typename E>
class SNode { // singly linked list node
private:
E elem; // linked list element value
SNode<E>* next; // next item in the list
friend class SLinkedList<E>; // provide SLinkedList access
};

template <typename E>
class SLinkedList { // a singly linked list
public:
SLinkedList(); // empty list constructor
˜SLinkedList(); // destructor
bool empty() const; // is list empty?
const E& front() const; // return front element
void addFront(const E& e); // add to front of list
void removeFront(); // remove front item list
private:
SNode<E>* head; // head of the list
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
template <typename E>
void SLinkedList<E>::removeFront() { // remove front item
        SNode<E>* old = head; // save current head
        head = old−>next; // skip over old head
        delete old; // delete the old head
}



int main(int argc, char const *argv[]) {
        //StringList A;
        string elem1,elem2,elem3;
        SLinkedList<string> A
        cin >> elem1;
        cin >> elem2;

        A.addFront(elem1);
        A.addFront(elem2);
        A.printelem();//print out all the element;
        cin >> elem3;
        A.addFront(elem3);
        A.printelem();//print out all the element;


        return 0;
}
