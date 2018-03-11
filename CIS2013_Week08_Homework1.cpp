#include <iostream>
#include <fstream>
using namespace std;

void draw_board();
char load_locations(char a[10][10]);
char initialize (char a[10][10]);

char strikes[10][10];
char ship_locations[10][10];

int main(){
	
	int score=0;
	int x;
	int y;

	cout << "Pick the board you want to load: ";
	
	load_locations (ship_locations);
	initialize (strikes);
	cout << endl << "          Let's Play!" << endl;
	
	while (score<17){
		draw_board();
		cout << "Type your x and y coordinates (0-9; a space between each): ";
		cin >> x >> y;
		//reverse x and y coordinates when assigning to array
		if (ship_locations[y][x]=='o'){
			cout << endl << "miss..." << endl;
			strikes[y][x]='0';
		}
		else if (ship_locations[y][x]=='x'){
			cout << endl << "Hit!" << endl;
			strikes[y][x]='X';
			score++;
		}
		else {
			cout << endl << "location already attempted.  Pick another."
			<< endl;
		}
		ship_locations[y][x]='s';
	}
	draw_board();
	cout << "You sank my battleship!";
	
	return 0;
}
char initialize (char a[10][10]){
	for(int x=0; x<10; x++){
		for( int y=0; y<10; y++){
			strikes[x][y] = '~';
		}
	}
}

void draw_board(){
	cout << endl << "       0 1 2 3 4 5 6 7 8 9" << endl;
	cout <<  "       ____________________" << endl;
	
	for(int x=0; x<10; x++){
		cout << "    " << x << " | ";
		for( int y=0; y<10; y++){
			cout << strikes[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

char load_locations (char a[10][10]){
	char next;
	char boardname[16];
	ifstream board;
	int count = 0;
	bool valid=false;
	
	while (!valid){
	cin >> boardname;
	board.open(boardname);
	if(board.fail()){
		cout << "Unable to open file.  Type another: ";
	}
	else{valid=true;
	}
	}
	while (count<100){
		for (int x=0; x<10; x++){
			for (int y=0; y<10; y++){
				board >> next;
				a[x][y]=next;
				count++;
			}
		}
	}
	board.close();
}




