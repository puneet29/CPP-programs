#include <iostream>

using namespace std;

void vowDel(char *str, int i=0, int j=0){
    if(str[i]=='\0'){
        str[j]='\0';
        return;
    }
    if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        vowDel(str, i+1, j);
    else{
        str[j]=str[i];
        vowDel(str, i+1, j+1);
    }
}

int main(){
    char str[]="My name is Puneet";
    vowDel(str);
    cout<<str;
    return 0;
}
