#include<iostream>
#include<iomanip>
#include "algorithm"
//#include "randomized.cpp"
using namespace std;

class random_median
{
public:

    int findElement(int array[], int k, int length)
    {
        int first=0, last= length-1;

        if(k < 1 || k > length)
        {
            cout<<"Invalid input. Returning 0..."<<endl;
            return 0;
        }

        k--;
        while(first < last)
        {
            int p = partition(array,first,last);

            if (k < p)
                last = p-1;

            else if (k > p)
                first = p+1;

            else
                return array[k];

        }
        return array[k];
    }

    int partition(int arr[], int first, int last) {
        int i = first, j = last-1;
        while (true)
        {
            while (arr[++i] < arr[first])
                if (i == last) break;
            while (arr[first] < arr[--j])
                if (j == first) break;
            if (i >= j) break;
            swap(arr, i, j);
        }
        swap(arr, first, j);
        return j;
    }

    void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] =array[j];
        array[j] = temp;
    }

    void printArray(int arr[],int first, int last)
    {
        for(int i=first; i<last; i++)
        {
            cout<<arr[i]<<"  "<<endl;
        }
    }


};
