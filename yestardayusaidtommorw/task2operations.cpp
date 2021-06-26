#include"MatrixG1.h"
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include<queue>
void Matrix::TaskAddVertex(vector<vector<int>>&G, int v1)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}

	cout << "\n";
	vector<int> num_of_vertexes;
	//cout << "Enter vertexes,if loop then add 0" << endl;
	//int temp;

	//while (cin >> temp) //enter any non-integer to end the loop!
	//{
	num_of_vertexes.push_back(v1);
	//}
	int new_num_of_vertex = G[G.size() - 1][0] + 1;

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

	for (int i = 0; i < G.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), G[i][0]) != std::end(num_of_vertexes))
		{
			G[i].push_back(new_num_of_vertex);
		}
	}
	G.insert(G.end(), num_of_vertexes);

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}

	FromSPtoAdjacencyNonOrient(G, G1);
	GetMatrixIncidence(G1, G1_I);
}

void Matrix::TaskDeleteVertex(vector<vector<int>>& G, int v3)
{
	
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j] << " ";
		}
		printf("\n");
	}
	printf("\n");

	int temp = v3;
	


	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			G.erase(G.begin() + i);
			--i;//возвращаю итерацию в норм русло 
		}
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] == temp)
			{
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				G[i].erase(std::remove(G[i].begin(), G[i].end(), temp), G[i].end());
			}
		}
	}
	printf("\n");

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j] << " ";
		}
		printf("\n");
	}

	FromSPtoAdjacencyNonOrient(G, G1);
	GetMatrixIncidence(G1, G1_I);
}

void Matrix::TaskDeleteEdge(vector<vector<int>>& G, pair<int, int> edge)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	cout << "\n";
	//cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	temp = edge.first;
	temp1 = edge.second;
	//cin >> temp >> temp1;

	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			G[i].erase(std::remove(G[i].begin(), G[i].end(), temp1), G[i].end());
			if (temp == temp1)
			{
				G[i].insert(G[i].begin(), temp);
			}
		}

		if (G[i][0] == temp1)
		{
			G[i].erase(std::remove(G[i].begin(), G[i].end(), temp), G[i].end());
			if (temp == temp1)
			{
				G[i].insert(G[i].begin(), temp);
			}
		}

	}

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	FromSPtoAdjacencyNonOrient(G, G1);
	GetMatrixIncidence(G1, G1_I);
}

void Matrix::TaskAddEdge(vector<vector<int>>& G, pair<int, int> edge)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	
	//cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	temp = edge.first;
	temp1 = edge.second;
	//cin >> temp >> temp1;

	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			if (temp != temp1)
				G[i].push_back(temp1);
		}

		if (G[i][0] == temp1)
		{

			G[i].push_back(temp);

		}

	}

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	FromSPtoAdjacencyNonOrient(G, G1);
	GetMatrixIncidence(G1, G1_I);
}

void Matrix::TaskComplement(vector<vector<int>>& G)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	cout << "\n";
	vector <int> V;
	vector <int> V1;

	for (int i = 1; i < G.size(); i++)
	{
		V.push_back(G[i][0]);//массив вершин для проверки со строчками 
	}
	V1 = V;
	for (int i = 1; i < G.size(); i++)//удалаяем из каждой строчки значения , входящие в V и добавляем невходящие
	{
		V1 = V;
		for (int j = 0; j < G[i].size(); j++)
		{
			V1.erase(std::remove(V1.begin(), V1.end(), G[i][j]), V1.end());

		}
		V1.insert(V1.begin(), G[i][0]);
		G[i] = V1;

	}
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	FromSPtoAdjacencyNonOrient(G, G4);
	GetMatrixIncidence(G4, G1_I);
}

void Matrix::TaskAddVertexOr(vector<vector<int>>&G,int v1)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j] << " ";
		}
		printf("\n");
	}

	cout << "\n";
	vector<int> num_of_vertexes;
	//cout << "Enter vertexes,if loop then add 0" << endl;
	//int temp;

	//while (cin >> temp) //enter any non-integer to end the loop!
	//{
	num_of_vertexes.push_back(v1);
	//}
	int new_num_of_vertex = G[G.size() - 1][0] + 1;

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

	for (int i = 0; i < G.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), G[i][0]) != std::end(num_of_vertexes))
		{
			G[i].push_back(new_num_of_vertex);
		}
	}
	G.insert(G.end(), num_of_vertexes);

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j] << " ";
		}
		printf("\n");
	}

	//FromSPtoAdjacencyNonOrient(G, G1);
	//GetMatrixIncidence(G1, G1_I);
}

void Matrix::TaskDeleteVertexOr(vector<vector<int>>& G, int v1)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	cout << "\n";
	//cout << "Enter the number of vetex to delete" << endl;

	int temp = v1;
	//cin >> temp;


	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			G.erase(G.begin() + i);
			--i;
		}
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] == temp)
			{

				G[i].erase(std::remove(G[i].begin(), G[i].end(), temp), G[i].end());
			}
		}
	}
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::TaskAddEdgeOr(vector<vector<int>>&G, pair<int, int> f)
{
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j];
		}
		printf("\n");
	}


	//cout << "Enter the numbers of 2 vertexes:";
	int temp=f.first, temp1=f.second;
	//cin >> temp >> temp1;

	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			if (temp != temp1)
				G[i].push_back(temp1);
		}



	}
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j];
		}
		printf("\n");
	}
}

void Matrix::TaskDeleteEdgeOr(vector<vector<int>>&G, pair<int, int> f)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	cout << "\n";
	//cout << "Enter the numbers of 2 vertexes:";
	int temp=f.first, temp1=f.second;
	//cin >> temp >> temp1;

	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			G[i].erase(std::remove(G[i].begin(), G[i].end(), temp1), G[i].end());
			if (temp == temp1)
			{
				G[i].insert(G[i].begin(), temp);
			}
		}

	}

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::TaskIdentification(vector<vector<int>>&G, pair<int, int> v)
{
	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
	cout << "\n";

	vector <int> V1;//первая вершина
	vector <int> V2;//вторая вершина
	vector <int> V;//V=V1+V2/V1 вершины где соединены первая и вторая 
	//cout << "Enter the numbers of 2 vertexes:";
	int temp=v.first, temp1=v.second;
	//cin >> temp >> temp1;
	int N1=0, N2 = 0;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp)
		{
			N1 = i;

		}
		if (G[i][0] == temp1)
		{
			N2 = i;

		}
	}
	V1 = G[N1];
	V2 = G[N2];
	for (int i = 0; i < V1.size(); i++)
	{
		if (std::find(std::begin(V2), std::end(V2), V1[i]) != std::end(V2))
		{
			V2.erase(std::remove(V2.begin(), V2.end(), V1[i]), V2.end());//v2/v1
		}

	}

	V2.erase(std::remove(V2.begin(), V2.end(), temp), V2.end());//v2/v1
	V2.erase(std::remove(V2.begin(), V2.end(), temp1), V2.end());//v2/v1
	V1.erase(std::remove(V1.begin(), V1.end(), temp), V1.end());//v2/v1
	V1.erase(std::remove(V1.begin(), V1.end(), temp1), V1.end());//v2/v1
	V = V1;
	for (int i = 0; i < V2.size(); i++)
	{
		V.push_back(V2[i]);
	}

	for (int i = 0; i < G.size(); i++)//удаляем вершину temp
	{
		if (G[i][0] == temp)
		{
			G.erase(G.begin() + i);
			--i;
		}
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] == temp)
			{
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				G[i].erase(std::remove(G[i].begin(), G[i].end(), temp), G[i].end());
			}
		}
	}
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i][0] == temp1)
		{
			G.erase(G.begin() + i);
			--i;
		}
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] == temp1)
			{
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				G[i].erase(std::remove(G[i].begin(), G[i].end(), temp1), G[i].end());
			}
		}
	}

	vector<int> num_of_vertexes;

	num_of_vertexes = V;

	int new_num_of_vertex = G[G.size() - 1][0] + 1;

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
	num_of_vertexes.insert(num_of_vertexes.begin(), new_num_of_vertex);

	for (int i = 0; i < G.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), G[i][0]) != std::end(num_of_vertexes))
		{
			G[i].push_back(new_num_of_vertex);
		}
	}
	G.insert(G.end(), num_of_vertexes);

	for (int i = 1; i < G.size(); i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j]<<" ";
		}
		printf("\n");
	}
}

void Matrix::TaskDisjunktion(vector<vector<int>>&G4, vector<vector<int>>&G2)
{

	for (int i = 1; i < G4.size(); i++)
	{
		for (int j = 0; j < G4[i].size(); j++)
		{
			cout << G4[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i < G2.size(); i++)
	{
		for (int j = 0; j < G2[i].size(); j++)
		{
			cout << G2[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");
	//vector<vector<int>> G_new;
	G_new = G4;
	vector<int> buf;
	int max1 = G4[G4.size() - 1][0];
	for (int i = 1; i < G2.size(); i++)
	{
		buf = G2[i];
		for (int j = 0; j < buf.size(); j++)
		{
			buf[j] = max1 + buf[j];
		}
		//	G1_SP.insert(G1_SP.end(), num_of_vertexes);
		G_new.insert(G_new.end(), buf);
	}
	for (int i = 1; i < G_new.size(); i++)
	{
		for (int j = 0; j < G_new[i].size(); j++)
		{
			cout << G_new[i][j]<<" ";
		}
		printf("\n");
	}
}

 
void Matrix::TaskEx(vector<vector<int>>& G_new_A)
{
	int size = G_new_A.size();
	int start, end;

	/*vector<int> from(size, -1);
	vector<int> used(size, 0);
	vector<int> dist(size);*/
	vector<int> v;
	//int mainMatrix[SIZE][SIZE];
	int tmp = G_new_A.size();
	int* way = new int[tmp];
	//int way[G1.size()];
	int counter = 0;

	//cin >> start >> end;
	//--start; --end;
	for (start = 0; start < G_new_A.size(); start++)
	{
		for (end = 0; end < G_new_A.size(); end++)
		{
			vector<int> from(size, -1);
			vector<int> used(size, 0);
			vector<int> dist(size);
			queue<int> Queue;
			Queue.push(start);

			dist[start] = 0;
			used[start] = 1;

			while (!Queue.empty())
			{
				int hold = Queue.front();
				Queue.pop();

				for (int i = 0; i < size; ++i)
				{
					if (G_new_A[hold][i] && !used[i])
					{
						dist[i] = dist[hold] + 1;
						from[i] = hold;
						Queue.push(i);
						used[i] = true;
					}
				}

			}
			if (used[end])
				//cout << dist[end];
			{
				v.push_back(dist[end]);
			}
			else
				;//cout << -1;
		}
		//G_Dist[start] = v;//создаём матрицу расстояний
		G_Dist.resize(start + 1);
		G_Dist[start] = v;
		v.clear();

	}
	cout << "The destination table"<<endl;
	for (int i = 0; i < G_Dist.size(); i++)
	{
		for (int j = 0; j < G_Dist[i].size(); j++)
		{
			cout << G_Dist[i][j]<<" ";
		}
		printf("\n");
	}
	vector <int> ex;

	for (int i = 0; i < G_Dist.size(); i++)
	{
		int mx = 0;
		//ex.push_back(*max_element(G_Dist[i].begin(), G_Dist[i].end()));
		for (int j = 0; j < G_Dist[i].size(); j++)
		{
			if (G_Dist[i][j] > G_Dist[i][mx])
			{
				mx = j;
			}
		}
		ex.push_back(G_Dist[i][mx]);

	}
	//cout << "R=" << *min_element(ex.begin(), ex.end());//min ex
	int mx = 0;
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[i] < ex[mx])
		{
			mx = i;
		}
	}
	cout << "R=" << ex[mx] << endl;
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[mx] == ex[i])
		{
			cout << "Central vertexes are: " << i << endl;
		}
	}
	mx = 0;
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[i] > ex[mx])
		{
			mx = i;//max
		}
	}
	cout << "D=" << ex[mx] << endl;
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[i] == ex[mx])
		{
			cout << "Perepheril vertexes are: " << i << endl;
		}
	}
	for (int i = 0; i < G_new_A.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < G_new_A[i].size(); j++)
		{
			sum = sum + G_new_A[i][j];
		}
		if (sum == 0)
		{
			cout << i << " is isolaited vertex" << endl;
		}
		else if (sum == 1)
		{
			cout << i << " is hanging vertex" << endl;
		}
	}
}
