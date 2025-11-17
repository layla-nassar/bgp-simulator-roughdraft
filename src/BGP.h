#pragma once
#include "Announcement.h"
#include "AS.h"

namespace BGP {

    // Step 3 — basic inbound policy (accept everything for now)
    bool accept(const Announcement& a);

    // Step 4 — export filtering rules
    bool export_to(AS* from, AS* to, const Announcement& a);

    // Step 5 — best path selection (placeholder for now)
    Announcement process(const Announcement& a);
}
