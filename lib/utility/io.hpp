#pragma once

#include <iomanip>

#include "lib/utility/printer.hpp"
#include "lib/utility/scanner.hpp"

__attribute__((constructor)) inline auto io_setup() noexcept {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
    std::cerr << std::fixed << std::setprecision(10);
}
