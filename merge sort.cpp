#include <iostream>

using namespace std;

void mergePost(int arr[], int low, int mid, int high){
    int n1=mid-low+1;
    int n2=high-mid;

    int l[n1], r[n2];

    for(int i=0; i<n1; i++){
        l[i]=arr[low+i];
    }
    for(int i=0; i<n2; i++){
        r[i]=arr[mid+1+i];
    }
    int i=0, j=0, k=low;

    while(i<n1 && j<n2){
        if(l[i]>r[j]){
            arr[k]=r[j];
            j++;
        }
        else{
            arr[k]=l[i];
            i++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=l[i];
        k++; i++;
    }

    while(j<n2){
        arr[k]=r[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int low, int high){
    if(high-low <=0){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    mergePost(arr, low, mid, high);
}

int main(){
    int arr[]={12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, 5);
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<"    ";
    }
    return 0;
}
