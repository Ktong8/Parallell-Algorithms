#include "parallel_prefix_sum.h"
#include "timer.h"
#include "par_sum_test.h"
#include <iostream>

constexpr int VECTOR_LEN = 100000;
constexpr int ARRAY_LEN = 1000;

int prefix_sum_loop(std::vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
}

void TestFunctions() {
    TestVectorSum();
    TestArraySum();
}


void BenchmarkVector(std::string message, size_t size, std::function<int(std::vector<int>&)> func) {
    using benchmark::Timer;
    std::vector<int> a(size);
    for (size_t i = 0; i < size; ++i) {
        a[i] = i;
    }
    {
        Timer timer {message};
        func(a);
    }
}

template <size_t N>
void BenchmarkArray(std::string message, std::function<int(std::array<int, N>&)> func) {
    using benchmark::Timer;
    std::array<int, N> a{};
    for (size_t i = 0; i < N; ++i) {
        a[i] = i;
    }
    {
        Timer timer{message};
        func(a);
    }
}

int main() {
    using benchmark::Timer;
    TestFunctions();
    std::vector<int> a(VECTOR_LEN);
    std::array<int, ARRAY_LEN> b{{}};
    return 0;
}
