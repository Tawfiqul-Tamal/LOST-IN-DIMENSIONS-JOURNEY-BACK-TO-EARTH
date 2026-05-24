<<<<<<< HEAD
# LOST-IN-DIMENSIONS-JOURNEY-BACK-TO-EARTH
=======
# 🌌 Lost in Dimensions: Journey Back to Earth

A 2D side-scrolling platformer game built with **C++ and OpenGL (GLUT)** as a Computer Graphics course project.

## Level's

| Level | Role |
|------|------|
| Level 0 |  Intro Screen, Character Movement |
| Level 1 |  Bridge Scene, Coins, Portals, Rain |
| Level 2 |  Ocean Scene, Fire Obstacle, Physics |
| Level 3 |  Dimension Scene, Zombie Enemy |

---

## 🎮 Game Overview

The player is lost across four surreal dimensions and must navigate through each level by collecting coins, avoiding obstacles, and stepping through portals to reach the next world — ultimately journeying back to Earth.

---

## 🗺️ Levels

| Level | Name | Description |
|-------|------|-------------|
| 0 | **Earth / Intro** | Starting screen with cityscape. Step into the right portal to begin. |
| 1 | **The Bridge** | A night-time bridge over a river. Collect coins, toggle rain, reach the right portal. |
| 2 | **Ocean World** | Rocky cliffs over a glowing ocean. Avoid the fire. Collect coins across platforms. |
| 3 | **Lost Dimension** | An alien landscape with mountains, lava, and a zombie enemy. Reach the final portal. |

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `A` | Move Left |
| `D` | Move Right |
| `SPACE` | Jump |
| `R` | Start Rain *(Level 1 only)* |
| `S` | Stop Rain *(Level 1)* / Move Down *(Level 3)* |
| `W` | Move Up *(Level 3)* |
| `K` | Angular Jump *(Level 2)* |
| `X` | Exit Game |

---

## ⚙️ How to Compile and Run

### Requirements
- C++ compiler (g++ / MinGW on Windows)
- OpenGL + GLUT library

### Windows (MinGW)
```bash
g++ main.cpp -o game -lfreeglut -lopengl32 -lglu32
./game
```

### Linux
```bash
g++ main.cpp -o game -lGL -lGLU -lglut
./game
```

---

## ✨ Features

- 4 unique hand-drawn levels using OpenGL primitives
- Coin collection system across all levels
- Portal-based level transitions (forward and backward)
- Jump physics with gravity simulation
- Rain toggle animation (Level 1)
- Animated stars (Level 1)
- Fire obstacle with collision detection (Level 2)
- Moving zombie enemy (Level 3)
- Player death on hazard collision
- DDA line drawing algorithm (Level 2)
- Bresenham's line algorithm (Level 3)

---

## 📁 Project Structure

lost-in-dimensions/
│
├── main.cpp          # Full game source code
├── README.md         # Project documentation
└── .gitignore        # Ignores compiled binaries


---



## 📚 Course Information

> Computer Graphics Lab Project  
> Department of Computer Science & Engineering

## 📜 Copyright

© 2026 Md. Tawfiqul Islam Tamal.  
All rights reserved.  

This project *Lost in Dimensions: Journey Back to Earth* was developed as part of the Computer Graphics Lab course in the Department of Computer Science & Engineering, AIUB.  
The source code and assets are provided for educational purposes. Redistribution or use outside academic contexts requires prior permission.

## 📜 License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

>>>>>>> 669d8f48e23698b7972c9ba8627eb2c7d158fe58
