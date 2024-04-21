#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
using namespace std;

class mergesortt
{
    int length=1000;
public:
    void merge(int arr[], int start, int m, int end) {
      int i = start;
      int j = m + 1;
      int k = start;
      int temp[length];

      while (i <= m && j <= end) {
        if (arr[i] <= arr[j]) {
          temp[k] = arr[i];
          i++;
          k++;
        } else {
          temp[k] = arr[j];
          j++;
          k++;
        }

      }

      while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;

      }
      while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
      }

      for (int p = start; p <= end; p++) {
        arr[p] = temp[p];
      }
    }
    void mergeSort(int arr[], int start, int end) {
      if (start< end) {
        int m = (start+ end) / 2;
        mergeSort(arr, start, m);
        mergeSort(arr, m + 1, end);
        merge(arr, start, m, end);
      }
    }
};

#endif // MERGESORT_H
