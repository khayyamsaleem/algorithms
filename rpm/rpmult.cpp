#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

unsigned long rpm(unsigned m, unsigned n){
	unsigned long x = min(n, m), y = max(n, m);
	unsigned long z = 0;
	while(x > 0){
		if(x%2 != 0){
			z += y;
		}
		x >>= 1;
		y <<= 1;
	}
	
	return z;

}

int main(int argc, char *argv[]){
	if (argc != 3){
		cout << "Usage: ./rpmult <integer m> <integer n>" << endl;
		return 1;
	}
	int m;
	istringstream iss;
	iss.str(argv[1]);
	if (!(iss >> m) || m < 0){
		cerr << "Error: The first argument is not a valid nonnegative integer." << endl;
		return 1;
	}
	iss.clear();
	iss.str(argv[2]);
	if(!(iss >> m) || m < 0){
		cerr << "Error: The second argument is not a valid nonnegative integer."<< endl;
		return 1;
	}
	cout << argv[1] << " x " << argv[2] << " = " << rpm(atoi(argv[1]), atoi(argv[2]));
	return 0;
}
