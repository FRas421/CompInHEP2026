#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    std::cout << "Hello world < " << n << " >" << std::endl;
    return 0;
}
