# **MISSION IMPOSSIBLE: Whirley Escape**

**Description:**
"Mission Impossible: Whirley Escape" is an exhilarating helicopter game developed using OpenGL and GLUT. Players control a helicopter navigating through space, avoiding obstacles while accumulating points.

**Features:**
1. **Player Interaction:** Control helicopter ascent/descent via keyboard or mouse.
2. **Obstacle Avoidance:** Navigate through obstacles simulating rugged terrain.
3. **Scoring System:** Accumulate points based on distance covered, with score boosts at milestones.
4. **Dynamic Level Up:** Difficulty increases as players progress, introducing faster obstacle movement.
5. **Sound Effects:** Immersive gaming experience with background "Mission Impossible" theme song.

**Installation:**
1. **Install OpenGL:**
   - **Windows:**
     - Download and install the OpenGL libraries suitable for your compiler (e.g., freeglut for MinGW).
     - Set up the necessary environment variables for OpenGL/GLUT.
   - **Linux (Ubuntu):**
     ```bash
     sudo apt-get install mesa-common-dev freeglut3-dev
     ```
   - **MacOS:**
     - OpenGL is included in the macOS system libraries.

2. **Clone Repository:**
```bash
git clone https://github.com/mushfikur-rahman/Mission_Impossible_Whirley_Escape.git
```
3. **Compile Source Code:**
```bash
cd Mission_Impossible_Whirley_Escape
gcc -o game main.c -lopengl32 -lglut32 -lglu32 -lm -mwindows -std=c99
```
4. **Run the Game:**
```bash
./game
```

**Collaborator:**
- [Md Mushfikur Rahman](https://www.linkedin.com/in/md-mushfikur-r-114761194) 
