#pragma once
#include"MatrixG1.h"
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include<cmath>
#include<queue>
class TaskMenu
{
private:
	static void CreatInit(Matrix &x);
	static void Fix(vector<vector<int>>& t);
	static void FixSP(vector<vector<int>>&SP);

public:
	static void Task1(Matrix &x);
	static void Task2(Matrix &x);
	static void Task3(Matrix&x);
	static void Task4(Matrix&x);
};
void TaskMenu::CreatInit(Matrix &x)
{
	x.G4_SP.resize(x.G1_SP.size());
	for (int i = 0; i < x.G4_SP.size(); i++)
	{
		x.G4_SP[i].resize(x.G1_SP[i].size());
		x.G4_SP[i] = x.G1_SP[i];
	}

	x.G4.resize(x.G1.size());
	for (int i = 0; i < x.G4.size(); i++)
	{
		x.G4[i].resize(x.G1[i].size());
		x.G4[i] = x.G1[i];
	}
	x.G4_I.resize(x.G1_I.size());
	for (int i = 0; i < x.G4.size(); i++)
	{
		x.G4_I[i].resize(x.G1_I[i].size());
		x.G4_I[i] = x.G1_I[i];
	}
	
	/*for (int i = 0; i < x.G1_SP.size(); i++)
	{
		for (int j = 0; j < x.G1_SP[i].size(); j++)
		{
			x.G4_SP[i][j] = x.G1_SP[i][j];
		}
	}

	for (int i = 0; i < x.G1.size(); i++)
	{
		for (int j = 0; j < x.G1[i].size(); j++)
		{
			x.G4[i][j] = x.G1[i][j];
		}
	}
	for (int i = 0; i < x.G1_I.size(); i++)
	{
		for (int j = 0; j < x.G1_I[i].size(); j++)
		{
			x.G4_I[i][j] = x.G1_I[i][j];
		}
	}*/

}

void TaskMenu::Task1(Matrix &x) 
{
	cout <<"\n"<<"The 1 Task" << endl;
	x.GetAmountVertex();
	cout << "The amount of edges G1 has: ";
	x.GetAmountEdge(x.G1);
	cout << "\n";
	cout << "The amount of edges G2 has: ";
	x.GetAmountEdge(x.G2_A);
	cout << "\n";
	cout << "The amount of edges G3 has: ";
	//x.GetAmountEdge(x.G3_A);
	x.AmountEdgesInOr();
	cout << "\n";
	cout << "The list of adjacency of G1" << endl;
	for (int i = 1; i < x.G1_SP.size(); i++)
	{
		for (int j = 0; j < x.G1_SP[i].size(); j++)
		{
			cout<<x.G1_SP[i][j]<<" ";
		}
		printf("\n");

	}
	
	cout << "The list of adjacency of G2" << endl;
	for (int i = 1; i < x.G2_SP.size(); i++)
	{
		for (int j = 0; j < x.G2_SP[i].size(); j++)
		{
			cout << x.G2_SP[i][j]<<" ";
		}
		printf("\n");

	}

	cout << "The list of adjacency of G3" << endl;
	for (int i = 1; i < x.G3_SP.size(); i++)
	{
		for (int j = 0; j < x.G3_SP[i].size(); j++)
		{
			cout << x.G3_SP[i][j]<<" ";
		}
		printf("\n");

	}
	x.PowerSequenceG1G2G3();

	cout << "The Incidence of G1" << endl;
	for (int i = 0; i < x.G1_I.size(); i++)
	{
		for (int j = 0; j < x.G1_I[i].size(); j++)
		{
			cout << x.G1_I[i][j]<< " ";
		}
		printf("\n");

	}


	cout << "The adjacency of G2" << endl;

	for (int i = 0; i < x.G2_A.size(); i++)
	{
		for (int j = 0; j < x.G2_A[i].size(); j++)
		{
			cout << x.G2_A[i][j]<<" ";
		}
		printf("\n");
	}

	cout << "The adjacency of G3" << endl;

	for (int i = 0; i < x.G3_A.size(); i++)
	{
		for (int j = 0; j < x.G3_A[i].size(); j++)
		{
			cout << x.G3_A[i][j]<<" ";
		}
		printf("\n");

	}

}
void TaskMenu::Task2(Matrix &x)
{
	cout << "This is Task2" << endl;
	//vi: {11, 12, 8, 8, 9, 10, 3};
	int d_vertex[] = { 11, 12, 8, 8, 9, 10, 3 };
	x.TaskAddVertex(x.G1_SP, d_vertex[0]);
	x.TaskAddVertex(x.G1_SP, d_vertex[1]);
	x.TaskDeleteVertex(x.G1_SP, d_vertex[2]);
	//FixSP(x.G1_SP);
	//ei: {(9,11), (9,10), (4,12), (10, 12), (5,11), (5,5), (7,1)}
	pair<int, int> edges[] = { make_pair(9, 11), make_pair(9, 10),make_pair(4,12),make_pair(10,12),make_pair(5,11),make_pair(5,5),make_pair(7,1) };
	x.TaskAddEdge(x.G1_SP, edges[0]);
	x.TaskAddEdge(x.G1_SP, edges[1]);
	x.TaskAddEdge(x.G1_SP, edges[2]);
	x.TaskAddEdge(x.G1_SP, edges[3]);
	x.TaskAddEdge(x.G1_SP, edges[4]);
	x.TaskDeleteEdge(x.G1_SP, edges[5]);
	x.TaskDeleteEdge(x.G1_SP, edges[6]);
	//построить дополнение
	x.TaskAddEdge(x.G1_SP, make_pair(1,7));
	//FixSP(x.G1_SP);
	CreatInit(x);

	x.G3_SP_C.resize(x.G3_SP.size());
	for (int i = 0; i < x.G3_SP.size(); i++)
	{
		x.G3_SP_C[i].resize(x.G3_SP[i].size());
		x.G3_SP_C[i] = x.G3_SP[i];
	}
	FixSP(x.G4_SP);
	x.TaskComplement(x.G4_SP);
	cout << "Matrix of Adjacency" << endl;
	for (int i = 0; i < x.G4.size(); i++)
	{
		for (int j = 0; j < x.G4[i].size(); j++)
		{
			cout << x.G4[i][j]<<" ";
		}
		printf("\n");
	}
	//------------------орграф
	x.TaskAddVertexOr(x.G3_SP,d_vertex[3]);
	x.TaskAddVertexOr(x.G3_SP, d_vertex[4]);
	x.TaskAddVertexOr(x.G3_SP, d_vertex[5]);
	x.TaskDeleteVertexOr(x.G3_SP, d_vertex[6]);

	pair<int, int> edgesor[] = { make_pair(1, 4), make_pair(2, 7),make_pair(1,9),make_pair(3,4)};
	x.TaskAddEdgeOr(x.G3_SP, edgesor[0]);
	x.TaskAddEdgeOr(x.G3_SP, edgesor[1]);
	x.TaskAddEdgeOr(x.G3_SP, edgesor[2]);
	x.TaskDeleteEdgeOr(x.G3_SP, edgesor[3]);

	//--------------обратный порядок
	x.TaskAddEdgeOr(x.G3_SP_C, edgesor[0]);
	x.TaskAddEdgeOr(x.G3_SP_C, edgesor[1]);
	x.TaskAddEdgeOr(x.G3_SP_C, edgesor[2]);
	x.TaskDeleteEdgeOr(x.G3_SP_C, edgesor[3]);
	x.TaskAddVertexOr(x.G3_SP_C, d_vertex[3]);
	x.TaskAddVertexOr(x.G3_SP_C, d_vertex[4]);
	x.TaskAddVertexOr(x.G3_SP_C, d_vertex[5]);
	x.TaskDeleteVertexOr(x.G3_SP_C, d_vertex[6]);
	

}

void TaskMenu::Task3(Matrix &x)
{
	//отождествить вершины G4 и объединить c G2
	cout << "This is Task 3"<<endl;
	pair<int, int> t;
	t.first = 1;
	t.second = 10;
	x.TaskIdentification(x.G4_SP, t);
	x.TaskDisjunktion(x.G4_SP, x.G2_SP);
	x.FromSPtoAdjacencyNonOrient(x.G_new, x.G_new_A);
}

void TaskMenu::Task4(Matrix &x)
{
	cout << "This is Task4:" << endl;
	FixSP(x.G_new);
	
	x.FromSPtoAdjacencyNonOrient(x.G_new, x.G_new_A);
	x.TaskEx(x.G_new_A);
}

void TaskMenu::Fix(vector<vector<int>>& t)
{
	for (int i = 1; i < t.size()-1; i++)
	{
		vector<int> tempVec;
		tempVec.push_back(i);
		if (t[i][0] != i)
		{
			t.insert(t.begin() + i, tempVec);
			tempVec.clear();
		}
		tempVec.clear();
	}
	
	
	
}

void TaskMenu::FixSP(vector<vector<int>>&SP)
{
	int toreduce = 0;
	for (int i = 1; i < SP.size(); i++)
	{
		if (SP[i][0] != i)
		{
			toreduce = SP[i][0];
			SP[i][0] = i;
			for (int k = 1; k < SP.size(); k++)
			{
				for (int r = 0; r < SP[k].size(); r++)
				{
					if (SP[k][r] == toreduce)
					{
						SP[k][r] = i;
					}
				}
			}
		}
	}
	puts("\n");
	for (int i = 0; i < SP.size(); i++)
	{
		for (int j = 0; j < SP[i].size(); j++)
		{
			cout << SP[i][j]<<" ";
		}
		printf("\n");
	}

}