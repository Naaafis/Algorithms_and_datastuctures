#include "job.h"
#include <iostream>
#include <string>
//#include <queue>
#include <vector>

using namespace std;

//int depthfirstsearch(vector<vector<int> > &adj_matrix, vector<vector<int> > &white_matrix, vector<vector<int> > &grey_matrix, vector<vector<int> > &black_matrix, int i, int j) {
int depthfirstsearch(vector<vector<int>> &list, vector<bool> &white, vector<bool> &grey, vector<bool> &black, int index){
// true means no cycle was detected, false means cycle has been detected

    if(black[index] == 1){ // if index had been finished being visited just return true
        return true; // this probably won't run in most cases;
    }

    if(grey[index] == 1){ // if the index being visited was already being visited there is a cycle 
        return false; // this will help every recursive funtion be false, thus making canFinish false
    }
    
    white[index] = 0; // being visited so no longer white
    grey[index] = 1; // visiting

    for(auto valuein:list[index]){ // run depthfirstsearch on the value of index (its dependent) 
        if(!depthfirstsearch(list, white, grey, black, valuein)){ // if an index is a part of cycle this will run
            return false; 
        }
    }

    grey[index] = 0; // reaching this point means the index has finished being visited and all its edges are not back edges
    black[index] = 1; // mark the index as visited
    return true; 
}


bool canFinish(int n, vector<pair<int, int> > &dependencies) {

    //attempted to use adjacency matrix:

    //vector<vector<int> > adj_matrix(n + 1, std::vector<int>(n + 1, 0));
    //vector<vector<int> > WGB_matrix(n + 1, std::vector<int>(n + 1, 0)); //populate a whitegrey and black matrix with 0s
    //later, white will represent unvisited edges as 1, grey will represent visiting edges as 2, black will represent visited edges as 3
    //vector<vector<int> > grey_matrix(n + 1, std::vector<int>(n + 1, 0));
    //vector<vector<int> > black_matrix(n + 1, std::vector<int>(n + 1, 0));

    vector<vector<int>> adj_list(n+1); // initializing adjacency list 

    //for (int i = 0; i < dependencies.size(); i++){
    //    adj_matrix[dependencies[i].first][dependencies[i].second] = 1;
    //      white_matrix[dependencies[i].first][dependencies[i].second] = 1;
    //}

    for(int i = 0;i < dependencies.size();i++){ // hold dependee as an index and dependent as its value
        adj_list[dependencies[i].first].push_back(dependencies[i].second); 
    }

    //queue<int> white;

    vector<bool> white(n+1, 1); // to begin every index up to the size of the list is set to white
    vector<bool> grey(n+1, 0); // nothing is grey yet
    vector<bool> black(n+1, 0); // nothing is black yet

    for(int i = 0; i < n; i++){
        if(white[i] == 1){ // for every white index run depthfirstsearch and turn it black
            if(!depthfirstsearch(adj_list, white, grey, black, i)){ // if an index is a part of cycle this will run
                return false;
            }
        }
    }

    return true; // reaching here means the function indeed CanFinish

    /*
    for(int row = 0; row < n + 1; row ++){
        for(int column = 0; column < n + 1; column++){
            if(adj_matrix[row][column] == 1){
                cout << "1" << " at" << " " << row << " " << column << endl;
            }
        }
    }

    cout << endl;

    for (auto vec : adj_matrix)
    {
        cout << "row?: " << endl;
        for (auto x : vec)
            std::cout << x << " ";
        std::cout << std::endl;
    }
    */
}

//int counter = 0;
//int counter2 = 0;
//vector<int> dependencies;
/*
void search(int n, vector<vector<int>> &adj_matrix, vector<bool> &dependencies_list, int nextdepen){
    //if(std::find(dependencies.begin(), dependencies.end(), nextdepen) == 0){
    //    cout << "not found " << endl;
    //    dependencies.push_back(nextdepen);
    //    counter++;
    //}

    //counter++;

    for(int row = 0; row < n + 1; row ++){
        for(int column = 0; column < n + 1; column++){
            if(adj_matrix[row][column] == 1){
                // cout << "1" << " at" << " " << row << " " << column << endl;
                if(column == nextdepen){
                    dependencies_list[row] = 1;
                    search(n, adj_matrix, dependencies_list, row);
                }
            }
        }
    }
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {


    vector<vector<int> > adj_matrix(n + 1, std::vector<int>(n + 1, 0));


    for (int i = 0; i < dependencies.size(); i++){
        adj_matrix[dependencies[i].first][dependencies[i].second] = 1;
    }


    vector<bool> dependencies_list(n + 1, 0);
    
    
    for(int row = 0; row < n + 1; row ++){
        for(int column = 0; column < n + 1; column++){
            if(adj_matrix[row][column] == 1){
                // cout << "1" << " at" << " " << row << " " << column << endl;
                if(column == j){
                    dependencies_list[row] = 1;
                    search(n, adj_matrix, dependencies_list, row);
                }
            }
        }
    }

    int counter = 1;

    for (int k = 0; k < dependencies_list.size(); k++){
        if (dependencies_list[k] == 1){
            counter++;
        }
    }

    if (i >= counter)
        return true;
    else
        return false;
}

*/

void search(int n, vector<vector<int>> &adj_list, vector<bool> &dependencies_list, int nextdepen){
    for (int index = 0; index < n; index++)
    {
        for (auto valuein : adj_list[index])
        {
            if (valuein == nextdepen)
            {
                dependencies_list[index] = 1;
                search(n, adj_list, dependencies_list, index);
            }
        }
    }
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {

    vector<vector<int>> adj_list(n + 1); // initializing adjacency list

    for (int i = 0; i < dependencies.size(); i++){ // hold dependee as an index and dependent as its value
        adj_list[dependencies[i].first].push_back(dependencies[i].second);
    }

    vector<bool> dependencies_list(n + 1, 0);

    for(int index = 0; index < n; index++){
        for(auto valuein: adj_list[index]){
            if(valuein == j){
                dependencies_list[index] = 1;
                search(n, adj_list, dependencies_list, index);
            }
        }
    }

    int counter = 1;

    for (int k = 0; k < dependencies_list.size(); k++)
    {
        if (dependencies_list[k] == 1)
        {
            counter++;
        }
    }

    if(i >= counter) return true;
    else return false;
}
