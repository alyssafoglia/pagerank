
#include <iostream>
using namespace std;
#include "adjacencyList.h"

int main() {

    //class object
    adjacencyList a;

    //read in the number of lines and power iterations
    int numlines, PI;
    cin >> numlines >> PI;
    string from, to;
    //create graph with the from and to edges
    for (int i = 0; i < numlines; i++) {
        cin >> from >> to;
        a.makeGraph(from, to);
    }

    a.pageRank(PI); //page rank calculation
    a.printGraph(); //print graph

    return 0;
}
