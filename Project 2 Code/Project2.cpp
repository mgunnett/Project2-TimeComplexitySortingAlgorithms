#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int binarySearch(vector<int> &binaryArr, int x);
int linearSearch();
void binaryArrFill(vector<int> &binaryArr);
void linearArrFill(vector<int> &linearArr);

/*
    @name binaryArrFill
    @param vector<int> &binaryArr
    @details Uses minimum and maximum amounts to fill the binaryArr with randomly
             generated numbers.
*/
void binaryArrFill(vector<int> &binaryArr) {
    /* Sets the minimum and maximum amounts for the values
    that can be entered into the vector*/
    const int binaryArrMin = binaryArr.size()*-3;
    const int binaryArrMax = binaryArr.size()*3;

    // creates random numbers to put into the vector & fills it
    for (int& num : binaryArr) {
        num = binaryArrMin + rand() % (binaryArrMax - binaryArrMin + 1);
    }

    // TESTING PURPOUSES
    // cout << "Binary Array: { ";
    // for (int num : binaryArr) {
    //     cout << num << " ";
    // }
    // cout << "}" << endl;
}

void linearArrFill(vector<int> &linearArr) {
    const int linearArrMin = linearArr.size()*-3;
    const int linearArrMax = linearArr.size()*3;

    for (int& num : linearArr) {
        num = linearArrMin + rand() % (linearArrMax - linearArrMin + 1);
    }

    // TESTING 
    cout << "Linear Array: { ";
    for (int num : linearArr) {
        cout << num << " ";
    }
    cout << "}" << endl;
}

/*
    @name binarySearch
    @param vector<int> &binaryArr, int x
    @details Uses a binary search algorithm to search for the indice that holds the randomly selected x
             in the main function. Compares whether x is at the middle, before the middle, or after the middle
*/
int binarySearch(vector<int> &binaryArr, int x) {
    int low = 0;
    int high = binaryArr.size() - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
    
    // Check if x is at the middle
        if (binaryArr[middle] == x){
            return middle;
        }

        // if x is greater than the middle, ignore left half of vector
        if (binaryArr[middle] < x) {
            low = middle + 1;
        }

        // if x is smaller than the middle, ignore right half
        else {
            high = middle - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0));
    // Runs for all 5 iterations
    for (int i=1; i < 6; i++) {
    // determines a random number for the size of our binaryArr
    int binaryArrSize = rand();
    // declares the binaryArr
    vector<int> binaryArr(binaryArrSize);
    // calls the binaryArrFill function to fill the array with random values
    binaryArrFill(binaryArr);
    // pre-sorts the array in increasing order
    sort(binaryArr.begin(), binaryArr.end());
    // picks a random value in the vector to search with
    int x = binaryArr[rand() % binaryArr.size()];
    // stores what index the x value was found at
    int indexValue = binarySearch(binaryArr, x);
    
    // TESTING
    // cout << x << " found at " << indexValue << "\n";
    }
    for (int i=1; i < 6; i++) {
        int linearArrSize = rand();
        vector<int> linearArr(linearArrSize);
        linearArrFill(linearArr);
    }

    // TO BE REMOVED AND REPLACED ONCE DONE
    // int replaceMe = 0;

    // cout << "Linear Search:\n";
    // cout << "----------------\n";
    // cout << "elapsed time for run #1 - ", replaceMe, "\n";
    // cout << "elapsed time for run #2 - ", replaceMe, "\n";
    // cout << "elapsed time for run #3 - ", replaceMe, "\n";
    // cout << "elapsed time for run #4 - ", replaceMe, "\n";
    // cout << "elapsed time for run #5 - ", replaceMe, "\n\n";
    // cout << "average search time: ", replaceMe, "\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";
    // cout << "\n\n\n\n";
    // cout << "Binary Search:\n";
    // cout << "-----------------\n";
    // cout << "elapsed time for run #1 - ", replaceMe, "\n";
    // cout << "elapsed time for run #2- ", replaceMe, "\n";
    // cout << "elapsed time for run #3 - ", replaceMe, "\n";
    // cout << "elapsed time for run #4 - ", replaceMe, "\n";
    // cout << "elapsed time for run #5 - ", replaceMe, "\n\n";
    // cout << "average search time: ", replaceMe, "\n";
    // cout << "sorting time: ", replaceMe, "\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";

    system("pause");
    return 0;
}