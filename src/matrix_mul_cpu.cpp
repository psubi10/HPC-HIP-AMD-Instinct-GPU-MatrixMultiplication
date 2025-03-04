/* This runs matrix multiplication sequentially on the CPU (slow for large matrices).This is the naïve C++ version of matrix multiplication */
#include <iostream>
#include <vector>
#include <chrono>

const int N = 512; // Matrix size

void matrixMulCPU(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

int main() {
    std::vector<int> A(N * N, 1), B(N * N, 1), C(N * N, 0);

    auto start = std::chrono::high_resolution_clock::now();
    matrixMulCPU(A, B, C, N);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "CPU Execution Time: " 
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms" << std::endl;

    return 0;
}
