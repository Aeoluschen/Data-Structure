#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class palin{
public:
  int pos_palin;
  int sum_palin;
  int rev_sum_palin;
  int rev_pos_palin;
  void rev_pospalin(string);
  void rev_sumpalin(string);
  void pospalin(string);
  void sumpalin(string);
};

bool rev_remv_word(int ,string);
bool remv_word(int ,string);

int main(int argc, char const *argv[]) {
    /* code */
    int n = 0;
    string word;
    palin P;
    scanf("%d\n", &n);
    while (getline(cin,word)) {
        /* code */
        //remv_space(word);
        if(remv_word(n,word)||rev_remv_word(n,word)){
            cout <<"Yes"<<"\n";
        }else {
            cout <<"No"<<"\n";
        };
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
                //cout <<"test"<<endl;
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
    void palin::rev_pospalin(string A){
          int leng = A.size();
          int i=0,j=0;
          for (i = leng-1; i >= leng/2+1; i--){
              if ((A[i] != A[leng-i-1])){
                    rev_pos_palin = i;
                    break;
                    //cout <<"test"<<endl;
              }else{
                rev_pos_palin = -1;
              }
            }

        }
        void palin::rev_sumpalin(string A){
              int leng = A.size();
              int i=0,j=0;
              for (i = leng-1; i > leng/2; i--){
                  if ((A[i] != A[leng-1-i])){
                        j++;
                  }
                }

                if(j!=0){
                  rev_sum_palin = j;
                }else {
                  rev_sum_palin = -1;
                }

            }

bool remv_word(int n ,string A){
  string A1=A;
  string A2=A;
  int leng = A.size();
  palin P,P1,P2;
  P.pospalin(A);
  P.sumpalin(A);
  P1 = P;
  P2 = P;
  if ((P.pos_palin >= 0)&& n>0){
    //cout <<"step1:deleted word :"<<A[P.pos_palin]<<endl;
    A1.erase(P.pos_palin,1);
    P1.pospalin(A1);
    P1.sumpalin(A1);
    if (A1.size()==1){
      //cout << "condition break" << endl;
      return true;
    }
    if ( P1.sum_palin < P.sum_palin){
      return remv_word(n-1 ,A1);
    }else if (P1.sum_palin >= P.sum_palin){
      //cout <<"step2:deleted word :"<<A[leng-P.pos_palin-1]<<endl;
      A2.erase(leng-P.pos_palin-1,1);
      P2.pospalin(A2);
      P2.sumpalin(A2);
      return remv_word(n-1 ,A2);
    }

  }else if ((P.pos_palin < 0)&& n>=0) {
    return true;
  }else {
    return false;

  }
}

  bool rev_remv_word(int n ,string A){
    string A1=A;
    string A2=A;
    int leng = A.size();
    palin P,P1,P2;
    P.rev_pospalin(A);
    P.rev_sumpalin(A);
    P1 = P;
    P2 = P;
    if ((P.rev_pos_palin >= 0)&& n>0){
      cout <<"step1:deleted word :"<<A[P.rev_pos_palin]<<endl;
      A1.erase(P.rev_pos_palin,1);
      P1.rev_pospalin(A1);
      P1.rev_sumpalin(A1);
      if (A1.size()==1){
        cout << "condition break" << endl;
        return true;
      }
      if ( P1.sum_palin <= P.sum_palin){
        return remv_word(n-1 ,A1);
      }else if (P1.sum_palin > P.sum_palin){
        cout <<"step2:deleted word :"<<A[leng-P.rev_pos_palin-1]<<endl;
        A2.erase(leng-P.rev_pos_palin-1,1);
        P2.rev_pospalin(A2);
        P2.rev_sumpalin(A2);
        return remv_word(n-1 ,A2);
      }

    }else if ((P.rev_pos_palin < 0)&& n>=0) {
      return true;
    }else {
      return false;

    }
}
