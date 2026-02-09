ifeq ($(origin CXX),default)
	CXX = g++
endif

CXXFLAGS ?= -Wall -Wextra -pedantic -O0 -g -std=c++17
OUT_O_DIR ?= build
ROOT_DIR ?= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

LIBDIR = logger

.PHONY: all logger
all: logger

logger:
	$(MAKE) -C $(LIBDIR) OUT_O_DIR=../$(OUT_O_DIR) CXXFLAGS=$(CXXFLAGS) ROOT_DIR=../$(ROOT_DIR)
	
.PHONY: clean
clean:
	$(MAKE) clean -C $(LIBDIR)
