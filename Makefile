ifeq ($(origin CXX),default)
	CXX = g++
endif

CXXFLAGS ?= -Wall -Wextra -pedantic -O0 -g -std=c++17
LDFLAGS ?=

BUILD_DIR ?= build
OUTPUT_DIR ?= $(BUILD_DIR)/bin
LIB_OUTPUT_DIR ?= $(BUILD_DIR)/lib
ROOT_DIR ?= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

LOGGER_DIR := logger
APP_DIR := app

.PHONY: all logger app clean
all: logger # app

logger:
	$(MAKE) -C $(LOGGER_DIR) \
		BUILD_DIR=../$(BUILD_DIR) \
		CXXFLAGS="$(CXXFLAGS)" \
		LIB_OUTPUT_DIR=../$(LIB_OUTPUT_DIR)

app: logger
	$(MAKE) -C $(APP_DIR) \
		BUILD_DIR=../$(BUILD_DIR) \
		CXXFLAGS="$(CXXFLAGS)" \
		LDFLAGS="$(LDFLAGS) -L../$(LIB_OUTPUT_DIR) -llogger" \
		OUTPUT_DIR=../$(OUTPUT_DIR) \
		LIB_OUTPUT_DIR=../$(LIB_OUTPUT_DIR)

run: app

	
clean:
	$(MAKE) clean -C $(LOGGER_DIR)
