#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//it's a 'rock, paper, scissors' game by Nadir Alishly

int main()
{
	int next_game=-1; //next game variable
	string save_name[100];
	int save_score[100][4];


	cout << "Hello, this is 'Rock, paper, scissors' game!" << endl; //welcome

	while(1) //main loop
	{
		int choise=0, round=0, i=0, item_num=0, data_choise=0; //main variables
		int choise_error=0, round_error=0, data_choise_error=0, item_choise_error=0; //error variables
		int count=0, win=0, lose=0, draw=0; //result counting variable
		string name, item, op_item; //srings

		while(choise!=1 && choise!=2) //game menu loop
		{
			if(choise_error==1) //menu error loop
			{
				cout << "You need to enter 1 or 2 (or 3 and 4, if visible)" << endl;
				choise_error=0;
			}

			cout << endl << "1) Start new game" << endl << "2) Exit" << endl << "Choise:";
			cin >> choise;
			choise_error=1;
		}

		if(choise==1) //new game loop
		{

			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Please, enter your name: "; //name reder
			cin >> name;
			cout << endl;

			while(round<=0) //round reader loop
			{	
				if(round_error==1) //round error loop
				{
					cout << endl << "You need to enter a number more than 0" << endl << endl;
					round_error=0;
				}

				cout << name << ", how many rounds do you want to play?" << endl << "Answer:";
				cin >> round;
				round_error=1;
			}	

			for(i=1;i<=round;i++) //round player loop
			{
				item_num=0;
				item_choise_error=0;
				int op; //opponent's choise variable
				op = (rand()%3)+1; //opponents choise randomiser

				switch(op) //opponent's choise to string
				{
					case 1:
						op_item="Rock";
						break;
					case 2:
						op_item="Paper";
						break;
					case 3:
						op_item="Scissors";
						break;		
				}

				//cout << op << endl; //uncomment to see what opponent chose (CHEAT)

				while(item_num!=1 && item_num!=2 && item_num!=3) //item chosing loop
				{
					if(item_choise_error==1) //item error loop
					{
						cout << endl << "You ned to chose 1,2 or 3" << endl;
						item_choise_error=0;
					}

					cout << endl << "----------" << endl; //round menu
					cout << "Round " << i << endl;
					cout << "Chose one:" << endl;
					cout << "1) Rock" << endl << "2) Paper" << endl << "3) Scissors" << endl;
					cout << "Choise:";
					cin >> item_num;
					item_choise_error=1;
				}

				switch(item_num) //user's choise to string
				{
					case 1:
						item="Rock";
						break;
					case 2:
						item="Paper";
						break;
					case 3:
						item="Scissors";
						break; 	
				}

				cout << endl << item << " vs " << op_item << endl; //choise print
				
				if(item_num+1==op) //result counter
				{
					cout << "You lose round" << endl;
					lose++;
				}
				else if(op+1==item_num)
				{
					cout << "You win round" << endl;
					win++;
				}
				else if(item_num==op+2)
				{
					cout << "You lose round" << endl;
					lose++;
				}
				else if(op==item_num+2)
				{
					cout << "You win round" << endl;
					win++;
				}
				else  
				{
					cout << "Draw" << endl;
					draw++;
				}

			}

			count=win-lose;

			cout<< endl << "####################" << endl; //result printer

			if(count>0)
			{
				cout << "You win the game. Congratulations " << name << endl;
			}
			else if (count<0)
			{
				cout << "You lose the game. Try again, you can do it " << name << endl;
			}
			else
			{
				cout << "It's draw game. And frendly final :)" << endl;
			}

			cout << "Your score is " << count << " ( " << win << " wins, " << lose << " loses, " << draw << " draws)" << endl; //score printer

			next_game++;

			while(data_choise!=1 && data_choise!=2 && data_choise!=3) //save menu loop
			{
				if(data_choise_error==1) //save menu error loop
				{
					cout << "You need to enter 1,2 or 3" << endl;
					data_choise_error=0;
				}

				cout << endl << "1) Save score (stats will be indicated)" << endl << "2) Indicate stats" << endl << "3) Continiue" << endl << "Choise:";
				cin >> data_choise;
				data_choise_error=1;
			}

			if(data_choise==1) //save operation
			{
				save_name[next_game]=name;
				save_score[next_game][0]=count;
				save_score[next_game][1]=win;
				save_score[next_game][2]=lose;
				save_score[next_game][3]=draw;
				data_choise=2;
			}

			cout << endl;

			if(data_choise==2) //score indicator
			{
				int d;
				cout << "<><><><><><><><><><><><><><><><><><><><>" << endl << "Stats:" << endl;
				for(d=0;d<=next_game;d++)
				{
					cout << (d+1) << ") " << save_name[d] << ": score " << save_score[d][0] << ", wins " << save_score[d][1] << ", loses " <<  save_score[d][2] << ", draws " << save_score[d][3] << endl; 
				}
				cout << "<><><><><><><><><><><><><><><><><><><><>" << endl;
			}

			cout << "####################" << endl;

		}

		else //exit
		{
			return 0;
		}

	}
		

	return 0;
}
