#include <gtest/gtest.h>
#include <bits/stdc++.h>

void solve(std::istream& in, std::ostream& out);

namespace fs = std::filesystem;
std::string dir = "../gtester/tests/";

void CheckSimple(const std::string& test) {
    std::ifstream out(dir + test + ".out"), ans(dir + test + ".ans");
    std::string str;
    std::vector<std::string> out_content, ans_content;

    while (out >> str) {
        out_content.push_back(str);
    }

    while (ans >> str) {
        ans_content.push_back(str);
    }

    ASSERT_EQ(out_content, ans_content);
}

void CheckIntegers(const std::string& test) {
    std::ifstream out(dir + test + ".out"), ans(dir + test + ".ans");
    double x;
    std::vector<double> out_content, ans_content;

    while (out >> x) {
        out_content.push_back(x);
    }

    while (ans >> x) {
        ans_content.push_back(x);
    }

    ASSERT_EQ(out_content, ans_content);
}

void CheckDoubles(const std::string& test) {
    std::ifstream out(dir + test + ".out"), ans(dir + test + ".ans");
    int x;
    std::vector<int> out_content, ans_content;

    while (out >> x) {
        out_content.push_back(x);
    }

    while (ans >> x) {
        ans_content.push_back(x);
    }

    ASSERT_EQ(out_content, ans_content);
}

class TestSuite : public ::testing::TestWithParam<std::string> {};

TEST_P(TestSuite, FunctionTest) {
    auto test = GetParam();
    std::ifstream in(dir + test + ".in");
    std::ofstream ans(dir + test + ".ans");
    solve(in, ans);
    in.close();
    ans.close();
    CheckSimple(test);
}

std::vector<std::string> getTestCases() {
    std::vector<std::string> tests;

    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.path().extension() == ".in") {
            std::string test = entry.path().filename().string();
            tests.emplace_back(test.substr(0, test.size() - 3));
        }
    }

    return tests;
}

INSTANTIATE_TEST_SUITE_P(
    DynamicTests,
    TestSuite,
    ::testing::ValuesIn(getTestCases())
);
