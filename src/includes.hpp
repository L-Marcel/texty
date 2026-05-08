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
#include "enums/operations.hpp"
#include "enums/references.hpp"
#include "enums/type.hpp"
#include "errors.hpp"
#include "lib/CLI11.hpp"
#include "lib/magic_enum.hpp"

using namespace std;