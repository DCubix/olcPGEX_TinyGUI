#pragma once

#include "olcPixelGameEngine.h"

#include <optional>
#include <functional>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <map>

#ifdef DrawText
#undef DrawText
#endif

#ifdef None
#undef None
#endif

namespace utils {
    template <typename... Args>
    std::string StringFormat(const std::string& format, Args... args) {
        size_t size = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;
        std::string result(size, '\0');
        std::snprintf(result.data(), size, format.c_str(), args...);
        return result.substr(0, size - 1);
    }

    float Luma(const olc::Pixel& color);

    std::vector<std::string> Split(const std::string& str, const std::string& delimiter);
    std::vector<std::string> Split(const std::string& str, const std::initializer_list<std::string>& delimiters);

    size_t GetIDFromName(const std::string& name);
}

#pragma region Hardcoded Data
// RGB565A8
constexpr uint8_t GuiMapWidth = 128;
constexpr uint8_t GuiMapHeight = 8;
constexpr uint16_t GuiMapDataLength = 3072;
constexpr uint16_t GuiMapAlphaChannelStart = GuiMapWidth * GuiMapHeight * 2u;

constexpr uint8_t GuiMap[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
    0x00, 0x00, 0xff, 0xff, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0xec, 0x62, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x9e, 0xf7, 0x9e, 0xf7, 0x9e, 0xf7, 0x9e, 0xf7, 0x92, 0x94, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0x25, 0x29, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0xec, 0x62, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x3c, 0xe7, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xf7, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x10, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x6d, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
    0x00, 0x00, 0x3c, 0xe7, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xf7, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x10, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x6d, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x3c, 0xe7, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xf7, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x10, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x6d, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
    0x00, 0x00, 0x3c, 0xe7, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xf7, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xba, 0xd6, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x10, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x6d, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xec, 0x62, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0x92, 0x94, 0xab, 0x5a, 0xab, 0x5a, 0xab, 0x5a, 0xab, 0x5a, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x25, 0x29, 0x6d, 0x6b, 0x6d, 0x6b, 0x6d, 0x6b, 0x6d, 0x6b, 0x10, 0x84, 0x00, 0x00, 0x00, 0x00, 0xec, 0x62, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x75, 0xad, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x86, 0x31, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x3c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    /*alpha channel*/
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x04, 0x0a, 0x0e, 0x0e, 0x0a, 0x04, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x04, 0x17, 0x36, 0x48, 0x48, 0x36, 0x17, 0x04, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x0a, 0x36, 0x7d, 0xa7, 0xa7, 0x7d, 0x36, 0x0a, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x0e, 0x48, 0xa7, 0xe0, 0xe0, 0xa7, 0x48, 0x0e, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x0e, 0x48, 0xa7, 0xe0, 0xe0, 0xa7, 0x48, 0x0e, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x0a, 0x36, 0x7d, 0xa7, 0xa7, 0x7d, 0x36, 0x0a, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x04, 0x17, 0x36, 0x48, 0x48, 0x36, 0x17, 0x04, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x04, 0x0a, 0x0e, 0x0e, 0x0a, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00
};

enum class GuiMapSprite : uint8_t {
    ButtonIdle = 0,
    ButtonHovered,
    ButtonActive,
    Panel,
    Frame,
    Selection,
    Shadow,
    ArrowRight,
    ArrowLeft,
    ArrowUp,
    ArrowDown,
    Grip,
    X,
    Circle,
    Square,
    Checker
};

constexpr int PopupItemHeight = 20;
constexpr int FrameTitleHeight = 18;
#pragma endregion

struct Rect {
    int x, y, width, height;

    bool HasPoint(int x, int y) const;
    bool HasPoint(const olc::vi2d& pos) const;
    Rect Expand(int amount = 1);

    bool Intersects(const Rect& other) const;
    Rect Union(const Rect& other) const;
    Rect Intersection(const Rect& other) const;

    int DistanceToRect(const Rect& other) const;

    olc::vi2d Center() const { return { x + width / 2, y + height / 2 }; }
    olc::vi2d Position() const { return { x, y }; }
    olc::vi2d Size() const { return { width, height }; }
};

enum Alignment {
    // horizontal
    AlignLeft = 0,
    AlignCenter = 2,
    AlignRight = 4,
    // vertical
    AlignTop = 8,
    AlignMiddle = 16,
    AlignBottom = 32
};

class olcPGEX_TinyGUI : olc::PGEX {
public:
    enum class WidgetState {
        Idle = 0,
        Hovered,
        Active,
        Clicked
    };

    struct Widget {
        size_t id;
        WidgetState state{ WidgetState::Idle };
        bool pressed{ false }, released{ false }, visible{ true };
    };

    olcPGEX_TinyGUI() : olc::PGEX(true) {}

    // ------- WIDGETS -------
    Widget& GetWidget(const std::string& name, Rect bounds, bool blockInputByPopup = true);
    void Label(
        Rect bounds,
        const std::string& text,
        int alignment = (Alignment::AlignLeft | Alignment::AlignTop),
        const std::optional<olc::Pixel>& bg = std::nullopt,
        bool wordWrap = false
    );
    bool Button(
        const std::string& name,
        Rect bounds,
        const std::string& text,
        const std::optional<olc::Pixel>& color = std::nullopt
    );
    bool Slider(
        const std::string& name,
        Rect bounds,
        int& value, int min = 0, int max = 100, int step = 1,
        const std::optional<olc::Pixel>& bg = std::nullopt
    );
    bool SliderF(
		const std::string& name,
		Rect bounds,
		float& value, float min = 0.0f, float max = 1.0f, float step = 0.01f,
		const std::optional<olc::Pixel>& bg = std::nullopt
	);
    bool Toggle(const std::string& name, Rect bounds, const std::string& text, bool& value);
    bool Spinner(
        const std::string& name,
        Rect bounds,
        int& value, int min = 0, int max = 100, int step = 1,
        const std::string& fmt = "%d",
        const std::optional<olc::Pixel>& bg = std::nullopt
    );
    bool SpinnerF(
        const std::string& name,
		Rect bounds,
		float& value, float min = 0.0f, float max = 1.0f, float step = 0.01f,
		const std::string& fmt = "%.2f",
        const std::optional<olc::Pixel>& bg = std::nullopt
    );
    bool EditBox(const std::string& name, Rect bounds, std::string& text);
    void Image(const std::string& name, Rect bounds, olc::Sprite* sprite);

    void TabBar(const std::string& name, Rect bounds, std::string* tabs, size_t numTabs, size_t& selected);

    void BeginFrame(
        const std::string& name,
        const std::string& title,
        const olc::vi2d& position,
        int width,
        bool collapsible = false, bool fixed = false
    );
    Rect EndFrame();

    bool MakePopup(
        const std::string& name,
        std::string* items, size_t numItems, size_t* selected = nullptr
    );

    size_t GetPopupSelection(const std::string& name) {
        auto id = std::hash<std::string>()(name);
        auto it = m_popups.find(id);
        if (it == m_popups.end()) return 0;
        return it->second.lastSelected;
    }

    void ShowPopup(const std::string& name, olc::vi2d position);
    void ShowPopup(const std::string& name);

    bool WidgetPressed(const std::string& name) {
		return GetWidgetByName(name).pressed;
	}

    bool WidgetReleased(const std::string& name) {
        return GetWidgetByName(name).released;
    }

    // ------- LAYOUT -------
    void PushRect(Rect rect);
    Rect& PeekRect();
    void PopRect();
    Rect RectCutLeft(int amount);
    Rect RectCutRight(int amount);
    Rect RectCutTop(int amount);
    Rect RectCutBottom(int amount);

    void AddDockingArea(const std::string& name, const Rect& rect);
    void AddDockingAreaLeft(const std::string& name, int size);
    void AddDockingAreaRight(const std::string& name, int size);
    void AddDockingAreaTop(const std::string& name, int size);
    void AddDockingAreaBottom(const std::string& name, int size);
    void AddDockingAreaRemainingSpace(const std::string& name);

    // ------- DRAWING -------
    olc::Pixel PixelBrightness(olc::Pixel color, float amount);
    std::pair<int, int> TextSize(const std::string& text);

    void UpdateDecals();

    // ------- STATE -------
    void OnBeforeUserCreate() override;
    bool OnBeforeUserUpdate(float& fElapsedTime) override;
    void OnAfterUserUpdate(float fElapsedTime) override;

    bool GetMouseState() const { return m_state.mouseDown; }

    olc::vi2d GetLastClickedWidgetPosition() const { return m_state.lastClickedWidgetPosition; }
    olc::vi2d GetMousePos() const { return m_state.mousePos; }
    bool IsMouseDown() const { return m_state.mouseDown; }

    // ------- DRAW COMMANDS -------
    void DrawText(const std::string& text, olc::Pixel color, Rect bounds, size_t position = -1);
    void DrawFillRect(olc::Pixel color, Rect bounds, size_t position = -1);
    void DrawLine(olc::Pixel color, olc::vi2d a, olc::vi2d b, size_t position = -1);
    void DrawStyleSprite(GuiMapSprite sprite, olc::Pixel color, Rect bounds, size_t position = -1);
    void DrawStyle9Patch(GuiMapSprite sprite, olc::Pixel color, Rect bounds, uint8_t flags = 0xFF, size_t position = -1);
    void DrawImage(olc::Decal* image, Rect bounds, size_t position = -1);
    void EnableClip(Rect bounds);
    void DisableClip();

    olc::Pixel baseColor{ olc::Pixel(95, 134, 176) };

private:

    Widget& GetWidgetByName(const std::string& name);

    void DrawPopups();

    void DrawStyle9Patch(Rect bounds, olc::Pixel color, GuiMapSprite sprite, uint8_t flags);
    void DrawStyleSprite(Rect bounds, olc::Pixel color, GuiMapSprite sprite);
    GuiMapSprite WidgetStateToSprite(WidgetState state);

    bool CurrentFrameIsCollapsed();

    void RenderAll();
    void RenderDockingAreas();

    olc::Pixel GetBestForegroundColor(const std::optional<olc::Pixel>& bgColor = std::nullopt);

    size_t NearestDockingArea(const Rect& bounds);
    bool IsDockingAreaFree(size_t id);

    template <typename T>
    bool SliderImpl(
        const std::string& name,
        Rect bounds,
        T& value, T min, T max, T step,
        const std::optional<olc::Pixel>& bg
    ) requires std::is_integral_v<T> || std::is_floating_point_v<T> {
        const int thumbWidth = 16;
        const int thumbHeight = bounds.height;

        auto& wid = GetWidget(name, bounds);

        T oldVal = value;

        int actualWidth = bounds.width - thumbWidth;
        if (wid.state == WidgetState::Active) {
            int relativeX = m_state.mousePos.x - bounds.x - thumbWidth / 2;
            float fac = float(relativeX) / actualWidth;
            value = T(fac * (max - min) + min);
            value = std::clamp(value, min, max);
            // snap to step
            value = T(int(value / step) * step);
        }

        DrawStyle9Patch(
            GuiMapSprite::ButtonActive,
            baseColor,
            Rect{
                bounds.x, bounds.y,
                bounds.width, thumbHeight,
            }
        );
        if (bg.has_value()) {
            DrawFillRect(*bg, Rect{ bounds.x + 1, bounds.y + 1, bounds.width - 2, thumbHeight - 2 });
        }

        auto state = wid.state == WidgetState::Active || wid.state == WidgetState::Clicked ?
            WidgetState::Hovered : wid.state;

        float fac = float(value - min) / (max - min);
        int thumbX = int(fac * actualWidth);

        DrawStyle9Patch(
            WidgetStateToSprite(state),
            baseColor,
            Rect{ bounds.x + thumbX, bounds.y, thumbWidth, thumbHeight }
        );
        DrawStyleSprite(
            GuiMapSprite::Grip,
            baseColor,
            Rect{
                bounds.x + thumbX + thumbWidth / 2 - 4,
                bounds.y + thumbHeight / 2 - 4,
                8, 8
            }
        );

        return oldVal != value;
    }

    template <typename T>
    bool SpinnerImpl(
        const std::string& name,
        Rect bounds,
        const std::function<void(T&, T)> fnIncrement,
        T& value, T min, T max, T step,
        const std::string& fmt,
        const std::optional<olc::Pixel>& bg
    ) requires std::is_integral_v<T> || std::is_floating_point_v<T> {
        const auto dark = PixelBrightness(baseColor, 0.5f);
        const int thumbWidth = 18;

        DrawStyle9Patch(
            bg.has_value() ? GuiMapSprite::ButtonIdle : GuiMapSprite::ButtonActive,
            bg.has_value() ? *bg : dark,
            bounds
        );

        auto wid = GetWidget(name, Rect{ bounds.x + thumbWidth, bounds.y, bounds.width - thumbWidth * 2, bounds.height });

        const int buttonX = bounds.x + bounds.width - thumbWidth;
        const int buttonHeight = bounds.height / 2;

        bool changed = false;

        // add button
        if (Button(name + "_add", Rect{ buttonX, bounds.y, thumbWidth, buttonHeight }, "+")) {
            fnIncrement(value, step);
            value = std::clamp(value, min, max);
            changed = true;
        }

        // sub button
        if (Button(name + "_sub", Rect{ buttonX, bounds.y + buttonHeight, thumbWidth, buttonHeight }, "-")) {
            fnIncrement(value, -step);
            value = std::clamp(value, min, max);
            changed = true;
        }

        if (wid.state == WidgetState::Active) {
            fnIncrement(value, T(m_state.mouseDelta.x * step));
            value = std::clamp(value, min, max);
            changed = true;
        }

        auto text = utils::StringFormat(fmt.c_str(), value);
        auto [tw, th] = TextSize(text);

        olc::Pixel textColor = olc::WHITE;
        if (bg.has_value()) {
            textColor = GetBestForegroundColor(bg);
        }

        int textAreaWidth = bounds.width - thumbWidth;
        DrawText(
            text,
            textColor,
            { bounds.x + textAreaWidth / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height }
        );

        return changed;
    }

    struct Popup {
        std::string name;
        olc::vi2d position;
        olc::vi2d size;
        std::vector<std::string> items;
        size_t lastSelected{ 0 };
    };

    struct Frame {
        std::string title, name;

        // draw command location
        size_t insertId;

        Rect bounds, titleBounds;
        olc::vi2d positionOffset{ 0, 0 };
        bool collapsible, fixed;
        bool collapsed{ false }, dragging{ false };

        size_t dockId{ 0 };
    };

    struct TabBarState {
        uint32_t startIndex{ 0 };
	};

    struct {
        size_t hoveredId, activeId, focusedId, frontMostPanelId{ 0 };
        bool mouseDown, ignoreCollapsed{ false };
        olc::vi2d mousePos, lastClickedWidgetPosition, mouseDelta;
        size_t openPopup;
        float blinkTimer{ 0.0f };
        bool blink{ false };
        uint32_t targetLayer{ 0 };
        Frame* clickedFrame{ nullptr };
    } m_state{};

    // widgets state
    std::map<size_t, Widget> m_widgets;

    // specific state
    std::map<size_t, Popup> m_popups;
    std::map<size_t, Frame> m_frames;
    std::map<size_t, TabBarState> m_tabBars;
    std::vector<size_t> m_frameStack;

    // graphics/layout states
    std::vector<Rect> m_rectStack;
    std::map<size_t, std::unique_ptr<olc::Decal>> m_images;

    // docking
    std::map<size_t, Rect> m_dockingAreas;

    // --- DRAW COMMANDS ---
    std::unique_ptr<olc::Sprite> m_guiSprite;
    std::unique_ptr<olc::Decal> m_guiDecal;

    enum class DrawCommandType {
        Text,
        FillRect,
        Line,
        StyleSprite,
        Style9Patch,
        Image,
        EnableClip,
        DisableClip
    };

    struct DrawCommand {
        DrawCommandType type;
        std::string text;
        olc::Pixel color;
        Rect bounds;
        olc::Decal* image;
        GuiMapSprite sprite;
        uint8_t ninePatchFlags{ 0xFF };
        uint32_t targetLayer{ 0 };
    };

    struct Word {
        std::string text;
        enum {
            TypeText = 0,
            TypeSpace,
            TypeTab,
            TypeNewLine
        } type;
    };

    std::vector<DrawCommand> m_drawCommands;
    uint32_t m_widgetsLayer{ 0 }, m_panelsLayer{ 0 };

    void AddDrawCommand(DrawCommand cmd, size_t position = -1);
    void SetTargetLayer(uint32_t layer);
};

#ifdef OLC_PGEX_TINYGUI

void olcPGEX_TinyGUI::RenderAll() {
    std::vector<Rect> scissorStack;

    uint32_t prevDrawTarget = 0;
    for (const auto& cmd : m_drawCommands) {
        if (prevDrawTarget != cmd.targetLayer) {
            pge->SetDrawTarget(cmd.targetLayer);
            prevDrawTarget = cmd.targetLayer;
        }

        switch (cmd.type) {
			case DrawCommandType::Text:
                pge->DrawStringPropDecal(
					{ float(cmd.bounds.x), float(cmd.bounds.y) },
					cmd.text,
					cmd.color
				);
				break;
			case DrawCommandType::FillRect:
				pge->FillRectDecal(cmd.bounds.Position(), cmd.bounds.Size(), cmd.color);
				break;
			case DrawCommandType::Line:
                pge->DrawLineDecal(
                    olc::vf2d{ float(cmd.bounds.x), float(cmd.bounds.y) },
                    olc::vf2d{ float(cmd.bounds.width), float(cmd.bounds.height) },
					cmd.color
				);
				break;
            case DrawCommandType::Style9Patch:
				DrawStyle9Patch(cmd.bounds, cmd.color, cmd.sprite, cmd.ninePatchFlags);
				break;
			case DrawCommandType::StyleSprite:
                DrawStyleSprite(cmd.bounds, cmd.color, cmd.sprite);
				break;
            case DrawCommandType::Image: {
                olc::vf2d scale = {
                    float(cmd.bounds.width) / cmd.image->sprite->width,
					float(cmd.bounds.height) / cmd.image->sprite->height
                };
                pge->DrawDecal(cmd.bounds.Position(), cmd.image, scale, cmd.color);
            } break;
            case DrawCommandType::EnableClip: {
                // get current scissor rect
                GLint rect[4];
                glGetIntegerv(GL_SCISSOR_BOX, rect);
                scissorStack.push_back(Rect{ rect[0], rect[1], rect[2], rect[3] });

                glScissor(cmd.bounds.x, pge->ScreenHeight() - cmd.bounds.height - cmd.bounds.y, cmd.bounds.width, cmd.bounds.height);
            } break;
            case DrawCommandType::DisableClip: {
                if (scissorStack.empty()) continue;
                auto& rect = scissorStack.back();
                scissorStack.pop_back();
                glScissor(rect.x, rect.y, rect.width, rect.height);
			} break;
            default: break;
		}
	}
	m_drawCommands.clear();
}

void olcPGEX_TinyGUI::RenderDockingAreas() {
    for (const auto& [id, rect] : m_dockingAreas) {
        if (!IsDockingAreaFree(id)) continue;
        DrawStyle9Patch(
            GuiMapSprite::Selection,
            olc::Pixel(0, 0, 0, 110),
            rect
        );
	}
}

bool olcPGEX_TinyGUI::CurrentFrameIsCollapsed() {
    if (m_state.ignoreCollapsed) return false;
    if (m_frameStack.empty()) return false;
    return m_frames[m_frameStack.back()].collapsed;
}

Rect Rect::Expand(int amount) {
	Rect rec = *this;
	rec.x -= amount;
	rec.y -= amount;
	rec.width += amount * 2;
	rec.height += amount * 2;
	return rec;
}

bool Rect::Intersects(const Rect& other) const {
    return x < other.x + other.width &&
        x + width > other.x &&
        y < other.y + other.height &&
        y + height > other.y;
}

Rect Rect::Union(const Rect& other) const {
    int x1 = std::min(x, other.x);
	int y1 = std::min(y, other.y);
	int x2 = std::max(x + width, other.x + other.width);
	int y2 = std::max(y + height, other.y + other.height);
	return { x1, y1, x2 - x1, y2 - y1 };
}

Rect Rect::Intersection(const Rect& other) const {
    // if there is no intersection
    if (!Intersects(other)) return { 0, 0, 0, 0 };

    int x1 = std::max(x, other.x);
    int y1 = std::max(y, other.y);
    int x2 = std::min(x + width, other.x + other.width);
    int y2 = std::min(y + height, other.y + other.height);
    return { x1, y1, x2 - x1, y2 - y1 };
}

int Rect::DistanceToRect(const Rect& other) const {
    //if (Intersects(other)) return 0;

	int dx = 0, dy = 0;
	if (x + width < other.x) dx = other.x - (x + width);
	else if (x > other.x + other.width) dx = x - (other.x + other.width);

	if (y + height < other.y) dy = other.y - (y + height);
	else if (y > other.y + other.height) dy = y - (other.y + other.height);

	return std::max(dx, dy);
}

bool Rect::HasPoint(int x, int y) const {
	return x >= this->x && x < this->x + this->width && y >= this->y && y < this->y + this->height;
}

bool Rect::HasPoint(const olc::vi2d& pos) const {
	return HasPoint(pos.x, pos.y);
}

void olcPGEX_TinyGUI::UpdateDecals() {
	for (auto&& [id, decal] : m_images) {
		decal->Update();
	}
}

void olcPGEX_TinyGUI::Label(
    Rect bounds,
    const std::string& text,
    int alignment,
    const std::optional<olc::Pixel>& bg,
    bool wordWrap
) {
    if (CurrentFrameIsCollapsed()) return;

    if (bg.has_value()) {
        DrawFillRect(*bg, bounds);
    }

    const int defaultLineSpacing = 2;

    olc::Pixel col = GetBestForegroundColor(bg);

    std::vector<char> stringArray(text.begin(), text.end());
    std::vector<Word> words;

    while (!stringArray.empty()) {
        if (::isspace(stringArray[0]) && stringArray[0] != '\n' && stringArray[0] != '\t') {
			words.push_back({ " ", Word::TypeSpace });
			stringArray.erase(stringArray.begin());
        }
        else if (stringArray[0] == '\t') {
			words.push_back({ "\t", Word::TypeTab });
			stringArray.erase(stringArray.begin());
        }
        else if (stringArray[0] == '\n') {
			words.push_back({ "\n", Word::TypeNewLine });
			stringArray.erase(stringArray.begin());
        }
        else {
			std::string word;
            while (!stringArray.empty() && !::isspace(stringArray[0])) {
				word += stringArray[0];
				stringArray.erase(stringArray.begin());
			}
			words.push_back({ word, Word::TypeText });
		}
    }

    int totalHeight = 0;
    int lineHeightAvg = 0;
    std::vector<int> lineWidths;

    // compute total height and max width
    int tempWidth = 0, tempHeight = 0;
    for (const auto& word : words) {
        if (word.type == Word::TypeNewLine) {
            lineHeightAvg += tempHeight;
			totalHeight += tempHeight;
			tempHeight = 0;
            lineWidths.push_back(tempWidth);
			tempWidth = 0;
		}
        else {
			auto [tw, th] = TextSize(word.text);

            if (word.type == Word::TypeTab) {
                tw *= 4;
			}

            if (tempWidth + tw > bounds.width) {
                if (wordWrap) {
                    lineHeightAvg += tempHeight;
                    totalHeight += tempHeight;
                    tempHeight = 0;
                    lineWidths.push_back(tempWidth);
                    tempWidth = 0;
                }
            }
            tempWidth += tw;
			tempHeight = std::max(tempHeight, th + defaultLineSpacing);
		}
	}
    lineWidths.push_back(tempWidth);

    if (lineHeightAvg <= 0) {
        auto [tw, th] = TextSize(words[0].text);
        lineHeightAvg = th;
    }
    else {
        lineHeightAvg /= lineWidths.size();
    }

    int offY = 0;

    // alignment offset
    uint32_t alignX = alignment & 0x0F;
    uint32_t alignY = alignment & 0xF0;

    switch (alignY) {
        case AlignMiddle: offY = bounds.height / 2 - totalHeight / 2; break;
        case AlignBottom: offY = bounds.height - totalHeight; break;
        default: break;
    }

    int currentX = 0, currentY = 0;
    int lineIndex = 0;
    while (!words.empty()) {
        Word word = words[0];
        words.erase(words.begin());

        switch (word.type) {
            case Word::TypeText: {
                auto [tw, th] = TextSize(word.text);
                
                if (currentX + tw > bounds.width) {
                    if (wordWrap) {
                        currentX = 0;
                        currentY += lineHeightAvg;
                        lineIndex++;
                    }
                    else {
						break;
					}
                }

                int offX = 0;
                switch (alignX) {
                    case AlignCenter: offX = bounds.width / 2 - lineWidths[lineIndex] / 2; break;
                    case AlignRight: offX = bounds.width - lineWidths[lineIndex]; break;
                    default: break;
                }

                DrawText(
                    word.text,
                    col,
                    { bounds.x + currentX + offX, bounds.y + currentY + offY, bounds.width, bounds.height }
                );

                currentX += tw;
			} break;
            case Word::TypeSpace: {
                auto [tw, th] = TextSize(" ");
                currentX += tw;
			} break;
            case Word::TypeTab: {
                auto [tw, th] = TextSize(" ");
                currentX += tw * 2;
			} break;
            case Word::TypeNewLine: {
				currentX = 0;
				currentY += lineHeightAvg;
                lineIndex++;
			} break;
        }
    }
}

bool olcPGEX_TinyGUI::Button(const std::string& name, Rect bounds, const std::string& text, const std::optional<olc::Pixel>& color) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);
    DrawStyle9Patch(WidgetStateToSprite(wid.state), color.value_or(baseColor), bounds);

    auto [tw, th] = TextSize(text);

    olc::Pixel textColor = GetBestForegroundColor(color);
    if (wid.state == WidgetState::Active) {
        textColor = olc::WHITE;
	}

    if (color.has_value()) {
        Rect innerBounds = bounds.Expand(-3);
        DrawFillRect(color.value(), innerBounds);
	}

    DrawText(
        text,
		textColor,
		{ bounds.x + bounds.width / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height }
    );

    return wid.state == WidgetState::Clicked;
}

bool olcPGEX_TinyGUI::Toggle(const std::string& name, Rect bounds, const std::string& text, bool& value) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);
    DrawStyle9Patch(WidgetStateToSprite(!value ? wid.state : WidgetState::Active), baseColor, bounds);

    if (wid.state == WidgetState::Clicked) {
        value = !value;
    }

    auto [tw, th] = TextSize(text);

    olc::Pixel textColor = GetBestForegroundColor();
    if (wid.state == WidgetState::Active) {
        textColor = olc::WHITE;
    }

    DrawText(
        text,
        value ? olc::WHITE : textColor,
        Rect{ bounds.x + bounds.width / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height }
    );

    return wid.state == WidgetState::Clicked;
}

bool olcPGEX_TinyGUI::Slider(
    const std::string& name, Rect bounds,
    int& value, int min, int max, int step,
    const std::optional<olc::Pixel>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SliderImpl<int>(name, bounds, value, min, max, step, bg);
}

bool olcPGEX_TinyGUI::SliderF(
    const std::string& name,
    Rect bounds,
    float& value, float min, float max, float step,
    const std::optional<olc::Pixel>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SliderImpl<float>(name, bounds, value, min, max, step, bg);
}

bool olcPGEX_TinyGUI::Spinner(
    const std::string& name,
    Rect bounds,
    int& value, int min, int max, int step,
    const std::string& fmt,
    const std::optional<olc::Pixel>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SpinnerImpl<int>(
		name, bounds,
		[&](int& val, int inc) { val += inc; },
        value, min, max, step, fmt, bg
	);
}

bool olcPGEX_TinyGUI::SpinnerF(
    const std::string& name,
    Rect bounds,
    float& value, float min, float max, float step,
    const std::string& fmt,
    const std::optional<olc::Pixel>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SpinnerImpl<float>(
		name, bounds,
		[&](float& val, float inc) { val += inc; },
        value, min, max, step, fmt, bg
	);
}

bool olcPGEX_TinyGUI::EditBox(const std::string& name, Rect bounds, std::string& text) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);

    const auto light = olc::WHITE;
    bool textChanged = false;
    bool focused = m_state.focusedId == wid.id;

    DrawStyle9Patch(GuiMapSprite::ButtonActive, baseColor, bounds);

    if (focused && !pge->IsTextEntryEnabled()) {
        pge->TextEntryEnable(true, text);
    }

    // text entry
    if (focused) {
        textChanged = pge->TextEntryGetString() != text;
        text = pge->TextEntryGetString();
    }

    auto sz = pge->GetTextSizeProp(text.substr(0, pge->TextEntryGetCursor()));
    int cursorX = bounds.x + 4 + sz.x;
    int textViewOffsetX = 0;

    // cursor is out of bounds?
    if (cursorX - textViewOffsetX > (bounds.x + bounds.width - 4) - 8 && focused) {
		textViewOffsetX = cursorX - (bounds.x + bounds.width - 4) + 8;
	}

    auto [tw, th] = TextSize(text);

    int textX = bounds.x + 4 - textViewOffsetX;
    EnableClip(bounds.Expand(-1));
    DrawText(text, light, Rect{ textX, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height });
    DisableClip();

    // draw cursor
    if (focused && m_state.blink) {
        DrawText("_", light, { cursorX - textViewOffsetX, bounds.y + bounds.height / 2 - sz.y / 2, 1, 1 });
    }

    if (!focused && pge->IsTextEntryEnabled()) {
        pge->TextEntryEnable(false);
	}

    return textChanged;
}

void olcPGEX_TinyGUI::Image(const std::string& name, Rect bounds, olc::Sprite* sprite) {
    if (CurrentFrameIsCollapsed()) return;
    
    auto id = std::hash<std::string>()(name);
    DrawStyle9Patch(GuiMapSprite::ButtonActive, baseColor, bounds);
	
    if (!sprite) return;

    // find decal
    auto&& pos = m_images.find(id);
    if (pos == m_images.end()) {
		m_images[id] = std::make_unique<olc::Decal>(sprite, false, true);
		pos = m_images.find(id);
	}

	// calculate image rect maintain aspect ratio 
    float aspect = 1.0f;
    if (sprite->width > sprite->height) {
        aspect = float(sprite->height) / sprite->width;
	}
	else {
		aspect = float(sprite->width) / sprite->height;
	}

    int width = bounds.width - 4;
	int height = int(width * aspect);

	if (height > bounds.height - 4) {
		height = bounds.height - 4;
		width = int(height / aspect);
	}

	int x = bounds.x + bounds.width / 2 - width / 2;
	int y = bounds.y + bounds.height / 2 - height / 2;

    DrawCommand cmd{};
    cmd.type = DrawCommandType::Image;
    cmd.bounds = Rect{ x, y, width, height };
    cmd.color = olc::WHITE;
    cmd.image = pos->second.get();
    m_drawCommands.push_back(cmd);
}

void olcPGEX_TinyGUI::TabBar(const std::string& name, Rect bounds, std::string* tabs, size_t numTabs, size_t& selected) {
    if (CurrentFrameIsCollapsed()) return;
    
    const int nextButtonWidth = 16;

    auto fg = GetBestForegroundColor();

    auto id = std::hash<std::string>()(name);
    auto pos = m_tabBars.find(id);
    if (pos == m_tabBars.end()) {
		m_tabBars[id] = TabBarState();
		pos = m_tabBars.find(id);
	}

    auto& tabBar = pos->second;

    std::vector<Rect> tabBounds;

    uint32_t startTab = tabBar.startIndex;
    uint32_t numVisibleTabs = 0;

    auto fnDrawTab = [&](Rect tabRect, size_t index, int offsetY) {
        auto [tw, th] = TextSize(tabs[index]);

        auto wid = GetWidget(name + "_tab" + std::to_string(index), tabRect);
        if (wid.state == WidgetState::Clicked) {
            selected = index;
        }

        tabRect.y += offsetY;
        tabRect.height -= offsetY;

        DrawStyle9Patch(
            GuiMapSprite::ButtonIdle,
            baseColor,
            tabRect,
            0b00011111
        );

        DrawText(
            tabs[index],
            fg,
            {
                tabRect.x + tabRect.width / 2 - tw / 2,
                tabRect.y + tabRect.height / 2 - th / 2,
                tabRect.width, tabRect.height
            }
        );
    };

    Rect selectedTabRect{};
    int offX = 3;
    for (size_t i = tabBar.startIndex; i < numTabs; i++) {
        auto [tw, th] = TextSize(tabs[i]);
        Rect tabRect{
			bounds.x + offX,
			bounds.y,
			tw + 10,
			bounds.height + 3
		};

        if (offX + tabRect.width > bounds.width - nextButtonWidth * 2)
			break;

        offX += tabRect.width - 3;

        // draw except selected
        if (i == selected) {
            selectedTabRect = tabRect;
        } else fnDrawTab(tabRect, i, 4);

        numVisibleTabs++;
	}

    // draw selected tab
    if (selected >= tabBar.startIndex && selected < tabBar.startIndex + numVisibleTabs)
        fnDrawTab(selectedTabRect, selected, 0);

    if (numVisibleTabs < numTabs) {
		// draw next button
		Rect nextButton{
			bounds.x + bounds.width - nextButtonWidth,
			bounds.y + 4,
			nextButtonWidth,
			bounds.height - 4
		};

		if (Button(name + "_next", nextButton, "")) {
			tabBar.startIndex++;
			tabBar.startIndex = std::clamp(tabBar.startIndex, uint32_t(0), uint32_t(numTabs) - numVisibleTabs);
		}
        DrawStyleSprite(
            GuiMapSprite::ArrowRight,
            GetBestForegroundColor(),
            Rect{ nextButton.x + nextButton.width / 2 - 4, nextButton.y + nextButton.height / 2 - 4 + 1, 8, 8 }
        );

		// draw prev button
		Rect prevButton{
			bounds.x + bounds.width - nextButtonWidth * 2,
			bounds.y + 4,
			nextButtonWidth,
			bounds.height - 4
		};

		if (Button(name + "_prev", prevButton, "")) {
			tabBar.startIndex--;
			tabBar.startIndex = std::clamp(tabBar.startIndex, uint32_t(0), uint32_t(numTabs) - numVisibleTabs);
		}
        DrawStyleSprite(
			GuiMapSprite::ArrowLeft,
			GetBestForegroundColor(),
			Rect{ prevButton.x + prevButton.width / 2 - 4, prevButton.y + prevButton.height / 2 - 4 + 1, 8, 8 }
		);
	}

    DrawLine(olc::BLACK, { bounds.x, bounds.y + bounds.height }, { bounds.x + bounds.width, bounds.y + bounds.height });
}

bool olcPGEX_TinyGUI::MakePopup(
    const std::string& name,
    std::string* items, size_t numItems, size_t* selected
) {
    auto id = std::hash<std::string>()(name);
    auto&& pos = m_popups.find(id);
    if (pos == m_popups.end()) {
        m_popups[id] = Popup();
        pos = m_popups.find(id);
    }

    auto& popup = pos->second;
    popup.name = name;
    popup.items = std::vector<std::string>(items, items + numItems);

    int width = 0, height = 0;
    for (size_t i = 0; i < numItems; i++) {
        auto item = items[i];

        width = std::max(width, TextSize(item).first);

        if (item.find_first_not_of('-') == std::string::npos) {
            height += PopupItemHeight / 2;
        }
        else {
            height += PopupItemHeight;
        }
    }

    Rect bounds{ popup.position.x, popup.position.y, width + 6, height + 4 };

    popup.size = bounds.Size();

    if (m_state.openPopup != id) return false;

    if (m_state.mouseDown && !bounds.HasPoint(m_state.mousePos)) {
        m_state.openPopup = 0;
        return false;
    }

    int y = bounds.y + 2;
    for (size_t i = 0; i < numItems; i++) {
        auto item = items[i];

        if (item.find_first_not_of('-') == std::string::npos) {
            y += PopupItemHeight / 2;
            continue;
        }

        Rect itemBounds{ bounds.x, y, bounds.width, PopupItemHeight };
        auto wd = GetWidget(item + name, itemBounds, false);

        if (wd.state == WidgetState::Clicked) {
            m_state.openPopup = 0;
            popup.lastSelected = i;
            if (selected) *selected = i;
            return true;
        }

        y += PopupItemHeight;
    }

    return false;
}

void olcPGEX_TinyGUI::ShowPopup(const std::string& name, olc::vi2d position) {
	auto id = std::hash<std::string>()(name);
	auto&& pos = m_popups.find(id);
	if (pos == m_popups.end()) {
        return;
	}

	auto& popup = pos->second;
	popup.position = position;

    if (popup.position.x + popup.size.x > pge->ScreenWidth()) {
		popup.position.x = pge->ScreenWidth() - popup.size.x;
	}

    if (popup.position.y + popup.size.y > pge->ScreenHeight()) {
		popup.position.y = pge->ScreenHeight() - popup.size.y;
	}

    m_state.openPopup = id;
}

void olcPGEX_TinyGUI::ShowPopup(const std::string& name) {
    ShowPopup(name, m_state.lastClickedWidgetPosition);
}

void olcPGEX_TinyGUI::OnBeforeUserCreate() {
    m_rectStack.push_back(Rect{ 0, 0, pge->ScreenWidth(), pge->ScreenHeight() });

    m_panelsLayer = pge->CreateLayer();
    pge->EnableLayer(m_panelsLayer, true);

    m_widgetsLayer = pge->CreateLayer();
    pge->EnableLayer(m_widgetsLayer, true);

    SetTargetLayer(m_widgetsLayer);

    // create gui sprite
    m_guiSprite = std::make_unique<olc::Sprite>(GuiMapWidth, GuiMapHeight);
    m_guiDecal = std::make_unique<olc::Decal>(m_guiSprite.get());

    uint16_t index = 0;
    for (size_t y = 0; y < GuiMapHeight; y++) {
        for (size_t x = 0; x < GuiMapWidth; x++) {
            uint8_t msb = GuiMap[index++];
            uint8_t lsb = GuiMap[index++];
			uint16_t rgb565 = (lsb << 8) | msb;

            // convert to RGB888
            uint8_t r = ((rgb565 & 0b1111100000000000) >> 11);
            uint8_t g = ((rgb565 & 0b0000011111100000) >> 5);
            uint8_t b = ( rgb565 & 0b0000000000011111);
            r = (r * 255) / 31;
            g = (g * 255) / 63;
            b = (b * 255) / 31;

            uint8_t a = GuiMap[GuiMapAlphaChannelStart + (y * GuiMapWidth + x)];

            m_guiSprite->SetPixel(x, y, olc::Pixel(r, g, b, a));
		}
	}
    m_guiDecal->Update();
}

bool olcPGEX_TinyGUI::OnBeforeUserUpdate(float& fElapsedTime) {
    m_state.mouseDown = pge->GetMouse(0).bHeld;
    m_state.mouseDelta = pge->GetMousePos() - m_state.mousePos;
	m_state.mousePos = pge->GetMousePos();

    if (m_rectStack.empty())
        m_rectStack.push_back(Rect{ 0, 0, pge->ScreenWidth(), pge->ScreenHeight() });

    if (!m_state.mouseDown) m_state.hoveredId = 0;

    for (auto&& [wid, widget] : m_widgets) {
        widget.pressed = false;
        widget.released = false;
	}

    pge->SetPixelMode(olc::Pixel::ALPHA);

    pge->SetDrawTarget(nullptr);
    pge->Clear(olc::BLANK);

    pge->SetDrawTarget(m_panelsLayer);
    pge->Clear(olc::BLANK);

    pge->SetDrawTarget(m_widgetsLayer);
    pge->Clear(olc::BLANK);

    SetTargetLayer(m_widgetsLayer);

    RenderDockingAreas();

	return false;
}

void olcPGEX_TinyGUI::OnAfterUserUpdate(float fElapsedTime) {
    // check frame clicks
    std::vector<size_t> frames;
    for (auto&& [id, frame] : m_frames) {
		frames.push_back(id);
	}

    // sort by fid == frontMostPanelId, placing it at the top
    std::sort(frames.begin(), frames.end(), [&](size_t a, size_t b) {
		return a == m_state.frontMostPanelId;
	});

    if (!frames.empty()) {
        for (auto fid : frames) {
			auto& frame = m_frames[fid];
            if (
                m_state.mouseDown &&
                frame.titleBounds.HasPoint(m_state.mousePos) &&
                !frame.dragging &&
                m_state.activeId == 0
            ) {
                m_state.activeId = fid;
                m_state.frontMostPanelId = fid;
                frame.dragging = true;
                frame.dockId = 0;
                m_state.clickedFrame = &frame;
                break;
            }
		}

        if (m_state.clickedFrame && !m_state.mouseDown) {
            m_state.activeId = 0;

            // docking logic
            auto dockId = NearestDockingArea(m_state.clickedFrame->bounds);
            if (dockId != size_t(-1) && IsDockingAreaFree(dockId)) {
                Rect dockRect = m_dockingAreas[dockId];
                m_state.clickedFrame->positionOffset.x = dockRect.x;
                m_state.clickedFrame->positionOffset.y = dockRect.y;
                m_state.clickedFrame->bounds.width = dockRect.width;
                m_state.clickedFrame->bounds.height = dockRect.height;
				m_state.clickedFrame->dockId = dockId;
            }

            m_state.clickedFrame->dragging = false;
            m_state.clickedFrame = nullptr;
		}
    }

    // docking highlight
    if (m_state.clickedFrame) {
        auto dockId = NearestDockingArea(m_state.clickedFrame->bounds);
        if (dockId != size_t(-1) && IsDockingAreaFree(dockId)) {
            DrawStyle9Patch(
                GuiMapSprite::Selection,
                olc::Pixel(18, 101, 255, 160),
                m_dockingAreas[dockId]
            );
        }
    }

    //////

    RenderAll();
    DrawPopups();

    if (!m_state.mouseDown) {
        m_state.activeId = 0;
    }

    m_rectStack.clear();

    m_state.blinkTimer += fElapsedTime;
    if (m_state.blinkTimer >= 0.4f) {
        m_state.blink = !m_state.blink;
        m_state.blinkTimer = 0.0f;
	}
}

void olcPGEX_TinyGUI::BeginFrame(
    const std::string& name,
    const std::string& title,
    const olc::vi2d& position,
    int width,
    bool collapsible, bool fixed
) {
    if (!m_frameStack.empty()) return; // Not possible to create frames inside frames

    const int padding = 5;

    auto fid = std::hash<std::string>()(name);
    auto pos = m_frames.find(fid);
    if (pos == m_frames.end()) {
		m_frames[fid] = Frame{};
		pos = m_frames.find(fid);
        pos->second.positionOffset = position;
	}

    Frame& fram = pos->second;
    fram.name = name;
    fram.title = title;
    fram.insertId = m_drawCommands.size();
    fram.collapsible = collapsible;
    fram.fixed = fixed;

    auto [tw, th] = TextSize(title);

    fram.bounds = Rect{ fram.positionOffset.x, fram.positionOffset.y, width, padding + FrameTitleHeight };
    if (fram.dockId != 0) {
        Rect dockRect = m_dockingAreas[fram.dockId];
        fram.bounds.width = dockRect.width;
        fram.bounds.height = dockRect.height;
    }

    fram.titleBounds = Rect{ fram.bounds.x + 2, fram.bounds.y + 2, fram.bounds.width - 4, FrameTitleHeight };

    // adjust title bounds to exclude the collapse button
    if (fram.collapsible && fram.dockId == 0) {
        fram.titleBounds.width -= FrameTitleHeight;
    }

    m_frameStack.push_back(fid);

    Rect widgetsRect = fram.bounds.Expand(-padding);
    widgetsRect.y += fram.titleBounds.height;
    widgetsRect.height -= fram.titleBounds.height;
    PushRect(widgetsRect);

    if (m_state.frontMostPanelId == fid) SetTargetLayer(m_panelsLayer);
    else SetTargetLayer(m_widgetsLayer);
}

Rect olcPGEX_TinyGUI::EndFrame() {
    const int padding = 5;

    if (m_frameStack.empty()) return Rect{}; // Why are you calling this?

    auto titleBgColor = PixelBrightness(baseColor, 0.3f);
    auto light = GetBestForegroundColor(titleBgColor);
    auto fid = m_frameStack.back();

    Frame& frame = m_frames[fid];

    Rect frameBounds = frame.bounds;
    Rect titleBounds = frame.titleBounds;

    bool docked = frame.dockId != 0;
    if (!docked) {
        frameBounds.height += PeekRect().y - frameBounds.y;
        frameBounds.height -= FrameTitleHeight;
    }

    if (frame.collapsed && !docked) {
        frameBounds.height = FrameTitleHeight + padding;
    }

    auto [tw, th] = TextSize(frame.title);
    DrawText(
        frame.title, light,
        Rect{ frameBounds.x + 6, frameBounds.y + 2 + (FrameTitleHeight / 2 - th / 2), frameBounds.width - 4, FrameTitleHeight },
        frame.insertId
    );

    DrawFillRect(
        titleBgColor,
        titleBounds,
        frame.insertId
    );

    DrawStyle9Patch(
        GuiMapSprite::Frame,
        baseColor,
        frameBounds,
        0xFF,
        frame.insertId
    );

    DrawStyle9Patch(
        GuiMapSprite::Shadow,
        baseColor,
        Rect{ frameBounds.x + 3, frameBounds.y + 3, frameBounds.width, frameBounds.height },
        0xFF,
        frame.insertId
    );

    if (frame.collapsible && !docked) {
        m_state.ignoreCollapsed = true;
        Rect collapseButtonBounds = Rect{
            frameBounds.x + frameBounds.width - FrameTitleHeight - 1,
            frameBounds.y + 2,
            FrameTitleHeight, FrameTitleHeight
        };
        int centerOff = FrameTitleHeight / 2 - 4;

        if (Button(frame.name + "_collapse", collapseButtonBounds, "")) {
            frame.collapsed = !frame.collapsed;
        }
        DrawStyleSprite(
            frame.collapsed ? GuiMapSprite::ArrowDown : GuiMapSprite::ArrowUp,
            GetBestForegroundColor(),
            Rect{ collapseButtonBounds.x + centerOff - 1, collapseButtonBounds.y + centerOff + 1, 8, 8 }
        );
        m_state.ignoreCollapsed = false;
    }

    PopRect();
    m_frameStack.pop_back();

    frame.bounds = frameBounds;
    
    // moving logic
    if (frame.dragging && !frame.fixed) {
        frame.positionOffset.x += m_state.mouseDelta.x;
        frame.positionOffset.y += m_state.mouseDelta.y;
    }

    SetTargetLayer(m_widgetsLayer);

    return frameBounds;
}

void olcPGEX_TinyGUI::PushRect(Rect rect) {
    if (CurrentFrameIsCollapsed()) return;
	m_rectStack.push_back(rect);
}

Rect& olcPGEX_TinyGUI::PeekRect() {
	return m_rectStack.back();
}

void olcPGEX_TinyGUI::PopRect() {
    if (CurrentFrameIsCollapsed()) return;
	m_rectStack.pop_back();
}

Rect olcPGEX_TinyGUI::RectCutLeft(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
    Rect& orig = PeekRect();
    Rect rec{ orig.x, orig.y, amount, orig.height };
    orig.x += amount;
    orig.width -= amount;
    return rec;
}

Rect olcPGEX_TinyGUI::RectCutRight(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x + orig.width - amount, orig.y, amount, orig.height };
	orig.width -= amount;
	return rec;
}

Rect olcPGEX_TinyGUI::RectCutTop(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x, orig.y, orig.width, amount };
	orig.y += amount;
	orig.height -= amount;
	return rec;
}

Rect olcPGEX_TinyGUI::RectCutBottom(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x, orig.y + orig.height - amount, orig.width, amount };
	orig.height -= amount;
	return rec;
}

void olcPGEX_TinyGUI::AddDockingArea(const std::string& name, const Rect& rect) {
    m_dockingAreas[utils::GetIDFromName(name)] = rect;
}

void olcPGEX_TinyGUI::AddDockingAreaLeft(const std::string& name, int size) {
    PushRect(RectCutLeft(size));
    AddDockingArea(name, PeekRect());
    PopRect();
}

void olcPGEX_TinyGUI::AddDockingAreaRight(const std::string& name, int size) {
    PushRect(RectCutRight(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void olcPGEX_TinyGUI::AddDockingAreaTop(const std::string& name, int size) {
    PushRect(RectCutTop(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void olcPGEX_TinyGUI::AddDockingAreaBottom(const std::string& name, int size) {
    PushRect(RectCutBottom(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void olcPGEX_TinyGUI::AddDockingAreaRemainingSpace(const std::string& name) {
    AddDockingArea(name, PeekRect());
}

olcPGEX_TinyGUI::Widget& olcPGEX_TinyGUI::GetWidget(const std::string& name, Rect bounds, bool blockInputByPopup) {
    auto id = std::hash<std::string>()(name);

    auto pos = m_widgets.find(id);
    if (pos == m_widgets.end()) {
        m_widgets[id] = Widget{};
        pos = m_widgets.find(id);
    }
    auto& widget = pos->second;
    widget.id = id;
    widget.state = WidgetState::Idle;
    widget.visible = true;
    size_t parentFrameId = 0;

    // is this widget inside of a collapsed frame?
    if (!m_frameStack.empty()) {
        auto& frame = m_frames[m_frameStack.back()];
        parentFrameId = m_frameStack.back();
        widget.visible = !frame.collapsed;
    }
    //

    // we should receive no input if there's a frame on top of the area where we're trying to click
    // so if there's a frame intersecting the widget bounds, and we try to click in both bounds, we should block the input

    Frame* blockingFrame = nullptr;
    for (auto&& [fid, frame] : m_frames) {
        Rect totalBounds = frame.titleBounds.Union(frame.bounds);
		if (totalBounds.Intersects(bounds) && m_state.frontMostPanelId == fid && m_state.frontMostPanelId != parentFrameId) {
            //DrawStyle9Patch(GuiMapSprite::Selection, olc::RED, bounds.Expand(2));
            //DrawStyle9Patch(GuiMapSprite::Selection, olc::GREEN, totalBounds.Expand(2));
			blockingFrame = &frame;
			break;
		}
	}

    bool blockingFrameHasPoint =
        blockingFrame &&
        (blockingFrame->bounds.HasPoint(m_state.mousePos) || blockingFrame->titleBounds.HasPoint(m_state.mousePos));

    bool blocked = blockInputByPopup && m_state.openPopup != 0;
    if (bounds.HasPoint(m_state.mousePos) && !blockingFrameHasPoint && !blocked) {
        m_state.hoveredId = id;
        widget.state = WidgetState::Hovered;
        if (m_state.activeId == 0 && m_state.mouseDown) {
            m_state.activeId = id;
            m_state.focusedId = id;
            m_state.lastClickedWidgetPosition.x = bounds.x;
            m_state.lastClickedWidgetPosition.y = bounds.y + bounds.height;
            widget.state = WidgetState::Active;
            widget.pressed = true;
        }
    }
    else {
        if (m_state.focusedId == id && m_state.mouseDown) {
            m_state.focusedId = 0;
        }
    }

    if (m_state.activeId == id && m_state.hoveredId == id && !blocked) {
        widget.state = WidgetState::Active;
        if (!m_state.mouseDown) {
            widget.released = true;
            widget.state = WidgetState::Clicked;
        }
    }

    return widget;
}

void olcPGEX_TinyGUI::DrawText(const std::string& text, olc::Pixel color, Rect bounds, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::Text;
	cmd.text = text;
	cmd.color = color;
	cmd.bounds = bounds;
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::DrawFillRect(olc::Pixel color, Rect bounds, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::FillRect;
	cmd.color = color;
	cmd.bounds = bounds;
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::DrawLine(olc::Pixel color, olc::vi2d a, olc::vi2d b, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::Line;
	cmd.color = color;
	cmd.bounds = Rect{ a.x, a.y, b.x, b.y };
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::DrawStyleSprite(GuiMapSprite sprite, olc::Pixel color, Rect bounds, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::StyleSprite;
	cmd.sprite = sprite;
	cmd.color = color;
	cmd.bounds = bounds;
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::DrawStyle9Patch(GuiMapSprite sprite, olc::Pixel color, Rect bounds, uint8_t flags, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::Style9Patch;
	cmd.sprite = sprite;
	cmd.color = color;
	cmd.bounds = bounds;
    cmd.ninePatchFlags = flags;
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::DrawImage(olc::Decal* image, Rect bounds, size_t position) {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::Image;
	cmd.image = image;
	cmd.bounds = bounds;
    AddDrawCommand(cmd, position);
}

void olcPGEX_TinyGUI::EnableClip(Rect bounds) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::EnableClip;
    cmd.bounds = bounds;
    AddDrawCommand(cmd);
}

void olcPGEX_TinyGUI::DisableClip() {
    DrawCommand cmd{};
	cmd.type = DrawCommandType::DisableClip;
	AddDrawCommand(cmd);
}

olcPGEX_TinyGUI::Widget& olcPGEX_TinyGUI::GetWidgetByName(const std::string& name) {
    auto id = std::hash<std::string>()(name);
    auto pos = m_widgets.find(id);
    if (pos == m_widgets.end()) {
        m_widgets[id] = Widget{};
        pos = m_widgets.find(id);
    }
    return pos->second;
}

std::pair<int, int> olcPGEX_TinyGUI::TextSize(const std::string& text) {
    olc::vi2d sz = pge->GetTextSizeProp(text);
    return { sz.x, sz.y };
}

olc::Pixel olcPGEX_TinyGUI::PixelBrightness(olc::Pixel color, float amount) {
    auto fnPerc = [amount](float value) {
        return std::clamp(value * amount, 0.0f, 1.0f);
    };

    const float r = float(color.r) / 255.0f;
    const float g = float(color.g) / 255.0f;
    const float b = float(color.b) / 255.0f;
    const float a = float(color.a) / 255.0f;
    return olc::PixelF(fnPerc(r), fnPerc(g), fnPerc(b), a);
}

void olcPGEX_TinyGUI::DrawStyle9Patch(Rect bounds, olc::Pixel color, GuiMapSprite sprite, uint8_t flags) {
    const int spriteWidth = 8;
    const int spriteHeight = 8;
    const int padding = 3;
    const int numCols = m_guiDecal->sprite->width / spriteWidth;

    int spriteIndex = int(sprite);
    Rect src{
        (spriteIndex % numCols) * spriteWidth,
		(spriteIndex / numCols) * spriteHeight,
        spriteWidth, spriteHeight
    };

    auto fnDraw = [this, color](Rect dst, Rect src) {
        olc::vf2d pos = { float(dst.x), float(dst.y) };
        olc::vf2d size = { float(dst.width), float(dst.height) };
        olc::vf2d srcPos = { float(src.x), float(src.y) };
        olc::vf2d srcSize = { float(src.width), float(src.height) };
        pge->DrawPartialDecal(pos, size, m_guiDecal.get(), srcPos, srcSize, color);
    };

#define IsBitSet(x, b) ((x & (1 << b)) != 0)

    // top left
    if (IsBitSet(flags, 0)) {
        fnDraw(Rect{ bounds.x, bounds.y, padding, padding }, Rect{ src.x, src.y, padding, padding });
    }

    // top center
    if (IsBitSet(flags, 1)) {
        fnDraw(
            Rect{ bounds.x + padding, bounds.y, bounds.width - padding * 2, padding },
            Rect{ src.x + padding, src.y, src.width - padding * 2, padding }
        );
    }

    // top right
    if (IsBitSet(flags, 2)) {
        fnDraw(
            Rect{ bounds.x + bounds.width - padding, bounds.y, padding, padding },
            Rect{ src.x + src.width - padding, src.y, padding, padding }
        );
    }

    // center left
    if (IsBitSet(flags, 3)) {
        fnDraw(
            Rect{ bounds.x, bounds.y + padding, padding, bounds.height - padding * 2 },
            Rect{ src.x, src.y + padding, padding, src.height - padding * 2 }
        );
    }

    // center center
    fnDraw(
        Rect{ bounds.x + padding, bounds.y + padding, bounds.width - padding * 2, bounds.height - padding * 2 },
        Rect{ src.x + padding, src.y + padding, src.width - padding * 2, src.height - padding * 2 }
    );

    // center right
    if (IsBitSet(flags, 4)) {
        fnDraw(
            Rect{ bounds.x + bounds.width - padding, bounds.y + padding, padding, bounds.height - padding * 2 },
            Rect{ src.x + src.width - padding, src.y + padding, padding, src.height - padding * 2 }
        );
    }

    // bottom left
    if (IsBitSet(flags, 5)) {
        fnDraw(
            Rect{ bounds.x, bounds.y + bounds.height - padding, padding, padding },
            Rect{ src.x, src.y + src.height - padding, padding, padding }
        );
    }

    // bottom center
    if (IsBitSet(flags, 6)) {
        fnDraw(
            Rect{ bounds.x + padding, bounds.y + bounds.height - padding, bounds.width - padding * 2, padding },
            Rect{ src.x + padding, src.y + src.height - padding, src.width - padding * 2, padding }
        );
    }

    // bottom right
    if (IsBitSet(flags, 7)) {
        fnDraw(
            Rect{ bounds.x + bounds.width - padding, bounds.y + bounds.height - padding, padding, padding },
            Rect{ src.x + src.width - padding, src.y + src.height - padding, padding, padding }
        );
    }

#undef IsBitSet
}

void olcPGEX_TinyGUI::DrawStyleSprite(Rect bounds, olc::Pixel color, GuiMapSprite sprite) {
    const int spriteWidth = 8;
	const int spriteHeight = 8;
    const int numCols = m_guiDecal->sprite->width / spriteWidth;

    int spriteIndex = int(sprite);
    Rect src{
        (spriteIndex % numCols) * spriteWidth,
        (spriteIndex / numCols) * spriteHeight,
        spriteWidth, spriteHeight
    };

    auto fnDraw = [this, color](Rect dst, Rect src) {
        olc::vf2d pos = { float(dst.x), float(dst.y) };
        olc::vf2d size = { float(dst.width), float(dst.height) };
        olc::vf2d srcPos = { float(src.x), float(src.y) };
        olc::vf2d srcSize = { float(src.width), float(src.height) };
        pge->DrawPartialDecal(pos, size, m_guiDecal.get(), srcPos, srcSize, color);
    };

    fnDraw(bounds, src);
}

GuiMapSprite olcPGEX_TinyGUI::WidgetStateToSprite(WidgetState state) {
    switch (state) {
		case WidgetState::Hovered: return GuiMapSprite::ButtonHovered;
		case WidgetState::Active:
		case WidgetState::Clicked: return GuiMapSprite::ButtonActive;
		default: return GuiMapSprite::ButtonIdle;
	}
}

olc::Pixel olcPGEX_TinyGUI::GetBestForegroundColor(const std::optional<olc::Pixel>& bgColor) {
    olc::Pixel bg = bgColor.value_or(baseColor);
    return utils::Luma(bg) > 0.5f ? olc::BLACK : olc::WHITE;
}

size_t olcPGEX_TinyGUI::NearestDockingArea(const Rect& bounds) {
    const int distanceTolerancePx = 1;

    int distance = INT_MAX;
    size_t dockId = size_t(-1);
    for (auto [id, area] : m_dockingAreas) {
        int dist = area.DistanceToRect(bounds);
        if (dist < distance && dist < distanceTolerancePx) {
			distance = dist;
            dockId = id;
        }
    }

    return dockId;
}

bool olcPGEX_TinyGUI::IsDockingAreaFree(size_t id) {
    for (auto&& [fid, frame] : m_frames) {
        if (frame.dockId == id) return false;
    }
    return true;
}

void olcPGEX_TinyGUI::AddDrawCommand(DrawCommand cmd, size_t position) {
    cmd.targetLayer = m_state.targetLayer;
    if (position < size_t(-1)) {
		m_drawCommands.insert(m_drawCommands.begin() + position, cmd);
	}
    else {
		m_drawCommands.push_back(cmd);
	}
}

void olcPGEX_TinyGUI::SetTargetLayer(uint32_t layer) {
    m_state.targetLayer = layer;
}

void olcPGEX_TinyGUI::DrawPopups() {
    const int paddingX = 8;
    const int paddingY = 5;

    pge->SetDrawTarget(nullptr);

    for (auto&& [wid, popup] : m_popups) {
        if (m_state.openPopup != wid) continue;

        int width = 0, height = 0;
        for (size_t i = 0; i < popup.items.size(); i++) {
            auto item = popup.items[i];
            auto [tw, th] = TextSize(item);

            width = std::max(width, tw);

            if (item.find_first_not_of('-') == std::string::npos) {
                height += PopupItemHeight / 2;
            }
            else {
                height += PopupItemHeight;
            }
        }

        Rect bounds{ popup.position.x, popup.position.y, width + paddingX * 2, height + paddingY * 2 };

        DrawStyle9Patch(
            Rect{ bounds.x + 3, bounds.y + 3, bounds.width, bounds.height },
            olc::WHITE,
            GuiMapSprite::Shadow,
            0xFF
        );
        DrawStyle9Patch(
            bounds,
            olc::WHITE,
            GuiMapSprite::Panel,
            0xFF
        );

        const auto light = PixelBrightness(baseColor, 2.5f);
        const auto dark = PixelBrightness(baseColor, 0.15f);

        int y = bounds.y + paddingY;
        for (size_t i = 0; i < popup.items.size(); i++) {
            auto item = popup.items[i];

            if (item.find_first_not_of('-') == std::string::npos) {
                pge->DrawLineDecal(
                    olc::vf2d{ float(bounds.x + 3), float(y + PopupItemHeight / 4) },
                    olc::vf2d{ float(bounds.x + bounds.width - 3), float(y + PopupItemHeight / 4) },
                    PixelBrightness(baseColor, 0.5f)
                );
                y += PopupItemHeight / 2;
                continue;
            }

            Rect wdBounds{ bounds.x, y, bounds.width, PopupItemHeight };
            auto wd = GetWidgetByName(item + popup.name);
            
            olc::Pixel fgColor = dark;
            switch (wd.state) {
                case WidgetState::Hovered:
                case WidgetState::Active:
                case WidgetState::Clicked:
                    fgColor = light;
                    pge->FillRectDecal(
                        olc::vi2d{ wdBounds.x, wdBounds.y },
                        olc::vi2d{ wdBounds.width, wdBounds.height },
                        dark
                    );
                    break;
                default: break;
            }

            auto [tw, th] = TextSize(item);
            pge->DrawStringPropDecal(
				{ float(bounds.x + paddingX), float(y + PopupItemHeight / 2 - th / 2) },
				item,
				fgColor
			);

            y += PopupItemHeight;
        }
    }
}

float utils::Luma(const olc::Pixel& color) {
    float r = float(color.r) / 255.0f;
    float g = float(color.g) / 255.0f;
    float b = float(color.b) / 255.0f;
    return r * 0.299f + g * 0.587f + b * 0.114f;
}

std::vector<std::string> utils::Split(const std::string& str, const std::string& delimiter) {
    return Split(str, { delimiter });
}

std::vector<std::string> utils::Split(const std::string& str, const std::initializer_list<std::string>& delimiters) {
    std::string original = str;
	std::vector<std::string> tokens;
    for (const auto& delimiter : delimiters) {
		size_t pos = 0;
		std::string token;
        while ((pos = original.find(delimiter)) != std::string::npos) {
			token = original.substr(0, pos);
			tokens.push_back(token);
			original.erase(0, pos + delimiter.length());
		}
	}
	tokens.push_back(original);
	return tokens;
}

size_t utils::GetIDFromName(const std::string& name) {
    return std::hash<std::string>()(name);
}

#endif
