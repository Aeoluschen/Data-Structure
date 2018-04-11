#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
char det(char A);
void i_to_p(char* infixpos,int stk_size);
int pri(char);

int main(int argc, char const *argv[]) {
        int stk_size;
        cin >> stk_size;
        char infixpos[stk_size];
        int i = 0;
        for (i = 0; i <= stk_size-1; i++) {
                cin >> infixpos[i];
        }

        i_to_p(infixpos,stk_size);

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
        case '/':
                return 'O';
                break;
        default:
                return 'X';
                break;
        }
}

int pri(char A){
        switch (A) {
        case '+':
        case '-':
                return '1';
                break;
        case '*':
        case '/':
                return '2';
                break;
        default:
                return '0';
                break;
        }
}


void i_to_p(char* infixpos,int stk_size){
        stack<char> in_to_pos;
        int i;
        for(i = 0; i <= stk_size-1; i++ ) {
                //cout <<i<< infixpos[i] <<" ";
        }
        cout <<endl;
        for(i = 0; i <= stk_size-1; i++ ) {
                //cout <<"right now is element:"<<infixpos[i]<<endl;
                switch (det(infixpos[i])) {
                case 'I':
                        //cout <<"case I"<<endl;
                        cout<<infixpos[i];
                        break;
                case 'P':
                        //cout <<"case P"<<endl;
                        in_to_pos.push(infixpos[i]);
                        break;
                case 'O':
                        //cout <<"case O"<<endl;
                        //cout <<infixpos[i]<<endl;
                        cout <<" ";
                        if(!in_to_pos.empty()) {
                                while(pri(in_to_pos.top())>=pri(infixpos[i])) {
                                        cout<<in_to_pos.top()<<" ";
                                        //cout <<"push out" <<in_to_pos.top();
                                        in_to_pos.pop();
                                        break;
                                }
                        }
                        //cout <<"push in"<<infixpos[i];
                        in_to_pos.push(infixpos[i]);
                        break;
                case 'Q':
                        //cout <<"case Q"<<endl;
                        cout <<" ";
                        while (in_to_pos.top()!='(') {
                                cout <<" "<< in_to_pos.top()<<" ";
                                in_to_pos.pop();
                                //cout<<"print right brace until left brace"<<endl;
                        }
                        //cout<<"the term beeing popped out is :"<<in_to_pos.top()<<endl;
                        in_to_pos.pop();
                        break;
                default:
                        cout <<" ";
                        cout << infixpos[i];
                }
        }
        while(!in_to_pos.empty()) {
                cout <<" ";
                cout << in_to_pos.top();
                in_to_pos.pop();
        }

}
