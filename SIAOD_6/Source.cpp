#include <iostream>
#include "Graph.h"

using namespace std;



int main() {

	Graph graph;
	setlocale(LC_ALL, "RUS");
	// ���� ���� � ����������
	cout << "������� ��������������� ���� ��� ������ �������� �����" << endl;	
	graph.inputGraph(true);
	graph.findDiameter();
	cout << "����� ������ � ���� ������ ������� ������" << endl;
	graph.printAdjList();
	cout << endl;
	cout << "������� ����������������� ���� ��� ������ ������������ ��������� ������" << endl;
	Graph graph1;
	graph.inputGraph(false);
	graph1.minimumSpanningTree().printAdjList();
	return 0;
}