#include<cmath>

int binarySearch(const int arr[],int goal, int size)
{
    int first=0;
    int last=size-1;
    int mid;

    while (first<=last)
    {
        mid=(first+last)/2;

        if (arr[mid]== goal)
            return mid;

        else if (arr[mid]< goal)
            first=mid+1;
        else if (arr[mid]>goal)
            last=mid-1;
    }
    return -1;
}

int interpolation(const int arr[], int goal, int size)
{
    int first=0;
    int last=size-1;
    int pos;

    while (first<=last && goal>=arr[first] && goal<=arr[last])
    {
        pos=first+(((last-first)/(arr[last]-arr[first]))*(goal-arr[first]));
        if (arr[pos]==goal)
            return pos;
        if (arr[pos]<goal)
            first=pos+1;
        else
            last=pos-1;
    }
    return -1;
}

int fibbonachi(const int arr[], int goal, int size)
{
    int fibM2=0;
    int fibM1=1;
    int fibM0=fibM1+fibM2;

    while (fibM0 < size)
    {
        fibM2=fibM1;
        fibM1=fibM0;
        fibM0=fibM1+fibM2;
    }

    int offset= -1;

    while (fibM0 > 1)
    {
        int i=std::min(fibM2+offset, goal-1);

        if (arr[i] < goal)
        {
            fibM0=fibM1;
            fibM1=fibM2;
            fibM2=fibM0-fibM1;
        }

        else if (arr[i]>goal)
        {
            fibM0=fibM2;
            fibM1-=fibM2;
            fibM2=fibM0- fibM1;
        }
        else
            return i;
    }

    if (fibM1==1 && arr[offset+1]==goal)
        return offset+1;

    return -1;

}