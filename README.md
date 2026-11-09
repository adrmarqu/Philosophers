# Philosophers - 42 Barcelona

Philosophers is a concurrent programming project from the 42 Barcelona curriculum. The project models Edsger Dijkstra's famous Dining Philosophers Problem to study the challenges of concurrent systems, including thread lifecycle, process management, race conditions, deadlocks, and shared resource synchronization.

The project provides two independent implementations:
- Mandatory Part (philo): Implemented using POSIX threads (pthread) and mutual exclusion locks (mutexes) in a shared memory environment.
- Bonus Part (philo_bonus): Implemented using distinct child processes (fork) and POSIX named semaphores (sem_open, sem_wait, sem_post) in isolated address spaces.

# Prerequisites

To compile and execute the simulation, you will need:

- A C compiler: gcc or clang (supporting C99 or later)
- GNU Make
- POSIX threads library (pthread) and standard C library
- Compatible Operating System: Linux or macOS

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/philosophers.git
cd philosophers
```

No external packages or dependencies are required. Both implementations rely solely on native POSIX system calls.

# Execution

### 1. Mandatory Implementation (philo)

Compile and launch using threads and mutexes:
```bash
cd philo
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### 2. Bonus Implementation (philo_bonus)

Compile and launch using processes and named semaphores:
```bash
cd ../philo_bonus
make
./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Command Line Arguments

- number_of_philosophers: The count of philosophers seated at the round table (and the number of forks).
- time_to_die: Time in milliseconds before a philosopher starves if they do not start eating.
- time_to_eat: Time in milliseconds required to finish a meal while holding two forks.
- time_to_sleep: Time in milliseconds a philosopher spends sleeping after finishing their meal.
- number_of_times_each_philosopher_must_eat: (Optional) If specified, the simulation terminates cleanly once every philosopher has eaten at least this many meals. If omitted, the simulation runs indefinitely until a philosopher dies.

### Simulation Examples

- Single philosopher scenario (must die after time_to_die):
  ./philo 1 800 200 200
- Standard infinite survival simulation (no philosopher should die):
  ./philo 5 800 200 200
- Finite simulation terminating on meal completion:
  ./philo 5 800 200 200 7
- Stress test under tight deadlines:
  ./philo 4 410 200 200

# Project Structure

```
philosophers/
├── en.subject.pdf           # 42 School English project specification
├── es.subject.pdf           # 42 School Spanish project specification
├── philo/                   # Mandatory part (Threads and Mutexes)
│   ├── Makefile             # Build automation for philo executable
│   ├── philo.h              # Header declarations and state structs
│   └── src/                 # Threads, mutexes, timing, and death monitoring
└── philo_bonus/             # Bonus part (Processes and Semaphores)
    ├── Makefile             # Build automation for philo_bonus executable
    ├── philo_bonus.h        # Header declarations for bonus
    └── src/                 # Child processes, named semaphores, and cleanup
```

# Commands and Makefile Targets

Both philo/ and philo_bonus/ provide a standard Makefile with these targets:

- make or make all: Compiles the source files and produces the binary
- make clean: Removes compiled object files (.o)
- make fclean: Removes object files and the compiled executable
- make re: Rebuilds the executable from scratch

# Concurrency and Architecture Features

- Log Synchronization: State transitions (taking forks, eating, sleeping, thinking, dying) are guarded by dedicated output mutexes or semaphores to guarantee messages are never garbled or interleaved.
- Microsecond Timing Precision: Custom timestamping and sleep routines compensate for system scheduling jitter, ensuring philosophers do not die prematurely due to thread starvation.
- Clean Resource Cleanup: All mutexes, threads, named semaphores, and child processes are systematically joined, unlocked, closed, unlinked, and terminated upon simulation end.

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
