#include <iostream>
#include "Graph.h"

using namespace std;



int main() {

	Graph graph;
	setlocale(LC_ALL, "RUS");
	// Ввод рёбер с клавиатуры
	cout << "Введите ориентированный граф для поиска диаметра графа" << endl;	
	graph.inputGraph(true);
	graph.findDiameter();
	cout << "Вывод дерева в виде списка смежных вершин" << endl;
	graph.printAdjList();
	cout << endl;
	cout << "Введите неориентированный граф для поиска минамального остовного дерева" << endl;
	Graph graph1;
	graph.inputGraph(false);
	graph1.minimumSpanningTree().printAdjList();
	return 0;
}