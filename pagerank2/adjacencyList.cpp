//
// Created by Alyssa Foglia on 7/16/21.
//

#include "adjacencyList.h"

/**
 * make the adjacency list/graph by inserting each edge that is submitted
 * @param from
 * @param to
 */
void adjacencyList::makeGraph(string from, string to) {
    //add to and from to name map, int is the index/position
    if(URL.find(to) == URL.end()) {
        int index = URL.size();
        URL[to] = index;
    }
    if(URL.find(from) == URL.end()) {
        int index = URL.size();
        URL[from] = index;
    }

    //gets index of each url
    float toVal = URL[to];
    float fromVal = URL[from];
    graph[fromVal].push_back(toVal);

    if (outdegrees.find(fromVal) == outdegrees.end()) { //add to the outdegree map for from
        outdegrees[fromVal] = 1;
    }
    else {
        outdegrees[fromVal]++;
    }


    if (outdegrees.find(toVal) == outdegrees.end()) {   //add to the outdegree map for to
        outdegrees[toVal] = 0;
    }
    if (graph.find(toVal) == graph.end()) {     //initialize to
        graph[toVal] = {};
    }


    //initializes the rank for every value to 1/v, or 1/(number of nodes)
    for (auto iter = URL.begin(); iter != URL.end(); iter++) {
        ranks[iter->second] = 1.0 / (float)URL.size();
    }
}


/**
 * Calculate the new rank. Call recursively, decreasing p by one. Make the new rank into a map.
 * @param p
 */
void adjacencyList::pageRank(int p) {
    map<float, float> newRank;    //map to keep track of new rank

    if (p == 1) {       //base condition, rank is just 1/v
        return;
    }

    //iterate through the map of names, get adjacent vals
    for (auto iterator = URL.begin(); iterator != URL.end(); iterator++){
        vector<float> adjacentvals = getAdj(iterator->second);    //get the adjacent vertices to this vertex
        for (unsigned int i = 0; i < adjacentvals.size(); i++) {

            if (newRank.find(adjacentvals.at(i)) == newRank.end()) {    //initialize the rank
                newRank[adjacentvals.at(i)] = 0;
            }
            //add the new rank value to the new rank map
            //new rank = previous rank/ outdegree
            newRank[adjacentvals.at(i)] += ranks[iterator->second] * 1.0 / outdegrees[iterator->second];
        }
    }

    ranks = newRank;    //have ranks=newranks
    pageRank(p-1);   //recursively call function lowering value of p
}

/**
 * return a vector of integers that are the adjacent values
 * @param vertex
 * @return
 */
vector<float> adjacencyList::getAdj(float index) {
    vector<float> returnval = graph[index];
    return returnval;
}

/**
 * print graph, round to 2 decimal places, use setprecision
 */
void adjacencyList::printGraph() {
    for (auto iterator = URL.begin(); iterator != URL.end(); iterator++) {
        cout << iterator->first << " ";
        cout << fixed << showpoint << setprecision(2) << ranks[iterator->second] << endl;
    }
}