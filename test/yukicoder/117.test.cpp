#define PROBLEM "https://yukicoder.me/problems/no/117"

#include "lib/modulus/modint.hpp"
#include "lib/modulus/modtable.hpp"

int main() {
    using Fp = Modint1000000007;
    const auto m = ModTable<Fp>(1000000);
    int t;
    std::cin >> t;
    while (t--) {
        char f, _;
        int n, k;
        std::cin >> f >> _ >> n >> _ >> k >> _;
        switch (f) {
            case 'C': std::cout << m.binom(n, k) << std::endl; break;
            case 'P': std::cout << m.perm(n, k) << std::endl; break;
            case 'H': std::cout << m.homo(n, k) << std::endl; break;
            default: assert(false);
        }
    }
}
