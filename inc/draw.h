#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include "./swapchain.h"
#include "./device.h"
#include "./pipeline.h"
#include "./framebuffer.h"
#include "./commandbuffer.h"

#ifndef DRAW_H
#define DRAW_H

class Draw {
    public:
        VkSemaphore imageAvailableSemaphore;
        VkSemaphore renderFinishedSemaphore;

        Draw(Device &device);

        void drawFrame(Device &device, SwapChain &swapChain, CommandBuffer &commandBuffer);
        void clean(Device &device);
    
    private:
        void createSemaphores(Device &device);
};


#endif