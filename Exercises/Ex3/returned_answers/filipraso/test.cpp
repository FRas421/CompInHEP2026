#include <iostream>
#include <iomanip>
#include <cmath>
#include "MET.h"

static bool approx(double a, double b, double prec = 1e-12) {
    return std::fabs(a - b) < prec;
}

int main() {
    MET met(3.0, 4.0);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "MET x = " << met.x() << "\n";
    std::cout << "MET y = " << met.y() << "\n";
    std::cout << "MET |v| = " << met.value() << "\n";
    std::cout << "MET phi = " << met.phi() << "\n";

    if (!approx(met.value(), 5.0)) {
        std::cerr << "ERR: Mag check failed \n";
        return 1;
    }

    if (!approx(met.phi(), std::atan2(4.0,3.0))) {
        std::cerr << "ERR: Phi check failed \n";
        return 1;
    }

    met.set(5.0, 7.0);
    met.add(1.0, 1.0);
    if (!approx(met.value(), 10.0)) {
        std::cerr << "ERR: Mag check failed \n";
        return 1;
    }

    if (!approx(met.phi(), std::atan2(8.0,6.0))) {
        std::cerr << "ERR: Phi check failed \n";
        return 1;
    }

    std::cout << "Everything correct";

}