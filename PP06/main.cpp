#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#pragma comment(lib,"opengl32")
//외부에 무언가를 갖다가 쓸 때

const char* vertexShaderSource =
{
    "#version 330 core\n"

    "#define IN_VERTEX	0\n"
    "#define IN_COLOR	1\n"
    "#define IN_TEXTURE 2\n"

    "layout (location=IN_VERTEX) in highp vec3 position;\n"
    "layout (location=IN_COLOR)	 in lowp vec3 colors;\n"
    "layout (location=IN_TEXTURE) in mediump vec2 texCoord;\n"

    "out mediump vec2 outTex;\n"

    "uniform highp mat4 transformationMat;\n"

    "void main()\n"
    "{\n"
    "	gl_Position = transformationMat*vec4(position,1.0);\n"
    "   outTex = texCoord;\n"
    "}\n"
};


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if(key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
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
    glfwGetKey(window, GLFW_KEY_RIGHT);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        int pos_x, pos_y;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.f, 0.f, 0.f, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

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

        glm::mat4 myMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.0f));


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
