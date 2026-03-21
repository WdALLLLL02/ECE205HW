#include <iostream>
using namespace std;
void initialize(char seats[][4], int rows);
void initialize(char seats[][4], int rows){
    for (int i=0;i<rows;i++){
        seats[i][0]='A';
        seats[i][1]='B';
        seats[i][2]='C';
        seats[i][3]='D';
    }
}
void display_map(char seats[][4], int rows);
void display_map(char seats[][4], int rows){
    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "    ";
        for (int j = 0; j < 4; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}
bool taken(char seats[][4], int rows);
bool taken(char seats[][4], int rows){
    for (int i = 0; i < rows; i++)
    {
        for (int j=0;j<4;j++)
        {
            if (seats[i][j] != 'X')
            {
                return false;
            }
        }
    }
    return true;
}
void assignseat(char seats[][4], int rows, int row_num, char seat_letter);
void assignseat(char seats[][4], int rows, int row_num, char seat_letter){
    int row_index=row_num-1;
    int col_index=seat_letter-'A';
    if (row_index<0||row_index>=rows||col_index<0||col_index > 3){
        cout << "invalid" << endl;
        return;
    }

    if (seats[row_index][col_index]=='X'){
        cout<<"Seat is already taken."<< endl;
    }else{
        seats[row_index][col_index]='X';
        cout<<"Seat assigned successfully."<<endl;
    }
}

int main(){
    const int ROWS=10;
    char seats[ROWS][4];
    initialize(seats, ROWS);
    seats[0][1]='X'; //1b
    seats[2][3]='X';//3d
    seats[4][0]='X'; //5a
    char choice='Y';
    while(choice=='Y'||choice == 'y')
    {
        display_map(seats, ROWS);
        if (taken(seats, ROWS)){
            cout << "all seats are taken." << endl;
            break;
        }
        int row_num;
        char seat_letter;
        cout <<"enter row number:";
        cin >> row_num;
        cout << "enter seat letter A,B,C,D:";
        cin >> seat_letter;

        if (seat_letter>='a'&&seat_letter<='d'){
            seat_letter=seat_letter-32;
        }
        assignseat(seats,ROWS,row_num,seat_letter);
        if (taken(seats, ROWS)){
            display_map(seats, ROWS);
            cout <<"all seats are taken."<< endl;
            break;
        }
        cout << "continue adding seats(Y/N): ";
        cin >> choice;
    }
    cout << "Final seat chart:"<<endl;
    display_map(seats, ROWS);
    return 0;
}