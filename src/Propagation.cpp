#include "Propagation.h"
#include "Graph.h"
#include "BGP.h"
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

namespace Propagation {

void run() {
    cout << "Running propagation..." << endl;

    // For each announcement loaded from anns.csv
    for (auto& ann : GLOBAL_GRAPH.announcements) {

        int origin = ann.origin;

        if (!GLOBAL_GRAPH.as_map.count(origin)) {
            cout << "Warning: origin AS " << origin << " not in graph\n";
            continue;
        }

        AS* origin_as = GLOBAL_GRAPH.as_map[origin];

        queue<AS*> q;
        unordered_set<int> visited;

        q.push(origin_as);
        visited.insert(origin);

        while (!q.empty()) {
            AS* cur = q.front();
            q.pop();

            // Loop through neighbors
            for (AS* n : cur->neighbors) {

                // Step 4: BGP export filter
                if (!BGP::export_to(cur, n, ann))
                    continue;

                if (!visited.count(n->asn)) {
                    visited.insert(n->asn);
                    q.push(n);
                }
            }
        }

        cout << "Prefix " << ann.prefix
             << " from AS" << ann.origin
             << " reached " << visited.size()
             << " ASes.\n";
    }

    cout << "Propagation finished.\n";
}

} // namespace Propagation
