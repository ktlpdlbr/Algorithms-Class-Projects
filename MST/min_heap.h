#ifndef min_heap_h
#define min_heap_h
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

int parent(int i);

int left(int i);

int right(int i);

void min_heapify(vector<Edge>& arr, int i);

int build_min_heap(vector<Edge>& arr);

void print_min_heap(vector<Edge> arr);

void min_heap_pop(vector<Edge>& arr);

void min_heap_push(vector<Edge>& heap, Edge edge);

#endif
