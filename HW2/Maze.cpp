#include <stdio.h>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
//class stack goes here
template <typename E>
class stack {
enum  {DEF_CAPACITY = 100 };
public:
stack(int cap = DEF_CAPACITY);
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

template <typename E> stack <E> :: stack(int cap) : S(new E[cap]),capacity(cap),t(-1){
}                                                                                              //constructor from capacity

template <typename E> int stack<E> ::size() const {
        return t+1;
}
template <typename E> bool stack<E>::empty() const {
        return t<0;
}
template <typename E>
const E& stack <E>::top(){
        return S[t];
}
template <typename E>
void stack<E>::push(const E& e){
        S[++t]=e;
}
template <typename E>
void stack<E> ::pop(){
        --t;
}

////////////////////////////////////////////////////////////////////////////////
class position {
public:
int x;
int y;
void getpos(int a,int b){
        x = a;
        y = b;
}
};

bool chg(char A,char B);
char det(char A);
void i_to_p(char*,int );
position step(int);
void resault(int,int);
int pri(char);

int main(int argc, char const *argv[]) {
        int n_times,w,h;
        int times = 1;
        scanf("%d\n",&n_times);
        printf("%d\n",n_times);
        for(times=1; times<=n_times; times++) {
                //cout <<"times: "<<times<<endl;
                scanf("%d\n%d\n",&w,&h);
                resault(h,w);

        }
        return 0;
}
/////////////////////////////////////////////////////////////////////////////
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

bool chg(char A,char B){
        if(A =='I'&&B=='I') {
                return true;
        }else if ((A =='I'&& B == 'O')) {
                return true;
        }else if ((A =='I'&& B == 'Q')) {
                return true;
        }else if ((A =='P'&& B == 'I')) {
                return true;
        }else if((A =='P'&& B == 'P')) {
                return true;
        }else if((A =='O'&& B == 'I')) {
                return true;
        }else if((A =='O'&& B == 'P')) {
                return true;
        }else if((A =='Q'&& B == 'O')) {
                return true;
        }else{
                return false;
        }
}
position step(int A){
        position up;
        up.getpos(-1,0);
        position right;
        right.getpos(0,1);
        position left;
        left.getpos(0,-1);
        position down;
        down.getpos(1,0);
        switch (A) {
        case 1:
                return down;
                break;
        case 2:
                return right;
                break;
        case 3:
                return left;
                break;
        case 4:
                return up;
                break;
        }
}

void resault(int h,int w){
        cout << w<<endl;
        cout <<h<<endl;
        char maze[h][w];
        char chg_maze[h][w];
        int path[h][w]={};
        int i,j;
        for (i = 0; i<= h-1; i++) {
                for (j = 0; j<= w-1; j++) {
                        cin >> maze[i][j];
                        chg_maze[i][j]=det(maze[i][j]);
                }
        }
        /*for (i = 0; i<= h-1; i++) {
                for (j = 0; j<= w-1; j++) {
                        cout << chg_maze[i][j]<<" ";
                }
                cout << endl;
           }*/
        /*if(i == 1) {

           }*/
        //  printf("%d\n%d\n",w,h);
        for (i = 0; i<= h-1; i++) {
                for (j = 0; j<= w-1; j++) {
                        cout << maze[i][j] << " ";
                }
                cout << endl;
        }

        /////////////////////////////////////////////////////////////////////////////
        stack<position> stk_pos;

        int dir = 1;
        path[0][0]=1;
        position begin;
        begin.getpos(0,0);
        position end;
        end.getpos(h-1,w-1);
        position now;
        now.getpos(begin.x,begin.y);
        position next;
        stk_pos.push(now);
        int n_P = 0;

        while (dir <= 5  && !stk_pos.empty()) {
                //cout <<"finding path"<<endl;
                now.getpos(stk_pos.top().x,stk_pos.top().y);
                next.getpos(now.x+step(dir).x,now.y+step(dir).y);
                //cout <<"("<<step(dir).x<<","<<step(dir).y<<") + "<<"("<<now.x<<","<<now.y<<") = ("<<next.x<<","<<next.y<<")"<<endl;
                if (now.x==end.x&&now.y==end.y) {
                        //cout<<"find path"<<endl;
                        break;
                }
                if(dir == 5) {
                        //cout << "the elems been pop out is" <<maze[now.x][now.y]<<endl;
                        stk_pos.pop();
                        dir = 1;
                        continue;
                }

                //cout <<"("<<now.x<<","<<now.y<<")"<<dir<< "("<<next.x<<","<<next.y<<")"<<endl;
                if(chg(chg_maze[now.x][now.y],chg_maze[next.x][next.y])&&path[next.x][next.y]!=1&&next.x>=0&&next.y>=0&&next.x<=h-1&&next.y<=w-1) {
                        //cout << "the elems been push in is " << "("<<next.x<<","<<next.y<<")"<<maze[next.x][next.y]<<endl;
                        if(chg_maze[next.x][next.y]=='P'){
                          n_P++;
                        }else if(chg_maze[next.x][next.y]=='Q'){
                          n_P--;
                        }
                        stk_pos.push(next);
                        path[next.x][next.y]=1;
                        dir = 1;
                }else{
                        //cout << "dir++"<<endl;
                        dir++;
                }
        }
        int stk_size = stk_pos.size();
        //cout << stk_size<<endl;
        /////////////////////////////////////////////////////////////////////////////
        /*for (i = 0; i<= h-1; i++) {
                for (j = 0; j<= w-1; j++) {
                        cout << path[i][j]<<" ";
                }
                cout << endl;
           }*/

        //cout << stk_size<<endl;
        if(stk_size>0) {
                cout << "Yes"<<endl;
                char infixpos[stk_size];
                for (i = 0; i <= stk_size-1; i++) {
                        infixpos[stk_size-1-i]=maze[stk_pos.top().x][stk_pos.top().y];
                        stk_pos.pop();
                }
                i_to_p(infixpos,stk_size);

        }else{
                cout<<"No"<<endl;
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
          if(det(infixpos[i])=='O'){
                cout <<" "<< infixpos[i] <<" ";
              }else{
                cout <<infixpos[i];
              }

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
                        in_to_pos.pop();
                }
        }
        while(!in_to_pos.empty()) {
                cout <<" ";
                cout << in_to_pos.top();
                in_to_pos.pop();
        }

}
