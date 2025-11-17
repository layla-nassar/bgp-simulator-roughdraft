#pragma once
#include "Announcement.h"
#include "AS.h"

namespace ROV {

    // Returns true if the AS accepts the announcement
    bool validate(const Announcement& ann, const AS* receiver);

    // Load list of ROV-enabled ASNs
    void load_rov_asns(const std::string& filename);

    // Check if an AS enforces ROV
    bool is_rov_asn(int asn);

}
