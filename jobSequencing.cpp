#include <bits/stdc++.h>
using namespace std;


struct Job{
    char id;
    int dead;
    int profit;
};

bool compare(Job a, Job b){
    return (a.profit > b.profit);
}

void jobSchedule(Job arr[], int n){
    sort(arr, arr+n, compare);
    int result[n];
    int slot[n];
    for(int i=0; i<n; i++){
        slot[i] = false;
    }
    for (int i = 0; i < n; i++){
        for (int j = min(n, arr[i].dead)-1; j >= 0; j--){
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n-1; i++){
        if (slot[i]) cout << arr[result[i]].id << "-->"; 
    }
}

// {'a', 2, 20}, {'b', 2, 15}, {'c', 1, 10},{'d', 3, 5}, {'e', 3, 1}}
int main(){
    Job arr[] = {{'a', 2, 20}, {'b', 2, 15}, {'c', 1, 10},{'d', 3, 5}, {'e', 3, 1}};
    jobSchedule(arr, 5);
    return 0;
}