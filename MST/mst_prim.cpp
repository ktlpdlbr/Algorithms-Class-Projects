#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "min_heap.h"
using namespace std;

std::pair<int, std::vector<Edge>> MST_Prim(int numVertices, vector<Edge>& edges){

    int MST_weight=0;
    
    vector<int> visited(numVertices, false);

    vector<vector<Edge>> adj(numVertices);
    vector<Edge> min_heap;
    vector<Edge> SpanningTree;

    for (int i=0; i<edges.size(); i++){ //creating an vector to store edges of the vertexes
        int vert1= edges[i].vertex1;
        int vert2= edges[i].vertex2;
        adj[vert1].push_back(edges[i]);
        adj[vert2].push_back(edges[i]);
    }

    //start with vertice 0
    for(auto v : adj[1]){
        min_heap_push(min_heap, v);  // add the adjacent edges to the min_heap
    }
    visited[1]=true;
    
    int new_vertex;

    while(min_heap.size()!=0){ //size 0 means there is no more vertexes to be connected
        Edge min_weight_edge=min_heap[0]; //minimum weight edge is acquired
        min_heap_pop(min_heap); //get rid of the edge in queue

        if(visited[min_weight_edge.vertex1] && visited[min_weight_edge.vertex2]){ //if vertices are visited, continue loop
            continue;
        }

        if(visited[min_weight_edge.vertex1]==false){ //choosing which vertex is the new vertex
            new_vertex=min_weight_edge.vertex1;   
        }
        else new_vertex=min_weight_edge.vertex2;

        MST_weight += min_weight_edge.weight; //add weight to the extended tree
        min_weight_edge.display();
        SpanningTree.push_back(min_weight_edge); //add edge to the vector to return
        visited[new_vertex]=true; //vertex is now included in the visited set
        
        for(auto e : adj[new_vertex]){ //check each edge of the new vertex
            if((visited[e.vertex1] && visited[e.vertex2])  == false){ //if there is an unvisited vertex 
                min_heap_push(min_heap, e); //add that to the min_heap
            }    
        }

        

    }

    return {MST_weight, SpanningTree};
}

int main(){

    int numVertices = 9;

    vector<Edge> edges= {
        Edge("A", 0, 1, 4),
        Edge("B", 0, 7, 8),
        Edge("C", 1, 2, 8),
        Edge("D", 1, 7, 11),
        Edge("E", 2, 3, 7),
        Edge("F", 2, 8, 2),
        Edge("G", 2, 5, 4),
        Edge("H", 3, 4, 9),
        Edge("I", 3, 5, 14),
        Edge("J", 4, 5, 10),
        Edge("K", 5, 6, 2),
        Edge("L", 6, 7, 1),
        Edge("M", 6, 8, 6),
        Edge("N", 7, 8, 7)
    };

    vector<Edge> edges1 = {
    Edge("A", 0, 1, 3),
    Edge("B", 0, 2, 1),
    Edge("C", 1, 3, 4),
    Edge("D", 1, 4, 6),
    Edge("E", 2, 3, 5),
    Edge("F", 2, 5, 2),
    Edge("G", 3, 4, 8),
    Edge("H", 3, 6, 7),
    Edge("I", 4, 6, 3),
    Edge("J", 5, 6, 4),
    Edge("K", 5, 7, 1),
    Edge("L", 6, 7, 2)
};

    vector<Edge> edges2 = {
    Edge("A", 0, 1, 6),
    Edge("B", 0, 2, 3),
    Edge("C", 0, 3, 7),
    Edge("D", 1, 3, 9),
    Edge("E", 1, 4, 5),
    Edge("F", 2, 3, 4),
    Edge("G", 2, 5, 2),
    Edge("H", 3, 4, 8),
    Edge("I", 3, 5, 6),
    Edge("J", 4, 6, 7),
    Edge("K", 5, 6, 3),
    Edge("L", 5, 7, 4),
    Edge("M", 6, 7, 5),
    Edge("N", 7, 8, 1),
    Edge("O", 6, 8, 9)
};

    auto result= MST_Prim(numVertices, edges2);

    int mst_weight= result.first;

    vector<Edge> SpanningTree= result.second;

    printf("MST Weight: %d \n", mst_weight);

    print_min_heap(SpanningTree);

    
}

