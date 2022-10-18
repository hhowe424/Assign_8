//12-1-2021
//This program reads a file of integers, sorts them from least to greatest,
//and then asks for a number to search for. It then searches the sorted array
//for the users number input and displays what position the number was found
//in. It also calculated and displays the mean value of the list of integers.

#include <iostream>
#include <fstream>

using namespace std;

int linearSearch (int [], int, int, int);
void selectionSort(int [], int);
void bubbleSortArray(int [], int);
int binarySearch(int [], int, int, int);
double findMean(int [], double);

int main () {
    ofstream outFile;
    outFile.open("output.txt");

    ifstream inFile;
    inFile.open("nums.txt");
    //determines the size of the array
    //depending on the amount of numbers in the file
    int numbers;
    int size;
    while(inFile >> numbers){
        size++;
    }
    const int SIZE = size;
    int nums[SIZE];
    inFile.close();

    inFile.open("nums.txt");

    if (inFile) {
        int numSearch;
        int index = 0;

        for (int i = 0; i < SIZE; i++) {
            inFile >> nums[i];
        }

        cout << "\nEnter an integer to search for: ";
        outFile << "\nEnter an integer to search for: ";
        cin >> numSearch;
        outFile << numSearch;
        cout << "This array has 12 items." << endl;
        cout << "\nThe array entered by the user is as follows: \n";
        outFile << "\nThis array has 12 items." << endl;
        outFile << "\nThe array entered by the user is as follows: \n";

        for (int i = 0; i < SIZE; i++) {
            cout << nums[i] << " ";
            outFile << nums[i] << " ";
        }

        //selectionSort(nums, SIZE);
        bubbleSortArray(nums, SIZE);

        cout << "\n\nThe sorted array is as follows: \n";
        outFile << "\n\nThe sorted array is as follows: \n";
        for (int i = 0; i < SIZE; i++) {
            cout << nums[i] << " ";
            outFile << nums[i] << " ";
        }
        cout << "\n\nThe item searched for is " << numSearch << endl;
        outFile << "\n\nThe item searched for is " << numSearch << endl;

        //index = linearSearch (nums, index, SIZE, numSearch);

        index = binarySearch(nums, index, SIZE, numSearch);

        if(index < 0 || index > SIZE - 1)
            cout << "The value searched for was not found" << endl;
        else {
            cout << "The value " << numSearch << " is in position number "
                 << index + 1 << " of the list" << endl;
            outFile << "The value " << numSearch << " is in position number "
                    << index + 1 << " of the list" << endl;
        }

        double mean = findMean(nums, SIZE);
        cout << "The mean of all the elements in the array is " << fixed
                << setprecision(1) << mean << endl;
        outFile << "The mean of all the elements in the array is " << fixed
             << setprecision(1) << mean << endl;

        inFile.close();
    }

    else {
        cout << "This file does not exist" << endl;
        outFile << "This file does not exist" << endl;
    }
    return 0;
}

int linearSearch (int array[], int index, int SIZE, int value){
    bool found = false;
    int position = -1;
    index = 0;
    while (found == false && index < SIZE){
        if(array[index] == value){
            found = true;
            position = index;
        }
        index++;
    }
    return index;
}

void selectionSort(int array[], int size) {
    int start, minIndex, minValue;

    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }

            int temp = array[minIndex];
            array[minIndex] = array[start];
            array[start] = temp;
        }
    }
}

//sorts the array of numbers from the file

void sortArray(int array[], int size) {
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

/*
int binarySearch(int array[], int index, int size, int num) {
    if (index <= size) {
        int midValue = (index + size) / 2;
        if (array[midValue] == num)
            return midValue;
        if (array[midValue] > num)
            return binarySearch(array, index, midValue - 1, num);
        if (array[midValue] < num)
            return binarySearch(array, midValue + 1, size, num);
    }
}
*/

void bubbleSortArray(int array[], int size){
    bool swap;
    int temp;

    do{
        swap = false;
        for(int count = 0; count < (size - 1); count++)
        {
            if(array[count] > array[count +1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}


//searches for the users input number in the array
int binarySearch(int array[], int index, int size, int num){
    int first = 0;
    int last = size - 1;
    bool found = false;
    int position = -1;
    while (found != true && first <= last){
        int mid = (last + first) / 2;
        if(array[mid] == num){
            found = true;
            position = mid;
        }
        else if (array[mid] > num){
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return position;
}


//calculates the mean (average) of the numbers in the file
double findMean(int array[], double size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

/*
Enter an integer to search for: 100
This array has 12 items.

The array entered by the user is as follows:
22 -4 5 100 39 20 88 10 55 3 10 78

The sorted array is as follows:
-4 3 5 10 10 20 22 39 55 78 88 100

The item searched for is 100
The value 100 is in position number 12 of the list
The mean of all the elements in the array is 35.5

Process finished with exit code 0
 */
