#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

void inToPostfix(char*, char*); // 中序轉後序
int priority(char); // 運算子優先權

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
char* i_to_p(char*,int );
position step(int);
void resault(int,int);

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
        case '\\':
                return 'O';
                break;
        default:
                return 'X';
                break;
        }
}

bool chg(char A,char B){
        if (A =='I'&& B!='X') {
                return true;
        }else if(A =='I'&&B=='O') {
                return true;
        }else if (A =='O'&& B == 'I') {
                return true;
        }else if ((A =='P'&& B == 'I')) {
                return true;
        }else if((A =='Q'&& B == 'O')) {
                return true;
        }else if(A =='P'&& B == 'I') {
                return false;
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
        stack<char> in_to_pos;
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
                char infixpos[stk_size]={};
                char postfix[stk_size]={};
                for (i = 0; i <= stk_size-1; i++) {
                        infixpos[stk_size-1-i]=maze[stk_pos.top().x][stk_pos.top().y];
                        stk_pos.pop();
                }
                for(i = 0; i <= stk_size-1; i++ ) {
                        cout << infixpos[i] <<" ";
                }
                cout << endl;
                inToPostfix(infixpos,postfix);
                for(i = 0; postfix[i] != '\0'; i++ ) {
                        cout << postfix[i] <<" ";
                }

        }else{
                cout<<"No"<<endl;
        }

}


void inToPostfix(char* infix, char* postfix) {
    char stack[100] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++) switch(infix[i]) {
        case '(':              // 運算子堆疊
            stack[++top] = infix[i];
            break;
        case '+': case '-': case '*': case '/':
            while(priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i]; // 存入堆疊
            break;
        case ')':
            while(stack[top] != '(') { // 遇 ) 輸出至 (
                postfix[j++] = stack[top--];
            }
            top--;  // 不輸出 (
            break;
        default:  // 運算元直接輸出
            postfix[j++] = infix[i];
    }
    while(top > 0) {
        postfix[j++] = stack[top--];
    }
}

int priority(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    }
}
