# Carryall
Useful C++ libraries for projects

# Getting started
## Prerequisites
### Mandatories  
* pthread

### Optionals
* clang-format (version >= 8.0): `apt install clang-format-8`
* [peanuts](https://gitlab.com/kimye/peanuts)'s repository access to build tests

## Installation
1. Clone the current repository: `git clone https://gitlab.com/project/kimye/carryall.git`
2. Install submodules:
* `git submodule sync --recursive`
* `git submodule update --init --recursive`
3. Build: `make`

# API
* Blocking-Queue: **ToDo**
* Command-Line: **ToDo**
* Semaphore: **ToDo**
* Worker: **ToDo**

# Exemples
**ToDo**

# ToDo
- Fill README
- build dynamic libs (i.e. libcarryall.so): `make dynamic`
- build static libs (i.e. libcarryall.a): `make static`
- `make` default usage should only be `make dynamic`
