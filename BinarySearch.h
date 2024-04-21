#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
using namespace std;
class binary
{
public:
    bool binarySearch(int arr[], int start, int end, int value)
    {
        while (start <= end) {
               int m = start + (end - start) / 2;

               // Check if x is present at mid
               if (arr[m] == value)
                   return true;

               // If x greater, ignore left half
               if (arr[m] < value)
                   start= m + 1;

               else
                   end = m - 1;
           }

        return false;
    }

};

#endif // BINARYSEARCH_H
