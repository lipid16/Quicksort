#include<iostream>
#include<iomanip>
using namespace std;

class quick_real
{
    //private static final int INSERTION_SORT_CUTOFF = 7;  //if array size is less than CUTOFF insertion sort would be called
    //private static final int MEDIAN_OF_3_CUTOFF = 40;

public:

    void quickSort(int arr[], int first, int last)
    {
        int size = last - first + 1;
        if(size <= 7)
        {
            insertion_sort(arr, first, last);
            return;
        }

        int part = partition(arr, first, last);

        int lsize = 0;
        int rsize = 0;
        if ((part - 1) >= first)
            lsize = (part - 1) - first;
        if ((part + 1) <= last)
            rsize = last - (part + 1);

        if (lsize < rsize) {
            quickSort(arr, first, part - 1);
            quickSort(arr, part + 1, last);
        } else {
            quickSort(arr, part + 1, last);
            quickSort(arr, first, part - 1);
        }
    }

    int partition(int arr[], int first, int last) {

        int pivot_median = getPivot(arr,first,last);
        swap(arr, first, pivot_median);

        int i = first;
        int j = last + 1;
        int p = arr[first];
        while (true) {

            while (i<last && arr[++i] < p)
                if (i == last)
                    break;

            while (j>first && p < arr[--j])
                if (j == first)
                    break;

            if (i >= j)
                break;
            swap(arr, i, j);
        }

        swap(arr, first, j);

        return j;
    }

    void insertion_sort (int arr[], int first, int last)
    {
	 	int j, temp;

        for (int i = first; i <= last; i++)
        {
            j = i;

            while (j > first && arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
		}
    }
 /*   void insertionSort(int arr[], int first, int last) {
        for (int i = lo; i <= hi; i++)
            for (int j = i; j > lo && arr[j] < arr[j-1]; j--)
                swap(arr, j, j-1);
    }*/


    void swap(int arr[],int i, int j)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    int getPivot(int arr[], int start, int end){

        int size = end - start + 1;

        if(size <= 40)
        {
            return median(arr, start, (start + end)/2, end);
        }

        int length = size / 8;
        int middle = (start + end)/2;

        int pivot1 = median(arr, start, start + length, start + 2 * length);
        int pivot2 = median(arr, end, end - length, end - 2 * length);
        int pivot3 = median(arr, middle, middle - length, middle + length);

        return median(arr, pivot1, pivot2, pivot3);
    }

    int median(int a[], int i, int j, int k)
    {
        return ((a[i] < a[j]) ?
                ((a[j] < a[k]) ? j : (a[i] < a[k]) ? k : i) :
                ((a[k] < a[j]) ? j : (a[k] < a[i]) ? k : i));
    }


};

/*int main()
{
    quick_real q1;
     int arr[10] = {3,5,2,9,6,8,4,1,4,3};
     q1.quickSort(arr, 0, 9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}*/
