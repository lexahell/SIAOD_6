#include "Graph.h"

void Graph::addVertex(int vertex) {
	for (int i = 0; i < adjList.size(); i++) {
		if (adjList[i].first == vertex) {
			return;
		}
	}
	pair <int, vector<pair<int, int>>> newVertex;
	newVertex.first = vertex;
	adjList.push_back(newVertex);
}
void Graph::addEdge(int from, int to, int weight) {
    bool existFrom = false, existTo = false;

    for (int i = 0; i < adjList.size(); i++) {
        if (adjList[i].first == from) {
            existFrom = true;
            for (int j = 0; j < adjList[i].second.size(); j++) {
                if (adjList[i].second[j].first == to) {
                    cout << "–ебро уже существует" << endl;
                    return;
                }
            }
            pair<int, int> adjVertex(to, weight);

            adjList[i].second.push_back(adjVertex);
        }
        if (adjList[i].first == to) {
            existTo = true;
        }
    }
    if (!existFrom) {
        addVertex(from);
        pair<int, int> adjVertex(to, weight);
        adjList.back().second.push_back(adjVertex);
    }
    if (!existTo) {
        addVertex(to);
    }
}
void Graph::inputGraph(bool isOriented) {
    int numEdges;
    cout << "¬ведите количество рЄбер: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int from;
        int to;
        int weight;
        cout << "¬ведите номер начальной вершины, номер конечной вершины и вес ребра: ";
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
        // дл€ не ориентированного графа
        if (!isOriented) {
            addEdge(to, from, weight);
        }
    }
}
void Graph::printAdjList() {
    for (int i = 0; i < adjList.size(); i++) {
        cout << adjList[i].first << ": [";
        for (int j = 0; j < adjList[i].second.size();j++) {
            cout << "(" << adjList[i].second[j].first << ", вес: " << adjList[i].second[j].second << ")";
            if (j != adjList[i].second.size() - 1) {
                cout << ", ";
            }
        }
        cout <<"]" << endl;
    }
}
int Graph::findDiameter() {
    int maxDiameter = 0;
    unordered_map<int, int> vertex_index;
    for (int i = 0; i < adjList.size(); i++){
        int vertexNum = adjList[i].first;
        vertex_index[vertexNum] = i;
    }

    for (int i = 0; i < adjList.size();i++) {
        int start = adjList[i].first;
        vector<int> distance(adjList.size(), 0);
        queue<int> q;

        q.push(vertex_index[start]);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < adjList[current].second.size(); i++) {
                int adjVertexInd = vertex_index[adjList[current].second[i].first];
                    q.push(adjVertexInd);
                    if (distance[adjVertexInd] == 0) {
                        distance[adjVertexInd] = distance[current] + adjList[current].second[i].second;
                    }
                    else {
                        distance[adjVertexInd] = min(distance[adjVertexInd], distance[current] + adjList[current].second[i].second);
                    }
            }
        }
        int maxDistance = *max_element(distance.begin(), distance.end());
        maxDiameter = max(maxDiameter, maxDistance);
    }

    return maxDiameter;
}

Graph Graph::minimumSpanningTree() {
    Graph newGraph;
    unordered_map<int, int> vertex_index;
    for (int i = 0; i < adjList.size(); i++) {
        int vertexNum = adjList[i].first;
        vertex_index[vertexNum] = i;
    }
    int number_edge = 0;
    vector <bool> used(adjList.size(), false);
    const int INF = 1e9;
    used[0] = true;
    int sum = 0;
    while (number_edge < adjList.size() - 1) {
        int min = INF;
        int from = 0;
        int to = 0;
        
        for (int i = 0; i < adjList.size(); i++) {
            if (used[i]) {
                for (int j = 0; j < adjList[i].second.size(); j++) {
                    if (!used[vertex_index[adjList[i].second[j].first]]) {
                        if (min > adjList[i].second[j].second) {
                            min = adjList[i].second[j].second;
                            from = adjList[i].first;
                            to = adjList[i].second[j].first;
                        }
                    }
                }
            }
        }
        sum += min;
        newGraph.addEdge(from, to, min);
        newGraph.addEdge(to, from, min);
        used[vertex_index[to]] = true;
        number_edge++;
    }
    cout << "—умма ребер остовного дерева равна: " << sum << endl;
    return newGraph;
}