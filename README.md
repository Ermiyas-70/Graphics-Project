# Interactive Graphic Designs: DHL Logo & Custom Flag (OpenGL / GLUT)

A high-fidelity computer graphics group assignment implementing modular vector designs, primitive geometry matrices, and real-time animation using C++ and the OpenGL Utility Toolkit (GLUT).

---

## 👥 Group Project Work Breakdown Structure (WBS)

Our team modularized the codebase into distinct functional structures to divide development labor:

### 1. Student 1: Letter Asset "D", Custom Flag Blueprint & Global Baselines
* **DHL Logo:** Engineered the composite curves for the letter `D` using trigonometric loops ($\cos(\theta)$ and $\sin(\theta)$) over $75^\circ$ and $-90^\circ$ radial sweep quadrants via `GL_TRIANGLE_FAN` and `GL_POLYGON`.
* **Flag Vector:** Authored the `drawUnionJack()` nested asset layout, layering intersecting `GL_LINES` with customized `glLineWidth` stroke properties over foundational background rectangles.
* **Star Cluster Matrix:** Built a parameterized `drawStar()` sub-routine mapped across a $2\pi$ loop divided into 15 discrete steps ($i \times \frac{2.0 \times \pi}{15.0}$) to render a uniform ring of stars at a translation offset of $(0.65, 0.0)$.

### 2. Student 2: Letter Asset "H" & Matrix Proportions
* **Primitive Generator:** Built the reusable `drawBlock()` module to programmatically render parallel, slanted quadrilaterals across uniform shear slopes.
* **Layout Balancing:** Computed the precise offset spacing bounds (`hShiftX`) to keep the structural segments aligned without manual hardcoding or vertex collision.
* **Testing:** Executed primary matrix scaling benchmarks and viewport clipping boundaries.

### 3. Student 3: Letter Asset "L", Mask Layering & Interactivity
* **Typography:** Structured the vertical stem, base, and fractional corner curve smoothing algorithms for the letter `L`.
* **Negative Space System:** Authored `student3_applyNegativeSpaceMask()`, which layers crisp white clipping blocks over rendered shapes to construct the iconic horizontal speed lines.
* **Interactivity & Main Stack:** Programmed the global transformation chain, double-buffered rendering refreshes, and the automated animation input logic.

---

## 🛠️ Checklist Coverage

| Required Criteria | Status | Technical Details in Code |
| :--- | :---: | :--- |
| **1. Basic Primitives** | ✅ PASSED | Combines `GL_QUADS`, `GL_POLYGON`, `GL_LINES`, and `GL_TRIANGLE_FAN`. |
| **2. Color Handling** | ✅ PASSED | Uses floating-point `glColor3f` maps: Navy Blue (`0.0, 0.13, 0.45`), White (`1.0, 1.0, 1.0`), and Red (`1.0, 0.0, 0.0`). |
| **3. Three Transformations** | ✅ PASSED | Links **Translation** (`glTranslatef`), **Scaling** (`glScalef`), and **Rotation** (`glRotatef`) in a uniform stack. |
| **4. Advanced Bonus Feature** | 🚀 COMPLETE | Interactive **60 FPS Animation Engine**. Mouse left-click toggles a smooth spin cycle around the origin using double buffering (`GLUT_DOUBLE`). |

---

## 🖥️ Environment Setup & Prerequisites

### 🟥 Windows (MinGW / GCC)
1. Download **FreeGLUT** development binaries from Transmission Zero.
2. Link development files inside your compiler directories:
   * Copy `include/GL/*` ➡️ `MinGW\include\GL\`
   * Copy `lib/libfreeglut.a` ➡️ `MinGW\lib\`
   * Copy `bin/freeglut.dll` ➡️ `C:\Windows\System32\` (or the project root directory).

### 🟩 Linux (Ubuntu / Debian)
Install development binaries via the native package manager:
```bash
sudo apt update && sudo apt install build-essential freeglut3-dev libglu1-mesa-dev mesa-common-dev

---
**Developed by:**
 ### Group members                                      	      ID.No
1. Biruk Afera	                                          GUR/01037/16       
2. Endaweke Birhanu        	                              GUR/01144/16
3. Ermiyas Tomas                     	                  GUR/02749/16
4. Bereket wubshet                                        GUR/01016/16
5. Dagmawi Mitiku                      	                  GUR/01039/16
6. Kirubel Workalmahu                                     GUR/01192/16

**Date:** April 2026
===================================================================================================
