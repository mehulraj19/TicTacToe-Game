#include <bits/stdc++.h>

using namespace std;

bool areSame(int r, int c, char card[3][3], char v) {
    if(r<0) return false;
    if(r>2) return false;
    if(c<0) return false;
    if(c>2) return false;
    if(card[r][c] == v) return true;
    return false;
}

bool isWin(int r, int c, char card[3][3], char v) {
    if(r == 0) {
        if(areSame(r+1,c,card,v) && areSame(r+2,c,card,v)) return true; 
        else if(c == 0 && areSame(r,c+1,card,v) && areSame(r,c+2,card,v)) return true;
        else if(c == 1 && areSame(r,c-1,card,v) && areSame(r,c+1,card,v)) return true;
        else if(c == 0 && areSame(r+1,c+1,card,v) && areSame(r+2,c+2,card,v)) return true; 
        else if(c == 2 && areSame(r,c-1,card,v) && areSame(r,c-2,card,v)) return true;
        else if(c == 2 && areSame(r+1,c-1,card,v) && areSame(r+2,c-2,card,v)) return true;
    }else if(r == 1) {
        if(areSame(r-1,c,card,v) && areSame(r+1,c,card,v)) return true;
        else if(c == 0 && areSame(r,c+1,card,v) && areSame(r,c+2,card,v)) return true;
        else if(c == 1 && areSame(r,c+1,card,v) && areSame(r, c-1, card, v)) return true;
        else if(c == 1 && areSame(r-1,c-1,card,v) && areSame(r+1,c+1,card,v)) return true;
        else if(c == 1 && areSame(r+1,c-1,card,v) && areSame(r-1,c+1,card,v)) return true;
        else if(c == 2 && areSame(r,c-1,card,v) && areSame(r,c-2,card,v)) return true;
    }else if(r == 2) {
        if(areSame(r-1,c,card,v) && areSame(r-2,c,card,v)) return true;
        else if(c == 0 && areSame(r,c+1,card,v) && areSame(r,c+2,card,v)) return true;
        else if(c == 0 && areSame(r-1,c+1,card,v) && areSame(r-2,c+2,card,v)) return true;
        else if(c == 1 && areSame(r,c-1,card,v) && areSame(r,c+1,card,v)) return true;
        else if(c == 2 && areSame(r,c-1,card,v) && areSame(r,c-2,card,v)) return true;
        else if(c == 2 && areSame(r-1,c-1,card,v) && areSame(r-2,c-2,card,v)) return true;
    }
    return false;
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
        for(int j=0; j<3; j++) {
            card[i][j] = ' ';
        }
    }
    
    // starting the game
    int numberOfAttemptsToStartGame = 0;
    char userChar1 = ' ', userChar2 = ' ';
    while(userChar1 != 'o' && userChar1 != 'O' && userChar1 != 'X' && userChar1 != 'x' && numberOfAttemptsToStartGame < 2){
        cout << " which char u want to choose: (O or X) ?" << endl;
        cin >> userChar1;
        if(userChar1 == 'O' || userChar1 == 'o') userChar2 = 'X';
        else if(userChar1 == 'X' || userChar1 == 'x') userChar2 = 'O';
        else {
            cout << "Chosen wrong char, choose again....." << endl;
            numberOfAttemptsToStartGame++;
        }
    }
    if(numberOfAttemptsToStartGame == 2) {
        cout << "Too many wrong attempts for the char... \nStopping the game............";
        return 0;
    }
    // main algo
    bool win = false;
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
                    win = isWin(i1, j1, card, userChar1);
                    userNum = 2;
                }else {
                    card[i1][j1] = userChar2;
                    win = isWin(i1, j1, card, userChar2);
                    userNum = 1;
                }
            }
        }
        
        // showing current status of the game
        cout << endl << endl << "current status....." << endl;
        printStatus(card);
        
        if(win) {
            if(userNum == 2) cout << endl << userChar1 << " is the Winner!!";
            else if(userNum == 1) cout << endl << userChar2 << " is the Winner!!";
        } else {
            if(isAllFilled(card)) {
                cout << endl << "Its a Draw!!";
                break;
            }
        }
    }
    return 0;
}
