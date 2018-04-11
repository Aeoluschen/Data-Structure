#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <typename E>
class ArrayStack {
enum  {DEF_CAPACITY = 100 };
public:
ArrayStack(int cap = DEF_CAPACITY);
int size() const;
bool empty() const;

const E& top();
void push(const E& e);
void pop();

private:
E* S;
int capacity;
int t;
};


template <typename E> ArrayStack <E> :: ArrayStack(int cap) : S(new E[cap]),capacity(cap),t(-1){
}                                                                                              //constructor from capacity

template <typename E> int ArrayStack<E> ::size() const {
        return t+1;
}
template <typename E> bool ArrayStack<E>::empty() const {
        return t<0;
}
template <typename E>
const E& ArrayStack <E>::top(){
        return S[t];
}
template <typename E>
void ArrayStack<E>::push(const E& e){
        S[++t]=e;
}
template <typename E>
void ArrayStack<E> ::pop(){
        --t;
}
////////////////////////////////////////////////////////////////////////////////
char det(char);
bool condition(char A,char B);
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) {
        /* code */
        char A,B;
        scanf("%c\n",&A);
        scanf("%c",&B);
        A = det(A);
        B = det(B);
        if (condition(A,B)) {
          cout << A<<B;
        }else{
          cout << "0";
        }
        return 0;
}
char det(char A){
  switch (A) {
    case '0':
    return 'I';
    break;
    case '1':
    return 'I';
    break;
    case '2':
    return 'I';
    break;
    break;
    case '3':
    return 'I';
    break;
    case '4':
    return 'I';
    break;
    case '5':
    return 'I';
    break;
    case '6':
    return 'I';
    break;
    case '7':
    return 'I';
    break;
    case '8':
    return 'I';
    break;
    case '9':
    return 'I';
    break;
    case '(':
    return 'P';
    break;
    case ')':
    return 'Q';
    break;
    case '+':
    return 'O';
    break;
    case '-':
    return 'O';
    break;
    case '*':
    return 'O';
    break;
    case '\\':
    return 'O';
    break;
  }
  }
  bool condition(char A,char B){
          if (A =='I') {
                  return true;
          }else if (A =='O'&& B == 'I') {
                  return true;
          }else if ((A =='P'&& B == 'I')) {
                  return true;
          }else if((A =='Q'&& B == 'O')) {
                  return true;
          }else{
                  return false;
          }
  }
