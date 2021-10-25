// implements functions for brute force algorithm
#include "bruteforce.hpp"

BruteForce::BruteForce() {
    // initialize distances to 0
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            distances[i][j] = 0;
        }
    }
}

void BruteForce::GenerateMatrix(std::string distancesFile) {
    std::ifstream inData;    
    inData.open(distancesFile);

    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            if (i != j) {
                inData >> distances[i][j];
            }
        }
    }

    inData.close();

    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            std::cout << std::left << std::setw(7) << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}