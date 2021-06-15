INC_DIR=inc
CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SOURCES = main.cpp components/helpers.cpp components/swapchain.cpp components/load.cpp components/pipeline.cpp components/device.cpp components/framebuffer.cpp components/commandbuffer.cpp components/draw.cpp
# DEPS = -I$(INC_DIR)/helpers.h -I$(INC_DIR)/validation.h

VulkanTest: main.cpp
	g++ $(CFLAGS) -o VulkanTest.exe $(SOURCES) $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./VulkanTest.exe

clean:
	rm -f VulkanTest.exe