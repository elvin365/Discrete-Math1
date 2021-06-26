#include "MatrixG1.h"
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include<cmath>
#include<queue>
void Matrix::AddVertexOr(vector<vector<int>>&SP3)
{
	/*for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");


	vector<int> In;
	vector<int> Out;
	cout << "Enter incoming vertexes" << endl;
	int temp;

	while (cin >> temp) //enter any non-integer to end the loop!
	{
		In.push_back(temp);
	}
	cout << "Enter outgoing vertexes,if loop then add 0" << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	while (cin >> temp) //enter any non-integer to end the loop!
	{
		Out.push_back(temp);
	}
	int new_num_of_vertex = SP3[SP3.size() - 1][0] + 1;

	bool exists = std::find(std::begin(Out), std::end(Out), 0) != std::end(Out);

	if (exists == 1)
	{
		for (int i = 0; i < Out.size(); i++)
		{
			if (Out[i] == 0)
			{
				Out[i] = new_num_of_vertex;
			}
		}
	}
	Out.insert(Out.begin(), new_num_of_vertex);
	SP3.insert(SP3.end(), Out);
	for (int i = 0; i < SP3.size()-1; i++)
	{
		if (std::find(std::begin(In), std::end(In), SP3[i][0]) != std::end(In))
		{
			SP3[i].push_back(new_num_of_vertex);
		}
	}

	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}*/
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j] << " ";
		}
		printf("\n");
	}
	printf("\n");

	vector<int> num_of_vertexes;
	cout << "Enter vertexes,if loop then add 0" << endl;
	int temp;

	while (cin >> temp) //enter any non-integer to end the loop!
	{
		num_of_vertexes.push_back(temp);
	}
	int new_num_of_vertex = SP3[SP3.size() - 1][0] + 1;

	bool exists = std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), 0) != std::end(num_of_vertexes);

	if (exists == 1)
	{
		for (int i = 0; i < num_of_vertexes.size(); i++)
		{
			if (num_of_vertexes[i] == 0)
			{
				num_of_vertexes[i] = new_num_of_vertex;
			}
		}
	}
	//num_of_vertexes.insert(num_of_vertexes.begin(), new_num_of_vertex);

	for (int i = 0; i < SP3.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), SP3[i][0]) != std::end(num_of_vertexes))
		{
			SP3[i].push_back(new_num_of_vertex);
		}
	}
	SP3.insert(SP3.end(), num_of_vertexes);

	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j];
		}
		printf("\n");
	}

}

void Matrix::DeleteVertexOr(vector<vector<int>>& SP3)
{
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	cout << "Enter the number of vetex to delete" << endl;

	int temp = 0;
	cin >> temp;


	for (int i = 1; i < SP3.size(); i++)
	{
		if (SP3[i][0] == temp)
		{
			SP3.erase(SP3.begin() + i);
			--i;
		}
		for (int j = 0; j < SP3[i].size(); j++)
		{
			if (SP3[i][j] == temp)
			{
				
				SP3[i].erase(std::remove(SP3[i].begin(), SP3[i].end(), temp), SP3[i].end());
			}
		}
	}
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}

}

void Matrix::AddEdgeOr(vector<vector<int>>& SP3)
{
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");


	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;

	for (int i = 0; i < SP3.size(); i++)
	{
		if (SP3[i][0] == temp)
		{
			if (temp != temp1)
				SP3[i].push_back(temp1);
		}

		

	}
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::DeleteEdgeOr(vector<vector<int>>& SP3)
{
	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;

	for (int i = 0; i < SP3.size(); i++)
	{
		if (SP3[i][0] == temp)
		{
			SP3[i].erase(std::remove(SP3[i].begin(), SP3[i].end(), temp1), SP3[i].end());
			if (temp == temp1)
			{
				SP3[i].insert(SP3[i].begin(), temp);
			}
		}

	}

	for (int i = 0; i < SP3.size(); i++)
	{
		for (int j = 0; j < SP3[i].size(); j++)
		{
			cout << SP3[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::DecomposeEdgeOr(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	cout << "Enter the numbers of 2 vertexes to create new:";
	int temp, temp1;
	cin >> temp >> temp1;
	vector<int> num_of_vertexes;
	num_of_vertexes.push_back(temp);
	num_of_vertexes.push_back(temp1);
	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			if (temp == temp1)
			{

				SP[i].insert(SP[i].begin(), temp);
			}
			SP[i].insert(SP[i].end(), new_num_of_vertex);
		}

	}
	num_of_vertexes.erase(num_of_vertexes.begin());
	num_of_vertexes.insert(num_of_vertexes.begin(), new_num_of_vertex);
	
	SP.insert(SP.end(), num_of_vertexes);
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::IdentificationOr(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	vector <int> V1;//исходяще из 1 и/или второй вершины 
	vector <int> V2;//входящие в 1 и/или 2 вершину
	//vector <int> V;//V=V1+V2/V1 вершины где соединены первая и вторая 
	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;
	int N1, N2 = 0;//номера строчек
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			N1 = i;

		}
		if (SP[i][0] == temp1)
		{
			N2 = i;

		}
	}
	V1 = SP[N1];
	V1.erase(V1.begin());
	
	
	for (int i = 1; i < SP[N2].size(); i++)
	{
		if (!(std::find(std::begin(V1), std::end(V1), SP[N2][i]) != std::end(V1)))
		{
			V1.push_back(SP[N2][i]);//создание списка исходящих из temp,temp1
		}

	}
	//V2 = G1_SP[N2];
	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp) != std::end(SP[i]))
		{
			if (SP[i][0]!=temp)
			{
				V2.push_back(SP[i][0]);
			}
			
		}
	}
	V1.erase(std::remove(V1.begin(), V1.end(), temp), V1.end());//v1/temp
	V1.erase(std::remove(V1.begin(), V1.end(), temp1), V1.end());//v1/temp


	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp1) != std::end(SP[i]))
		{
			if (SP[i][0] != temp1)
			{
				if (!(std::find(std::begin(V2), std::end(V2), SP[i][0]) != std::end(V2)))
				{
					V2.push_back(SP[i][0]);
				}
			}
		}
	}

	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			SP.erase(SP.begin() + i);
			--i;
		}
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (SP[i][j] == temp)
			{

				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			}
		}
	}
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp1)
		{
			SP.erase(SP.begin() + i);
			--i;
		}
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (SP[i][j] == temp1)
			{

				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			}
		}
	}

	vector<int> In;
	vector<int> Out;

	
	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;

	In = V2;
	Out = V1;
	Out.insert(Out.begin(), new_num_of_vertex);
	SP.insert(SP.end(), Out);
	for (int i = 0; i < SP.size() - 1; i++)
	{
		if (std::find(std::begin(In), std::end(In), SP[i][0]) != std::end(In))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}

	

	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::IdentificationOrVertex(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j] << " ";
		}
		printf("\n");
	}
	printf("\n");
	bool ifexist = 0;//было ли ребро
	vector <int> V1;//исходяще из 1 и/или второй вершины 
	vector <int> V2;//входящие в 1 и/или 2 вершину
	//vector <int> V;//V=V1+V2/V1 вершины где соединены первая и вторая 
	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;
	int N1, N2 = 0;//номера строчек
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			N1 = i;

		}
		if (SP[i][0] == temp1)
		{
			N2 = i;

		}
	}
	ifexist = (std::find(std::begin(SP[N1]), std::end(SP[N1]), temp1) != std::end(SP[N1]) || std::find(std::begin(SP[N2]), std::end(SP[N2]), temp) != std::end(SP[N2]));
	V1 = SP[N1];
	V1.erase(V1.begin());


	for (int i = 1; i < SP[N2].size(); i++)
	{
		if (!(std::find(std::begin(V1), std::end(V1), SP[N2][i]) != std::end(V1)))
		{
			V1.push_back(SP[N2][i]);//создание списка исходящих из temp,temp1
		}

	}
	//V2 = G1_SP[N2];
	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp) != std::end(SP[i]))
		{
			if (SP[i][0] != temp)
			{
				V2.push_back(SP[i][0]);
			}

		}
	}
	V1.erase(std::remove(V1.begin(), V1.end(), temp), V1.end());//v1/temp
	V1.erase(std::remove(V1.begin(), V1.end(), temp1), V1.end());//v1/temp


	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp1) != std::end(SP[i]))
		{
			if (SP[i][0] != temp1)
			{
				if (!(std::find(std::begin(V2), std::end(V2), SP[i][0]) != std::end(V2)))
				{
					V2.push_back(SP[i][0]);
				}
			}
		}
	}

	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			SP.erase(SP.begin() + i);
			--i;
		}
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (SP[i][j] == temp)
			{

				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			}
		}
	}
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp1)
		{
			SP.erase(SP.begin() + i);
			--i;
		}
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (SP[i][j] == temp1)
			{

				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			}
		}
	}

	vector<int> In;
	vector<int> Out;


	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;

	In = V2;
	Out = V1;
	Out.insert(Out.begin(), new_num_of_vertex);
	SP.insert(SP.end(), Out);
	for (int i = 0; i < SP.size() - 1; i++)
	{
		if (std::find(std::begin(In), std::end(In), SP[i][0]) != std::end(In))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}
	if (ifexist)
	{
		SP[SP.size() - 1].push_back(new_num_of_vertex);
	}


	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j] << " ";
		}
		printf("\n");
	}
}

void Matrix::DuplicateVertexOr(vector<vector<int>>& SP)
{

	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;
	int temp;
	cin >> temp;//ввод вершины на будликацию
	int N = 0;
	for (int j = 0; j< SP.size(); j++)
	{
		if (SP[j][0] == temp)
		{
			N = j;
		}//номер строчки.с котор начин
	}
	vector<int> row = SP[N];
	row.erase(row.begin());//старый нулевой элемент на удаление
	row.insert(row.begin(), new_num_of_vertex);
	for (int i = 0; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp) != std::end(SP[i]))
		{
			if (i != N)
			{
				SP[i].push_back(new_num_of_vertex);
			}
		}
	}
	SP.insert(SP.end(), row);

	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}

}

void Matrix::BreedingVertexOr(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;
	int temp;
	cin >> temp;//ввод вершины на будликацию
	int N = 0;
	for (int j = 0; j < SP.size(); j++)
	{
		if (SP[j][0] == temp)
		{
			N = j;
		}//номер строчки.с котор начин
	}
	vector<int> row = SP[N];
	row.erase(row.begin());//старый нулевой элемент на удаление
	row.insert(row.begin(), new_num_of_vertex);
	for (int i = 0; i < SP.size(); i++)
	{
		if (std::find(std::begin(SP[i]), std::end(SP[i]), temp) != std::end(SP[i]))
		{
			if (i != N)
			{
				SP[i].push_back(new_num_of_vertex);
			}
		}
	}
	SP.insert(SP.end(), row);
	
	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			if (temp != new_num_of_vertex)
				SP[i].push_back(new_num_of_vertex);
		}
	}

	/*for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == new_num_of_vertex)
		{
			if (new_num_of_vertex != temp)
				SP[i].push_back(temp);
		}
	}*/
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::DisjunctionOr(vector<vector<int>>& SP)
{


	for (int i = 0; i < SP.size(); i++)//G3
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	vector<vector<int>> G_Or{ {0} ,{1,2,3},{2,3},{3} };//орграфа для двуместныех операций
	for (int i = 0; i < G_Or.size(); i++)//G_or
	{
		for (int j = 0; j < G_Or[i].size(); j++)
		{
			cout << G_Or[i][j];
		}
		printf("\n");
	}
	printf("\n");

	vector<vector<int>> G_new;
	G_new = SP;
	vector<int> buf;
	int max1 = SP[SP.size() - 1][0];
	for (int i = 1; i < G_Or.size(); i++)
	{
		buf = G_Or[i];
		for (int j = 0; j < buf.size(); j++)
		{
			buf[j] = max1 + buf[j];
		}
		//	G1_SP.insert(G1_SP.end(), num_of_vertexes);
		G_new.insert(G_new.end(), buf);
	}
	for (int i = 0; i < G_new.size(); i++)
	{
		for (int j = 0; j < G_new[i].size(); j++)
		{
			cout << G_new[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::SoedinenieOr(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");

	vector<vector<int>> G_Or{ {0}, {3,4,5},{4,5},{5} };//орграфа для двуместныех операций
	for (int i = 0; i < G_Or.size(); i++)
	{
		for (int j = 0; j < G_Or[i].size(); j++)
		{
			cout << G_Or[i][j]<<" ";
		}
		printf("\n");
	}
	vector<vector<int>> G_new;
	//G_new = SP;
	vector<int> V;
	bool exists;
	//множество совпадающих вершин
	for (int i = 1; i < SP.size(); i++)
	{
		for (int j = 1; j < G_Or.size(); j++)
		{
			if (SP[i][0] == G_Or[j][0])
			{
				V.push_back(SP[i][0]);
			}
		}
	}
	G_new = SP;
	for (int i = 1; i < G_Or.size(); i++)
	{
		//for (int j = 1; j < G1_SP.size(); j++)
		exists = std::find(std::begin(V), std::end(V), G_Or[i][0]) != std::end(V);//проверка вершина G2 есть в G1 или нет , елси лежит в V - есть в G1
		if (exists)
		{
			for (int j = 1; j < SP.size(); j++)
			{
				if (G_Or[i][0] == SP[j][0])
				{
					for (int k = 1; k < G_Or[i].size(); k++)
					{
						bool exists1 = std::find(std::begin(SP[j]), std::end(SP[j]), G_Or[i][k]) != std::end(SP[j]);//содержится ли элемент G2 в G1
						if (exists1 == 0)
						{
							G_new[i].push_back(G_Or[i][k]);
						}

					}
				}
			}

		}
		else
		{
			G_new.insert(G_new.end(), G_Or[i]);
		}

	}


	/*vector<int>V1, V2;
	for (int i = 1; i < G3_SP.size(); i++)
	{

		if (!(std::find(std::begin(V), std::end(V), G3_SP[i][0]) != std::end(V)))
		{
			V1.push_back(G3_SP[i][0]);//создадим список вершин , входящих в G1,но не входящих в G2
		}

	}
	for (int i = 1; i < G_Or.size(); i++)
	{

		if (!(std::find(std::begin(V), std::end(V), G_Or[i][0]) != std::end(V)))
		{
			V2.push_back(G_Or[i][0]);//создадим список вершин , входящих в G2,но не входящих в G1
		}

	}
	for (int i = 0; i < V1.size(); i++)
	{
		for (int j = 0; j < V2.size(); j++)
		{
			for (int i = 0; i < G_new.size(); i++)
			{
				if (G_new[i][0] == V1[i])
				{
					if (V1[i] != V2[j])
						G_new[i].push_back(V2[j]);
				}

				if (G_new[i][0] == V2[j])
				{

					G_new[i].push_back(V1[i]);

				}

			}

		}
	}*/


	for (int i = 1; i < SP.size(); i++)
	{
		if (!(std::find(std::begin(V), std::end(V), G_new[i][0]) != std::end(V)))
		{
			for (int j = 1; j < G_Or.size(); j++)
			{
				
				if (!(std::find(std::begin(G_new[i]), std::end(G_new[i]), G_Or[j][0]) != std::end(G_new[i])))
				{
					G_new[i].push_back(G_Or[j][0]);
				}
			}
		}

	}
	//теперь в обратную сторону
	for (int i = SP.size(); i < G_new.size(); i++)
	{
		if (!(std::find(std::begin(V), std::end(V), G_new[i][0]) != std::end(V)))
		{
			for (int j = 1; j < SP.size(); j++)
			{

				if (!(std::find(std::begin(G_new[i]), std::end(G_new[i]), SP[j][0]) != std::end(G_new[i])))
				{
					G_new[i].push_back(SP[j][0]);
				}
			}
		}

	}

	for (int i1 = 0; i1 < V.size(); i1++)//
	{
		int N1, N2 = 0;//номера строчек
		for (int i = 1; i < SP.size(); i++)
		{
			if (SP[i][0] == V[i1])
			{
				N1 = i;

			}
			
		}
		for (int i = 1; i < G_Or.size(); i++)
		{
			if (G_Or[i][0] == V[i1])
			{
				N2 = i;

			}

		}
		for (int i = 1; i < G_Or[N2].size(); i++)
		{
			if (!(std::find(std::begin(G_new[N1]), std::end(G_new[N1]), G_Or[N2][i]) != std::end(G_new[N1])))
			{
				G_new[N1].push_back(G_Or[N2][i]);
			}
		}
	}


	for (int i = 0; i < G_new.size(); i++)
	{
		for (int j = 0; j < G_new[i].size(); j++)
		{
			cout << G_new[i][j]<<" ";
		}
		printf("\n");
	}

}

void Matrix::DecProductOr(vector<vector<int>>& SP)
{
	//for (int i = 0; i < G3_SP.size(); i++)
	//{
	//	for (int j = 0; j < G3_SP[i].size(); j++)
	//	{
	//		cout << G3_SP[i][j]<<" ";
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//vector<vector<int>> G_Or{ {0}, {1,2,3},{2,3},{3} };//орграфа для двуместныех операций

	//vector<vector<int>> G2_new = G_Or;
	//int max1 = G3_SP[G3_SP.size() - 1][0];
	//for (int i = 1; i < G2_new.size(); i++)
	//{
	//	for (int j = 0; j < G2_new[i].size(); j++)
	//	{
	//		G2_new[i][j] = max1 + G2_new[i][j];
	//	}
	//}
	//for (int i = 0; i < G2_new.size(); i++)
	//{
	//	for (int j = 0; j < G2_new[i].size(); j++)
	//	{
	//		cout << G2_new[i][j];
	//	}
	//	printf("\n");
	//}
	//vector<vector<int>> G_D;
	//G_D.resize((G3_SP.size() - 1)*(G2_new.size() - 1) + 1);
	//for (int i = 0; i < G_D.size(); i++)
	//{
	//	G_D[i].push_back(i);
	//}

	//int M = G3_SP.size();
	//int N = G2_new.size();
	//for (int i = 1; i < M; i++) // номр сторки
	//{
	//	for (int j = 1; j < N; j++)//номр столбец
	//	{
	//		for (int k = j; k < N; k++)//
	//		{
	//			if (std::find(std::begin(G2_new[j]), std::end(G2_new[j]), G2_new[k][0]) != std::end(G2_new[j]))
	//			{
	//				for (int i1 = 0; i1 < G_D.size(); i1++)
	//				{
	//					if (G_D[i1][0] == Index(i, j, N - 1))
	//					{
	//						if (Index(i, j, N - 1) != Index(i, k, N - 1))
	//							G_D[i1].push_back(Index(i, k, N - 1));
	//					}

	//					/*if (G_D[i1][0] == Index(i, k, N - 1))
	//					{

	//						G_D[i1].push_back(Index(i, j, N - 1));

	//					}*/

	//				}
	//			}


	//		}
	//	}
	//}
	//for (int i = 1; i < N; i++) // номр столца
	//{
	//	for (int j = 1; j < M; j++)//номр строки
	//	{
	//		for (int k = j; k < M; k++)//
	//		{
	//			if (std::find(std::begin(G3_SP[j]), std::end(G3_SP[j]), G3_SP[k][0]) != std::end(G3_SP[j]))
	//			{
	//				for (int i1 = 0; i1 < G_D.size(); i1++)
	//				{
	//					if (G_D[i1][0] == Index(j, i, N - 1))
	//					{
	//						if (Index(j, i, N - 1) != Index(k, i, N - 1))
	//							G_D[i1].push_back(Index(k, i, N - 1));
	//					}

	//					/*if (G_D[i1][0] == Index(j, k, N - 1))
	//					{

	//						G_D[i1].push_back(Index(j, i, N - 1));

	//					}*/

	//				}
	//			}


	//		}
	//	}
	//}
	//for (int i = 0; i < G_D.size(); i++)
	//{
	//	for (int j = 0; j < G_D[i].size(); j++)
	//	{
	//		cout << G_D[i][j] << ",";
	//	}
	//	printf("\n");
	//}
	
for (int i = 0; i < SP.size(); i++)
{
	for (int j = 0; j < SP[i].size(); j++)
	{
		cout << SP[i][j] << " ";
	}
	printf("\n");
}
vector<vector<int>> G2_new{ {0}, {1,2},{2} };
int max1 = SP[SP.size() - 1][0];
for (int i = 1; i < G2_new.size(); i++)
{
	for (int j = 0; j < G2_new[i].size(); j++)
	{
		G2_new[i][j] = max1 + G2_new[i][j];
	}
}
vector<pair<int, int>> lin_dec;
vector<vector<pair<int, int>>> Result;
pair<int, int> temp;
int move = 0;
for (int i = 1; i <= SP.size() - 1; i++)
{
	for (int j = 1; j <= G2_new.size() - 1; j++)
	{
		temp.first = i;
		temp.second = G2_new[j][0];//j+max1;
		lin_dec.push_back(temp);
	}

}
Result.resize(lin_dec.size());
for (int i = 0; i < Result.size(); i++)
{
	Result[i].push_back(lin_dec[i]);
}
for (int i = 0; i < lin_dec.size(); i++)
{
	for (int j = 0; j < lin_dec.size(); j++)
	{
		if (lin_dec[i] == lin_dec[j])
		{
			continue;
		}
		if (lin_dec[i].first == lin_dec[j].first)
		{
			bool exists = std::find(std::begin(G2_new[lin_dec[i].second - max1]), std::end(G2_new[lin_dec[i].second - max1]), lin_dec[j].second) != std::end(G2_new[lin_dec[i].second - max1]);
			if (exists)
			{
				Result[i].push_back(lin_dec[j]);
			}
		}
		if (lin_dec[i].second == lin_dec[j].second)
		{
			bool exists = std::find(std::begin(SP[lin_dec[i].first]), std::end(SP[lin_dec[i].first]), lin_dec[j].first) != std::end(SP[lin_dec[i].first]);
			if (exists)
			{
				Result[i].push_back(lin_dec[j]);
			}

		}
	}
}
printf("\n");
for (int i = 0; i < Result.size(); i++)
{
	for (int j = 0; j < Result[i].size(); j++)
	{
		cout << Result[i][j].first << Result[i][j].second << ";";
	}
	printf("\n");
}

	
}

void Matrix::AmountEdgesInOr()
{
	cout << G3[1].size();
}



