#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: ./cache_sim num_entries associativity input_file" << endl;
        return 1;
    }

    int num_entries    = stoi(argv[1]);
    int associativity  = stoi(argv[2]);
    int block_size     = stoi(argv[3]);
    string input_file  = argv[4];

    int num_sets = num_entries / associativity;

    vector<list<int>> cache(num_sets);

    ifstream infile(input_file);
    ofstream outfile("cache_sim_output");

    int addr;
    while (infile >> addr) {
        int set_index = addr / block_size % num_sets;
        int tag       = addr / (block_size * num_sets);

        list<int>& lru = cache[set_index];
        bool hit = false;

        // Search the set for a matching tag
        for (auto it = lru.begin(); it != lru.end(); ++it) {
            if (*it == tag) {
                hit = true;
                lru.erase(it);      
                lru.push_back(tag); 
                break;
            }
        }

        if (hit) {
            outfile << addr << " : HIT\n";
        } else {
            outfile << addr << " : MISS\n";
            if ((int)lru.size() >= associativity) {
                lru.pop_front();   
            }
            lru.push_back(tag);     
        }
    }

    return 0;
}