// Chase Morris 
// CS3610
// Dr.Jundong Liu
// 1/20/2024 

#include<iostream>
#include<map>
#include<string>
#include<cmath>

using namespace std; 

void Sieve(int);											// Seive function.

int main(int argc, char const *argv[]) {

	int number;

	if(argc < 2){ 
		printf("Missing Argument.");
		return 0; 
	}

	for(int i = 1; i < argc; i++) { 

		try { 
			number = stoi(argv[i]);
			
			if ((number < 2) || number > 30000) {					// checks to see if number is in range. 
				printf("Out of Range.");
			}

		} catch (exception e) { 
			printf("Nan.");
		}

		Sieve(number);
	}

}


void Sieve(int n) {

	map<int, bool> numbers = map<int,bool>();				// map used to keep track of primes. 
	const int firstPrime = 2; 
	string composite = "\n";

	for (int i = firstPrime; i < (n + 1); i++)				// assign prime number list. 
		numbers.insert({i,false});

	for (int i = firstPrime; i < (n + 1); i++) {			// look through all primes starting at 2. 
		if (!numbers[i]) {									// if number is false then it means it has not been eliminated. 

			int num = i;

			printf("%d%s", num, " "); 

			if (num < floor(sqrt(i * firstPrime))) {		// check to see if the numbers floored square is greater than the chosen number. 
				return;
			}

			num = i * firstPrime;

			for (auto b : numbers) {						// iterate through the numbers. 

				if (b.first == num) {						// if the number is not a prime set it to true. 
					numbers[num] = true;
					num = num + i;
				}

			}

		}
		else {
			composite += to_string(i) + " "; 
		}
	} 

	printf("%s\n", composite.c_str());
	
}