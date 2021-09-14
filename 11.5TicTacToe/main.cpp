#include <iostream>

using namespace std;

char get_elem(string s, int x , int y);
bool check_row(string s);
char win(string s);

int main(){
    cout<<"11.5 Tic-tac-toe. \n";

    cout << "Input a results of the game Tic-tac-toe: ";
    string str_1, str_2, str_3;
    getline(cin, str_1);
    getline(cin, str_2);
    getline(cin, str_3);



    string s = str_1 + str_2 + str_3;
    return 0;
}

char get_elem(string s, int x , int y){
    if (x == 1 && y == 1) return s[0];
    if (x == 1 && y == 2) return s[1];
    if (x == 1 && y == 3) return s[3];
    if (x == 2 && y == 1) return s[4];
    if (x == 2 && y == 2) return s[5];
    if (x == 2 && y == 3) return s[6];
    if (x == 3 && y == 1) return s[7];
    if (x == 3 && y == 2) return s[8];
    if (x == 3 && y == 3) return s[9];
}

char win(string s){
    for(int i = 1;  i <= 3; i++){
        for (int j = 1; i <= 3; i++){
            if(get_elem(s, i, j) == get_elem(s, i + 1, j + 1) && get_elem(s, i + 1, j + 1) == get_elem(s, i + 2, j + 2))
        }
    }

}
bool check_row(string s){
    string sub_str = "XO.";
    int count_X = 0;
    int count_O = 0;

    for(int i = 0; i < s.length(); i++){
        if(sub_str.find(s[i]) < 0){
            cout << "Incorrect" << endl;
            return 0;
        } else {
            if(s[i] == 'X') count_X++;
            if(s[i] == 'O') count_O++;
        }
    }

    if(win(s) == 'X' && win(s) == 'O'){
        cout << "Incorrect" << endl;
        return 0;
    }
    if (win(s) == 'X' && count_O >= count_X){
        cout << "Incorrect" << endl;
        return 0;
    }
    if (win(s) == 'O' && count_X > count_O){
        cout << "Incorrect" << endl;
        return 0;
    }
    //if win(s) == 'XXX' || win(s) == 'OOO' выиграли несколько раз;
    return 1;

}

