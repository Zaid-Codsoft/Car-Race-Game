// PP PROOO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include"Header.h"
#include <windows.h>
#include <cstdlib>
using namespace std;

int main() {
	//system("Color 71");
	graph g(7);
	g.addEdge(0, 1, true); g.addEdge(0, 2, true); g.addEdge(0, 0, true);
	g.addEdge(1, 0, true); g.addEdge(1, 2, true);	g.addEdge(2, 1, true);
	g.addEdge(3, 4, true); g.addEdge(1, 5, false); g.addEdge(1, 3, true); g.addEdge(3, 6, true); g.addEdge(4, 2, true);
	g.addEdge(4, 1, true);
	g.addEdge(5, 3, true);
	g.addEdge(5, 6, true);
	g.addEdge(6, 1, true);
	g.addEdge(6, 4, true);
	g.addEdge(6, 6, true);
	g.addEdge(6, 2, true);





	// Set the initial position of the car
	g.cR = 6;
	g.cC = 0;
	g.grid[g.cR][g.cC] = 'c';

	while (true) {
		Randfun(g);
		int x = 0;
		

		cout << "\n\n                                        WELCOME TO CAR RACING GAME                        \n\n\n1. MANUAL GAMEPLAY....\n2. AUTO GAMEPLAY....\n3. SCORE CARD.....\n4. EXIT...\n\n";
		cin >> x;
		if (x == 1) {
			cout << " ENTER NAME OF USER :";
			cin >> g.name;
			char move;
			do {
				system("cls");
				//system("Color 71");
				cout << "\n\n SCORE :" << g.score << endl;
				cout << " COINS :" << g.coins << "                    Name :" << g.name << endl;
				cout << "TROPHY :" << g.trophy << endl << endl;

				g.display();

				// cout << "\nBFS: ";
				// g.bfs(0);
				// cout << "\n\n SCORE :" << g.score << endl<<endl;

				cout << "\nUse W/A/S/D to move the car (Q to quit): ";
				move = _getch(); // Get a single character from the console

				if (move != 'Q' && move != 'q') {
					g.moveCar(move);
				}
			} while (move != 'Q' && move != 'q');



		}
		else if (x == 2) {
			cout << "<<<<AUTO>>>>"<<endl;
		}
		else if (x == 3) {
			cout << "\n                          SCORE CARD         \n";
			g.displayboard();
		}
		else if (x == 4) {
			cout << "\n\n YOU HAVE EXIT YOUR GAME :!!!!!!!!\n\n";
			exit(0);
		}
	}

	return 0;
}


