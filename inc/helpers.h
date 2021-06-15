#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

#ifndef HELPERS_H
#define HELPERS_H

void createInstance(VkInstance *pInstance);
void pickPhysicalDevice(VkInstance *pInstance, VkPhysicalDevice *physicalDevice);
void createSurface(VkInstance *instance, GLFWwindow *window, VkSurfaceKHR *surface);

#endif