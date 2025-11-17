#pragma once
#include <string>
#include <vector>

struct Route {
    int origin;                  // Origin ASN
    std::string prefix;          // Prefix being routed
    std::vector<int> as_path;    // AS path
    int local_pref = 0;          // Customer(2), Peer(1), Provider(0)
    bool rov_invalid = false;    // For ROV support (default false)
};
