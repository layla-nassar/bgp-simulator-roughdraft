#include "ROV.h"
#include "Graph.h"
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iostream>

static std::unordered_set<int> ROV_ENABLED;

// Load ROV-enabled AS numbers from CSV: single column "asn"
void ROV::load_rov_asns(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open ROV ASN file: " << filename << "\n";
        return;
    }

    std::string line;
    bool first = true;

    while (std::getline(file, line)) {

        if (line.size() < 1)
            continue;

        // Skip header
        if (first) {
            first = false;
            continue;
        }

        int asn = std::stoi(line);
        ROV_ENABLED.insert(asn);
    }

    std::cout << "Loaded " << ROV_ENABLED.size()
              << " ROV-enabled ASNs.\n";
}

bool ROV::is_rov_asn(int asn) {
    return ROV_ENABLED.count(asn) != 0;
}

// Core ROV logic
bool ROV::validate(const Announcement& ann, const AS* receiver) {

    // If receiver does NOT enforce ROV, always accept
    if (!is_rov_asn(receiver->asn))
        return true;

    // If receiver enforces ROV:
    // reject the announcement if its origin is invalid
    if (ann.rov_invalid) {
        // ROV filter applied
        return false;
    }

    // Otherwise valid
    return true;
}
