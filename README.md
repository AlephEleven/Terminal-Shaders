# Terminal Shaders

Text-based shaders library for the command-line, written in C. Heavily based on the Shadertoy library.

## Table of Contents
* [Features](#features)
* [Examples](#examples)
* [Setup](#setup)
* [Requirements](#requirements)


## Features
- Library for handling 2d and 3d vectors based on cartesian coordinates
- Over >25 functions for implementing shaders
- Easy to create new features with example code
- Customizable window screen and refresh rate

## Examples

### Original Shadertoy demo

![alt text](https://github.com/AlephEleven/Terminal-Shaders/blob/master/results/demo.PNG?raw=true)

### Masterpiece
[Reference](https://www.youtube.com/watch?v=f4s1h2YETNY).

![alt text](https://github.com/AlephEleven/Terminal-Shaders/blob/master/results/masterpiece.PNG?raw=true)

## Setup

Install render.c and shaders.c in same directory and run:

```
gcc render.c -o render -lm; ./render 
```

For best-use on complex shaders, use Raster Fonts 4x6, fullscreen, and set WINDOW_X and WINDOW_Y = 100 in shaders.c

## Requirements

Requires standard C libraries for Linux











