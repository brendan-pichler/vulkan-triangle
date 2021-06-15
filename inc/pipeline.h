#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "../inc/load.h"
#include "../inc/device.h"
#include "../inc/swapchain.h"

#ifndef PIPELINE_H
#define PIPELINE_H

class Pipeline {
    public:
        VkRenderPass renderPass;
        VkPipeline graphicsPipeline;
        VkPipelineLayoutCreateInfo pipelineLayoutInfo;
        VkPipelineLayout pipelineLayout;

        Pipeline(Device &device, SwapChain &swapChain);
        void clean(Device &device);

    private:
        VkShaderModule vertShaderModule{};
        VkShaderModule fragShaderModule{};
        VkPipelineShaderStageCreateInfo shaderStages[2];
        VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
        VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
        VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
        VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
        VkViewport viewport{};
        VkRect2D scissor{};
        VkPipelineViewportStateCreateInfo viewportState{};
        VkPipelineRasterizationStateCreateInfo rasterizer{};
        VkPipelineMultisampleStateCreateInfo multisampling{};
        VkPipelineColorBlendAttachmentState colorBlendAttachment{};
        VkPipelineColorBlendStateCreateInfo colorBlending{};
        VkPipelineDynamicStateCreateInfo dynamicState{};

        void createGraphicsPipeline(Device &device, SwapChain &swapChain);
        VkShaderModule createShaderModule(const std::vector<char> &code, Device &device);
        void createRenderPass(Device &device, SwapChain &SwapChain);
};

#endif