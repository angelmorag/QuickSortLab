/* Name: Angel Mora Gutierrez
 * Instructor: Professor Vaughn
 * Course:MCSCI-272
 * Lab: Quick Sort Lab
 * Purpose: Implementation of the Quick Sort algorithm using the midpoint
 * partition strategy
 */

#include <iostream>
#include <vector>

using namespace std;

// The partition function
int Partition(vector<int>& numbers, int i, int k) {
    int midpoint = i + (k - i) / 2;
    int pivot = numbers.at(midpoint);

    int low = i;
    int high = k;

    bool done = false;
    while (!done) {
        while (numbers.at(low) < pivot) {
            low++;
        }

        while (numbers.at(high) > pivot) {
            high--;
        }

        if (low >= high) {
            done = true;
        } else {
            int temp = numbers.at(low);
            numbers.at(low) = numbers.at(high);
            numbers.at(high) = temp;

            low++;
            high--;
        }
    }

    return high;
}

int main() {
    vector<int> numbers = {10, 2, 78, 4, 45, 32, 7, 11};

    cout << "Original: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    int lastLeftIndex = Partition(numbers, 0, numbers.size() - 1);

    cout << "After Partition: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "Partition Index: " << lastLeftIndex << endl;
    cout << "Left side ends at index " << lastLeftIndex << " (value: "
    << numbers[lastLeftIndex] << ")" << endl;

    return 0;
}