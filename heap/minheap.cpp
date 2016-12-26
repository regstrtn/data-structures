#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int heapsize;

void heapify(int arr[], int index) {
    int i=index, j, k, l, temp;
    while(i<(heapsize-1)/2) {
        j = 2*i+1;
        if(j<heapsize-1 && arr[j+1]<arr[j]) j = j+1;
        if(arr[i]<=arr[j]) break;
        if(arr[i]>arr[j]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
         }
    }
}

void insert(int arr[], int val) {
    arr[heapsize] = val;
    heapsize++;
    int i = heapsize-1;
    int temp = arr[i];
    while(i>0 && arr[(i-1)/2]>arr[i]) {
        temp = arr[i];
        arr[i] = arr[(i-1)/2];
        arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void delheap(int arr[], int val) {
    int index=0, i, j, k, l;
    while(arr[index]!=val) index++;
    arr[index] = arr[heapsize - 1];
    heapsize--;
    heapify(arr, index);
}

int main() {
    int i, q, j, k, l, m, n;
    cin>>n;
    heapsize = 0;
    int arr[n];
    for(i=0;i<n;i++) {
        cin>>q;
        if(q==1) {
            cin>>j; 
            insert(arr, j);
        }
        else if(q==2) {
            cin>>j;
            delheap(arr, j);
        }
        else if(q==3) {
            cout<<arr[0]<<endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
