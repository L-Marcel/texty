#include <cmath>
#include "core.hpp"

namespace txy {

// Não apagar!!!
// using unbounded_value = ::std::monostate;
// using bound_value =
//     ::std::variant<unbounded_value, ::std::uint8_t, ::std::int32_t,
//                    ::std::int64_t, float, double>;

// using balue = ::std::variant<::std::string, ::std::uint8_t, ::std::int32_t,
//                              ::std::int64_t, float, double, bool, Record,
//                              Enum, Pointer, Option, Range>;
template <typename T>
struct array {
  ::std::shared_ptr<::std::vector<T>> ptr;

  array() : ptr(::std::make_shared<::std::vector<T>>()) {};
  array(::std::int32_t size)
      : ptr(::std::make_shared<::std::vector<T>>(
            static_cast<::std::size_t>(size))) {};
  array(::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {};
  array(::std::int32_t size, ::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {
    ptr->resize(static_cast<::std::size_t>(size));
  };

  T& operator[](::std::int32_t index) {
    return (*ptr)[static_cast<::std::size_t>(index)];
  };

  bool contains(const T& value) const {
    return ::std::find(ptr->begin(), ptr->end(), value) != ptr->end();
  };

  array<T> operator<<(const array<T>& other) const {
    array<T> result;
    result.ptr->reserve(this->ptr->size() + other.ptr->size());
    result.ptr->insert(result.ptr->end(), this->ptr->begin(), this->ptr->end());
    result.ptr->insert(result.ptr->end(), other.ptr->begin(), other.ptr->end());
    return result;
  };
};

template <typename T>
struct option {
  ::std::optional<T> inner;

  option() : inner(::std::nullopt) {}
  option(T value) : inner(::std::move(value)) {};

  bool is_some() const { return this->inner.has_value(); };
  bool is_none() const { return !this->inner.has_value(); };

  T unwrap() const {
    if (!this->inner.has_value()) {
      throw ::std::runtime_error("tentativa de acessar valor none");
    }
    return this->inner.value();
  };
};
};  // namespace txy
// namespace txy