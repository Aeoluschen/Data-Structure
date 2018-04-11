#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;
////////////////////////////////////////////////////////////////////////////////
class Pos {
public:

Posi(int x,int y){
        pos_x = x;
        pos_y = y;
}
int pos_x;
int pos_y;
Pos operator+ (Pos);
bool operator== (Pos);
};

Pos Pos::operator+ (Pos A){
        Pos sum;
        sum.pos_x = this->pos_x+A.pos_x;
        sum.pos_y = this->pos_y+A.pos_y;
        return sum;
}

bool Pos::operator== (Pos A){
        Pos B;
        if(B.pos_x != A.pos_x || B.pos_y != A.pos_y) {
                return false;
        }else{
                return true;
        }
}

////////////////////////////////////////////////////////////////////////////////
char detect(char);
bool condition(char,char);
Pos step(int);
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) {
        /* code */
        int n_matrix=0;
        int width=0,height =0;
        int i = 0,j=0;
        scanf("%d\n", &n_matrix);
        scanf("%d\n", &height);
        scanf("%d\n", &width);
        char matrix[height][width];
        char char_matrix[height][width];
        int markpath[height][width]={0};
        for (i = 0; i <= height-1; i++) {
                for (j = 0; j <= width-1; j++) {
                        cin >> matrix[i][j];
                        char_matrix[i][j] = detect(matrix[i][j]);
                }
        }

        ///////////////////////////////////////////////////////////////////////////
        //do the calculate
        Pos end;
        end.Posi(height-1,width-1);
        stack<Pos> stk_path;
        Pos begin;
        begin.Posi(0,0);
        stk_path.push(begin);
        markpath[0][0]=1;
        int direction = 1;
        while(direction <= 5) {
                Pos now;
                now.Posi(stk_path.top().pos_x,stk_path.top().pos_y);
                Pos next;
                next.Posi((now+step(direction)).pos_x,(now+step(direction)).pos_y);
                cout <<"("<< now.pos_y <<","<<now.pos_x<<")"<<" "<<direction<<"("<< next.pos_y <<","<<next.pos_x<<")"<<" "<<endl;
                cout << "("<<matrix[now.pos_x][now.pos_y]<<","<<matrix[next.pos_x][next.pos_y]<<")"<<(condition(char_matrix[now.pos_x][now.pos_y],char_matrix[next.pos_x][next.pos_y]))<<endl;
                if (now.pos_x==end.pos_x&& now.pos_y== end.pos_y) {
                        break;
                }
                if (stk_path.empty()) {
                        break;
                }
                if (direction == 5) {
                        stk_path.pop();
                        direction = 1;
                        continue;
                }
                if (condition(char_matrix[now.pos_x][now.pos_y],char_matrix[next.pos_x][next.pos_y])&& markpath[next.pos_x][next.pos_y]==0 && now.pos_y<=height-1&&now.pos_x<=width-1) {
                        stk_path.push(next);
                        markpath[next.pos_x][next.pos_y]==1;
                        direction = 1;
                }else {
                        direction++;
                }

        }

        ///////////////////////////////////////////////////////////////////////////
        //print out the resault
        if (!stk_path.empty()) {
                cout << "yes"<<endl;
        }else{
                cout << "No"<<endl;
        }
        while (!stk_path.empty()) {
                int x = stk_path.top().pos_x;
                int y = stk_path.top().pos_y;
                cout << matrix[x][y];
                stk_path.pop();
        }
        cout << endl;
        ///////////////////////////////////////////////////////////////////////////
        printf("%d\n%d\n%d\n",n_matrix,width,height);
        for (i = 0; i <= height-1; i++) {
                for (j = 0; j <= width-1; j++) {
                        printf("%c ", char_matrix[i][j]);
                }
                printf("\n");
        }

        return 0;
}
/////////////////////////////////////////////////////////////////////////////////
char detect(char A){
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

bool condition(char A,char B){
        if (A =='I'&& B!='X') {
                return true;
        }else if(A =='I'&&B=='O'){
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
Pos step(int A){
        Pos up;
        up.Posi(-1,0);
        Pos right;
        right.Posi(0,1);
        Pos left;
        left.Posi(0,-1);
        Pos down;
        down.Posi(1,0);
        switch (A) {
        case 1:
                return right;
                break;
        case 2:
                return down;
                break;
        case 3:
                return left;
                break;
        case 4:
                return up;
                break;
        }
}
