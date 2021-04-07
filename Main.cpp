#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>

using ariel::Direction;
using namespace std;

int main()
{
    ariel::Board board;
	//read empty places
	cout <<board.read(20,5,Direction::Horizontal,6)<<endl;
	cout <<board.read(0,0,Direction::Horizontal,1)<<endl;
	cout <<board.read(4,15,Direction::Vertical,2)<<endl;
	cout <<board.read(100,15,Direction::Vertical,10)<<endl;
	cout <<""<< endl;

	//post empty add
	board.post(0,10, Direction::Horizontal, "");
	cout <<board.read(0,10,Direction::Horizontal,1)<<endl;
	board.post(20,10, Direction::Vertical, "");
	cout <<board.read(20,10,Direction::Vertical,1)<<endl;
	cout <<""<< endl;

	//check  post and read Horizontal
	board.post(0,0, Direction::Horizontal, "hello");
	cout << board.read(0,0, Direction::Horizontal,5) << endl; //print hello
	cout << board.read(0,0, Direction::Horizontal,7) << endl; //print hello__
	cout << board.read(0,0, Direction::Horizontal,3) << endl; //print hel
	cout <<""<< endl;
	//check  post and read Horizontal
	board.post(2,0, Direction::Vertical, "noa");
	cout << board.read(2,0, Direction::Vertical,3) << endl; //print noa
	cout << board.read(2,0, Direction::Vertical,5) << endl; //print noa__
	cout << board.read(0,0, Direction::Vertical,4) << endl; //print h_no
	cout <<""<< endl;
	//check that posting a new ad overturns what it was before
	board.post(1,0, Direction::Horizontal, "hello");
	board.post(2,0, Direction::Horizontal, "hello");
	board.post(3,0, Direction::Horizontal, "hello");
	board.post(4,0, Direction::Horizontal, "hello");
	board.show();
	cout <<""<< endl;
	board.post(0,0, Direction::Vertical, "*****");
	board.post(0,4, Direction::Vertical, "*****");
	board.post(0,0, Direction::Horizontal, "*****");
	board.post(4,0, Direction::Horizontal, "*****");
	board.show();
	cout <<""<< endl;

	ariel::Board newboard;
	newboard.post(100,100, Direction::Vertical, "^^^^^^^^^^^^^^^");
	newboard.post(100,150, Direction::Vertical, "^^^^^^^^^^^^^^^");
	newboard.post(103,126, Direction::Vertical, "*");
	newboard.post(108,146, Direction::Vertical, "*");
	newboard.post(113,111, Direction::Vertical, "*");
	newboard.post(105,103, Direction::Vertical, "*");
	newboard.post(107,123, Direction::Horizontal, "*hello");
	newboard.post(109,123, Direction::Horizontal, "world");
	newboard.show();
}
