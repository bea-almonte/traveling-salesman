// implements brute force algorithm for traveling salesman problem
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#ifndef DISTANCEMATRIX_HPP
#define DISTANCEMATRIX_HPP

class DistanceMatrix {
private:
    double distances[20][20];
public:
    DistanceMatrix();
    void GenerateMatrix(std::string distancesFile); // generate adjacency matrix
    void SetMatrix(double algoDistances[][20]);
    void PrintMatrix();
};

#endif