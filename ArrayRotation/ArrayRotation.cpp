#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class ArrayRotation{

    public:

        int gcd(int a, int b){
            if(b == 0) return a;
            else return gcd(b,(a % b));
        }

        void printArr(int arr[],int size){
            for(int i = 0; i < size; i++){
                cout<<arr[i]<<" ";
            }
        }
        void rotateArr(int arr[], int rot, int size){
            rot = rot % size;
            int i, j, k, temp;
            int Gcd = gcd(rot, size);
            for(i = 0; i < Gcd; i++){
                temp = arr[i];
                j = i;
                while(true){
                    k = j + rot;
                    if( k >= size) k -= size;
                    if( k == i) break;
                    arr[j] = arr[k];
                    j = k;
                }
                arr[j] = temp;
            }
        }
};

int main(){
    int size,nOfRot;
    ArrayRotation a;
    cout<<"Welcome to Left rotation of an array program\n";
    cout<<"\nEnter the size of arr: ";
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++){
        int ele;
        cout<<"\nEnter element "<<i+1<<": ";
        cin>>ele;
        arr[i] = ele;
    }
    cout<<"\n Enter number of rotations to be performed: ";
    cin>>nOfRot;
    a.rotateArr(arr, nOfRot, size);
    cout<<"\n The array after preforming "<<nOfRot<<" rotations is: '";
    a.printArr(arr, size);cout<<"'";

    getch();
    return 0;
}