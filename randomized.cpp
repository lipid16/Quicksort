#include<iostream>
#include<cstdlib>

using namespace std;


class Randomized{

public:

    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    // Partitioning the array on the basis of values at high as pivot value.
    int Partition(int a[], int first, int last)
    {
        int pivot, index, i;
        index = first;
        pivot = last;

        // Getting index of pivot.
        for(i=first; i < last; i++)
        {
            if(a[i] < a[pivot])
            {
                swap(&a[i], &a[index]);
                index++;
            }
        }
        // Swapping value at last and at the index obtained.
        swap(&a[pivot], &a[index]);

        return index;
    }

    // Random selection of pivot.
    int RandomPivotPartition(int a[], int first, int last)
    {
        int pvt, n, temp;
        n = rand();
        // Randomizing the pivot value in the given subpart of array.
        pvt = first + n%(last-first+1);

        // Swapping pvt value from last, so pvt value will be taken as pivot while partitioning.
        swap(&a[last], &a[pvt]);

        return Partition(a, first, last);
    }

    // Implementing QuickSort algorithm.
    int QuickSort(int a[], int first, int last)
    {
        int pindex;
        if(first < last)
        {
            // Partitioning array using randomized pivot.
            pindex = RandomPivotPartition(a, first, last);
            // Recursively implementing QuickSort.
            QuickSort(a, first, pindex-1);
            QuickSort(a, pindex+1, last);
        }
        return 0;
    }

};
