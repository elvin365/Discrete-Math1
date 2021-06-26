#define _CRT_SECURE_NO_WARNINGS
#include"MatrixG1.h"
#include"TaskMenu.h"
void FixSP(vector<vector<int>>&SP)
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

}
void enter(Matrix &x)
{
	int k = 0;
	int j = 0;
	char letter;
	cout << "Choose an option"<<endl;
	cout << "1-определение числа вершин" << endl;
	cout << "2-определение числа ребер (дуг)" << endl;
	cout << "3-определение степенной последовательности графа"<<endl;
	cout << "4-определение матрицы смежности" << endl;
	cout << "5-определение матрицы инцидентности" << endl;
	cout << "6-определение списка смежности" << endl;
	cout << "7-определение расстояния между двумя вершинами" << endl;
	cout << "8-эксцентриситеты и всё про них" << endl;
	cout << "9-добавление вершины в неориентированный граф" << endl;
	cout << "10-удаление вершины в неориентированный граф" << endl;
	cout << "11-удаление ребра в неориентированный граф" << endl;
	cout << "12-определение дополнения графа" << endl;
	cout << "13-подразбиение ребра" << endl;
	cout << "14-отождествление вершин" << endl;
	cout << "15-дублирование вершины" << endl;
	cout << "16-размножение вершины" << endl;
	cout << "17-объединение (дизъюнктивное) графов" << endl;
	cout << "18-соединение графов" << endl;
	cout << "19-произведение графов" << endl;
	cout << "20-добавление вершины в ориентированный граф" << endl;
	cout << "21-удаление вершины в ориентированном графe" << endl;
	cout << "22-добавление ребра в ориентированном графe" << endl;
	cout << "23-удаление ребра в ориентированный граф" << endl;
	cout << "24-подразбиение ребра орграфа" << endl;
	cout << "25-отождествление вершин орграфа" << endl;
	cout << "26-дублирование вершины орграфа" << endl;
	cout << "27-размножение вершины орграфа" << endl;
	cout << "28-объединение (дизъюнктивное) орграфов" << endl;
	cout << "29-соединение орграфа" << endl;
	cout << "30-произведение орграфа" << endl;
	cout << "31-добавление ребра в неориентированный граф" << endl;






	cin >> letter;
	switch (letter)
	{
	case '1':x.GetAmountVertex();
		break;
	case '2':x.GetAmountEdge(x.G1);
		x.GetAmountEdge(x.G2_A);
		x.GetAmountEdge(x.G3_A);
		break;
	case '3':x.PowerSequenceG1G2G3();
		break;
	case'4':
		printf("Матрица смежности G2\n");
		x.GetMatrixAdjacency(x.G2, x.G2_A);
		printf("\nМатрица смежности G3\n");
		x.GetMatrixAdjacencyG3();
		break;
	case '5':
		printf("Матрица инцидентности G1\n");
		x.GetMatrixIncidence(x.G1, x.G1_I);
		break;
	case '6' :
		printf("Список смежности G1\n");
		x.MakeSPAdjacency(x.G1, x.G1_SP);
		for (int i = 0; i < x.G1_SP.size(); i++)
		{
			for (int j = 0; j < x.G1_SP[i].size(); j++)
			{
				cout << x.G1_SP[i][j];
			}
			printf("\n");

		}
		printf("\n");
		printf("Список смежности G2\n");
		x.MakeSPAdjacency(x.G2_A, x.G2_SP);
		for (int i = 0; i < x.G2_SP.size(); i++)
		{
			for (int j = 0; j < x.G2_SP[i].size(); j++)
			{
				cout << x.G2_SP[i][j];
			}
			printf("\n");

		}
		printf("\n");
		printf("Список смежности G3\n");
		x.MakeSPAdjacency(x.G3_A, x.G3_SP);
		for (int i = 0; i < x.G3_SP.size(); i++)
		{
			for (int j = 0; j < x.G3_SP[i].size(); j++)
			{
				cout << x.G3_SP[i][j];
			}
			printf("\n");
		}
		break;
	case '7':
		printf("Enter from to digits: ");
		cin >> k >> j;
		x.MinDlin(x.G1, k, j);
		break;
	case '8': x.Ex(x.G1);
		break;
	case'9': x.AddVertex(x.G1_SP);
		break;
	case'10':x.DeleteVertex(x.G1_SP);
		break;
	case'11':x.DeleteEdge(x.G1_SP);
		break;
	case'12':x.Complement(x.G1_SP);
		break;
	case'13':x.DecomposeEdge(x.G1_SP);
		break;
	case'14':x.IdentificationVertex(x.G1_SP);
		break;
	case'15':x.DuplicateVertex(x.G1_SP);
		break;
	case'16':x.VertexBreeding(x.G1_SP);
		break;
	case'17':x.Disjunction(x.G1_SP);
		break;
	case'18':x.Soedinenie(x.G1_SP);
		break;
	case'19':x.DecProduct(x.G1_SP);
		break;
	case'20': x.AddVertexOr(x.G3_SP);
		break;
	case'21':x.DeleteVertexOr(x.G3_SP);
		break;
	case'22':x.AddEdgeOr(x.G3_SP);
		break;
	case'23':x.DeleteEdgeOr(x.G3_SP);
		break;
	case'24':x.DecomposeEdgeOr(x.G3_SP);
		break;
	case'25': x.IdentificationOr(x.G3_SP);
		break;
	case'26': x.DuplicateVertexOr(x.G3_SP);
		break;
	case'27': x.BreedingVertexOr(x.G3_SP);
		break;
	case'28': x.DisjunctionOr(x.G3_SP);
		break;
	case'29': x.SoedinenieOr(x.G3_SP);
		break;
	case'30': x.DecProductOr(x.G3_SP);
		break;
	case'31':x.AddEdge(x.G1_SP);
		break;
	default:
		break;
	}
}
int main()
{
	system("chcp 1251"); // переходим в консоли на русский язык
	Matrix x;//fist to go so far..
	//x.Complement(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.IdentificationVertex(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.DecProduct(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.IdentificationOr(x.G3_SP);
	//x.SoedinenieOr(x.G3_SP);
	//x.DecProductOr(x.G3_SP);
	//x.DisjunctionOr(x.G3_SP);
	//FixSP(x.G3_SP);
	/*x.DeleteVertex(x.G1_SP);
	FixSP(x.G1_SP);
	x.DecomposeEdge(x.G1_SP);
	FixSP(x.G1_SP);
	x.Identification(x.G1_SP);
	FixSP(x.G1_SP);
	x.DuplicateVertex(x.G1_SP);
	FixSP(x.G1_SP);
	x.VertexBreeding(x.G1_SP);
	FixSP(x.G1_SP);
	x.Disjunction(x.G1_SP);
	x.DeleteVertex(x.G1_SP);
	FixSP(x.G1_SP);*/
	/*x.AddVertex(x.G1_SP);
	FixSP(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.AddVertex(x.G1_SP);
	FixSP(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.AddEdge(x.G1_SP);
	FixSP(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.AddEdge(x.G1_SP);
	FixSP(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.AddEdge(x.G1_SP);
	FixSP(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.DeleteEdge(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.DeleteEdge(x.G1_SP);
	cin.clear();
	cin.ignore(32767, '\n');
	x.DeleteEdge(x.G1_SP);*/
	//x.IdentificationEdge(x.G1_SP);
	//x.IdentificationVertex(x.G1_SP);
	//x.DuplicateVertex(x.G1_SP);
	//x.Soedinenie(x.G1_SP);
	//x.Complement(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.IdentificationEdge(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.DecProduct(x.G1_SP);
	//x.Soedinenie(x.G1_SP);
	//x.DecProduct(x.G1_SP);
	//FixSP(x.G1_SP);
	//FixSP(x.G1_SP);
	//x.Complement();	
	//x.Identification();
	/*int t = x.G1_SP.size();
	for (int i = 1; i < t - 1; i++)
	{
		vector<int> tempVec;
		tempVec.push_back(i);
		if (x.G1_SP[i][0] != i)
		{
			x.G1_SP.insert(x.G1_SP.begin() + i, tempVec);
			tempVec.clear();
		}
		tempVec.clear();
	}*/
	/*for (int i = 1; i < x.G1_SP.size(); i++)
	{
		for (int j = 0; j < x.G1_SP[i].size(); j++)
		{
			x.G1_SP[i][j] = x.G1_SP[i][j] - 1;
		}
	}*/
	//x.DecProduct();
	//x.GetMatrixIncidence();
	//x.GetAmountVertex();
	//x.GetMatrixAdjacencyG3();
	//x.MakeSPAdjacency();
	//x.GetMatrixAdjacencyG3();
	//x.MakeSPAdjacencyG3();
	//x.GetMatrixIncidence();
	//x.MakeSPAdjacency();
	//x.GetMatrixAdjacency();
	//x.GetMatrixIncidence();
	//x.GetMatrixAdjacency();
	/*x.MakeSPAdjacencyG2();
	x.MakeSPAdjacency();
	x.GetMatrixAdjacencyG3();
	x.MakeSPAdjacencyG3();*/
	//x.MakeSPAdjacencyG3();
	//x.AddVertex();
//	x.DeleteVertex();
//	x.DeleteVertex();
//	x.DeleteEdge();
	//x.AddEdge();
	//x.Complement();
	//x.DecomposeEdge();
	//x.Identification();
	//x.GetMatrixAdjacency();
	//x.GetMatrixAdjacencyG3();
	//x.PowerSequenceG1G2G3();
	//x.DuplicateVertex();
//	x.Ex();
	//x.VertexBreeding();
	//x.Disjunction();
	//x.Soedinenie();
	//x.DecProduct();
	//x.AddVertexOr();
	//x.DeleteVertexOr();
//	x.AddEdgeOr();
	//x.Soedinenie(x.G1_SP);
	//x.DeleteEdgeOr();
	//x.DecomposeEdgeOr();
	//x.IdentificationOr();
	//x.DuplicateVertexOr();
	//x.BreedingVertexOr();
	//x.DisjunctionOr();
	//x.GetMatrixAdjacency();
	//x.SoedinenieOr();
	//x.Soedinenie();
	//x.DecProduct();

	//TaskMenu::Task1(x);
	//x.AddVertex();
//	TaskMenu::Task2(x);
//	TaskMenu::Task3(x);
//	TaskMenu::Task4(x);
	char letter;
	cout << "Enter t(task) or c(custom) ";
	cin >> letter;
	switch (letter)
	{
	case 't':
		TaskMenu::Task1(x);
		TaskMenu::Task2(x);
		TaskMenu::Task3(x);
		TaskMenu::Task4(x);
		break;
	case 'c': enter(x);
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}