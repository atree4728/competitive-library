#define IGNORE
#include "../include.hpp"

/**
 * @brief Print
 */

struct Print {
    ostream &os;
    const string sep;
    bool is_debug;
    Print(ostream &os, string sep, bool is_debug):
        os(os), sep(sep), is_debug(is_debug) {}
    void operator()(bool) { os << "\n"; }
    template<class Head, class... Tail> void operator()(bool is_first, Head &&head, Tail &&...tail) {
        os << head;
        if (not is_first and sizeof...(tail) != 0) os << sep;
        operator()(false, forward<Tail>(tail)...);
    }
    template<class T> void operator()(bool, vector<T> &vec) {
        copy(cbegin(vec), cend(vec), experimental::make_ostream_joiner(os, sep));
        os << "\n";
    }
    template<class T> void operator()(bool, vector<vector<T>> &vv) {
        size_t ind = 0;
        if (is_debug) os << "\n";
        for (auto &vec: vv) {
            if (is_debug) os << ind++ << ": ";
            operator()(false, vec);
        }
    }
};

auto print_impl = Prnt(cout, " ", false);
#define print(...) print_impl(true, "", __VA_ARGS__)
#ifdef LOCAL
auto debug_impl = Print(cerr, " ", true);
    #define debug(...) debug_impl(true, "(" #__VA_ARGS__ ") "s, __VA_ARGS__)
#else
    #define debug(...)
#endif
