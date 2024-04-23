//#include <windows.h>
//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h> // For rand()
//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <process.h>
//#include <time.h>
//
//#define THREAD_COUNT 15
//
//HANDLE g_StartEventHandle;
//HANDLE g_Threads[THREAD_COUNT];
//DWORD_PTR g_affinityMask[THREAD_COUNT];
//LARGE_INTEGER g_Frequency;
//LARGE_INTEGER g_StartTime, g_EndTime;
//
//int generate_random_number(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//void CALLBACK consume_cpu(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
//
//    LARGE_INTEGER frequency, start, end;
//    QueryPerformanceFrequency(&frequency);
//    QueryPerformanceCounter(&start);
//
//    while (WaitForSingleObject(exitEvent, 0) == WAIT_TIMEOUT) {
//        double result = 0;
//        int random_number2 = generate_random_number(999999, 999999999);
//        int random_number3 = generate_random_number(999999, 999999999);
//
//        for (int i = 0; i < 99999999999; i++) {
//            result += log((double)random_number2) * pow(i, 2) * log((double)random_number3);
//        }
//
//        QueryPerformanceCounter(&end);
//        if (((end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart) >= DURATION_MS) {
//            break;
//        }
//    }
//}
//DWORD WINAPI func1(LPVOID lpParam) {
//    int threadIndex = (int)lpParam;
//
//    // Set thread to run on a specific CPU core
//    SetThreadAffinityMask(g_Threads[threadIndex], g_affinityMask[threadIndex]);
//
//    // Set highest priority
//    SetThreadPriority(g_Threads[threadIndex], THREAD_PRIORITY_HIGHEST);
//
//    // Wait for the start event
//    WaitForSingleObject(g_StartEventHandle, INFINITE);
//
//    // Perform tasks
//    while (TRUE) {
//        QueryPerformanceCounter(&g_EndTime);
//        if ((g_EndTime.QuadPart - g_StartTime.QuadPart) * 1000.0 / g_Frequency.QuadPart >= 5.0) {
//            break; // Stop after 5ms
//        }
//
//        double result = 0;
//        int random_number2 = generate_random_number(999999, 999999999);
//        int random_number3 = generate_random_number(999999, 999999999);
//
//        for (int i = 0; i < 999999999; i++) {
//            result += log((double)random_number2) * pow(i, 2) * log((double)random_number3);
//        }
//    }
//    return 0;
//}
//
//int main() {
//    DWORD ThreadId;
//
//    // Create a manual-reset event object
//    g_StartEventHandle = CreateEvent(NULL, TRUE, FALSE, NULL);
//    if (g_StartEventHandle == NULL) {
//        printf("CreateEvent failed (%d)\n", GetLastError());
//        return 1;
//    }
//
//    // Get the frequency of the high-resolution performance counter
//    QueryPerformanceFrequency(&g_Frequency);
//
//    // Initialize CPU core affinity masks
//    for (int i = 0; i < THREAD_COUNT; i++) {
//        g_affinityMask[i] = (DWORD_PTR)1 << i;
//    }
//
//    // Create threads
//    for (int i = 0; i < THREAD_COUNT; i++) {
//        g_Threads[i] = CreateThread(NULL, 0, func1, (PVOID)i, 0, &ThreadId);
//        if (g_Threads[i] == NULL) {
//            printf("CreateThread failed (%d)\n", GetLastError());
//            return 1;
//        }
//    }
//
//    // Start the cycle of releasing and stopping threads
//    for (int cycle = 0; cycle < 10; cycle++) {
//        // Start the timer
//        QueryPerformanceCounter(&g_StartTime);
//
//        // Release the threads
//        SetEvent(g_StartEventHandle);
//
//        // Wait for 5ms
//        Sleep(100);
//
//        // Reset the event to stop the threads
//        ResetEvent(g_StartEventHandle);
//
//        // Wait for another 5ms before the next cycle
//        Sleep(100);
//    }
//
//    // Wait for all threads to complete
//    WaitForMultipleObjects(THREAD_COUNT, g_Threads, TRUE, INFINITE);
//
//    // Clean up
//    for (int i = 0; i < THREAD_COUNT; i++) {
//        CloseHandle(g_Threads[i]);
//    }
//    CloseHandle(g_StartEventHandle);
//
//    return 0;
//}
//


//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <process.h>
//#include <time.h>
//
//#define NUM_ITERATIONS 100
//#define NUM_CORES 16
//#define DURATION_MS 4 // Duration in milliseconds
//
//HANDLE exitEvent;
//HANDLE threadPool;
//TP_CALLBACK_ENVIRON environment;
//
//// Function to generate a random number
//int generate_random_number(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//
//// Function to simulate CPU-intensive task
//void CALLBACK consume_cpu(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
//
//    LARGE_INTEGER frequency, start, end;
//    QueryPerformanceFrequency(&frequency);
//    QueryPerformanceCounter(&start);
//
//    while (WaitForSingleObject(exitEvent, 0) == WAIT_TIMEOUT) {
//        double result = 0;
//        int random_number2 = generate_random_number(999999, 999999999);
//        int random_number3 = generate_random_number(999999, 999999999);
//
//        for (int i = 0; i < 99999999999; i++) {
//            result += log((double)random_number2) * pow(i, 2) * log((double)random_number3);
//        }
//
//        QueryPerformanceCounter(&end);
//        if (((end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart) >= DURATION_MS) {
//            break;
//        }
//    }
//}
//
//int main() {
////    HANDLE currentProcess = GetCurrentProcess();
////    if (!SetPriorityClass(currentProcess, REALTIME_PRIORITY_CLASS)) {
////        printf("Failed to set process priority. Error: %lu\n", GetLastError());
////    }
////
////    // Optionally, set processor affinity (bind process to specific CPUs)
////    DWORD_PTR affinityMask = 1; // e.g., use processor 0
////    if (!SetProcessAffinityMask(currentProcess, affinityMask)) {
////        printf("Failed to set process affinity. Error: %lu\n", GetLastError());
////    }
//    exitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
//    threadPool = CreateThreadpool(NULL);
//    InitializeThreadpoolEnvironment(&environment); // Initialize the environment
//
//    SetThreadpoolThreadMaximum(threadPool, NUM_CORES);
//    SetThreadpoolCallbackPool(&environment, threadPool);
//
//    PTP_WORK work[NUM_CORES];
//    for (int i = 0; i < NUM_CORES; i++) {
//        work[i] = CreateThreadpoolWork(consume_cpu, NULL, &environment);
//    }
//
//    for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
//        for (int core = 0; core < NUM_CORES; core++) {
//            SubmitThreadpoolWork(work[core]);
//        }
//
//        Sleep(DURATION_MS);
//        SetEvent(exitEvent);
//        WaitForThreadpoolWorkCallbacks(work[0], FALSE); // Wait for all work items
//
//        for (int core = 0; core < NUM_CORES; core++) {
//            CloseThreadpoolWork(work[core]);
//        }
//
//        Sleep(DURATION_MS);
//        ResetEvent(exitEvent);
//    }
//
//    CloseHandle(exitEvent);
//    CloseThreadpool(threadPool);
//    return 0;
//}

//#include <stdio.h>
//#include <windows.h>
//#include <math.h>
//
//#define NUM_CORES 20 // Number of work items to submit, assuming one per core
//#define WORK_INTERVAL_MS 4
//#define REST_INTERVAL_MS 4
//
//CRITICAL_SECTION cs;
//HANDLE startEvent;
//HANDLE workItemsCompletedEvent;
//volatile LONG pendingWorkItems;
//
//// Work callback function
//VOID CALLBACK WorkCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
//    WaitForSingleObject(startEvent, INFINITE); // Wait for the signal to start work
//
//    // Simulate CPU-intensive work
//    DWORD startTime = GetTickCount();
//    while (GetTickCount() - startTime < WORK_INTERVAL_MS) {
//        double result = 0;
//        for (int i = 0; i < 1000000; i++) {
//            result += sin(i) * cos(i) * log((double)i) * pow(i, 2)* log((double)i);
//        }
//    }
//
//    // Atomically decrement the count of pending work items
//    if (InterlockedDecrement(&pendingWorkItems) == 0) {
//        // Last work item to finish signals that all work is completed
//        SetEvent(workItemsCompletedEvent);
//    }
//}
//
//int main() {
//    InitializeCriticalSection(&cs);
//    startEvent = CreateEvent(NULL, TRUE, FALSE, NULL); // Manual reset event
//    workItemsCompletedEvent = CreateEvent(NULL, FALSE, FALSE, NULL); // Auto reset event
//
//    PTP_POOL pool = CreateThreadpool(NULL);
//    SetThreadpoolThreadMaximum(pool, NUM_CORES);
//    SetThreadpoolThreadMinimum(pool, NUM_CORES);
//
//    PTP_CLEANUP_GROUP cleanupGroup = CreateThreadpoolCleanupGroup();
//    SetThreadpoolCallbackPool(&cleanupGroup, pool);
//
//    PTP_WORK works[NUM_CORES];
//    for (int i = 0; i < NUM_CORES; ++i) {
//        works[i] = CreateThreadpoolWork(WorkCallback, NULL, &cleanupGroup);
//    }
//
//    // Main loop to control work submission and synchronization
//    for (int i = 0; i < 10000; ++i) { // Example: 10 iterations
//        ResetEvent(workItemsCompletedEvent);
//        pendingWorkItems = NUM_CORES; // Reset pending work items count
//
//        // Submit work items
//        for (int j = 0; j < NUM_CORES; ++j) {
//            SubmitThreadpoolWork(works[j]);
//        }
//
//        SetEvent(startEvent); // Start all work items simultaneously
//        WaitForSingleObject(workItemsCompletedEvent, INFINITE); // Wait for all work to complete
//
//        // Work completed, reset for next iteration
//        ResetEvent(startEvent);
//        Sleep(REST_INTERVAL_MS); // Simulate rest interval
//    }
//
//    // Cleanup
//    for (int i = 0; i < NUM_CORES; ++i) {
//        CloseThreadpoolWork(works[i]);
//    }
//    CloseThreadpoolCleanupGroupMembers(cleanupGroup, FALSE, NULL);
//    CloseThreadpoolCleanupGroup(cleanupGroup);
//    CloseThreadpool(pool);
//
//    DeleteCriticalSection(&cs);
//    CloseHandle(startEvent);
//    CloseHandle(workItemsCompletedEvent);
//
//    return 0;

//
//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <process.h>
//
//#define NUM_ITERATIONS 10000
//#define NUM_CORES 20
//HANDLE exitEvent;  //A HANDLE is a generic reference to various types of objects in the Windows API; it's an opaque pointer to a resource managed by the Windows kernel.
//HANDLE startEvent; // Added for synchronization
//
//
//// Function to generate a random number
//int generate_random_number(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//
//// Function to simulate CPU-intensive task adapted for ThreadPool
//void CALLBACK consume_cpu(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
//// Get the current system time
//    DWORD_PTR core = GetCurrentProcessorNumber(); // Get the CPU core number
//    SYSTEMTIME start, end;
//    GetSystemTime(&start); // Get start timestamp
//    // Print the timestamp
//
//    WaitForSingleObject(startEvent, INFINITE); // Wait for the start signal
//    while (WaitForSingleObject(exitEvent, 0) == WAIT_TIMEOUT) {
//        double result = 0;
//        int random_number2 = generate_random_number(999999, 999999999);
//        int random_number3 = generate_random_number(999999, 999999999);
//
//        for (int i = 0; i < 999999999; i++) { // Adjusted loop count for practicality
//            result += log((double)random_number2) * pow(i, 2) * log((double)random_number3);
//        }
//        break; // Break after one iteration to simulate the original behavior
//    }
//}
//
//int main() {
//
//    srand((unsigned)time(NULL)); // Seed the random number generator
//    exitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
//    startEvent = CreateEvent(NULL, TRUE, FALSE, NULL); // Initialize startEvent
//
//    PTP_WORK workItems[NUM_CORES];
//    PTP_POOL pool = CreateThreadpool(NULL);
//    SetThreadpoolThreadMaximum(pool, NUM_CORES);
//    InitializeThreadpoolEnvironment(&pool);
//
//    // Create ThreadPool work items
//    for (int core = 0; core < NUM_CORES; core++) {
//        workItems[core] = CreateThreadpoolWork(consume_cpu, NULL, NULL);
//        SubmitThreadpoolWork(workItems[core]);
//    }
//
//    // Main loop to start and reset work
//    for (int i = 1; i < NUM_ITERATIONS; i++) {
//        SetEvent(startEvent); // Signal all threads to start
//        Sleep(5000); // Simulate work duration
//        ResetEvent(startEvent); // Prepare for next iteration
//        SetEvent(exitEvent); // Signal threads to exit their loop
//
//        // Wait briefly to ensure all work items can check the exitEvent
//        Sleep(5000);
//
//        // Reset exitEvent for the next iteration
//        ResetEvent(exitEvent);
//    }
//
//    // Cleanup
//    for (int core = 0; core < NUM_CORES; core++) {
//        CloseThreadpoolWork(workItems[core]);
//    }
//    CloseHandle(exitEvent);
//    CloseHandle(startEvent);
//    return 0;
//}
//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <process.h>
//#include <time.h>
//
//#define NUM_ITERATIONS 10000
//#define NUM_CORES 40
//
//volatile int stop_threads = 0;
//
//// Function to generate a random number
//int generate_random_number(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//
//// Function to simulate CPU-intensive task
//void consume_cpu() {
//    while (!stop_threads) {
//        double result = 0;
//
//        int random_number1 = generate_random_number(999999, 999999999);
//        int random_number2 = generate_random_number(999999, 999999999);
//        int random_number3 = generate_random_number(999999, 9999999999999);
//
//        for (int i = 0; i < 9999; i++) {
//            result += log((double)random_number2) * pow(i, 2);
//        }
//    }
//}
//
//// Function to wrap the function pointer for _beginthread
//void wrapper_function(void* func_ptr) {
//    void (*func)(void) = func_ptr;
//    func();
//}
//
//// Function to get current time in milliseconds using clock_gettime
//unsigned long long get_current_time() {
//    struct timespec ts;
//    clock_gettime(CLOCK_MONOTONIC, &ts);
//    return ts.tv_sec * 1000ULL + ts.tv_nsec / 1000000ULL;
//}
//
//int main() {
//    srand((unsigned int)time(NULL));
//
//
//    for (int i = 1; i < NUM_ITERATIONS; i++) {
//        HANDLE threads[NUM_CORES];
//
//        // Line 1
//        for (int core = 0; core < NUM_CORES; core++) {
//            threads[core] = (HANDLE)_beginthread(wrapper_function, 0, consume_cpu);
//        }
//
//        // Line 2
//
//        Sleep(1000000);
//
//
//        // Line 3
//        stop_threads = 1;
//
//        // Line 4
//
//        for (int core = 0; core < NUM_CORES; core++) {
//            WaitForSingleObject(threads[core], INFINITE);
//            CloseHandle(threads[core]);
//        }
//
//
//        // Line 5
//        Sleep(10000000);
//
//        stop_threads = 0;
//    }
//}


#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <timeapi.h>

#define NUM_CORES 12
#define NUM_ITERATIONS 10000
#define TIMEOUT 2000


volatile LONG pendingJobs = 0;
volatile int stop_threads = 0;
HANDLE logMutex; // Mutex for log file access


// Function to generate a random number
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// High-resolution timestamp function
unsigned long long GetHighResolutionTimestamp() {
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (unsigned long long)(counter.QuadPart * 1000.0 / freq.QuadPart);
}

void PreciseSleep(long long milliseconds) {
    unsigned long long endTime = GetHighResolutionTimestamp() + milliseconds;
    while (GetHighResolutionTimestamp() < endTime) {
        // Optionally, use a short Sleep here to yield the processor
        Sleep(1); // Sleep for 1 ms to reduce CPU usage during the wait
    }
}

void HybridSleep(long long milliseconds) {
    unsigned long long start = GetHighResolutionTimestamp();
    unsigned long long end = start + milliseconds;
    unsigned long long now = start;

    // First, use Sleep to wait for the majority of the wait time, but wake up slightly earlier.
    long long earlyWakeTime = milliseconds - 1; // Wake up 1 ms early
    if (earlyWakeTime > 0) {
        Sleep((DWORD)earlyWakeTime);
    }

    // Then, use a busy-wait loop for the final milliseconds to achieve higher precision.
    do {
        now = GetHighResolutionTimestamp();
    } while (now < end);
}
// Thread-safe logging function
void LogToFile(const char* logMessage) {
    WaitForSingleObject(logMutex, INFINITE);

    FILE* logFile = fopen("C:\\Users\\user\\CLionProjects\\CPU_Overloader\\thread_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s\n", logMessage);
        fclose(logFile);
    }

    ReleaseMutex(logMutex);
}

// Callback function for thread pool work items
VOID CALLBACK MyWorkCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
    UNREFERENCED_PARAMETER(Instance);
    UNREFERENCED_PARAMETER(Context);
    UNREFERENCED_PARAMETER(Work);
    double result = 0;

    unsigned long long startTime = GetHighResolutionTimestamp();
    DWORD processorNumber = GetCurrentProcessorNumber();

    // Simulate work with precise timing
    /// here ///
    unsigned long long targetTime = TIMEOUT; // Target time in milliseconds
    unsigned long long endTime = startTime + targetTime;
    unsigned long long currentTime;
    do {
        currentTime = GetHighResolutionTimestamp();
        for (int i = 0; i < 999999; i++) {
            result += log((double)i) * pow(i, 2);
        }
    } while (currentTime < endTime && !stop_threads);

    unsigned long long actualTime = GetHighResolutionTimestamp() - startTime;
    char logBuffer[128];
    snprintf(logBuffer, sizeof(logBuffer), "Thread finished in %llu ms on processor %lu", actualTime, processorNumber);
    LogToFile(logBuffer);

    // Decrement the count of pending jobs
    InterlockedDecrement(&pendingJobs);
}

int main() {
    timeBeginPeriod(1);

    srand((unsigned int)time(NULL));

    if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS)) {
        printf("Failed to set process priority. Error: %lu\n", GetLastError());
        return -1;
    }
    // Initialize log mutex
    logMutex = CreateMutex(NULL, FALSE, NULL);
    if (logMutex == NULL) {
        printf("Failed to create log mutex.\n");
        return -1;
    }

    TP_CALLBACK_ENVIRON CallBackEnviron;
    InitializeThreadpoolEnvironment(&CallBackEnviron);
    SetThreadpoolCallbackRunsLong(&CallBackEnviron);
    // Create a thread pool
    PTP_POOL pool = CreateThreadpool(NULL);
    if (!pool) {
        printf("Failed to create thread pool.\n");
        return -1;
    }



    SetThreadpoolThreadMaximum(pool, NUM_CORES);
    if (!SetThreadpoolThreadMinimum(pool, NUM_CORES)) {
        printf("Failed to set the minimum thread count.\n");
        CloseThreadpool(pool);
        return -1;
    }
    SetThreadpoolCallbackPool(&CallBackEnviron, pool);
    for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
        char iterationStartMsg[128];
        unsigned long long iterationStartTime = GetHighResolutionTimestamp();
        snprintf(iterationStartMsg, sizeof(iterationStartMsg), "Iteration %d started at %llu ms", iteration + 1, iterationStartTime);
        LogToFile(iterationStartMsg);
        stop_threads = 0; // Ensure threads are running for the new iteration
        pendingJobs = 0; // Reset the pending jobs counter

        // Create work items and submit them to the pool
        for (int i = 0; i < NUM_CORES; i++) {

            PTP_WORK workItem = CreateThreadpoolWork(MyWorkCallback, NULL, NULL);
            if (!workItem) {
                printf("Failed to create work item.\n");
                CloseThreadpool(pool);
                return -1;
            }
            InterlockedIncrement(&pendingJobs);
            SubmitThreadpoolWork(workItem);
        }

        // Simulate work
        /// here ///
        Sleep(TIMEOUT);

        // Signal threads to stop
        stop_threads = 1;

        // Wait for all work items to complete
        while (pendingJobs > 0) {
            Sleep(TIMEOUT); // Wait and let worker threads finish
        }

        // Cleanup the work items for this iteration
        // Note: In this structure, we're not storing handles to individual work items for closing them after completion within an iteration.
    }

    // Close the thread pool after all iterations are done
    CloseThreadpool(pool);
    printf("All work items have completed across %d iterations.\n", NUM_ITERATIONS);
    CloseHandle(logMutex);
    timeEndPeriod(1);
    return 0;
}


// Manual management threads
//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <process.h>
//#include <time.h>
//#include <timeapi.h>
//
//#define NUM_CORES 16
//#define NUM_ITERATIONS 150
//
//volatile LONG pendingJobs = 0;
//volatile int stop_threads = 0;
//HANDLE logMutex; // Mutex for log file access
//HANDLE threads[NUM_CORES]; // Array to store thread handles
//
//// Function to generate a random number
//int generate_random_number(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//
//// High-resolution timestamp function
//unsigned long long GetHighResolutionTimestamp() {
//    LARGE_INTEGER freq, counter;
//    QueryPerformanceFrequency(&freq);
//    QueryPerformanceCounter(&counter);
//    return (unsigned long long)(counter.QuadPart * 1000.0 / freq.QuadPart);
//}
//
//void PreciseSleep(long long milliseconds) {
//    unsigned long long endTime = GetHighResolutionTimestamp() + milliseconds;
//    while (GetHighResolutionTimestamp() < endTime) {
//        // Optionally, use a short Sleep here to yield the processor
//        Sleep(1); // Sleep for 1 ms to reduce CPU usage during the wait
//    }
//}
//
//void HybridSleep(long long milliseconds) {
//    unsigned long long start = GetHighResolutionTimestamp();
//    unsigned long long end = start + milliseconds;
//    unsigned long long now = start;
//
//    // First, use Sleep to wait for the majority of the wait time, but wake up slightly earlier.
//    long long earlyWakeTime = milliseconds - 1; // Wake up 1 ms early
//    if (earlyWakeTime > 0) {
//        Sleep((DWORD)earlyWakeTime);
//    }
//
//    // Then, use a busy-wait loop for the final milliseconds to achieve higher precision.
//    do {
//        now = GetHighResolutionTimestamp();
//    } while (now < end);
//}
//// Thread-safe logging function
//void LogToFile(const char* logMessage) {
//    WaitForSingleObject(logMutex, INFINITE);
//
//    FILE* logFile = fopen("C:\\Users\\user\\CLionProjects\\CPU_Overloader\\thread_log.txt", "a");
//    if (logFile != NULL) {
//        fprintf(logFile, "%s\n", logMessage);
//        fclose(logFile);
//    }
//
//    ReleaseMutex(logMutex);
//}
//
//// Callback function for thread pool work items
//VOID CALLBACK MyWorkCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work) {
//    UNREFERENCED_PARAMETER(Instance);
//    UNREFERENCED_PARAMETER(Context);
//    UNREFERENCED_PARAMETER(Work);
//    double result = 0;
//
//    unsigned long long startTime = GetHighResolutionTimestamp();
//    DWORD processorNumber = GetCurrentProcessorNumber();
//
//// Simulate work with precise timing
//    unsigned long long targetTime = 5; // Target time in milliseconds
//    unsigned long long endTime = startTime + targetTime;
//    unsigned long long currentTime;
//    do {
//        currentTime = GetHighResolutionTimestamp();
//        for (int i = 0; i < 999; i++) {
//            result += log((double)i) * pow(i, 2);
//        }
//    } while (currentTime < endTime && !stop_threads);
//
//    unsigned long long actualTime = GetHighResolutionTimestamp() - startTime;
//    char logBuffer[128];
//    snprintf(logBuffer, sizeof(logBuffer), "Thread finished in %llu ms on processor %lu", actualTime, processorNumber);
//    LogToFile(logBuffer);
//
//// Decrement the count of pending jobs
//    InterlockedDecrement(&pendingJobs);
//}
//
//
//// Thread function for manual thread management
//unsigned __stdcall ThreadFunction(void* pContext) {
//    int coreIndex = *((int*)pContext); // Determine the core index
//    DWORD_PTR affinityMask = (DWORD_PTR)1 << coreIndex;
//    SetThreadAffinityMask(GetCurrentThread(), affinityMask); // Set affinity to the specified core
//
//    MyWorkCallback(NULL, NULL, NULL); // Call the original callback function
//
//    return 0;
//}
//
//int main() {
//    timeBeginPeriod(1);
//
//    srand((unsigned int)time(NULL));
//
//    if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS)) {
//        printf("Failed to set process priority. Error: %lu\n", GetLastError());
//        return -1;
//    }
//    // Initialize log mutex
//    logMutex = CreateMutex(NULL, FALSE, NULL);
//    if (logMutex == NULL) {
//        printf("Failed to create log mutex.\n");
//        return -1;
//    }
//
//    TP_CALLBACK_ENVIRON CallBackEnviron;
//    InitializeThreadpoolEnvironment(&CallBackEnviron);
//    SetThreadpoolCallbackRunsLong(&CallBackEnviron);
//    // Create a thread pool
//    PTP_POOL pool = CreateThreadpool(NULL);
//    if (!pool) {
//        printf("Failed to create thread pool.\n");
//        return -1;
//    }
//    SetThreadpoolThreadMaximum(pool, NUM_CORES);
//    if (!SetThreadpoolThreadMinimum(pool, NUM_CORES)) {
//        printf("Failed to set the minimum thread count.\n");
//        CloseThreadpool(pool);
//        return -1;
//    }
//
//    int coreIndices[NUM_CORES]; // Array to store core indices for passing to threads
//
//    for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
//        char iterationStartMsg[128];
//        unsigned long long iterationStartTime = GetHighResolutionTimestamp();
//        snprintf(iterationStartMsg, sizeof(iterationStartMsg), "Iteration %d started at %llu ms", iteration + 1, iterationStartTime);
//        LogToFile(iterationStartMsg);
//        stop_threads = 0; // Ensure threads are running for the new iteration
//        pendingJobs = NUM_CORES; // Set pending jobs to the number of cores
//
//        // Create threads and set their affinity
//        for (int i = 0; i < NUM_CORES; i++) {
//            coreIndices[i] = i; // Assign core index
//            threads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFunction, &coreIndices[i], 0, NULL);
//            if (threads[i] == NULL) {
//                printf("Failed to create thread for core %d.\n", i);
//                // Cleanup and exit if thread creation fails
//                for (int j = 0; j < i; j++) {
//                    if (threads[j] != NULL) {
//                        CloseHandle(threads[j]);
//                    }
//                }
//                return -1;
//            }
//        }
//
//        // Simulate work
//        Sleep(5);
//
//        // Signal threads to stop
//        stop_threads = 1;
//
//        // Wait for all threads to complete
//        WaitForMultipleObjects(NUM_CORES, threads, TRUE, INFINITE);
//
//        // Reset stop_threads for the next iteration
//        stop_threads = 0;
//
//        // Close thread handles
//        for (int i = 0; i < NUM_CORES; i++) {
//            CloseHandle(threads[i]);
//        }
//    }
//
//    CloseThreadpool(pool);
//    printf("All work items have completed across %d iterations.\n", NUM_ITERATIONS);
//    CloseHandle(logMutex);
//    timeEndPeriod(1);
//    return 0;
//}

