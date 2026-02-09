ifeq ($(origin CXX),default)
	CXX = g++
endif

TARGET = liblogger.so

CXXFLAGS ?= -Wall -Wextra -O0 -g -std=c++17
OUT_O_DIR ?= build
COMMONINC = -I./include
SRC = ./src
ROOT_DIR ?= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

override CXXFLAGS += $(COMMONINC)

CPPSRC = src/main.cpp

PREF = $(OUT_O_DIR)/obj
CPPOBJ := $(addprefix $(PREF)/,$(CPPSRC:.cpp=.o))
DEPS = $(CPPOBJ:.o=.d)

.PHONY: all
all: logger

logger: $(CPPOBJ)
	$(CXX) $(CXXFLAGS) $(CPPOBJ) -o $@
	
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