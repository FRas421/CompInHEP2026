#pragma once
#include <iosfwd>

class Track {
    public:
        Track();
        Track(double px, double py, double pz, double E);

        double px() const, py() const, pz() const, E() const;
        double pt() const, p() const, eta() const;

        void print(std::ostream & os) const;

    protected:
        double px_{0.0}, py_{0.0}, pz_{0.0}, E_{0.0};
    
};