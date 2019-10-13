#include "Catch.hpp"
#include "ApprovalTests/utilities/CartesianProduct.h"

#include <set>

using namespace ApprovalTests;

using Result = std::vector<std::string>;

// ------------------------------------------------------------------

// A hard-coded struct for accumulating results
struct AccumulateResults2StringsCommaSeparated
{
    Result out;
    void operator()(std::string&& s1, std::string&& s2)
    {
        out.push_back(s1 + "," + s2);
    }
};

TEST_CASE("Two Vectors-Single Value-hard-coded-converter")
{
    std::vector<std::string> input1{"hello"};
    std::vector<std::string> input2{"world"};
    AccumulateResults2StringsCommaSeparated results_store;
    CartesianProduct::cartesian_product(results_store, input1, input2);
    Result expected{"hello,world"};
    REQUIRE(results_store.out == expected);
}

// ------------------------------------------------------------------

// Converter is the lambda, function or similar, that takes a set of input values, and returns a calculated result
template<class Converter>
struct AccumulateResults
{
    Result out;
    Converter converter;
    template<class T, class... Ts>
    void operator()(T&& input1, Ts&&... inputs) {
        out.push_back(converter(input1, inputs...));
    }
};

template<class Converter, class Container, class... Containers>
void test_cartesian_product(const Result& expected, Converter&& converter, const Container& input0, const Containers&... inputs)
{
    auto results_store = AccumulateResults<Converter>{
        Result(),
        std::forward<Converter>(converter)};
    CartesianProduct::cartesian_product(results_store, input0, inputs...);
    REQUIRE(results_store.out == expected);
}

std::string concatenate_2_strings_comma_separated(const std::string& s1, const std::string& s2)
{
    return (s1 + "," + s2);
}

TEST_CASE("Cartesian product with iterator types")
{
    const Result expected{"A,1", "A,2", "B,1", "B,2"};
    SECTION("random-access")
    {
        const std::vector<std::string> input1{"A", "B"};
        const std::vector<std::string> input2{"1", "2"};
        test_cartesian_product(expected, concatenate_2_strings_comma_separated, input1, input2);
    }

    SECTION("bi-directional-access")
    {
        const std::set<std::string> input1{"A", "B"};
        const std::set<std::string> input2{"1", "2"};
        test_cartesian_product(expected, concatenate_2_strings_comma_separated, input1, input2);
    }
}


TEST_CASE("Cartesian product works with mixed input types")
{
    const std::vector<std::string> input1{"hello"};
    const std::set<std::string> input2{"world"};
    const Result expected{"hello,world"};
    test_cartesian_product(expected, concatenate_2_strings_comma_separated, input1, input2);
}

TEST_CASE("Cartesian product with an empty input gives empty output")
{
    const std::set<std::string> input1{"A", "B"};
    const std::set<std::string> input2;
    const Result expected;
    test_cartesian_product(expected, concatenate_2_strings_comma_separated, input1, input2);
}
