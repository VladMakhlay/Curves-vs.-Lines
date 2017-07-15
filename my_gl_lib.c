
#include "my_gl_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#define GLEW_STATIC

#include <gl/glut.h>


#include "glfw3.h"
#include "glfw3native.h"

#define ace_lenth 50000        // ace lenth from zero to 50000;
#define dots_coverage 2000     //diapason where poins are printed;
//----------------------------------------------------------------------------

void draw_axis(float max)
{

    glColor3f (1.0,1.0,1.0);
    glPointSize(2);
      glBegin(GL_LINES);
        glVertex2f (0, ace_lenth);
        glVertex2f (0,  -ace_lenth);

        glBegin(GL_LINES);
        glVertex2f (-ace_lenth, 0);
        glVertex2f (ace_lenth, 0);
      glEnd();

      glPointSize(2);
        glBegin(GL_LINES);
//------------ 0.5 step
        for(float i = -ace_lenth; i < ace_lenth; i += 0.5)
        {

                    glVertex2f(i, -0.03);
                    glVertex2f(i, 0.03);


        }

        for(float i = -ace_lenth; i < ace_lenth; i += 0.5)
        {

                    glVertex2f(0.03, i);
                    glVertex2f(-0.03, i);
        }
        glEnd();

        glPointSize(3);
          glBegin(GL_LINES);
 //------------ 1 step
                for(float i = -ace_lenth; i < ace_lenth; i++)
                {

                            glVertex2f(i, -0.06);
                            glVertex2f(i, 0.06);
                }

                for(float i = -ace_lenth; i < ace_lenth; i++)
                {

                            glVertex2f(0.06, i);
                            glVertex2f(-0.06, i);
                }
        glEnd();

        glPointSize(3);
          glBegin(GL_LINES);

 //---------- 5 step
        for(float i = -ace_lenth; i < ace_lenth; i += 5)
        {

                    glVertex2f(i, -0.15);
                    glVertex2f(i, 0.15);
        }

        for(float i = -ace_lenth; i < ace_lenth; i += 5)
        {

                    glVertex2f(0.15, i);
                    glVertex2f(-0.15, i);
        }
        glEnd();

        glPointSize(4);
          glBegin(GL_LINES);
 //--------- 10 step

        for(float i = -ace_lenth; i < ace_lenth; i += 10)
        {

                    glVertex2f(i, -0.4);
                    glVertex2f(i, 0.4);
        }

        for(float i = -ace_lenth; i < ace_lenth; i += 10)
        {

                    glVertex2f(0.4, i);
                    glVertex2f(-0.4, i);
        }
        glEnd();

        glPointSize(5);
          glBegin(GL_LINES);

               //--------- 50 step

                      for(float i = -ace_lenth; i < ace_lenth; i += 50)
                      {

                                  glVertex2f(i, -0.75);
                                  glVertex2f(i, 0.75);
                      }

                      for(float i = -ace_lenth; i < ace_lenth; i += 50)
                      {

                                  glVertex2f(0.75, i);
                                  glVertex2f(-0.75, i);
                      }
              glEnd();


        axis_marking( max);

}

//--------------------------------------------------------------------------------------


void axis_marking(float max)
{
  char marking[10];     // array for transformed floats into chars

float index = 0;         //index of changing ace markings related with max (maximum coordinate-point)
if(max <= 5)
{
    index = 1;
}
else
{
    index = max / 5;
}

if(max < 5)                          ////----------- max < 5
{
    for(float i = -10; i < 11; i++)   //-------------------------------// ace X
    {
         glRasterPos2f(i, -0.3 * index);
        if(i < 0)
        {
          glRasterPos2f(i - 0.15 * index, -0.3 * index);
        }
        else if(i == 0)
        {
            continue;
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }

    for(float i = -10; i < 11; i++)     //------------------------------//ace Y
    {
         glRasterPos2f( -0.3 * index, i);
        if(i < 0)
        {
          glRasterPos2f( -0.4 * index, i - 0.25 * index);
        }
        else if(i == 0)
        {
            continue;
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }
  }

if(max > 4.999999 && max < 10)                          ////----------- 5 < max < 10
{
    for(float i = -20; i < 21; i += 2)   //-------------------------------// ace X
    {
         glRasterPos2f(i, -0.3 * index);
        if(i < 0)
        {
          glRasterPos2f(i - 0.3 * index, -0.3 * index);
        }
        else if(i == 0)
        {
            glRasterPos2f(i + 0.3 * index, -0.25 * index);
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }

    for(float i = -20; i < 21; i += 2)     //------------------------------//ace Y
    {
         glRasterPos2f( -0.3 * index, i);
        if(i < 0)
        {
          glRasterPos2f( -0.5 * index, i - 0.3 * index);
        }
        else if(i == 0)
        {
            continue;
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }
  }
if(max > 9.999999 && max < 20)                     //////////////  10 < max < 20
{

    //---------from -30 to 30 # X # ----------------

    for(float i = -30; i < 31; i += 5)   //-------------------------------// ace X
    {
         glRasterPos2f(i, -0.3 * index);
        if(i < 0)
        {
          glRasterPos2f(i - 0.3 * index, -0.3 * index);
        }
        else if(i == 0)
        {
            glRasterPos2f(i + 0.3 * index, -0.3 * index);
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }

    for(float i = -30; i < 31; i += 5)     //------------------------------//ace Y
    {
         glRasterPos2f( -0.5 * index, i);
        if(i < 0)
        {
          glRasterPos2f( -0.7 * index, i - 0.3 * index);
        }
        else if(i == 0)
        {
            continue;
        }
        sprintf(marking, "%.f", i);
            for(unsigned int j = 0; j <strlen(marking); j++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
            }

    }
}

    if(max > 19.999999 && max < 51)                        ////////////////// 20 < max < 50
    {
        ///--------from -100 to 100 # X #--------

        for(float i = -100; i < 101; i += 10)   //-------------------------------// ace X
        {
             glRasterPos2f(i, -0.25 * index);
            if(i < 0)
            {
              glRasterPos2f(i - 0.3 * index, -0.25 * index);
            }
            else if(i == 0)
            {
                glRasterPos2f(i + 0.3 * index, -0.25 * index);
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }

        for(float i = -100; i < 101; i += 10)     //------------------------------//ace Y
        {
             glRasterPos2f( -0.3 * index, i);
            if(i < 0)
            {
              glRasterPos2f( -0.5 * index, i - 0.3 * index);
            }
            else if(i == 0)
            {
                continue;
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }
   }

    if(max > 50.999999 && max < 201)                           ////////--------- 50 < max < 200------
    {
        //------------ from -400  to 400 # X #-------------
        for(float i = -400; i < 401; i += 25)   //-------------------------------// ace X
        {
             glRasterPos2f(i, -0.3 * index);
            if(i < 0)
            {
              glRasterPos2f(i - 0.3 * index, -0.3 * index);
            }
            else if(i == 0)
            {
                glRasterPos2f(i + 0.3 * index, -0.25 * index);
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }

        for(float i = -400; i < 401; i += 25)     //------------------------------//ace Y
        {
             glRasterPos2f( -0.51 * index, i);
            if(i < 0)
            {
              glRasterPos2f( -0.7 * index, i - 0.3 * index);
            }
            else if(i == 0)
            {
                continue;
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }
    }

    if(max > 200.999999 && max < 501)       /////----------------- 200 < max < 500
    {
        for(float i = -1000; i < 1001; i += 100)   //-------------------------------// ace X
        {
             glRasterPos2f(i, -0.3 * index);
            if(i < 0)
            {
              glRasterPos2f(i - 0.3 * index, -0.3 * index);
            }
            else if(i == 0)
            {
                glRasterPos2f(i + 0.3 * index, -0.25 * index);
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }

        for(float i = -1000; i < 1001; i += 100)     //------------------------------//ace Y
        {
             glRasterPos2f( -0.5 * index, i);
            if(i < 0)
            {
              glRasterPos2f( -0.8 * index, i - 0.3 * index);
            }
            else if(i == 0)
            {
                continue;
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }
    }

    if(max > 500.999999 && max < 1001)       /////----------------- 500 < max < 1000
    {
        for(float i = -2000; i < 2001; i += 250)   //-------------------------------// ace X
        {
             glRasterPos2f(i, -0.3 * index);
            if(i < 0)
            {
              glRasterPos2f(i - 0.3 * index, -0.3 * index);
            }
            else if(i == 0)
            {
                glRasterPos2f(i + 0.3 * index, -0.25 * index);
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }

        for(float i = -2000; i < 2001; i += 250)     //------------------------------//ace Y
        {
             glRasterPos2f( -0.5 * index, i);
            if(i < 0)
            {
              glRasterPos2f( -0.8 * index, i - 0.3 * index);
            }
            else if(i == 0)
            {
                continue;
            }
            sprintf(marking, "%.f", i);
                for(unsigned int j = 0; j <strlen(marking); j++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, marking[j]);
                }

        }
    }
}
//--------------------------------------------------------------------------------------
 void draw_line(Object* ob)
 {
     glColor3f(0.0, 0.0, 1.0);
     glPointSize(2);
     glBegin(GL_POINTS);
     for(float i = -dots_coverage; i < dots_coverage; i +=0.0005 )
     {
         glVertex2f(i, ob->k * i + ob->q);
     }
       glEnd();
 }

 //-------------------------------------------------------------------------------------
void draw_hyperbola(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f( sqrt(pow(ob->a, 2) + pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), i);
      }
    glEnd();

    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f( -sqrt(pow(ob->a, 2) + pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), i);
     }
   glEnd();

      glBegin(GL_POINTS);
      for(float i = 0; i < dots_coverage; i += 0.0005)
       {
       glVertex2f( sqrt(pow(ob->a, 2) + pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))),- i);
       }
     glEnd();

     glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f( -sqrt(pow(ob->a, 2) + pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), -i);
      }
    glEnd();
}


//-------------------------------------------------------------------------

void draw_Ellipse(Object* ob)
{

    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f( sqrt(pow(ob->a, 2) - pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), i);
      }
    glEnd();

    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f( -sqrt(pow(ob->a, 2) - pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), i);
     }
   glEnd();

   glBegin(GL_POINTS);
   for(float i = 0; i < dots_coverage; i += 0.0005)
    {
    glVertex2f( sqrt(pow(ob->a, 2) - pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), -i);
    }
  glEnd();

  glBegin(GL_POINTS);
  for(float i = 0; i < dots_coverage; i += 0.0005)
   {
   glVertex2f( -sqrt(pow(ob->a, 2) - pow(i, 2) * pow(ob->a, 2) / (pow(ob->b, 2))), -i);
   }
 glEnd();
}

//--------------------------------------------------------------------

void draw_parabola_right(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f(pow(i, 2) / (2 * ob->p), i);
      }
    glEnd();
    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f(pow(i, 2) / (2 * ob->p),-i);
     }
   glEnd();


}

//----------------------------------------------------------------------

void draw_parabola_left(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f(-i, sqrt( 2 * ob->p * i));
      }
    glEnd();
    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f(-i, -sqrt( 2 * ob->p * i));
     }
   glEnd();


}

//--------------------------------------------------------------------------

void draw_parabola_up(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f(i, pow(i, 2) / (2 * ob->p));
      }
    glEnd();
    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f(-i, pow(i, 2) / (2 * ob->p));
     }
   glEnd();

}

//-----------------------------------------------------------------

void draw_parabola_down(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = 0; i < dots_coverage; i += 0.0005)
      {
      glVertex2f(i, -1 * pow(i, 2) / (2 * ob->p));
      }
    glEnd();
    glBegin(GL_POINTS);
    for(float i = 0; i < dots_coverage; i += 0.0005)
     {
     glVertex2f(-i, -1 * pow(i, 2) / (2 * ob->p));
     }
   glEnd();
}

//------------------------------------------------------------------

void draw_circle(Object* ob)
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
     for(float i = -dots_coverage; i < dots_coverage; i += 0.0005)
      {
      glVertex2f(i, ob->b + sqrt(pow(ob->R, 2) - (pow(i, 2) - 2 * i * ob->a + pow(ob->a , 2))));
      }
    glEnd();

    glBegin(GL_POINTS);
    for(float i = -dots_coverage; i < dots_coverage; i += 0.0005)
     {
     glVertex2f(i, ob->b - sqrt(pow(ob->R, 2) - (pow(i, 2) - 2 * i * ob->a + pow(ob->a , 2))));
     }
   glEnd();
}

//--------------------------------------------------------------------------------

void draw_point(Object* ob)
{

    if(ob->flag == 2)
    {
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(6);
    glBegin(GL_POINTS);

    glVertex2f(ob->x1, ob->y1);
    glVertex2f(ob->x2, ob->y2);
    glEnd();

//    if(ob->x1 != 0 && ob->y1 != 0)    /// ---- proection to the aces first crossing - point
//    {
//    glColor3f(1.0, 0.4, 0.2);
//    glLineWidth(0.02);
//    glBegin(GL_LINES);

//    glVertex2f(ob->x1, ob->y1);
//    glVertex2f(ob->x1, 0);

//    glVertex2f(ob->x1, ob->y1);
//    glVertex2f(0, ob->y1);
//    glEnd();
//    }

//    if(ob->x2 != 0 && ob->y2 != 0) ////--------proection to the aces second crossing-point
//    {
//    glColor3f(1.0, 0.4, 0.2);
//    glLineWidth(0.002);
//    glBegin(GL_LINES);
//    glVertex2f(ob->x2, ob->y2);
//    glVertex2f(ob->x2, 0);

//    glVertex2f(ob->x2, ob->y2);
//    glVertex2f(0, ob->y2);
//    glEnd();
//    }
    }

    else if(ob->flag == 1)
    {
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(6);
    glBegin(GL_POINTS);

     glVertex2f(ob->x1, ob->y1);

    glEnd();
//    if(ob->x1 != 0 && ob->y1 != 0)      ////-------one crossing point
//    {
//    glColor3f(1.0, 0.4, 0.2);
//    glLineWidth(0.002);
//    glBegin(GL_LINES);

//    glVertex2f(ob->x1, ob->y1);     ///--proection to the ace X
//    glVertex2f(ob->x1, 0);

//    glVertex2f(ob->x1, ob->y1);    ///--proection to the ace Y
//    glVertex2f(0, ob->y1);
//    glEnd();
//    }
    }
    else
    {
       return;
    }

    }

//----------------------------------------------------------------

void key_callback(GLFWwindow* window,int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


//-------------------------------------------------------------------

void windowResizeHandler( int windowWidth, int windowHeight, float max)
{

    const float aspectRatio = ((float)windowWidth) / windowHeight;

    float xSpan = max * 2;
    float ySpan = max * 2;

    if (aspectRatio > 1)
    {
                                    // Width > Height, so scale xSpan accordinly.
        xSpan *= aspectRatio;
    }
    else
    {
        ySpan = xSpan / aspectRatio;
    }

    glOrtho(-1*xSpan, xSpan, -1*ySpan, ySpan, -1, 1);

                                        // Use the entire window for rendering.
    glViewport(0, 0, windowWidth, windowHeight);
}

//-----------------------------------------------------------------------

//------------------------------------------------------------------------

int abracadabra(Object *ob, fun_p fun, float max)
{
    int width = 760,
        height = 700;

    GLFWwindow* window;

    if (!glfwInit())
        return -1;


     window = glfwCreateWindow (width, height, "GL Line_vs_curve", NULL, NULL);

     if (!window)
     {
         glfwTerminate();
         return -1;
     }
     if (window == NULL)
     {
         printf("Failed to create window");
         glfwTerminate ();;
         return -1;
     }

     glfwMakeContextCurrent(window);
     glfwGetFramebufferSize(window, &width, &height);
     glfwSetWindowPos( window, 600,25);
     glViewport(0, 0, width, height);
      glfwSetKeyCallback(window, key_callback);
      windowResizeHandler( width, height, max);

        glOrtho (-400, 400, -400, 400, 0,0);

 while (!glfwWindowShouldClose(window))
   {
            glfwPollEvents();
            glClearColor(0.0, 0.0, 0.0, 0.0);
            glClearDepth(1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        draw_axis(max);
        fun(ob);
        draw_line( ob);
        draw_point(ob);

        write_coordinates( ob, max);

        glfwSwapBuffers(window);
         glfwPollEvents();
   }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

//---------------------------------------------------------------
void lets_draw(Object* ob, fun_p fun, float max)
{
    int key = 0;
    int count_tries = 0;

    printf("\nWould you like to visualize the intersection?\n\n");
    do
    {
        printf("Enter - 1 -  for YES  : ");
        scanf("%i", &key);

            if(key != 1 && count_tries < 1)
            {
                printf("\nYou sure you don't want to see the REAL ART ?\n\n");
            }
            if(key != 1 && count_tries == 1)
            {
                printf("\nYour choice. Goodbye!\n\n\n");
                break;
            }

         count_tries++;
    }while(key != 1);
if(key == 1)
  {
    abracadabra(ob, fun, max);
  }
else
  {
    return;
  }

}

//----------------------------------------------------------------------------

void write_coordinates(Object* ob, float max)
{
    float indexX = 0;
    float indexY = 0;
    char first[30];
    char second[30];

    if(max < 5)
    {
        indexX = 0.5;
        indexY = 0.3;
    }
    else
    {
        indexX = max / 10;
        indexY = max / 17;
    }

    if(ob->flag == 2)
    {
    sprintf(first, "( %.2f ; %.2f )", ob->x1, ob->y1);
    glRasterPos2f(ob->x1 + indexX, ob->y1 + indexY);
    for(unsigned int i = 0; i < strlen(first); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, first[i]);

    }
    glFlush();

    sprintf(second, "( %.2f ; %.2f )", ob->x2, ob->y2);
    glRasterPos2f(ob->x2 + indexX, ob->y2 + indexY);

    for(unsigned int i = 0; i < strlen(second); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, second[i]);

    }
    glFlush();
    }

    else if(ob->flag ==1)
    {
        sprintf(first, "( %.2f ; %.2f )", ob->x1, ob->y1);
        glRasterPos2f(ob->x1 + indexX, ob->y1 + indexY);
        for(unsigned int i = 0; i < strlen(first); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, first[i]);

        }
        glFlush();
    }
}
