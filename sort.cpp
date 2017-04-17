#include "sort.h"

/**
  * Insertion sort, Quicksort, Mergesort and External Mergesort implementations
  *
  */

/**
 * @brief Sort::Sort
 */
Sort::Sort()
{

}

void Sort::insertionsort(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size() - 1; i++){
        int k = i;
        while(k > 0 && arr[k - 1] > arr[k]){
            swap(arr, k-1, k);
            k--;
        }
    }
}

void Sort::mergesort(std::vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1;
    mergesort(arr, lo, hi);
}

void Sort::mergesort(std::vector<int> &arr, int lo, int hi)
{
    if(lo < hi){
        int mid = (lo + hi) / 2;
        mergesort(arr, lo, mid);
        mergesort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
}

/**
 * @brief Sort::merge Leans heavily on the implementation from http://quiz.geeksforgeeks.org/merge-sort/
 * @param arr
 * @param left
 * @param mid
 * @param right
 */
void Sort::merge(std::vector<int> &arr, int lo, int mid, int hi)
{

    int i, j, k;                                      /** Index **/
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    std::vector<int> L(n1,0), R(n2,0);  /** buffers to hold elements for merge **/

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[lo + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = lo; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Sort::quicksort
 * @param arr
 */
void Sort::quicksort(std::vector<int> &arr)
{
    quicksort(arr, 0, arr.size() - 1);
}

/**
 * @brief Sort::quicksort
 * @param arr
 * @param left
 * @param right
 */
void Sort::quicksort(std::vector<int> &arr, int lo, int hi)
{
    int p;
    if((hi - lo) > 0){
        p = partition(arr, lo, hi);
        quicksort(arr, lo, p - 1);
        quicksort(arr, p + 1, hi);
    }
}

/**
 * @brief Sort::partition Implementation from Steven S. Skiena's The Algorithm Design Manual
 * @param arr
 * @param left
 * @param right
 * @return hi
 */
int Sort::partition(std::vector<int> &arr, int lo, int hi)
{
    int i;         // counter
    int p;         // pivot element index
    int firsthigh; // divider position for pivot element

    p = hi;
    firsthigh = lo;
    for(i = lo; i < hi; i++){
        if(arr[i] < arr[p]){
            swap(arr, i, firsthigh);
            firsthigh++;
        }
    }

    swap(arr, p, firsthigh);

    return firsthigh;
}

/**
 * @brief Sort::swap
 * @param arr
 * @param lo
 * @param hi
 */
void Sort::swap(std::vector<int> &arr, int lo, int hi)
{
    int c = arr[lo];
    arr[lo] = arr[hi];
    arr[hi] = c;
}

/**
 * @brief Sort::external_mergesort
 * Read in 100MB at a time;
 * sort via Quicksort;
 * commit to file(s);
 * REPEAT
 * @param filePath
 */
static void Sort::external_mergesort(std::string filePath)
{
    ext_merge();
}
