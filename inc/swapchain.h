#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <optional>
#include <set>
#include <cstdint> // Necessary for UINT32_MAX
#include <algorithm> // Necessary for std::min/std::max
#include "./device.h"

#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class SwapChain {
    public:
        VkSwapchainKHR swapChain;
        uint32_t imageCount;
        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;
        std::vector<VkImage> swapChainImages;
        std::vector<VkImageView> swapChainImageViews;

        SwapChain(
            VkPhysicalDevice* physicalDevice, 
            VkSurfaceKHR* surface, 
            GLFWwindow* window,
            Device &device
        );

        void clean(Device &device);

    private:
        void getSwapChainImages(Device &device);
        void createImageViews(Device &device);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice *physicalDevice, VkSurfaceKHR *surface);
        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow *window);
};

#endif