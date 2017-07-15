//#include <stdio.h>
//#include <windows.h>
//#define GLEW_STATIC

//#include "glew.h"

//#include <GL/gl.h>

//#include "glfw3.h"
//#include "glfw3native.h"


//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


//// Shaders
////GLchar* vertexShaderSource = "#version 330 core\n"
////    "layout (location = 0) in vec3 position;\n"
////    "void main()\n"
////    "{\n"
////    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
////    "}\0";
////GLchar* fragmentShaderSource = "#version 330 core\n"
////    "out vec4 color;\n"
////    "void main()\n"
////    "{\n"
////    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
////    "}\n\0";


//typedef struct
//{
//    float r;
//    float g;
//    float b;
//    float a;
//} colorRGBA;

//int main ()
//{

//    int width = 800,
//        height = 600;
//    printf("Please enter the value");

//    GLFWwindow* window;

//    // (0.2f, 0.3f, 0.3f, 1.0f) dark green-blueish --> mut`
//    // (0.01f, 0.2f, 0.8f, 1.0f) zbs blue
//    colorRGBA color;
//    color.r  = 0.01f;
//    color.g = 0.2f;
//    color.b = 0.8f;
//    color.a = 1.0f;

//    GLfloat vertices[] =
//    { //   x       y      z
//        -0.5f, -0.5f, 0.0f,
//         0.5f, -0.5f, 0.0f,
//         0.0f,  0.5f, 0.0f
//    };

//    // init GLFW
//    if (!glfwInit())
//        return -1;
//    // Set options
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

//    // GLFWindow object
//    window = glfwCreateWindow (width, height, "GL renderring", NULL, NULL);

//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//    if (window == NULL)
//    {
//        printf("Failed to create window");
//        glfwTerminate ();;
//        return -1;
//    }

//    // viewport dimension
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &width, &height);
//    glViewport(0, 0, width, height);

//    // Set the required callback function
//    glfwSetKeyCallback(window, key_callback);


////    // shaders
////    GLuint vertexShader;
////    vertexShader = glCreateShader(GL_VERTEX_SHADER);
////    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////    glCompileShader(vertexShader);

//    // Check for errors
////    GLint success;
////    GLchar infoLog[512];
////    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////    if (!success)
////    {
////        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////        printf("%s\n", infoLog);
////    }

//////! coord start in left top vertex
//  glOrtho (0, 800, 600, 0, 0, 1);

//    while (!glfwWindowShouldClose(window))
//    {
//        glfwPollEvents();
//        glClearColor(color.r, color.g, color.b, color.a);
//        glClear(GL_COLOR_BUFFER_BIT);

//        ////
//        glColor3b (80,240,90);

////        glBegin (GL_TRIANGLES);
////                glVertex3f (60.0, 60.0, 0.0 ) ;
////                glVertex3f (0.0, 60.0, 0.0);
////                glVertex3f (60.0, 0.0, 0.0);
////                glEnd ( ) ;

////        glBegin (GL_QUADS);
////                glVertex3f (  10.0,  10.0, 0.0);
////                glVertex3f (100.0,  10.0, 0.0);
////                glVertex3f (100.0,  50.0, 0.0);
////                glVertex3f ( 10.0 ,  50.0, 0.0);
////                glEnd ( ) ;
////// !
//            glBegin (GL_LINES);
//                    glVertex2f (  10.0,  10.0);
//                    glVertex2f (100.0,  10.0);
//            glBegin (GL_LINE);
//                    glVertex2f (100.0,   10.0);
//                    glVertex2f (100.0, 100.0);
//            glBegin (GL_LINE);
//                    glVertex2f (100.0, 100.0);
//                    glVertex2f (  10.0, 100.0);
//            glBegin (GL_LINE);
//                    glVertex2f (  10.0, 100.0);
//                    glVertex2f (  10.0,   10.0);
////// !
//            glBegin (GL_LINE);
//                    glVertex2f ( 120.0, 10.0);
//                    glVertex2f ( 210.0, 45.0);
//            glBegin (GL_LINE);
//                    glVertex2f (120.0, 100.0);
//                    glVertex2f (210.0, 45.0);
////            glBegin (GL_LINE);
////                    glVertex2f ( 210.0,   10.0);
////                    glVertex2f ( 210.0, 100.0);
////            glBegin (GL_LINE);
////                    glVertex2f ( 210.0, 100.0);
////                    glVertex2f ( 120.0, 100.0);
//            glBegin (GL_LINE);
//                    glVertex2f ( 120.0, 100.0);
//                    glVertex2f ( 120.0,   10.0);
//            glBegin (GL_LINE);
//                    glVertex2f ( 120.0,   10.0);
//                    glVertex2f ( 120.0, 200.0);
////// !
//            glBegin (GL_LINE);
//                    glVertex2f ( 220.0, 100.0);
//                    glVertex2f ( 260.0,   10.0);
//            glBegin (GL_LINE);
//                    glVertex2f ( 260.0,   10.0);
//                    glVertex2f ( 300.0, 100.0);
//            glBegin (GL_LINE);
//                    glVertex2f ( 229.0, 80.0);
//                    glVertex2f ( 280.0, 60.0);
////// !
//        glBegin (GL_LINE);
//                glVertex2f (330.0, 10.0);
//                glVertex2f (360.0, 200.0);
//        glBegin (GL_LINE);
//                glVertex2f (360.0, 10.0);
//                glVertex2f (360.0, 200.0);
//        glBegin (GL_LINE);
//                glVertex2f (390.0, 10.0);
//                glVertex2f (360.0, 200.0);
//        glBegin (GL_CURVE);
//                glVertex2f ( 200.0,   60.0);
//                glVertex2f ( 300.0, 100.0);

//                glEnd();

//        glfwSwapBuffers(window);



////        glfwSetKeyCallback(window, key_callback);
//    }


//    glfwTerminate();
//    return 0;
//}



//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}
