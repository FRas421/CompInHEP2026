#pragma once
#include "Track.h"
#include <iosfwd>

class PSim : public Track {
    public:
        PSim();
        PSim(double px, double py, double pz, double E, int pid, int parentId);

        int pid() const;
        int parentId() const;
        void print(std::ostream & os) const;

    private:
        int pid_{0};
        int parentId_{-1};
};