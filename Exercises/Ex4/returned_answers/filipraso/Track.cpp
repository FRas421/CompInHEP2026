#include "Track.h"
#include <cmath>
#include <stdexcept>
#include <ostream>

Track::Track() = default;
Track::Track(double px, double py, double pz, double E) : px_(px), py_(py), pz_(pz), E_(E) {}

double Track::px() const { return px_; }
double Track::py() const { return py_; }
double Track::pz() const { return pz_; }
double Track::E() const { return E_; }
double Track::pt() const { return std::hypot(px_, py_); }
double Track::p() const { return std::sqrt(px_*px_ + py_*py_ + pz_*pz_); }
double Track::eta() const {
    if (p() - pz_ <= 0.0) {
        if (pz_ > 0) return std::numeric_limits<double>::infinity();
        if (pz_ < 0) return -std::numeric_limits<double>::infinity();
        throw std::runtime_error("Eta is NA for 0 momentum");
    }
    return 0.5 * std::log((p()+pz_)/(p()-pz_));

}

void Track::print(std::ostream & os) const {
    os << "Track(px=" << px_ << ", py=" << py_ << ", pz_=" << pz_ << ", E=" << E_ << ", pt=" << pt() << ", eta=" << eta() << ")";
}

