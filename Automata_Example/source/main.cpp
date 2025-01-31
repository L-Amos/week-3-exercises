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
    string word;
    std::cout << "Enter a word" << std::endl;
    std::cin >> word;
    vector<string> strings = {"abab", "aaba"};
    try {
        string accepted;
        int state = (*ends_with_b).Read(word);
        if (state==1) {
            accepted = "accepted";
        } else {
            accepted = "not accepted";
        }
        std::cout << word << " is " << accepted << "!" << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        main();
    }
    return 0;
}