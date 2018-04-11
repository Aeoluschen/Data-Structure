#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int test_palindorm(string);
bool revpalin(int, string);
bool palin(int, string);


int main(int argc, char const *argv[]) {
  /* code */
  int n = 0;
  scanf("%d\n", &n);
  string word;
  while (getline(cin,word)) {
      /* code */
      //remv_space(word);
      if(palin(n,word)){
          cout <<"Yes"<<"\n";
      }else {
          cout <<"No"<<"\n";
      };
  }

}

int test_palindorm(string A){
  int leng = A.size();
  //cout<<A.size()<<endl;
  int i = 0,j=-1;
  for (i = 0; i <= leng/2; i++){
      if ((A[i] != A[leng-i-1])){
          return j;
      }
return j;
}
               }


bool palin(int n, string A){
    int leng = A.size();
    //cout<<A.size()<<endl;
    string A1,A2;
    A1=A;
    A2=A;
    int i = 0;
     if((test_palindorm(A1)== -1)){
       return true;
     }else if ((test_palindorm(A1) != -1)&&(n>0)){
      A1.erase(test_palindorm(A1),1);
      return palin(n-1,A1);
    }else if((test_palindorm(A1) != -1)&&(n<=0)){
      return revpalin(n,A2);
    }
  }

bool revpalin(int n, string A){
      int leng = A.size();
      //cout<<A.size()<<endl;
      string A1,A2;
      A1=A;
      A2=A;
      int i = 0;
       if((test_palindorm(A1)== -1)){
         return true;
       }else if ((test_palindorm(A1) != -1)&&(n>0)){
        A1.erase(leng-1-test_palindorm(A1),1);
        return revpalin(n+1,A2);
      }else if((test_palindorm(A1) != -1)&&(n<=0)){
        return false;
      }
    }
