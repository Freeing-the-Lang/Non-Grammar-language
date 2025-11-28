// op.hpp
#pragma once
#include "signal.hpp"

template <typename A, typename B, typename Fn>
struct Op {
    static constexpr auto value(A a, B b) {
        return Fn::apply(a, b);
    }
};
