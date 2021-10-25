#include <time.h>
#include "bruteforce.hpp"
#include "distancematrix.hpp"

int main() {
    DistanceMatrix matrix1;
    BruteForce run1;
    matrix1.GenerateMatrix("distances.txt");
    matrix1.SetMatrix(run1.distances);
    //run1.PrintMatrix();
    run1.CalcDistance();
    run1.PrintCurrPath();
    
    run1.CreatePermutations(120);
    std::cout << "Best: " << run1.bestDistance << std::endl;
    return 0;
}