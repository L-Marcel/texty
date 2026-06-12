#pragma once
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <variant>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#undef CONST
#undef IN
#undef VOID
#undef CHAR
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef BYTE
#undef BOOL
#undef ERROR
#endif
#include "enums/access.hpp"
#include "enums/array.hpp"
#include "enums/assign.hpp"
#include "enums/call.hpp"
#include "enums/cases.hpp"
#include "enums/for.hpp"
#include "enums/if.hpp"
#include "enums/operations.hpp"
#include "enums/option.hpp"
#include "enums/range.hpp"
#include "enums/references.hpp"
#include "enums/type.hpp"
#include "enums/while.hpp"
#include "errors.hpp"
#include "lib/CLI11.hpp"
#include "lib/magic_enum.hpp"

#define ANSI_RESET "\033[0m"
#define ANSI_BOLD "\033[1m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN "\033[36m"

#define FATAL_LABEL string("[\033[31m FATAL \033[0m] ")
#define ERROR_LABEL string("[\033[35m ERRO \033[0m] ")
#define DEBUG_LABEL string("[\033[36m DEBUG \033[0m] ")
#define INFO_LABEL string("[\033[34m INFO \033[0m] ")
#define SUCCESS_LABEL string("[\033[32m SUCESSO \033[0m] ")

using namespace std;