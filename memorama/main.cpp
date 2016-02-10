

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

float t=-1.0;
float delta=0.1;

int turnos = 0;
int sumaTotal = 0;
bool start = false;

int mazo[16] = {5,4,6,7,1,2,3,0,4,3,0,7,1,5,6,2};
bool expuesta[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};


void myTimer(int i) {
    if ( start){
        sumaTotal += 1;
    }
    
    delta = 0.1;
    t += delta;
    glutPostRedisplay();
    glutTimerFunc(100,myTimer,1);
}



int	screenWidth = 640, screenHeight = 640;

void reshape(int ancho, int alto) {
    
    screenHeight = alto;
    screenWidth = ancho;
    
    glViewport(0.0,0.0,(GLdouble) ancho,(GLdouble)  alto);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    // hace la conversion a openGL
    gluOrtho2D( 0.0,(GLdouble) ancho, 0.0,(GLdouble)  alto);
    
    
}

void dibujaInfo() {
    
    GLint k;
    char mensaje3 [200] = "";
    sprintf(mensaje3,"Turns: %d", turnos);
    glColor3f(1, 1, 1);
    glRasterPos2f(500, 200); // inicializa raster position
    for (k=0; mensaje3[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje3[k]);
    }
    
    char mensaje4 [200] = "";
    sprintf(mensaje4, "%s", "Autores: Jorge Perales, Matricula:00813101");
    glColor3f(1, 1, 1);
    glRasterPos2f(20, 130); // inicializa raster position
    for (k=0; mensaje4[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje4[k]);
    }
    char mensaje5 [200] = "";
    sprintf(mensaje5, "%s", "Diego Aleman, Matricula:11934700");
    glColor3f(1, 1, 1);
    glRasterPos2f(100, 100); // inicializa raster position
    for (k=0; mensaje5[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje5[k]);
    }
    
    char mensaje [200] = "";
    sprintf(mensaje, "%s", "I-Iniciar, P-Pausa, R-Reset");
    glColor3f(1, 1, 1);
    glRasterPos2f(100, 70); // inicializa raster position
    for (k=0; mensaje[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje[k]);
    }
    
    char mensaje2 [200] = "";
    sprintf(mensaje2, "%s", "Esc-Salir");
    glColor3f(1, 1, 1);
    glRasterPos2f(400, 70);
    for (k=0; mensaje2[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje2[k]);
    }
}

void cronometro() {
    
    GLint k;
    
    char msg [200] = "";
    
    int a,b,c;
    
    float x = sumaTotal / 10.0;
    b = x;
    
    x = x - b;
    
    x = x * 10;
    c=x;
    
    a = b /60;
    b = b %60;
    
    
    
    if (b <= 9) {
        sprintf(msg, "%d : 0%d : %d", a, b , c);
    } else {
        sprintf(msg, "%d : %d : %d", a, b , c);
    }
    
    
    glColor3f(1, 1, 1);
    glRasterPos2f(50, 200); // inicializa raster position
    for (k=0; msg[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[k]);
    }
    
    
    
}

void myDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //Color del background
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
    cronometro();
    dibujaInfo();
    
    glutSwapBuffers();
    
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    switch (theKey)
    {
        case 'I':
        case 'i':
            start = true;
            break;
            
        case 'R':
        case 'r':
            start = false;
            sumaTotal = 0;
            break;
        case 'P':
        case 'p':
            start = false;
            break;
            
        case 27:
            exit(-1);
            
        default:
            break;		      // do nothing
    }
}





int main( int argc, char ** argv ) {
    
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB); // dos buffers
    glutInitWindowSize( screenWidth, screenHeight );
    glutInitWindowPosition( 0, 0 );// create window
    glutCreateWindow( "Memorama" );
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(100,myTimer,1);
    
    
    glutMainLoop();
    return 0;
    
    
}
