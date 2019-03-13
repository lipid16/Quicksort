#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

class pivot_median
{
    private:
        int size;

public:

    void setSize(int s){
        size = s;
    }

    void quickSort(int arr[], int first, int last)
    {
        if(last < first)
            return;

        int j = partition(arr, first, last);
        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }

    int partition(int arr[], int first, int last)
    {
        int length;
        int median = getPivotUsingMedian(arr,first,last, size/2);
        int pivotIndex;
        for (pivotIndex = first; pivotIndex < last; pivotIndex++)
            if(arr[pivotIndex] == median)
                break;
        swap(arr, pivotIndex, first);

        //Regular partition code of Quicksort
        int i = first;
        int j = last + 1;
        int p = arr[first];
        while (true) {

            // find item on lo to swap
            while (i<last && arr[++i] < p)
                if (i == last)
                    break;

            // find item on hi to swap
            while (j>first && p < arr[--j])
                if (j == first)
                    break;

            // check if pointers cross
            if (i >= j)
                break;
            swap(arr, i, j);
        }
        // put partitioning item p at a[j]
        swap(arr, first, j);

        return j;
    }

    void swap(int arr[],int i, int j)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    int getPivotUsingMedian(int arr[], int first, int last, int k) {

        if (k >= 0 && k <= last - first + 1) {

            int n = last-first+1;        //size of array

            int median[(n+4)/5];
            //int *median = new int[(n+4)/5];
            //int median[] = arr[(n+4)/5];       //holds the median for each group
            int i;

            //For each group of 5 find the median and store in median[]
            // total number of groups would be floor(n/5)
            for (i=0; i<n/5; i++)
                median[i] = findMedian(arr, first+i*5, first+i*5 + 5);

            if (i*5 < n)        //For last group with less than 5 elements
            {
                median[i] = findMedian(arr, first+i*5, first+i*5 + n%5);
                i++;
            }

            //Recursively call getPivotUsingMedian to find Median of Median
            //If array has only one element, no need of recursive call
            return (i == 1)? median[i-1]: getPivotUsingMedian(median, 0, i-1, i/2);
        }

        //If k is larger than number of elements in array
        return 0;
    }

    int findMedian(int arr[], int first, int last)
    {
        sort(arr, arr+last);  // Sort the array
        return arr[(first+last)/2];   // Return middle element
    }
};

