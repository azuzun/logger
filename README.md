# Console Input Logger

[![C++ Build](https://github.com/azuzun/logger/actions/workflows/ci.yml/badge.svg)](https://github.com/azuzun/logger/actions/workflows/ci.yml)

A small C++ console application that demonstrates character-by-character standard-input handling and immediate file output.

## Overview

The program reads characters entered into its terminal and writes them to `keystrokes.txt`. Each character is flushed to disk immediately, making the project a focused demonstration of C++ file streams, terminal input, error handling, and timed execution.

Despite the repository name, this application does **not** capture system-wide keyboard events or run in the background. It only records characters supplied to its own standard input.

## Key Features

- Reads one character at a time from standard input.
- Writes the current session to `keystrokes.txt`.
- Flushes each character immediately instead of waiting for the stream buffer to fill.
- Reports an error when the output file cannot be opened.
- Includes a separate `std::ofstream` example.

## Technologies Used

| Technology | Purpose |
| --- | --- |
| C++ | Application implementation |
| C++ standard library | Console input, file output, timing, and threading |
| CMake | Reproducible project builds |
| GitHub Actions | Linux and macOS build verification |

## Project Architecture

The repository contains two independent executables:

| Target | Source | Responsibility |
| --- | --- | --- |
| `console_input_logger` | `src/main.cpp` | Reads terminal input and records it in `keystrokes.txt` |
| `ofstream_example` | `examples/ofstream_example.cpp` | Demonstrates basic file creation and output |

The application source has been preserved as originally written. Repository organization and supporting GitHub files were improved without changing program behavior.

## Requirements

- A C++17-compatible compiler, such as Clang or GCC
- CMake 3.16 or newer
- A terminal or command prompt

## Installation

```bash
git clone https://github.com/azuzun/logger.git
cd logger
cmake -S . -B build
cmake --build build
```

## Usage

Run the main application:

```bash
./build/console_input_logger
```

Enter text in the terminal. The application records each character in `keystrokes.txt` and confirms it in the console. Stop the application manually with `Ctrl+C`.

Run the standalone file-stream example:

```bash
./build/ofstream_example
```

This creates `output.txt` in the current working directory.

## Example Input and Output

If the user enters `H`, the application prints:

```text
Keystroke recorded: H
```

The same character is written to `keystrokes.txt`.

## Testing

Build the project and run the configured smoke test:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

The automated smoke test verifies that the standalone `ofstream_example` executable runs successfully. The interactive logger is compiled in continuous integration and should be checked manually because it runs continuously until interrupted.

GitHub Actions performs the build and smoke test on both Ubuntu and macOS.

## Project Structure

```text
logger/
├── .github/
│   └── workflows/
│       └── ci.yml
├── examples/
│   └── ofstream_example.cpp
├── src/
│   └── main.cpp
├── .editorconfig
├── .gitignore
├── CMakeLists.txt
└── README.md
```

## Technical Challenges and Solutions

| Challenge | Current approach |
| --- | --- |
| Confirming that the log is writable | Checks `is_open()` before entering the input loop |
| Persisting input without a delayed buffered write | Calls `flush()` after every character |
| Avoiding a tight loop during interactive use | Pauses for 100 milliseconds after each iteration |
| Keeping generated files out of Git | Ignores build directories and runtime output files |

## Limitations and Future Improvements

The following are proposed improvements and are not part of the current implementation:

- Detect end-of-file and exit the input loop cleanly.
- Handle shutdown without requiring an external interrupt.
- Accept the output path as a command-line option.
- Add testable input/output abstractions and automated unit tests.
- Add append-versus-overwrite configuration for existing log files.

## Responsible Use

Use the program only with input you are authorized to record. The current implementation is limited to its own terminal input and is intended as a file-stream learning project.

## License

No license has been selected. All rights remain with the repository owner unless a license is added later.
