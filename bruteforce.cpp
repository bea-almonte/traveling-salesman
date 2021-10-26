// implements functions for brute force algorithm
#include "bruteforce.hpp"
#include "distancematrix.hpp"

BruteForce::BruteForce() {
    // initialize distances to 0
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            distances[i][j] = 0;
        }
    }

    //PrintPath(currPath);
}

void BruteForce::RunBruteForce(int totalCities) {
    // reset cities
    citiesToRun = totalCities;
    // resize cities to permutate
    currPath.resize(--citiesToRun);

    // initialize first path
    for (int i = 0; i < citiesToRun; i++) {
        currPath.at(i) = i+1; 
    }
    // set best path to compare later
	bestPath = currPath;

    CreatePermutations(citiesToRun);
}

void BruteForce::PrintMatrix() {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            std::cout << std::left << std::setw(7) << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double BruteForce::CalcDistance(std::vector<int>&inputPath) {
    double totalSum = 0;
	int i = 0;
    
    if (i+1 < citiesToRun) {
        totalSum += distances[0][inputPath.at(1)];
    }
    
    for (i = 0;i < citiesToRun-1; i++) {
        totalSum += distances[inputPath.at(i)][inputPath.at(i+1)];
    }

	totalSum += distances[inputPath.at(i)][0];

	return totalSum;
}

void BruteForce::SetBestDistance(double currDistance) {

	if (currDistance < bestDistance) {
		bestDistance = currDistance;
		bestPath = currPath;
	}
}

void BruteForce::PrintPath(std::vector<int>&inputPath) {
    std::cout << "0 ";
    for (int i = 0;i < citiesToRun; i++) {
        std::cout << inputPath.at(i) << " ";
    }
    std::cout << 0 << std::endl;
	std::cout << "Cost: " << CalcDistance(inputPath) << std::endl;
}

void BruteForce::CreatePermutations(long permsThisCall) {
    int m, k, p , q, i;
 
	bestDistance = CalcDistance(currPath);
    
    permsThisCall = GetFactorial(permsThisCall);
    
    //PrintPath(bestPath);
    //PrintCurrPath();
    for(i = 1; i < permsThisCall; i++) {
    	m = citiesToRun-2;

       	while(currPath[m]>currPath[m+1]) {
          	m = m - 1;
        }
       	k = citiesToRun-1;
       	while(currPath[m] > currPath[k]) {
          	k = k - 1;
    	}
       	std::swap(currPath[m],currPath[k]);
       	p = m + 1;
       	q = citiesToRun-1;
       	
		while( p < q) {
        	std::swap(currPath[p],currPath[q]);
         	p++;
        	q--;
       	}
		SetBestDistance(CalcDistance(currPath));
       	//PrintPath(currPath);
     }
}

long BruteForce::GetFactorial(int num) {
    return (num==1 || num == 0) ? 1 : GetFactorial(num-1) * num;
}

void BruteForce::PrintBest() {
    PrintPath(bestPath);
}