# cub3D 🎮 - 42 School Lisbon

### Table of Contents
* [Introduction](#introduction-)
* [How to Install](#how-to-install-️)
* [How to Use?](#how-to-use-)
* [Technical Challenges](#technical-challenges-)
* [Project Objectives](#project-objectives-)
* [Features](#features-)
* [Conclusion](#conclusion-)

## Introduction 📖

cub3D is a 42 School project that explores the world of Raycasting. Inspired by the legendary **Wolfenstein 3D**, the goal was to create a dynamic 3D graphical interface from a 2D map using C and the MinilibX (MLX) library.

The project focuses on calculating the perspective of walls in real-time based on the player's position and orientation, managing textures, and ensuring a smooth, flicker-free rendering experience at a high frame rate.

## How to Install 🛠️

**Steps**

To compile and run cub3D, follow these steps:

**Dependencies:**
Ensure you have the following installed on your system:
- MinilibX (MLX) dependencies (X11, Xext, AppKit depending on OS)
- gcc / clang
- make

**Building the Project:**
```bash
make
```
## How to Use? 👨‍💻

After building the project, launch the engine by providing a map file (with the `.cub` extension):

```bash
./cub3D maps/map.cub
```

## Controls:

W, A, S, D: Move the player.

Left/Right Arrows: Rotate the camera.

ESC / Close Window: Exit the game safely.

## Technical Challenges 🎯
The core of cub3D is the Raycasting Algorithm (DDA):

Vector Math: Calculating ray direction and distance to the nearest wall using Euclidean and Manhattan geometry.

Fish-eye Correction: Applying trigonometric adjustments to prevent wall distortion.

Texture Mapping: Determining exactly which pixel of a texture (North, South, East, West) should be rendered based on the wall hit point.

## Project Objectives 🎯
The cub3D project develops a deep understanding of:

Graphics Programming: Interacting with pixels and buffers using MinilibX.

Mathematical Logic: Implementation of DDA (Digital Differential Analyzer) algorithm.

Event Handling: Managing keyboard and mouse inputs to provide a real-time experience.

Parsing: Handling .cub files, validating maps (walls, player start), and loading custom textures.

Optimization: Ensuring the rendering loop is efficient enough to maintain a stable FPS.

## Features
Key features implemented in cub3D:

Raycasting Engine: Smooth 3D navigation in a 2D environment.

Collision Detection: Players cannot walk through walls.

Custom Textures: Different textures for North, South, East, and West faces.

Floor & Ceiling Colors: Configurable colors via the .cub file.

Robust Parsing: Detailed error handling for invalid maps or missing assets.

## Conclusion ✅
cub3D was a challenging dive into the intersection of mathematics and software engineering. It required me to shift from purely logical backend thinking to a more visual, geometry-based approach.

This project was developed by me and @hbourlot. It significantly improved my skills in C, memory management, and performance-oriented programming.

Feel free to explore the source code or test your own maps!
