#ifndef MY_GL_LIB_H
#define MY_GL_LIB_H

typedef struct
{
    float A;         // A, B, C - line's parameters    (Ax + By + C = 0) ;
    float B;
    float C;

    float a;         // a and b - curve's parameters ;
    float b;
    float R;        // circle's parameter - radius;

    float k;          // k and q - line's coefficients   ( y = k*x + q );
    float q;
    float t;       // in case B = 0, coefficient  (x1 = t);
    float p;       // parabola's coefficient;

    float D;       //discriminant;

    float x1;
    float x2;         // coordinates of the crossing points;
    float y1;
    float y2;

    int flag;
}Object;



typedef struct GLFWwindow GLFWwindow;

typedef void (*fun_p)(Object*);

int abracadabra(Object *, fun_p, float);

void lets_draw(Object *, fun_p, float);

void key_callback(GLFWwindow*, int, int, int, int);

void windowResizeHandler(int, int, float);


void draw_axis(float);

void axis_marking(float);

void draw_line(Object *);

void draw_hyperbola(Object *);

void draw_Ellipse(Object *);

void draw_parabola_right( Object *);

void draw_parabola_left(Object *);

void draw_parabola_up( Object *);

void draw_parabola_down(Object *);

void draw_circle(Object *);

void draw_point(Object *);

void write_coordinates(Object* , float);



#endif // MY_GL_LIB_H
