# Digital Differential Analyzer (DDA) Examples 🖥️

## Overview

This repository contains three small implementations of the Digital Differential Analyzer (DDA) line algorithm in C, C++, and Python. Each example demonstrates how the DDA algorithm generates points along a line between two coordinates. The C/C++ versions simulate a pixel grid (console output), and the Python version uses Matplotlib to plot the line.

---

## Files

- `dda.c` ✅ (C)
  - Purpose: Simulates a 16×16 pixel grid using a 2D char array. The grid is initialized with `.` and plotted points are marked with `o`.
  - Key behavior: Uses floats for X/Y and increments, rounds to nearest pixel, and inverts Y when printing to simulate a **bottom-left origin** (screen-like coordinates).
  - Build & run:
    - Install a C compiler (gcc/MinGW or Visual Studio).
    - Compile: `gcc -o dda dda.c -lm`
    - Run: `./dda` (or `dda.exe` on Windows)
  - Notes: Change `px_Start`, `py_Start`, `px_End`, `py_End`, or `GRID_SIZE` to try different lines or grid sizes.

- `DigitalDifferentialAnalyzer-Cprogram.cpp` ✅ (C++)
  - Purpose: Very similar to `dda.c` but configured with `GRID_SIZE = 30` by default. Also prints a text-based grid and simulates a bottom-left origin.
  - Build & run:
    - Install a C++ compiler (g++ or MSVC).
    - Compile: `g++ -o dda_cpp DigitalDifferentialAnalyzer-Cprogram.cpp -lm`
    - Run: `./dda_cpp` (or `dda_cpp.exe` on Windows)
  - Notes: Modify the start/end coordinates or `GRID_SIZE` to see different results.

- `digitalDifeerentialAnalizer.py` ✅ (Python)
  - Purpose: Python implementation that computes DDA points and plots them with Matplotlib.
  - Dependencies:
    - Python 3
    - Matplotlib: `pip install matplotlib`
  - Run: `python digitalDifeerentialAnalizer.py`
  - Notes: Coordinates are set in the driver code (`x0,y0` and `x1,y1`); change them to test different lines. The script plots the computed points with small markers.

- `Breseham Line Algorthm.cpp` ✅ (C++)
  - Purpose: Implements Bresenham's line drawing algorithm for efficient integer-based rasterization across all slopes. The program simulates a text-based pixel grid and marks plotted pixels (commonly with `B`).
  - Build & run:
    - Install a C++ compiler (g++ or MSVC).
    - Compile: `g++ -o bresenham "Breseham Line Algorthm.cpp" -lm`
    - Run: `./bresenham` (or `bresenham.exe` on Windows)
  - Notes: Uses integer decision parameters (no floats), faster and more accurate for pixel-perfect lines compared to DDA. Modify start/end coordinates in `main` to test different slopes and directions.

- `MIDPIONT.cpp` ✅ (C++)
  - Purpose: Midpoint Circle Algorithm — draws circles using an efficient integer decision parameter and 8-way symmetry to plot octants simultaneously.
  - Build & run:
    - Install a C++ compiler (g++ or MSVC).
    - Compile: `g++ -o midpoint MIDPIONT.cpp -lm`
    - Run: `./midpoint` (or `midpoint.exe` on Windows)
  - Notes: Set the center `(xc, yc)` and radius `r` in `main` to experiment with different circles. This implementation prints a text grid showing the circle points.

---

## Behavior / Implementation Notes 💡

- The C and C++ examples simulate pixels in a small console grid and mark plotted pixels with `o`.
- The grid printing in C/C++ intentionally inverts Y (`GRID_SIZE - 1 - round(Y)`) to simulate a bottom-left origin (0,0 at lower-left), matching typical screen coordinates.
- Increments (X_Inc, Y_Inc) are computed as `(end - start) / max( abs(dx), abs(dy) )` to step smoothly between the endpoints.
- If you want exact integer-stepped plotting (pixel-perfect DDA), consider rounding or using integer arithmetic variations.

---

## Quick Examples

- To change the line in `dda.c` or the C++ program, edit:
  - `px_Start`, `py_Start`, `px_End`, `py_End` (near the top of `main`)
- To change the Python example, edit `x0, y0, x1, y1` in the `if __name__ == "__main__"` block.

---

## Contribution & License

Feel free to open issues or submit PRs to improve examples, add tests, or add alternative line drawing algorithms (Bresenham, Wu, etc.).

---

Happy experimenting! ✅
