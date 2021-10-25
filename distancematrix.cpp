#include "distancematrix.hpp"

DistanceMatrix::DistanceMatrix() {
    // initialize matrix to 0
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            distances[i][j] = 0;
        }
    }
}

void DistanceMatrix::GenerateMatrix(std::string distancesFile) {
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

}

void DistanceMatrix::PrintMatrix() {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout << std::left << std::setw(7) << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DistanceMatrix::SetMatrix(double algoDistances[][20]) {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            if (i != j) {
                algoDistances[i][j] = distances[i][j];
            }
        }
    }
}