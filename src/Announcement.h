#pragma once
#include <string>
#include <vector>

struct Announcement {
    int origin;
    std::string prefix;
    std::vector<int> as_path;
    int as_path_len;
    bool rov_invalid;

    Announcement(int origin,
                 const std::string &prefix,
                 bool rov_invalid)
        : origin(origin),
          prefix(prefix),
          as_path(),
          as_path_len(0),
          rov_invalid(rov_invalid)
    {}
};
