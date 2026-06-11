#include <cstdint>
#include <memory>
#include <vector>

namespace txy {
struct vector {
  ::std::shared_ptr<::std::vector<::std::int32_t>> ptr;

  vector(int size)
      : ptr(::std::make_shared<::std::vector<::std::int32_t>>(size)) {};

  ::std::int32_t& operator[](int index) { return (*ptr)[index]; };
};
};  // namespace txy