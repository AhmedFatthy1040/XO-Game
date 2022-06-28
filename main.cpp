#include <iostream>
using namespace std;

/**
 Made By Ahmed Fatthi , Student ID : 20210089
*/

char Matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char Player = 'X';
void PrintMatrix() {
    int i, j;
    system("cls");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << Matrix[i][j] << "\t";
        cout << "\n" << "\n";
    }
}
void Input() {
    char Position;
    cout << "Choose Your Position - Player ( " << Player << " ) : ";
    cin >> Position;
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (Matrix[i][j] == Position)
                Matrix[i][j] = Player;
    if (Player == 'X')
        Player = 'O';
    else if(Player == 'O')
        Player = 'X';
}
char Winner() {
    int XCounter = 0, OCounter = 0, Counter = 0, i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (Matrix[i][j] != 'X' && Matrix[i][j] != 'O')
                Counter++;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (Matrix[i][j] == 'X')
                XCounter++;
            else if (Matrix[i][j] == 'O')
                OCounter++;
            if (XCounter == 3 || OCounter == 3)
                return XCounter > OCounter ? 'X' : 'O';
        }
        XCounter = 0;
        OCounter = 0;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (Matrix[j][i] == 'X')
                XCounter++;
            else if (Matrix[j][i] == 'O')
                OCounter++;
            if (XCounter == 3 || OCounter == 3)
                return XCounter > OCounter ? 'X' : 'O';
        }
        XCounter = 0;
        OCounter = 0;
    }

    if (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X')
        return 'X';
    else if (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
        return 'O';
    else if (Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
        return 'X';
    else if (Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O')
        return 'O';

    if (Counter == 0)
        return 'D';

    return 'C';
}
int main()
{
    while (Winner() == 'C') {
        PrintMatrix();
        Input();
    }
    PrintMatrix();
    if (Winner() == 'D')
        cout << "\nIt's a Draw! No One Wins\n\n";
    else
        cout << "The Winner is Player (" << Winner() << ") , Congratulations!\n\n";
    system("pause");
    return 0;
}

