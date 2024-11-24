#include <stdio.h>
#include <cstdlib>
#include <chrono>

/*
merge(int max1, int max2):Merge algorithm
simply comparing two elements and returning
bigger one. 
*/
int merge(int max1, int max2){
    
    if(max1>=max2){
        return max1;
    }
    else{
        return max2;
    }
    
    
}

/*
find_max(int arr[], int size): Divide and Conquer Algorithm 
which at first divides the array until only one element 
is left in an array (base case) and then using merge, 
returns max of these elements by comparing two. 
*/
int find_max(int arr[], int size){
    
    if (size==1){
        return arr[0];
    }
    int half_size= size/2;
    int residual;
    
    /*
    This residual part is to ensure 
    correctness of the function when 
    an array with odd number of elements
    given as input. By adding one residual
    unit to the second array we make sure
    the division by two is achieved without
     missing an element.
    */
    if(size%2==0){
        residual=0;
    }
    else{ 
        residual=1;
    }

    //Recursive function calls
    int max1=find_max(arr, half_size);
    int max2=find_max(arr+half_size, (half_size+residual));
    
    //Merging the results of recursive calls
    return merge(max1,max2);
}


/*
Straightforward algorithm to find maximum by iteration. 
Used to check functionality of Divide and Conquer algorithm
*/
int classic_find_max(int arr[], int size){
    int max=arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}


int main(){

std::srand(static_cast<unsigned int>(std::time(0)));

//Generation of 3 random arrays with 10,100,1000 elements
int arr1[10];
for(int i=0; i<10; i++){
    arr1[i]=rand();
}

int arr2[100];
for(int i=0; i<100; i++){
    arr2[i]=rand();
}

int arr3[1000];
for(int i=0; i<1000; i++){
    arr3[i]=rand();
}

//Returning maximum and analyzing running time execution of classical algorithm:
auto start=std::chrono::high_resolution_clock::now();
int output_classic_10=classic_find_max(arr1,10);
auto stop=std::chrono::high_resolution_clock::now();

auto duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output_classic_10); 
printf("Duration of classic algorithm for length 10: %ld nanoseconds", duration);

start=std::chrono::high_resolution_clock::now();
int output_classic_100=classic_find_max(arr2,100);
stop=std::chrono::high_resolution_clock::now();

duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output_classic_100);
printf("Duration of classic algorithm for length 100: %ld nanoseconds", duration);

start=std::chrono::high_resolution_clock::now();
int output_classic_1000=classic_find_max(arr3,1000);
stop=std::chrono::high_resolution_clock::now();

duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output_classic_1000);
printf("Duration of classic algorithm for length 1000: %ld nanoseconds\n", duration);

//Returning maximum and analyzing running time execution of divide and conquer algorithm:
start=std::chrono::high_resolution_clock::now();
int output10=find_max(arr1,10);
stop=std::chrono::high_resolution_clock::now();

duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output10);
printf("Duration of divide_conquer algorithm for length 10: %ld nanoseconds", duration);

start=std::chrono::high_resolution_clock::now();
int output100=find_max(arr2,100);
stop=std::chrono::high_resolution_clock::now();

duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output100);
printf("Duration of divide_conquer algorithm for length 100: %ld nanoseconds", duration);

start=std::chrono::high_resolution_clock::now();
int output1000=find_max(arr3,1000);
stop=std::chrono::high_resolution_clock::now();

duration =std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

printf("\n%d, ",output1000);
printf("Duration of divide_conquer algorithm for length 1000: %ld nanoseconds\n", duration);
}