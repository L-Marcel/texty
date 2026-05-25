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

#include "enums/access.hpp"
#include "enums/assign.hpp"
#include "enums/call.hpp"
#include "enums/for.hpp"
#include "enums/if.hpp"
#include "enums/operations.hpp"
#include "enums/range.hpp"
#include "enums/references.hpp"
#include "enums/type.hpp"
#include "enums/while.hpp"
#include "errors.hpp"
#include "lib/CLI11.hpp"
#include "lib/magic_enum.hpp"

// Correção para Windows: evita colisão com macros do sistema
#ifdef _WIN32
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

using namespace std;