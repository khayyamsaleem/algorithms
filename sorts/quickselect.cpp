#include <iostream>
#include <algorithm>


using namespace std;


int lomuto_partition(int array[], int left, int right){
    int p = array[left], s = left;
    for (int i = left + 1; i <= right; ++i){
        if (array[i] < p){
            ++s; 
            swap(array[s], array[i]);
        }
    }
    swap(array[left], array[s]);
    return s;
}

int quick_select(int array[], int left, int right, int k){
    int s = lomuto_partition(array, left, right);
    if (s - left == k - 1){
        return array[s];
    }
    if (s > left + k - 1){
        return quick_select(array, left, s-1, k);
    }
    return quick_select(array, s+1, right, k - 1 - s);
}

int main(){
    int cheese[] = {1, 3, 5, 2, 4};
    cout << quick_select(cheese, 0, 4, 5) << endl;
}
