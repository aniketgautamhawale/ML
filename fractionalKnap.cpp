#include <bits/stdc++.h>
using namespace std;


struct Item{
    int value, weight;
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool compare(Item a, Item b){
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}

void fracKnap(Item arr[], int n, int W){
    sort(arr, arr+n, compare);
    double maxProfit = 0.0;
    for (int i = 0; i < n; i++){
        if (arr[i].weight <= W){
            W -= arr[i].weight;
            maxProfit += arr[i].value;
        }
        else{
            maxProfit += arr[i].value * ((double) W / (double) arr[i].weight);
            break;
        }
    }
    cout << maxProfit << endl;
}


int main(){
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(arr)/sizeof(arr[0]);
    fracKnap(arr, n, W);
    return 0;
}