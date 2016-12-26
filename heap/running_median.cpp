#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>

class minheap {
  public:
    //int capacity;
  int *arr;
  int hsize;
  minheap(int capacity) {
     arr = new int[capacity];
     hsize = 0;
  }
  int getmin() {
     return arr[0];
  }
  void swap(int &a, int &b) {
      int temp = a;
      a = b;
      b = temp;
  }
  void heapify(int index) {
     int i, j, temp;
     i = index;
     while(i<=(hsize-1)/2) {
         j = 2*i+1;
         if(j<hsize-1 && arr[j+1]<arr[j]) j++;
         if(arr[i]<=arr[j]) break;
         else if(arr[i]>arr[j]) swap(arr[i], arr[j]);
         i = j;
     }
  }
  void insert(int val) {
     int i, j, temp;
     i = hsize;
     arr[hsize] = val;
     hsize++;
     while(i>0 && arr[(i-1)/2]>arr[i]) {
         swap(arr[(i-1)/2], arr[i]);
         i = (i-1)/2;
     }
  }
  void del(int val) {
      int index = 0; while(arr[index]!=val) index++;
      arr[index] = arr[hsize-1];
      hsize--;
      heapify(index);
  }
};

class maxheap {
  public:
  int *arr;
  int hsize;
  maxheap(int capacity) {
      arr = new int[capacity];
      hsize = 0;
  }
  int getmax() {
      return arr[0];
  }
  void swap(int &a, int &b) {
      int temp = a;
      a = b;
      b = temp;
  }
  void heapify(int index) {
     int i, j, temp;
     i = index;
     while(i<=(hsize-1)/2) {
         j = 2*i+1;
         if(j<hsize-1 && arr[j+1]>arr[j]) j++;
         if(arr[i]>=arr[j]) break;
         else if(arr[i]<arr[j]) swap(arr[i], arr[j]);
         i = j;
     }
  }
  void insert(int val) {
     int i, j, temp;
     i = hsize;
     arr[hsize] = val;
     hsize++;
     while(i>0 && arr[(i-1)/2]<arr[i]) {
         swap(arr[(i-1)/2], arr[i]);
         i = (i-1)/2;
     }
  }
  void del(int val) {
      int index = 0; while(arr[index]!=val) index++;
      arr[index] = arr[hsize-1];
      hsize--;
      heapify(index);
  }
};

using namespace std;
int main() {
    int n, i, j, k, l; 
    float inp;
    float med, temp;
    cin>>n;
    minheap min(n); maxheap max(n);
    cin>>inp; 
    med = inp; max.insert(inp); cout<<med<<endl;
    for(i=0;i<n-1;i++) {
        cin>>inp;
        if(inp>med) min.insert(inp); //insert into minheap
        else        max.insert(inp); //insert into maxheap
        if(min.hsize-max.hsize > 1) {            //del from min and add to max 
            temp = min.getmin();
            max.insert(temp);
            min.del(temp);
        } 
        else if(max.hsize - min.hsize > 1) {
            temp = max.getmax();
            min.insert(temp);
            max.del(temp);
        }
        else {
            temp = 1.0*(min.getmin() + max.getmax())/2.0;
            //even elements
        }
        if(min.hsize>max.hsize) med = min.getmin(); 
        else if(max.hsize>min.hsize)   med = max.getmax(); 
        else if(max.hsize == min.hsize) med = (1.0*(min.getmin()+max.getmax())/2.0);
        cout<<med<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
