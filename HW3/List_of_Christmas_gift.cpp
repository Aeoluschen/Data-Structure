#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <typename E>
class LNode {
private:
E elem;
LNode<E>* next;
LNode<E>* prev;
friend class LList;
};

template <typename E>
class LList {
public:
void LList();
void ~LList();
bool empty() const;
void InsertBack(const E& e);
void InsertAfter(const E& e);
void Delete_ele(const E& e);
void Reverse();
private:
LNode* header;
LNode* tailer;
protected:
void add(LNode* v,const E& e);
void remove(LNode* v);
};
///////////////////////////////////////////////////////
LList::LList(){
        header = new LNode;
        tailer = new LNode;
        header->next = trailer;
        trailer->prev = header;
}
LList::~LList(){
        while (empty()) {
                removeFront();
                delete header;
                delete tailer;
        }
}
bool LList::empty(){
        return head->next==trailer;
}
void LList::InsertBack(const E& e){
        add(header->next,e);
}
void LList::InsertAfter(const E& e){
        add(trailer,e);
}
void LList::add(LNode* v,const E& e){
  LNode* u = new LNode;
  u -> elem = e;
  u -> next = v;
  u -> prev = u-> prev;
  v -> prev = next = v-> prev = u;
}
void LList::remove(LNode* v){
  LNode* u = v -> prev;
  LNode* w = v -> next;
  u -> next = w;
  w -> prev = u;
  delete v;
}
void LList::removeFront(){
  remove(header->next);
}
///////////////////////////////////////////////////////
class santa {
string gift;
int price;
};
///////////////////////////////////////////////////////
int detect(LNode& );

int main(int argc, char const *argv[]) {
        //LNode giftlist;
        int A;
        do {
                A = detect();
                cout << A;
        } while(A);

        return 0;
}
///////////////////////////////////////////////////////
int detect(LNode& giftlist){
        string A;
        cin >> A;
        santa item;
        int d_price;
        if (A=="InsertBack") {
                cin >> item.gift;
                cin >> item.price;
                giftlist.InsertBack(item);
                return 1;
        }else if(A=="InsertAfter") {
                cin >> item.gift;
                cin >> item.price;
                giftlist.InsertAfter(item);
                return 2;
        }else if(A=="Delete") {
                cin >> d_price;
                giftlist.Delete(d_price);
                return 3;
        }else if(A=="Reverse") {
                giftlist.Reverse();
                return 4;
        }else{
                return 0;
        }

}
