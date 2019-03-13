#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
    int arr[10000000];

    srand(time(NULL));
    for(int i=0; i<= 10000000; i++)
    {
        //for(int j=0; j<i; j++)
        arr[i] = rand()%200000+1;
        cout<<arr[i]<<" ";
       // QuicksortUsingMedianAsPivot.main(arr);
    }
    cout<<endl;
}
