#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;
using std::string;

int main()
{
    vector<vector<int>> M{{0, 1}, {0, 1}};
    map<char, int> A{{'a', 0}, {'b', 1}}; 
    vector<int> S{1};
    Automaton ends_with_b(A, M, S);
    vector<string> strings = {"abab", "waba"};
    for (const string &x : strings) {
        try {
            int state = ends_with_b.Read(x);
            std::cout << "Read " << x << " = " << state << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            return 0;
        }
    }

    return 0;
}