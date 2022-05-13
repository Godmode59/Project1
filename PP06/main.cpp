#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"opengl32")
//외부에 무언가를 갖다가 쓸 때


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(1.f, 1.f, 1.f, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.81, 1, 0.89);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.75, -0.6);
        glVertex2f(-0.9, -0.9);
        glVertex2f(-0.6, -0.9);
        glColor3f(1, 0, 0);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.9, -0.6);
        glVertex2f(0.9, -0.9);
        glVertex2f(0.6, -0.9);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.9, -0.6);
        glVertex2f(0.6, -0.9);
        glEnd();

        glLoadIdentity();

        glRotatef(45, 0, 0, 1);

        glTranslatef(0.7, 0.7, 0);

        glScalef(2, 2, 2);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}