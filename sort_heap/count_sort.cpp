#include <stdio.h>
#include <cstdlib>
#include <chrono>

int* count_sort(int arr[], int size, int max_val){
    int* B= new int[size]; //array to be returned
    int C[max_val+1]; //array to count how many of which number is present

    for(int i=0; i<max_val+1; i++){
        C[i]=0; //initiliaze count of numbers as 0
    }

    for(int i=0; i<size; i++){
        C[arr[i]]=C[arr[i]]+1; //count of occurences of a number     
    }

    for(int i=1; i<max_val+1; i++){
        C[i]=C[i]+C[i-1]; //adding with the previous number of elements so index is found
    }

    for(int i=size-1; i>=0; i--){
        B[C[arr[i]]]=arr[i]; //assigning elements to their sorted places
        C[arr[i]]=C[arr[i]]-1; //decrementing the count when an element is placed 
    }
    
    return B+1; //returning sorted array

}

int main(){

    int arr[6]={19,0,14,12,13,16};

    int* B=count_sort(arr,6,19);

    for(int i=0; i<6; i++){
        printf("%d \n",B[i]);
    }

}