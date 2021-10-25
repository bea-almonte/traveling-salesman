// implements brute force algorithm for traveling salesman problem
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

class BruteForce {
private:
    double distances[20][20];
    int citiesToRun;
public:
    BruteForce();
    void GenerateMatrix(std::string distancesFile); // generate adjacency matrix
};

#endif