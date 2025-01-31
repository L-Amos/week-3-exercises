#include "automaton.h"
#include <iostream>
#include <stdexcept>

Automaton::Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S) : alphabet(A), transition_matrix(M), accepting_states(S) {
    if (alphabet.size() != transition_matrix[0].size() or transition_matrix.size() != 2) {  // Define the problem such that there are 2 possible states
        throw std::invalid_argument("Transition matrix needs the same number of rows as letters in the alphabet, and the same number of columns as accepting states.");
    }
}

bool Automaton::Read(string word)
{
    for (auto &c : word)
    {
        // a map's find method returns an iterator to the key-value pair for the given key
        // iterators have syntax similar to pointers: 
        // (*it) gives the key-value pair
        // -> can be used to access methods of the key value pair
        auto it = alphabet.find(c);
        if (it==alphabet.end()) {
            throw std::invalid_argument("String contains characters not in the alphabet!");
        }

        //it->first gives the key, it->second gives the value
        int j = it->second;
        state = transition_matrix[state][j];
    }

    return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}