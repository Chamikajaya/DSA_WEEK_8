#include <iostream>
#include <vector>

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int largest = root;
    int left = (2 * root)+ 1;
    int right = (2 * root)+ 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    // if largest != root, then we should do a swap
    if (largest != root){
        swap(arr[largest], arr[root]);
        // Call heapify recursively in order to make the sub tree a heap
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    // To build the heap use the heapify above implemented
    // index of first non leaf node
    int x = (n / 2) - 1;
    for (int i = x; i >= 0; i--){
        heapify(arr, n, i);
    }
    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        // Rebuild the heap to maintain the heap property
        heapify(arr, i, 0);  // Need to pass 0 as root because rebuilding happens from root
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
    int heap_arr[] = {5, 2, 9, -1, 0, 12, 14, 15};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"My custom Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array for my input "<<endl;
    displayArray(heap_arr, n);


}