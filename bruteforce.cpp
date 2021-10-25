// implements functions for brute force algorithm
#include "bruteforce.hpp"

BruteForce::BruteForce() {
    // initialize distances to 0
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            distances[i][j] = 0;
        }
    }
    citiesToRun = 5;
    currPath.resize(citiesToRun);
    for (int i = 0; i < citiesToRun; i++) {
        currPath.at(i) = i;
    }
	bestDistance = 0;
}

void BruteForce::PrintMatrix() {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout << std::left << std::setw(7) << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double BruteForce::CalcDistance() {
    double totalSum = 0;
    for (int i = 0;i < citiesToRun; i++) {
        totalSum += currPath.at(i);
    }
	return totalSum;
}

void BruteForce::SetBestDistance(double currDistance) {
	if (currDistance < bestDistance) {
		bestDistance = currDistance;
	}
}

void BruteForce::PrintCurrPath() {
    for (int i = 0;i < citiesToRun; i++) {
        std::cout << currPath.at(i) << " ";
    }
    std::cout << std::endl;
}

void BruteForce::CreatePermutations(int permsThisCall) {
    int m, k, p , q, i;
	bestDistance = CalcDistance();
    PrintCurrPath();
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
		SetBestDistance(CalcDistance());
       	PrintCurrPath();
     }
} 