#include <iostream>

using namespace std;

int main(){
    int str[5]= {6,157,84,855,864};
    for (int i=1; i<=5; i++){
        int j=i;
        while(j>0 && str[j-1]>str[j]){
            int temp=str[j];
            str[j]=str[j-1];
            str[j-1]=temp;
            j--;
        }
    }
    for (int i=0; i<5; i++){
        cout<<str[i]<<endl;
    }
    return 0;
}
