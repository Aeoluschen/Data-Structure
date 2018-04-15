#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class santa {
public:
string gift;
int price;
};

class Node {
public:
santa elem;
Node* next;
Node* prev;
friend class LLT;
};

class LLT {
public:
int size;
LLT();
~LLT();
void addfront(const santa&);
void addback(const santa&);
Node* findprice(const int);
Node* findgift(const string);
void removefront();
void removeback();
bool empty();
santa front();
void remove();
void pt_all();
void add(Node* v,const santa& e);
void remove(Node* v);
void reverse();
private:
Node* header;
Node* tailer;

};

LLT::LLT(){
        header = new Node;
        tailer = new Node;
        header->next = tailer;
        tailer->prev = header;
        size = 0;
}
LLT::~LLT(){
}
void LLT::add(Node* v,const santa& e){
        //cout <<"add successfully"<<endl;
        Node* u = new Node;
        u->elem = e;
        u->next = v;
        u->prev = v->prev;
        v->prev->next = u;
        v->prev = u;
        size++;
}
void LLT::addfront(const santa& e){
        add(header->next,e);
        //  cout <<"add successfully"<<endl;
}
void LLT::addback(const santa& e){
        add(tailer,e);
}
bool LLT::empty(){
        return (header->next == tailer);
}
santa LLT::front(){
        return header->next->elem;
}
void LLT::remove(Node* v){
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete v;
        size--;
}
void LLT::removefront(){
        remove(header->next);
};
void LLT::removeback(){
        remove(tailer->prev);
};
Node* LLT::findprice(const int e){
        santa termin;
        termin.price = 0;
        termin.gift = "X";
        //cout <<termin.price<<","<<termin.gift<<endl;
        Node* v = header;
        while(v->elem.price != e) {

                if(v->next == tailer) {
                        return NULL;
                        break;
                }
                v=v->next;
        }
        return v;
}
Node* LLT::findgift(const string e){
        santa termin;
        termin.price = 0;
        termin.gift = "X";
        Node* v = header;
        while(v->elem.gift != e) {

                if(v->next == tailer) {
                        //cout << "Not Found"<<endl;
                        return NULL;
                        break;
                }
                v= v->next;
        }
        return v;
}
void LLT::pt_all(){
        //cout << size<<endl;
        while(!(size==0)) {
                while(!(size==1)) {
                        cout <<"("<<front().gift<<","<<front().price<<")->";
                        removefront();
                }
                cout <<"("<<front().gift<<","<<front().price<<")";
                removefront();
        }

}
void LLT::reverse(){
        Node* u = NULL;
        Node* v = header;
        tailer = v;
        while(v != NULL) {
                //cout <<"U:"<< u->elem.price<<","<<u->elem.gift<<endl;
                //cout <<"V:"<< v->elem.price<<","<<v->elem.gift<<endl;
                u = v->prev;
                v->prev = v->next;
                v->next = u;
                v = v->prev;
        }
        if(u != NULL) {
                header = u->prev;
        }
        //cout << "change is end"<<endl;
        //cout <<"header"<< header->elem.price<<","<<header->elem.gift<<endl;
        //cout <<"tailer"<< tailer->elem.price<<","<<tailer->elem.gift<<endl;
}
////////////////////////////////////////////////
int detect(LLT& giftlist);

int main(int argc, char const *argv[]) {
        santa sta;
        LLT giftlist;
        int A;
        do {
                A = detect(giftlist);
                //cout << A << endl;
        } while(A);
        cout << "List"<<endl;
        giftlist.pt_all();
        cout <<endl;
        return 0;
}

///////////////////////////////////////////////////////
int detect(LLT& giftlist){
        string A;
        cin >> A;
        santa item;
        int d_price;
        if (A=="InsertBack") {
                cin >> item.gift;
                cin >> item.price;
                if((giftlist.findprice( item.price)==NULL)&&(giftlist.findgift(item.gift)==NULL)) {
                        giftlist.addback(item);
                }
                //cout << "Gift been pushed Back in is :";
                //cout<< giftlist.front().gift<<","<<giftlist.front().price<<endl;
                return 1;
        }else if(A=="InsertAfter") {
                cin >> item.gift;
                cin >> item.price;
                int fd_price;
                cin >> fd_price;
                //cout <<fd_price<<endl;
                if((giftlist.findprice(fd_price)!=NULL)) {
                        giftlist.add(giftlist.findprice(fd_price)->next,item);
                }
                //cout << "Gift been pushed After in is :";
                //cout<< giftlist.back().gift<<","<<giftlist.back().price<<endl;
                return 2;
        }else if(A=="Delete") {
                cin >> d_price;
                if((giftlist.findprice(d_price)!=NULL)) {
                        giftlist.remove(giftlist.findprice(d_price));
                }
                return 3;
        }else if(A=="Reverse") {
                giftlist.reverse();
                return 4;
        }else{
                return 0;
        }

}
