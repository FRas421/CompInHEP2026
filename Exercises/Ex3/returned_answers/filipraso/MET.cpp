#include "MET.h"

MET::MET(double met_x, double met_y)
    : met_x_(met_x), met_y_(met_y) {}

void MET::set(double met_x, double met_y) {
    met_x_ = met_x;
    met_y_ = met_y;
}

void MET::add(double dx, double dy) {
    met_x_ += dx;
    met_y_ += dy;
}

double MET::x() const {
    return met_x_;
}

double MET::y() const {
    return met_y_;
}

double MET::value() const {
    return std::sqrt(met_x_ * met_x_ + met_y_ * met_y_);    
}

double MET::phi() const {
    return std::atan2(met_y_, met_x_);
}
