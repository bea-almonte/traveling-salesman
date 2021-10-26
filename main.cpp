#include <time.h>
#include <stdio.h>
#include "bruteforce.hpp"
#include "distancematrix.hpp"

int main() {
    DistanceMatrix matrix1;
    BruteForce run1;
    int totalCities = 0;
    matrix1.GenerateMatrix("distances.txt");
    matrix1.SetMatrix(run1.distances);
    
    std::freopen("bruteforce.txt","a+",stdout);

    std::cout << "Total Cities: ";
    std::cin >> totalCities;

    std::cout << totalCities << std::endl;

    run1.RunBruteForce(totalCities);
    run1.PrintBest();

    std::fclose(stdout);
    return 0;
}