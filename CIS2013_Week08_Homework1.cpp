#include <iostream>
#include <fstream>
using namespace std;

void draw_board();
char load_locations(char locations[10][10]);
char numbers[10][10];
char boardname[16];
char locations[10][10];

int main(){
	
	// int score=0;
	
	// cout >> "Pick the board you want to load: ";
	// cin << boardname;
	load_locations (locations);
	
	
	// for(int x=0; x<10; x++){
		// for( int y=0; y<10; y++){
			// numbers[x][y] = '~';
		// }
	// }
	// draw_board();
	// return 0;
// }

// void draw_board(){
	// cout << endl << "       0 1 2 3 4 5 6 7 8 9" << endl;
	// cout <<  "       ____________________" << endl;
	
	// for(int x=0; x<10; x++){
		// cout << "    " << x << " | ";
		// for( int y=0; y<10; y++){
			// cout << numbers[x][y] << " ";
		// }
		// cout << endl;
	// }
}

char load_locations (char locations[10][10]){
	char next;
	int count = 0;
	ifstream board;
	board.open("board1.dat");
	if(board.fail()){
		cout << "Unable to open file.";
		exit (1);
	}
	while (count<100){
		for (int x=0; x<10; x++){
			for (int y=0; y<10; y++){
				board >> next;
				locations[x][y]=next;
				count++;
			}
		}
	}
}



