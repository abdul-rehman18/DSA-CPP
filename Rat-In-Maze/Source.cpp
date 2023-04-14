#include<fstream>
#include"myStack.h"
using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");
	int size = 0;
	char c;
	myStack<char> obj(10);
	if (!fin)
		cout << "Data not found" << endl;
	while (fin.get(c)) {
		if (c == '\n') {
			size++;
		}
	}
	if (c != '\n') {
		size++;
	}
	//cout << size << endl;
	fin.close();
	fin.open("input.txt");
	int** maze;
	maze = new int*[size];
	for (int i = 0; i<size; i++)
		maze[i] = new int[size];
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			fin >> maze[i][j];
		}
	}
	cout<<"Original Array is : "<<endl;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	//int visited[4][4];
	int** visited;
	visited = new int*[size];
	for (int i = 0; i<size; i++)
		visited[i] = new int[size];
	
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			visited[i][j] = 0;
		}
	}
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	int k = 0, j = 0;
	bool flag = false;
	while (1)
	{

		if (k >= 0 && k < size && j >= 0 && j < size && maze[0][0] == 1 )
		{
			visited[0][0] = 1;
			if (j + 1<size && maze[k][j + 1] == 1 && visited[k][j + 1] != 1 )
			{
				obj.push('R');
				j++;
				visited[k][j] = 1;
				//continue;
			}
			else if (k + 1<size  && maze[k + 1][j] == 1 && visited[k + 1][j] != 1)
			{

				obj.push('D');
				k++;
				visited[k][j] = 1;
				//continue;
			}
			else if ( j-1>=0 && maze[k][j - 1] == 1 && visited[k][j - 1] != 1 )
			{

				obj.push('L');
				j--;
				visited[k][j] = 1;

			}
			else if (k-1>=0 && maze[k - 1][j] == 1 && visited[k - 1][j] != 1)
			{
				obj.push('U');
				k--;
				visited[k][j] = 1;
				//continue;

			}
			
			else if (obj.top() == 'R')
			{
				maze[k][j] = -1;
				visited[k][j] = 0;
				j--;
				obj.pop();
			}
			else if (obj.top() == 'D')
			{
				maze[k][j] = -1;
				visited[k][j] = 0;
				k--;
				obj.pop();
			}
			else if (obj.top() == 'L')
			{
				maze[k][j] = -1;
				visited[k][j] = 0;
				j++;
				obj.pop();
			}
			else if (obj.top() == 'U')
			{
				maze[k][j] = -1;
				visited[k][j] = 0;
				k++;
				obj.pop();
			}
			else
				break;
			if (k == size - 1 && j == size - 1)
			{
				if (maze[k][j] == 1)
				{
					flag = true;
				}
				break;
			}
		}
		else
		{
			break;
		}
		cout<<"Stack after operation is : "<<endl;
		obj.display();
		cout<<"----------------"<<endl;
	}
	//cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;

	
	cout<<endl;
	cout<<"Orignal Array After Operation is: "<<endl;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"See \"Output.txt\" for more info !!!"<<endl;
	cout<<endl;
	ofstream fout;
	fout.open("Output.txt");
	if (flag)
	{
		fout << "Path Found" << endl;
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				fout << visited[i][j] << " ";
				//cout << visited[i][j] << " ";
			}
			fout << endl;
			//cout << endl;
		}
	}
	else
	{
		fout << "Path Not Found...." << endl;
		//cout << "Not Found" << endl;
	}
	//obj.display();
	fout.close();
	delete visited;
	delete maze;
	return 0;
}
