#include "bishop.h"

Bishop::Bishop(char color, shared_ptr<std::vector<std::vector<std::shared_ptr<Piece>>>> boardmap) : Piece(color, 3,
                                                                                                          boardmap) {}

bool Bishop::check(int torow, int tocol, int kingrow, int kingcol) {
    if (abs(torow - kingrow) == abs(tocol - kingcol)) {
        bool check = true;
        if (kingrow > torow && kingcol > tocol) {
            for (int i = 1; i < abs(torow - kingrow); i++) {
                if ((*boardmap)[torow + i][tocol + i] != nullptr) {
                    return false;
                }
            }
            return check;
        } else if (kingrow < torow && kingcol < tocol) {
            for (int i = 1; i < abs(torow - kingrow); i++) {
                if ((*boardmap)[kingrow + i][kingcol + i] != nullptr) {
                    return false;
                }
            }
            return check;

        } else if (torow > kingrow && tocol < kingcol) {
            for (int i = 1; i < abs(torow - kingrow); i++) {
                if ((*boardmap)[kingrow + i][tocol + i] != nullptr) {
                    return false;
                }
            }
            return check;
        } else {
            for (int i = 1; i < abs(torow - kingrow); i++) {
                if ((*boardmap)[torow + i][kingcol + i] != nullptr) {
                    return false;
                }
            }
            return check;
        }
    } else {
        return false;
    }
}

pair<int, int> Bishop::legalMove(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}

pair<int, int> Bishop::capture(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}

pair<int, int> Bishop::avoid(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}

pair<int, int> Bishop::checks(int r, int c) {
    pair<int, int> a = {0, 0};
    return a;
}