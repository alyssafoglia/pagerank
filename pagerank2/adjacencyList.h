//
// Created by Alyssa Foglia on 7/16/21.
//

#ifndef PAGERANK2_ADJACENCYLIST_H
#define PAGERANK2_ADJACENCYLIST_H
#include <map>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;


class adjacencyList {
public:
    void makeGraph(string from, string to);
    void pageRank(int p);
    void printGraph();
    vector<float> getAdj(float vertex);
private:
    map<float, vector<float>> graph;
    map<string, float> URL; //names
    map<float, float> ranks;    //ranks
    map<float, float> outdegrees;   //outdegrees
};


#endif //PAGERANK2_ADJACENCYLIST_H
