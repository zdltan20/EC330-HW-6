#include "job.h"
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <iterator>
using namespace std;

/* SOURCES
	constructing adjacency lists - https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-list
	Depth First Search - https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	
	All sources used to get general idea of how to contstruct the algorithm
	All algorithms were created to accomplish the task
*/

void DFS(int v, list<int> adj[], int visited[], bool &flag) {
	//Not Visited = 0
	//Visiting = -1
	//Visited = 1
	if(!flag) return; //if cycle detected end recurrsion
	visited[v] = -1; //set current vertex to visiting
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++) {
		if(!flag) break;
		if(visited[*i] == -1) { //if next vertex is visiting
			flag = false; //cycle detected
		} else if(visited[*i] == 0) { //if unvisited
			DFS(*i, adj, visited, flag);
		}
	}
	visited[v] = 1; //set vertex to visited
}	

bool canFinish(int n, vector<pair<int, int>> &dependencies) { 
	//Variable Declaration
	list<int> adj[n+1];
	bool flag = true;
	int visited[n+1] = {0};
	
	//Adjacency List Population
	for(int i = 0; i < dependencies.size(); i++) 
		adj[dependencies[i].first].push_back(dependencies[i].second);
	
	//Call DFS Search
	for(int i = 1; i <= n; i++) {
		DFS(i, adj, visited, flag);
		if(!flag) break; //if any cycle detected, break;
		for(int j = 1; j < n + 1; j++) //reset visited array
			visited[j] = 0;
	}
	return flag; 
}

void countDependents(int v, int largest, list<int> adj[], int freq[]) {
	//using DFS for to count dependents
	
	//Variable Declaration
	int top;
	bool visited[largest+1] = {false};
	vector<int> dependent;
	stack<int> myStack;
	
	myStack.push(v);
	visited[v] = true;
	while(!myStack.empty()) { //while vertex is being visited
		top = myStack.top();
		myStack.pop();
		list<int>::iterator i;
		for(i = adj[top].begin(); i != adj[top].end(); i++) {
			if(!visited[*i]) { //while not unvisited 
				dependent.push_back(*i);
				myStack.push(*i);
				visited[*i] = true;
			}
		}
	}
	for(int i = 0; i < dependent.size(); i++) //store frequency of dependents
		freq[dependent[i]]++;
}	

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
	list<int> adj[n+1];
	int freq[n+1] = {0};
	
	for(int k = 0; k < dependencies.size(); k++) 
		adj[dependencies[k].first].push_back(dependencies[k].second);
	
	for(int k = 1; k <= n; k++)
		countDependents(k, n, adj, freq);
	
	if(freq[j] < i) return true; //if less dependents than i
	return false;
}
