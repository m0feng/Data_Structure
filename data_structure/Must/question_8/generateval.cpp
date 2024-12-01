#include <iostream>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h> /* srand, rand */
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int main()
{
	srand(time(NULL));
	const int val_count = 500000; // 8seconds for selection, 0 seconds
	ofstream file;
	file.open("big-a.txt", ios::out);
	for (int i = 0; i < val_count; i++)
	{
		int val = (rand() % 5000000);
		file << val << endl;
	}
	file.close();
	return 0;
}
