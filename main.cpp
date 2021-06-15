#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "inc/helpers.h"
#include "inc/swapchain.h"
#include "inc/pipeline.h"
#include "inc/device.h"
#include "inc/framebuffer.h"
#include "inc/commandbuffer.h"
#include "inc/draw.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;


class HelloTriangleApplication {
    public:
        void run() {
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }
    
    private:
        GLFWwindow* window;
        VkInstance instance;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkSurfaceKHR surface;

        Device *device;
        SwapChain *swapChain;
        Pipeline *pipeline;
        FrameBuffer *frameBuffer;
        CommandBuffer *commandBuffer;
        Draw *draw;
        

        void initWindow() {
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        }

        void initVulkan() {
            createInstance(&instance);
            pickPhysicalDevice(&instance, &physicalDevice);
            createSurface(&instance, window, &surface);

            // passing all this stuff between objects is unneccessary, should just store reference
            device = new Device(&surface, &physicalDevice);
            swapChain = new SwapChain(&physicalDevice, &surface, window, *device);
            pipeline = new Pipeline(*device, *swapChain);
            frameBuffer = new FrameBuffer(*device, *swapChain, *pipeline);
            commandBuffer = new CommandBuffer(*device);
            commandBuffer->createCommandBuffers(*device, *frameBuffer, *pipeline, *swapChain);
            draw = new Draw(*device);
        }

        void mainLoop() {
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
                draw->drawFrame(*device, *swapChain, *commandBuffer);
                // https://vulkan-tutorial.com/en/Drawing_a_triangle/Drawing/Rendering_and_presentation
            }
        }

        void cleanup() {
            draw->clean(*device);
            commandBuffer->clean(*device);
            frameBuffer->clean(*device);
            pipeline->clean(*device);
            swapChain->clean(*device);

            vkDestroySurfaceKHR(instance, surface, nullptr);
            vkDestroyDevice(device->device, nullptr);
            vkDestroyInstance(instance, nullptr);
            glfwDestroyWindow(window);
            glfwTerminate();
        }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

