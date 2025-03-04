#Project Type: Self-Learning Project
📌 Technologies: C++, HIP, HPC, AMD Instinct GPUs
# HPC-HIP-AMD-Instinct-GPU-MatrixMultiplication
High-Performance Computing (HPC) with C++: GPU-Accelerated Matrix Multiplication Using AMD HIP on Instinct GPUs

# 🚀 High-Performance Computing (HPC) with C++: GPU-Accelerated Matrix Multiplication Using AMD HIP on Instinct GPUs

This project demonstrates **GPU acceleration for matrix multiplication** using **AMD HIP on AMD Instinct GPUs**. It showcases **HPC techniques**, **parallel computing**, and **performance benchmarking** between **CPU vs. GPU computations**.

## 🔹 Key Features
✅ Implemented **matrix multiplication using C++**  
✅ Optimized using **HIP for AMD Instinct GPUs**  
✅ Benchmarked **CPU vs. GPU performance** for HPC applications  
✅ Showcases **heterogeneous computing (CPU + GPU offloading)**  

## 🔹 Performance Comparison (CPU vs. GPU)
| Matrix Size | CPU Execution Time (ms) | GPU Execution Time (ms) | Speedup |
|------------|------------------------|------------------------|---------|
| 512x512    | 950 ms                 | 25 ms                  | **38x**  |
| 1024x1024  | 7800 ms                | 210 ms                 | **37x**  |

## 🔹 Why is This Relevant to HPC?
- **Matrix multiplication** is used in **scientific simulations, AI, and deep learning**.
- **AMD Instinct GPUs** are optimized for **AI, HPC, and data science workloads**.
- **HIP enables high-performance parallel computing** on AMD hardware.

## 🔹 Getting Started (Run the Code)
**How to compile and run the CPU version **
g++ matrix_mul_cpu.cpp -o matrix_cpu -O2
./matrix_cpu

**How to Run the HIP GPU Version**
### Install HIP & ROCm (For AMD Instinct GPUs)
```bash
sudo apt install rocm-dev

Compile & Run the GPU-Accelerated Code
hipcc matrix_mul_hip.cpp -o matrix_gpu
./matrix_gpu

Note:

A GPU is hardware, but software needs to use it for specific tasks. Gaming, video editing, AI, and other high-performance applications offload processing (CPU offloads the complex tasks to GPU)to the GPU to improve speed and efficiency.
How the CPU and GPU Work Together?
The CPU handles general tasks, like:

Running the operating system (Windows, macOS, Linux).
Managing files, apps, and background tasks.
Handling logic-based tasks like AI decision-making.
The GPU accelerates specific tasks, like:

Rendering graphics for games, movies, and 3D modeling.
AI computations for machine learning.
Video editing & rendering for smoother playback.
Data science & big data processing in professional applications.
This teamwork between the CPU and GPU results in faster processing and reduced run time for tasks that need high-speed calculations.


