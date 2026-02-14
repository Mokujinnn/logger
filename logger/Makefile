ifeq ($(origin CXX),default)
	CXX = g++
endif

TARGET := liblogger.so

CXXFLAGS ?= -Wall -Wextra -O0 -g -std=c++17
COMMONINC = -I./include/logger
override CXXFLAGS += -fPIC $(COMMONINC)
LDFLAGS = -shared

BUILD_DIR ?= ../build
LIB_OUTPUT_DIR ?= $(BUILD_DIR)/lib
OBJ_DIR ?= $(BUILD_DIR)/obj/logger

TARGET := $(LIB_OUTPUT_DIR)/$(TARGET)

SRC = ./src
ROOT_DIR ?= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

CPPSRC = src/DefaultLogger.cpp src/FileSink.cpp src/TextFormatter.cpp

PREF = $(BUILD_DIR)/obj/logger
CPPOBJ := $(addprefix $(PREF)/,$(CPPSRC:.cpp=.o))
DEPS = $(CPPOBJ:.o=.d)

.PHONY: all
all: logger

logger: $(TARGET)

$(TARGET): $(CPPOBJ)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) $^ -o $@
	
$(CPPOBJ) : $(PREF)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DEPS) : $(PREF)/%.d : %.cpp
	@mkdir -p $(@D)
	$(CXX) -E $(CXXFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -rf $(CPPOBJ) $(DEPS) $(PREF) 

# targets which we have no need to recollect deps
NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
include $(DEPS)
endif