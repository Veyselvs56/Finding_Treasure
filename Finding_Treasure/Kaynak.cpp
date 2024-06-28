#include<iostream>          // PROGRAM THAT CONTAINS TREASURE IN THE CORDINATE SYSTEM 
#include<conio.h>
#include<time.h>         
#include <thread>
using namespace std;
int main() {
	//we defined two random numbers between 1 and 10 
	srand(time(0));
	int random_number_x = (1 + (int)rand() % 10);
	int random_number_y = (1 + (int)rand() % 10);


	double distance_x = 0, distance_y = 0;         
	double total_distance_1 = 0;
	char konum = 'a';               // the position may be an empty character so we assigned it to a for now
	int x = 10, y = 10;            // we could also make the starting position random
	double starting_distance;        

	total_distance_1 = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
	// With the Pythagorean theorem, the distance of the starting point to the treasure is known

	while (konum != '\r') {                 // the loop will run unless enter is entered
		cout << "\nyour lacation is " << x << "," << y;

		cout << "\nEnter direction(n,s,e,w) :";
		konum = _getche();
		switch (konum)
		{
		case 'n':
		case 'N':
			y++; break;
		case's':
		case 'S':
			y--; break;
		case'e':
		case 'E':
			x++; break;
		case'w':
		case 'W':
			x--; break;
		default:cout << "\nyou entered an invalid direction" << endl;   
		}

		distance_x = abs(random_number_x - x);    //abs=absolute value 
		distance_y = abs(random_number_y - y);

		if (x == random_number_x && y == random_number_y)
		{
			cout << "\nyou found the treasure !\n";  
			cout << "treasure location is " << x << "," << y;
			exit(0);               
		}
		else {
			double total_distance_2 = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
			//we calculated the second distance and conditioned it on the first distance
			if (total_distance_1 > total_distance_2) {
				cout << " you got closer";  
			}
			else if (total_distance_1 == total_distance_2) {
				cout << " the same distance"; 
			}
			else {
				cout << " become distant";  
			}
			total_distance_1 = total_distance_2; // at each step we transfer the new location to 
			//the old location because we need to check whether we are close or far from our old state
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
	return 0;
}
