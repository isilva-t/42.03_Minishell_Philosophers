# Philosophers

![table](./scheme.png)

## Overview
My implementation of the classic dining philosophers problem using threads and mutexes.

In this project, philosophers sit at a round table with a bowl of spaghetti in the middle. Each philosopher needs two forks to eat, and there are as many forks as philosophers. The simulation ends when a philosopher dies of starvation or when all philosophers have eaten a specified number of times.

## Features
- Each philosopher is a separate thread
- Forks are protected by mutexes to prevent race conditions
- Detailed logging of philosopher actions (eating, sleeping, thinking)
- Customizable parameters: number of philosophers, time to die/eat/sleep, optional meals limit
- Deadlock prevention with fork priority assignment
- Clean memory management with no leaks

## File Structure
I organized my code with a numbered file structure for better readability. This approach helps me visualize the program flow more easily:

```
00_*.c  # Main program flow
11_*.c  # Argument validation
21_*.c  # Data parsing
31_*.c  # Memory allocation
4*_*.c  # Thread operations
7*_*.c  # Mutex handling
9*_*.c  # Cleanup
```

## Some Implementation Details

### Bitwise Operations for Error Tracking
I played around with bitwise operations for error handling during argument parsing. It's a fun way to track multiple errors at once:

```c
void ft_check_if_have_bigger_than_int_max(t_args *d)
{
    if (d->nb_philos > INT_MAX)
        d->error_philo = (1 << 5) | d->error_philo;
    if (d->time_to_die > INT_MAX)
        d->error_philo = (1 << 4) | d->error_philo;
    // ...
}
```

This lets me report all errors at once instead of stopping at the first one. Not the most practical approach for all projects, but it was a good learning experience!

### Thread Synchronization
I implemented a few concurrency concepts that I learned along the way:
- Using mutexes to protect shared resources
- Preventing deadlocks by having philosophers grab forks in a specific order
- Adding small delays between thread startups to reduce contention
- Trying to keep the monitoring efficient

## Usage
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:
```
./philo 5 800 200 200 7  # 5 philosophers, must each eat 7 times
./philo 4 410 200 200    # 4 philosophers, run until someone dies
```



