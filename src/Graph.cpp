#include "Graph.h"

Graph GLOBAL_GRAPH;

AS* Graph::get_or_create(int asn) {
    if (!as_map.count(asn)) {
        as_map[asn] = new AS(asn);
    }
    return as_map[asn];
}

void Graph::add_relationship(int provider, int customer) {
    AS* p = get_or_create(provider);
    AS* c = get_or_create(customer);

    // Provider → Customer
    p->add_customer(c);

    // Customer → Provider
    c->add_provider(p);

    // Peer relationships are NOT defined here.
}
