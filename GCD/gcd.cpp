//================================================================================
// Name        : GCD.cpp
// Author      : Khayyam Saleem
// Class       : CS385 RB
// Description : Computes the GCD of any two integers iteratively and recursively
// Pledge:     : I pledge my honor that I have abided by the Stevens Honor System. 
//================================================================================

#include <iostream>
#include <sstream>
using namespace std;

int rgcd(int a, int b){
	if (b == 0){
		return a;
	}
	return rgcd(b, a % b);
}

int igcd(int a, int b){
	while (b != 0){
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main(int argc, char *argv[]) {
	int m, n;
	if (argc != 3){
		cerr << "Usage: ./gcd <integer m> <integer n>" << endl;
		return 1;
	}
	
	//argument checks
	istringstream iss;
	iss.str(argv[1]);
	if (!(iss >> m)) {
		cerr << "Error: The first argument is not a valid integer." << endl;
		return 1;
	}

	iss.clear();
	iss.str(argv[2]);
	if(!(iss >> n)) {
		cerr << "Error: The second argument is not a valid integer." << endl;
		return 1;
	}

	cout << "Iterative: gcd(" << m << ", " << n << ") = " << igcd(m, n) << endl;
	cout << "Recursive: gcd(" << m << ", " << n << ") = " << rgcd(m, n) << endl;

}
