# Pixel Souls – 2D Platformer in C

## Overview

**Pixel Souls** is a 2D platformer game written in **C**, inspired by the atmosphere and difficulty of *Dark Souls*, but presented in a **pixel art** style.  
The project uses the **MiniLibX** graphical library to handle window creation, rendering, and user input.

The goal of this project is to explore low-level game programming concepts such as:
- Real-time rendering
- Event handling
- Game loops
- Collision detection
- Basic physics (movement, gravity, jumps)

All of this is done without a game engine, using only C and MiniLibX.

---

## Features

- 2D pixel art platformer gameplay
- Keyboard-controlled character movement
- Dark, minimalist atmosphere inspired by Dark Souls
- Custom game loop and rendering system
- Written entirely in C

---

## Technologies Used

- **C language**
- **MiniLibX** (graphics library)
- **Makefile** for compilation

---

## Requirements

To compile and run the project, you need:

- A Unix-based system (Linux)
- `gcc` compiler
- `make`
- **MiniLibX** installed and correctly configured

On Linux, it typically requires:
- X11 development libraries

---

## Compilation

The project is compiled using a **Makefile**.

To compile the game, simply run:

```bash
make
```

To remove object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To recompile everything from scratch:

```bash
make re
```

---

## Running the Game

After compilation, run the executable:

```bash
./knightOfAshes
```

---

## Controls

 - `← / →`: Move left / right
 - `Space`: Jump
 - `Q`: Fast attack
 - `W`: Strong attack
 - `R`: Roll

---

## Learning Objectives

This project focuses on:

 - Managing memory safely in C
 - Structuring a medium-sized C project
 - Using a graphical library at a low level
 - Understanding how simple games work internally