# Interactive Graphic Designs: DHL Logo & Custom Flag Vector Assets (OpenGL / GLUT)

A high-fidelity structured computer graphics group assignment that recreates, partitions, and animates vector designs using primitive geometry matrices. Built natively using C++ and the OpenGL Utility Toolkit (GLUT), this repository combines an interactive silhouette of the historic DHL branding logo with a custom maritime flag blueprint featuring a complex Union Jack quadrant and a 15-star ring.

---

## 👥 Group Project Work Breakdown Structure (WBS)

To meet our project development timeline, our team cleanly modularized the codebase into distinct functional structures. Each member was responsible for specific geometric assets and their underlying mathematical layouts:

### 1. Student 1: Letter Asset "D", Custom Flag Blueprint & Global Baselines
* **Responsibilities:**
  * **DHL Logo Portion:** Engineered the intricate composite curves for the letter `D` by computing procedural trigonometric arrays over a fixed radial sweep angle ($75^\circ$ and $-90^\circ$ quadrants). Calculates custom vector steps using standard geometric loops utilizing $\cos(\theta)$ and $\sin(\theta)$ to plot continuous smooth vertex points via `GL_TRIANGLE_FAN` and `GL_POLYGON`. Positioned the initial far-left background baseline extension structures.
  * **Flag Vector Portion:** Authored the comprehensive procedural rendering matrix for the custom flag. This included engineering a localized `drawUnionJack()` nested asset assembly utilizing overlapping lines (`GL_LINES`) with customized stroke widths (`glLineWidth`) and geometric bounds (`drawRectangle()`) to form the Saint George and Saint Andrew cross configuration.
  * **Star Cluster Matrix:** Designed a parameterized `drawStar()` sub-routine and calculated a distribution matrix using a $2\pi$ radial loop partitioned into 15 discrete divisions ($i \times \frac{2.0 \times \pi}{15.0}$) to perfectly generate a circular ring of stars centered at a translation offset of $(0.65, 0.0)$.

### 2. Student 2: Letter Asset "H" & Matrix Proportions
* **Responsibilities:**[cite: 1]
  * Constructed the modular framework helper function `drawBlock()` to automatically handle the construction of parallel, slanted quadrilaterals across multiple shear slopes[cite: 1].
  * Computed precise layout balancing logic to calculate individual spacing gaps (`hShiftX`), keeping the horizontal crossbars structurally aligned with the vertical columns without overlapping[cite: 1].
  * Conducted primary matrix scaling and viewport safety testing[cite: 1].

### 3. Student 3: Letter Asset "L", Mask Layering & Interactivity
* **Responsibilities:**[cite: 1]
  * Structured the primary stem, baseline, and foundational smooth curve radius of the letter `L`[cite: 1].
  * Designed the negative-space masking system (`student3_applyNegativeSpaceMask`). This function intentionally renders white clipping strips over existing geometry layers to seamlessly construct the iconic horizontal speed lines across all letters without breaking underlying structural loops[cite: 1].
  * Implemented the Global Matrix Transformation chain, incorporating the **Bonus Challenge** mouse callback interactive trigger and automated double-buffered rendering frame refreshes[cite: 1].

---

## 🛠️ Grading Rubric Checklist Coverage

| Required Criteria | Implementation Status | Technical Details in Code |
| :--- | :---: | :--- |
| **1. Basic Primitives** | ✅ PASSED | Utilizes a rich suite of primitives including `GL_QUADS`, `GL_POLYGON`, `GL_LINES`, and `GL_TRIANGLE_FAN`. |
| **2. Color Handling** | ✅ PASSED | Leverages floating-point `glColor3f` arrays mapping complex real-world monochromatic and historical color fields (Deep Maritime Navy Blue `0.0, 0.13, 0.45`, Crisp White `1.0, 1.0, 1.0`, and Pure Red `1.0, 0.0, 0.0`). |
| **3. Three Distinct Transformations** | ✅ PASSED | Combines **Translation** (`glTranslatef`), **Scaling** (`glScalef`), and **Rotation** (`glRotatef`) operations within a unified stack[cite: 1]. |
| **4. Advanced Bonus Feature** | 🚀 COMPLETE | High-performance interactive **Animation Loop Engine**. Left-clicking inside the viewport dynamically toggles a smooth $60\text{ FPS}$ rotative spin cycle around the matrix origin point using double buffering (`GLUT_DOUBLE`)[cite: 1]. |

---

## 🖥️ Environment Setup & Prerequisites

Before compiling, you must have an environment capable of linking OpenGL/GLUT[cite: 1]. 

### 🟥 For Windows (Using MinGW / GCC)
1. Download the **FreeGLUT** development binaries (e.g., from Transmission Zero)[cite: 1].
2. Extract the files and map them to your system directories[cite: 1]:
   * Copy `include/GL` files inside your MinGW compiler path: `MinGW\include\GL\`[cite: 1].
   * Copy `lib/libfreeglut.a` (or `libglut32.a`) to `MinGW\lib\`[cite: 1].
   * Move `bin/freeglut.dll` to `C:\Windows\System32\` (or leave it in your active execution directory)[cite: 1].

### 🟩 For Linux (Ubuntu / Debian / Mint)
Install the primary development tools and mesa-util architecture directly from your native packet manager[cite: 1]:
```bash
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev mesa-common-dev
