#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Edge{
    public:
     //Public variables
        std::string name;
        int vertex1;
        int vertex2;
        int weight;

        //Constructor
        Edge(const std::string& name, int vertex1, int vertex2, int weight): name(name), vertex1(vertex1), vertex2(vertex2), weight(weight) {}
        
        //Default Constructor
        Edge() : name("Unknown"), vertex1(0), vertex2(0), weight(0){}
        
        //Display person information
        void display() const{
            printf("(%s, vertex1:%d, vertex2:%d, weight:%d) \n ", name.c_str(), vertex1, vertex2, weight);
        }
};

//problem with indexing... we start with 0 not 1
int parent(int i){
    return i/2 ;
}

int left(int i){
    return 2*i ;
}

int right(int i){
    return (2*i)+1 ;
}



//this function should return max of an array using heap structure with logn complexity
void min_heapify(vector<Edge>& arr, int i){

    Edge node_i= arr[i-1];
    std::string node_i_name= arr[i-1].name;
    int left_child= left(i);
    int right_child= right(i);


    int min= i;

    
    if (left_child<= arr.size() && arr[left_child-1].weight< arr[min-1].weight){
        min= left_child;
    }

    if (right_child<= arr.size() && arr[right_child-1].weight< arr[min-1].weight){
        min= right_child;
    }

    if (min!=i){
        arr[i-1]= arr[min-1];
        arr[min-1]= node_i;
        min_heapify(arr, min);
    }
    
}

/* This function will generate min_heap
and return first (max) of heap */
int build_min_heap(vector<Edge>& arr){
    for(int i=(arr.size()/2); i>0; i--){
        min_heapify(arr, i);
    }

    return arr[0].weight;
}

void print_min_heap(vector<Edge> arr){
    for (int i = 0; i < arr.size(); ++i){
        arr[i].display();
    } 
}

void min_heap_pop(vector<Edge>& arr){
    if (arr.size()<=0) return;

    arr[0]=arr[arr.size()-1];
    arr.resize(arr.size()-1);
    min_heapify(arr, 1);
}

void min_heap_push(vector<Edge>& arr, Edge edge) {
 
    arr.push_back(edge); // add to the end 

    //heapify
    int index = arr.size() - 1; // index of the newly added element
    while (index > 0) {
        int parent = (index - 1) / 2; // parent index

        // if the parent is smaller or equal, the heap property is satisfied
        if (arr[parent].weight <= arr[index].weight) 
            break;

        swap(arr[parent], arr[index]); // swap the parent and child

        index = parent; // move up the heap
    }
}


/*
int main(){
    
    int numEdges = 14;

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

    vector<Edge> adj[numVertices];

    for (int i=0; i<numEdges; i++){
        int vert1= edges[i].vertex1;
        int vert2= edges[i].vertex2;
        int weight= edges[i].weight;
        adj[vert1].push_back(edges[i]);
        adj[vert2].push_back(edges[i]);
    }




    build_min_heap(edges);

    print_min_heap(edges);

    min_heap_pop(edges);
    printf("\n");
    print_min_heap(edges);

      min_heap_pop(edges);
    printf("\n");
    print_min_heap(edges);

      min_heap_pop(edges);
    printf("\n");
    print_min_heap(edges);

    min_heap_push(edges, Edge("Z",0,3,0));
    printf("\n");
    print_min_heap(edges);
}
*/