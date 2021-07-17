package ArrayRotation;
import java.util.Scanner;

class ArrayRotation{

    public static void printArr(int arr[], int size){
        for(int i = 0; i < size; i++){
            print(arr[i]+" ");
        }
    }

    public static void print(String s){
        System.out.print(s);
    }
    public static void println(String s){
        System.out.println(s);
    }
    public static void lRotate(int arr[], int timesToRotate, int size){
        timesToRotate = timesToRotate % size;
        int i, j, k, temp;
        int gcd = Gcd(timesToRotate, size);
        for(i = 0; i < gcd; i++){
            temp = arr[i];
            j = i;
            while(true){
                k = j + timesToRotate;
                if( k >= size) k -= size;
                if( k == i) break;
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }

    }

    public static int Gcd(int num1, int num2){
            if(num2 == 0)
                return num1;
            else
                return Gcd(num2, (num1 % num2));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        print("\nEnter size of array: ");
        int size = sc.nextInt();
        int arr[] = new int[size];
        print("\nEnter elements one by one: ");
        for(int i = 0; i < size; i++){
            println("Element "+(i+1));
            arr[i] = sc.nextInt();
        }
        println("Enter number of times left rotation should be done: ");
        int rot = sc.nextInt();
        sc.close();
        println("After left rotate: ");
        lRotate(arr,rot,size);
        printArr(arr, size);
    }
}