#include <iostream>
#include <vector>
#include <cstdlib>
#include<windows.h>

using namespace std;



class Omok
{
private:
    vector<vector<char>> a;
    bool GameEnded = false;
public:
   
    Omok() {}
    Omok(vector<vector<char>> _a)
    {
        a = _a;
    }

    bool CheckGameEnded() {
        return GameEnded;
    }

    int isWin(int x, int y) {

        int cnt = 0;
        while (1)
        {

            for (int A = 0; A < 5; ++A)
            {

                if (x + 4 > 18)
                {
                    continue;
                }
                if (a[x][y] == a[x + A][y])
                {
                    ++cnt;
                    if (cnt == 5)
                    {

                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x + A][y]) {
                    cnt = 0;
                }
            }

            for (int A = 0; A < 5; ++A)
            {
                if (y + 4 > 18)
                {
                    continue;
                }
                if (a[x][y] == a[x][y + A])
                {

                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x][y + A])
                {
                    cnt = 0;
                }
            }

            for (int A = 0; A < 5; ++A)
            {
                if (x - 4 < 0)
                {
                    continue;
                }
                if (a[x][y] == a[x - A][y])
                {
                    // printf("\n x-A : %d", x-A);
                    // printf("%d\n", A);
                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x - A][y]) {
                    cnt = 0;
                }
            }

            for (int A = 0; A < 5; ++A)
            {
                if (y - 4 < 0)
                {
                    continue;
                }
                if (a[x][y] == a[x][y - A])
                {

                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x][y - A])
                {
                    cnt = 0;
                }
            }

            for (int A = 0; A < 5; ++A)
            {
                if (x + 4 > 18 || y + 4 > 18)
                {
                    continue;
                }
                if (a[x][y] == a[x + A][y + A])
                {
                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x + A][y + A]) { cnt = 0; }
            }

            for (int A = 0; A < 5; ++A)
            {
                if (x - 4 < 0 || y - 4 < 0)
                {
                    continue;
                }

                if (a[x][y] == a[x - A][y - A])
                {
                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x - A][y - A]) { cnt = 0; }
            }


            for (int A = 0; A < 5; ++A)
            {
                if (x - 4 < 0 || y + 4 > 18)
                {
                    continue;
                }
                if (a[x][y] == a[x - A][y + A])
                {
                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x - A][y + A]) { cnt = 0; }
            }


            for (int A = 0; A < 5; ++A)
            {
                if (x + 4 > 18 || y - 4 < 0)
                {
                    continue;
                }
                if (a[x][y] == a[x + A][y - A])
                {
                    ++cnt;
                    if (cnt == 5)
                    {
                        return 999;
                        break;
                    }
                }
                else if (a[x][y] != a[x + A][y - A]) { cnt = 0; }
            }
            return 0;
        }
    }

    void SetBoard() {
        system("cls");
        cout << "\n" << "  A" << " B" << " C" << " D" << " E" << " F" << " G" << " H" << " I" << " J" << " K" << " L" << " M" << " N" << " O" << " P" << " Q" << " R" << " S" << endl;

        for (int i = 0; i < 19; ++i)
        {
            if (i == 0)
            {

            }
            cout << char(65 + i);
            for (int j = 0; j < 19; ++j)
            {
                cout << " " << a[i][j];
            }
            cout << endl;
        }

    }

   


    void Stone()
    {
        int p1 = 0, p2 = 0;
        char _b, _c;

        for (int i = 0; i < 2; ++i)
        {
            cin >> _c >> _b;
            // printf("%d, %d, %d", int(_c), int(_b), int('S'));

            if (i == 0)
            {
                if (int(_c) > int('S') || int(_b) > int('S') || a[int(_b) - 65][int(_c) - 65] == 'O' || a[int(_b) - 65][int(_c) - 65] == 'X')
                {
                    cout << "잘못된 위치입니다. 다시 하세요. 또는 잘못된 좌표입니다. 다시 입력하세요.";
                    return;
                }
                a[int(_b) - 65][int(_c) - 65] = 'X';
                cout << a[int(_b) - 65][int(_c) - 65];
                int n = isWin(int(_b) - 65, int(_c) - 65);
                if (n == 999) {
                    SetBoard();
                    cout << "흑 승리";
                    GameEnded = true;
                    return;
                    break;

                }
            }
            if (i == 1)
            {
                bool check = true;

                do {
                    if (int(_c) > int('S') || int(_b) > int('S') || a[int(_b) - 65][int(_c) - 65] == 'O' || a[int(_b) - 65][int(_c) - 65] == 'X')
                    {
                        cout << "잘못된 위치입니다. 다시 하세요. 또는 잘못된 좌표입니다. 다시 입력하세요.";
                        check = true;
                        cin >> _c >> _b;
                    }
                    else {
                        check = false;
                    }

                } while (check == true);

                a[int(_b) - 65][int(_c) - 65] = 'O';
                cout << a[int(_b) - 65][int(_c) - 65];
                int n = isWin(int(_b) - 65, int(_c) - 65);
                if (n == 999)
                {
                    SetBoard();
                    cout << "백 승리";
                    GameEnded = true;
                    return;
                    break;

                }
            }
            SetBoard();

        }
    }
};



class OmokAI:Omok
{
public:
};





int main()
{
    vector<vector<char>> v(20);

    cout << "  A" << " B" << " C" << " D" << " E" << " F" << " G" << " H" << " I" << " J" << " K" << " L" << " M" << " N" << " O" << " P" << " Q" << " R" << " S" << endl;

    for (int i = 0; i < 19; ++i)
    {
        if (i == 0)
        {

        }
        cout << char(65 + i);
        for (int j = 0; j < 19; ++j)
        {
            cout << " .";
            v[i].push_back('.');
        }
        cout << endl;
    }

    Omok o(v);

    while (1)
    {
        o.Stone();
        if (o.CheckGameEnded()) break;

    }

}
