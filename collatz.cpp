// Collatz Conjecture in cpp
// Add peek - highest number - add all nums to an array and then sort it and print the biggest one
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::literals::chrono_literals;


void collatz(long long num) {
    
    long long num_count = 0;

    vector<long long> Numbers;

    auto start = chrono::high_resolution_clock::now(); // Starts the timer.

    while (num != 1) {

        if (num % 2 == 0) { // If the number is even, divide it by two.
            num /= 2;
        }
        else if (num % 2 == 1) { // If the number is odd, triple it and add one.
            num *= 3;
            num += 1;
        }
        Numbers.push_back(num);
        num_count++;
        cout << "\n" << num; // Prints the numbers on a new line.
    }
    
    sort(Numbers.begin(), Numbers.end(), greater<long long>()); // Sorts the array from highest to lowest.

    auto end = chrono::high_resolution_clock::now(); // Stops the timer.
    chrono::duration<double> duration = end - start; // Calculates duration.
    cout << "\n\nPeak: " << Numbers[0] // Prints the highest number in the sequence.
        << "\nAmount of calculations: " << num_count // Prints the amount of calculations.
        << "\nTime needed: " << duration.count() << "s\n(Press enter to exit)"; // Prints the time needed.
}

int main(int argc, char* argv[])
{
    long long number;

    if (argc == 1) { // If no arguments are given.
        cout << "Enter a positive intiger: ";
        cin >> number;
    }
    else if (argc == 2) {
        number = atof(argv[1]);
    }

    collatz(number); // Call the collatz function.

    cin.get();
    return 0;
}