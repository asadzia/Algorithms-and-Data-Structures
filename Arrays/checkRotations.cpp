/* A program to check the number of rotations of a sorted array */
#include <iostream>

using namespace std;

int checkRotations(int arr[], int size)
{
    int min_index = 0;
    int min = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int main(int argc, char** args)
{
    int arr[] = {3,4,5,6,7,1,2};
    int size = (sizeof(arr)/sizeof(arr[0]));

    cout << "Number of rotations: " << checkRotations(arr, size) << endl;

    return 0;
}

