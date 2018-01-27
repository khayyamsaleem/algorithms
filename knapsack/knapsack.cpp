/*******************************************************************************
 * Name        : knapsack.cpp
 * Author      : Khayyam Saleem
 * Version     : 1.0
 * Date        : 12/4/16
 * Description : Demonstration of dynamic programming with knapsack problem.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Item {
    unsigned int item_number, weight, value;
    string description;

    explicit Item(const unsigned int item_number,
            const unsigned int weight,
            const unsigned int value,
            const string &description) :
        item_number(item_number),
        weight(weight),
        value(value),
        description(description) { }
    friend std::ostream& operator<<(std::ostream& os, const Item &item){
        os << "Item " << item.item_number << ": " << item.description
            << " (" << item.weight
            << (item.weight == 1 ? " pound" : " pounds") << ", $"
            << item.value << ")";
        os.flush();
        return os;
    }

    unsigned w(){
        return weight;
    }

    unsigned v(){
        return value;
    }

    string d(){
        return description;
    }

};

vector< vector<unsigned> > knapsack(unsigned cap, vector<Item> items){
    vector< vector<unsigned> > k;
    vector<unsigned> v;
    vector<unsigned> w;
    for (unsigned i = 0; i < items.size(); i++){
        v.push_back(items[i].v());
        w.push_back(items[i].w());
    }
    k.push_back(w);
    k.push_back(v);
    unsigned n = w.size();
    vector< vector<unsigned> > out(n+1, vector<unsigned>(cap+1));
    for(unsigned i = 0; i < n; i++){
        out[i][0] = 0;
    }
    for(unsigned j = 0; j < cap; j++){
        out[0][j] = 0;
    }
    for (unsigned i = 1; i <= n; i++){
        for (unsigned j = 1; j <= cap; j++){
            unsigned l = out[i-1][j];
            if(j >= k[0][i-1]){
                unsigned u = k[1][i-1] + out[i-1][j-k[0][i-1]];
                out[i][j] = max(u, l);
            }
            if(j < k[0][i-1]){
                out[i][j] = l;
            }
        }
    }
    return out;
}

void steal(vector<Item> items, unsigned cap){
    cout << "Candidate items to place in knapsack:" << endl;
    for (unsigned i = 0; i < items.size(); i++){
        cout << "   " << items[i] << endl;
    }
    string grammar = (cap == 1) ? " pound" : " pounds";
    cout << "Capacity: " << cap << grammar  << endl;
    cout << "Items to place in knapsack:";
    unsigned c = 0;
    vector<unsigned> w;
    vector<unsigned> v;
    for (unsigned i = 0; i < items.size(); i++){
        w.push_back(items[i].w());
        v.push_back(items[i].v());
        if(items[i].w() > cap){
            c++;
        }
    }
    if (cap == 0 || c == items.size()){
        cout << " None" << endl;
        cout << "Total weight: 0 pounds" << endl;
        cout << "Total value : $0" << endl;
    } else {
        cout << endl;
        vector< vector<unsigned> > k = knapsack(cap, items);
        vector<unsigned> out;
        unsigned i = k.size()-1;
        unsigned j = k[0].size()-1;
        while(!(i==0 || j==0)){
            if(k[i][j] != k[i-1][j]){
                out.push_back(i-1);
                j -= w[i-1];
            }
            i--;
        }
        reverse(out.begin(), out.end());
        int totw = 0;
        int totv = 0;
        for (unsigned i = 1; i <= out.size(); i++){
            totw += w[out[i-1]];
            totv += v[out[i-1]];
            cout << "   " << Item(out[i-1]+1, w[out[i-1]],
                    v[out[i-1]], items[out[i-1]].d()) << endl;
        }
        string gram = (totw == 1) ? " pound" : " pounds";
        cout << "Total weight: " << totw << gram << endl;
        cout << "Total value : $" << totv << endl;
    }
}

int main(int argc, char * const argv[]){
    if (argc != 3){
        cerr << "Usage: ./knapsack <capacity> <filename>" << endl;
        return 1;
    }
    int m;
    istringstream iss;
    iss.str(argv[1]);
    if ( !(iss >> m) || m < 0){
        cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
        return 1;
    }
    vector<Item> items;
    iss.clear();
    ifstream read;
    read.open(argv[2]);
    if(read.is_open()){
        int ln = 1;
        do{
            string word;
            vector<string> l;
            getline(read, word);
            //cout << line << endl;
            istringstream ss(word);
            while(getline(ss, word, ',')){
                l.push_back(word);
            }
            if(l.size() != 3 && l.size() != 0){
                cerr << "Error: Line number " << ln << " does not contain 3 fields." << endl;
                return 1;
            }
            if(!l.empty()){
                istringstream check;
                iss.str(l[1]);
                if (!(iss >> m) || m < 0){
                    cerr << "Error: Invalid weight '" << l[1]
                        << "' on line number " << ln << "." << endl;
                    return 1;
                }
                iss.clear();
                iss.str(l[2]);
                if (!(iss >> m) || m < 0){
                    cerr << "Error: Invalid value '" << l[2]
                        << "' on line number " << ln << "." << endl;
                    return 1;
                }
                iss.clear();
                items.push_back(Item(ln, atoi(l[1].c_str()),
                            atoi(l[2].c_str()), l[0]));
            };
            // cout << "[";
            // for (int i = 0; i < oneline.size(); i++){
            //     if (i == oneline.size() - 1){
            //         cout << oneline[i] << "]" << endl;
            //     } else {
            //         cout << oneline[i] << ", ";
            //     }
            // }
            word.clear();
            ln++;
        } while (!read.eof());
    } else {
        cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
        return 1;
    }
    read.close();
    iss.clear();
    iss.str(argv[1]);
    int n;
    if(iss >> n){
        steal(items, n);
    };
    iss.clear();
    return 0;
}
