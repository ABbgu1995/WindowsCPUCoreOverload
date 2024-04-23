# WindowsCoreOverload

The `WindowsCoreOverload` application is designed to heavily load the CPU by running high-computation tasks across multiple threads. This application is ideal for stress testing CPU performance and stability by simulating high-load conditions.

## Features

- **Multi-threading:** Utilizes multiple threads to ensure that all CPU cores can be loaded simultaneously.
- **Configurable Core Count:** The number of threads can be adjusted, allowing the application to use a specific number of CPU cores.
- **High Precision Timing:** Utilizes high-resolution performance counters to manage operation durations accurately.
- **Dynamic Load Adjustment:** The computational load and the duration for which it is applied can be configured, allowing for flexible stress tests.
- **Windows API Integration:** Directly interfaces with several Windows API functions for thread management and performance timing.
- **Logging:** In order to keep track which core are overload and for how much time, the script is generating a log file

## Windows API Functions Used

- `CreateThread`: For creating threads that run on specified CPU cores.
- `SetThreadAffinityMask`: To bind threads to specific CPU cores, ensuring that the load is evenly distributed.
- `QueryPerformanceFrequency` and `QueryPerformanceCounter`: For high-resolution timing to measure the duration of thread execution accurately.
- `SetThreadPriority`: Adjusts the priority of threads to `THREAD_PRIORITY_HIGHEST` to simulate a high-load scenario.
- `WaitForSingleObject` and `CreateEvent`: Used for synchronization between threads, especially for starting and stopping the load application.

## Configuration

- **Core Usage:** The number of cores used by the application can be specified through the `NUM_CORES` macro.
- **Load Duration:** The duration for which each thread should apply computational load can be adjusted. This is managed by the `TIMEOUT` definition which specifies how long each thread should run before stopping.

## Usage

To use the application, compile the C code with a C compiler that supports Windows API, and run the executable. The application will automatically start applying load using the configured settings.

## Building

Use any C compiler that supports Windows API. For example, with Microsoft Visual C++, you can compile using:

```bash
cl WindowsCoreOverload.c
