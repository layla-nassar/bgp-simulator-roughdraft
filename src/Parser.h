#pragma once
#include <string>

class Parser {
public:
    static void load_graph(const std::string &filename);
    static void load_announcements(const std::string &filename);
};
