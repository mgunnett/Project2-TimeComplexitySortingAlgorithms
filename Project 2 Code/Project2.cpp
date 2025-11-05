#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int binarySearch(vector<int> &binaryArr, int x);
int linearSearch(vector<int> &linearArr, int x);
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
    // cout << "Linear Array: { ";
    // for (int num : linearArr) {
    //     cout << num << " ";
    // }
    // cout << "}" << endl;
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

int linearSearch(vector<int> &linearArr, int x) {
    // Iterate through the vector to find the key
    for (int i=0; i < linearArr.size(); i++) {
        if (linearArr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    // includes all of the chrono methods I need
    using chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    // Initiates random time
    srand(time(0));

    double avg;
    int inputSize;

    // Has the user input the size of the vector
    cout << "What's the input size? - ";
    cin >> inputSize;
    cout << "\n";

    /*
        BEGINNING OF BINARY SEARCH STATEMENTS
    */
    cout << "Binary Search:\n";
    cout << "-----------------\n";

    // Runs for all 5 iterations
    for (int i=1; i < 6; i++) {

    // sets binaryArrSize to whatever user chooses as input size
    int binaryArrSize = inputSize;

    // declares the binaryArr
    vector<int> binaryArr(binaryArrSize);

    // calls the binaryArrFill function to fill the array with random values
    binaryArrFill(binaryArr);

    // pre-sorts the array in increasing order
    sort(binaryArr.begin(), binaryArr.end());

    // picks a random value in the vector to search with
    int x = binaryArr[rand() % binaryArr.size()];

    // begins timer for binarySearch function
    auto start = high_resolution_clock::now();

    // stores what index the x value was found at
    int indexValue = binarySearch(binaryArr, x);

    // ends timer for binarySearch function
    auto end = high_resolution_clock::now();

    // calculates the duration (millisec) by subtracting end time and start time
    duration<double, milli> millisec = end - start;

    // converts the time result to something the console can display with cout
    auto binaryElapsedTime = millisec.count();

    // displays the elapsed time for each run 1-5
    cout << "elapsed time for run #" << i << "- " << binaryElapsedTime << " milliseconds\n";
    
    // calculates the average search time in milliseconds
    for (int j = 1; j <= i; j++) {
        avg = avg + binaryElapsedTime;
    }
    avg = avg / 5;
    }

    // displays the average search time in milliseconds
    cout << "\naverage search time: " << avg << " milliseconds\n";

    // cout << "sorting time: ", replaceMe, "\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";

    /*
    BEGINNING OF LINEAR SEARCH STATEMENTS
    */
    cout << "\n\nLinear Search:\n";
    cout << "----------------\n";
    for (int i=1; i < 6; i++) {
        // sets linearArrSize to whatever user chooses as input size
        int linearArrSize = inputSize;

        // declares the linearArr
        vector<int> linearArr(linearArrSize);

        //calls the linearArrFill function to fill the vector with random values
        linearArrFill(linearArr);

        // pre-sorts the array in increasing order for the search funciton
        sort(linearArr.begin(), linearArr.end());

        // sets x to a random value in the linearArr vector
        int x = linearArr[rand() % linearArr.size()];

        // begins timer for linearSearch function
        auto start = high_resolution_clock::now();

        // returns the index value of the specified x by calling the linearSearch function
        int indexValue = linearSearch(linearArr, x);

        // ends the timer for linearSearch function
        auto end = high_resolution_clock::now();

        // determines the total elapsed run time for each run
        duration<double, milli> millisec = end - start;

        // converts the run time into something the console can print with cout
        auto linearElapsedTime = millisec.count();
        
        // displays the elapsed run time for each run in linearSearch
        cout << "elapsed time for run #" << i << "- " << linearElapsedTime << " milliseconds\n";
       
        // calculates the average search time for linearSearch
        for (int j = 1; j <= i; j++) {
            avg = avg + linearElapsedTime;
        }
        avg = avg / 5;
    }
    // Displays average search time for linearSearch
    cout << "\naverage search time: " << avg << " milliseconds\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";

    // cout << "Linear Search:\n";
    // cout << "----------------\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";
    // cout << "\n\n\n\n";
    // cout << "Binary Search:\n";
    // cout << "-----------------\n";
    // cout << "sorting time: ", replaceMe, "\n";
    // cout << "number of comparisons made: ", replaceMe, "\n";

    system("pause");
    return 0;
}