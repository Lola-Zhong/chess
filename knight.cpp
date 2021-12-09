#include "knight.h"

Knight::Knight(char color, shared_ptr<std::vector<std::vector<std::shared_ptr<Piece>>>> boardmap) : Piece(color, 3,
                                                                                                          boardmap) {}


bool Knight::check(vector<vector<shared_ptr<Piece>>> &b, int torow, int tocol, int kingrow, int kingcol) {
    int w = abs(kingcol - tocol);
    int h = abs(kingrow - torow);
    if ((w == 2 && h == 1) || (w == 1 && h == 2)) {
        return true;
    } else {
        return false;
    }
}


vector<pair<int, int>> Knight::legalMoves(int r, int c) {
    vector<pair<int, int>> listOfLegalMoves;
    vector<pair<int, int>> dir = {{1,  2},
                                  {1,  -2},
                                  {-1, 2},
                                  {-1, -2},
                                  {2,  1},
                                  {2,  -1},
                                  {-2, 1},
                                  {-2, -1}};
    for (int i = 0; i < 8; i++) {
        int newrow = r + dir[i].first;
        int newcol = c + dir[i].second;
        if ((newrow >= 0 && newrow < 8 && newcol >= 0 && newcol < 8) &&
            (!(*boardmap)[newrow][newcol] || ((*boardmap)[newrow][newcol]->getColor() != this->color))) {
            pair<int, int> temp = {newrow, newcol};
            listOfLegalMoves.emplace_back(temp);
        } else {
            continue;
        }
    }
    return listOfLegalMoves;
}

vector<pair<int, int>> Knight::captureMoves(int r, int c) {
    vector<pair<int, int>> a;
    return a;
}

vector<pair<int, int>> Knight::avoidMoves(int r, int c) {
    vector<pair<int, int>> a;
    return a;
}

vector<pair<int, int>> Knight::checkMoves(int r, int c) {
    vector<pair<int, int>> a;
    return a;
}
