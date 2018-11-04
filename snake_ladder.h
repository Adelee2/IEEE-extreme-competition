#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
//#include <array>
#include <bits/stdc++.h>

using namespace std;

	vector<int> arr_cord;
	vector<int> arr_cord1;
	vector<vector<int>>board;
	int result=0;
	int players;
	
class Get_coord{
	public:
		void snake_coordinate();
		void ladder_coordinate( );
		struct Get_result{
		int results;
		};
		
		Get_result myresult[11]={};
			
};

class Snake_ladder:public Get_coord{
	
	public:
//		Snake_ladder(int size);
		void draw(int size);
		void display();
		int roll_dice(int);
		bool winner(int);
		void display_test();
	~Snake_ladder();	
		
	private:
		int dimension;
		int counting;
		int counting1;
	
};





