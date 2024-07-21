#include <catch2/catch_test_macros.hpp>
#include <iostream>

// change if you choose to use a different header name
#include "AdjacencyList.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Test 1", "[flag]"){
    // instantiate any class members that you need to test here
    int one = 1;

    // anything that evaluates to false in a REQUIRE block will result in a failing test
    REQUIRE(one == 1); // fix me!

    // all REQUIRE blocks must evaluate to true for the whole test to pass
    REQUIRE(true); // also fix me!
}

TEST_CASE("Test 2", "[flag]"){
    // you can also use "sections" to share setup code between tests, for example:
    int one = 1;

    SECTION("num is 2") {
        int num = one + 1;
        REQUIRE(num == 2);
    };

    SECTION("num is 3") {
        int num = one + 2;
        REQUIRE(num == 3);
    };

    // each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for extra credit on this project!

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
TEST_CASE("Example PageRank Output Test", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

   // Simulate input
    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());

    // Capture output
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    // Create the graph and read the input
    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; i++) {
        std::cin >> from;
        std::cin >> to;
        Created_Graph.addEdge(from, to);
    }

    // Perform PageRank
    Created_Graph.PageRank(power_iterations);

    // Reset the buffers
    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);

    // Get the actual output
    string actualOutput = output_stream.str();

    // Compare the expected and actual output
    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("Example PageRank Output Test 2", "[flag]") {
    string input = R"(5 3
a.com b.com
b.com c.com
c.com a.com
a.com d.com
d.com b.com)";

    string expectedOutput = R"(a.com 0.25
b.com 0.25
c.com 0.25
d.com 0.25
)";

    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; ++i) {
        std::cin >> from >> to;
        Created_Graph.addEdge(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);
    string actualOutput = output_stream.str();
    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Example PageRank Output Test 3", "[flag]") {
    string input = R"(4 2
a.com b.com
a.com c.com
b.com d.com
c.com d.com)";

    string expectedOutput = R"(a.com 0.09
b.com 0.23
c.com 0.23
d.com 0.45
)";

    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; ++i) {
        std::cin >> from >> to;
        Created_Graph.addEdge(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);
    string actualOutput = output_stream.str();
    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Example PageRank Output Test 4", "[flag]") {
    string input = R"(6 4
a.com b.com
a.com c.com
b.com d.com
b.com e.com
c.com e.com
d.com a.com)";

    string expectedOutput = R"(a.com 0.15
b.com 0.15
c.com 0.12
d.com 0.27
e.com 0.31
)";

    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; ++i) {
        std::cin >> from >> to;
        Created_Graph.addEdge(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);
    string actualOutput = output_stream.str();
    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Example PageRank Output Test 5", "[flag]") {
    string input = R"(3 3
a.com b.com
b.com c.com
c.com a.com)";

    string expectedOutput = R"(a.com 0.33
b.com 0.33
c.com 0.33
)";

    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; ++i) {
        std::cin >> from >> to;
        Created_Graph.addEdge(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);
    string actualOutput = output_stream.str();
    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Example PageRank Output Test 6", "[flag]") {
    string input = R"(8 2
a.com b.com
b.com c.com
c.com d.com
d.com e.com
e.com f.com
f.com g.com
g.com h.com
h.com a.com)";

    string expectedOutput = R"(a.com 0.12
b.com 0.12
c.com 0.12
d.com 0.12
e.com 0.12
f.com 0.12
g.com 0.12
h.com 0.12
)";

    std::istringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());
    std::ostringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    AdjacencyList Created_Graph;
    int no_of_lines, power_iterations;
    std::cin >> no_of_lines >> power_iterations;
    std::string from, to;
    for (int i = 0; i < no_of_lines; ++i) {
        std::cin >> from >> to;
        Created_Graph.addEdge(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cin.rdbuf(nullptr);
    std::cout.rdbuf(nullptr);
    string actualOutput = output_stream.str();
    REQUIRE(actualOutput == expectedOutput);
}