# Logger Project

## Overview

This project consists of:

- **Dynamic library `liblogger.so`** — custom logging library.
- **Console application `app`** — demonstrates the library functionality.

Both components are built using GNU Make. All build artifacts are placed into the `build/` directory.

---

## Build

Run from the project root:

```
make
```

## Run

```
./build/bin/app log.txt info
```