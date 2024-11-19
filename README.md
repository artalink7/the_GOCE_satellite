# GOCE Satellite Sensityvity Toy Model

This repository contains a toy model to test the sensitivity of the GOCE satellite to variations in Earth's gravitational field caused by a hypothetical mountain range.

The **GOCE** (Gravity Field and Steady-State Ocean Circulation Explorer) satellite orbited Earth from 2009 to 2013 at an altitude of approximately 250 km. It analyzed variations in Earth's gravitational field with an instrument sensitivity of δg/g = 1E-13.

## Problem Setup

### Overview
The model simplifies the physical problem: 
+ The Earth is modelled as a circle with radius R, centred at the origin of a 2D reference frame.
+ The GOCE satellite's orbit is discretized into 1000 points for computational purposes. 
+ A fictitious mountain range is represented as 100 consecutive circles on Earth's surface. These "mountains" are positioned along a contour defined by (-R,θ), where: 
  + R is the radial distance from the origin (Earth's radius).
  + θ is the angular position in radians.

### Objectives
The goal is to determine whether the GOCE satellite can detect the gravitational influence of the mountain range. 

### Steps:
1. Compute the gravitational field experienced by the satellite at each point in its orbit, considering only Earth's bare field.
2. Add the gravitational contribution of the mountain range to Earth's field at each point.
3. Calculate the modulus variations of the total gravitational field and compare them to the sensitivity threshold (1E-13).

### Output
The Program generates two output files:
+ A PDF graph showing the variations in the gravitational field modulus as a function of the angle θ.
+ A TXT file listing all variations exceeding the GOCE satellite's sensitivity threshold (1E-13).

## How to Use

### Prerequisite
+ A C++ environment, preferably with the ROOT libraries installed (for generating the PDF graph).
### Compilation
1. Use the provided `makefile` for quick compilation. Simply run:
```
make
```
2. This will compile all scripts in the directory.

### Running the program
+ By default, the program computes the gravitational variations and generates the output txt file. 
+ If you have ROOT installed, uncomment the `//` lines in the `main` function to produce your custom ROOT canvas.
