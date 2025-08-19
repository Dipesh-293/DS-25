//Linear seach 
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n-1];
    cout<<"Enter a sorted array of "<<n-1<<" elements: ";
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]!= (i+1)){
            cout<<"The missing element is: "<<(i+1)<<endl;
            break;
        }
    }

}
