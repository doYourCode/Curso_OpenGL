#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <string>

namespace Common
{
    class IApplication
    {
    public:
        /**
         * @brief Constructs an ApplicationInterface instance.
         *
         * Initializes the application with the specified window dimensions and title.
         * The window itself is not created in the constructor.
         *
         * @param width The width of the application window (default: 800).
         * @param height The height of the application window (default: 600).
         * @param title The title of the application window (default: "GLFW Application").
         */
        IApplication(const std::string& title = "GLFW Application", int width = 800, int height = 600)
            : m_Width(width), m_Height(height), m_Title(title) {
        }

        /**
         * @brief Destroys the ApplicationInterface instance.
         *
         * Calls the Shutdown() method to ensure proper cleanup of resources.
         */
        virtual ~IApplication() { Shutdown(); }

        /**
         * @brief Starts the application's main loop.
         *
         * This function runs the main event loop, handling updates and rendering
         * until the application is instructed to exit.
         */
        void Run();

        // Utility methods

        /**
         * @brief Gets the GLFW window instance.
         *
         * @return Pointer to the GLFWwindow associated with this application.
         */
        inline GLFWwindow* GetWindow() const { return m_Window; }

        /**
         * @brief Gets the width of the application window.
         *
         * @return The window width in pixels.
         */
        inline int GetWidth() const { return m_Width; }

        /**
         * @brief Gets the height of the application window.
         *
         * @return The window height in pixels.
         */
        inline int GetHeight() const { return m_Height; }

        /**
         * @brief Gets the title of the application window.
         *
         * @return A reference to the window title string.
         */
        inline const std::string& GetTitle() const { return m_Title; }

        /**
         * @brief Sets the title of the application window.
         *
         * @param title The new window title.
         */
        inline void SetTitle(const std::string_view title) { m_Title = title; }

        /**
         * @brief Gets the root path for application assets.
         *
         * @return A reference to the string containing the assets root path.
         */
        inline const std::string& GetAssetsRootPath() const { return m_AssetsRootPath; }

        /**
         * @brief Checks if the application is currently running.
         *
         * @return True if the application is running, false otherwise.
         */
        inline bool IsRunning() const { return m_Running; }

        /**
         * @brief Stops the application by setting the running flag to false.
         */
        inline void Exit() { m_Running = false; }


    protected:

        // Virtual methods to be overridden by subclasses

        /**
         * @brief Called during application initialization.
         *
         * This method should be overridden to perform setup operations such as
         * loading resources, initializing graphics, or configuring the application.
         *
         * @return True if initialization succeeds, false otherwise.
         */
        virtual bool OnInit() = 0;

        /**
         * @brief Called every frame to update the application state.
         *
         * This method should be overridden to handle logic updates, physics simulation,
         * input processing, and other per-frame operations.
         *
         * @param deltaTime The time elapsed since the last frame, in seconds.
         */
        virtual void OnUpdate(float deltaTime) = 0;

        /**
         * @brief Called every frame to render the application.
         *
         * This method should be overridden to handle rendering logic, including
         * drawing objects, UI elements, and handling post-processing effects.
         */
        virtual void OnRender() = 0;

        /**
         * @brief Called during application shutdown.
         *
         * This method should be overridden to release resources, save state, and
         * perform any necessary cleanup before the application exits.
         */
        virtual void OnShutdown() = 0;

        // Callback event handlers

        /**
         * @brief Callback event handler for window resize events.
         *
         * This method is called whenever the window is resized.
         *
         * @param window The GLFW window that was resized.
         * @param width The new width of the window.
         * @param height The new height of the window.
         */
        virtual void OnResize(GLFWwindow* window, int width, int height) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for keyboard events.
         *
         * This method is called whenever a key event occurs, such as a key press or release.
         *
         * @param window The GLFW window where the event occurred.
         * @param key The key that was pressed or released.
         * @param scancode The scancode of the key.
         * @param action The action associated with the event (e.g., GLFW_PRESS, GLFW_RELEASE).
         * @param mods The modifier keys (e.g., GLFW_MOD_SHIFT).
         */
        virtual void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for character input events.
         *
         * This method is called whenever a character is input.
         *
         * @param window The GLFW window where the event occurred.
         * @param codepoint The Unicode codepoint of the character that was input.
         */
        virtual void OnCharacterEvent(GLFWwindow* window, unsigned int codepoint) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for mouse movement events.
         *
         * This method is called whenever the mouse is moved inside the window.
         *
         * @param window The GLFW window where the event occurred.
         * @param xpos The new X position of the mouse.
         * @param ypos The new Y position of the mouse.
         */
        virtual void OnMouseMove(GLFWwindow* window, double xpos, double ypos) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for mouse entering or leaving the window.
         *
         * This method is called when the mouse enters or leaves the window.
         *
         * @param window The GLFW window where the event occurred.
         * @param entered A flag indicating whether the mouse has entered (1) or left (0) the window.
         */
        virtual void OnMouseEnter(GLFWwindow* window, int entered) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for mouse button events.
         *
         * This method is called whenever a mouse button is pressed or released.
         *
         * @param window The GLFW window where the event occurred.
         * @param button The mouse button that was pressed or released.
         * @param action The action associated with the event (e.g., GLFW_PRESS, GLFW_RELEASE).
         * @param mods The modifier keys (e.g., GLFW_MOD_SHIFT).
         */
        virtual void OnMouseButton(GLFWwindow* window, int button, int action, int mods) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for mouse scroll events.
         *
         * This method is called whenever the mouse wheel is scrolled.
         *
         * @param window The GLFW window where the event occurred.
         * @param xoffset The amount of horizontal scroll.
         * @param yoffset The amount of vertical scroll.
         */
        virtual void OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for joystick events.
         *
         * This method is called whenever a joystick event occurs.
         *
         * @param jid The joystick ID.
         * @param event The event type (e.g., connected, disconnected).
         */
        virtual void OnJoystickEvent(int jid, int event) { /* meant to be overiden */ };

        /**
         * @brief Callback event handler for file drop events.
         *
         * This method is called when files are dropped into the window.
         *
         * @param window The GLFW window where the event occurred.
         * @param count The number of dropped files.
         * @param paths An array of file paths for the dropped files.
         */
        virtual void OnFileDrop(GLFWwindow* window, int count, const char** paths) { /* meant to be overiden */ };


    private:

        // Internal data members

        GLFWwindow* m_Window = nullptr;

        int m_Width;

        int m_Height;

        std::string m_Title;

        bool m_Running = false;

        const std::string m_AssetsRootPath = "asset/";

        static IApplication* m_CurrentApplication;

        bool InitializeSubsystems();

        void Shutdown();

        // Glfw callbacks

        static void error_callback(int error, const char* description);

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void character_callback(GLFWwindow* window, unsigned int codepoint);

        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

        static void cursor_enter_callback(GLFWwindow* window, int entered);

        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

        static void joystick_callback(int jid, int event);

        static void drop_callback(GLFWwindow* window, int count, const char** paths);
    };
}