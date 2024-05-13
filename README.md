# Particle Simulation with C++ and Raylib

This project implements a simple particle simulation using C++ and the Raylib library. The simulation models particles interacting in a 2D space under the influence of gravitational forces.

## Features

- **Particle Interaction**: Particles exert gravitational forces on each other based on their masses and positions.
- **Real-time Visualization**: The simulation provides real-time visualization of particle movements and interactions.
- **User Interaction**: Users can interact with the simulation by spawning particles with different properties using keyboard inputs.

## Controls

- **Spawn Particle**: Press `D` to spawn a particle with a large mass (star-like).
- **Adjust Velocity**: Press `W` to spawn a particle with a small mass (regular particle). Press `]` to increase the initial velocity of regular particles, and `[` to decrease it.
- **Clear Particles**: Press `ENTER` to clear all particles from the simulation.

## Technologies Used

- **C++**: Used for implementing the simulation logic.
- **Raylib**: A simple and easy-to-use library for game development in C++. Raylib is used for rendering graphics and handling user input.
- **OpenGL**: Raylib utilizes OpenGL for hardware-accelerated rendering.
- **Git**: Version control system for tracking changes in the project.

## How to Use

1. Clone the repository to your local machine.
2. Ensure you have a C++ compiler and Raylib installed on your system.
3. Compile the source code using your preferred C++ compiler (e.g., g++, clang++).
4. Run the compiled executable.
5. Interact with the simulation using keyboard inputs as described in the Controls section.
6. Enjoy observing the gravitational interactions between the particles in real-time.

## File Structure

- `particle.h`: Contains the declaration of the Particle class.
- `main.cpp`: Contains the main source code for the particle simulation.
