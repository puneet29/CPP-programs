#include <iostream>

using namespace std;

class change{
  char str[100];
  int i;
public:
  void encrypt(){
    for (i=0; str[i]!='\0'; i++){
      str[i]=str[i]+5;
    }
    cout<<"Encrypted data is: "<<str<<endl;
    cout<<"Data encrypted successfully!"<< endl;
  }

  void decrypt(){
    for(i=0; str[i]!='\0'; i++){
      str[i]=str[i]-5;
    }
    cout<<"Decrypted data is: "<<str<<endl;
    cout<<"Data decrypted successfully"<<endl;
  }

  void input(){
    cout<<"Enter text: ";
    cin>>str;
  }
};

int main(){
  change x;
  x.input();
  x.encrypt();
  x.decrypt();
  return 0;
}
