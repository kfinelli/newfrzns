TARGET := newfrzns
SRC_DIRS := src
INC_DIRS := include
OBJ_DIR := .o
DEP_DIR := .d

SRCS := $(wildcard $(SRC_DIRS)/*.cpp)
#$(info $(SRCS))
OBJS := $(patsubst %,$(OBJDIR)%.o,$(basename $(SRCS)))
#$(info $(OBJS))
DEPS := $(patsubst %,$(DEPDIR)%.d,$(basename $(SRCS)))

$(shell mkdir -p $(dir $(OBJS)) >/dev/null)
$(shell mkdir -p $(dir $(DEPS)) >/dev/null)

CPP := g++
LD  := g++

INCFLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INCFLAGS) -std=c++11 -Wall -pedantic
LDFLAGS := 
DEPFLAGS := -MT $@ -MD -MP -MF $(DEP_DIR)/$*.Td

LD_LIBS := -lc -lSDL2 -lSDL2_image


$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS)$^ $(LD_LIBS) -o $@ 

%.d: %.cpp
	$(CPP) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
