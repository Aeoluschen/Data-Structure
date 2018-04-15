#include <stdio.h>
#include <iostream>

using namespace std;

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

///////////////////////////////////////////////////////
class santa {
public:
string gift;
int price;
};
///////////////////////////////////////////////////////
int detect(SNode<santa>& );

int main(int argc, char const *argv[]) {
        //LNode giftlist;
        int A;
        SNode<santa> giftlist;
        do {
                A = detect(giftlist);
                cout << A << endl;
        } while(A);

        return 0;
}

int detect(SNode<santa>& giftlist){
        string A;
        cin >> A;
        santa item;
        int d_price;
        if (A=="InsertBack") {
                cin >> item.gift;
                cin >> item.price;
                //giftlist.InsertBack(item);
                //cout << "Gift been pushed Back in is :" << giftlist.front(item)<<endl;
                return 1;
        }else if(A=="InsertAfter") {
                cin >> item.gift;
                cin >> item.price;
                //giftlist.InsertAfter(item);
                //cout << "Gift been pushed After in is :" << giftlist.back(item)<<endl;
                return 2;
        }else if(A=="Delete") {
                cin >> d_price;
                //giftlist.Delete(d_price);
                return 3;
        }else if(A=="Reverse") {
                //giftlist.Reverse();
                return 4;
        }else{
                return 0;
        }

}
