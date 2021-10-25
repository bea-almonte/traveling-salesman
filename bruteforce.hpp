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
    
    std::vector<double>currPath;
    
    
public:
    BruteForce();
    void PrintMatrix();
    void FindBestPath();
    double CalcDistance();
    void PrintCurrPath();
    double bestDistance;
    double distances[20][20];
    void CreatePermutations(int permsThisCall);
};

#endif