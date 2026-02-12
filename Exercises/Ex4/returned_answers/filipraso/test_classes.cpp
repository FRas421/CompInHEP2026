#include "Track.h"
#include "PSim.h"
#include <iostream>
#include <cmath>

static void assert_close(double a, double b, double err=1e-12) {
    if (std::fabs(a - b) > err) {
        std::cerr << "Assertion fail: " << a << " vs " << "\n";
        std::exit(1);
    }

}

int main() {
    Track t(3.0, 4.0, 12.0, 13.0);
    std::cout << "Track:\n";
    t.print(std::cout);
    std::cout << "\n";

    assert_close(t.pt(), 5.0);
    const double p = std::sqrt(3.0*3.0 + 4.0*4.0 + 12.0*12.0);
    const double theta = std::acos(12.0 / p);
    const double eta_theta = -std::log(std::tan(theta/2.0));
    assert_close(t.eta(), eta_theta, 1e-12);

    PSim sp(10.0, 0.0, 0.0, 10.0, 11, 23);
    std::cout << "\n PSim:\n";
    sp.print(std::cout);
    std::cout << "\n";

    assert_close(sp.pt(), 10.0);
    if (sp.pid() != 11 || sp.parentId() != 23) {
        std::cerr << "PId/ ParId mismatch \n";
        return 1;
    }

    std::cout << "\n All passed. \n";
    return 0;

}