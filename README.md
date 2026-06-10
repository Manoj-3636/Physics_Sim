# Physics_Sim

A real-time 2D spring-mass physics simulation engine written in **C11**, rendered with [raylib](https://www.raylib.com/). Demonstrates physics simulation using a **Symplectic Euler integrator**, **Hooke's law with axial damping**, interactive mouse controls, and live energy tracking.

## Features

- **Spring-Mass Simulation** — Supports rigid bodies connected by springs with configurable stiffness, rest length, and damping
- **Symplectic Euler Integration** — Semi-implicit integrator for stable energy behavior
- **Interactive Mouse Control** — Click and drag bodies with a spring-damper "pointer"; visual spring line drawn in real time
- **Live Stats HUD** — Shows FPS, initial total energy, and current total energy (kinetic + gravitational potential + elastic)
- **Demo Scenes** — Built-in cloth simulation and spring pendulum demos (see `src/demos.c`)
- **Real-time Rendering** — Bodies rendered in red, springs as animated coil-line segments

## Physics Engine

| Property | Value / Model |
|----------|---------------|
| Integrator | Symplectic (Semi-Implicit) Euler |
| Gravity | `980.0f` units/s² (downward) |
| Drag | `1.5f` velocity-dependent drag |
| Damping | Axial spring damping to reduce oscillation |
| Body Types | Circles and rectangles |
| Fixed Bodies | Mass = `0.0f` (pinned / immovable) |

## Controls

| Input | Action |
|-------|--------|
| **Left Click + Hold** | Grab a body and pull it with a spring cursor |
| **Left Click Release** | Release the body |

The grab cursor acts as a **spring-damper** (`stiffness=300`, `damping=15`) pulling the exact click-point on the body, allowing realistic manipulation.

## Building

### Prerequisites

- **CMake ≥ 3.20**
- **C11 compiler** (GCC/Clang)
- **raylib** installed system-wide at `/usr/local/lib/libraylib.a` with headers in `/usr/local/include`  
  *(If raylib is elsewhere, adjust `CMakeLists.txt`)*

### Compile

```bash
mkdir -p build && cd build
cmake ..
make
```

### Run

```bash
./sim
```

> Window defaults to **2200×1200** fullscreen-like window titled *"Physics Simulation"*.

## Project Structure

```
Physics_Sim/
├── CMakeLists.txt      # CMake build configuration
├── include/
│   ├── world.h         # Core data structures (RigidBody, Spring, World)
│   ├── physics.h       # Physics step & force computation API
│   ├── render.h        # World & stats rendering API
│   ├── demos.h         # Scene setup functions
│   ├── interact.h      # Mouse grab interaction
│   ├── stats.h         # Stats tracking (FPS, energy)
│   └── rigidbody.h     # Rigid body helpers (future)
├── src/
│   ├── main.c          # Main loop: input, physics, render
│   ├── physics.c       # Integrator, gravity, springs, drag, cleanup
│   ├── render.c        # Draw bodies, springs, stats HUD
│   ├── demos.c         # Cloth & pendulum scene generation
│   ├── interact.c      # Mouse pick / spring-pull logic
│   ├── stats.c         # Energy calculations
│   └── rigidbody.c     # Stub
└── .gitignore
```

## Demos

### Cloth Simulation (default in `main.c`)
- **6×6 grid** of bodies
- **Top row pinned** (`mass = 0.0f`)
- **Structural springs** connect horizontal and vertical neighbors
- Stiffness: `2500`, Damping: `10.0`, Spacing: `75 px`

### Spring Pendulum
- 3-body chain with 2 springs
- Demonstrates chained spring forces and energy tracking

> You can switch demos by editing `main.c`:  
> `World* world = SetupClothSimulation();` → `World* world = SetupSpringPendulum();`

## Key Physics Details

### Energy Tracking
The stats module computes total system energy as:

```
E_total = Σ( ½·m·v² )                    // Kinetic
        + Σ( -m·g·y )                    // Gravitational potential
        + Σ( ½·k·(x - x_rest)² )         // Elastic potential
```

### Spring Forces
Each spring applies:
- **Hooke's law force**: `F = k · (|length| - rest_length)` along the spring axis
- **Axial damping**: `F_damp = c · (v₂ - v₁)·û` where `û` is the unit axis vector  
  This damps oscillations only along the spring direction, preserving perpendicular motion.

### Integrator
**Symplectic Euler** (velocity-then-position):
```
v(t+Δt) = v(t) + a(t)·Δt
x(t+Δt) = x(t) + v(t+Δt)·Δt
```

This is more stable for oscillatory systems than explicit Euler and conserves energy better over long runs.


## License

This project is open for personal and educational use. See repository for full licensing details.

---

**Author:** [Manoj-3636](https://github.com/Manoj-3636)  
**Repo:** [Physics_Sim](https://github.com/Manoj-3636/Physics_Sim)
