#include "BGP.h"
#include <iostream>

bool BGP::accept(const Announcement& a) {
    // For now, accept every announcement
    return true;
}

// STEP 4 — EXPORT FILTER RULES
bool BGP::export_to(AS* from, AS* to, const Announcement& a) {

    // CUSTOMER → anyone: always allowed
    for (AS* c : from->customers)
        if (c == to) return true;

    // PEER → only to customers
    for (AS* p : from->peers)
        if (p == to) {
            // We only export peer-learned routes to customers
            return false;  
        }

    // PROVIDER → only to customers
    for (AS* pr : from->providers)
        if (pr == to) {
            // Providers only export to their customers (valley free)
            return false;
        }

    // Default allow if none applied
    return true;
}

// STEP 5 — PROCESS ANNOUNCEMENT (for now just return same)
Announcement BGP::process(const Announcement& a) {
    return a;
}
