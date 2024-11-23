#include <stdio.h>
#include <cstdlib>
#include <chrono>


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



void max_heapify(int arr[], int i, int size){ //i is the node we want to max_heapify

    int node_i= arr[i-1]; //getting node_i
    
    int left_child= left(i);
    int right_child= right(i);

    int largest= i; //first assume i is largest

    
    if (left_child<= size && arr[left_child-1]> arr[largest-1]){ //checking whether left_child of node_i is bigger
        largest= left_child; //if true assign left_child as largest
    }

    if (right_child<= size && arr[right_child-1]> arr[largest-1]){ //checking whether right_child is bigger than largest
        largest= right_child; //if true assign right_child as largest
    }

    if (largest!=i){ //swap values if largest has changed 
        arr[i-1]= arr[largest-1]; //copy largest in place of node_i
        arr[largest-1]= node_i; //assign node_i to the placeof largest
        max_heapify(arr, largest, size); //recursive call to max_heapify the changed leaf nodes
    }
    
}

int build_max_heap(int arr[], int size){ 
    for(int i=(size/2); i>0; i--){
        max_heapify(arr, i, size); //max_heapify starts from the leafs to root node to build a max_heap
    }

    return arr[0]; //returning maximum value, which is the root
}

int main(){
    int Arr[5]={10,14,100,1110,290};

    int res= build_max_heap(Arr,5);

    printf("%d",res);
    
}