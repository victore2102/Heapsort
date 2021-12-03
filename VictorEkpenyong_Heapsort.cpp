#include <iostream>

using namespace std;

// This function exchanges the values of var1 and var2.
void Swap(int& var1, int& var2)
{
   //temp variable created to swap passed in variables and memory locations
   int temp;
   temp = var1;
   var1 = var2;
   var2 = temp;
}

// This function performs the 'percolate down' operation from node arr[index].
void PercolateDown(int arr[], int index, int size)
{
    //Conditional statements which sees if child of index has a sibling to the right of them to be compared to
    //2 leaves attached to parent (passed in index)
    if(2*index +1 <= size)
    {
        //Conditional statements which compares left and right child leaves
        //Left leaf smaller
        if(arr[2*index] < arr[2*index + 1])
        {
            //Conditional statements to see if parent (passed in index) is larger than left child; If so Swap, if not, function stops
            if(arr[index] > arr[2*index])
            {
                Swap(arr[index], arr[2*index]);
                return;
            }
            //Parent (passed in index) smaller than left child
            else
            {
                return;
            }
        }
        //Right leaf smaller
        else
        {
            //Conditional statements to see if parent (passed in index) is larger than right child; If so Swap, if not, function stops
            if(arr[index] > arr[2*index + 1])
            {
                Swap(arr[index], arr[2*index + 1]);
                return;
            }
            //Parent (passed in index) smaller than right child
            else
            {
                return;
            }
        }
    }
    //1 leaf attached to parent (passed in index)
    else
    {
        //Conditional statements to see if parent (passed in index) is larger than left child; If so Swap, if not, function stops
        if(arr[index] > arr[2*index])
        {
            Swap(arr[index], arr[2*index]);
            return;
        }
        //Parent (passed in index) smaller than left child
        else
        {
            return;
        }
    }


}

// This function swaps the minimum-value element with the last element
// in arr[first..last] and leaves (does not delete) the minimum-value element.
// After DeleteMin, the heap shrinks by 1.
void DeleteMin(int arr[], int& last)
{
    //integer heap size (h_size) set equal to passed in last value
    int h_size = last;
    //Swap between root (smallest element) and current last element
    Swap(arr[1], arr[h_size]);
}

// This functions coverts the array arr[] to a heap, i.e., it has the *head-order*
// property while it is interpreted as a complete binary tree.
void BuildHeap(int arr[], int size)
{
    //Loop taking passed in size and starts with parent of last leaf(size) and decrements and terminates once i = 1
    for(int i = size/2; i>0; i--)
    {
        //Percolate function called passing in current i value and passed in size value
        PercolateDown(arr, i, size);
    }
}


// This is the 'heapsort' function that sorts the array arr[] in *descending* order.
// You may want to use the BuildHeap and DeleteMin functions in this function.
void Heapsort(int arr[], int size)
{
    //integer heap size (size_h) set equal to passed in size
    int size_h = size;
    //Buildheap function called to establish heap order initialy
    BuildHeap(arr, size_h);

    //While loop which calls DeleteMin and decrements heap size; Buildheap called again to establish heap order; Loop terminates once heap size = 1
    while(size_h > 1)
    {
        DeleteMin(arr, size_h);
        size_h--;
        BuildHeap(arr, size_h);
    }

}

int main()
{
   cout << "Please enter the length (number of elements) of the input array: ";
   int size;
   cin >> size;

   if(size <= 0) {
      cout << "Illegal input array length!" << endl;
      return 0;
   }

   int* arr = new int[size+1];

   cout << "Please enter each element in the array" << endl;
   cout << "(each element must be an integer within the range of int type)." << endl;
   for(int i = 1; i <= size; i++) {
      cout << "arr[" << i << "] = ";
      cin >> arr[i];
   }

   cout << "The input array arr[] is: ";
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   Heapsort(arr,size);

   cout << "After heapsort, the sorted array arr[] is: ";
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   delete [] arr;

   return 0;
}
