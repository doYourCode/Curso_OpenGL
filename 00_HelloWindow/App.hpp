#pragma once

#include <Application/IApplication.h>

#include <glm/glm.hpp>

class App : public Common::IApplication
{
public:

    bool OnInit() final;

    void OnUpdate(float deltaTime) final;

    void OnRender() final;

    void OnShutdown() final { /* Must be overriden */ }

    void OnResize(GLFWwindow* window, int width, int height) final;

private:

    glm::vec4 m_BgColor = { 1.0f, 0.0f, 0.0f, 1.0f };
};

