// node.hpp
#pragma once

template <typename Fn, typename Left, typename Right>
struct Node {
    static constexpr auto eval() {
        return Fn::apply(Left::value, Right::value);
    }
};
