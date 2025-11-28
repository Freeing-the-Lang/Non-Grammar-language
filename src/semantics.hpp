// semantics.hpp
#pragma once

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
