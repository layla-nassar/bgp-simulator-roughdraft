#include "Parser.h"
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// =======================================================
// LOAD GRAPH (ribs.csv)
// =======================================================
void Parser::load_graph(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open graph file: " << filename << std::endl;
        return;
    }

    std::string line;
    bool first = true;

    while (std::getline(file, line)) {
        if (line.size() < 3) continue;

        if (first) {  
            first = false;   // skip header
            continue;
        }

        std::stringstream ss(line);
        std::string provider_str, customer_str;

        if (!std::getline(ss, provider_str, ',')) continue;
        if (!std::getline(ss, customer_str, ',')) continue;

        int provider = std::stoi(provider_str);
        int customer = std::stoi(customer_str);

        GLOBAL_GRAPH.add_relationship(provider, customer);
    }

    std::cout << "Finished loading graph." << std::endl;
}



// =======================================================
// LOAD ANNOUNCEMENTS (anns.csv)
// =======================================================
void Parser::load_announcements(const std::string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open announcement file: " << filename << endl;
        return;
    }

    string line;
    bool first = true;

    while (getline(file, line)) {
        if (line.size() < 3)
            continue;

        // Skip header (seed_asn,prefix,rov_invalid)
        if (first) {
            first = false;
            continue;
        }

        stringstream ss(line);
        string as_str, prefix_str, rov_str;

        if (!getline(ss, as_str, ',')) continue;
        if (!getline(ss, prefix_str, ',')) continue;
        if (!getline(ss, rov_str, ',')) continue;

        int asn = stoi(as_str);

        // "True", "False", "1", "0"
        bool rov_invalid = (rov_str == "True" || rov_str == "true" || rov_str == "1");

        // Your Announcement struct constructor MUST match this:
        GLOBAL_GRAPH.announcements.push_back(
            Announcement(asn, prefix_str, rov_invalid)
        );
    }

    cout << "Loaded " << GLOBAL_GRAPH.announcements.size()
         << " announcements." << endl;
}
