CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I./src -Igrammar/build -Iexternal/magic_enum/include

TARGET = texty
GRAMMAR_DIR = grammar
BUILD_DIR = $(GRAMMAR_DIR)/build
BISON_CC = $(BUILD_DIR)/syntax.tab.cc
BISON_HH = $(BUILD_DIR)/syntax.tab.hh
FLEX_C = $(BUILD_DIR)/lex.yy.c

SRCS = src/main.cpp \
       src/syntax/tree.cpp \
       src/syntax/literals.cpp \
       src/syntax/specials.cpp \
       src/references/references.cpp \
			 src/debug/debug.cpp

all: $(TARGET)

$(TARGET): $(BISON_CC) $(FLEX_C) $(SRCS)
	$(CXX) $(CXXFLAGS) $(FLEX_C) $(BISON_CC) $(SRCS) -o $(TARGET)

$(BISON_CC) $(BISON_HH): $(GRAMMAR_DIR)/syntax.y
	@mkdir -p $(BUILD_DIR)
	bison -d $(GRAMMAR_DIR)/syntax.y -o $(BISON_CC)

$(FLEX_C): $(GRAMMAR_DIR)/lexical.l $(BISON_HH)
	@mkdir -p $(BUILD_DIR)
	flex -o $(FLEX_C) $(GRAMMAR_DIR)/lexical.l

ast:
	dot -Tpng ast.dot -o ast.png

run:
	./$(TARGET)

pendrive:
	/lib64/ld-linux-x86-64.so.2 ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)