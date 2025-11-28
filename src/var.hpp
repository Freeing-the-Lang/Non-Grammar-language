// var.hpp
#pragma once

template <auto V>
struct Var {
    static constexpr auto value = V;
};
