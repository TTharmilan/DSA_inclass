#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root){
   int largest = root; // Initialize largest as root
   int left = 2 * root + 1; // left = 2*i + 1
   int right = 2 * root + 2; // right = 2*i + 2
 
   // eft child is larger than root
   if (left < n && arr[left] > arr[largest]){
       largest = left;
   }
   //right child is larger than largest
   if (right < n && arr[right] > arr[largest]){
       largest = right;
   }
   //  largest is not root
   if (largest != root) {
       swap(arr[root], arr[largest]);
 
       // heapify sub-tree
       heapify(arr, n, largest);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
       // rearrange array
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);
 
   // getting elements from heap
   for (int i = 0; i < n; i++) {
       // Move current root to end
       swap(arr[0], arr[n-1-i]);
 
       // heapify the reduced heap
       heapify(arr, n-1-i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {2,17,13,21,9,6,15,4,32};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
