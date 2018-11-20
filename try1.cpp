#include <iostream>

using namespace std;

int[] mergefunc(int arr1[], int arr2[], int size1, int size2){

}

void mergeSort(int arr[], int arrsize){
    if(arrsize>1){
        int arr1[arrsize/2], arr2[arrsize/2];
        for(int i=0; i<arrsize/2; i++){
            arr1[i]=arr[i];
        }
        for(int i=arrsize/2; i<arrsize; i++){
            arr1[i]=arr[i];
        }
        mergefunc(arr1, arr2, arrsize/2)
    }
}

int main(){
    int arr[]={5,4,3,2,6,1};
    mergeSort(arr, 6);
    return 0;
}
