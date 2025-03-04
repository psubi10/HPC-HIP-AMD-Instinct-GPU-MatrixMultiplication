/* matrix_mul_hip.cpp (GPU Version Using HIP) This offloads matrix multiplication to AMD GPUs using HIP, making it significantly faster*/
#include <hip/hip_runtime.h>
#include <iostream>
#include <vector>
#include <chrono>

const int N = 512; // Matrix size

// GPU Kernel for Matrix Multiplication
__global__ void matrixMulGPU(int* A, int* B, int* C, int N) {
    int row = threadIdx.y + blockIdx.y * blockDim.y;
    int col = threadIdx.x + blockIdx.x * blockDim.x;

    if (row < N && col < N) {
        int sum = 0;
        for (int k = 0; k < N; ++k) {
            sum += A[row * N + k] * B[k * N + col];
        }
        C[row * N + col] = sum;
    }
}

int main() {
    size_t size = N * N * sizeof(int);
    
    std::vector<int> h_A(N * N, 1), h_B(N * N, 1), h_C(N * N, 0);
    int *d_A, *d_B, *d_C;

    // Allocate GPU memory
    hipMalloc(&d_A, size);
    hipMalloc(&d_B, size);
    hipMalloc(&d_C, size);

    // Copy data to GPU
    hipMemcpy(d_A, h_A.data(), size, hipMemcpyHostToDevice);
    hipMemcpy(d_B, h_B.data(), size, hipMemcpyHostToDevice);

    dim3 threadsPerBlock(16, 16);
    dim3 blocksPerGrid((N + 15) / 16, (N + 15) / 16);

    auto start = std::chrono::high_resolution_clock::now();

    // Launch Kernel on GPU
    hipLaunchKernelGGL(matrixMulGPU, blocksPerGrid, threadsPerBlock, 0, 0, d_A, d_B, d_C, N);
    hipDeviceSynchronize();

    auto end = std::chrono::high_resolution_clock::now();

    // Copy result back to CPU
    hipMemcpy(h_C.data(), d_C, size, hipMemcpyDeviceToHost);

    std::cout << "GPU Execution Time: " 
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms" << std::endl;

    // Free GPU memory
    hipFree(d_A);
    hipFree(d_B);
    hipFree(d_C);

    return 0;
}
