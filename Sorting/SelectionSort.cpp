#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
void selectionSort(int a[], int size){
    int i, j, min, temp;
    for(i = 0; i < size - 1; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
void printArr(int a[],int s){
    cout<<"\n The sorted Array is: ";
    for(int i = 0; i < s; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int size;
    cout<<"\nEnter array size: ";
    cin>>size;
    int *a = new int(size);
    cout<<"\nEnter elements: \n";
    for(int i = 0; i < size; i++){
        int ele;
        cout<<"\nElement "<<i+1<<": ";
        cin>>ele;
        a[i] = ele;
    }


    selectionSort(a,size);
    printArr(a,size);
    getch();
    return 0;
}