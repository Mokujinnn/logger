ifeq ($(origin CXX),default)
	CXX = g++
endif

TARGET = app

CXXFLAGS ?= -Wall -Wextra -O0 -g -std=c++17
COMMONINC ?= -I./logger/include
override CXXFLAGS += -fPIC $(COMMONINC)
LDFLAGS ?=
override LDFLAGS += -Wl,-rpath,'$$ORIGIN/../lib'

BUILD_DIR ?= ../build
BIN_OUTPUT_DIR ?= $(BUILD_DIR)/bin
LIB_OUTPUT_DIR ?= $(BUILD_DIR)/lib
OBJ_DIR ?= $(BUILD_DIR)/obj/app

TARGET := $(BIN_OUTPUT_DIR)/$(TARGET)

SRC = ./src
ROOT_DIR ?= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

CPPSRC = $(wildcard $(SRC)/*.cpp)

PREF = $(BUILD_DIR)/obj/app
CPPOBJ := $(addprefix $(PREF)/,$(CPPSRC:.cpp=.o))
DEPS = $(CPPOBJ:.o=.d)

.PHONY: all app
all: $(TARGET)

$(TARGET): $(CPPOBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPOBJ) -o $@ $(LDFLAGS)
	
$(CPPOBJ) : $(PREF)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DEPS) : $(PREF)/%.d : %.cpp
	@mkdir -p $(@D)
	$(CXX) -E $(CXXFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -rf $(CPPOBJ) $(DEPS) $(PREF) $(TARGET)

# targets which we have no need to recollect deps
NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
include $(DEPS)
endif