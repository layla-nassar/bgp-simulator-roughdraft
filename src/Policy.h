#pragma once
#include "Announcement.h"

class Policy {
public:
    virtual bool accept(const Announcement&) = 0;
    virtual Announcement process(const Announcement&) = 0;
    virtual ~Policy() = default;
};
