// Tic Tac Toe
#include <iostream>
using namespace std;

void DrawBoard(char board[]);
void WriteName(char name[]);
int CheckWinner(char board[]);

int main() {
	const int NameSize = 50;
	char nameP1[NameSize];
	char nameP2[NameSize];
	char playAgain; // y/n
	char changeName; // y/n
	int winsP1 = 0;
	int winsP2 = 0;
	bool nameValidation;

	int turn_player = 0; // 0:P1, 1:P2
	int turn;
	int winner; // 0:none, 1:P1, 2:P2, 3:draw

	char board[9];

	do { // loop to check new names
		system("cls");
		cout << "********* Tic Tac Toe *********\n";
		cout << "Enter name of Player 1(X): ";
		/*
		do {
			cin.getline(nameP1, NameSize);
			if (cin.fail()) {
				cout << "Enter a valid name\n";
				nameValidation = false;
				continue;
			}
			nameValidation = true;
		} while (!nameValidation);
		*/
		cout << "Enter name of Player 2(O): ";
		cin.getline(nameP2, NameSize);
		cout << "******************************\n";

		do { // loop to ask for playing again
			// initialise board
			board[0] = '1';
			board[1] = '2';
			board[2] = '3';
			board[3] = '4';
			board[4] = '5';
			board[5] = '6';
			board[6] = '7';
			board[7] = '8';
			board[8] = '9';

			do { // loop till one game ends
				system("cls");
				cout << "********* Tic Tac Toe *********\n";
				cout << "Turn : ";
				if (turn_player == 0) {
					WriteName(nameP1);
					cout << " (X)\n";
				}
				else {
					WriteName(nameP2);
					cout << " (O)\n";
				}

				DrawBoard(board);

				do {
					cout << "Enter a valid place (1-9): ";
					cin >> turn;

					if (board[turn - 1] != 'X' && board[turn - 1] != 'O') {
						if (turn_player == 0){
							board[turn - 1] = 'X';
						}
						else {
							board[turn - 1] = 'O';
						}
					}
					else {
						turn = -1; // will cause loop to run again
					}
				} while (turn < 1 || turn > 9);

				turn_player = (turn_player + 1) % 2; // next turn

				winner = CheckWinner(board);

			} while (winner == 0);

			system("cls");
			cout << "********* Tic Tac Toe *********\n";
			DrawBoard(board);

			switch (winner) {
			case 1: cout << "Winner is Player 1 (" << nameP1 << ")!\n";
				winsP1++;
				break;
			case 2: cout << "Winner is Player 2 (" << nameP2 << ")!\n";
				winsP2++;
				break;
			case 3: cout << "It's a draw!\n";
				break;
			}
			cout << "Wins Player 1 (" << nameP1 << "): " << winsP1 << '\n';
			cout << "Wins Player 2 (" << nameP2 << "): " << winsP2 << '\n';
			cout << "Do you want to play again? (y/n) ";
			cin >> playAgain;
		} while (playAgain == 'y');

		cout << "Do you want to change player name? (y/n) ";
		cin >> changeName;

		cin.ignore();
	} while (changeName == 'y');

	system("cls");
	cout << "********* Tic Tac Toe *********\n";
	cout << "Wins Player 1 (" << nameP1 << "): " << winsP1 << '\n';
	cout << "Wins Player 2 (" << nameP2 << "): " << winsP2 << '\n';
	cout << "******************************\n";
	cout << "*     Thanks for playing     *\n";
	cout << "******************************\n";


	system("pause");
	return 0;
}

void DrawBoard(char board[]){
	cout << "***************\n";
	cout << "*  " << board[0] << " | " << board[1] << " | " << board[2] << "  * \n";
	cout << "* --- --- ---" << " *\n";
	cout << "*  " << board[3] << " | " << board[4] << " | " << board[5] << "  * \n";
	cout << "* --- --- ---" << " *\n";
	cout << "*  " << board[6] << " | " << board[7] << " | " << board[8] << "  * \n";
	cout << "***************\n";
}

void WriteName(char name[]) {
	for (int i = 0; name[i] != '\0'; i++) {
		cout << name[i];
	}
}

int CheckWinner(char board[]) {
	//returns 0:none, 1:P1, 2:P2, 3:draw
	//check horizontal
	for (int i = 0; i <= 6; i += 3) {
		if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
			if (board[i] == 'X') {
				return 1;
			}
			else if (board[i] == 'O') {
				return 2;
			}
		}
	}
	//check vertical
	for (int i = 0; i <= 3; i++) {
		if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
			if (board[i] == 'X') {
				return 1;
			}
			else if (board[i] == 'O') {
				return 2;
			}
		}
	}
	// check '\'
	if (board[0] == board[4] && board[0] == board[8]) {
		if (board[0] == 'X') {
			return 1;
		}
		else if (board[0] == 'O') {
			return 2;
		}
	}
	// check '/'
	if (board[2] == board[4] && board[2] == board[6]) {
		if (board[2] == 'X') {
			return 1;
		}
		else if (board[2] == 'O') {
			return 2;
		}
	}

	//check if any empty space
	for (int i = 0; i < 9; i++) {
		if (board[i] != 'X' && board[i] != 'O') {
			return 0;
		}
	}
	// if noone wins and grid full, its draw 
	return 3;
}