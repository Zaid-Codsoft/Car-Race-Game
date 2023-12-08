#pragma once

#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <windows.h>
#include<fstream>
using namespace std;
			//created a template class for linked list......................
template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node(T data) :data(data), next(NULL) {}

};
			//class for LINKED LIST..........................
template <typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList() : head(nullptr) {}

	~LinkedList() {
		while (head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void insertFront(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	void insertEnd(T value) {
		Node<T>* newNode = new Node<T>(value);

		if (!head) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void deleteNode(T value) {
		Node<T>* current = head;
		Node<T>* prev = nullptr;

		while (current && current->data != value) {
			prev = current;
			current = current->next;
		}

		if (current) {
			if (prev) {
				prev->next = current->next;
			}
			else {
				head = current->next;
			}
			delete current;
		}
	}
	void showw() const {
		Node<T>* current = head;
		if (current) {
			cout << current->data << " ";
			current = current->next;
		}

		//cout << endl;
	}
	void display() const {
		Node<T>* current = head;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}

		//cout << endl;
	}
};
			// creating template for queues....................
template <typename T>
class queue {
	Node<T>* front;
	Node<T>* rear;
public:
	queue() {
		front = nullptr;
		rear = nullptr;

	}
	~queue() {
		while (!isEmpty()) {
			dequeue();
		}
	}
	bool isEmpty() const {
		return front == nullptr;
	}
	void enqueue(T val) {
		Node<T>* newNode = new Node<T>(val);
		if (isEmpty()) {

			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}
	T dequeue() {
		if (isEmpty()) {

			return -1;

		}
		else {
			T removedata = front->data;
			Node<T>* temp = front;
			front = front->next;
			delete temp;
			if (front == nullptr) {
				rear = nullptr;
			}
			return removedata;
		}

	}
	void display() {
		if (isEmpty()) {
			cout << "EMpty Stack:";
		}
		Node<T>* current = front;
		while (current != nullptr) {
			cout << " " << current->data;
			current = current->next;
		}
		cout << endl;
	}
	T Front() const {
		if (isEmpty()) {

			return T();
		}
		return front->data;
	}
};

				// class for graph.....................

class graph {
public:
	int** adjmat;
	int n;
	bool** obstacles;
	bool** powerup;
	bool** Trophy;
	bool** Coins;
	char** grid; // the grid with a car
	int score;
	string name;
	int coins;
	int trophy;
	int cR, cC; // Current position of  CAR

	graph(int v) {
		n = v;
		cR = 0;
		cC = 0;
		coins = 0;
		trophy = 0;
		score = 0;
		name = "";
		adjmat = new int* [v];
		obstacles = new bool* [v];   //obstacles
		powerup = new bool* [v];	//powerup
		Trophy = new bool* [v];		//trophy
		Coins = new bool* [v];		//coins
		grid = new char* [v];		//grid

		for (int i = 0; i < v; ++i) {
			adjmat[i] = new int[v];
			obstacles[i] = new bool[v];
			powerup[i] = new bool[v];
			Trophy[i] = new bool[v];
			Coins[i] = new bool[v];
			grid[i] = new char[v];

			for (int j = 0; j < v; ++j) {
				adjmat[i][j] = 0;
				obstacles[i][j] = false;
				powerup[i][j] = false;
				Trophy[i][j] = false;
				Coins[i][j] = false;
				grid[i][j] = ' ';
			}
		}
	}
		// Linked List and queue object................
	queue<char> cq;
	LinkedList<char> LL;    
	LinkedList<char> LC;
	LinkedList<char> NT;
	LinkedList<char> NC;
		
	void addEdge(int n, int v, bool bi) {
		adjmat[n][v] = 1;
		if (bi) {
			adjmat[v][n] = 1;
		}
	}
	void addObstacle(int i, int j) {		// function for adding obstacles
		obstacles[i][j] = true;
		cq.enqueue('#');
	}
	void addPowerup(int i, int j) {			// function for adding powerup
		powerup[i][j] = true;

	}
	void addTrophy(int i, int j) {			// function for adding Trophy
		Trophy[i][j] = true;
		LL.insertEnd('T');
	}
	void addCoins(int i, int j) {			// function for adding coins
		Coins[i][j] = true;
		LC.insertEnd('$');
	}



	void display() {							// Displaying graph for the Grid and path............
		cout << "\n     ------------------\n";
		cout << "     |  E             |" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << "--> |  ";
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'c') {
					cout << "C ";

				}

				else if (adjmat[i][j] == 1) {
					if (obstacles[i][j] || powerup[i][j] || Trophy[i][j] || Coins[i][j]) {
						if (powerup[i][j]) {
							// this will change the obstacles......
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);

							cout << "% ";

							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						}
						else if (obstacles[i][j]) {
							cq.dequeue();
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
							cout << "# ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


						}
						else if (Coins[i][j]) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);

							cout << "$ ";

							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						}
						else if (Trophy[i][j]) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

							cout << "T ";

							// Reset console text attribute to default
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						}
					}
					else {
						cout << "+ ";
					}

				}


				else {
					cout << "  ";
				}
			}

			cout << "|" << endl;
			if (i == 0) {
				cout << "     |  |   |         |                              PRESS  P  to pause the Game ...." << endl;
				cout << "     |  |   |         |" << endl;
			}
			else if (i == 1) {
				cout << "     |  |       |   | |" << endl;
				cout << "     |  |       |   | |                             CONTROLS :                       SYMBOL REPRESENTATION :" << endl;
			}
			else if (i == 2) {
				cout << "     |    |     |   | |                             W: Accelerate		     OBSTACLES : #" << endl;
				cout << "     |    |     |   | |                             S: Back			     POWER-UP : %" << endl;
			}
			else if (i == 3) {
				cout << "     |    |         | |                             A: Left			     TROPHY : T" << endl;
				cout << "     |    |         | |                             D: Right			     COINS : $" << endl;
			}
			else if (i == 4 || i == 5) {
				cout << "     |        |     | |" << endl;
				cout << "     |        |     | |" << endl;
			}
			else if (i == 6) {
				cout << "     |    S           |" << endl;
				cout << "     ------------------" << endl;
			}
			else {
				cout << "     |" << endl;
				cout << "     |" << endl;
			}
		}
	}

	void moveCar(char d) {			// moving Car by keys buttons............
		int newRow = cR;
		int newCol = cC;

		switch (d) {
		case 'W':
		case 'w':
			newRow = max(0, cR - 1);  // this will Move the car as index is stored

			break;
		case 'S':
		case 's':
			newRow = min(n - 1, cR + 1);

			break;
		case 'A':
		case 'a':
			newCol = max(0, cC - 1);

			break;
		case 'D':
		case 'd':
			newCol = min(n - 1, cC + 1);

			break;
		case 'P':
		case 'p':
			system("pause");

		default:
			break;
		}

		
		if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && adjmat[newRow][newCol] == 1 /*&& !obstacles[newRow][newCol]*/) {
			grid[cR][cC] = ' ';
			cR = newRow;
			cC = newCol;
			grid[cR][cC] = 'c';
			score++;

			if (obstacles[newRow][newCol]) {
				score = score - 5;
				cout << " \n\n			HITTED WITH OBSTACLE !!!    [|  Score is  -5 |]\n\n";
				obstacles[newRow][newCol] = false;
				Sleep(1000);

			}
			if (powerup[newRow][newCol]) {
				score = score + 3;
				cout << " \n\n			BOOSTED WITH POWERUP...%%%%    [|  Score +3... |]\n\n";

				Sleep(1000);

			}
			if (Coins[newRow][newCol]) {
				score = score + 10;
				coins++;
				NC.insertEnd('$');
				Coins[newRow][newCol] = false;
				cout << " \n\n			COIN COllECTED....$$$$    [|  Score +10... |]\n\n";

				Sleep(1000);

			}
			if (Trophy[newRow][newCol]) {
				score = score + 20;
				trophy++;
				NT.insertEnd('T');
				Trophy[newRow][newCol] = false;
				cout << " \n\n			TROPHY COLLECTED...TTTT    [|  Score +20... |]\n\n";

				Sleep(1000);

			}
			if (grid[cR][cC] == grid[0][0]) {
				cout << " \n\n           GAME WIN ! You reached at the End. \n\n	   YOU WIN THE RACE WITH SCORE :  " << score << endl;
				updateboard();
				totalT();
				totalC();
				exit(0);
			}
		}
	}
	void displayboard() {               // this will display the score card of the user.............
		ifstream inFile("FILE.txt");

		if (inFile.is_open()) {
			string name;
			int score;
			

			while (inFile >> name >> score) {
				cout << " Name: " << name << "     Score: " << score << endl;
				
			}

			inFile.close();
		}
		else {
			cerr << "corrupted." << endl;
		}
	}


	void updateboard() {   // this will create file and update the system.......

		ofstream outFile("FILE.txt", ios::app);

		if (outFile.is_open()) {
			outFile << name << "  " << score << endl;

			outFile.close();
		}
		else {
			cout << "Unable to open  filesssssssss." << endl;
		}

	}
	void bfs(int start) {
		bool* visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}

		queue<int> q;

		visited[start] = true;
		q.enqueue(start);

		cout << "BFS traversal starting from  " << start << ": ";

		while (!q.isEmpty()) {
			int current = q.Front();
			cout << current << " ";
			q.dequeue();

			for (int i = 0; i < n; i++) {
				if (adjmat[current][i] == 1 && !visited[i]) {
					visited[i] = true;
					q.enqueue(i);
				}
			}
		}

		cout << endl;

		delete[] visited;
	}
	/*void NC() {
		NC.display();
	}
	void NT() {
		NT.display();
	}*/
	void totalT() {
		cout << "\n\n  TOTAL TROPHIES : ";
		LL.display();
		cout << "  YOU GAIN : " << trophy << "  [ ";
		NT.display();
		cout << "]";

	}
	void totalC() {
		cout << "\n  TOTAL COINS: ";
		LC.display();
		cout << "  YOU GAIN : " << coins << "  [ ";
		NC.display();
		cout << "]";
	}


};
void Randfun(graph g)     // this will create random system..................
{
	srand(time(0));
	int N = 4;
	int x = rand() % N;

	if (x == 0) {
		g.addObstacle(5, 4);
		// g.addObstacle(3, 6);
		g.addObstacle(2, 6);



		g.addPowerup(6, 4);
		g.addPowerup(3, 6);


		g.addTrophy(2, 6);
		g.addTrophy(3, 1);

		g.addCoins(5, 3);
		g.addCoins(5, 6);


	}
	else if (x == 1) {
		g.addObstacle(3, 1);
		// g.addObstacle(3, 6);
		g.addObstacle(1, 0);



		g.addPowerup(6, 4);
		g.addPowerup(3, 6);


		g.addTrophy(5, 6);
		g.addTrophy(2, 4);

		g.addCoins(3, 4);
		g.addCoins(2, 6);

	}
	else if (x == 2) {
		g.addObstacle(6, 5);
		// g.addObstacle(3, 6);
		g.addObstacle(4, 3);



		g.addPowerup(6, 4);
		g.addPowerup(3, 6);


		g.addTrophy(4, 3);
		g.addTrophy(0, 1);

		g.addCoins(0, 2);



	}
	else {
		g.addObstacle(1, 5);
		// g.addObstacle(3, 6);
		g.addObstacle(4, 2);



		g.addPowerup(6, 4);



		g.addTrophy(1, 0);
		g.addTrophy(6, 3);

		g.addCoins(1, 3);
		g.addCoins(6, 2);
		g.addCoins(6, 6);

	}

}
