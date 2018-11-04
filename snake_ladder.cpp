#include "snake_ladder.h"

void Get_coord::snake_coordinate()
{
	string temp;
	int k=0;
	cout<<"\n";
	getline(cin,temp);
	//converting string to array
	
	for(size_t i=0;i<temp.size();i++){
		if(temp[i]!=' '){
		   int arr = temp[i] -'0';
		   arr_cord.push_back(arr);
	   }
    }
    
}

void Get_coord::ladder_coordinate()
{
	string temp;int k=0;
	cout<<"\n";
	getline(cin,temp);
	//converting string to array
	for(size_t i=0;i<temp.size();i++){
		if(temp[i]!=' '){
		   int arr = temp[i] -'0';
		   arr_cord1.push_back(arr);
	   }
    }
}


void Snake_ladder::draw(int size)
{
	dimension=size;
	int k=(dimension * dimension);
	int temp1,temp2;
	for(size_t i=0;i<dimension;i++){
		board.push_back(vector<int>());
		if(i%2==0){
			for(size_t j=0;j<dimension;j++){
				temp1=k-j;
				board[i].push_back(temp1);
			}
			k=temp1-dimension;
		}
		else{
			for(size_t j=0;j<dimension;j++){
//			cout<<j<<" ";
			temp2=k++;
				board[i].push_back(temp2);
//				cout<<board[i][j]<<" ";
			}
			k=temp2-dimension;
		}
	}

}

void Snake_ladder::display()
{
//	draw();
	for(auto i : board){
		for(auto j : i){
			cout<<setw(5)<<j<<setw(5);
		}
		cout<<"\n";
	}
}

int Snake_ladder::roll_dice(int p)
{
//	Get_result myresult[players]; 
     //keeps record of the result of each player
	int die1,die2,die_t,result=0;
	cout<<"\nEnter 1st die ";
	cin>>die1;
	cout<<"\nEnter 2nd die ";
	cin>>die2;
	

	die_t = die1 + die2;
	
	auto len=arr_cord.size();
	auto len1=arr_cord1.size();
	
	cout<<"len "<<len<<"\n";
	cout<<"len1 "<<len1<<"\n";
	for(size_t i=0;i<dimension;i++){
		if(myresult[p].results>(dimension * dimension)){
			cout<<"its out ";
			break;
		}
		else{
		for(size_t j=0;j<dimension;j++){
			
			if(board[i][j]==die_t){
//				cout<<die_t;
				cout<<" ("<<i<<","<<j<<"), ";
				for(size_t k=0;k<len;k+=4){
//					cout<<"test_yes!!!!!!!";
					if(i==arr_cord[k] && j==arr_cord[k+1]){  //if die1 + die2 falls on the head of the snake,go back to its tail result = value of its tail
					cout<<" snake head ";
						result=board[arr_cord[k+2]][arr_cord[k+3]];
					}
					else{
						cout<<" no snake ";
						result+=board[i][j];
					}
				}
				for(size_t m=0;m<len1;m+=4){
					if(i==arr_cord1[m] && j==arr_cord1[m+1]){ //if die1 + die2 falls on ladder,it jumps it up the ladder;result=value of the top ladder
						result+= board[arr_cord1[m+2]][arr_cord1[m+3]];
						cout<<" ladder seen ";
					}
				}
			}
		}
	}
  }
 	myresult[p].results=result;
  cout<<"result "<<p<<" "<<myresult[p].results<<" \n";
//  result=0;
//  return result;
}
void Snake_ladder::display_test(){
	cout<<"entered\n";
	for(size_t i=0;i<dimension;i++){
		for(size_t j=0;j<dimension;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";	
	}
}
bool Snake_ladder::winner(int i)
{
//	Get_result myre
		return (myresult[i].results> (dimension * dimension))? true: false;
}

int main()
{
	int input,i=0,counter=0;

	cout<<"Enter the size of board you want: ";
	cin>>input;
	if(input %2 ==0){
		 int count=0,count1=0;		
		cout<<"Enter number of players: ";
		cin>>players;
		if(players<=10 && players >1)	{
			Get_coord mysnake_ladders;
			int snakes;
				 cout<<"Enter number of snakes: ";
				 cin>>snakes;               //gets total number of snakes
				 cout<<"\n";
				 cout<<"Enter coordinate of the snake";
				 snakes+=1;
				 while(snakes>0){
					mysnake_ladders.snake_coordinate(); //gets coordinates of each snake(its head and tail) and process it
					snakes--;
				}
			int ladders;
				 cout<<"Enter number of ladders: ";
				 cin>>ladders;            //gets total number of ladders
				 cout<<"\n";
				 cout<<"Enter coordinate of the ladder";
				 ladders+=1;
				 while(ladders>0){
					mysnake_ladders.ladder_coordinate();  //gets coordinates of each ladder and process it
					ladders--;
				}
				
	
				Snake_ladder mysnake_ladder[players];  //creates object snake_ladder for as many players as possible
			int total_dice;
				 cout<<"Enter total number of dice: ";
				 cin>>total_dice;
				 
		while(total_dice>0){
			for(size_t i =0;i<players;i++){        //iterates through each player
			 	mysnake_ladder[i].draw(input);
			 	cout<<"\n\nFor player "<<i+1;	
				
//				mysnake_ladder[i].display_test();
				mysnake_ladder[i].roll_dice(i); 	//adds the the dice and checks for snake heads or ladder;if the addition of the dice falls on them do stuffs
				if(mysnake_ladder[i].winner(i)==true){
					cout<<i+1<<" winner\n";
					counter++;
				}
			}
			if(counter==players){
				break;
			}
			else if(counter==0 && total_dice==1){
				cout<<"no winner";
				break;
			}
			
			total_dice--;
		}
	}
	
		else{
			cout<<"players must be between 2 to 10"<<endl;
		}
	}
	else{
		cout<<"input must be an even number"<<endl;
	}
	return 0;
}

//	
