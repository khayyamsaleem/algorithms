/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Khayyam Saleem
 * Date        : 9/11/16
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit) : is_prime_(new bool[limit + 1]), limit_(limit) { //constructor
        sieve();
    }

    ~PrimesSieve() { //destructor
        delete [] is_prime_;
    }

    inline int num_primes() const { //number of primes
        return num_primes_;
    }

    void display_primes() const {
        // TODO: write code to display the primes in the format specified in the
        // requirements document.

    	int max_prime_width = num_digits(max_prime_);
    	cout << "Number of primes found: " << count_num_primes() << endl;
    	cout << "Primes up to " << limit_ << ":" << endl;

    	int chars = 0; //character counter
    	for (int p=0; p<=limit_; ++p) {
			if (is_prime_[p]) {
				chars += max_prime_width + 1;
			}
    	}
    	bool one_line = chars <= 80; //checks if one line

    	chars = 0;
    	for (int p=0; p<=limit_; ++p) {
    		if (chars + max_prime_width + 1 > 80) {
    			chars = 0;
    			cout << endl;
    		}
    		if (is_prime_[p]) {
    			if (!one_line)
    				cout << setw(max_prime_width); //set field width to width of max prime
    	    	chars += max_prime_width + 1;
    			cout << p;
    			if (p != max_prime_ && chars < 80)
    				cout << " ";
    		}
    	}
    }



private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    int count_num_primes() const {
        // TODO: write code to count the number of primes found
    	int c = 0;
    	for (int i=0; i <= limit_; i++){
    		if (is_prime_[i]){
    			c += 1;
    		}
    	}
    	return c;
    }

    int num_digits(int num) const {
        // TODO: write code to determine how many digits are in an integer
        // Hint: No strings are needed. Keep dividing by 10.
    	int c = 1;
    	while(num >= 10){
    		num /= 10;
    		c++;
    	}
    	return c;
    }

    void sieve() {
        // TODO: write sieve algorithm
    	is_prime_[0] = false;
    	is_prime_[1] = false;
    	for (int i=2; i <= limit_; i++){
    		is_prime_[i] = true;
    	}
		for (int i=2; i <= sqrt(limit_); i++){
			if (is_prime_[i]){
				for (int j = i*i; j <= limit_; j+=i){
					is_prime_[j] = false;
				}
			}
		}
		for (int i=limit_; i > 0; i--){ //determines max prime
			if (is_prime_[i] == true){
				max_prime_ = i;
				break;
			}
		}

	}

};

int main(void) {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;
    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    cout << endl;
    PrimesSieve test(limit);
    test.display_primes();

    return 0;
}
