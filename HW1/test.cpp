#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class palin{
public:
  int pos_palin;
  int sum_palin;
  void pospalin(string);
  void sumpalin(string);
};

bool rever_palin(int n, string A);

int main()
{ const int arrayLength = 40; char name1[arrayLength];

string word;
palin P;
while (getline(cin,word)) {
    /* code */
    P.pospalin(word);
    P.sumpalin(word);
    cout<<P.pos_palin<<endl;
    cout<<P.sum_palin<<endl;

}
return 0;
}

void palin::pospalin(string A){
  int leng = A.size();
  int i=0,j=0;
  for (i = 0; i < leng/2; i++){
      if ((A[i] != A[leng-i-1])){
            pos_palin = i;
            break;
            cout <<"test"<<endl;
      }else{
        pos_palin = -1;
      }
    }

}
void palin::sumpalin(string A){
  int leng = A.size();
  int i=0,j=0;
  for (i = 0; i < leng/2; i++){
      if ((A[i] != A[leng-1-i])){
            j++;
      }
    }

    if(j!=0){
      sum_palin = j;
    }else {
      sum_palin = -1;
    }

}

bool rever_palin(int n, string A){
    int leng = A.size();
    //cout<<A.size()<<endl;
    int i = 0;
    for (i = 0; i <= leng/2; i++){
        if ((A[leng-i-1] != A[i])&& (n >=0) ){
            A.erase((leng-i-1),1);
            return rever_palin(n-1, A);
        }
        else if ((A[leng-i] != A[i]) && (n <0) ||(leng == 0)){
            return false;
        }
    }
    return true;
}
