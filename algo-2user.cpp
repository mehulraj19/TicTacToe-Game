#include <bits/stdc++.h>

using namespace std;

int isSame(int r, int c, char card[3][3], char v) {
    if(r<0) return 0;
    if(r>2) return 0;
    if(c<0) return 0;
    if(c>2) return 0;
    if(card[r][c] == v) return 1;
    return 0;
}
int didWin(int r, int c, char card[3][3], char v) {
    int win = 0;
    win += isSame(r-1,c,card,v);
    win += isSame(r+1,c,card,v);
    win += isSame(r,c-1,card,v);
    win += isSame(r,c+1,card,v);
    win += isSame(r-1,c+1,card,v);
    win += isSame(r+1,c-1,card,v);
    win += isSame(r+1,c+1,card,v);
    win += isSame(r-1,c-1,card,v);
    return win;
}

void printStatus(char card[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << card[i][j] << "  |  ";
        }
        cout << endl << "---|-----|-----|" << endl;
    }
}

bool isAllFilled(char card[3][3]) {
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) if(card[i][j] == ' ') return false;
    }
    return true;
}

int main()
{
    cout << "intializing the game" << endl;
    char card[3][3];
    // setting all the locations as ' '
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) card[i][j] = ' ';
    }
    
    // starting the game
    int numberOfAttemptsToStartGame = 0;
    char userChar1 = ' ', userChar2 = ' ';
    while(userChar1 != 'o' && userChar1 != 'O' && userChar1 != 'X' && userChar1 != 'x' && numberOfAttemptsToStartGame < 10){
        cout << " which char u want to choose: (O or X) ?" << endl;
        cin >> userChar1;
        if(userChar1 == 'O' || userChar1 == 'o') userChar2 = 'X';
        else if(userChar1 == 'X' || userChar1 == 'x') userChar2 = 'O';
        else {
            cout << "Chosen wrong char, choose again....." << endl;
            numberOfAttemptsToStartGame++;
        }
    }
    if(numberOfAttemptsToStartGame == 10) {
        cout << "Too many wrong attempts for the char... \nStopping the game............";
        return 0;
    }
    // main algo
    bool win = false;
    int win1, win2;
    win1 = win2 = 0;
    char winner;
    // userChar1 will start and then userChar2
    int userNum=1;
    while(!win) {
        int i1, j1;
        cout << "give ur pos....." << endl;
        cin >> i1 >> j1;
        
        // user choosing location
        bool rightPlace = false;
        while(!rightPlace) {
            // check for valid pos
            if((i1<0 || i1 >2) && (j1<0 || j1 > 2)) cout << "this location is not valid, pick another location" << endl;
            // checking if already fill
            else if(card[i1][j1] != ' ') cout << "this location is already fill, pls choose another locaton" << endl;
            else {
                rightPlace = true;
                if(userNum == 1) {
                    card[i1][j1] = userChar1;
                    win1 += didWin(i1, j1, card, userChar1);
                    cout << win1 << " ---- current status for user1 ----" << endl;
                    userNum = 2;
                }else {
                    card[i1][j1] = userChar2;
                    win2 += didWin(i1, j1, card, userChar2);
                    cout << win2 << " ---- current status for user2 ----" << endl;
                    userNum = 1;
                }
            }
        }
        
        // showing current status of the game
        cout << endl << endl << "current status....." << endl;
        printStatus(card);
        
        // giving win status
        if(win1 == 2) {
            cout << endl << userChar1 << " is the Winner!!";
            win = true;
        }
        else if(win2 == 2) {
            cout << endl << userChar2 << " is the Winner!!";
            win = true;
        }
        else{
            if(isAllFilled(card)) cout << endl << "Its a Draw!!";
        }
    }
    return 0;
}
