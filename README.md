# Philosophers

This project is an introduction to multi-threads/multi-process programming with the use of mutex and semaphore.The problem that Philosophers deals with is called the Dining Philosophers Problem, which is quite famous in computer science.

![screenshot](/assets/dining_phil.png)

## Acknowledgements:

- Threads?

    - A thread in computer science is short for a thread of execution.
    - Threads are a way for a program to divide (termed "split") itself into two or more simultaneously (or pseudo-simultaneously) running tasks.
    - A thread is a path of execution within a process.
    - A process can contain multiple threads.
    - A thread is also known as lightweight process.
    - All processes have at least one thread called Main Thread , and processes are processed in units of threads.
    - A thread shares with its peer threads few information like code segment, data segment and open files.
    - Threads provide a way to improve application performance through parallelism.

- Types of Threads:

    There are two types of threads :
    - User Level Thread
    - Kernel Level Thread

- Threads run mode:

    A Thread can run in two modes
    - Joinable Mode
    - Detached Mode

- Mutexes (mutual exclusion)?

    - A mutex is a mutual exclusion lock.Only one thread can hold the lock. 
    - Mutexes are used to protect data or other resources from concurrent access. A mutex has attributes, which specify the characteristics of the mutex.

- What is a Race Condition?

    - A race condition occurs when two or more threads can access shared data and try to change it at the same time. Because the thread scheduling algorithm can swap between threads at any time, you don't know the order in which the threads will attempt to access the shared data.

- What is a Deadlock?

    - A deadlock happens when two threads/processes cannot make progress because each one waits for the other to release a lock.

- SEMAPHORE?

    - Semaphore is simply an unsigned int. This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment.

    Semaphores are of two types:
    - Counting Semaphore
    - Binary Semaphore 

    named and unnamed semaphores:
    - Named Semaphores are like process-shared semaphores, except that named semaphores are referenced with a pathname rather than a shared value. Named semaphores are sharable by several processes. Named semaphores have an owner user-id, group-id, and a protection mode.

    Unnamed Semaphores are allocated in process memory and initialized. Unnamed semaphores might be usable by more than one process, depending on how the semaphore is allocated and initialized. Unnamed semaphores are either private, inherited through fork(), or are protected by access protections of the regular file in which they are allocated and mapped.
