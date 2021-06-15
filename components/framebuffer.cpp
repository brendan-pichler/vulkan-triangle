#include "../inc/framebuffer.h"

FrameBuffer::FrameBuffer(Device &device, SwapChain &swapChain, Pipeline &pipeline) {
    swapChainFramebuffers.resize(swapChain.swapChainImageViews.size());

    for (size_t i = 0; i < swapChain.swapChainImageViews.size(); i++) {
        VkImageView attachments[] = {
            swapChain.swapChainImageViews[i]
        };

        VkFramebufferCreateInfo framebufferInfo{};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = pipeline.renderPass;
        framebufferInfo.attachmentCount = 1;
        framebufferInfo.pAttachments = attachments;
        framebufferInfo.width = swapChain.swapChainExtent.width;
        framebufferInfo.height = swapChain.swapChainExtent.height;
        framebufferInfo.layers = 1;

        vkCreateFramebuffer(device.device, &framebufferInfo, nullptr, &swapChainFramebuffers[i]);
    }
}

void FrameBuffer::clean(Device &device) {
    for (auto framebuffer : swapChainFramebuffers) {
        vkDestroyFramebuffer(device.device, framebuffer, nullptr);
    }
}
