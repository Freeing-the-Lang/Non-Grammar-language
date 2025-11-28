// pipeline.hpp
#pragma once

template <typename... Steps>
struct Pipeline {
    template <typename T>
    static constexpr auto run(T value) {
        return (Steps::apply(value))...; // fold expression 가능
    }
};
