// NQueens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stack>
#include <array>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>> board, int N){
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void printStack(stack<int> place) {
	if (!place.size() == 0) {
		
		while (!place.empty()) {
			cout << place.top() << ", ";
			place.pop();
		}
		cout << endl;
	}
	else {
		cout << "empty" << endl;
	}
}

bool placeValid(vector<vector<int>> board, int j, int cRow, int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (board[i][k] == 1) {
				if (i == cRow && k == j) {
					continue;
				}
				if (i == cRow || k == j) {
					return false;
				}
				else if (abs(k - j) == abs(cRow - i)) {
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	std::cout << "Determine N for NxN board:  ";
	int n;
	cin >> n;
	vector<vector<int>> board(n);
	for (int c = 0; c < n; c++) {
		board[c].resize(n);
	}

	stack<int> j_locations;
	//j_locations.push(1);
	int i = 0;
	int j = 0;
	int Qplaced = 0;

	while (i < n) {
		while (j < n) {
			if ((placeValid(board, j, i, n))) {
				j_locations.push(j);
 				board[i][j] = 1;
				Qplaced++;


				cout << i << ", " << j << "  set 1" <<  endl;
				printStack(j_locations);
				printBoard(board, n);
				
				
				i++;
				j = 0;
				break;
			} else if (j < n - 1) {
				cout << i << ", " << j << "  pass" << endl;
				printStack(j_locations);
				printBoard(board, n);
				
				
				j++;
				continue;
			} else {
				cout << i << ", " << j << "  pass" << endl;
				printStack(j_locations);
				printBoard(board, n);


				j = j_locations.top();
				i--;
				j_locations.pop();
				board[i][j] = 0;
				Qplaced--;
				
				
				cout << i << ", " << j << "  pop" << endl;
				printStack(j_locations);
				printBoard(board, n);


				if (j == n - 1) {
					j = j_locations.top();
					i--;
					j_locations.pop();
					board[i][j] = 0;
					Qplaced--;
					
					
					cout << i << ", " << j << "  pop" << endl;
					printStack(j_locations);
					printBoard(board, n);
					
					
					j++;
				}
				else {
					j++;
				}
				break;
			}
		}
	}
	if (Qplaced == n) {
		printBoard(board, n);
	}
	return 0;
}

	

//Made using the Visual Studio IDE
