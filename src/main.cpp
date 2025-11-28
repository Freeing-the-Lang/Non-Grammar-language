#include <iostream>

// --------------------------------------------------
// Non-Grammar-language core (header-less inline impl)
// --------------------------------------------------

// Value holder (signal)
template <auto V>
struct Var {
    static constexpr auto value = V;
};

// Semantic operations (meaning-level functions)
struct Add {
    static constexpr auto apply(auto a, auto b) {
        return a + b;
    }
};

struct Mul {
    static constexpr auto apply(auto a, auto b) {
        return a * b;
    }
};

struct Sub {
    static constexpr auto apply(auto a, auto b) {
        return a - b;
    }
};

struct Div {
    static constexpr auto apply(auto a, auto b) {
        return a / b;
    }
};

// Node = meaning-level computation unit
template <typename Fn, typename Left, typename Right>
struct Node {
    static constexpr auto eval() {
        return Fn::apply(Left::value, Right::value);
    }
};

// --------------------------------------------------
// Example program made of **types only**
// --------------------------------------------------

using A  = Var<10>;
using B  = Var<32>;

using AddAB = Node<Add, A, B>;
using MulAB = Node<Mul, A, B>;
using SubAB = Node<Sub, A, B>;
using DivAB = Node<Div, B, A>;  // 32 / 10

// --------------------------------------------------
// main()
// --------------------------------------------------

int main() {
    constexpr auto r1 = AddAB::eval();   // 10 + 32
    constexpr auto r2 = MulAB::eval();   // 10 * 32
    constexpr auto r3 = SubAB::eval();   // 10 - 32
    constexpr auto r4 = DivAB::eval();   // 32 / 10 (integer division)

    std::cout << "Non-Grammar-Language (C++ TMP Engine)\n";
    std::cout << "------------------------------------\n";
    std::cout << "10 + 32 = " << r1 << "\n";
    std::cout << "10 * 32 = " << r2 << "\n";
    std::cout << "10 - 32 = " << r3 << "\n";
    std::cout << "32 / 10 = " << r4 << "\n";

    return 0;
}
