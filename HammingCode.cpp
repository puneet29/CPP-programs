#include <iostream>

using namespace std;

int main(){
  int data[10];
  int dataAtRec[10], c, c1, c2, c3;

  cout<<"Enter 4 bits of data one by one:"<<endl;
  cin>>data[2];
  cin>>data[4];
  cin>>data[5];
  cin>>data[6];

  data[0]=data[2]^data[4]^data[6];
  data[1]=data[2]^data[5]^data[6];
  data[3]=data[4]^data[5]^data[6];

  cout<<"Encoded data is: "<<endl;
  for (int i=0; i<7; i++){
    cout<<data[i];
  }

  cout<<endl<<"Enter received data bits one by one: "<<endl;
  for (int i=0; i<7; i++){
    cin>>dataAtRec[i];
  }

  c1=dataAtRec[0]^dataAtRec[2]^dataAtRec[4]^dataAtRec[6];
  c2=dataAtRec[1]^dataAtRec[2]^dataAtRec[5]^dataAtRec[6];
  c3=dataAtRec[3]^dataAtRec[4]^dataAtRec[5]^dataAtRec[6];

  c= c1*1 + c2*2 + c3*4;

  if(c==0){
    cout<<"There is no error while transmission of data!"<<endl;
  }
  else{
    cout<<"Error on position: "<<c<<endl;

    cout<<"Data sent: "<<endl;
    for(int i=0; i<7; i++){
      cout<<data[i];
    }

    cout<<endl<<"Data received: "<<endl;
    for(int i=0; i<7; i++){
      cout<<dataAtRec[i];
    }

    cout<< endl<<"Corrected data: "<<endl;

    if(dataAtRec[c-1]==0){
      dataAtRec[c-1]=1;
    }
    else{
      dataAtRec[c-1]=0;
    }
    for(int i=0; i<7; i++){
      cout<<dataAtRec[i];
    }
  }

  return 0;
}
