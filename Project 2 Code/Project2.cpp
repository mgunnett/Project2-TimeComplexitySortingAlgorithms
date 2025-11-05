#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int binarySearch(vector<int> &binaryArr, int x, int &binaryComparisonCounter);
int linearSearch(vector<int> &linearArr, int x, int &linearComparisonCounter);
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
}

/*
    @name linearArrFill
    @param vector<int> &linearArr
    @details Uses minimum and maximum amounts to fill the linearArr with randomly
             generated numbers.
*/
void linearArrFill(vector<int> &linearArr) {
    /* Sets the minimum and maximum amounts for the values
    that can be entered into the vector*/
    const int linearArrMin = linearArr.size()*-3;
    const int linearArrMax = linearArr.size()*3;

    // creates random numbers to put into the vector & fills it
    for (int& num : linearArr) {
        num = linearArrMin + rand() % (linearArrMax - linearArrMin + 1);
    }
}

/*
    @name binarySearch
    @param vector<int> &binaryArr, int x
    @details Uses a binary search algorithm to search for the indice that holds the randomly selected x
             in the main function. Compares whether x is at the middle, before the middle, or after the middle
*/
int binarySearch(vector<int> &binaryArr, int x, int &binaryComparisonCounter) {
    // sets the lowest indice and the highest indice
    int low = 0;
    int high = binaryArr.size() - 1;

    // runs as long as the lowest indice is less than or equal to the highest observed indice
    while (low <= high) {
        // increments comparison counter for each comparison
        binaryComparisonCounter++;
        // calculates the indice in the middle of the lowest and highest
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
    // if not found, returns -1
    return -1;
}

/*
    @name linearSearch
    @param vector<int> &linearArr, int x
    @details Uses a linear search algorithm to search for the indice that holds the randomly selected x
             in the main function. Searches through each indice to see if x is the same as the number in 
             that indice position. If it is, it returns i, or the indice number. If it does not, it continues
             until it finds the indice. If a matching value is not found, it returns -1.
*/
int linearSearch(vector<int> &linearArr, int x, int &linearComparisonCounter) {
    // Iterate through the vector to find the key
    for (int i=0; i < linearArr.size(); i++) {
        // increments comparison counter up for each comparison
        linearComparisonCounter++;
        // if the value at the indice located at i is the same as the value of x, returns that indice
        if (linearArr[i] == x) {
            return i;
        }
    }
    // if value/indice not found, returns -1
    return -1;
}

int main() {
    // includes all of the chrono methods I need
    using chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using chrono::milliseconds;
    // Initiates random time
    srand(time(0));

    double binaryavg = 0.0;
    double linearavg = 0.0;
    int inputSize;
    int binaryComparisonCounter = 0;
    int linearComparisonCounter = 0;
    double sortingTime;

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

    // begins timer for binary array sorting
    auto startSort = high_resolution_clock::now();

    // pre-sorts the array in increasing order
    sort(binaryArr.begin(), binaryArr.end());

    // ends the timer for binary array sorting
    auto endSort = high_resolution_clock::now();

    // calculates the duration (sortMillisec) by subtracting end time and start time
    chrono::duration<double, milli> sortMillisec = endSort - startSort;

    // converts the time result to something the console can display with cout
    auto binarySortingTime = sortMillisec.count();

    sortingTime = binarySortingTime;

    // picks a random value in the vector to search with
    int x = binaryArr[rand() % binaryArr.size()];

    // begins timer for binarySearch function
    auto start = high_resolution_clock::now();

    // stores what index the x value was found at
    int indexValue = binarySearch(binaryArr, x, binaryComparisonCounter);

    // ends timer for binarySearch function
    auto end = high_resolution_clock::now();

    // calculates the duration (millisec) by subtracting end time and start time
    chrono::duration<double, milli> binarymillisec = end - start;

    // converts the time result to something the console can display with cout
    auto binaryElapsedTime = binarymillisec.count();

    // displays the elapsed time for each run 1-5
    cout << "elapsed time for run #" << i << "- " << binaryElapsedTime << " milliseconds\n";
    
    // calculates the average search time in milliseconds
        binaryavg = binaryavg + binaryElapsedTime;
    }
    binaryavg = binaryavg / 5;
    // displays the average search time in milliseconds
    cout << "\naverage search time: " << binaryavg << " milliseconds\n";
    // displays sorting time in milliseconds
    cout << "sorting time: " << sortingTime << " milliseconds\n";
    // displays number of comparisons made
    cout << "number of comparisons made: " << binaryComparisonCounter << "\n";


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

        // sets x to a random value in the linearArr vector
        int x = linearArr[rand() % linearArr.size()];

        // begins timer for linearSearch function
        auto start = high_resolution_clock::now();

        // returns the index value of the specified x by calling the linearSearch function
        int indexValue = linearSearch(linearArr, x, linearComparisonCounter);

        // ends the timer for linearSearch function
        auto end = high_resolution_clock::now();

        // determines the total elapsed run time for each run
        chrono::duration<double, milli> linearmillisec = end - start;

        // converts the run time into something the console can print with cout
        auto linearElapsedTime = linearmillisec.count();
        
        // displays the elapsed run time for each run in linearSearch
        cout << "elapsed time for run #" << i << "- " << linearElapsedTime << " milliseconds\n";
       
        // calculates the average search time for linearSearch
            linearavg = linearavg + linearElapsedTime;
    }
    linearavg = linearavg / 5;
    // Displays average search time for linearSearch
    cout << "\naverage search time: " << linearavg << " milliseconds\n";
        // displays number of comparisons made
    cout << "number of comparisons made: " << linearComparisonCounter << "\n";

    // tells command prompt to stay open after running the program
    system("pause");
    return 0;
}