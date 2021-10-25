// implements functions for brute force algorithm
#include "bruteforce.hpp"

BruteForce::BruteForce() {
    // initialize distances to 0
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            distances[i][j] = 0;
        }
    }
    citiesToRun = 5;
    currPath.resize(citiesToRun);
    for (int i = 0; i < citiesToRun; i++) {
        currPath.at(i) = i;
    }
}

void BruteForce::PrintMatrix() {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout << std::left << std::setw(7) << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void BruteForce::CalcDistance() {
    double totalSum = 0;
    for (int i = 0;i < citiesToRun; i++) {
        totalSum += currPath.at(i);
    }
    if (totalSum > bestDistance) {
        bestDistance = totalSum;
    }
}

void BruteForce::PrintCurrPath() {
    for (int i = 0;i < citiesToRun; i++) {
        std::cout << currPath.at(i) << " ";
    }
    std::cout << std::endl;
}