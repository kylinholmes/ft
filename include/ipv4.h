#include <_types/_uint32_t.h>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>

enum ErrCode {
    ok = 1u,
    err = 3u,
    nan = 4u,
    overflow_u8 = 5u,
    overflow_u32 = 6u,
};
auto f(std::string s) -> std::pair<uint32_t, uint32_t>;
