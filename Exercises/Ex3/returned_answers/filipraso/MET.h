#ifndef MET_H
#define MET_H

#include <cmath>

class MET {
    public:
        MET(double met_x = 0.0, double met_y = 0.0);

        void set(double met_x, double met_y);
        void add(double dx, double dy);

        double x() const, y() const, value() const, phi() const;
    
    private:
        double met_x_, met_y_;

};

#endif