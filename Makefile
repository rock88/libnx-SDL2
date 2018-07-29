BUILD = libnx/lib
TARGET :=	$(BUILD)/libnx.a
SOURCES := source/gfx source/runtime source/runtime/devices source/services

CC := gcc
CXX := g++
AR := ar

INCLUDES := -I./libnx/include $(shell sdl-config --cflags)
CFLAGS := -g -Wall -Werror -ffunction-sections -fdata-sections
CFLAGS += $(INCLUDES)
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++11
ASFLAGS := -g

CFILES := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c))
CPPFILES := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.cpp))

OBJS := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o)

#---------------------------------------------------------------------------------
all: $(BUILD) $(OBJS) $(TARGET)

$(BUILD):
	@[ -d $@ ] || mkdir -p $@

$(TARGET): $(OBJS)
	$(AR) -rc $@ $^

#---------------------------------------------------------------------------------
%.o: %.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.o: %.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(OBJS) $(TARGET)

