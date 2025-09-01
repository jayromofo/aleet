##################################################
### Valiables
##################################################

#########################
# C++
#########################
CXX = g++

#########################
# GO
#########################
BINARY_NAME=aleet-cli 
MAIN_PATH=./cmd/main.go
GO_BUILD_DIR=./bin
##################################################

#########################
# Build Flags
#########################
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS=-ldflags "-s -w"
GOFLAGS=-trimpath


# Default target
.PHONY: run clean buildcc build stats help

all: clean build

runc: buildcc
	@if [ -z "$(file)" ]; then \
		echo "Usage: make run file=XX"; \
		exit 1; \
	fi; \
	mkdir -p problems/build

	$(CXX) $(CXXFLAGS) -o problems/build/$(file) problems/src/$(file).cpp && \
	./problems/build/$(file)

# Move solution to solved folder
solved: 
	@if [ -z "$(file)" ]; then \
		echo "Usage: make solved file=XX"; \
		exit 1; \
	fi; \
	mkdir -p problems/solved && \
	mv ~/aleet/problems/src/$(file).cpp ~/aleet/problems/solved/

# Create build directory if it doesn't exist
buildcc: 
	
	mkdir -p build

test: 
	go test -v ./...

test-race:
	go test -race -v ./...

fmt: 
	go fmt ./...

lint:
	golangci-lint run

# Clean compiled files
clean:
	rm -rf problems/build/*
	rm -rf bin/aleet
	go clean


# Compile without running
compile:
	@if [ -z "$(file)" ]; then \
		echo "Usage: make compile file=XX"; \
		exit 1; \
	fi; \	
	$(CXX) $(CXXFLAGS) -o problems/build/$(file) problems/src/$(file).cpp

# Create new problem with template
create: 
	@if [ -z "$(file)" ]; then \
		echo "Usage: make create file=XX"; \
		exit 1; \
	fi; \
	[ -f "templates/cpp.tmpl" ] && [ ! -f "$(file).cpp" ] && cp templates/cpp.tmpl problems/src/$(file).cpp
	code problems/src/$(file).cpp


# Statistics
stats:
	@echo "Problems in progress: $$(ls -1 problems/src/ 2>/dev/null | wc -l || echo 0)"
	@echo "Problems solved: $$(ls -1 problems/solved/ 2>/dev/null | wc -l || echo 0)"

# Compile Go
build: 
	mkdir -p $(GO_BUILD_DIR)
	go build $(GOFLAGS) $(LDFLAGS) -o $(GO_BUILD_DIR)/$(BINARY_NAME) $(MAIN_PATH)

# Dev
dev: 
	go build -race -o $(GO_BUILD_DIR)/$(BINARY_NAME)-d $(MAIN_PATH)

run:
	go run $(MAIN_PATH)

install:
	 go install $(GOFLAGS) $(LDFLAGS) $(MAIN_PATH)

start: build
	./bin/aleet-cli serve

# CLI Help
help:
   	@echo "  Available targets:"
	@echo "  build     - Build the binary"
	@echo "  dev       - Build with race detection"
	@echo "  run       - Run without building"
	@echo "  install   - Install to GOPATH/bin"
	@echo "  test      - Run tests"
	@echo "  test-race - Run tests with race detection"
	@echo "  fmt       - Format code"
	@echo "  lint      - Run linter"
	@echo "  clean     - Remove build artifacts"

