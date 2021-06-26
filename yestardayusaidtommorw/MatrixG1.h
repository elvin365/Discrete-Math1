#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include <fstream>
#include<string>
using namespace std;
#define Vmax 100
#define Emax Vmax*2
class Matrix
{
public:
	
	Matrix();
	~Matrix();
	const void GetAmountVertex() const;//общий метод для узнавания кол-ва вершин графа
	int GetAmountEdge(vector<vector<int>>) const;// метод для узнавания кол-ва ребер 
	void GetMatrixIncidence(vector<vector<int>>&, vector<vector<int>>&);//получение матрицы инцидентности для любой матрицы смежности
	void GetMatrixAdjacency(vector<vector<int>>&, vector<vector<int>>&);//получние матрицы смежности для любой матрицы инцидентности
	void GetMatrixAdjacencyG3();//получегние матрицы смежности для G3
	void MakeSPAdjacency(vector<vector<int>>&, vector<vector<int>>&);//получение списка смежности по матрице смежности
	void MakeSPAdjacencyG2();//получение списка смежности графа G2
	void MakeSPAdjacencyG3();//получение списка смежности графа G3(ориент)
	void AddVertex(vector<vector<int>>&);//добавление новой вершины в неориентированный граф
	void DeleteVertex(vector<vector<int>>&);//удаление нужной вершины G1
	void DeleteEdge(vector<vector<int>>&);//удаление в G1 ребра
	void AddEdge(vector<vector<int>>&);//добавление ребра в  G1
	void Complement(vector<vector<int>>&);//дополнение в граф вG1
	void DecomposeEdge(vector<vector<int>>&);//подразбиение графа G1
	void IdentificationEdge(vector<vector<int>>&);//Стягивание ребра
	void IdentificationVertex(vector<vector<int>>&);//Отождествление вершин
	void PowerSequenceG1G2G3();//степенная последовательность неориентрованных графов
	void DuplicateVertex(vector<vector<int>>&);//дублирование вершины неориент графов
	void Ex(vector<vector<int>>&G);//эксцентриситеты и всё про них
	void VertexBreeding(vector<vector<int>>&);//размножение вершины неориент
	void Soedinenie(vector<vector<int>>&);//соединение графов неоринет
	void Disjunction(vector<vector<int>>&);//дизъюнкт объединение
	void DecProduct(vector<vector<int>>&);//декартого проиизведение
	void AddVertexOr(vector<vector<int>>&);//добавление вершины в орграф
	void DeleteVertexOr(vector<vector<int>>&);//удалени вершины в орграфе 
	void AddEdgeOr(vector<vector<int>>&);//добавление ребра в орграф
	void DeleteEdgeOr(vector<vector<int>>&);//удаление ребра в оргрфе 
	void DecomposeEdgeOr(vector<vector<int>>&);//подразбиение ребра в орграфе  
	void IdentificationOr(vector<vector<int>>&);//стягивание ребра
	void IdentificationOrVertex(vector<vector<int>>&);// отождествление вершины
	void DuplicateVertexOr(vector<vector<int>>&);//дублирование вершины оргрфа
	void BreedingVertexOr(vector<vector<int>>&);//размножение вершины орграфа
	void DisjunctionOr(vector<vector<int>>&);//объединение графаор
	void SoedinenieOr(vector<vector<int>>&);//соединение орграфов
	void DecProductOr(vector<vector<int>>&);//произвделдениеграфов ор
	void AmountEdgesInOr();//кол-во ребер в орграфе
	void MinDlin(vector<vector<int>>&G,int,int);

//operations----------------------------------
	void TaskAddVertex(vector<vector<int>>&G,int);//добавление вершины для задания 2
	void TaskDeleteVertex(vector<vector<int>>&G, int);//удаление вершны для заданяи 2
	void TaskDeleteEdge(vector<vector<int>>&G, pair<int,int>);//удаление ребра
	void TaskAddEdge(vector<vector<int>>&G, pair<int, int>);//добавления ребра
	void TaskComplement(vector<vector<int>>&G);
	void TaskAddVertexOr(vector<vector<int>>&,int);
	void TaskDeleteVertexOr(vector<vector<int>>&, int);
	void TaskAddEdgeOr(vector<vector<int>>&, pair<int, int>);
	void TaskDeleteEdgeOr(vector<vector<int>>&, pair<int, int>);
	void TaskIdentification(vector<vector<int>>&, pair<int, int>);
	void TaskDisjunktion(vector<vector<int>>&, vector<vector<int>>&);
	void FromSPtoAdjacencyNonOrient(vector<vector<int>>&SP, vector<vector<int>>&G);
	void TaskEx(vector<vector<int>>&);

//private:
	vector<vector<int>> G1;//изначально смежности
	vector<vector<int>> G1_I;// матрица инцидентности
	vector<vector<int>> G2;//изначально инцидентности
	vector<vector<int>> G2_A;// матрица смежности G2
	vector<vector<int>> G3;//изначально инцидентности
	vector<vector<int>> G3_A;// матрица смежности G3
	vector<vector<int>> G1_SP;// список смежности матрицы смежности G1
	vector<vector<int>> G2_SP;// список смежности матрицы смежности G2
	vector<vector<int>> G3_SP;// список смежности матрицы смежности G3
	vector<vector<int>> G3_SP_C;//копия 
	vector<vector<int>> G_Dist;//матрица расстояний для нахождения ex
	vector<pair<int, int>>G1_P;//для check_pair
	vector<vector<int>> G4_SP;//task 2c
	vector<vector<int>> G4;//смежность для 2с
	vector<vector<int>> G4_I;//инцедентность
	vector<vector<int>> G_new; // тут результат третьего задания
	vector<vector<int>> G_new_A; // тут результат третьего задания

private:
	void M_I_move(int&, int&, int&);
	int LookG1(int&,int&, vector<vector<int>>G_A);
	bool check_pair(int&, int&);
	int LookInG2(vector<int>&,int&,int&,int&);
	void LookInG3(vector<int>&, int&, int&, int&);
	//void CreateSP_G1();
	void AddSP(int, int,int&);
	void Repeating(vector<int>&, int i);
	void Plus1(vector<int>&, int i);
	int Index(int, int,int);
	void Indexes(int*,int,int);
	void WriteInSP(ifstream&);
	bool IfIncidence(ifstream&, bool&, string&);
	//void FromSPtoAdjacencyNonOrient(vector<vector<int>>&SP, vector<vector<int>>&G);
	void ReSizeGFromSP(vector<vector<int>>&SP, vector<vector<int>>&G);
	//const int Vmax = 100, Emax = Vmax * 2;
	//----------------------------
	int head[Vmax];
	int next_el[Emax];
	int terminal[Emax];
	//int n, m, i, j, k, v, u;
	char r;
	////////------------------------
	

};

