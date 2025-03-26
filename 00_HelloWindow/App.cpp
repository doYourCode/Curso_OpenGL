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
}

void App::OnRender()
{
    glClearColor(m_BgColor.r, m_BgColor.g, m_BgColor.b, m_BgColor.a);
}

void App::OnShutdown()
{
}
