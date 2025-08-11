# Philosophers

> _“I never thought philosophy would be so deadly.”_ — 42 School Project

## 📖 Overview
This project is an implementation of the **Dining Philosophers Problem**, a classic concurrency exercise.  
You will learn how to use **threads** and **mutexes** in C to handle shared resources without causing **data races** or **deadlocks**.

Philosophers sit at a round table, alternating between **eating**, **sleeping**, and **thinking**. They need two forks to eat, but forks are limited and must be shared without causing starvation.

---

## 🛠 Features
- Each philosopher is a **thread**.
- Forks are **mutex-protected** to prevent race conditions.
- Accurate logging with timestamps in milliseconds.
- Stops simulation when:
  - A philosopher dies (doesn’t eat in `time_to_die`).
  - _(Optional)_ All philosophers have eaten at least `number_of_times_each_philosopher_must_eat`.
- No global variables — clean and modular design.

---

## 📦 Requirements
- **Language**: C (Norm-compliant for 42 projects)
- **Compiler**: `cc` with flags `-Wall -Wextra -Werror`
- **Libraries used**:
  - `pthread` (POSIX threads)
  - `unistd.h`, `sys/time.h`, `stdlib.h`, `stdio.h`

---

## 📂 Project Structure
```
philo/
├── Makefile
├── philo.h
├── src/
│   ├── philo.c
│   ├── init.c
│   ├── routine.c
│   ├── utils.c
│   └── ...
└── philo_subject.pdf
```

---

## ⚙️ Compilation
Run:
```bash
make
```
This creates the `philo` executable.

Clean object files:
```bash
make clean
```

Remove executable and object files:
```bash
make fclean
```

Recompile everything:
```bash
make re
```

---

## ▶️ Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments**:
1. `number_of_philosophers` — Number of philosophers and forks.
2. `time_to_die` *(ms)* — Time without eating before a philosopher dies.
3. `time_to_eat` *(ms)* — Eating duration.
4. `time_to_sleep` *(ms)* — Sleeping duration.
5. *(Optional)* `number_of_times_each_philosopher_must_eat` — Simulation stops when all have eaten this many times.

---

### Example
```bash
./philo 5 800 200 200
```
Five philosophers, each dies if they don’t eat within **800 ms**.

```bash
./philo 5 800 200 200 7
```
Same as above, but simulation stops when all have eaten **7 times**.

---

## 📜 Log Format
```
[timestamp_in_ms] [philosopher_id] has taken a fork
[timestamp_in_ms] [philosopher_id] is eating
[timestamp_in_ms] [philosopher_id] is sleeping
[timestamp_in_ms] [philosopher_id] is thinking
[timestamp_in_ms] [philosopher_id] died
```

---

## 📚 Learning Objectives
- Understanding **thread creation** (`pthread_create`)
- Mutex usage (`pthread_mutex_lock`, `pthread_mutex_unlock`)
- Time management in milliseconds
- Preventing **data races** & **deadlocks**
- Writing **deterministic** concurrent programs

---

## 📄 License
This project follows the 42 school project guidelines and is intended for educational purposes.

---

**Author**: [Rama Albluwi](https://github.com/ramabluwi)
