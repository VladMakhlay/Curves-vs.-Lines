#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "glfw3.h"
#include "glfw3native.h"
#include "my_algo_lib.h"
#include "my_gl_lib.h"

#define number_of_ob_elements 11

//-------------------------------------------------------
void greating()
{
    printf("\n\n........................Hello!.........................\n");
      printf("\n..........You are welcome to test my program!..........\n");
      printf("\n\n\n\n");
}

//-----------------------------------------------------------

void Lets_go(Object *ob)
{

      int choice = 0;

   do
    {
     printf("Please, choose an action : \n\t1 -- line - circle -- intersection\n\t2 -- line - ellipse -- intersection");
     printf("\n\t3 -- line - hyperbola -- intersection\n\t4 -- line - parabola -- intersection: ");
      scanf("%i", &choice);

             switch(choice)
        {
            case 1 : circle_vs_line(ob);
                    break;
            case 2 : ellipse_vs_line(ob);
                    break;
            case 3 : hyperbola_vs_line(ob);
                    break;
            case 4 : parabola_vs_line(ob);
                    break;
            default: printf("\nThere are four variants of actions to choose, try again!\n\n");
                    break;
        }
      }while(choice < 1 || choice > 4);
}


//-----------------------------------------------------------

float max_point(Object *ob)
{

    float max = 0,
          max1 = 0,
          max2 = 0;
    switch(ob->flag)
    {
    case 2 :  max1 = (fabs(ob->x1) > fabs(ob->y1)) ? fabs(ob->x1) : fabs(ob->y1);
              max2 = (fabs(ob->x2) > fabs(ob->y2)) ? fabs(ob->x2) : fabs(ob->y2);
              max = (max1 > max2) ? max1 : max2;
             break;
    case 1 :  max = (fabs(ob->x1) > fabs(ob->y1)) ? fabs(ob->x1) : fabs(ob->y1);
             break;
    case 0 :  max = 15;
             break;
    }

    return max;
}

//-------------------------------------------------------------------------------------------------------------------------------
void line_parameters(Object *ob)
{
 printf("\nInput three parameters of a line :\n");
    do
    {
        printf("\tA :");
        scanf("%f", &ob->A);
        printf("\tB :");
        scanf("%f", &ob->B);
        if(ob->A == 0 && ob->B == 0)printf("A and B can't be equal to '0' at the same time. Try again.\n");
    }while(ob->A == 0 && ob->B == 0);
        printf("\tC :");
        scanf("%f", &ob->C);
}
//--------------------------------------------------------------------------------------------------------------------
void circle_vs_line(Object *ob)
{
    float max = 0;
    line_parameters(ob);
  printf("Enter parameters of a circle :\n\t");

             printf("a : ");
             scanf("%f", &ob->a);

             printf("\tb : ");
             scanf("%f", &ob->b);
             do
             {
               printf("\tR : ");
               scanf("%f", &ob->R);
                 if(ob->R <= 0)
                    printf("Try again. Enter R greater then '0'.\n");
              }while(ob->R <= 0);
    if(ob->B && ob->A)
    {
        ob->k = -ob->A/ob->B;
        ob->q = -ob->C/ob->B;

        ob->D = 4 * (ob->k * ob->k) * (ob->R * ob->R) + 4 * (ob->R * ob->R) - 4 * (ob->q * ob->q) - 4 *
                (ob->b * ob->b) - 4 * (ob->k * ob->k) * (ob->a * ob->a) - 8 * ob->k * ob->q * ob->a + 8 * ob->q * ob->b + 8 * ob->k * ob->b * ob->a;

        if(ob->D > 0)
        {
            ob->x1 = (- 2 * ob->k * ob->q +  2 * ob->k * ob->b + 2 * ob->a - sqrt(ob->D)) / (2 + 2 * ob->k * ob->k);
            ob->y1 = ob->k * ob->x1 + ob->q;

            ob->x2 = (- 2 * ob->k * ob->q +  2 * ob->k * ob->b + 2 * ob->a + sqrt(ob->D)) / (2 + 2 * ob->k * ob->k);
            ob->y2 = ob->k * ob->x2 + ob->q;

            ob->flag = 2;
             max = max_point(ob);

            printf("There are two points of intersection :\n\n");
            printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
            printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);




        }
        else if(ob->D == 0)
        {
            ob->x1 = (-ob->k * ob->q + ob->k * ob->b + ob->a);
            ob->y1 = ob->k * ob->x1 + ob->q;

            ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);

        }

        else
        {
            printf("There are no points of intersection at all.\n\n");
            ob->flag = 0;
            max = max_point(ob);
        }

    }
    if(!ob->B)
    {
        ob->t = -ob->C/ob->A;
        ob->x1 = ob->t;

        ob->D = 4 * (ob->R - ob->a + ob->t) * (ob->R + ob->a - ob->t);
       // printf("%.2f\n", ob->D);
        if(ob->D > 0)
        {
            ob->y1 = ob->b - sqrt((ob->R - ob->a + ob->t) * (ob->R + ob->a - ob->t));
            ob->y2 = ob->b + sqrt((ob->R - ob->a + ob->t) * (ob->R + ob->a - ob->t));

            ob->flag = 2;
             max = max_point(ob);

            printf("There are two points of intersection :\n\n");
            printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
            printf("--Point2(%.2f, %.2f)\n\n", ob->x1, ob->y2);

        }
        else if(ob->D == 0)
        {
            ob->y1 = ob->b;

            ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);

        }
        else
        {
         printf("There are no points of intersection at all.\n\n");

         ob->flag = 0;
          max = max_point(ob);
        }
    }
    if(!ob->A)
    {
        ob->q = -ob->C / ob->B;
        ob->y1 = ob->q;

        ob->D = 4 * (pow(ob->R, 2) - pow(ob->q, 2) -pow(ob->b, 2) + 2 * ob->q * ob->b);
        //printf("%.2f\n", ob->D);

        if(ob->D > 0)
        {
            ob->x1 = (2 * ob->a - sqrt(ob->D)) / 2;
            ob->x2 = (2 * ob->a + sqrt(ob->D)) / 2;

            ob->flag = 2;
             max = max_point(ob);

             printf("There are two points of intersection :\n\n");
            printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
            printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y1);

        }
        else if(ob->D == 0)
        {
            ob->x1 = ob->a;

            ob->flag = 1;
             max = max_point(ob);

             printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);

        }
        else
        {
           printf("There are no points of intersection at all.\n\n");
           ob->flag = 0;
            max = max_point(ob);
        }
    }

    //------drawing--------//
    lets_draw(ob, draw_circle, max);
}
//-------------------------------------------------------------------------------------------------------------------
void ellipse_vs_line(Object *ob)
{
    float max = 0;
    line_parameters(ob);
    printf("Enter parameters of an ellipse :\n");
        do
        {
             printf("\ta : ");
             scanf("%f", &ob->a);

             printf("\tb : ");
             scanf("%f", &ob->b);

             if(ob->a == 0 || ob->b == 0)
                printf("Neither  a nor b can be equal to '0'. Try again.\n");
        }while(ob->a == 0 || ob->b == 0);

        if(ob->B && ob->A)
        {
            ob->k = -ob->A/ob->B;
            ob->q = -ob->C/ob->B;

            ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->a * ob->k, 2) - pow(ob->q, 2) + pow(ob->b, 2));
             //printf("%.2f\n", ob->D);
            if(ob->D > 0)
                {
                    ob->x1 = (-pow(ob->a, 2) * ob->k * ob->q - ob->a * ob->b * sqrt(pow(ob->a * ob->k, 2) - pow(ob->q, 2) + pow(ob->b, 2))) /
                            (pow(ob->a * ob->k, 2) + pow(ob->b, 2));

                    ob->x2 = (-pow(ob->a, 2) * ob->k * ob->q + ob->a * ob->b * sqrt(pow(ob->a * ob->k, 2) - pow(ob->q, 2) + pow(ob->b, 2))) /
                            (pow(ob->a * ob->k, 2) + pow(ob->b, 2));

                    ob->y1 = ob->k * ob->x1 + ob->q;
                    ob->y2 = ob->k * ob->x2 + ob->q;

                    ob->flag = 2;
                     max = max_point(ob);

                    printf("\nThere are two points of intersection :\n\n");
                    printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                    printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);


                }

            else if(ob->D == 0)
            {
                ob->x1 = (-pow(ob->a, 2) * ob->k * ob->q) / (pow(ob->a * ob->k, 2) + pow(ob->b, 2));
                ob->y1 = ob->k * ob->x1 + ob->q;

                ob->flag = 1;
                 max = max_point(ob);

                printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);


            }
            else
            {
                printf("There are no points of intersection at all.\n\n");
                ob->flag = 0;
                 max = max_point(ob);
            }
        }
        if(!ob->B)
        {
            ob->t = -ob->C / ob->A;
            ob->x1 = ob->t;

            ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->a, 2) - pow(ob->t, 2));
            //printf("%.2f", ob->D);

            if(ob->D > 0)
            {
                ob->y1 = (-ob->a * ob->b * sqrt(pow(ob->a, 2) - pow(ob->b, 2))) / pow(ob->a, 2);
                ob->y2 = (ob->a * ob->b * sqrt(pow(ob->a, 2) - pow(ob->b, 2))) / pow(ob->a, 2);

                ob->flag = 2;
                 max = max_point(ob);

                    printf("\nThere are two points of intersection :\n\n");
                    printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                    printf("--Point2(%.2f, %.2f)\n\n", ob->x1, ob->y2);

            }
            else if(ob->D == 0)
            {
                ob->y1 = (-ob->a * ob->b * sqrt(pow(ob->a, 2) - pow(ob->b, 2))) / pow(ob->a, 2);

                ob->flag = 1;
                 max = max_point(ob);

                 printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);

            }
            else
            {
                printf("There are no points of intersection at all.\n\n");
                ob->flag = 0;
                 max = max_point(ob);
            }
        }
        if(!ob->A)
        {
            ob->q = -ob->C / ob->B;
            ob->y1 = ob->q;

            ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->b, 2) - pow(ob->q, 2));
           // printf("%.2f", ob->D);

            if(ob->D > 0)
            {
                ob->x1 = (-ob->a * ob->b * sqrt(pow(ob->b, 2) - pow(ob->q, 2))) / pow(ob->b, 2);
                ob->x2 = (ob->a * ob->b * sqrt(pow(ob->b, 2) - pow(ob->q, 2))) / pow(ob->b, 2);

                ob->flag = 2;
                 max = max_point(ob);

                 printf("\nThere are two points of intersection :\n\n");
                    printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                    printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y1);

            }
            else if(ob->D == 0)
            {
                ob->x1 = (-ob->a * ob->b * sqrt(pow(ob->b, 2) - pow(ob->q, 2))) / pow(ob->b, 2);

                ob->flag = 1;
                 max = max_point(ob);

                printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);

            }
            else
            {
              printf("There are no points of intersection at all.\n\n");

              ob->flag = 0;
               max = max_point(ob);            }
        }

        //---------drawing---------//
        lets_draw(ob,  draw_Ellipse, max);
}
//-------------------------------------------------------------------------------------------------------------------
void hyperbola_vs_line(Object *ob)
{
    float max = 0;
    line_parameters(ob);
    printf("Enter parameters of a hyperbola :\n");
        do
        {
             printf("\ta : ");
             scanf("%f", &ob->a);

             printf("\tb : ");
             scanf("%f", &ob->b);

             if(ob->a == 0 || ob->b == 0)
                printf("Neither  a nor b can be equal to '0'. Try again.\n");
        }while(ob->a == 0 || ob->b == 0);

        if(ob->B && ob->A)
        {
            ob->k = -ob->A / ob->B;
            ob->q = -ob->C / ob->B;

            if((pow(ob->b, 2) - pow(ob->a * ob->k, 2)) == 0)
             {
                ob->x1 = -(pow(ob->q, 2) + pow(ob->b, 2)) / (2 * ob->k * ob->q);
                ob->y1 = ob->k * ob->x1 + ob->q;

                ob->flag = 1;
                 max = max_point(ob);

                printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
             }
            else
              {
               ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->q, 2) + pow(ob->b, 2) - pow(ob->a * ob->k, 2));
               //printf("%.2f\n", ob->D);

               if(ob->D > 0)
                {
                    ob->x1 = (2 * pow(ob->a, 2) * ob->k * ob->q - sqrt(ob->D)) / (2 * (pow(ob->b, 2) - pow(ob->a * ob->k, 2)));
                    ob->y1 = ob->k * ob->x1 + ob->q;

                    ob->x2 = (2 * pow(ob->a, 2) * ob->k * ob->q + sqrt(ob->D)) / (2 * (pow(ob->b, 2) - pow(ob->a * ob->k, 2)));
                    ob->y2 = ob->k * ob->x2 + ob->q;

                    ob->flag = 2;
                     max = max_point(ob);

                    printf("\nThere are two points of intersection :\n\n");
                    printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                    printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);

                }
                else if(ob->D == 0)
                {
                    ob->x1 = pow(ob->a, 2) * ob->k * ob->q / (pow(ob->b, 2) - pow(ob->a * ob->k, 2));
                    ob->y1 = ob->k * ob->x1 + ob->q;

                    ob->flag = 1;
                     max = max_point(ob);

                    printf("\nThere is only one common point :\n\n");
                    printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                }
                else
                {
                   ob->flag = 0;
                    max = max_point(ob);
                   printf("There are no points of intersection at all.\n\n");
                }
              }
            }

        if(!ob->B)
        {
            ob->t = -ob->C / ob->A;
            ob->x1 = ob->t;

            ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->t, 2) - pow(ob->a, 2));
            //printf("%.2f\n", ob->D);

            if(ob->D > 0)
            {
                ob->y1 = -sqrt(ob->D) / (2 * pow(ob->a, 2));
                ob->y2 = sqrt(ob->D) / (2 * pow(ob->a, 2));

                ob->flag = 2;
                 max = max_point(ob);

                printf("\nThere are two points of intersection :\n\n");
                printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                printf("--Point2(%.2f, %.2f)\n\n", ob->x1, ob->y2);
            }
            else if(ob->D == 0)
            {
                ob->y1 = sqrt(ob->D) / (2 * pow(ob->a, 2));

                ob->flag = 1;
                 max = max_point(ob);

                printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
            }
            else
            {
                ob->flag = 0;
                 max = max_point(ob);
               printf("There are no points of intersection at all.\n\n");
            }

        }
        if(!ob->A)
        {
            ob->q = -ob->C / ob->B;
            ob->y1 = ob->q;

            ob->D = 4 * pow(ob->a * ob->b, 2) * (pow(ob->q, 2) + pow(ob->b, 2));
           // printf("%.2f\n", ob->D);

            if(ob->D > 0)
            {
                ob->x1 = -sqrt(ob->D) / (2 * pow(ob->b, 2));
                ob->x2 = sqrt(ob->D) / (2 * pow(ob->b, 2));

                ob->flag = 2;
                 max = max_point(ob);

                printf("\nThere are two points of intersection :\n\n");
                printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y1);
            }
            else if(ob->D == 0)
            {
                ob->x1 = sqrt(ob->D) / (2 * pow(ob->b, 2));

                ob->flag = 1;
                 max = max_point(ob);

                printf("\nThere is only one common point :\n\n");
                printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
            }
            else
            {
                ob->flag = 0;
                 max = max_point(ob);

               printf("There are no points of intersection at all.\n\n");
            }

        }
        //--------------drawing--------------//
        lets_draw(ob,  draw_hyperbola, max);
}
//-------------------------------------------------------------------------------------------------------------------
void parabola_vs_line(Object *ob)
{
    int direction = 0;
     do
    {
          printf("\n\nSelect a direction of the parabola's branches : \n\t");
    printf("1 - branches go to the right \n\t2 - branches go to the left \n\t3 - branches go up \n\t4 - branches go down  : ");

    scanf("%i", &direction);
    if(direction < 1 || direction > 4)
        printf("\nThere are only four directions of the parabola's branches! Try again.\n");
   }while(direction < 1 || direction > 4);

     line_parameters(ob);

     printf("Enter parameter of a parabola :\n\t");
        do
         {
           printf("p : ");
           scanf("%f", &ob->p);

            if(ob->p == 0)
             printf("Sorry, p can't be equal to '0'. Try again.\n\t");
         }while(ob->p == 0);

      switch(direction)
    {
        case 1 : right_parabola(ob);
                break;
        case 2 : left_parabola(ob);
                break;
        case 3 : up_parabola(ob);
                break;
        case 4 : down_parabola(ob);
                break;
    }
}
//--------------------------------------------------------------------------------------------------------------------
void right_parabola(Object *ob)
{
    float max = 0;

               if(ob->B && ob->A)
                {
                   ob->k = -ob->A/ob->B;
                   ob->q = -ob->C/ob->B;

                   ob->D = 4 * ob->p * (ob->p  - 2 * ob->k * ob->q);

                    //printf("%.2f", ob->D);
                    if(ob->D > 0)
                    {
                        ob->x1 = (ob->p - ob->k * ob->q - sqrt(pow(ob->p, 2) - 2 * ob->k * ob-> q * ob->p)) / pow(ob->k, 2);
                        ob->y1 = ob->k * ob->x1 + ob->q;

                        ob->x2 = (ob->p - ob->k * ob->q + sqrt(pow(ob->p, 2) - 2 * ob->k * ob-> q * ob->p)) / pow(ob->k, 2);
                        ob->y2 = ob->k * ob->x2 + ob->q;

                        ob->flag = 2;
                         max = max_point(ob);

                        printf("\nThere are two points of intersection :\n\n");
                        printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                        printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);
                    }
                    else if(ob->D == 0)
                    {
                        ob->x1 = (ob->p - ob->k * ob->q  ) / pow(ob->k, 2);
                        ob->y1 = ob->k * ob->x1 + ob->q;

                        ob->flag = 1;
                         max = max_point(ob);

                        printf("There is only one common point :\n\n");
                        printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                    }
                    else
                    {
                        ob->flag = 0;
                         max = max_point(ob);
                        printf("There are no points of intersection at all.\n\n");
                    }
                }
                if(!ob->B)
                {
                    ob->t = -ob->C / ob->A;
                    ob->x1 = ob->t;

                    ob->D = 8 * ob->p * ob->t;

                    if(ob->D > 0)
                    {
                        ob->y1 = sqrt(ob->D) / 2;
                        ob->y2 = -sqrt(ob->D) / 2;

                        ob->flag = 2;
                         max = max_point(ob);

                        printf("\nThere are two points of intersection :\n\n");
                        printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                        printf("--Point2(%.2f, %.2f)\n\n", ob->x1, ob->y2);
                    }
                    else if(ob->D == 0)
                    {
                      ob->t = -ob->C / ob->A;

                        ob->x1 = ob->t;
                        ob->y1 = sqrt(ob->D) / 2;

                        ob->flag = 1;
                         max = max_point(ob);

                         printf("There is only one common point :\n\n");
                        printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                    }
                    else
                    {
                        ob->flag = 0;
                         max = max_point(ob);

                        printf("There are no points of intersection at all.\n\n");
                    }

                }
                if(!ob->A)
                {
                  //ob->D = 0;    Discriminant always equals to '0', so there will be always one point of crossing;
                  ob->q = -ob->C/ob->B;
                  ob->y1 = ob->q;

                  ob->x1 = pow(ob->q, 2) / (2 * ob->p) ;

                  ob->flag = 1;
                   max = max_point(ob);

                  printf("There is only one common point :\n\n");
                  printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                }
    //---------------drawing---------------------//
     lets_draw(ob,  draw_parabola_right, max);

}
//---------------------------------------------------------------------------------------------------------------------------------
void left_parabola(Object *ob)
{
    float max = 0;

               if(ob->B && ob->A)
                {
                   ob->k = -ob->A/ob->B;
                   ob->q = -ob->C/ob->B;

                   ob->D = 4 * ob->p * (ob->p  + 2 * ob->k * ob->q);

                    //printf("%.2f", ob->D);
                    if(ob->D > 0)
                    {
                        ob->x1 = (-ob->p - ob->k * ob->q - sqrt(pow(ob->p, 2) + 2 * ob->k * ob-> q * ob->p)) / pow(ob->k, 2);
                        ob->y1 = ob->k * ob->x1 + ob->q;

                        ob->x2 = (-ob->p - ob->k * ob->q + sqrt(pow(ob->p, 2) + 2 * ob->k * ob-> q * ob->p)) / pow(ob->k, 2);
                        ob->y2 = ob->k * ob->x2 + ob->q;

                        ob->flag = 2;
                         max = max_point(ob);

                        printf("\nThere are two points of intersection :\n\n");
                        printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                        printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);
                    }
                    else if(ob->D == 0)
                    {
                        ob->x1 = (-ob->p - ob->k * ob->q  ) / pow(ob->k, 2);
                        ob->y1 = ob->k * ob->x1 + ob->q;

                        ob->flag = 1;
                         max = max_point(ob);

                        printf("There is only one common point :\n\n");
                        printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                    }
                    else
                    {
                        ob->flag = 0;
                         max = max_point(ob);

                        printf("There are no points of intersection at all.\n\n");
                    }
                }
                if(!ob->B)
                {
                    ob->t = -ob->C / ob->A;
                    ob->x1 = ob->t;

                    ob->D = -8 * ob->p * ob->t;

                    if(ob->D > 0)
                    {
                        ob->y1 = sqrt(ob->D) / 2;
                        ob->y2 = -sqrt(ob->D) / 2;

                        ob->flag = 2;
                         max = max_point(ob);

                        printf("\nThere are two points of intersection :\n\n");
                        printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
                        printf("--Point2(%.2f, %.2f)\n\n", ob->x1, ob->y2);
                    }
                    else if(ob->D == 0)
                    {
                      ob->t = -ob->C / ob->A;

                        ob->x1 = ob->t;
                        ob->y1 = sqrt(ob->D) / 2;

                        ob->flag = 1;
                         max = max_point(ob);

                         printf("There is only one common point :\n\n");
                        printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                    }
                    else
                    {
                        ob->flag = 0;
                         max = max_point(ob);

                        printf("There are no points of intersection at all.\n\n");
                    }

                }
                if(!ob->A)
                {
                  //ob->D = 0;    Discriminant always equals to '0', so there will be always one point of crossing;
                  ob->q = -ob->C/ob->B;
                  ob->y1 = ob->q;

                  ob->x1 = -pow(ob->q, 2) / (2 * ob->p) ;

                  ob->flag = 1;
                   max = max_point(ob);

                  printf("There is only one common point :\n\n");
                  printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
                }
 //-----------------drawing---------------------------//
    lets_draw(ob,  draw_parabola_left, max);
}

//---------------------------------------------------------------------------------------

void up_parabola(Object *ob)
{
    float max = 0;
    if(ob->B && ob->A)
    {
        ob->k = -ob->A/ob->B;
        ob->q = -ob->C/ob->B;

        ob->D = 4 * (pow(ob->p * ob->k, 2) + 2 * ob->p * ob->q);
        //printf("%.2f", ob->D);

        if(ob->D > 0)
        {
             ob->x1 = ob->p * ob->k - sqrt(pow(ob->p * ob->k, 2) + 2 * ob->p * ob->q);
             ob->y1 = ob->k * ob->x1 + ob->q;

             ob->x2 = ob->p * ob->k + sqrt(pow(ob->p * ob->k, 2) + 2 * ob->p * ob->q);
             ob->y2 = ob->k * ob->x2 + ob->q;

             ob->flag = 2;
              max = max_point(ob);

             printf("\nThere are two points of intersection :\n\n");
             printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
             printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);
        }
        else if(ob->D == 0)
        {
            ob->x1 = ob->p * ob->k;
            ob->y1 = ob->k * ob->x1 + ob->q;

            ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
        }
        else
        {            
            ob->flag = 0;
             max = max_point(ob);

         printf("There are no points of intersection at all.\n\n");
        }
    }
    if(!ob->B)
    {
        ob->t = - ob->C / ob->A;

        ob->x1 = ob->t;
        ob->y1 = pow(ob->t, 2) / (2 * ob->p);

        ob->flag = 1;
         max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
    }

    if(!ob->A)
    {
        ob->q = -ob->C / ob->B;
        ob->y1 = ob->q;

        ob->D = 8 * ob->p * ob->q;
        if(ob->D > 0)
        {
            ob->x1 = -sqrt(ob->D) / 2;
            ob->x2 = sqrt(ob->D) / 2;

            ob->flag = 2;
             max = max_point(ob);

             printf("\nThere are two points of intersection :\n\n");
             printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
             printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y1);
        }
        else if(ob->D == 0)
        {
            ob->x1 = sqrt(ob->D) / 2;

            ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
        }
        else
        {
            ob->flag = 0;
             max = max_point(ob);

            printf("There are no points of intersection at all.\n\n");
        }

    }
//-----------------------drawing---------------------//
    lets_draw(ob,  draw_parabola_up, max);

}

//---------------------------------------------------------------------------------------

void down_parabola(Object *ob)
{
    float max = 0;
    if(ob->B && ob->A)
    {
        ob->k = -ob->A/ob->B;
        ob->q = -ob->C/ob->B;

        ob->D = 4 * (pow(ob->p * ob->k, 2) - 2 * ob->p * ob->q);
        //printf("%.2f", ob->D);

        if(ob->D > 0)
        {
            ob->x1 = -ob->p * ob->k - sqrt(pow(ob->p * ob->k, 2) - 2 * ob->q * ob->p);
            ob->y1 = ob->k * ob->x1 + ob->q;

            ob->x2 = -ob->p * ob->k + sqrt(pow(ob->p * ob->k, 2) - 2 * ob->q * ob->p);
            ob->y2 = ob->k * ob->x2 + ob->q;

             ob->flag = 2;
             max = max_point(ob);

            printf("\nThere are two points of intersection :\n\n");
            printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
            printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y2);
        }
        else if(ob->D == 0)
        {
            ob->x1 = -ob->p * ob->k;
            ob->y1 = ob->k * ob->x1 + ob->q;

             ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
        }
        else
        {
             ob->flag = 0;
             max = max_point(ob);

           printf("There are no points of intersection at all.\n\n");
        }
    }
    if(!ob->B)
    {
      ob->t = - ob->C / ob->A;

        ob->x1 = ob->t;
        ob->y1 = -pow(ob->t, 2) / (2 * ob->p);

         ob->flag = 1;
         max = max_point(ob);

        printf("There is only one common point :\n\n");
        printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
    }
    if(!ob->A)
    {
        ob->q = -ob->C / ob->B;
        ob->y1 = ob->q;

        ob->D = -8 * ob->p * ob->q;

        //printf("%.2f", ob->D);

        if(ob->D > 0)
        {
            ob->x1 = -sqrt(ob->D) / 2;
            ob->x2 = sqrt(ob->D) / 2;

             ob->flag = 2;
             max = max_point(ob);

            printf("\nThere are two points of intersection :\n\n");
            printf("--Point1(%.2f, %.2f)\n", ob->x1, ob->y1);
            printf("--Point2(%.2f, %.2f)\n\n", ob->x2, ob->y1);
        }
        else if(ob->D == 0)
        {
            ob->x1 = sqrt(ob->D) / 2;

             ob->flag = 1;
             max = max_point(ob);

            printf("There is only one common point :\n\n");
            printf("--Point(%.2f, %.2f)\n\n", ob->x1, ob->y1);
        }
        else
        {            
             ob->flag = 0;
             max = max_point(ob);

           printf("There are no points of intersection at all.\n\n");
        }
    }
 //------------------------drawing-------------------------//
    lets_draw(ob,  draw_parabola_down, max);
}

//------------------------------------------------------------------------------

