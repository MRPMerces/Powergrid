//#include "Graph.h"
//
//Graph::Graph(int s) :size(s) {
//
//	arr = new bool* [size];
//	for (int i = 0; i < size; i++) {
//		arr[i] = new bool[size];
//
//		for (int j = 0; j < size; j++) arr[i][j] = false;
//	}
//}
//
//void Graph::add_edge(int a, int b) {
//	if (a < 0 || b < 0 || a >= size || b >= size) error("Invalid index");
//
//	arr[a][b] = true;
//	arr[b][a] = true;
//	// cost[a][b] = 10;
//	// cost[b][a] = 10;
//}
//
//void Graph::remove_edge(int a, int b) {
//	if (a < 0 || b < 0 || a >= size || b >= size) error("Invalid index");
//
//	arr[a][b] = false;
//	arr[b][a] = false;
//}
//
//void Graph::print() {
//	for (int i = 0; i < size; i++) {
//		std::cout << i << " -> ";
//		for (int j = 0; j < size; j++) if (arr[i][j]) std::cout << j << " ";
//		std::cout << std::endl;
//
//	}
//}
//
//int Edge::get_cost() const {
//	return cost;
//}
//
//void Edge::set_cost(int c) {
//	cost = c;
//}
