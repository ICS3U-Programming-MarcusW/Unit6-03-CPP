// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: December 15 2022
// This program generates random numbers, adds
// them to a list, and then finds and displays the minimum value

#include <array>
#include <iostream>
#include <random>

// Declare global constant to represent the max array size
const int MAX_ARRAY_SIZE = 10;

// This function returns the minimum value in the array
int FindMinValue(std::array<int, MAX_ARRAY_SIZE> randIntList) {
    // Initialize the variable to -1
    int minValue = -1;

    // Iterate through list to find min value
    for (int index : randIntList) {
        // Check if the index is less than the current min value
        if (index < minValue) {
            // If true, assign it as the new min value
            minValue = index;
        }
    }
    // Returns the min value
    return minValue;
}

// Function to populate a list with randomly generated numbers
int main() {
    // Constants as parameters for randomly genrated number
    const int MIN_NUM = 0;
    const int MAX_NUM = 100;

    // Declare a 10 cell array
    std::array<int, MAX_ARRAY_SIZE> arrayOfInts;

    // Declared variables
    int ranNum, minNum;

    // Loop to generate ten random numbers and add them to the array
    for (int counter = 0; counter < MAX_ARRAY_SIZE; counter++) {
        // Generates a random number from 0-100
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(MIN_NUM, MAX_NUM);

        // Holds the random number
        ranNum = idist(rgen);
        // Adds the new number to each cell as the
        // counter increments
        arrayOfInts[counter] = ranNum;
        // Displays the added number and its position
        std::cout << arrayOfInts[counter]
                  << " added to the array at position " << counter << std::endl;
    }
    // Calls function return the min value
    minNum = FindMinValue(arrayOfInts);
    // Display the min value
    std::cout << "\nThe min of the numbers: " << minNum << std::endl;
}
