

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
int clickCarta = 0;

int sumaTotal = 0;
bool start = false;

int mazo[16] = {5,4,6,7,1,2,3,0,4,3,0,7,1,5,6,2};
bool expuesta[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
bool destapado[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};


void myTimer(int i) {
    if ( start){
        sumaTotal += 1;
    }
    
    delta = 0.1;
    t += delta;
    glutPostRedisplay();
    glutTimerFunc(100,myTimer,1);
}



int	screenWidth = 700, screenHeight = 640;

void reshape(int ancho, int alto) {
    
    screenHeight = alto;
    screenWidth = ancho;
    
    glViewport(0.0,0.0,(GLdouble) ancho,(GLdouble)  alto);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    // hace la conversion a openGL
    gluOrtho2D( 0.0,(GLdouble) ancho, 0.0,(GLdouble)  alto);
    
    
}

void despliegaMazo(){
    
    float posX, posYbottom, posYtop;
    posX = 0;
    posYtop = 640;
    posYbottom = 400;
    
    for (int i=0; i<=15; i++){
        //glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        if (i%2 == 0) {
            if (expuesta[i]) {
                glColor3ub(0, 255, 0);
            } else if (destapado[i]) {
                glColor3ub(255, 255, 0);
            } else {
               glColor3ub(255, 255, 255);
            }
            
            glVertex2f(posX, posYbottom);
            //glColor3ub(255, 255, 255);
            glVertex2f(posX+43.7, posYbottom);
            //glColor3ub(255, 255, 255);
            glVertex2f(posX+43.5, posYtop);
            //glColor3ub(255, 255, 255);
            glVertex2f(posX, posYtop);
        } else {
            if (expuesta[i]) {
                glColor3ub(0, 255, 0);
            } else if (destapado[i]) {
                glColor3ub(255, 255, 0);
            } else {
                glColor3ub(100, 100, 100);
            }
            
            glVertex2f(posX, posYbottom);
            //glColor3ub(100, 100, 100);
            glVertex2f(posX+43.7, posYbottom);
            //glColor3ub(100, 100, 100);
            glVertex2f(posX+43.5, posYtop);
            //glColor3ub(100, 100, 100);
            glVertex2f(posX, posYtop);
        }
        
        //if (expuesta[i]) {
            GLint k;
            char mensaje7 [200] = "";
            sprintf(mensaje7,"%s", "hola");
            glColor3f(0, 0, 1);
            glRasterPos2f(posX+5, posYbottom+10); // inicializa raster position
            for (k=0; mensaje7[k] != '\0'; k++) {
                glColor3f(0, 0, 1);
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje7[k]);
            }
        //}
        
        glEnd();
        posX += 43.75;
    }
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
    despliegaMazo();
    
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
            turnos = 0;
            clickCarta = 0;
            for (int i = 0; i < 15; i++) {
                expuesta[i] = false;
                destapado[i] = false;
            }
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

int calculaCarta(int x, int y){
    if (y >= 400 && y <= 640) {
        
        float carta = x/43.75;
        return (int)carta;
    } else {
        return -1;
    }
}


bool pares() {
    int aux1 = 0, aux2 = 0;
    bool encontro1 = false;
    for (int i = 0; i < 15; i++) {
        if (expuesta[i]) {
            if (encontro1 == false){
                aux1=i;
                encontro1 = true;
            }
            else if (encontro1){
                aux2=i;
                continue;
            }
            
        }
    }
    
    if (mazo[aux1] == mazo[aux2]) {
        destapado[aux1] = true;
        destapado[aux2] = true;
        return true;
    } else {
        return false;
    }
}

void mouse(int button, int state, int x, int y){
    if (start) {
        if(button == GLUT_LEFT_BUTTON){
            if(state == GLUT_DOWN){
                int posicion = calculaCarta(x, 640-y);
                
                if (expuesta[posicion] == false) {
                    clickCarta++;
                }
                if (clickCarta > 2) {
                    pares();
                    turnos++;
                    for (int i = 0; i < 15; i++) {
                        expuesta[i] = false;
                    }
                    clickCarta = 1;
                }
                
                if (posicion >= 0) {
                    expuesta[posicion] = true;
                }
                myDisplay();
            }
        }
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
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutTimerFunc(100,myTimer,1);
    
    
    glutMainLoop();
    return 0;
    
    
}
