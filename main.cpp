#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

//EZZ I CREATE IT EZZZZ
//To Compile: g++ main.cpp imgui/imgui.cpp imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_impl_glfw.cpp imgui/imgui_impl_opengl2.cpp -lGL -lglfw -o imguiic

//booleans
bool draw_cricle = false;

void Drawing(int Size) {

}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int tab = 3;

int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Linux | OpenGL 2 | GLFW | By Cold Studio :)", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while (!glfwWindowShouldClose(window))
    {

        auto flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;

        glfwPollEvents();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static float f = 0.0f;
        static int counter = 0;
        static float fps = ImGui::GetIO().Framerate;

        ImGui::Begin("You Window", nullptr, flags);

        //imgui_tables
        if (ImGui::Button("Menu 1", ImVec2(0.0f, 0.0f))) {
            tab = 0;
        }
        ImGui::SameLine(0.f, 2.f);
         if (ImGui::Button("Menu 2", ImVec2(0.0f, 0.0f))) {
            tab = 1;
        }
        ImGui::SameLine(0.f, 2.f);
         if (ImGui::Button("Menu 3", ImVec2(0.0f, 0.0f))) {
            tab = 2;
        }
        ImGui::SameLine(0.f, 2.f);
         if (ImGui::Button("Menu 4", ImVec2(0.0f, 0.0f))) {
            tab = 3;
        }

        //imgui_checkboxes
        if (tab == 0) {
            ImGui::Text("Menu Test 1");
        }
        if (tab == 1) {
            ImGui::Text("Menu Test 2");
        }
        if (tab == 2) {
            ImGui::Text("Menu Test 3");
        }
        if (tab == 3) {
            ImGui::Text("Menu Test 4");
        }
        ImGui::End();


        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
