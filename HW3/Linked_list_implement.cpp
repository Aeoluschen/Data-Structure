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

StringList::StringList() : head(NULL){
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






int main(int argc, char const *argv[]) {
        StringList A;
        string elem1,elem2,elem3;
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
