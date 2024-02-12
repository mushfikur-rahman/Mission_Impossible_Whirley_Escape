#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <mmsystem.h>

float bspd = 0.02; // block dx value
char name[25];
float b1x = 50.0, b1y = 0; // block 1 init position
float hm = 0.0; // copter moving dy value
int i = 0, sci = 1;
float scf = 1; // for increment score score_int score_flag
char scs[20], slevel[20]; // to store score_string using itoa() and level as well
int level = 1, lflag = 1, wflag = 1; // level_flag & welcome_flag init w/ 1

void init(void)
{




    srand(time(0));
    b1y = (rand() % 45) + 10; // b/w 10 to 44
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

void drawcopter()
{
    glColor3f(0.7, 1.0, 1.0);
    glRectf(10, 49.8, 19.8, 44.8); // body
    glRectf(2, 46, 10, 48); // tail
    glRectf(2, 46, 4, 51); // tail up
    glRectf(14, 49.8, 15.8, 52.2); // propeller stand
    glRectf(7, 53.6, 22.8, 52.2); // propeller
}

void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void quitGame()
{
    printf("\n\nClose the console window to exit...\n");
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if ((i == 730 || i == -700) || (((int)b1x == 10 || (int)b1x == 7 || (int)b1x == 4 || (int)b1x == 1) && (int)b1y < 53 + (int)hm && (int)b1y + 35 > 53 + (int)hm) || (((int)b1x == 9 || (int)b1x == 3 || (int)b1x == 6) && (int)b1y < 45 + (int)hm && (int)b1y + 35 > 45 + (int)hm) || (((int)b1x == 0) && (int)b1y < 46 + (int)hm && (int)b1y + 35 > 46 + (int)hm))
    {
        glColor3f(0.0, 0.0, 1.0);
        glRectf(0.0, 0.0, 100.0, 100.0);
        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(40, 70, 0, GLUT_BITMAP_HELVETICA_18, "GAME OVER!!!");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(25, 58, 0, GLUT_BITMAP_TIMES_ROMAN_24, "You");
        renderBitmapString(45, 58, 0, GLUT_BITMAP_TIMES_ROMAN_24, "scored:");
        renderBitmapString(70, 58, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs);
        glutSwapBuffers();
        glFlush();
        printf("\nGAME OVER\n\n");
        printf("%s\nYou scored %s", name, scs);
        Sleep(3000);
        quitGame();
    }
    else if (wflag == 1)
    {
        wflag = 0;
        glColor3f(0.0, 0.5, 0.7);
        glRectf(0.0, 0.0, 100.0, 10.0); //ceil
        glRectf(0.0, 100.0, 100.0, 90.0); //floor
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(30, 85, 0, GLUT_BITMAP_HELVETICA_18, "Chittagong University of Engineering and Technology");
        renderBitmapString(41, 80, 0, GLUT_BITMAP_HELVETICA_12, "Pahartoli,Raozan");
        glColor3f(1.0, 1.0, 0.0);
        renderBitmapString(30, 65, 0, GLUT_BITMAP_8_BY_13, "A project for Computer Graphics  Sessional");
         renderBitmapString(30, 60, 0, GLUT_BITMAP_8_BY_13, "Developed by Mushfik & Pranta");
        renderBitmapString(30, 70, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Mission Impossible  : Whirley Escape");
        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(40, 45, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Welcome");
        renderBitmapString(53, 45, 0, GLUT_BITMAP_TIMES_ROMAN_24, name);
        renderBitmapString(36, 30, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Click Here  To Start The Game");
        renderBitmapString(15, 20, 0, GLUT_BITMAP_9_BY_15,"CLICK AND HOLD LEFT MOUSE BUTTON TO GO UP &  RELEASE TO GO DOWN   ");
       renderBitmapString(15, 18, 0, GLUT_BITMAP_9_BY_15,"  OR PRESS W --FOR GOING UP & M --FOR GOING DOWN & Q --FOR QUITING THE GAME   ");

        glColor3f(0.0, 0.0, 0.0);
        drawcopter();
        glutSwapBuffers();
        glFlush();
    }
    else
    {
        glPushMatrix();
        glColor3f(0.0, 0.5, 0.7);
        glRectf(0.0, 0.0, 100.0, 10.0); //ceil
        glRectf(0.0, 100.0, 100.0, 90.0); //floor
        glColor3f(0.0, 0.0, 0.0); //score
        renderBitmapString(1, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Distance:");
        sprintf(slevel, "%d", level); //level
        renderBitmapString(80, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Level:");
        renderBitmapString(93, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, slevel);
        scf += 0.025; //so less as program run very fast
        sci = (int)scf;
        sprintf(scs, "%d", sci);
        renderBitmapString(20, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs);

        glTranslatef(0.0, hm, 0.0);
        drawcopter();

        if (b1x < -10)
        {
            b1x = 50;
            b1y = (rand() % 25) + 20;
        }
        else
            b1x -= bspd;

        glTranslatef(b1x, -hm, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glRectf(b1x, b1y, b1x + 5, b1y + 35); //block 1
        glPopMatrix();
        glutSwapBuffers();
        glFlush();
    }
}

void moveHeliU(void)
{
    hm += 0.05;
    i++;
    glutPostRedisplay();
}

void moveHeliD()
{
    hm -= 0.05;
    i--;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(moveHeliU);
        else if (state == GLUT_UP)
            glutIdleFunc(moveHeliD);
        break;
    default:
        break;
    }
}

void keys(unsigned char key, int x, int y)
{
    if (key == 'w')
        glutIdleFunc(moveHeliU);
    if (key == 'm')
        glutIdleFunc(moveHeliD);

   if (key == 'q')
    {
       printf("\nYou quit the game.\n");
        quitGame();
    }
}

int main(int argc, char** argv)
{
    printf("Enter your name to play: ");
    scanf("%s", name);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(90, 90);
    glutCreateWindow("Mission Impossible  : Whirley Escape");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    sndPlaySound("mission impossible theme song.wav", SND_ASYNC);
    glutMainLoop();
    quitGame();
    return 0;
}
