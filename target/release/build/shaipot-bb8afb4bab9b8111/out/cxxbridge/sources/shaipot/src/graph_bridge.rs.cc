#include "graph_generator.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};

template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

using GraphGenerator = ::GraphGenerator;

extern "C" {
::GraphGenerator *cxxbridge1$create_graph_generator(::std::uint64_t seed, ::std::uint64_t range) noexcept {
  ::std::unique_ptr<::GraphGenerator> (*create_graph_generator$)(::std::uint64_t, ::std::uint64_t) = ::create_graph_generator;
  return create_graph_generator$(seed, range).release();
}

::std::uint64_t cxxbridge1$GraphGenerator$next_random(::GraphGenerator &self) noexcept {
  ::std::uint64_t (::GraphGenerator::*next_random$)() = &::GraphGenerator::next_random;
  return (self.*next_random$)();
}

static_assert(::rust::detail::is_complete<::GraphGenerator>::value, "definition of GraphGenerator is required");
static_assert(sizeof(::std::unique_ptr<::GraphGenerator>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::GraphGenerator>) == alignof(void *), "");
void cxxbridge1$unique_ptr$GraphGenerator$null(::std::unique_ptr<::GraphGenerator> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::GraphGenerator>();
}
void cxxbridge1$unique_ptr$GraphGenerator$raw(::std::unique_ptr<::GraphGenerator> *ptr, ::GraphGenerator *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::GraphGenerator>(raw);
}
::GraphGenerator const *cxxbridge1$unique_ptr$GraphGenerator$get(::std::unique_ptr<::GraphGenerator> const &ptr) noexcept {
  return ptr.get();
}
::GraphGenerator *cxxbridge1$unique_ptr$GraphGenerator$release(::std::unique_ptr<::GraphGenerator> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$GraphGenerator$drop(::std::unique_ptr<::GraphGenerator> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::GraphGenerator>::value>{}(ptr);
}
} // extern "C"
