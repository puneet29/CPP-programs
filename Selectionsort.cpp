#include <iostream>

using namespace std;

void selSort (int a[], int l){
    if(l<1)
        return;
    int maximum=a[0], point=0;
    for (int i=0; i<l; i++){
        if(maximum<a[i]){
            maximum=a[i];
            point = i;
        }
    }
    a[point]=a[l-1];
    a[l-1]=maximum;
    selSort(a, l-1);
    cout<<a[l-1]<<" ";
}

int main(){
    int a[]={5,4,3,2,1};
    selSort(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
