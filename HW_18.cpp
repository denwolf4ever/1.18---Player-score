// HW_18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Player 
{
public:
	string GetName()
	{
		return name;
	}
	Player (string newName, int newScore)
	{
		this->name = newName;
		this->score = newScore;
	}
	int GetScore()
	{
		return score;
	}
	
	Player ();
	~Player ();
void shakersort(Player arr[], int end) {
	
	
	bool b = true;
	//Player* beg = first-1;
	//Player* end = first+size;
	int beg = -1; 
	while (b) {
		b = false;
		beg++;
		for (int i = beg; i < end; i++) {
			if (arr[i].score < arr[i + 1].score)
			{
				swap(*(arr+i), *(arr+i+1));
				b = true;
			}
		}
		if (!b) break;
		end--;
		for (int i = end; i > beg; i--) {
			if (arr[i].score > arr[i - 1].score)
				{
				swap(*(arr + i), *(arr + i + -1));
				b = true;
			}
		}
	}
}
private:
	string name;
	int score;

};



Player::Player()
{
}

Player ::~Player ()
{
}



int main()
{	
	int quant;
   cout << "Please enter the quantity of players" << endl;
   cin >> quant;

   Player* arr = new Player[quant];
 for (int i = 0; i < quant; i++)
   {
	   string newName;
	   int newScore;
	   cout << "Please enter the name of player #" << i+1 << endl;
	   cin >> newName;
	   cout << "Please enter the score of player #" << i + 1 << endl;
	   cin >> newScore;
	   arr[i] = Player(newName, newScore);
   }
   

   for (int i = 0; i < quant; i++)
   {
	  
	   cout << arr[i].GetName() << '\t' << arr[i].GetScore() << endl;
	  
   }
   arr->shakersort(arr, quant);

   for (int i = 0; i < quant; i++)
   {

	   cout << arr[i].GetName() << '\t' << arr[i].GetScore() << endl;

   }

	   
	delete[] arr;
}

