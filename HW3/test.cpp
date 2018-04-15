#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class santa {
public:
string gift;
int price;
};

class Node{
private:
  santa elem;
  Node* next;
  Node* prev;
  friend class LLT;
};

class LLT{
public:
  LLT();
  ~LLT();
  void addfront(const santa&);
  void addback(const santa&);
  void removefront();
  void removeback();
  bool empty();
  santa front();
  void remove();
private:
  Node* header;
  Node* tailer;
protected:
  void add(Node* v,const santa& e);
  void remove(Node* v);
};

LLT::LLT(){
  header = new Node;
  tailer = new Node;
  header -> next = tailer;
  tailer -> prev = header;
}
LLT::~LLT(){
}
void LLT::add(Node* v,const santa& e){
  //cout <<"add successfully"<<endl;
  Node* u = new Node;
  u -> elem = e;
  u -> next = v;
  u -> prev = v -> prev;
  v -> prev -> next = u;
  v -> prev = u;
}
void LLT::addfront(const santa& e){
  add(header -> next,e);
  //  cout <<"add successfully"<<endl;
}
void LLT::addback(const santa& e){
  add(tailer ,e);
}
bool LLT::empty(){
  return (header -> next == tailer);
}
santa LLT::front(){
  return header -> next->elem;
}
void LLT::remove(Node* v){
  v -> prev -> next = v-> next;
  v -> next -> prev = v->prev;
  delete v;
}
void LLT::removefront(){
  remove(header->next);
};
void LLT::removeback(){
  remove(tailer->prev);
};

int main(int argc, char const *argv[]) {
  cout << "hello world"<<endl;
  santa i;
  LLT giftlist;
  cin >> i.gift>> i.price;
  //cin ;
  //cout << i.gift<<","<<i.price<<endl;
  cout <<"resault"<<endl;
  //cout << giftlist.empty();
  giftlist.addfront(i);
  //cout << giftlist.empty()<<endl;
  cout << giftlist.front().gift<<","<<giftlist.front().price<<endl;
  cout <<"next"<<endl;
  cin >> i.gift>> i.price;
  //cin ;
  cout << i.gift<<","<<i.price<<endl;
  giftlist.addback(i);
  //cout << giftlist.front().gift<<","<<giftlist.front().price<<endl;
  giftlist.removeback();
  cout << giftlist.front().gift<<","<<giftlist.front().price<<endl;
  //cout<<"after remove : "<<endl;
  //cout << giftlist.empty()<<endl;
  //cout << giftlist.front().gift<<","<<giftlist.front().price<<endl;

  return 0;
}
