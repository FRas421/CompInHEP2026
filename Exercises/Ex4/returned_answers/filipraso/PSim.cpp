#include "PSim.h"
#include <ostream>

PSim::PSim() = default;
PSim::PSim(double px, double py, double pz, double E, int pid, int parentId) : Track(px, py, pz, E), pid_(pid), parentId_(parentId) {}

int PSim::pid() const {return pid_; }
int PSim::parentId() const { return parentId_; }

void PSim::print(std::ostream & os) const {
    os << "PSim(pid=" << pid_ << ", parentId=" << parentId_ << ", ";
    Track::print(os);
    os << ")";
}