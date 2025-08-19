//Bubble sort in C++
#include<iostream>
using namespace std;

    int main(){

        int temp=0;
        int arr[7] = {64,34,25,12,22,11,90};
        int n = 7;

            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-1-i;j++){
                    if(arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            cout<<"Sorted array: \n";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            return 0;
    }