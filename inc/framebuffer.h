#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include "./swapchain.h"
#include "./device.h"
#include "./pipeline.h"

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class FrameBuffer {
    public:
        std::vector<VkFramebuffer> swapChainFramebuffers;

        FrameBuffer(Device &device, SwapChain &swapChain, Pipeline &pipeline);
        void clean(Device &device);
};


#endif