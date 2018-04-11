#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool palin(int, string);
bool rever_palin(int, string);

int main(int argc, char const *argv[]) {
    /* code */
    int n = 0;
    scanf("%d\n", &n);
    string word;
    while (getline(cin,word)) {
        /* code */
        //remv_space(word);
        if(palin(n,word)||rever_palin(n,word)){
            cout <<"Yes"<<"\n";
        }else {
            cout <<"No"<<"\n";
        };
    }

    return 0;
}

bool palin(int n, string A){
    int leng = A.size();
    //cout<<A.size()<<endl;
    int i = 0;
    for (i = 0; i <= leng/2; i++){
        if ((A[i] != A[leng-i-1]) && (n >=0) ){
            A.erase(i,1);
            return rever_palin(n-1, A);
        }
        else if ((A[i] != A[leng-i])&& (n <0) ){
            return false;
        }
    }
    return true;
}

bool rever_palin(int n, string A){
    int leng = A.size();
    //cout<<A.size()<<endl;
    int i = 0;
    for (i = 0; i <= leng/2; i++){
        if ((A[leng-i-1] != A[i])&& (n >=0) ){
            A.erase((leng-i-1),1);
            return palin(n-1, A);
        }
        else if ((A[leng-i] != A[i]) && (n <0) ||(leng == 0)){
            return false;
        }
    }
    return true;
}
