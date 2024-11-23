#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

class Item {
public:
    string name;   
    int value;     
    int weight;    

    Item(string itemName, int itemValue, int itemWeight) 
        : name(itemName), value(itemValue), weight(itemWeight) {}

    Item() : name(""), value(0), weight(0) {}

    void printAttributes() const {
        printf("Name: %s, Value: %d, Weight: %d \n" ,name.c_str(), value, weight);
    }

};

tuple<int, Item* , int> knapsack_max(Item items[], int n , int capacity){
    vector<vector<int>> dp_table(n + 1, vector<int>(capacity + 1, 0)); //Initializing table with 0's


    for (int i = 1; i <= n; ++i) { //Traversing item
        for (int j = 1; j <= capacity; ++j) { //Traversing weight
            if (items[i - 1].weight <= j) { //If item weight is not bigger than capacity, check
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i - 1][j - items[i - 1].weight] + items[i - 1].value); //Compare the non included value with, included value + max value in the remaining weight, assign max of the two
            } else { //If capacity is smaller go on without including
                dp_table[i][j] = dp_table[i - 1][j];
            }
        }
    }
    
    // Tracing back to find the selected items
    int j = capacity;
    int num_items_in_sack = 0;
    Item* Selected_Items= new Item[n]; //Value to be returned
    for (int i = n; i > 0; --i) {
        if (dp_table[i][j] != dp_table[i - 1][j]) { //If not equal that means the Item i was included
            Selected_Items[num_items_in_sack] = items[i-1]; // Item i was included
            j = j - items[i - 1].weight; // Weight is updated
            num_items_in_sack += 1 ;
        }
    }

    return{dp_table[n][capacity], Selected_Items, num_items_in_sack}; //Return max value sack can contain, pointer to the beggining of the selected items array, and number of items in the sack
}

int main(){

Item items[8]={Item("A", 60, 10), Item("B", 100, 20), Item("C", 120, 30), Item("D", 80, 40), Item("E", 50, 5), Item("F", 140, 25), Item("G", 70, 15), Item("H", 30, 10)};

tuple result= knapsack_max(items, 8, 50);

printf("Maximum Value: %d \n", get<0>(result));

printf("Number of items in sack: %d \n", get<2>(result));

printf("Items in sack: \n");

Item* returned_items =get<1>(result);

for(int i=0; i < get<2>(result); i++){
    returned_items[i].printAttributes();
}
}