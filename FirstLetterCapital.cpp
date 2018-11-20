#include <iostream>

using namespace std;

void uCase(char *str, int start=0){
    int i;
    if(str[start]!=' ')
        str[start]-=32;
    for(i=start; str[i]!=' '; i++){
        if(str[i]=='\0')
            return;
    }
    uCase(str, i+1);
}

int main(){
    char str[]="i love programming";
    uCase(str);
    cout<<str;
    return 0;
}
