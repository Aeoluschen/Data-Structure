#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class santa{
public:
  santa();
  string gift;
  int price;
};

/*santa::santa(){
  //gift = (string)NULL;
  //price = (int)NULL;
}*/
class LN{
public:
  LN();
  ~LN();
  void remove();
  bool empty();
protected:
  santa* header;
private:
  santa elem;
  santa* next;
};

LN::LN(){
  header = NULL;
}
LN::~LN(){
  while(!empty()){
    remove();
  }
  delete header;
}
bool LN::empty(){
  return header == (NULL);
}
void remove(){
  santa* v;
  v = next;
  header = v;
  delete header;
}
