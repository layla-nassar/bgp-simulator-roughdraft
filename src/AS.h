#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "Route.h"     // <-- REAL FIX

struct AS {
    int asn;

    std::vector<AS*> providers;
    std::vector<AS*> customers;
    std::vector<AS*> peers;
    std::vector<AS*> neighbors;

    std::unordered_map<std::string, Route> best_routes;

    AS(int a) : asn(a) {}

    void add_provider(AS* p) {
        providers.push_back(p);
        neighbors.push_back(p);
    }

    void add_customer(AS* c) {
        customers.push_back(c);
        neighbors.push_back(c);
    }

    void add_peer(AS* p) {
        peers.push_back(p);
        neighbors.push_back(p);
    }
};
