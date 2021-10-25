// implements brute force algorithm for traveling salesman problem
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

class BruteForce {
private:
    int citiesToRun;
    
    std::vector<double>currPath;
    
    void CreatePermutations(int permsThisCall);
public:
    BruteForce();
    void PrintMatrix();
    void FindBestPath();
    void CalcDistance();
    void PrintCurrPath();
    double bestDistance;
    double distances[20][20];
};

#endif