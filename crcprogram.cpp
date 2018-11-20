#include <iostream>
#define SIZE 20

using namespace std;

class CRC{
  int mess[SIZE], div[SIZE], temp[SIZE], rem[SIZE];
  int rmes[SIZE], rdiv[SIZE], rtemp[SIZE], rrem[SIZE];
  int msize, dsize, tsize;
  int rmsize, rtsize;
public:
  CRC(){
    for (int i=0; i<SIZE; i++){
      mess[i]=div[i]=temp[i]=rem[i]=-1;
      rmes[i]=rdiv[i]=rtemp[i]=rrem[i]=-1;
      msize=dsize=tsize=rmsize=rtsize=0;
    }
  }
  void getdata(){
    cout<<"Enter size of message bit: ";
    cin>>msize;

    cout<<"Enter bit one by one: "<<endl;
    for (int i=0; i<msize; i++){
      cin>>mess[i];
    }

    cout<<"Enter size of divisor bit: ";
    cin>>dsize;

    cout<<"Enter bit one by one: "<<endl;
    for (int i=0; i<dsize; i++){
      cin>>div[i];
    }
  }
  void display(){
    cout<<"Entered message bit is "<<endl;
    for(int i=0;i<msize;i++)
      cout<<'\t'<<mess[i];

    cout<<endl<<"Entered divisor bit is "<<endl;
    for(int i=0;i<dsize;i++)
    cout<<'\t'<<div[i];
  }
  void convert(){

    //Appending 0s to the end of mess[] and incrementing msize
    for(int i=0; i<dsize-1; i++){
      mess[i+msize]=0;
    }
    msize+=dsize-1;

    cout<<endl<<"New message bit is: "<<endl;
    for(int i=0; i<msize; i++){
      cout<<'\t'<<mess[i];
    }

    //Creating a temporary array to store the remainders alongside.
    //Initialise it to the values of the message bits.
    tsize=msize;
    for(int i=0; i<msize; i++){
      temp[i]=mess[i];
    }

    //Division:
    for(int i=0; i<msize-dsize+1; i++){
      int j=0;
      int k=i;

      if(temp[k]>=div[j]){
        while(j<dsize){
          if(temp[k]==div[j]){
            temp[k]=0;
          }
          else{
            temp[k]=1;
          }
          j++; k++;
        }
      }
    }

    for(int i=0; i<msize; i++){
      mess[i]+=temp[i];
    }

    //--------------------------------------------------------------------------

    cout<<endl<<"CRC code generated here is: "<<endl;
    for (int i=0; i<msize; i++){
      cout<<mess[i];
    }
  }
  void crccheck(){
    cout<<endl<<"Enter size of received message bit: ";
    cin>>rmsize;

    cout<<"Enter received bit one by one: "<<endl;
    for (int i=0; i<rmsize; i++){
      cin>>rmes[i];
    }

    rtsize= rmsize;

    for(int i=0; i<rtsize; i++){
      rtemp[i]=rmes[i];
    }

    //Division:
    for(int i=0; i<rmsize-dsize+1; i++){
      int j=0;
      int k=i;

      if(rtemp[k]>=div[j]){
        while(j<dsize){
          if(rtemp[k]==div[j]){
            rtemp[k]=0;
          }
          else{
            rtemp[k]=1;
          }
          j++; k++;
        }
      }
    }

    int check=0;
    cout<<"Remainder is: "<<endl;
    for(int i=0; i<rmsize; i++){
      cout<<'\t'<<rtemp[i];
      if(rtemp[i]==1){
        check=1;
      }
    }

    if(check==0)
      cout<<endl<<"There is no error!";
    else
      cout<<endl<<"There is error!";

  }

};

int main()
{
CRC c;

c.getdata();
c.display();
c.convert();
c.crccheck();

return 0;
}
