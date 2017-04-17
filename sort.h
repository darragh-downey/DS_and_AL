#ifndef SORT_H
#define SORT_H

#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

class Sort
{
public:
    Sort();
    static void quicksort(std::vector<int> &arr);
    static void external_mergesort(std::vector<int> &arr);
    static void mergesort(std::vector<int> &arr);
    static void insertionsort(std::vector<int> &arr);
private:
    static void quicksort(std::vector<int> &arr, int lo, int hi);
    static void mergesort(std::vector<int> &arr, int lo, int hi);
    static void merge(std::vector<int> &arr, int lo, int mid, int hi);
    static int partition(std::vector<int> &arr, int lo, int hi);
    static void swap(std::vector<int> &arr, int lo, int hi);
};

#endif // SORT_H
