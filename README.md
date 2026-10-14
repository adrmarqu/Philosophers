# Philosophers

A 42 School project simulating Dijkstra's classic **Dining Philosophers Problem** to study concurrent programming, multithreading, multiprocessing, and synchronization primitives.

---

## Overview

The project consists of two implementations:
- **Mandatory (`philo`)**: Implemented using **threads** and **mutexes** (shared memory concurrency).
- **Bonus (`philo_bonus`)**: Implemented using **processes** (`fork`) and **POSIX named semaphores** (isolated memory concurrency).

---

## Requirements & Prerequisites

To build and run this project, you need:
- **Operating System**: Linux or macOS.
- **Compiler**: `gcc` or `clang` (supporting C99 or later).
- **Build tool**: `make`.
- **Standard C library** and **POSIX threads library** (`pthread`).

### Installing Prerequisites

#### Debian / Ubuntu / Linux Mint
```bash
sudo apt update
sudo apt install build-essential
```

#### macOS
Install the Xcode Command Line Tools:
```bash
xcode-select --install
```

---

## Compilation

Clone the repository and enter the directory:

```bash
git clone <repository-url>
cd philo
```

### 1. Mandatory Part (`philo`)
Uses threads and mutexes:

```bash
cd philo
make
```
This produces the executable `philo`.

### 2. Bonus Part (`philo_bonus`)
Uses child processes and named semaphores:

```bash
cd philo_bonus
make
```
This produces the executable `philo_bonus`.

### Cleaning Build Files

To remove object files:
```bash
make clean
```

To remove object files and the compiled executable:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

---

## Usage

Both executables take the same command-line arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Or for the bonus version:

```bash
./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Arguments Description

| Parameter | Description |
| :--- | :--- |
| `number_of_philosophers` | The number of philosophers and forks on the table (1 to 200). |
| `time_to_die` | Time in milliseconds before a philosopher dies if they have not started eating. |
| `time_to_eat` | Time in milliseconds it takes for a philosopher to eat. |
| `time_to_sleep` | Time in milliseconds a philosopher spends sleeping. |
| `[number_of_times_each_philosopher_must_eat]` | *(Optional)* The simulation stops once all philosophers have eaten at least this many times. If omitted, the simulation runs until a philosopher dies. |

---

## Examples

### 1. Single philosopher (must die)
```bash
./philo 1 800 200 200
```
*Expected: The philosopher takes one fork and dies after 800ms due to lack of a second fork.*

### 2. Standard simulation (no one should die)
```bash
./philo 5 800 200 200
```
*Expected: The philosophers alternate eating, sleeping, and thinking indefinitely without starving.*

### 3. Simulation with meal limit
```bash
./philo 5 800 200 200 7
```
*Expected: Every philosopher eats at least 7 times, and the simulation terminates cleanly.*

### 4. Tight timing test
```bash
./philo 4 410 200 200
```
*Expected: The philosophers survive continuously without dying.*

### 5. Starvation scenario
```bash
./philo 4 310 200 100
```
*Expected: A philosopher dies because the eating schedule cannot be maintained within 310ms.*

---

## Log Output Format

Every action is printed to stdout in the following format:

```text
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
- `timestamp_in_ms`: Current timestamp in milliseconds since simulation start.
- `X`: Philosopher ID (1 to N).
