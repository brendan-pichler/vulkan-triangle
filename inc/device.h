#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <optional>
#include <set>

#ifndef DEVICE_H
#define DEVICE_H

struct QueueFamilyIndices {
    uint32_t graphicsFamily;
    uint32_t presentFamily;
};

class Device {
    public:
        VkDevice device;
        QueueFamilyIndices indices;
        VkQueue graphicsQueue;
        VkQueue presentQueue;

        Device(VkSurfaceKHR* surface, VkPhysicalDevice* physicalDevice);

    private:
        void findQueueFamilies(VkPhysicalDevice* physicalDevice, VkSurfaceKHR* surface);
};

#endif