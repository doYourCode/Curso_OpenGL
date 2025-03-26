#pragma once

#include <Application/IApplication.h>

#include <glm/glm.hpp>

using Color = glm::vec4;

class App : public Common::IApplication
{
public:

    bool OnInit() final;

    void OnUpdate(float deltaTime) final;

    void OnRender() final;

    void OnShutdown() final;

private:

    Color m_BgColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
};

