#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include "./swapchain.h"
#include "./device.h"
#include "./pipeline.h"
#include "./framebuffer.h"

#ifndef COMMANDBUFFER_H
#define COMMANDBUFFER_H

class CommandBuffer {
    public:
        VkCommandPool commandPool;
        std::vector<VkCommandBuffer> commandBuffers;

        CommandBuffer(Device &device);
        void createCommandBuffers(Device &device, FrameBuffer &frameBuffer, Pipeline &pipeline, SwapChain &swapChain);
        void clean(Device &device);
};


#endif