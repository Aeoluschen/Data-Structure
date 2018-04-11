#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int test_palin(string);
bool palin(int, string);
bool rever_palin(int, string);

int main(int argc, char const *argv[]) {
    /* code */
    int n = 0;
    string word;
    scanf("%d\n", &n);
    while (getline(cin,word)) {
        /* code */
        //remv_space(word);
        if(palin(n,word)){
            cout <<"Yes"<<"\n";
        }else {
            cout <<"No"<<"\n";
        };
    }
    return 0;
}
int test_palin(string A){
      int leng = A.size();
      int i=0,j=0;
      for (i = 0; i <= leng/2; i++){
          if ((A[i] != A[leng-i])){
            i++;
          }
        }
      for (i = 0; i <= leng/2; i++){
          if ((A[i] != A[leng-i])){
            cout <<i <<endl;
              return (i,j);
          }
          else {
              return (-1,-1);
          }
        }
}
bool palin(int n, string A){
    int leng = A.size();
    string word1=A;
    string word2=A;
    //cout<<A.size()<<endl;

    int i = 0;
    if (n>0&&test_palin(word1)!=-1){
       i = test_palin(word1);
       cout << "the deleted item is " <<A[i]<<endl;
       word1.erase(i,1);
      if(i<test_palin(word1)&&test_palin(word1)!=-1){
       word2.erase(leng-2-i,1);
       return palin(n-1,word2);
     }else if(i=test_palin(word1)){
       word1.erase(leng-i,1);
     }else{
       return palin(n-1,word1);
     }
   }else if(n<=0&&test_palin(word1)!=-1){
     return false;
   }else{
     return true;
   }
}
