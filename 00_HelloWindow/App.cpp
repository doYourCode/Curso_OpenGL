#include "App.hpp"

#include <glad/glad.h>

#include <Util/MathUtility.hpp>

bool App::OnInit()
{
    glClearColor(m_BgColor.r, m_BgColor.g, m_BgColor.b, m_BgColor.a);

    return true;
}

void App::OnUpdate(float deltaTime)
{
    m_BgColor.r += 0.333f * deltaTime;
    m_BgColor.r = Common::MathUtility::ClampSwap(m_BgColor.r, 0.0f, 1.0f);

    glClearColor(m_BgColor.r, m_BgColor.g, m_BgColor.b, m_BgColor.a);
}

void App::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void App::OnResize(GLFWwindow* window, int width, int height)
{
    SetDimensions(width, height);
    glViewport(0, 0, width, height);
}
