#include "human.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

pair<pair<int, int>, pair<int, int>> Human::generateMove(vector<vector<shared_ptr<Piece>>> &boardmap, string input) {
    stringstream ss(input);
    string command;
    string movefrom;
    string moveto;
    ss >> command;
    ss >> movefrom;
    ss >> moveto;
    int fromcol = movefrom[0] - 'a';
    int fromrow = movefrom[1] - '1';
    int tocol = moveto[0] - 'a';
    int torow = moveto[1] - '1';
    
    if ((fromcol < 0 || fromcol >= 8) || (fromrow < 0 || fromrow >= 8) || (torow < 0 || torow >= 8) ||  (tocol < 0 || tocol >= 8)) { // input out off range
        cerr << "Invalid input, please try again." << endl;
        return {{-1, -1},
                {-1, -1}};
    }

    if ((boardmap)[fromrow][fromcol] == nullptr) { // input fromrow fromcol is empty
        cout << "Invalid input, please try again." << endl;
        return {{-1, -1},
                {-1, -1}};
    }


    if ((boardmap)[fromrow][fromcol]->getColor() != *currentPlayer) {
        cout << "This is not the turn of this piece you want to move, please try again." << endl;
        return {{-1, -1},
                {-1, -1}};
    }

    vector<pair<int, int>> legalmoves = (boardmap)[fromrow][fromcol]->legalMoves(boardmap, fromrow, fromcol);
    pair<pair<int, int>, pair<int, int>> wantmove = {{fromrow, fromcol},
                                                     {torow,   tocol}};
    pair<int, int> wantmoveto = {torow, tocol};
    if (find(legalmoves.begin(), legalmoves.end(), wantmoveto) != legalmoves.end()) {
        return wantmove;
    } else {
        cout << "Invalid input, please try again." << endl;
        return {{-1, -1},
                {-1, -1}};
    }
}
