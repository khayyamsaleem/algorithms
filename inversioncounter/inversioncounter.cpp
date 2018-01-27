/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Khayyam Saleem
 * Version     : 1.0
 * Date        : 10/30/2016 
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. 
 ******************************************************************************/

#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


// Function prototype.
long mergesort(int array[], int scratch[], int low, int high);
long merge(int array[], int scratch[], int l, int m, int r);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    long count = 0;
    for (int i = 0; i < length-1; i++){
        for (int j = i+1; j < length; j++){
            if (array[i] > array[j]){
                count +=1;
            }
        }
    }
    return count;
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length, int* scratch) {
    return mergesort(array, scratch, 0, length-1);
}

long mergesort(int array[], int scratch[], int low, int high) {
    int m = (high+low)/2;
    long count = 0;

    if (high > low){
        m = (high+low)/2;
        count = mergesort(array, scratch, low, m);
        count += mergesort(array, scratch, m+1, high);
        count += merge(array, scratch, low, m+1, high);
    }
    return count;
}

long merge(int array[], int scratch[], int l, int m, int r){
    int i,j,k;
    long count = 0;
    i = l; j = m; k = l;
    while(( i <= m -1) && (j <= r)){
        if (array[i] <= array[j]){
            scratch[k++] = array[i++];
        } else {
            scratch[k++] = array[j++];
            count = count + (m - i);
        }
    }
    while (i <= m - 1) scratch[k++] = array[i++];
    while (j <= r) scratch[k++] = array[j++];
    for (i=l; i <= r; i++) array[i] = scratch[i];
    return count;
}

int main(int argc, char *argv[]) {
    using namespace std;

    if (argc > 2){
        cerr << "Usage: ./inversioncounter [slow]" << endl;
        return 1;
    }
    string option = "";
    if (argc == 2)
        option = argv[1];
    if (argc == 2 && option != "slow"){
        cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
        return 1;
    }
    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                        << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }
    if (values.empty()){
        cerr << "Error: Sequence of integers not received." << endl;
        //    	delete values;
        return 1;
    };
    int *array = &values[0];

    if (option ==  "slow"){
        cout << "Number of inversions: " << count_inversions_slow(array, values.size()) << endl;
        return 0;
    }
    int *scratch = new int[values.size()];
    cout << "Number of inversions: " << count_inversions_fast(array, values.size(), scratch) << endl;
    delete[] scratch;
    return 0;
}
