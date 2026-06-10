CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I./src -Igrammar/build -Iexternal/magic_enum/include

TARGET = texty
BUILD_DIR = build
GRAMMAR_DIR = grammar
GRAMMAR_BUILD_DIR = $(GRAMMAR_DIR)/build
BISON_CC = $(GRAMMAR_BUILD_DIR)/syntax.tab.cc
BISON_HH = $(GRAMMAR_BUILD_DIR)/syntax.tab.hh
FLEX_C = $(GRAMMAR_BUILD_DIR)/lex.yy.c

SRCS = $(shell find src -name "*.cpp")
EXAMPLES = $(shell find examples -name "*.txy")
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o) $(BISON_CC:.cc=.o) $(FLEX_C:.c=.o))

build: all
all: $(TARGET)

$(TARGET): $(BISON_CC) $(FLEX_C) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BISON_CC) $(BISON_HH): $(GRAMMAR_DIR)/syntax.y
	@mkdir -p $(GRAMMAR_BUILD_DIR)
	bison -d $(GRAMMAR_DIR)/syntax.y -o $(BISON_CC)

$(FLEX_C): $(GRAMMAR_DIR)/lexical.l $(BISON_HH)
	@mkdir -p $(GRAMMAR_BUILD_DIR)
	flex --header-file=$(GRAMMAR_BUILD_DIR)/lex.yy.h -o $(FLEX_C) $(GRAMMAR_DIR)/lexical.l

$(OBJS): $(BISON_CC) $(FLEX_C)

check: 
	bison -Wcounterexamples grammar/syntax.y

examples: build
	@failed=0; \
	for file in $(EXAMPLES); do \
		echo "[ COMPILE ] $$file"; \
		(./$(TARGET) --file "$$file" && dot -Tsvg "$${file%.txy}.dot" -o "$${file%.txy}.svg") || failed=1; \
	done; \
	if [ $$failed -ne 0 ]; then exit 1; fi

examples-pendrive: build
	@failed=0; \
	for file in $(EXAMPLES); do \
		echo "[ COMPILE ] $$file"; \
		(/lib64/ld-linux-x86-64.so.2 ./$(TARGET) --file "$$file" && dot -Tsvg "$${file%.txy}.dot" -o "$${file%.txy}.svg") || failed=1; \
	done; \
	if [ $$failed -ne 0 ]; then exit 1; fi

clean:
	rm -rf $(BUILD_DIR) $(GRAMMAR_BUILD_DIR) $(TARGET)