#include <iostream>
using namespace std;
char screen[80][25] = {};
void scanConvertPoint(int x, int y)
{

    screen[x][y] = '*';
}

int main()
{
    int x = 40;
    int y = 12;
    scanConvertPoint(x, y);
    for (int j = 0; j < 25; j++) {
        for (int i = 0; i < 80; i++) {
            cout << screen[i][j];
        }
        cout << endl;
    }

    return 0;
}

