#include <iostream>
#include "Parser.h"
#include "Graph.h"
#include "Propagation.h"

using namespace std;

int main() {

    cout << "BGP Simulator starting..." << endl;

    Parser::load_graph("../datasets/bench/subprefix/ribs.csv");
    Parser::load_announcements("../datasets/bench/subprefix/anns.csv");

    cout << "Loaded AS graph with "
         << GLOBAL_GRAPH.as_map.size()
         << " ASes." << endl;

    cout << "Loaded "
         << GLOBAL_GRAPH.announcements.size()
         << " announcements." << endl;

    Propagation::run();

    return 0;
}
