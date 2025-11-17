#pragma once
#include <unordered_map>
#include <vector>
#include "AS.h"
#include "Announcement.h"

struct Graph {
    std::unordered_map<int, AS*> as_map;
    std::vector<Announcement> announcements;

    AS* get_or_create(int asn);
    void add_relationship(int provider, int customer);
};

extern Graph GLOBAL_GRAPH;
