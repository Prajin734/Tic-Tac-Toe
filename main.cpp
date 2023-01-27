#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <vector>

using namespace std;

bool player_1_turn {true};
int attempts {3};
int count {};
vector<char> chars = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void build_frame(){
    system("cls");
    cout << " " << chars[0] << " | " << chars[1] << " | " << chars[2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << chars[3] << " | " << chars[4] << " | " << chars[5] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << chars[6] << " | " << chars[7] << " | " << chars[8] << " " << endl;
    cout << "   |   |   " << endl;
}

int check_game(){
    build_frame();
    if(chars[0] == chars[1] && chars[1] == chars[2]){
        throw 0;
    }
    else if(chars[3] == chars[4] && chars[4] == chars[5]){
        throw 0;
    }
    else if(chars[6] == chars[7] && chars[7] == chars[8]){
        throw 0;
    }
    else if(chars[0] == chars[3] && chars[3] == chars[6]){
        throw 0;
    }
    else if(chars[1] == chars[4] && chars[4] == chars[7]){
        throw 0;
    }
    else if(chars[2] == chars[5] && chars[5] == chars[8]){
        throw 0;
    }
    else if(chars[0] == chars[4] && chars[4] == chars[8]){
        throw 0;
    }
    else if(chars[2] == chars[4] && chars[4] == chars[6]){
        throw 0;
    }
    else {
        throw 1;
    }
    return 0;
}

bool check_input(string pos_char){
    if(pos_char.length() > 1)
        return false;
    for(char i: pos_char)
        return isdigit(i);
}

int game_set(){
    if(count == 9){
        cout << "Draw!" << endl;
        return 0;
    }
    count++;
    build_frame();
    if(player_1_turn)
        cout << "Player 1" << endl;
    else
        cout << "Player 2" << endl;
    string pos_char;
    bool is_valid {false};
    while(!is_valid){
        cout << "Enter position: ";
        cin >> pos_char;
        if(!check_input(pos_char)){
            cout << "Invalid Input!" << endl;
            continue;
        }
        int position;
        for(char i: pos_char)
            position = atoi(&i);
        if(chars[position-1] != 'X' || chars[position-1] != 'O'){
            if(player_1_turn){
                chars[position-1] = 'X';
            }
            else {
                chars[position-1] = 'O';
            }
            is_valid = true;
        }
    }
    try {
        check_game();
    }
    catch(int &ex){
        if(ex == 0){
            cout << "Player ";
            if(player_1_turn)
                cout << "1";
            else
                cout << "2";
            cout << " wins!" << endl;
        }
        else if(ex == 1) {
            if(player_1_turn){
                player_1_turn = false;
            }
            else
                player_1_turn = true;
            game_set();
        }
    }
    return 0;
}

int main(){
    build_frame();
    cout << "Tic-Tac-Toe" << endl;
    cout << "Player 1: X, Player 2: O\n" << endl;
    game_set();
    cout << "Game Over!" << endl;
    return 0;
}

