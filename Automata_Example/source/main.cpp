#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>
#include <memory>

using std::vector;
using std::map;
using std::string;

int main()
{
    vector<vector<int>> M{{0, 1}, {0, 1}};
    map<char, int> A{{'a', 0}, {'b', 1}}; 
    vector<int> S{1};
    std::unique_ptr<Automaton> ends_with_b;
    try {
        ends_with_b = std::make_unique<Automaton> (Automaton(A,M,S));
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    } 
    vector<string> strings = {"abab", "aaba"};
    for (const string &x : strings) {
        try {
            int state = (*ends_with_b).Read(x);
            std::cout << "Read " << x << " = " << state << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}