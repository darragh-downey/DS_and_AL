#include <chrono>
#include <ctime>
#include <random>

#include "bst.h"
#include "sort.h"

// There are other clocks, but this is usually the one you want.
// It corresponds to CLOCK_MONOTONIC at the syscall level.
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
//using namespace std::literals::chrono_literals;

using namespace std;

int main(int argc, char *argv[])
{
    /**
    BST bst(124);
    bst.insert(12);
    bst.insert(435);
    bst.insert(3554);
    bst.insert(1);
    bst.insert(4);

    bst.printInOrder();
    //bst.printPreOrder();
    //bst.printPostOrder();

    bst.contains(4);
    **/

    time_point<Clock> start = Clock::now();

    std::srand(std::time(0));
    std::vector<int> ab;

    for(int i = 0; i < 1000; i++){
        int rndm = std::rand();
        ab.push_back(rndm);
    }

    std::vector<int> bc = ab;
    std::vector<int> cd = bc;

    std::cout << "unsorted..." << std::endl;

    time_point<Clock> inst = Clock::now();
    Sort::insertionsort(ab);
    time_point<Clock> inend = Clock::now();

    std::cout << "insertion sorted..." << std::endl;

    //for(int i = 0; i < ab.size()-1; i++)
    //        std::cout << ab[i] << std::endl;

    time_point<Clock> mst = Clock::now();
    Sort::mergesort(ab);
    time_point<Clock> mend = Clock::now();

    std::cout << "mergesorted..." << std::endl;

    time_point<Clock> qst = Clock::now();
    Sort::quicksort(cd);
    time_point<Clock> qend = Clock::now();

    for(int i = 0; i < cd.size()-1; i++)
            std::cout << cd[i] << std::endl;

    //bst.search_tree(&bst, 435)->printValue();

    time_point<Clock> end = Clock::now();

    std::cout << "Running Times:" << std::endl;

    milliseconds total_diff = duration_cast<milliseconds>(end - start);
    std::cout << "Total: " << total_diff.count() << "ms" << std::endl;

    milliseconds in_diff = duration_cast<milliseconds>(inend - inst);
    std::cout << "Insertion Sort: " << in_diff.count() << "ms" << std::endl;

    milliseconds merge_diff = duration_cast<milliseconds>(mend - mst);
    std::cout << "Mergesort: " <<  merge_diff.count() << "ms" << std::endl;

    milliseconds quick_diff = duration_cast<milliseconds>(qend - qst);
    std::cout << "Quicksort: " <<  quick_diff.count() << "ms" << std::endl;

    return 0;
}
