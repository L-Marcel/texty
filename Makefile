CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I./src -Igrammar/build -Iexternal/magic_enum/include

TARGET = texty
BUILD_DIR = build
GRAMMAR_DIR = grammar
GRAMMAR_BUILD_DIR = $(GRAMMAR_DIR)/build
BISON_CC = $(GRAMMAR_BUILD_DIR)/syntax.tab.cc
BISON_HH = $(GRAMMAR_BUILD_DIR)/syntax.tab.hh
FLEX_C = $(GRAMMAR_BUILD_DIR)/lex.yy.c
EMBEDDED_STD = src/embedded_standard.hpp
PACKER_SRC = src/packer.cpp

ifeq ($(OS),Windows_NT)
	BISON = win_bison
	FLEX = win_flex
	TARGET_EXT = .exe
	MD = if not exist $(subst /,\,$1) mkdir $(subst /,\,$1)
	RD = if exist $(subst /,\,$1) rmdir /s /q $(subst /,\,$1)
	RM_FILE = if exist $(subst /,\,$1) del /q $(subst /,\,$1)
else
	BISON = bison
	FLEX = flex
	TARGET_EXT =
	MD = mkdir -p $1
	RD = rm -rf $1
	RM_FILE = rm -f $1
endif

PACKER_BIN = packer$(TARGET_EXT)

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRCS_ALL = $(call rwildcard,src/,*.cpp)
SRCS = $(filter-out $(PACKER_SRC), $(SRCS_ALL))
EXAMPLES = $(call rwildcard,examples/,*.txy)
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o) $(BISON_CC:.cc=.o) $(FLEX_C:.c=.o))

.PHONY: build all check clean examples examples-pendrive

build: all
all: $(TARGET)$(TARGET_EXT)

$(TARGET)$(TARGET_EXT): $(EMBEDDED_STD) $(BISON_CC) $(FLEX_C) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)$(TARGET_EXT)

$(EMBEDDED_STD): $(PACKER_SRC) $(call rwildcard,src/standard/,*.*)
	@echo "[ PACK ] Compilando empacotador..."
	$(CXX) -std=c++17 $(PACKER_SRC) -o $(PACKER_BIN)
	@echo "[ PACK ] Gerando biblioteca padrao embutida..."
	./$(PACKER_BIN)

$(BUILD_DIR)/%.o: %.cpp
	@$(call MD,$(dir $@))
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cc
	@$(call MD,$(dir $@))
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c
	@$(call MD,$(dir $@))
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BISON_CC) $(BISON_HH): $(GRAMMAR_DIR)/syntax.y
	@$(call MD,$(GRAMMAR_BUILD_DIR))
	$(BISON) -d $(GRAMMAR_DIR)/syntax.y -o $(BISON_CC)

$(FLEX_C): $(GRAMMAR_DIR)/lexical.l $(BISON_HH)
	@$(call MD,$(GRAMMAR_BUILD_DIR))
	$(FLEX) --header-file=$(GRAMMAR_BUILD_DIR)/lex.yy.h -o $(FLEX_C) $(GRAMMAR_DIR)/lexical.l

$(OBJS): $(BISON_CC) $(FLEX_C)

$(BUILD_DIR)/src/nodes/compiler.o: src/nodes/compiler.cpp $(EMBEDDED_STD)

check: 
	$(BISON) -Wcounterexamples grammar/syntax.y

examples: build $(EXAMPLES)
ifeq ($(OS),Windows_NT)
	@powershell -ExecutionPolicy Bypass -Command "\
	$$failed=0; \
	foreach ($$file in '$(EXAMPLES)'.Split(' ')) { \
		if ($$file -eq '') { continue; } \
		Write-Host '[ COMPILE ]' $$file; \
		& .\$(TARGET)$(TARGET_EXT) --file $$file; \
		if ($$LASTEXITCODE -eq 0) { \
			$$dot = $$file -replace '\.txy$$', '.dot'; \
			$$svg = $$file -replace '\.txy$$', '.svg'; \
			dot -Tsvg $$dot -o $$svg; \
		} else { \
			$$failed=1; \
		} \
	}; \
	if ($$failed -ne 0) { exit 1; }"
else
	@failed=0; \
	for file in $(EXAMPLES); do \
		echo "[ COMPILE ] $$file"; \
		(./$(TARGET)$(TARGET_EXT) --file "$$file" && dot -Tsvg "$${file%.txy}.dot" -o "$${file%.txy}.svg") || failed=1; \
	done; \
	if [ $$failed -ne 0 ]; then exit 1; fi
endif

examples-pendrive: build $(EXAMPLES)
	@failed=0; \
	for file in $(EXAMPLES); do \
		echo "[ COMPILE ] $$file"; \
		(/lib64/ld-linux-x86-64.so.2 ./$(TARGET) --file "$$file" && dot -Tsvg "$${file%.txy}.dot" -o "$${file%.txy}.svg") || failed=1; \
	done; \
	if [ $$failed -ne 0 ]; then exit 1; fi

clean:
	@$(call RD,$(BUILD_DIR))
	@$(call RD,$(GRAMMAR_BUILD_DIR))
	@$(call RM_FILE,$(TARGET)$(TARGET_EXT))
	@$(call RM_FILE,$(PACKER_BIN))
	@$(call RM_FILE,$(EMBEDDED_STD))