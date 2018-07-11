TARGET = newfrzns
SRC_DIRS = ./src
INC_DIRS ?= ./include

SRCS := $(wildcard $(SRC_DIRS)/*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

LD_FLAGS = -lc -lSDL2 -lSDL2_image

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -std=c++11 -Wall -pedantic

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LD_FLAGS)

%.d: %.cpp
	$(CPP) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
