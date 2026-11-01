#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double ratio;   // value per unit weight
};

// Sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    Item items[100];   // fixed-size array (supports up to 100 items)

    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalValue = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum value in knapsack = " << totalValue << endl;
    return 0;
}