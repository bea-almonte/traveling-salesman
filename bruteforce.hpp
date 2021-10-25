// implements brute force algorithm for traveling salesman problem
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

class BruteForce {
private:
    int citiesToRun;
    
    std::vector<int>currPath;
    void SetBestDistance(double currDistance);
    std::vector<int>bestPath;
public:
    BruteForce();
    void PrintMatrix();
    void FindBestPath();
    double CalcDistance();
    void PrintBest();
    double bestDistance;
    double distances[20][20];
    void CreatePermutations(long permsThisCall);
};

#endif