#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int binarySearch(vector<int> &binaryArr, int x);
int linearSearch();
int binaryArrFill(vector<int> &binaryArr);

int binaryArrFill(vector<int> &binaryArr) {
    const int binaryArrMin = binaryArr.size()*-3;
    const int binaryArrMax = binaryArr.size()*3;

    for (int& num : binaryArr) {
        num = binaryArrMin + rand() % (binaryArrMax - binaryArrMin + 1);
    }

    cout << "Binary Array: { ";
    for (int num : binaryArr) {
        cout << num << " ";
    }
    cout << "}" << endl;
    
    return 1;
}

int main() {
    for (int i=1; i < 6; i++) {
    srand(time(0));
    int binaryArrSize = rand();
    vector<int> binaryArr(binaryArrSize);
    binaryArrFill(binaryArr);
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
}