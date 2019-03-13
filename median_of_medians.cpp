#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

class MedianOfMedians
{
private:
    int group = 3;
    int size = 5;

public:


    void findMedian(int array[], int x)
    {
        //int size;
        int median = findMedianUtil(array, x,0,size-1);

        if(x == size/2)
            cout<<"Median: "<<median<<endl;
        else
            cout<<"Smallest element is: "<<median<<endl;
    }

    int findMedianUtil(int array[], int x, int first, int last)
    {
        if(first == last)
        {
            return array[first];
        }

        int m = partition(array, first, last);

        int len = m - first; //len = m - first + 1;

        if(len == x)
        {
            return array[m];
        }

        if(len > x)
        {
            return findMedianUtil(array, x, first, m-1);
        }
        else
        {
            return findMedianUtil(array, x-len, m+1, last);
        }
    }

    int partition(int array[], int first, int last)
    {
       int pivotValue = getPivotValue(array, first, last);

        while(first < last)
        {
            while(array[first] < pivotValue)
            {
                first++;
            }

            while(array[last] > pivotValue)
            {
                last--;
            }

            if(array[first] == array[last])
            {
                first++;
            }
            else if(first < last)
            {
                int temp = array[first];
                array[first] = array[last];
                array[last] = temp;
            }
        }
        return last;
    }

    int getPivotValue(int array[], int first, int last)
    {
        int len;
        if(last-first+1 <= 5)
        {
            sort(array,array+last);
            return array[size/2];
        }

        int temp[size/2];

        //int *medians = new int[(int)ceil((double)(last-first+1)/group)];
        int med_size = (last-first+1)/group;
        int medians[med_size];
        int medianIndex = 0;

        while(first <= last)
        {
            len = min(group, last-first+1);
            temp[len];

            for(int j=0;j<temp[len] && first <= last;j++)
            {
                temp[j] = array[first];
                first;
            }

            sort(temp, temp+len);

            medians[medianIndex] = temp[temp[len]/2];
            medianIndex++;
        }
        return (medians, 0, medians[len]-1);
    }

};
