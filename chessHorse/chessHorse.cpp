#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <string>
using namespace std;

int board[8][8] = { 0 };

int knight(int c1, int r1, int c2, int r2) {
    
    if (c1 == c2 && r1 == r2) return board[0][0];
    else {
        if (board[abs(c1 - c2)][abs(r1 - r2)] != 0)
            return board[abs(c1 - c2)][abs(r1 - r2)];
        else {
            int x1, y1, x2, y2;
            if (c1 <= c2) {
                if (r1 <= r2) {
                    x1 = c1 + 2; y1 = r1 + 1; 
                    
                    x2 = c1 + 1; y2 = r1 + 2;
                }
                else {
                    x1 = c1 + 2; y1 = r1 - 1; x2 = c1 + 1; y2 = r1 - 2;
                }
            }
            else {
                if (r1 <= r2) {
                    x1 = c1 - 2; y1 = r1 + 1; x2 = c1 - 1; y2 = r1 + 2;
                }
                else {
                    x1 = c1 - 2; y1 = r1 - 1; x2 = c1 - 1; y2 = r1 - 2;
                }
            }
            board[abs(c1 - c2)][abs(r1 - r2)] = min(knight(x1, y1, c2, r2), knight(x2, y2, c2, r2)) + 1;
            board[abs(r1 - r2)][abs(c1 - c2)] = board[abs(c1 - c2)][abs(r1 - r2)];
            return board[abs(c1 - c2)][abs(r1 - r2)];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    string pos1, pos2;
    int c1, r1, c2, r2, result;
    const int n = 8;
    
    cout << "Введите pos1: ";
    cin >> pos1;
    cout << "Введите pos2: ";
    cin >> pos2;
    char f[9] = "abcdefgh";
    for (int i = 0; i < 8; i++) {
        if (f[i] == pos1[0]) c1 = i + 1;
        if (f[i] == pos2[0]) c2 = i + 1;
    }
    r1 = (int)pos1[1]-48;
    r2 = (int)pos2[1]-48;

    //углы:
    if ((c1 == 1 && r1 == 1 && c2 == 2 && r2 == 2) ||
        (c1 == 2 && r1 == 2 && c2 == 1 && r2 == 1)) result = 4;
    else if ((c1 == 1 && r1 == n && c2 == 2 && r2 == n - 1) ||
        (c1 == 2 && r1 == n - 1 && c2 == 1 && r2 == n)) result = 4;
    else if ((c1 == n && r1 == 1 && c2 == n - 1 && r2 == 2) ||
        (c1 == n - 1 && r1 == 2 && c2 == n && r2 == 1)) result = 4;
    else if ((c1 == n && r1 == n && c2 == n - 1 && r2 == n - 1) ||
        (c1 == n - 1 && r1 == n - 1 && c2 == n && r2 == n)) result = 4;
    else {
        board[0][1] = 3; board[0][2] = 2;
        board[1][0] = 3; board[1][1] = 2; board[1][2] = 1;
        board[2][0] = 2; board[2][1] = 1;
        result = knight(c1, r1, c2, r2);
    }

    cout << result;
    cin.get();
    return 0;
}