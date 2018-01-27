/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Khayyam Saleem 
 * Date        : 10/03/2016
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    vector< vector<int> > ways;
    if (num_stairs == 0){
        ways.push_back(vector<int>());
    }
    else {
        for (unsigned int i=1; i < 4; i++){
            if (num_stairs >= 1){
                vector< vector<int> > result = get_ways(num_stairs - i);
                for (unsigned int j = 0; j < result.size(); j++){
                    result[j].push_back(i);
                }
                //				ways.insert(ways.end(), result.begin(), result.end());
                for (unsigned int j=0; j < result.size(); j++){
                    ways.push_back(result[j]);
                }
            }
        }
    }
    return ways;
}

int num_digits (int n){
    unsigned int c = 1;
    while (n>=10){
        n/=10;
        c++;
    }
    return c;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.

    for (unsigned int i=0; i < ways.size(); i++){
        cout << setw(num_digits(ways.size()));
        cout << i+1 << ". " << "[" ;
        cout << setw(0);
        for (unsigned int j=ways[i].size()-1; j >= 1; j--){
            cout << ways[i][j] << ", "; 
        }
        cout << ways[i][0] << "]" << endl;
    }
}

int main(int argc, char * const argv[]) {
    //checking for valid arguments
    if (argc != 2){
        cerr << "Usage: ./stairclimber <number of stairs>" << endl;
        return 1;
    }
    istringstream iss;
    int m;
    iss.str(argv[1]);
    if (!(iss >> m) || m <= 0){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
    iss.clear();
    //	cout << m << endl;
    vector < vector<int> > x = get_ways(m);
    if (x.size() == 1){
        cout << "1 way to climb 1 stair." << endl;
        cout << "1. [1]";
    } else {
        cout << x.size() << " ways to climb " << m << " stairs." << endl;
        display_ways(x);
    }
}
