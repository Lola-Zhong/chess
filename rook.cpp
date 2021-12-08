#include "rook.h"

Rook::Rook(char color, shared_ptr<std::vector<std::vector<std::shared_ptr<Piece>>>> boardmap) : Piece(color, 5,
                                                                                                      boardmap) {}

bool Rook::check(int torow, int tocol, int kingrow, int kingcol) {
    if (tocol == kingcol) {
        bool check = true;
        if (torow < kingrow) {
            for (int i = torow + 1; i < kingrow; i++) {
                if ((*boardmap)[i][tocol] != nullptr) {
                    check = false;
                    break;
                }
            }
            return check;
        } else {
            for (int i = kingrow + 1; i < torow; i++) {
                if ((*boardmap)[i][tocol] != nullptr) {
                    check = false;
                    break;
                }
            }
            return check;
        }
    } else if (torow == kingrow) {
        bool check = true;
        if (tocol < kingcol) {
            for (int i = tocol + 1; i < kingcol; i++) {
                if ((*boardmap)[torow][i] != nullptr) {
                    check = false;
                    break;
                }
            }
            return check;
        } else {
            for (int i = kingcol + 1; i < tocol; i++) {
                if ((*boardmap)[torow][i] != nullptr) {
                    check = false;
                    break;
                }
            }
            return check;
        }

    } else {
        return false;
    }
}

pair<int, int> Rook::legalMove(int r, int c) {
    /* vector<pair<int, int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
     pair<int, int> temp = {-1, -1};
     for (int i = 0; i < 8; ++i) {
         int j = 1;
         while (true) {
             int newrow = r + j * dir[i].first;
             int newcol = c + j * dir[i].second;
             if (newrow > 8 || newrow < 0 || newcol > 8 || newcol < 0) {
                 break;
             }
             if (boardmap[newrow][newcol]->color == currentPlayer) {
                 break;
             } else {
                 temp = {newrow, newcol};
                 return temp;
             }
             j++;
         }
     }
     return temp;*/
}

pair<int, int> Rook::capture(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}

pair<int, int> Rook::avoid(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}

pair<int, int> Rook::checks(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}
