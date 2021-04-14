#include <bits/stdc++.h>
using namespace std;
const int N = 3;
const int n_players = 2;
const char marks[n_players] = {'X', 'O'};
char grid[N][N];


void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}


bool check_win() {

   for(int i=0;i<N;i++)
        if(grid[i][0]==grid[i][1]&&grid[i][0]==grid[i][2]&&grid[i][0]!='.')
          return 1;
   for(int j=0;j<N;j++)
        if(grid[0][j]==grid[1][j]&&grid[0][j]==grid[2][j]&&grid[0][j]!='.')
        return 1;
    if(grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2]&&grid[0][0]!='.')
      return 1;
    if(grid[0][2]==grid[1][1]&&grid[0][2]==grid[2][0]&&grid[0][2]!='.')
      return 1;

      return 0;
}
bool check_tie_player(char mark) {
   for(int i=0;i<N;i++)
        if(grid[i][0]!=mark&&grid[i][1]!=mark&&grid[i][2]!=mark)
          return 0;
   for(int j=0;j<N;j++)
        if(grid[0][j]!=mark&&grid[1][j]!=mark&&grid[2][j]!=mark)
        return 0;
    if (grid[0][0]!=mark&&grid[1][1]!=mark&&grid[2][2]!=mark)
      return 0;
     if(grid[0][2]!=mark&&grid[1][1]!=mark&&grid[0][2]!=mark)
      return 0;

      return 1;
}

bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}





bool check_empty(int i, int j) {
    return (grid[i][j]=='.');
}


bool check_valid_position(int i, int j) {
return ((i>=0&&i<=2)&&(j>=0&&j<=2));
}

void set_cell(int i, int j, char mark) {
grid[i][j]=mark;
}

void grid_clear() {
 for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
       grid[i][j]='.';

}

void read_input(int &i, int &j) {
	cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}

void play_game() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    bool player = 0;
    while (true) {

        print_grid();

        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);

        set_cell(i, j, marks[player]);

        if (check_win()) {

            print_grid();

            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }


        if (check_tie()) {

            print_grid();

            cout << "Woah! That's a tie!\n";
            break;
        }

        player = 1 - player;
    }
}
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
}    }
