#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <time.h>
#include <fstream>  

using namespace std;

void setup(int distances[4][4]) {
	//Random Graph generator
	
	/*srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		distances[i][i] = 0;
		for (int j = i + 1; j < 4; j++) {
			int d = rand() % 50;

			distances[i][j] = d;
			distances[j][i] = d;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << distances[j][i]<<" ";
		}
		cout << endl;
	}
	cout << endl;*/

	//Test Case 1

	/*distances[0][0] = 0;
	distances[0][1] = 10;
	distances[0][2] = 15;
	distances[0][3] = 20;
	distances[1][0] = 10;
	distances[1][1] = 0;
	distances[1][2] = 35;
	distances[1][3] = 25;
	distances[2][0] = 15;
	distances[2][1] = 35;
	distances[2][2] = 0;
	distances[2][3] = 30;
	distances[3][0] = 20;
	distances[3][1] = 25;
	distances[3][2] = 30;
	distances[3][3] = 0;*/


	//Test Case 2
	/*
	distances[0][0] = 0;
	distances[0][1] = 4;
	distances[0][2] = 1;
	distances[0][3] = 3;
	distances[1][0] = 4;
	distances[1][1] = 0;
	distances[1][2] = 2;
	distances[1][3] = 1;
	distances[2][0] = 1;
	distances[2][1] = 2;
	distances[2][2] = 0;
	distances[2][3] = 5;
	distances[3][0] = 3;
	distances[3][1] = 1;
	distances[3][2] = 5;
	distances[3][3] = 0;*/

	//Test Case 3

	/*
	distances[0][0] = 0;
	distances[0][1] = 2;
	distances[0][2] = 4;
	distances[0][3] = 3;
	distances[1][0] = 2;
	distances[1][1] = 0;
	distances[1][2] = 3;
	distances[1][3] = 6;
	distances[2][0] = 4;
	distances[2][1] = 3;
	distances[2][2] = 0;
	distances[2][3] = 1;
	distances[3][0] = 3;
	distances[3][1] = 6;
	distances[3][2] = 1;
	distances[3][3] = 0;*/


	distances[0][0] = 0;
	distances[0][1] = 1011;
	distances[0][2] = 1102;
	distances[0][3] = 1266;
	distances[1][0] = 1011;
	distances[1][1] = 0;
	distances[1][2] = 491;
	distances[1][3] = 267;
	distances[2][0] = 1102;
	distances[2][1] = 491;
	distances[2][2] = 0;
	distances[2][3] = 347;
	distances[3][0] = 1266;
	distances[3][1] = 267;
	distances[3][2] = 347;
	distances[3][3] = 0;
}

int main() {
	int max = 4;

	int distances[4][4];

	setup(distances);

	vector<int> route(max);
	vector<int> currentroute;
	vector<int> betterroute;
	iota(route.begin(), route.end(), 0);

	int best_distance = std::numeric_limits<int>::max();
	do {
		int distance = 0;
		for (int i = 1; i < route.size(); i++) {
			distance += distances[route[i - 1]][route[i]];
			currentroute.push_back(route[i-1]);
			if (distance > best_distance)
				break;
		}
		distance += distances[route[max - 1]][0];

		if (distance < best_distance)
		{
			betterroute = currentroute;
			best_distance = distance;
		}
		currentroute.clear();
	} while (next_permutation(route.begin() + 1, route.end()));

	cout << "Best Distance: " << best_distance << endl;
	cout << "Best Route: ";

	std::ofstream outfile("path.txt");

	for (int i = 0; i < betterroute.size(); i++)
	{
		cout << betterroute[i] << "->";
		outfile << betterroute[i] <<  endl;
	}
	
	bool flag=false;
	for (int i = 0; i < max; i++)
	{
		flag = false;
		for (int j=0; j < betterroute.size(); j++)
		{
			if (flag == true)
			{
				break;
			}
			if (betterroute[j] == i)
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << i<<endl;
			outfile << i;
		}
	}
	

	

	outfile.close();
	system("pause");
}