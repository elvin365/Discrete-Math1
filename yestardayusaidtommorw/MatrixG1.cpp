#include "MatrixG1.h"
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include<cmath>
#include<queue>
Matrix::Matrix()
{
	
	string str;
	char* forstr;
	bool checked = 0;
	//ifstream myfile("C:\\Users\\Elvin\\source\\repos\\yestardayusaidtommorw\\yestardayusaidtommorw\\G1.txt");
	//ifstream myfile("C:\\Users\\Elvin\\source\\repos\\yestardayusaidtommorwthird\\yestardayusaidtommorw\\G1.txt");
	ifstream myfile ("C:\\Users\\Elvin\\source\\repos\\yestardayusaidtommorwfourth\\yestardayusaidtommorw\\G1.txt");
	if (myfile.is_open())
	{
		int j = 0;
		while (getline(myfile, str, '\n'))
		{
			if (strstr(str.c_str(), "{"))
			{
				//rewind(ifstream);
				myfile.clear();
				myfile.seekg(0);
				WriteInSP(myfile);
				FromSPtoAdjacencyNonOrient(G1_SP, G1);
				GetMatrixIncidence(G1, G1_I);
				//break;
				goto read_futher;
			}
			if (checked == 0 && IfIncidence(myfile, checked, str))
			{
				GetMatrixAdjacency(G1_I, G1);
				MakeSPAdjacency(G1, G1_SP);
				break;
			}
			if (str != "\0")
			{
				G1.resize(str.length());
				G1[j].resize(str.length());
				for (int i = 0; i < str.length(); i++)
				{
					//G1[j][i] = str[i]-48;//Magic
					G1[j][i] = str[i] - 48;
				}
				j++;
			}
		}
		GetMatrixIncidence(G1, G1_I);
		MakeSPAdjacency(G1, G1_SP);
	}
	read_futher:
	myfile.close();
		forstr = nullptr;
		ifstream myfile1("C:\\Users\\Elvin\\source\\repos\\yestardayusaidtommorwfourth\\yestardayusaidtommorw\\G2.txt");
		if (myfile1.is_open())
		{
			int j = 0;
			size_t k = 1;
			while (getline(myfile1, str, '\n'))
			{
				G2.resize(k);
				G2[j].resize(str.length());
				for (int i = 0; i < str.length(); i++)
				{
					//G1[j][i] = str[i]-48;//Magic
					G2[j][i] = str[i] - 48;
				}
				j++;
				++k;
			}
		}
		GetMatrixAdjacency(G2, G2_A);
		MakeSPAdjacency(G2_A, G2_SP);
		myfile1.close();
		forstr = nullptr;
		ifstream myfile2("C:\\Users\\Elvin\\source\\repos\\yestardayusaidtommorwfourth\\yestardayusaidtommorw\\G3.txt");
		if (myfile2.is_open())
		{
			int j = 0;
			int i1 = 0;
			size_t k = 1;
			while (getline(myfile2, str, '\n'))
			{
				G3.resize(k);
				//G3[j].resize(str.length());
				for (int i = 0; i < str.length(); i++)
				{
					if (str[i] == '-')
					{
						//G3[j][i1] = -1;
						//i1++;
						G3[j].push_back(-1);
						i = i + 1;
					}
					else
					{
						//G3[j][i1] = str[i] - 48;
						G3[j].push_back(str[i] - 48);
						//i1++;
					}
					 
				}
				j++;
				++k;
			}
		}
		GetMatrixAdjacencyG3();
		MakeSPAdjacencyG3();
		myfile2.close();

	

}




Matrix::~Matrix()
{
}

const void Matrix::GetAmountVertex() const
{
	//берем длину строки у матриц инцидентности  и длину чего угодно мат. смежности
	cout << "The Amount of vertexes in G1 is "<< G1[1].size()<< endl;
	cout << "The Amount of vertexes in G2 is " << G2_A[1].size() << endl;
	cout << "The Amount of vertexes in G3 is " << G3_A[1].size() << endl;
}

int Matrix::GetAmountEdge(vector<vector<int>> G_any) const
{
	//сумма степеней вершин/2=число ребер , лемма того чувака
	int max = 0;
	for (int i = 0; i < G_any.size(); i++)
	{
		for (int j = 0; j < G_any[1].size(); j++)
		{
			max = max + G_any[i][j];
		}
	}
	cout <<"The amount of edges is "<<max/2 << endl;
	return max / 2;
}

void Matrix::GetMatrixIncidence(vector<vector<int>>& G_A_any, vector<vector<int>>&G_I)
{
	int a_vertex = G_A_any[0].size();//кол-во вершин для из матрицы смежности для мат инцидентности 
	int a_edges = GetAmountEdge(G_A_any);//возвращаем значение о кол-ве ребер матрицы инцидентности
	//int* Pair = new int[a_vertex];// это вершины матрицы инцидентности , чтобы не рассматривать повторы буду ставить 1и0, изанчально нули
	//memset(Pair, 0, a_vertex * sizeof(int));

	//ходим по матрице смежности и ищем 1 или 2
	//2- значит в графе два ребра , соединяющих две вершины
	//1 -значит в графе одно ребро ,соединяющие 2 вершины
	// 2 и i==j , тогда одно ребро и оно - петля

	// кол-во строк - это кол-во вершин ,то есть а вертекс
	//vector<vector<int>> G1_I;// матрица инцидентности
	G_I.resize(a_vertex);//столько строк(вершины)
	for (int i = 0; i < G_I.size(); i++)
	{
		G_I[i].resize(a_edges);
	}
	//-------выделил памяти------.///


	//vector<vector<pair<int,int>>> G1_P;//массив пар для уникальности




	int iter = 0;
	int jter = 0;
	int result = 0;
	for (int j = 0; j < G_I[1].size(); /*j++*/)//управляет нумерацией ребёр 
	{
		result = LookG1(iter, jter, G_A_any);
		if (check_pair(iter, jter))
		{


			if (result == 0)
			{
				continue;
			}
			else if (result == 1) // то есть в матрице смежности нашлась единица, соед две вершины i,j
			{
				G_I[iter][j] = 1;
				G_I[jter][j] = 1;
				++j;
			}
			else if (result == 2 && iter == jter)
			{
				G_I[iter][j] = 1;
				++j;

			}
			else if (result == 2 && iter != jter)
			{
				G_I[iter][j] = 1;
				G_I[jter][j] = 1;
				j = j + 1;//отвечает за номер ребра
				G_I[iter][j] = 1;
				G_I[jter][j] = 1;
				++j;
			}
			//jter++;
			//++j;//хочу изменять номер ребра только когда была вставка, иначе - не меняем номер, поэтому убрал из цикла инкремент
		}
		jter++;//отвечает за перемещение по матрице смежности

	}
	int k = 0;
	/*cout << "This is matrix of incedent of G1" << endl;
	for (int i = 0; i < G_I.size(); i++)
	{
		for (int j = 0; j < G_I[1].size(); j++)
		{
			cout << G_I[i][j] << " ";
		}
		printf("\n");
	}*/
	G1_P.clear();
}
void Matrix::GetMatrixAdjacency(vector<vector<int>>&G_I, vector<vector<int>>&G_A)
{
	int vertex = G_I.size();
	//vector<vector<int>> G2_A;// матрица смежности
	G_A.resize(vertex);
	for (int i = 0; i < vertex; i++)
	{
		G_A[i].resize(vertex);
	}
	vector<int> G2_Bite;
	int iter = 0;
	int jter = 0;
	int toput = 0;
	int k = 0;
	for (int i = 0; i < G_I[1].size(); i++)
	{
		for (int j = 0; j < G_I.size(); j++)//кушаю столбец и отправляю на проверку
		{
			G2_Bite.push_back(G_I[j][i]);
		}
		k = LookInG2(G2_Bite, iter, jter, toput);//откусанный столбец проверяется
		if (k == 0)
		{
			continue;
		}
		if (k == 2)
		{
			G_A[iter][iter] = 2;
		}
		if (k == 1)
		{
			if (G_A[iter][jter] == 1 && G_A[jter][iter] == 1)
			{
				G_A[iter][jter] = 2;//кратные ребра
				G_A[jter][iter] = 2;
			}
			if (G_A[iter][jter] == 0 && G_A[jter][iter] == 0)
			{
				G_A[iter][jter] = 1;
				G_A[jter][iter] = 1;
			}
		}
		G2_Bite.clear();
	}
	cout << "This is matrix of Adjacency of G2" << endl;
	for (int i = 0; i < G_A.size(); i++)
	{
		for (int j = 0; j < G_A[1].size(); j++)
		{
			cout << G_A[i][j] << " ";
		}
		printf("\n");
	}

}

void Matrix::GetMatrixAdjacencyG3()
{
	int vertex = G3.size();
	//vector<vector<int>> G3_A;// матрица смежности
	G3_A.resize(vertex);
	for (int i = 0; i < vertex; i++)
	{
		G3_A[i].resize(vertex);
	}
	vector<int> G3_Bite;
	int iter = 0;
	int jter = 0;
	int toput = 0;
	int k = 0;
	for (int i = 0; i < G3[1].size(); i++)
	{
		for (int j = 0; j < G3.size(); j++)//кушаю столбец и отправляю на проверку
		{
			G3_Bite.push_back(G3[j][i]);
		}
		LookInG3(G3_Bite, iter, jter, toput);//откусанный столбец проверяется
		if (toput != 99)
		{
			G3_A[toput][toput] = 1;
		}
		if (iter < jter)//то есть сначала была найдена -1 , а потом 1
		{
			G3_A[iter][jter] = G3_A[iter][jter] +0;
			if(G3_A[jter][iter]!=1)
			G3_A[jter][iter] = G3_A[jter][iter] + 1;
		}
		else
		{
			G3_A[iter][jter] = G3_A[iter][jter] + 0;
			if(G3_A[jter][iter]!=1)
			G3_A[jter][iter] = G3_A[jter][iter] + 1;

		}
		G3_Bite.clear();
		toput = 99;
	}
	cout << "This is matrix of Adjacency of G3" << endl;
	for (int i = 0; i < G3_A.size(); i++)
	{
		for (int j = 0; j < G3_A[1].size(); j++)
		{
			cout << G3_A[i][j] << " ";
		}
		printf("\n");
	}
}

void Matrix::MakeSPAdjacency(vector<vector<int>>&G_A, vector<vector<int>>&SP)
{
	int a_edges = GetAmountEdge(G_A);
	int vertex = G_A.size();
	int  k = 0;
	int i1 = 0;
	int j1 = 0;
	for (int i = 0; i < G_A.size(); i++)
	{
		for (int j = i; j < G_A.size(); j++)
		{
			if (G_A[i][j] == 1 && i != j)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				//CreateSP_G1(vertex, a_edges, i, j,G1[i][j]);//
			}
			if (G_A[i][j] == 2 && i != j)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				//CreateSP_G1(vertex, a_edges, i, j, G1[i][j]);//

			}
			if (i == j && G_A[i][j] == 2)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				i1 = i;
				j1 = j;
			}

		}

	}



	//---------------------------
	int p = 0;
	int j2 = 0;
	SP.resize(vertex + 1);
	for (int i = 0; i < vertex + 1; i++, p++)
	{
		j2 = head[i];
		if (i)
		{
			//cout << i << "->";

		}
		while (j2 > 0)
		{
			if (!next_el[j2])
			{
				//cout << terminal[j2];
				SP[p].push_back(terminal[j2]);
			}
			else
			{
				//cout << terminal[j2] << ", ";
				SP[p].push_back(terminal[j2]);
			}
			j2 = next_el[j2];
		}
		cout << endl;
	}

	for (int i = 0; i < SP.size(); i++)
	{
		Repeating(SP[i], i);
	}
	for (int i = 0; i < SP.size(); i++)
	{
		Plus1(SP[i], i);
	}

	//G1_SP.erase(G1_SP.begin());




	memset(next_el, 0, Emax);
	memset(terminal, 0, Emax);
	memset(head, 0, Vmax);

}

void Matrix::MakeSPAdjacencyG2()
{
	int a_edges = GetAmountEdge(G2_A);
	int vertex = G2_A.size();
	int  k = 0;
	int i1 = 0;
	int j1 = 0;
	for (int i = 0; i < G2_A.size(); i++)
	{
		for (int j = i; j < G2_A.size(); j++)
		{
			if (G2_A[i][j] == 1 && i != j)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				//CreateSP_G1(vertex, a_edges, i, j,G1[i][j]);//
			}
			if (G2_A[i][j] == 2 && i != j)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				//CreateSP_G1(vertex, a_edges, i, j, G1[i][j]);//

			}
			if (i == j && G2_A[i][j] == 2)
			{
				AddSP(i + 1, j + 1, k);
				AddSP(j + 1, i + 1, k);
				i1 = i;
				j1 = j;
			}

		}

	}



	//---------------------------
	int p = 0;
	int j2 = 0;
	G2_SP.resize(vertex + 1);
	for (int i = 0; i < vertex + 1; i++, p++)
	{
		j2 = head[i];
		if (i)
		{
			//cout << i << "->";

		}
		while (j2 > 0)
		{
			if (!next_el[j2])
			{
			//	cout << terminal[j2];
				G2_SP[p].push_back(terminal[j2]);
			}
			else
			{
			//	cout << terminal[j2] << ", ";
				G2_SP[p].push_back(terminal[j2]);
			}
			j2 = next_el[j2];
		}
		cout << endl;
	}

	for (int i = 0; i < G2_SP.size(); i++)
	{
		Repeating(G2_SP[i], i);
	}
	for (int i = 0; i < G2_SP.size(); i++)
	{
		Plus1(G2_SP[i], i);
	}

	//G1_SP.erase(G1_SP.begin());




	memset(next_el, 0, Emax);
	memset(terminal, 0, Emax);
	memset(head, 0, Vmax);
}

void Matrix::MakeSPAdjacencyG3()
{
	int a_edges = GetAmountEdge(G3_A);
	int vertex = G3_A.size();
	int  k = 0;
	int i1 = 0;
	int j1 = 0;
	for (int i = 0; i < G3_A.size(); i++)
	{
		for (int j = 0; j < G3_A.size(); j++)
		{
			if (G3_A[i][j] == 1)
			{
				AddSP(i + 1, j + 1, k);
			}
			
		}
	}
	int p = 0;
	int j2 = 0;
	G3_SP.resize(vertex + 1);
	for (int i = 0; i < vertex + 1; i++, p++)
	{
		j2 = head[i];
		if (i)
		{
			cout << i << "->";

		}
		while (j2 > 0)
		{
			if (!next_el[j2])
			{
				cout << terminal[j2];
				G3_SP[p].push_back(terminal[j2]);
			}
			else
			{
				cout << terminal[j2] << ", ";
				G3_SP[p].push_back(terminal[j2]);
			}
			j2 = next_el[j2];
		}
		cout << endl;
	}
	for (int i = 0; i < G3_SP.size(); i++)
	{
		Plus1(G3_SP[i], i);
	}
}

void Matrix::AddVertex(vector<vector<int>>& SP) //для G1
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

	vector<int> num_of_vertexes;
	cout << "Enter vertexes,if loop then add 0"<<endl;
	int temp;
	
	while (cin >> temp) //enter any non-integer to end the loop!
	{
		num_of_vertexes.push_back(temp);
	}
	int new_num_of_vertex = SP[SP.size()-1][0]+1;
	
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
	
	for (int i = 0; i< SP.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), SP[i][0]) != std::end(num_of_vertexes))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}
	SP.insert(SP.end(), num_of_vertexes);
	
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j];
		}
		printf("\n");
	}

}

void Matrix::DeleteVertex(vector<vector<int>>& SP)
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

	cout << "Enter the number of vetex to delete"<<endl;

	int temp = 0;
	cin >> temp;
	

	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			SP.erase(SP.begin()+i);
			--i;
 		}
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (SP[i][j] == temp)
			{
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			}
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

void Matrix::DeleteEdge(vector<vector<int>>& SP)
{
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}

	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;

	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			if (temp == temp1)
			{
				SP[i].insert(SP[i].begin(), temp);
			}
		}

		if (SP[i][0] == temp1)
		{
			SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			if (temp == temp1)
			{
				SP[i].insert(SP[i].begin(), temp);
			}
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

void Matrix::AddEdge(vector<vector<int>>& SP)
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

	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;

	for (int i = 0; i < SP.size(); i++)
	{
		if (SP[i][0] == temp)
		{
			if(temp!=temp1)
				SP[i].push_back(temp1);
		}

		if (SP[i][0] == temp1)
		{
			
			SP[i].push_back(temp);

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

void Matrix::Complement(vector<vector<int>>& SP)
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

	vector <int> V;
	vector <int> V1;

	for (int i = 1; i < SP.size(); i++)
	{
		V.push_back(SP[i][0]);//массив вершин для проверки со строчками 
	}
	V1 = V;
	for (int i = 1; i < SP.size(); i++)//удалаяем из каждой строчки значения , входящие в V и добавляем невходящие
	{
		V1 = V;
		for (int j = 0; j < SP[i].size(); j++)
		{
			V1.erase(std::remove(V1.begin(), V1.end(), SP[i][j]), V1.end());
			
		}
		V1.insert(V1.begin(), SP[i][0]);
		SP[i] = V1;
		
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

void Matrix::DecomposeEdge(vector<vector<int>>&SP)
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
		}

		if (SP[i][0] == temp1)
		{
			SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			if (temp == temp1)
			{
				SP[i].insert(SP[i].begin(), temp);
			}
		}

	}
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
	for (int i = 0; i < SP.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), SP[i][0]) != std::end(num_of_vertexes))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}
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

void Matrix::IdentificationEdge(vector<vector<int>>& SP)
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

	vector <int> V1;//первая вершина
	vector <int> V2;//вторая вершина
	vector <int> V;//V=V1+V2/V1 вершины где соединены первая и вторая 
	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;
	int N1, N2 = 0;
	for (int i = 1; i < SP.size(); i++)
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
	V2 = SP[N2];
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
	
	for (int i = 1; i < SP.size(); i++)//удаляем вершину temp
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
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			}
		}
	}
	for (int i = 1; i < SP.size(); i++)
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
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			}
		}
	}

	vector<int> num_of_vertexes;
	
	num_of_vertexes = V;
	
	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;

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

	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), SP[i][0]) != std::end(num_of_vertexes))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}
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

void Matrix::IdentificationVertex(vector<vector<int>>&SP)
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

	vector <int> V1;//первая вершина
	vector <int> V2;//вторая вершина
	vector <int> V;//V=V1+V2/V1 вершины где соединены первая и вторая 
	cout << "Enter the numbers of 2 vertexes:";
	int temp, temp1;
	cin >> temp >> temp1;
	int N1, N2 = 0;
	for (int i = 1; i < SP.size(); i++)
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
	V2 = SP[N2];
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

	for (int i = 1; i < SP.size(); i++)//удаляем вершину temp
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
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp), SP[i].end());
			}
		}
	}
	for (int i = 1; i < SP.size(); i++)
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
				//G1_SP[i].erase(G1_SP[i].begin()+j);
				SP[i].erase(std::remove(SP[i].begin(), SP[i].end(), temp1), SP[i].end());
			}
		}
	}

	vector<int> num_of_vertexes;

	num_of_vertexes = V;

	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;

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

	for (int i = 1; i < SP.size(); i++)
	{
		if (std::find(std::begin(num_of_vertexes), std::end(num_of_vertexes), SP[i][0]) != std::end(num_of_vertexes))
		{
			SP[i].push_back(new_num_of_vertex);
		}
	}
	SP.insert(SP.end(), num_of_vertexes);
	SP[SP.size()-1].push_back(new_num_of_vertex);
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j] << " ";
		}
		printf("\n");
	}
}

void Matrix::PowerSequenceG1G2G3()
{
	vector<int> powervetrex;
	int max = 0;
	for (int i = 0; i < G1.size(); i++)
	{
		max = 0;
		for (int j = 0; j < G1[i].size(); j++)
		{
			max = max + G1[i][j];
		}
		powervetrex.push_back(max);
	}
	cout << "This is G1 sequence: ";
	std::sort(powervetrex.begin(), powervetrex.end());
	std::copy(powervetrex.begin(), powervetrex.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	vector<int> powervetrex1;
	int max1 = 0;
	for (int i = 0; i < G2_A.size(); i++)
	{
		max1 = 0;
		for (int j = 0; j < G2_A[i].size(); j++)
		{
			max1 = max1 + G2_A[i][j];
		}
		powervetrex1.push_back(max1);
	}
	cout << "This is G2 sequence: ";
	std::sort(powervetrex1.begin(), powervetrex1.end());
	std::copy(powervetrex1.begin(), powervetrex1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	int iter=0;
	int jter=0;
	int locmax;
	int funcmax;
	vector<int> outgoing;
	vector<int> incoming;
	for (int i = 0; i < G3_A.size(); i++)
	{
		locmax = 0;
		funcmax = 0;
		M_I_move(iter, jter, funcmax);
		for (int j = 0; j < G3_A[i].size(); j++)
		{
			locmax = locmax + G3_A[i][j];//идём по матрице смжности складывая единицы строк (исходящие)
			if (i == j && G3_A[i][j] == 1)
			{
				++funcmax;//для петли 
			}
		}
		//
		outgoing.push_back(locmax);//исходящие 
		incoming.push_back(funcmax - locmax);
		//incoming.push_back(funcmax);//заходящие 
	}
	cout << "Outgoing: ";
	std::copy(outgoing.begin(), outgoing.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	cout << "Incoming: ";
	std::copy(incoming.begin(), incoming.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
}

void Matrix::DuplicateVertex(vector<vector<int>>& SP)
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
	vector<int> row= SP[N];
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

void Matrix::Ex(vector<vector<int>>&G1)
{
	int size=G1.size();
	int start, end;
	
	/*vector<int> from(size, -1);
	vector<int> used(size, 0);
	vector<int> dist(size);*/
	vector<int> v;
	//int mainMatrix[SIZE][SIZE];
	int tmp = G1.size();
	int* way = new int[tmp];
	//int way[G1.size()];
	int counter = 0;

	//cin >> start >> end;
	//--start; --end;
	for (start = 0; start < G1.size(); start++)
	{
		for (end = 0; end < G1.size(); end++)
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
					if (G1[hold][i] && !used[i])
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
				cout << -1;
		}
		//G_Dist[start] = v;//создаём матрицу расстояний
		G_Dist.resize(start+1);
		G_Dist[start] = v;
		v.clear();
		
	}
	for (int i = 0; i < G_Dist.size(); i++)
	{
		for (int j = 0; j < G_Dist[i].size(); j++)
		{
			cout << G_Dist[i][j];
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
			cout << "Central vertexes are: " << i<<endl;
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
			cout << "Perepheril vertexes are: " << i<<endl;
		}
	}
	for (int i = 0; i < G1.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < G1[i].size(); j++)
		{
			sum = sum + G1[i][j];
		}
		if (sum == 0)
		{
			cout << i << "is isolaited vertex"<<endl;
		}
		else if (sum == 1)
		{
			cout << i << "is hanging vertex" << endl;
		}
	}

}

void Matrix::VertexBreeding(vector<vector<int>>&SP)
{
	

	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	int new_num_of_vertex = SP[SP.size() - 1][0] + 1;
	int temp;
	cin >> temp;//ввод вершины на будликацию
	vector<int> row = SP[temp];
	row.erase(row.begin());//старый нулевой элемент на удаление
	row.insert(row.begin(), new_num_of_vertex);
	SP.insert(SP.end(), row);
	SP[new_num_of_vertex].push_back(temp);
	



	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}

}

void Matrix::Soedinenie(vector<vector<int>>& SP)
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
	vector<vector<int>> SP2{ {0},{4,5} ,{5,4} };
	for (int i = 0; i < SP2.size(); i++)
	{
		for (int j = 0; j < SP2[i].size(); j++)
		{
			cout << SP2[i][j]<<" ";
		}
		printf("\n");
	}

	vector<vector<int>> G_new;
	G_new = SP;
	vector<int> V;
	bool exists;
	//множество совпадающих вершин
	for (int i=1;i< SP.size();i++)
	{
		for (int j = 1; j < SP2.size(); j++)
		{
			if (SP[i][0] == SP2[j][0])
			{
				V.push_back(SP[i][0]);
			}
		}
	}
	for (int i = 1; i < SP2.size(); i++)
	{
		//for (int j = 1; j < G1_SP.size(); j++)
		exists = std::find(std::begin(V), std::end(V), SP2[i][0]) != std::end(V);//проверка вершина G2 есть в G1 или нет , елси лежит в V - есть в G1
		if(exists)
		{
			for (int j = 1; j < SP.size(); j++)
			{
				if (SP2[i][0] == SP[j][0])
				{
					for (int k = 1; k < SP2[i].size(); k++)
					{
						bool exists1 = std::find(std::begin(SP[j]), std::end(SP[j]), SP2[i][k]) != std::end(SP[j]);//содержится ли элемент G2 в G1
						if (exists1 == 0)
						{
							G_new[i].push_back(SP2[i][k]);
						}

					}
				}
			}
		
		}
		else
		{
			G_new.insert(G_new.end(), SP2[i]);
		}
		
	}


	vector<int>V1, V2;
	for (int i = 1; i < SP.size(); i++)
	{

		if (!(std::find(std::begin(V), std::end(V), SP[i][0]) != std::end(V)))
		{
			V1.push_back(SP[i][0]);//создадим список вершин , входящих в G1,но не входящих в G2
		}

	}
	for (int i = 1; i < SP2.size(); i++)
	{

		if (!(std::find(std::begin(V), std::end(V), SP2[i][0]) != std::end(V)))
		{
			V2.push_back(SP2[i][0]);//создадим список вершин , входящих в G2,но не входящих в G1
		}

	}
	for (int i = 0; i < V1.size(); i++)
	{
		for (int j = 0; j < V2.size(); j++)
		{
			for (int i1 = 1; i1 < G_new.size(); i1++)
			{
				if (G_new[i1][0] == V1[i])
				{
					if (V1[i] != V2[j])
						G_new[i1].push_back(V2[j]);
				}

				if (G_new[i1][0] == V2[j])
				{

					G_new[i1].push_back(V1[i]);

				}

			}

		}
	}




	printf("\n");
	for (int i = 0; i < G_new.size(); i++)
	{
		for (int j = 0; j < G_new[i].size(); j++)
		{
			cout << G_new[i][j]<<" ";
		}
		printf("\n");
	}


}

void Matrix::Disjunction(vector<vector<int>>& SP)
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
	vector<vector<int>> SP2{ {0},{1,2,3} ,{2,1,3},{3,1,2} };
	for (int i = 0; i < SP2.size(); i++)
	{
		for (int j = 0; j < SP2[i].size(); j++)
		{
			cout << SP2[i][j]<<" ";
		}
		printf("\n");
	}
	printf("\n");
	vector<vector<int>> G_new;
	G_new = SP;
	vector<int> buf;
	int max1 =SP[SP.size()-1][0];
	for (int i = 1; i < SP2.size(); i++)
	{
		buf = SP2[i];
		for (int j=0; j < buf.size(); j++)
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
void Matrix::DecProduct(vector<vector<int>>& SP)
{
	/*for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}
	
	//vector<vector<int>> G2_new = G2_SP;
	vector<vector<int>> G2_new{ {0}, {1,2},{2,1} };
	int max1 = SP[SP.size() - 1][0];
	for (int i = 1; i < G2_new.size(); i++)
	{
		for (int j = 0; j < G2_new[i].size(); j++)
		{
			G2_new[i][j] = max1 + G2_new[i][j];
		}
	}
	for (int i = 0; i < G2_new.size(); i++)
	{
		for (int j = 0; j < G2_new[i].size(); j++)
		{
			cout << G2_new[i][j];
		}
		printf("\n");
	}
	vector<vector<int>> G_D;
	G_D.resize((SP.size()-1)*(G2_new.size()-1)+1);
	for (int i = 0; i < G_D.size(); i++)
	{
		G_D[i].push_back(i);
	}
	
	int M = SP.size();
	int N = G2_new.size();
	for (int i = 1; i < M; i++) // номр сторки
	{
		for (int j = 1; j < N; j++)//номр столбец
		{
			for (int k = j; k < N; k++)//
			{
				if (std::find(std::begin(G2_new[j])+1, std::end(G2_new[j]), G2_new[k][0]) != std::end(G2_new[j]))
				{
					for (int i1 = 0; i1 < G_D.size(); i1++)
					{
						if (G_D[i1][0] == Index(i,j,N-1))
						{
							if (Index(i, j, N-1) != Index(i, k, N-1))
								G_D[i1].push_back(Index(i, k, N-1));
						}

						if (G_D[i1][0] == Index(i, k, N-1))
						{

							G_D[i1].push_back(Index(i, j, N-1));

						}

					}
				}
				
				
			}
		}
	}
	for (int i = 1; i < N; i++) // номр столца
	{
		for (int j = 1; j < M; j++)//номр строки
		{
			for (int k = j; k < M; k++)//
			{
				if (std::find(std::begin(SP[j])+1, std::end(SP[j]), SP[k][0]) != std::end(SP[j]))
				{
					for (int i1 = 0; i1 < G_D.size(); i1++)
					{
						if (G_D[i1][0] == Index(j, i, N - 1))
						{
							if (Index(j, i, N - 1) != Index(k, i, N - 1))
								G_D[i1].push_back(Index(k, i, N - 1));
						}

						if (G_D[i1][0] == Index(k, i, N - 1))
						{

							G_D[i1].push_back(Index(j, i, N - 1));

						}

					}
				}


			}
		}
	}
	int k[2];
	for (int i = 0; i < G_D.size(); i++)
	{
		Indexes(k, i, N - 1);
		cout << k[0] << " " << k[1]<<"->";
		for (int j = 0; j < G_D[i].size(); j++)
		{
			cout << G_D[i][j]<<",";

		}
		printf("\n");
	}*/
	
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j] << " ";
		}
		printf("\n");
	}
	vector<vector<int>> G2_new{ {0}, {1,2},{2,1} };
	int max1 = SP[SP.size() - 1][0];
	for (int i = 1; i < G2_new.size(); i++)
	{
		for (int j = 0; j < G2_new[i].size(); j++)
		{
			G2_new[i][j] = max1 + G2_new[i][j];
		}
	}
	vector<pair<int,int>> lin_dec;
	vector<vector<pair<int,int>>> Result;
	pair<int, int> temp;
	int move = 0;
	for (int i = 1; i <= SP.size()-1; i++)
	{
		for (int j = 1; j <= G2_new.size()-1; j++)
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
				bool exists = std::find(std::begin(G2_new[lin_dec[i].second-max1]), std::end(G2_new[lin_dec[i].second-max1]), lin_dec[j].second) != std::end(G2_new[lin_dec[i].second-max1]);
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
			cout << Result[i][j].first<< Result[i][j].second<<";";
		}
		printf("\n");
	}



}


void Matrix::M_I_move(int &i, int &j, int &max)
{
	for (; i < G3.size();)
	{
		for (j=0; j < G3[i].size(); j++)
		{
			max = max + fabs(G3[i][j]);
		}
		++i;
		return;
	}

}

int Matrix::LookG1(int &i, int &j, vector<vector<int>>G_A)
{
	for (; i < G_A.size();i++ ,j=0)
	{
		for (; j < G_A[0].size(); j++)
		{
			if (G_A[i][j] == 0)
				continue;
			if (G_A[i][j] == 1)
			{
				return 1;// в матрице нашлась 1

			}
			if (G_A[i][j] == 2)
			{
				return 2;// но проверить i и j , там может окакзаться петля, если i==j
			}
			
		}
	}
}

bool Matrix::check_pair(int &iter, int &jter)
{
	//static vector<pair<int, int>>G1_P;
	//static int size_p=1;
	//G1_P.resize(size_p);
	
	//size_p++;
	pair<int, int> digits;
	pair<int, int> digits2;
	digits.first = iter;
	digits.second = jter;
	digits2.first = jter;
	digits2.second = iter;

	bool exists = std::find(std::begin(G1_P), std::end(G1_P), digits) != std::end(G1_P);
	bool exists1 = std::find(std::begin(G1_P), std::end(G1_P), digits2) != std::end(G1_P);
	if (!(exists == 1 && exists1 == 1))
	{
		G1_P.push_back(digits);
		//size_p++;
		G1_P.push_back(digits2);
		//size_p++;
		return 1;
	}
	else
		return 0;
	

	/*bool k = 0;
	for (auto temp : G1_P)
	{
		//if (temp.first != digits.first && temp.second != digits2.second)
		if(temp!=digits)
		{
			//if (temp.first != digits2.first && temp.second != digits2.second)
			if(temp!=digits2)
			{
				G1_P.push_back(digits);
				G1_P.push_back(digits2);
				size_p++;
				k = 1;
				return 1;
			}
			return 0;
		}
		return 0;
	}
	//return k;*/

	


}

int Matrix::LookInG2(vector<int>&G2_Bite,int &i, int &j,int& toput)
{
	int counter = 0;
	int place = 0;
	int place1 = 0;

	for (int k=0;k<G2_Bite.size();k++)
	{
		if (G2_Bite[k] == 1)
		{
			counter = counter + 1;
			if(counter==1)
				place = k;
			if (counter == 2)
				place1 = k;
		}
		
	}
	if (counter == 0)
	{
		return 0;
	}
	if (counter == 1)
	{
		i = place;//то есть нашил петлю
		j = 99;
		return 2;
	}
	else if (counter == 2)
	{
		i = place;
		j = place1;
		return 1;
	}
	
}

void Matrix::LookInG3(vector<int>&G3_Bite, int &i, int &j, int &toput)
{
	int counter = 0;
	int place = 0;
	int place1 = 0;
	for (int k = 0; k < G3_Bite.size(); k++)
	{
		if (G3_Bite[k] == 0)
			counter++;
		else
			toput = k;//позиция 1 или -1 
	}
	if (counter == G3_Bite.size() - 1)
	{
		return;
	}
	else
	{
		toput = 99;
	}
	for (int k = 0; k < G3_Bite.size(); k++)
	{
		if (G3_Bite[k] == -1)
		{
			i = k;//хранит значения для -1
		}
		if (G3_Bite[k] == 1)
		{
			j = k;//хранит для 1
			

		}

	}
	
}

/*void Matrix::CreateSP_G1(int &vertexes, int &edges, int &i, int &j,int&G_value)
{
	bool k = 0;
	int i1 = 0;
	int j1 = 0;
	if (i == j && G_value == 2)
	{
		AddSP(i, j);
		AddSP(j, i);
		k = 1;
		i1 = i;
		j1 = j;
	}
	else if (i != j && G_value == 2)
	{
		AddSP(i, j);
		AddSP(j, i);
		AddSP(i, j);
		AddSP(j, i);
	}
	else if (i != j && G_value == 1)
	{
		AddSP(i, j);
		AddSP(j, i);
	}
	
	G1_SP.resize(vertexes+1);
	int j2 = 0;
	static int p = 0;
	int i2 = 0;
	for (i2 = 0; i2 < vertexes + 1; i2++, p++)
	{
		j2 = head[i2];
		if (i2)
		{
			cout << i2 << "->";

		}
		while (j2 > 0)
		{
			if (!next_el[j2])
			{
				cout << terminal[j2];
				G1_SP[p].push_back(terminal[j2]);
			}
			else
			{
				cout << terminal[j2] << ", ";
				G1_SP[p].push_back(terminal[j2]);
			}
			j2 = next_el[j2];
		}
		cout << endl;
	}
	memset(next_el, 0, Emax);
	memset(terminal, 0, Emax);
	memset(head, 0, Vmax);

}*/

void Matrix::AddSP(int v, int u,int& k)
{
	
	k = k + 1;
	terminal[k] = u;
	next_el[k] = head[v];
	head[v] = k;
}

void Matrix::Repeating(vector<int>& array, int i)
{
	for (int i1 = 0; i1 < array.size(); i1++)
	{
		for (int j = i1 + 1; j < array.size(); j++)
		{
			if (array[i1] == array[j])
			{
				//cout << array[i1];
				if (i == array[i1])
				{
					array.erase(array.begin() + i1);//
				}
			}
		}
	}
}

void Matrix::Plus1(vector<int>&arr, int i)
{
	arr.insert(arr.begin(), i);
}

int Matrix::Index(int i, int j,int N)
{
	return (i - 1)*N + j;
}

void Matrix::Indexes(int* arr, int x, int n)
{
	int i=0;
	int j = 0;
	if (x%n == 0)
	{
		i = static_cast<int>(x / n);
	}
	else
	{
		i = static_cast<int>(x / n)+1;
	}
	j = x - (i - 1)*n;
	arr[0] = i;
	arr[1] = j;
}


void Matrix::WriteInSP(ifstream & myfile)
{
	string str;
	int i = 2;
	int j = 1;
	while (getline(myfile, str, '\n'))
	{
		char* str2 = new char[str.length() + 1];
		memset(str2, 0, str.length() + 1);
		G1_SP.resize(i);
		vector<int> buf;
		strcpy(str2, str.c_str());
		while (*str2++)
		{
			if (isdigit(*(str2)))
			{
				buf.push_back((*str2) - 48);
			}
		}
		/*for (; j < i; j++)
		{
			G1_SP[j] = buf;
		}
		i++;*/
		G1_SP[i - 1] = buf;
		i++;
	}
	myfile.close();

}

bool Matrix::IfIncidence(ifstream& myfile, bool& checked, string& str1)
{
	str1.clear();
	checked = 1;
	string str;
	myfile.clear();
	myfile.seekg(0, std::ios::beg);
	bool second = 1;
	vector<vector<int>> LocTempMat;

	int j = 0;
	size_t k = 1;
	while (getline(myfile, str, '\n'))
	{
		LocTempMat.resize(k);
		LocTempMat[j].resize(str.length());
		for (int i = 0; i < str.length(); i++)
		{
			LocTempMat[j][i] = str[i] - 48;
		}
		j++;
		++k;
	}
	int rows = LocTempMat.size();
	int cols = LocTempMat[1].size();
	if (rows != cols)
	{
		second = 0;
		G1_I = LocTempMat;
		return 1;
	}
	for (int i = 0; i < LocTempMat.size(); i++)
	{
		for (int j = 0; j < LocTempMat[i].size(); j++)
		{
			if (LocTempMat[i][j] == LocTempMat[j][i])
			{
				continue;
			}
			else
			{
				second = 0;//эт не матрица смежности,проверка на симметричность провалена, значит точно матрица инцидентности 
			}

		}
	}
	if (second == 1)
	{
		myfile.clear();
		myfile.seekg(0, std::ios::beg);
		fflush;
		return 0;//
	}
	else
	{
		G1_I = LocTempMat;
		return 1;

	}

}

void Matrix::FromSPtoAdjacencyNonOrient(vector<vector<int>>& SP, vector<vector<int>>&G)
{
	int count = 0;
	ReSizeGFromSP(SP, G);

	for (int i = 1; i < SP.size(); i++)
	{
		for (int k = 1; k < SP[i].size(); k++)
		{
			if (SP[i][0] == SP[i][k])
			{
				G[i - 1][SP[i][k] - 1] = 2;
			}
			if (SP[i][0] != SP[i][k])
			{
				G[i - 1][SP[i][k] - 1] = G[i - 1][SP[i][k] - 1] + 1;
			}
		}
		//FindDuplicate(SP[i]);
		/*for (int k = 1; k < SP[i].size(); k++)
		{
			for (int j = k + 1; j < SP[i].size(); j++)
			{
				if (SP[i][k] == SP[i][j])
				{
					cout << SP[i][k];
					//if(i== SP[i][k])
					G[i-1][SP[i][k]-1] = 2;//кртаные ребра
				}
			}
		}
		int temp = SP[i][0];
		for (int k = 1; k < SP[i].size(); k++)
		{
			if (temp == SP[i][k])
			{
				G[i - 1][SP[i][k]] = 2;//петли
			}
		}
		for (int j = 1; j < SP[i].size(); j++)
		{

		}*/
	}
}




void Matrix::ReSizeGFromSP(vector<vector<int>>& SP, vector<vector<int>>& G)
{
	G.resize(SP.size() - 1);
	int maxwides = 1;

	/*for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			if (maxwides < SP[i][j])
				maxwides = SP[i][j];
		}

	}*/

	for (int i = 0; i < SP.size() - 1; i++)
	{
		G[i].clear();
		//G[i].resize(maxwides);
		//G[i].resize(SP[SP.size()-1][0]);
		G[i].resize(SP.size());
	}
}

void Matrix::MinDlin(vector<vector<int>>&G,int from1,int to)
{
	int size;
	int start, end;
	//cin >> size;
	size = G.size();

	vector<int> from(size, -1);
	vector<int> used(size, 0);
	vector<int> dist(size);

	
	int way[100];
	int counter = 0;

	//cin >> start >> end;
	start = --from1;
	end = --to;

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
			if (G[hold][i] && !used[i])
			{
				dist[i] = dist[hold] + 1;
				from[i] = hold;
				Queue.push(i);
				used[i] = true;
			}
		}

	}
	if (used[end])
		cout << dist[end];
	else
		;

}
