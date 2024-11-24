#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <string>
#include <vector>
#include <ctime>

std::string generateRandomName() {
    const std::vector<std::string> firstNames = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivan", "Judy",
        "Kevin", "Laura", "Mike", "Nina", "Oscar", "Paul", "Quinn", "Rachel", "Sam", "Tina",
        "Uma", "Victor", "Wendy", "Xander", "Yara", "Zach", "Aaron", "Bella", "Carl", "Dana",
        "Eli", "Fiona", "George", "Helen", "Isaac", "Jenny", "Kyle", "Lena", "Mark", "Nora",
        "Olivia", "Peter", "Quincy", "Rita", "Steve", "Tracy", "Ursula", "Vince", "Whitney", "Xenia"
    };
    
    const std::vector<std::string> lastNames = {
        "Smith", "Johnson", "Brown", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin",
        "Thompson", "Garcia", "Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall",
        "Allen", "Young", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores", "Green",
        "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", "Carter", "Roberts", "Gomez",
        "Phillips", "Evans", "Turner", "Diaz", "Parker", "Cruz", "Edwards", "Collins", "Reyes", "Stewart"
    };

    // Randomly select a first name and a last name
    std::string firstName = firstNames[rand() % firstNames.size()];
    std::string lastName = lastNames[rand() % lastNames.size()];

    return firstName + " " + lastName;
}

class Person {
    public:
        //Public variables
        std::string name;
        int age;

        //Constructor
        Person(const std::string& name, int age): name(name), age(age) {}

        //Default Constructor
        Person() : name("Unknown"), age(0){}

        //Display person information
        void display() const{
            printf("(%s, %d), ", name.c_str(), age);
        }
};

//problem with this indexing... we start with 0 not 1
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
void max_heapify(Person arr[], int i, int size){

    int node_i= arr[i-1].age;
    std::string node_i_name= arr[i-1].name;
    int left_child= left(i);
    int right_child= right(i);


    int largest= i;

    
    if (left_child<= size && arr[left_child-1].age> arr[largest-1].age){
        largest= left_child;
    }

    if (right_child<= size && arr[right_child-1].age> arr[largest-1].age){
        largest= right_child;
    }

    if (largest!=i){
        arr[i-1].age= arr[largest-1].age;
        arr[i-1].name= arr[largest-1].name;
        arr[largest-1].age= node_i;
        arr[largest-1].name= node_i_name;
        max_heapify(arr, largest, size);
    }
    
}

/* This function will generate max_heap
and return first (max) of heap */
int build_max_heap(Person arr[], int size){
    for(int i=(size/2); i>0; i--){
        max_heapify(arr, i, size);
    }

    return arr[0].age;
}


//sorting by O(n) using count sort
Person* count_sort(Person arr[], int size, int max_val){
    Person* B= new Person[size+1];
    Person C[max_val+1];

    /*for(int i=0; i<max_val+1; i++){
        C[i].age=0;   
    }*/

    for(int i=0; i<size; i++){
        C[arr[i].age].age=C[arr[i].age].age+1;   
    }

    for(int i=1; i<max_val+1; i++){
        C[i].age=C[i].age+C[i-1].age;
    }

    for(int i=size-1; i>=0; i--){
        B[C[arr[i].age].age].age=arr[i].age;
        B[C[arr[i].age].age].name=arr[i].name;
        C[arr[i].age].age=C[arr[i].age].age-1;
    }

    return B+1;

}

int main(){
    
    int numPeople = 4;
    
    Person people[numPeople] = {
        Person("Alice", 25),
        Person("Bob", 32),
        Person("Charlie", 25),
        Person("David", 40)
    };

    /*int max_age= build_max_heap(people,numPeople);
    for(int i=0; i<numPeople; i++){
        //printf("%s, %d\n",B[i].name,B[i].age);
        people[i].display();
    }
    printf("\n%d\n",max_age);

    Person* B=count_sort(people,4,max_age);

    for(int i=0; i<numPeople; i++){
        //printf("%s, %d\n",B[i].name,B[i].age);
        B[i].display();
    }*/

    std::srand(static_cast<unsigned int>(std::time(0)));
    
    std::string names_1[10];
    std::string names_2[100];
    std::string names_3[1000];
    int ages_1[10];
    int ages_2[100];
    int ages_3[1000];
    Person people_1[10];
    Person people_2[100];
    Person people_3[1000];

    for(int i=0; i<10; i++){
        //ages_1[i]=rand()%151;
        //names_1[i]=generateRandomName();
        people_1[i].name=generateRandomName();
        people_1[i].age=rand()%151;
    }

    
    for(int i=0; i<100; i++){
        //ages_2[i]=rand()%151;
        //names_2[i]=generateRandomName();
        people_2[i].name=generateRandomName();
        people_2[i].age=rand()%151;
    }

    for(int i=0; i<1000; i++){
        //ages_3[i]=rand()%151;
        //names_3[i]=generateRandomName();
        people_3[i].name=generateRandomName();
        people_3[i].age=rand()%151;
    }

    for(int i=0; i<10; i++){
    people_1[i].display();
    }

    int max_age_1= build_max_heap(people_1,10);
    int max_age_2= build_max_heap(people_2,100);
    int max_age_3= build_max_heap(people_3,1000);
    printf("\n%d\n",max_age_1);
    printf("\n%d\n",max_age_2);
    printf("\n%d\n",max_age_3);
    Person* A=count_sort(people_1,10,max_age_1);
    Person* B=count_sort(people_2,100,max_age_2);
    Person* C=count_sort(people_3,1000,max_age_3);

    for(int i=0; i<10; i++){
        //printf("%s, %d\n",B[i].name,B[i].age);
        A[i].display();
    }

    /*for(int i=0; i<100; i++){
        //printf("%s, %d\n",B[i].name,B[i].age);
        B[i].display();
    }*/

    /*for(int i=0; i<1000; i++){
        //printf("%s, %d\n",B[i].name,B[i].age);
        C[i].display();
    }*/


}