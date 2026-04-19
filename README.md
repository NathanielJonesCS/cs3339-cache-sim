# Cache Simulator

A cache simulator written in C++ for CS3339 - Computer Architecture.

## Description

This program simulates the behavior of a configurable set-associative cache with LRU replacement policy. Given a cache configuration and a sequence of memory addresses, it reports whether each reference is a hit or miss.

## Building

```bash
g++ -o cache_sim cache_sim.cpp
```

## Running

```bash
./cache_sim num_entries associativity input_memory_reference_file
```

- `num_entries` — total number of cache entries (must be a power of two)
- `associativity` — associativity of the cache (must evenly divide `num_entries`)
- `input_memory_reference_file` — path to a file containing space-separated word addresses

## Output

Results are written to a file named `cache_sim_output` in the current directory. Each line corresponds to one memory reference:

```
[ADDR] : [HIT or MISS]
```

## Example

Given an input file containing:
```
1 3 5 1 3 1
```

Run:
```bash
./cache_sim 4 2 input_memory_reference_file
```

Output (`cache_sim_output`):
```
1 : MISS
3 : MISS
5 : MISS
1 : MISS
3 : MISS
1 : HIT
```