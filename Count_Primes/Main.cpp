// Problem: Counting Primes

// Algorithm (my own solution): Sieve of Eratosthenes

#include <iostream>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		// special case handling
		if (n == 0 || n == 1) {
			return 0;
		}

		// dynamically allocate a bool array with size n (representing whether numbers from 0...n-1 are prime or not)
		bool* numbers = new bool[n];

		// for starters, initialize everyone as being prime
		for (int i = 0; i < n; i++) {
			numbers[i] = true;
		}

		// 0 and 1 are not primes
		numbers[0] = false;
		numbers[1] = false;

		// starting from index 2 (which represents the number 2), mark each of it's multiples as non-prime
		for (int i = 2; i < n; i++) {
			// if number is prime, mark its multiples as non-prime
			if (numbers[i]) {
				for (int j = (i + i); j < n; j = (j + i)) {
					numbers[j] = false;
				}
			}
		}

		unsigned int count = 0;
		// count the occurrences of true in the array
		for (int i = 0; i < n; i++) {
			if (numbers[i]) {
				count++;
			}
		}

		return count;
	}
};