#include <iostream>

using namespace std;

int monkey (int a, int pointer=0){
    int sum1=0, sum2=0;
    if(a-pointer==2){
        return 2;
    }
    else if(a-pointer==1){
        return 1;
    }
    sum1+=monkey(a, pointer+1);
    sum2+=monkey(a, pointer+2);
    return (sum1+sum2);
}

int main(){
    int steps=6;
    cout<<monkey(steps);
    return 0;
}
