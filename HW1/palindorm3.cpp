#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool palin(int, string);
bool rev_palin(int, string);

int main(int argc, char const *argv[]) {
    /* code */
    int n = 0;
    scanf("%d\n", &n);
    string word;
    while (getline(cin,word)) {
        /* code */
        //remv_space(word);
        if(palin(n,word)||rev_palin(n,word)){
            cout <<"Yes"<<"\n";
        }else {
            cout <<"No"<<"\n";
        };
    }

    return 0;
}

bool palin(int n, string A){
    int leng = A.size();
    //cout << leng<<endl;
    int i = 0;
    for (i = 0; i <= leng/2 ; i++){
        if (n>0&&(A[leng/2-i-1] != A[leng/2+i]) && (A[leng/2-i-1] != A[leng/2+i+1])){
            //cout <<"x"<<leng/2-i-1<<endl;
            A.erase(leng/2-i-1,1);
            return palin(n-1, A);
        }
        else if (n>0&&(A[leng/2-i-1] != A[leng/2+i])&& (A[leng/2-i-1] == A[leng/2+i+1])){
            A.erase(leng/2+i,1);
            //cout <<A[leng-i-1]<<endl;
            return palin(n-1, A);
        }else if((A[leng/2-i-1] != A[leng/2+i]) &&n <=0 ){
          return false;
        }
    }
    cout << "test"<<endl;
    return true;
}

bool rev_palin(int n, string A){
    int leng = A.size();
    //cout << leng<<endl;
    int i = 0;
    for (i = 0; i <= leng/2 ; i++){
        if (n>0&&(A[leng/2-i-1] != A[leng/2+i]) && (A[leng/2-i-1] != A[leng/2+i+1])){
            //cout <<"x"<<leng/2-i-1<<endl;
            A.erase(leng/2+i,1);
            return palin(n-1, A);
        }
        else if (n>0&&(A[leng/2-i-1] != A[leng/2+i])&& (A[leng/2-i-1] == A[leng/2+i+1])){
            A.erase(leng/2-i-1,1);
            //cout <<A[leng-i-1]<<endl;
            return palin(n-1, A);
        }else if((A[leng/2-i-1] != A[leng/2+i]) &&n <=0 ){
          return false;
        }
    }
    cout << "test"<<endl;
    return true;
}
