#pragma once

#ifndef TINYGUI_PGEX // Use OpenGL backend
// disable min/max macros
#define NOMINMAX
#include "glbind.h"
#include "stb_image.h"
#include "stb_truetype.h"
#include <iostream>
#include <fstream>
#else // Use PixelGameEngine backend
#include "olcPixelGameEngine.h"
#endif

#include <optional>
#include <functional>
#include <algorithm>
#include <vector>
#include <array>
#include <tuple>
#include <string>
#include <initializer_list>
#include <map>

#ifdef DrawText
#undef DrawText
#endif

#ifdef None
#undef None
#endif

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

struct Color {
    uint8_t r, g, b, a;

#ifdef TINYGUI_PGEX
    olc::Pixel AsOLC() const { return olc::Pixel(r, g, b, a); }
#endif

    std::tuple<float, float, float, float> AsFloat() const {
		return {
			static_cast<float>(r) / 255.0f,
			static_cast<float>(g) / 255.0f,
			static_cast<float>(b) / 255.0f,
			static_cast<float>(a) / 255.0f
		};
	}

    static Color FromFloat(float r, float g, float b, float a = 1.0f) {
		return {
            static_cast<uint8_t>(r * 255),
            static_cast<uint8_t>(g * 255),
            static_cast<uint8_t>(b * 255),
            static_cast<uint8_t>(a * 255)
        };
	}
};

template <typename T>
concept IsNumber = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <typename T> requires IsNumber<T>
struct Vector2 {
    T x, y;

    std::pair<T, T> AsPair() const { return { x, y }; }

    Vector2 operator+(const Vector2& other) const { return { x + other.x, y + other.y }; }
    Vector2 operator-(const Vector2& other) const { return { x - other.x, y - other.y }; }

#ifdef TINYGUI_PGEX
    olc::v2d_generic<T> AsOLC() const { return { x, y }; }
#endif
};

using Vector2i = Vector2<int32_t>;
using Vector2ui = Vector2<uint32_t>;
using Vector2f = Vector2<float>;

struct Rect {
    int x, y, width, height;

    bool HasPoint(int x, int y) const;
    bool HasPoint(const Vector2i& pos) const;
    Rect Expand(int amount = 1);

    bool Intersects(const Rect& other) const;
    Rect Union(const Rect& other) const;
    Rect Intersection(const Rect& other) const;

    int DistanceToRect(const Rect& other) const;

    Vector2i Center() const { return { x + width / 2, y + height / 2 }; }
    Vector2i Position() const { return { x, y }; }
    Vector2i Size() const { return { width, height }; }
};

class Texture {
public:
    void Load(const std::string& filename);
    void LoadFromMemory(uint8_t* data, uint32_t width, uint32_t height, uint32_t channels);

    Vector2ui Size() const { return { m_width, m_height }; }

#ifdef TINYGUI_PGEX
    olc::Sprite* GetSprite() { return m_sprite.get(); }
	olc::Decal* GetDecal() { return m_decal.get(); }
#else
	GLuint GetID() const { return m_id; }
#endif

private:
    uint32_t m_width, m_height;

#ifdef TINYGUI_PGEX
    std::unique_ptr<olc::Sprite> m_sprite;
    std::unique_ptr<olc::Decal> m_decal;
#else
    GLuint m_id;
#endif
};

class Shader;
class Font;
class RendererBackend {
public:
    virtual void DrawQuad(const Rect& bounds, const Color& color, Texture* texture) = 0;
    virtual void DrawPartialQuad(const Rect& dest, const Rect& src, const Color& color, Texture* texture) = 0;
    virtual void DrawLine(Vector2i a, Vector2i b, const Color& color) = 0;
    virtual void EnableScissor(const Rect& bounds) = 0;
    virtual void DisableScissor() = 0;
    virtual void Render(Shader* shader, Vector2ui screenSize) = 0;
    virtual Vector2i GetTextSize(Font* font, const std::string& text) = 0;

    virtual void DrawPartialQuadUV(const Rect& dest, float* uvs, const Color& color, Texture* texture) = 0;
    virtual void DrawChar(Font* font, const Vector2f& pos, char c, Color color) = 0;
    virtual void DrawText(Font* font, const Vector2f& pos, const std::string& text, Color color) = 0;

    virtual void SetDrawTarget(size_t index) {}
};

#ifndef TINYGUI_PGEX
class Shader {
public:
    enum class Type {
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
    };

    Shader& AddSource(Type type, const std::string& source);
    void Link();

    void Use() const;

    void SetUniform(const std::string& name, int value);
    void SetUniform(const std::string& name, float value);
    void SetUniform(const std::string& name, const Vector2f& value);
    void SetUniform(const std::string& name, const Color& value);
    void SetUniform(const std::string& name, float* matrix, bool transpose = false);
private:
    std::vector<GLint> m_shaders;
    std::map<std::string, GLint> m_uniforms;

    GLuint m_id;

    GLint GetUniformLocation(const std::string& name);
};

class BatchedRenderer : public RendererBackend {
public:
    BatchedRenderer();

    void DrawQuad(const Rect& bounds, const Color& color, Texture* texture) override;
    void DrawPartialQuad(const Rect& dest, const Rect& src, const Color& color, Texture* texture) override;
    void DrawLine(Vector2i a, Vector2i b, const Color& color) override;
    void EnableScissor(const Rect& bounds) override;
    void DisableScissor() override;

    void DrawPartialQuadUV(const Rect& dest, float* uvs, const Color& color, Texture* texture) override;
    void DrawChar(Font* font, const Vector2f& pos, char c, Color color) override;
    void DrawText(Font* font, const Vector2f& pos, const std::string& text, Color color) override;

    Vector2i GetTextSize(Font* font, const std::string& text) override;

    void Render(Shader* shader, Vector2ui screenSize) override;
private:
    struct Vertex {
        Vector2f pos;
        float color[4];
		Vector2f uv;
    };

    struct Batch {
        uint32_t offset, count;
        Texture* texture;
        Rect scissor;

        enum Type {
            TypeQuad = 0,
            TypeLine,
            TypeScissor
        } type;
    };

    std::vector<Batch> m_batches;
    std::vector<Vertex> m_vertices;

    GLuint m_vao, m_vbo;
    uint32_t m_vertexCount{ 0 };

    void UpdateBuffers();
    bool IsPreviousBatchIsCompatible(Batch::Type type, Texture* texture);
    Batch* GetLastBatch();
    Batch* GetNewBatch(Batch::Type type, uint32_t count, Texture* texture);
};

constexpr uint32_t StartCharacter = 32;
constexpr uint32_t CharacterCount = 655;

class Font {
public:
    struct CharInfo {
        int advanceX, leftSideBearing, kerningAdvance;
    };

    void Load(const std::string& filename, float size);

    Texture& GetTexture() { return m_texture; }

    int GetLineHeight() const { return m_lineHeight; }
    int GetAscent() const { return m_ascent; }
    int GetBaseline() const { return m_baseline; }

    const CharInfo& GetCharInfo(uint32_t prevCp, uint32_t nextCp);
    stbtt_packedchar GetPackedChar(char c) { return m_chars[c - StartCharacter]; }

    float GetScale() const { return m_scale; }
private:
    std::array<stbtt_packedchar, CharacterCount> m_chars;
    std::vector<uint8_t> m_ttfData;
    std::map<uint32_t, CharInfo> m_charInfo;

    stbtt_fontinfo m_fontInfo;

    int m_ascent, m_baseline, m_lineHeight;
    float m_scale;

    Texture m_texture;

    int GetKerningAdvance(uint32_t a, uint32_t b);
    void GetCodepointMetrics(uint32_t cp, int& advance, int& lsb);
    void GetCodepointBox(uint32_t cp, int& x0, int& y0, int& x1, int& y1) const;
};
#else
class PGERendererBackend : public RendererBackend {
public:
    PGERendererBackend(olc::PixelGameEngine* pge);

    void DrawQuad(const Rect& bounds, const Color& color, Texture* texture) override;
    void DrawPartialQuad(const Rect& dest, const Rect& src, const Color& color, Texture* texture) override;
    void DrawLine(Vector2i a, Vector2i b, const Color& color) override;

    void EnableScissor(const Rect& bounds) override {} // PGE still has no support for this
    void DisableScissor() override {} // PGE still has no support for this
    void Render(Shader* shader, Vector2ui screenSize) override {}

    Vector2i GetTextSize(Font* font, const std::string& text) override;

    void DrawPartialQuadUV(const Rect& dest, float* uvs, const Color& color, Texture* texture) override;
    void DrawChar(Font* font, const Vector2f& pos, char c, Color color) override {}
    void DrawText(Font* font, const Vector2f& pos, const std::string& text, Color color) override;

    void SetDrawTarget(size_t index) override;

    olc::PixelGameEngine* GetPGE() { return m_pge; }
private:
    olc::PixelGameEngine* m_pge;
};
#endif

class Renderer {
public:
    Renderer() = default;

    void Init();

#ifdef TINYGUI_PGEX
    void SetPGE(olc::PixelGameEngine* pge);
#endif

    void DrawText(const std::string& text, Color color, Rect bounds, uint32_t layer, size_t position = -1);
    void DrawFillRect(Color color, Rect bounds, uint32_t layer, size_t position = -1);
    void DrawLine(Color color, Vector2i a, Vector2i b, uint32_t layer, size_t position = -1);
    void DrawStyleSprite(GuiMapSprite sprite, Color color, Rect bounds, uint32_t layer, size_t position = -1);
    void DrawStyle9Patch(GuiMapSprite sprite, Color color, Rect bounds, uint32_t layer, uint8_t flags = 0xFF, size_t position = -1);
    void DrawImage(Texture* image, Rect bounds, uint32_t layer, size_t position = -1);
    void EnableClip(Rect bounds, uint32_t layer);
    void DisableClip();

    // Raw drawing
    void DrawStyle9Patch(Rect bounds, Color color, GuiMapSprite sprite, uint8_t flags);
    void DrawStyleSprite(Rect bounds, Color color, GuiMapSprite sprite);

    Vector2ui GetScreenSize() const;
    void SetScreenSize(Vector2ui size);

    Vector2i GetTextSize(const std::string& text);
    size_t GetDrawCommandCount() const { return m_drawCommands.size(); }

    void RenderAll();
private:
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
        Color color;
        Rect bounds;
        Texture* image;
        GuiMapSprite sprite;
        uint8_t ninePatchFlags{ 0xFF };
        uint32_t targetLayer{ 0 };
    };

    std::vector<DrawCommand> m_drawCommands;
    std::map<size_t, Texture> m_textures;

    Texture m_guiTexture;

    std::unique_ptr<RendererBackend> m_backend;
#ifndef TINYGUI_PGEX
    Shader m_shader;
    Vector2ui m_screenSize;
    Font m_font;
#endif

    void AddDrawCommand(DrawCommand cmd, uint32_t layer, size_t position = -1);

    void LoadGuiTexture();
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

struct InputState {
	Vector2i mousePos;
	bool mouseDown;
};

struct InputEvent {
    enum class Type {
        MouseDown,
        MouseUp,
        MouseMove,
        TextInput,

        Backspace,
        Delete,
        Home,
		End,
        Left,
        Right,
        Return
    } type;

    Vector2i mousePos, mouseDelta;
    int key;
    bool mouseState;
    char keyChar;
};

namespace utils {
    template <typename... Args>
    std::string StringFormat(const std::string& format, Args... args) {
        size_t size = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;
        std::string result(size, '\0');
        std::snprintf(result.data(), size, format.c_str(), args...);
        return result.substr(0, size - 1);
    }

    float Luma(const Color& color);

    std::vector<std::string> Split(const std::string& str, const std::string& delimiter);
    std::vector<std::string> Split(const std::string& str, const std::initializer_list<std::string>& delimiters);

    size_t GetIDFromName(const std::string& name);

    uint32_t GetCodepoint(const std::string& text, uint32_t pos, uint32_t& out);
}

class TinyGUI {
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

    // ------- WIDGETS -------
    Widget& GetWidget(const std::string& name, Rect bounds, bool blockInputByPopup = true);
    void Label(
        Rect bounds,
        const std::string& text,
        int alignment = (Alignment::AlignLeft | Alignment::AlignTop),
        const std::optional<Color>& bg = std::nullopt,
        bool wordWrap = false
    );
    bool Button(
        const std::string& name,
        Rect bounds,
        const std::string& text,
        const std::optional<Color>& color = std::nullopt
    );
    bool Slider(
        const std::string& name,
        Rect bounds,
        int& value, int min = 0, int max = 100, int step = 1,
        const std::optional<Color>& bg = std::nullopt
    );
    bool SliderF(
		const std::string& name,
		Rect bounds,
		float& value, float min = 0.0f, float max = 1.0f, float step = 0.01f,
		const std::optional<Color>& bg = std::nullopt
	);
    bool Toggle(const std::string& name, Rect bounds, const std::string& text, bool& value);
    bool Spinner(
        const std::string& name,
        Rect bounds,
        int& value, int min = 0, int max = 100, int step = 1,
        const std::string& fmt = "%d",
        const std::optional<Color>& bg = std::nullopt
    );
    bool SpinnerF(
        const std::string& name,
		Rect bounds,
		float& value, float min = 0.0f, float max = 1.0f, float step = 0.01f,
		const std::string& fmt = "%.2f",
        const std::optional<Color>& bg = std::nullopt
    );
    bool EditBox(const std::string& name, Rect bounds, std::string& text);
    void Image(const std::string& name, Rect bounds, Texture* texture);

    void TabBar(const std::string& name, Rect bounds, std::string* tabs, size_t numTabs, size_t& selected);

    void BeginFrame(
        const std::string& name,
        const std::string& title,
        const Vector2i& position,
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

    void ShowPopup(const std::string& name, Vector2i position);
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
    Color PixelBrightness(Color color, float amount);

    // ------- STATE -------
    void OnCreate();
    bool OnUpdate(float deltaTime);
    void OnFinalize(float deltaTime);
    void OnEvent(InputEvent ev);

    bool GetMouseState() const { return m_state.mouseDown; }

    Vector2i GetLastClickedWidgetPosition() const { return m_state.lastClickedWidgetPosition; }
    Vector2i GetMousePos() const { return m_state.mousePos; }
    bool IsMouseDown() const { return m_state.mouseDown; }

    bool IsDragging() const { return m_state.dragging; }
    Vector2i GetDragPosition() const { return m_state.dragStart + m_state.dragOffset - m_state.dragCorrection; }

    void PrepareDrag(Vector2i elementPosition);

    Renderer& GetRenderer() { return m_renderer; }

    Color baseColor{ Color(95, 134, 176) };

#ifdef TINYGUI_PGEX
    void SetPGE(olc::PixelGameEngine* pge) { m_pge = pge; }
#endif

protected:

    Widget& GetWidgetByName(const std::string& name);

    void DrawPopups();

    GuiMapSprite WidgetStateToSprite(WidgetState state);

    bool CurrentFrameIsCollapsed();

    void RenderDockingAreas();

    Color GetBestForegroundColor(const std::optional<Color>& bgColor = std::nullopt);

    size_t NearestDockingArea(const Rect& bounds);
    bool IsDockingAreaFree(size_t id);

    template <typename T>
    bool SliderImpl(
        const std::string& name,
        Rect bounds,
        T& value, T min, T max, T step,
        const std::optional<Color>& bg
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

        m_renderer.DrawStyle9Patch(
            GuiMapSprite::ButtonActive,
            baseColor,
            Rect{
                bounds.x, bounds.y,
                bounds.width, thumbHeight,
            },
            m_state.targetLayer
        );
        if (bg.has_value()) {
            m_renderer.DrawFillRect(
                *bg,
                Rect{ bounds.x + 1, bounds.y + 1, bounds.width - 2, thumbHeight - 2 },
                m_state.targetLayer
            );
        }

        auto state = wid.state == WidgetState::Active || wid.state == WidgetState::Clicked ?
            WidgetState::Hovered : wid.state;

        float fac = float(value - min) / (max - min);
        int thumbX = int(fac * actualWidth);

        m_renderer.DrawStyle9Patch(
            WidgetStateToSprite(state),
            baseColor,
            Rect{ bounds.x + thumbX, bounds.y, thumbWidth, thumbHeight },
            m_state.targetLayer
        );
        m_renderer.DrawStyleSprite(
            GuiMapSprite::Grip,
            baseColor,
            Rect{
                bounds.x + thumbX + thumbWidth / 2 - 4,
                bounds.y + thumbHeight / 2 - 4,
                8, 8
            },
            m_state.targetLayer
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
        const std::optional<Color>& bg
    ) requires std::is_integral_v<T> || std::is_floating_point_v<T> {
        const int thumbWidth = 18;

        m_renderer.DrawStyle9Patch(
            bg.has_value() ? GuiMapSprite::ButtonIdle : GuiMapSprite::ButtonActive,
            bg.has_value() ? *bg : Color{ 255, 255, 255, 255 },
            bounds,
            m_state.targetLayer
        );

        auto wid = GetWidget(name, Rect{ bounds.x, bounds.y, bounds.width - thumbWidth, bounds.height });

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
        auto [tw, th] = m_renderer.GetTextSize(text).AsPair();

        Color textColor = Color{ 255, 255, 255, 255 };
        if (bg.has_value()) {
            textColor = GetBestForegroundColor(bg);
        }

        int textAreaWidth = bounds.width - thumbWidth;
        m_renderer.DrawText(
            text,
            textColor,
            { bounds.x + textAreaWidth / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height },
            m_state.targetLayer
        );

        return changed;
    }

    struct Word {
        std::string text;
        enum {
            TypeText = 0,
            TypeSpace,
            TypeTab,
            TypeNewLine
        } type;
    };

    struct Popup {
        std::string name;
        Vector2i position;
        Vector2i size;
        std::vector<std::string> items;
        size_t lastSelected{ 0 };
    };

    struct Frame {
        std::string title, name;

        // draw command location
        size_t insertId;

        Rect bounds, titleBounds;
        Vector2i positionOffset{ 0, 0 };
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
        Vector2i mousePos, lastClickedWidgetPosition, mouseDelta;

        Vector2i dragStart, dragOffset, dragCorrection;
        bool dragging{ false };

        size_t openPopup;

        float blinkTimer{ 0.0f };
        bool blink{ false };

        uint32_t targetLayer{ 0 };

        Frame* clickedFrame{ nullptr };

        // text input state
        std::string textInput;
        bool textInputActive{ false };
        int textInputCursor{ 0 };
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

    Renderer m_renderer{};
#ifdef TINYGUI_PGEX
    olc::PixelGameEngine* m_pge{ nullptr };
#endif

    // docking
    std::map<size_t, Rect> m_dockingAreas;

    uint32_t m_widgetsLayer{ 0 }, m_panelsLayer{ 0 };

    void SetTargetLayer(uint32_t layer);
};

#ifdef TINYGUI_PGEX
class olcPGEX_TinyGUI : public olc::PGEX, public TinyGUI {
public:
    olcPGEX_TinyGUI() : olc::PGEX(true), TinyGUI() {}

    void OnBeforeUserCreate() override;
    bool OnBeforeUserUpdate(float& fElapsedTime) override;
    void OnAfterUserUpdate(float fElapsedTime) override;

private:
    bool m_mouseWasDown{ false }, m_typed{ false };
    olc::vi2d m_prevMousePos{ 0, 0 };
};
#endif

#ifdef TINYGUI_IMPLEMENTATION

void Texture::Load(const std::string& fileName) {
#ifdef TINYGUI_PGEX
	m_sprite = std::make_unique<olc::Sprite>(fileName);
	m_decal = std::make_unique<olc::Decal>(m_sprite.get());
    m_width = m_sprite->width;
    m_height = m_sprite->height;
#else
	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(fileName.c_str(), &width, &height, &channels, 0);
    if (!data) {
		std::cerr << "Failed to load texture: " << fileName << std::endl;
		return;
	}

    LoadFromMemory(data, width, height, channels);

	stbi_image_free(data);
#endif
}

void Texture::LoadFromMemory(uint8_t* data, uint32_t width, uint32_t height, uint32_t channels) {
#ifdef TINYGUI_PGEX
    // TODO: Finish this up
	m_sprite = std::make_unique<olc::Sprite>(width, height);
	m_decal = std::make_unique<olc::Decal>(m_sprite.get());

    // copy data
    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            uint8_t pixel[4] = { 0, 0, 0, 255 };
            for (uint32_t c = 0; c < channels; c++) {
                pixel[c] = data[(y * width + x) * channels + c];
            }
            m_sprite->SetPixel(x, y, olc::Pixel(pixel[0], pixel[1], pixel[2], pixel[3]));
        }
    }
    m_decal->Update();

	m_width = width;
	m_height = height;
#else
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    GLenum format = GL_RGB;
    switch (channels) {
        case 1: format = GL_ALPHA; break;
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default: break;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    m_width = width;
    m_height = height;
#endif
}

#ifndef TINYGUI_PGEX
Shader& Shader::AddSource(Type type, const std::string& source) {
    GLuint shader = glCreateShader(static_cast<GLenum>(type));
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << "Shader compilation failed: " << infoLog << std::endl;
	}

    m_shaders.push_back(shader);

    return (*this);
}

void Shader::Link() {
    m_id = glCreateProgram();
    for (auto shader : m_shaders) {
		glAttachShader(m_id, shader);
	}
	glLinkProgram(m_id);

	GLint success;
	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
		std::cerr << "Shader linking failed: " << infoLog << std::endl;
	}

    for (auto shader : m_shaders) {
		glDeleteShader(shader);
	}

    m_shaders.clear();
}

void Shader::Use() const {
    glUseProgram(m_id);
}

void Shader::SetUniform(const std::string& name, int value) {
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform(const std::string& name, float value) {
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform(const std::string& name, const Vector2f& value) {
	glUniform2f(GetUniformLocation(name), value.x, value.y);
}

void Shader::SetUniform(const std::string& name, const Color& value) {
    glUniform4f(
        GetUniformLocation(name),
        float(value.r) / 255.0f,
        float(value.g) / 255.0f,
        float(value.b) / 255.0f,
        float(value.a) / 255.0f
    );
}

void Shader::SetUniform(const std::string& name, float* matrix, bool transpose) {
    glUniformMatrix4fv(GetUniformLocation(name), 1, transpose, matrix);
}

GLint Shader::GetUniformLocation(const std::string& name) {
    auto it = m_uniforms.find(name);
    if (it != m_uniforms.end()) {
		return it->second;
	}

	GLint location = glGetUniformLocation(m_id, name.c_str());
	m_uniforms[name] = location;
	return location;
}

BatchedRenderer::BatchedRenderer() {
    glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void BatchedRenderer::DrawQuad(const Rect& bounds, const Color& color, Texture* texture) {
    const Vector2f vertices[] = {
        { 0.0f, 0.0f },
        { 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f }
    };
    const uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };

    uint32_t vertOffset = m_vertices.size();
    Batch* batch = GetNewBatch(Batch::TypeQuad, 6, texture);

    for (size_t i = 0; i < 6; i++) {
        Vertex vertex{};
        vertex.pos = {
            float(bounds.x + vertices[indices[i]].x * bounds.width),
            float(bounds.y + vertices[indices[i]].y * bounds.height)
        };
        vertex.color[0] = float(color.r) / 255.0f;
        vertex.color[1] = float(color.g) / 255.0f;
        vertex.color[2] = float(color.b) / 255.0f;
        vertex.color[3] = float(color.a) / 255.0f;
        vertex.uv = { vertices[indices[i]].x, vertices[indices[i]].y };

        m_vertices.push_back(vertex);
    }
}

void BatchedRenderer::DrawPartialQuad(const Rect& dest, const Rect& src, const Color& color, Texture* texture) {
    const Vector2f vertices[] = {
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f }
	};

    const Vector2ui size = texture->Size();
    const Vector2f uvs[] = {
        { float(src.x) / size.x, float(src.y) / size.y },
        { float(src.x + src.width) / size.x, float(src.y) / size.y },
		{ float(src.x + src.width) / size.x, float(src.y + src.height) / size.y },
		{ float(src.x) / size.x, float(src.y + src.height) / size.y }
    };
	const uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };

    uint32_t vertOffset = m_vertices.size();
    Batch* batch = GetNewBatch(Batch::TypeQuad, 6, texture);

    for (size_t i = 0; i < 6; i++) {
        Vertex vertex{};
        vertex.pos = {
            float(dest.x + vertices[indices[i]].x * dest.width),
            float(dest.y + vertices[indices[i]].y * dest.height)
        };
        vertex.color[0] = float(color.r) / 255.0f;
        vertex.color[1] = float(color.g) / 255.0f;
        vertex.color[2] = float(color.b) / 255.0f;
        vertex.color[3] = float(color.a) / 255.0f;
        vertex.uv = uvs[indices[i]];

        m_vertices.push_back(vertex);
    }
}

void BatchedRenderer::DrawLine(Vector2i a, Vector2i b, const Color& color) {
    uint32_t vertOffset = m_vertices.size();
    Batch* batch = GetNewBatch(Batch::TypeLine, 2, nullptr);

    Vector2i points[] = { a, b };
    for (size_t i = 0; i < 2; i++) {
        Vertex vertex{};
        vertex.pos = { float(points[i].x), float(points[i].y) };
        vertex.color[0] = float(color.r) / 255.0f;
        vertex.color[1] = float(color.g) / 255.0f;
        vertex.color[2] = float(color.b) / 255.0f;
        vertex.color[3] = float(color.a) / 255.0f;
        vertex.uv = { 0.0f, 0.0f };

        m_vertices.push_back(vertex);
    }
}

void BatchedRenderer::EnableScissor(const Rect& bounds) {
    Batch batch{};
	batch.offset = 0;
	batch.count = 0;
	batch.type = Batch::TypeScissor;
	batch.scissor = bounds;
	m_batches.push_back(batch);
}

void BatchedRenderer::DisableScissor() {
    Batch batch{};
	batch.offset = 0;
	batch.count = 0;
	batch.type = Batch::TypeScissor;
	batch.scissor = Rect{ 0, 0, 0, 0 };
	m_batches.push_back(batch);
}

void BatchedRenderer::DrawPartialQuadUV(const Rect& dest, float* uvs, const Color& color, Texture* texture) {
    const Vector2f vertices[] = {
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f }
	};
	const uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };

	uint32_t vertOffset = m_vertices.size();
	Batch* batch = GetNewBatch(Batch::TypeQuad, 6, texture);

	for (size_t i = 0; i < 6; i++) {
		Vertex vertex{};
		vertex.pos = {
			float(dest.x + vertices[indices[i]].x * dest.width),
			float(dest.y + vertices[indices[i]].y * dest.height)
		};
		vertex.color[0] = float(color.r) / 255.0f;
		vertex.color[1] = float(color.g) / 255.0f;
		vertex.color[2] = float(color.b) / 255.0f;
		vertex.color[3] = float(color.a) / 255.0f;
		vertex.uv = { uvs[indices[i] * 2], uvs[indices[i] * 2 + 1] };

		m_vertices.push_back(vertex);
	}
}

void BatchedRenderer::DrawChar(Font* font, const Vector2f& pos, char c, Color color) {
    stbtt_packedchar packedChar = font->GetPackedChar(c);
    
    Rect src = {
		packedChar.x0, packedChar.y0,
		packedChar.x1 - packedChar.x0, packedChar.y1 - packedChar.y0
	};
    Rect dest = {
		int(pos.x + packedChar.xoff),
		int(pos.y + packedChar.yoff) + font->GetBaseline(),
		src.width, src.height
	};

	DrawPartialQuad(dest, src, color, &font->GetTexture());
}

void BatchedRenderer::DrawText(Font* font, const Vector2f& pos, const std::string& text, Color color) {
    Vector2f cursor = pos;
    uint32_t prevCp = 0;
	for (size_t i = 0; i < text.size(); i++) {
		char c = text[i];
		if (c < StartCharacter || c >= StartCharacter + CharacterCount) continue;

		DrawChar(font, cursor, c, color);

        auto info = font->GetCharInfo(prevCp, uint32_t(c));
        cursor.x += info.advanceX + info.leftSideBearing + info.kerningAdvance;

        prevCp = uint32_t(c);
	}
}

Vector2i BatchedRenderer::GetTextSize(Font* font, const std::string& text) {
    int w = 0, h = 0;
    int accumWidth = 0;

    int i = 0;

    uint32_t prevCp = 0;
    for (char c : text) {
        if (c < StartCharacter || c >= StartCharacter + CharacterCount) continue;

        if (c == '\n') {
            h += font->GetLineHeight();
            w = std::max(w, accumWidth);
            accumWidth = 0;
        }
        else {
            auto info = font->GetCharInfo(prevCp, uint32_t(c));
            accumWidth += info.advanceX + info.leftSideBearing + info.kerningAdvance;
        }

        prevCp = uint32_t(c);
    }

    w = std::max(w, accumWidth);
    h += font->GetLineHeight();

    return { w, h };
}

void BatchedRenderer::Render(Shader* shader, Vector2ui screenSize) {
    UpdateBuffers();

    auto fnOrtho = [](float left, float right, float bottom, float top, float znear, float zfar, float* m) {
        float tx = -((right + left) / (right - left));
		float ty = -((top + bottom) / (top - bottom));
		float tz = -((zfar + znear) / (zfar - znear));

        m[0] = 2.0f / (right - left);
        m[1] = 0.0f;
        m[2] = 0.0f;
        m[3] = 0.0f;

        m[4] = 0.0f;
        m[5] = 2.0f / (top - bottom);
        m[6] = 0.0f;
        m[7] = 0.0f;

        m[8] = 0.0f;
        m[9] = 0.0f;
        m[10] = -2.0f / (zfar - znear);
        m[11] = 0.0f;

        m[12] = tx;
        m[13] = ty;
        m[14] = tz;
        m[15] = 1.0f;

    };

    float projection[16];
    fnOrtho(0.0f, float(screenSize.x), float(screenSize.y), 0.0f, -1.0f, 1.0f, projection);

    shader->SetUniform("uTexture", 0);
    shader->SetUniform("uProjection", projection);

    int scissorBox[4];
    glGetIntegerv(GL_SCISSOR_BOX, scissorBox);

    glActiveTexture(GL_TEXTURE0);

    GLuint prevTexture = 0;
    for (const Batch& batch : m_batches) {
        if (batch.texture && prevTexture != batch.texture->GetID()) {
			glBindTexture(GL_TEXTURE_2D, batch.texture->GetID());
            prevTexture = batch.texture->GetID();
        }

        shader->SetUniform("uUseTexture", batch.texture ? 1 : 0);

        switch (batch.type) {
            case Batch::TypeScissor: {
                if (batch.scissor.width == 0 || batch.scissor.height == 0) {
					glDisable(GL_SCISSOR_TEST);
                }
                else {
					glEnable(GL_SCISSOR_TEST);
                    int y = screenSize.y - batch.scissor.y - batch.scissor.height;
                    glScissor(batch.scissor.x, y, batch.scissor.width, batch.scissor.height);
                }
            } break;
            case Batch::TypeLine: {
				glDrawArrays(GL_LINES, batch.offset, batch.count);
			} break;
            case Batch::TypeQuad: {
                glDrawArrays(GL_TRIANGLES, batch.offset, batch.count);
            } break;
        }
    }

    glScissor(scissorBox[0], scissorBox[1], scissorBox[2], scissorBox[3]);
    m_batches.clear();
}

void BatchedRenderer::UpdateBuffers() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    if (m_vertexCount != m_vertices.size()) {
		glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_DYNAMIC_DRAW);
    }
    else {
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_vertices.size() * sizeof(Vertex), m_vertices.data());
    }

	m_vertexCount = m_vertices.size();

    m_vertices.clear();
}

bool BatchedRenderer::IsPreviousBatchIsCompatible(Batch::Type type, Texture* texture) {
    if (m_batches.empty()) return false;
	auto& lastBatch = m_batches.back();

    if (lastBatch.type != type) return false;
	if (lastBatch.texture != texture) return false;

	return true;
}

BatchedRenderer::Batch* BatchedRenderer::GetLastBatch() {
    if (m_batches.empty()) return nullptr;
	return &m_batches.back();
}

BatchedRenderer::Batch* BatchedRenderer::GetNewBatch(Batch::Type type, uint32_t count, Texture* texture) {
    if (!IsPreviousBatchIsCompatible(type, texture)) {
        Batch batch{};
        batch.offset = m_vertices.size();
        batch.count = count;
        batch.texture = texture;
        batch.type = type;
        m_batches.push_back(batch);
        return &m_batches.back();
    }

    Batch* batch = GetLastBatch();
    if (batch) {
        batch->count += count;
    }
    return batch;
}

void Font::Load(const std::string& filename, float size) {
    // read font file as byte array
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open font file: " << filename << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    file.seekg(0, std::ios::beg);

    m_ttfData.resize(length);
    file.read(reinterpret_cast<char*>(m_ttfData.data()), length);
    file.close();

    if (!stbtt_InitFont(&m_fontInfo, m_ttfData.data(), stbtt_GetFontOffsetForIndex(m_ttfData.data(), 0))) {
		std::cerr << "Failed to initialize font: " << filename << std::endl;
		return;
	}

    std::vector<uint8_t> bitmap;
    uint32_t textureSize = 32;
    while (true) {
        bitmap.resize(textureSize * textureSize);

        stbtt_pack_context ctx;
        stbtt_PackBegin(&ctx, bitmap.data(), textureSize, textureSize, 0, 1, nullptr);
        stbtt_PackSetOversampling(&ctx, 1, 1);

        if (!stbtt_PackFontRange(&ctx, m_ttfData.data(), 0, size, StartCharacter, CharacterCount, m_chars.data())) {
            stbtt_PackEnd(&ctx);
            textureSize *= 2;
        }
        else {
            stbtt_PackEnd(&ctx);
			break;
        }
    }

    std::vector<uint8_t> bitmapRGBA(textureSize * textureSize * 4);
    for (size_t i = 0; i < bitmap.size(); i++) {
		bitmapRGBA[i * 4 + 0] = 255;
		bitmapRGBA[i * 4 + 1] = 255;
		bitmapRGBA[i * 4 + 2] = 255;
		bitmapRGBA[i * 4 + 3] = bitmap[i];
	}

    m_texture.LoadFromMemory(bitmapRGBA.data(), textureSize, textureSize, 4);

    m_scale = stbtt_ScaleForPixelHeight(&m_fontInfo, size);

    int descent, lineGap;
    stbtt_GetFontVMetrics(&m_fontInfo, &m_ascent, &descent, &lineGap);

    m_baseline = int(m_ascent * m_scale);
    m_lineHeight = int((m_ascent - descent + lineGap) * m_scale);
}

const Font::CharInfo& Font::GetCharInfo(uint32_t prevCp, uint32_t nextCp) {
    auto pos = m_charInfo.find(nextCp);
    if (pos != m_charInfo.end()) {
        return pos->second;
    }

    CharInfo info{};
    GetCodepointMetrics(nextCp, info.advanceX, info.leftSideBearing);
    info.kerningAdvance = GetKerningAdvance(prevCp, nextCp);

    m_charInfo[nextCp] = info;

    return m_charInfo[nextCp];
}

int Font::GetKerningAdvance(uint32_t a, uint32_t b) {
    int adv = stbtt_GetCodepointKernAdvance(&m_fontInfo, a, b);
    return int(adv * m_scale);
}

void Font::GetCodepointMetrics(uint32_t cp, int& advance, int& lsb) {
    int advValue = 0, lsbValue = 0;
    stbtt_GetCodepointHMetrics(&m_fontInfo, cp, &advValue, &lsbValue);
    advance = int(advValue * m_scale);
    lsb = int(lsbValue * m_scale);
}

void Font::GetCodepointBox(uint32_t cp, int& x0, int& y0, int& x1, int& y1) const {
    stbtt_GetCodepointBox(&m_fontInfo, cp, &x0, &y0, &x1, &y1);
    x0 *= m_scale;
    y0 *= m_scale;
    x1 *= m_scale;
    y1 *= m_scale;
}
#else
PGERendererBackend::PGERendererBackend(olc::PixelGameEngine* pge) {
    m_pge = pge;
}

void PGERendererBackend::DrawQuad(const Rect& bounds, const Color& color, Texture* texture) {
	if (texture) {
        auto size = texture->Size();
		m_pge->DrawPartialDecal(
            bounds.Position().AsOLC(),
            bounds.Size().AsOLC(),
			texture->GetDecal(),
			olc::vf2d{ 0.0f, 0.0f },
			size.AsOLC(),
			color.AsOLC()
		);
	}
	else {
		m_pge->FillRectDecal(bounds.Position().AsOLC(), bounds.Size().AsOLC(), color.AsOLC());
	}
}

void PGERendererBackend::DrawPartialQuad(const Rect& dest, const Rect& src, const Color& color, Texture* texture) {
    if (!texture) {
        DrawQuad(dest, color, nullptr);
        return;
    }

	auto size = texture->Size();
	m_pge->DrawPartialDecal(
		dest.Position().AsOLC(),
		dest.Size().AsOLC(),
		texture->GetDecal(),
        src.Position().AsOLC(),
        src.Size().AsOLC(),
        color.AsOLC()
	);
}

void PGERendererBackend::DrawLine(Vector2i a, Vector2i b, const Color& color) {
	m_pge->DrawLine(a.x, a.y, b.x, b.y, color.AsOLC());
}

Vector2i PGERendererBackend::GetTextSize(Font* font, const std::string& text) {
    auto [w, h] = m_pge->GetTextSizeProp(text);
    return { w, h };
}

void PGERendererBackend::DrawPartialQuadUV(const Rect& dest, float* uvs, const Color& color, Texture* texture) {
    if (!texture) {
		DrawQuad(dest, color, nullptr);
		return;
	}

	auto size = texture->Size();
	m_pge->DrawPartialDecal(
		dest.Position().AsOLC(),
		dest.Size().AsOLC(),
		texture->GetDecal(),
		olc::vf2d{ uvs[0] * size.x, uvs[1] * size.y },
		olc::vf2d{ uvs[2] * size.x, uvs[3] * size.y },
		color.AsOLC()
	);
}
void PGERendererBackend::DrawText(Font* font, const Vector2f& pos, const std::string& text, Color color) {
    m_pge->DrawStringPropDecal(pos.AsOLC(), text, color.AsOLC());
}

void PGERendererBackend::SetDrawTarget(size_t index) {
    m_pge->SetDrawTarget(index);
}
#endif

void Renderer::AddDrawCommand(DrawCommand cmd, uint32_t layer, size_t position) {
    cmd.targetLayer = layer;
    if (position < size_t(-1)) {
        m_drawCommands.insert(m_drawCommands.begin() + position, cmd);
    }
    else {
        m_drawCommands.push_back(cmd);
    }
}

void Renderer::Init() {
    LoadGuiTexture();
#ifndef TINYGUI_PGEX
    m_backend = std::make_unique<BatchedRenderer>();
    m_font.Load("opensans.ttf", 18.0f);

    std::string vert = R"(
        #version 460 core
		layout(location = 0) in vec2 aPos;
		layout(location = 1) in vec4 aColor;
		layout(location = 2) in vec2 aUV;

		out vec4 vColor;
		out vec2 vUV;

        uniform mat4 uProjection;

		void main() {
			gl_Position = uProjection * vec4(aPos, 0.0, 1.0);
			vColor = aColor;
			vUV = aUV;
		}
    )";

    std::string frag = R"(
		#version 460 core
        in vec4 vColor;
        in vec2 vUV;
        
        out vec4 FragColor;

        uniform sampler2D uTexture;
        uniform bool uUseTexture;

        void main() {
            vec4 color = vColor;
            if (uUseTexture) {
				color *= texture(uTexture, vUV);
			}
			FragColor = color;
		}
	)";

    m_shader
        .AddSource(Shader::Type::Vertex, vert)
        .AddSource(Shader::Type::Fragment, frag)
        .Link();
#endif
}

#ifdef TINYGUI_PGEX
inline void Renderer::SetPGE(olc::PixelGameEngine* pge) {
    m_backend = std::make_unique<PGERendererBackend>(pge);
}
#endif

void Renderer::DrawText(const std::string& text, Color color, Rect bounds, uint32_t layer, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::Text;
    cmd.text = text;
    cmd.color = color;
    cmd.bounds = bounds;
    AddDrawCommand(cmd, layer, position);

  //  auto [tw, th] = GetTextSize(text).AsPair();
  //  DrawStyle9Patch(
  //      GuiMapSprite::Selection,
  //      Color{ 0, 255, 0, 128 },
  //      Rect{ bounds.x, bounds.y, tw, th },
		//0
  //  );
}

void Renderer::DrawFillRect(Color color, Rect bounds, uint32_t layer, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::FillRect;
    cmd.color = color;
    cmd.bounds = bounds;
    AddDrawCommand(cmd, layer, position);
}

void Renderer::DrawLine(Color color, Vector2i a, Vector2i b, uint32_t layer, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::Line;
    cmd.color = color;
    cmd.bounds = Rect{ a.x, a.y, b.x, b.y };
    AddDrawCommand(cmd, layer, position);
}

void Renderer::DrawStyleSprite(GuiMapSprite sprite, Color color, Rect bounds, uint32_t layer, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::StyleSprite;
    cmd.sprite = sprite;
    cmd.color = color;
    cmd.bounds = bounds;
    AddDrawCommand(cmd, layer, position);
}

void Renderer::DrawStyle9Patch(GuiMapSprite sprite, Color color, Rect bounds, uint32_t layer, uint8_t flags, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::Style9Patch;
    cmd.sprite = sprite;
    cmd.color = color;
    cmd.bounds = bounds;
    cmd.ninePatchFlags = flags;
    AddDrawCommand(cmd, layer, position);
}

void Renderer::DrawImage(Texture* image, Rect bounds, uint32_t layer, size_t position) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::Image;
    cmd.image = image;
    cmd.bounds = bounds;
    AddDrawCommand(cmd, layer, position);
}

void Renderer::EnableClip(Rect bounds, uint32_t layer) {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::EnableClip;
    cmd.bounds = bounds;
    AddDrawCommand(cmd, layer);
}

void Renderer::DisableClip() {
    DrawCommand cmd{};
    cmd.type = DrawCommandType::DisableClip;
    AddDrawCommand(cmd, 0);
}

void Renderer::DrawStyle9Patch(Rect bounds, Color color, GuiMapSprite sprite, uint8_t flags) {
    const int spriteWidth = 8;
    const int spriteHeight = 8;
    const int padding = 3;
    const int numCols = m_guiTexture.Size().x / spriteWidth;

    int spriteIndex = int(sprite);
    Rect src{
        (spriteIndex % numCols) * spriteWidth,
        (spriteIndex / numCols) * spriteHeight,
        spriteWidth, spriteHeight
    };

    auto fnDraw = [this, color](Rect dst, Rect src) {
        m_backend->DrawPartialQuad(dst, src, color, &m_guiTexture);
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

void Renderer::DrawStyleSprite(Rect bounds, Color color, GuiMapSprite sprite) {
    const int spriteWidth = 8;
    const int spriteHeight = 8;
    const int numCols = m_guiTexture.Size().x / spriteWidth;

    int spriteIndex = int(sprite);
    Rect src{
        (spriteIndex % numCols) * spriteWidth,
        (spriteIndex / numCols) * spriteHeight,
        spriteWidth, spriteHeight
    };

    m_backend->DrawPartialQuad(bounds, src, color, &m_guiTexture);
}

Vector2ui Renderer::GetScreenSize() const {
#ifndef TINYGUI_PGEX
    return m_screenSize;
#else
    auto pgeBackend = dynamic_cast<PGERendererBackend*>(m_backend.get());
    auto pge = pgeBackend->GetPGE();
    return { uint32_t(pge->ScreenWidth()), uint32_t(pge->ScreenHeight()) };
#endif
}

void Renderer::SetScreenSize(Vector2ui size) {
#ifndef TINYGUI_PGEX
	m_screenSize = size;
#endif
}

Vector2i Renderer::GetTextSize(const std::string& text) {
#ifndef TINYGUI_PGEX
    return m_backend->GetTextSize(&m_font, text);
#else
    return m_backend->GetTextSize(nullptr, text);
#endif
}


void Renderer::RenderAll() {
    std::vector<Rect> scissorStack;

    uint32_t prevDrawTarget = 0;
    for (const auto& cmd : m_drawCommands) {
        if (prevDrawTarget != cmd.targetLayer) {
            m_backend->SetDrawTarget(cmd.targetLayer);
            prevDrawTarget = cmd.targetLayer;
        }

        switch (cmd.type) {
            case DrawCommandType::Text: {
#ifndef TINYGUI_PGEX
                m_backend->DrawText(
                    &m_font,
                    { float(cmd.bounds.x), float(cmd.bounds.y) },
                    cmd.text,
                    cmd.color
                );
#else
                m_backend->DrawText(
                    nullptr,
                    { float(cmd.bounds.x), float(cmd.bounds.y) },
                    cmd.text,
                    cmd.color
                );
#endif
            } break;
			case DrawCommandType::FillRect:
                m_backend->DrawQuad(
					cmd.bounds,
					cmd.color,
					nullptr
				);
				break;
			case DrawCommandType::Line:
                m_backend->DrawLine(
                    { cmd.bounds.x, cmd.bounds.y },
                    { cmd.bounds.width, cmd.bounds.height },
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
                m_backend->DrawQuad(
					cmd.bounds,
					Color(255, 255, 255),
					cmd.image
				);
            } break;
            case DrawCommandType::EnableClip: {
                GLint rect[4];
                glGetIntegerv(GL_SCISSOR_BOX, rect);
                scissorStack.push_back(Rect{ rect[0], rect[1], rect[2], rect[3] });

                m_backend->EnableScissor(cmd.bounds);
            } break;
            case DrawCommandType::DisableClip: {
                if (scissorStack.empty()) continue;
                auto& rect = scissorStack.back();
                scissorStack.pop_back();
                m_backend->DisableScissor();
			} break;
            default: break;
		}
	}
	m_drawCommands.clear();

#ifndef TINYGUI_PGEX
    m_shader.Use();
    m_backend->Render(&m_shader, GetScreenSize());
#endif
}

void Renderer::LoadGuiTexture() {
    uint8_t* pixelData = new uint8_t[GuiMapWidth * GuiMapHeight * 4];

    uint16_t index = 0, dataIndex = 0;
    for (size_t y = 0; y < GuiMapHeight; y++) {
        for (size_t x = 0; x < GuiMapWidth; x++) {
            uint8_t msb = GuiMap[index++];
            uint8_t lsb = GuiMap[index++];
            uint16_t rgb565 = (lsb << 8) | msb;

            // convert to RGB888
            uint8_t r = ((rgb565 & 0b1111100000000000) >> 11);
            uint8_t g = ((rgb565 & 0b0000011111100000) >> 5);
            uint8_t b =  (rgb565 & 0b0000000000011111);
            r = (r * 255) / 31;
            g = (g * 255) / 63;
            b = (b * 255) / 31;

            uint8_t a = GuiMap[GuiMapAlphaChannelStart + (y * GuiMapWidth + x)];

            pixelData[dataIndex++] = r;
            pixelData[dataIndex++] = g;
            pixelData[dataIndex++] = b;
            pixelData[dataIndex++] = a;
        }
    }

    m_guiTexture.LoadFromMemory(pixelData, GuiMapWidth, GuiMapHeight, 4);
    delete[] pixelData;
}

void TinyGUI::RenderDockingAreas() {
    for (const auto& [id, rect] : m_dockingAreas) {
        if (!IsDockingAreaFree(id)) continue;
        m_renderer.DrawStyle9Patch(
            GuiMapSprite::Selection,
            Color(0, 0, 0, 110),
            rect,
            0
        );
	}
}

bool TinyGUI::CurrentFrameIsCollapsed() {
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

bool Rect::HasPoint(const Vector2i& pos) const {
	return HasPoint(pos.x, pos.y);
}

void TinyGUI::Label(
    Rect bounds,
    const std::string& text,
    int alignment,
    const std::optional<Color>& bg,
    bool wordWrap
) {
    if (CurrentFrameIsCollapsed()) return;

    if (bg.has_value()) {
        m_renderer.DrawFillRect(*bg, bounds, m_state.targetLayer);
    }

    const int defaultLineSpacing = 2;

    Color col = GetBestForegroundColor(bg);

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
			auto [tw, th] = m_renderer.GetTextSize(word.text).AsPair();

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
        auto [tw, th] = m_renderer.GetTextSize(words[0].text).AsPair();
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

    m_renderer.EnableClip(bounds.Expand(-1), m_state.targetLayer);

    int currentX = 0, currentY = 0;
    int lineIndex = 0;
    while (!words.empty()) {
        Word word = words[0];
        words.erase(words.begin());

        switch (word.type) {
            case Word::TypeText: {
                auto [tw, th] = m_renderer.GetTextSize(word.text).AsPair();
                
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

                m_renderer.DrawText(
                    word.text,
                    col,
                    { bounds.x + currentX + offX, bounds.y + currentY + offY, bounds.width, bounds.height },
                    m_state.targetLayer
                );

                currentX += tw;
			} break;
            case Word::TypeSpace: {
                auto [tw, th] = m_renderer.GetTextSize(" ").AsPair();
                currentX += tw;
			} break;
            case Word::TypeTab: {
                auto [tw, th] = m_renderer.GetTextSize(" ").AsPair();
                currentX += tw * 2;
			} break;
            case Word::TypeNewLine: {
				currentX = 0;
				currentY += lineHeightAvg;
                lineIndex++;
			} break;
        }
    }

    m_renderer.DisableClip();
}

bool TinyGUI::Button(const std::string& name, Rect bounds, const std::string& text, const std::optional<Color>& color) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);
    m_renderer.DrawStyle9Patch(WidgetStateToSprite(wid.state), color.value_or(baseColor), bounds, m_state.targetLayer);

    auto [tw, th] = m_renderer.GetTextSize(text).AsPair();

    Color textColor = GetBestForegroundColor(color);
    if (wid.state == WidgetState::Active) {
        textColor = { 255, 255, 255, 255 };
	}

    if (color.has_value()) {
        Rect innerBounds = bounds.Expand(-3);
        m_renderer.DrawFillRect(color.value(), innerBounds, m_state.targetLayer);
	}

    m_renderer.DrawText(
        text,
		textColor,
		{ bounds.x + bounds.width / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height },
        m_state.targetLayer
    );

    return wid.state == WidgetState::Clicked;
}

bool TinyGUI::Toggle(const std::string& name, Rect bounds, const std::string& text, bool& value) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);
    m_renderer.DrawStyle9Patch(WidgetStateToSprite(!value ? wid.state : WidgetState::Active), baseColor, bounds, m_state.targetLayer);

    if (wid.state == WidgetState::Clicked) {
        value = !value;
    }

    auto [tw, th] = m_renderer.GetTextSize(text).AsPair();

    Color textColor = GetBestForegroundColor();
    if (wid.state == WidgetState::Active) {
        textColor = { 255, 255, 255, 255 };
    }

    m_renderer.DrawText(
        text,
        value ? Color{ 255, 255, 255, 255 } : textColor,
        Rect{ bounds.x + bounds.width / 2 - tw / 2, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height },
        m_state.targetLayer
    );

    return wid.state == WidgetState::Clicked;
}

bool TinyGUI::Slider(
    const std::string& name, Rect bounds,
    int& value, int min, int max, int step,
    const std::optional<Color>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SliderImpl<int>(name, bounds, value, min, max, step, bg);
}

bool TinyGUI::SliderF(
    const std::string& name,
    Rect bounds,
    float& value, float min, float max, float step,
    const std::optional<Color>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SliderImpl<float>(name, bounds, value, min, max, step, bg);
}

bool TinyGUI::Spinner(
    const std::string& name,
    Rect bounds,
    int& value, int min, int max, int step,
    const std::string& fmt,
    const std::optional<Color>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SpinnerImpl<int>(
		name, bounds,
		[&](int& val, int inc) { val += inc; },
        value, min, max, step, fmt, bg
	);
}

bool TinyGUI::SpinnerF(
    const std::string& name,
    Rect bounds,
    float& value, float min, float max, float step,
    const std::string& fmt,
    const std::optional<Color>& bg
) {
    if (CurrentFrameIsCollapsed()) return false;
    return SpinnerImpl<float>(
		name, bounds,
		[&](float& val, float inc) { val += inc; },
        value, min, max, step, fmt, bg
	);
}

bool TinyGUI::EditBox(const std::string& name, Rect bounds, std::string& text) {
    if (CurrentFrameIsCollapsed()) return false;
    
    auto& wid = GetWidget(name, bounds);

    const auto light = Color{ 255, 255, 255, 255 };
    bool textChanged = false;
    bool focused = m_state.focusedId == wid.id;

    m_renderer.DrawStyle9Patch(GuiMapSprite::ButtonActive, baseColor, bounds, m_state.targetLayer);

    if (focused && !m_state.textInputActive) {
        m_state.textInput = text;
        m_state.textInputCursor = text.size();
        m_state.textInputActive = true;
    }

    // text entry
    if (focused) {
        textChanged = m_state.textInput != text;
        text = m_state.textInput;
    }

    auto sz = m_renderer.GetTextSize(text.substr(0, m_state.textInputCursor));
    int cursorX = bounds.x + 1 + sz.x;
    int textViewOffsetX = 0;

    // cursor is out of bounds?
    if (cursorX - textViewOffsetX > (bounds.x + bounds.width - 4) - 4 && focused) {
		textViewOffsetX = cursorX - (bounds.x + bounds.width - 4) + 4;
	}

    auto [tw, th] = m_renderer.GetTextSize(text).AsPair();

    int textX = bounds.x + 4 - textViewOffsetX;
    m_renderer.EnableClip(bounds.Expand(-3), m_state.targetLayer);
    m_renderer.DrawText(
        text,
        light,
        Rect{ textX, bounds.y + bounds.height / 2 - th / 2, bounds.width, bounds.height },
        m_state.targetLayer
    );
    m_renderer.DisableClip();

    // draw cursor
    if (focused && m_state.blink) {
        auto [curW, curH] = m_renderer.GetTextSize("|").AsPair();
        m_renderer.DrawText(
            "|",
            light,
            { cursorX - textViewOffsetX, bounds.y + bounds.height / 2 - curH / 2 - 1, 1, 1 },
            m_state.targetLayer
        );
    }

    if (!focused && m_state.textInputActive) {
        m_state.textInputActive = false;
	}

    return textChanged;
}

void TinyGUI::Image(const std::string& name, Rect bounds, Texture* texture) {
    if (CurrentFrameIsCollapsed()) return;
    
    auto id = std::hash<std::string>()(name);
    m_renderer.DrawStyle9Patch(GuiMapSprite::ButtonActive, baseColor, bounds, m_state.targetLayer);

    auto size = texture->Size();

	// calculate image rect maintain aspect ratio 
    float aspect = 1.0f;
    if (size.x > size.y) {
        aspect = float(size.y) / size.x;
	}
	else {
		aspect = float(size.x) / size.y;
	}

    int width = bounds.width - 4;
	int height = int(width * aspect);

	if (height > bounds.height - 4) {
		height = bounds.height - 4;
		width = int(height / aspect);
	}

	int x = bounds.x + bounds.width / 2 - width / 2;
	int y = bounds.y + bounds.height / 2 - height / 2;

    m_renderer.DrawImage(texture, { x, y, width, height }, m_state.targetLayer);
}

void TinyGUI::TabBar(const std::string& name, Rect bounds, std::string* tabs, size_t numTabs, size_t& selected) {
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
        auto [tw, th] = m_renderer.GetTextSize(tabs[index]).AsPair();

        auto wid = GetWidget(name + "_tab" + std::to_string(index), tabRect);
        if (wid.state == WidgetState::Clicked) {
            selected = index;
        }

        tabRect.y += offsetY;
        tabRect.height -= offsetY;

        m_renderer.DrawStyle9Patch(
            GuiMapSprite::ButtonIdle,
            baseColor,
            tabRect,
            m_state.targetLayer,
            0b00011111
        );

        m_renderer.DrawText(
            tabs[index],
            fg,
            {
                tabRect.x + tabRect.width / 2 - tw / 2,
                tabRect.y + tabRect.height / 2 - th / 2,
                tabRect.width, tabRect.height
            },
            m_state.targetLayer
        );
    };

    Rect selectedTabRect{};
    int offX = 3;
    for (size_t i = tabBar.startIndex; i < numTabs; i++) {
        auto [tw, th] = m_renderer.GetTextSize(tabs[i]).AsPair();
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
        m_renderer.DrawStyleSprite(
            GuiMapSprite::ArrowRight,
            GetBestForegroundColor(),
            Rect{ nextButton.x + nextButton.width / 2 - 4, nextButton.y + nextButton.height / 2 - 4 + 1, 8, 8 },
            m_state.targetLayer
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
        m_renderer.DrawStyleSprite(
			GuiMapSprite::ArrowLeft,
			GetBestForegroundColor(),
			Rect{ prevButton.x + prevButton.width / 2 - 4, prevButton.y + prevButton.height / 2 - 4 + 1, 8, 8 },
            m_state.targetLayer
		);
	}

    m_renderer.DrawLine(
        Color{ 0, 0, 0, 255 },
        { bounds.x, bounds.y + bounds.height },
        { bounds.x + bounds.width, bounds.y + bounds.height },
        m_state.targetLayer
    );
}

bool TinyGUI::MakePopup(
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

        width = std::max(width, m_renderer.GetTextSize(item).x);

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

void TinyGUI::ShowPopup(const std::string& name, Vector2i position) {
	auto id = std::hash<std::string>()(name);
	auto&& pos = m_popups.find(id);
	if (pos == m_popups.end()) {
        return;
	}

	auto& popup = pos->second;
	popup.position = position;

    auto screenSize = m_renderer.GetScreenSize();
    if (popup.position.x + popup.size.x > screenSize.x) {
		popup.position.x = screenSize.x - popup.size.x;
	}

    if (popup.position.y + popup.size.y > screenSize.y) {
		popup.position.y = screenSize.y - popup.size.y;
	}

    m_state.openPopup = id;
}

void TinyGUI::ShowPopup(const std::string& name) {
    ShowPopup(name, m_state.lastClickedWidgetPosition);
}

void TinyGUI::OnCreate() {
    m_renderer.Init();
#ifdef TINYGUI_PGEX
    m_renderer.SetPGE(m_pge);
#endif

    auto screenSize = m_renderer.GetScreenSize();
    m_rectStack.push_back(Rect{ 0, 0, int(screenSize.x), int(screenSize.y) });

#ifdef TINYGUI_PGEX
    m_panelsLayer = m_pge->CreateLayer();
    m_pge->EnableLayer(m_panelsLayer, true);

    m_widgetsLayer = m_pge->CreateLayer();
    m_pge->EnableLayer(m_widgetsLayer, true);
#endif

    SetTargetLayer(m_widgetsLayer);
}

bool TinyGUI::OnUpdate(float deltaTime) {
    if (m_rectStack.empty()) {
        auto screenSize = m_renderer.GetScreenSize();
        m_rectStack.push_back(Rect{ 0, 0, int(screenSize.x), int(screenSize.y) });
    }

    if (!m_state.mouseDown) m_state.hoveredId = 0;

    for (auto&& [wid, widget] : m_widgets) {
        widget.pressed = false;
        widget.released = false;
	}

#ifdef TINYGUI_PGEX
    m_pge->SetPixelMode(olc::Pixel::Mode::ALPHA);

    m_pge->SetDrawTarget(nullptr);
    m_pge->Clear(olc::BLANK);

    m_pge->SetDrawTarget(m_panelsLayer);
    m_pge->Clear(olc::BLANK);

    m_pge->SetDrawTarget(m_widgetsLayer);
    m_pge->Clear(olc::BLANK);

    SetTargetLayer(m_widgetsLayer);
#endif

    RenderDockingAreas();

	return false;
}

void TinyGUI::OnFinalize(float deltaTime) {
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
                PrepareDrag(frame.positionOffset);
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
            m_renderer.DrawStyle9Patch(
                GuiMapSprite::Selection,
                Color(18, 101, 255, 160),
                m_dockingAreas[dockId],
                m_state.targetLayer
            );
        }
    }

    //////

    DrawPopups();
    m_renderer.RenderAll();

    if (!m_state.mouseDown) {
        m_state.activeId = 0;
    }

    m_rectStack.clear();

    m_state.blinkTimer += deltaTime;
    if (m_state.blinkTimer >= 0.4f) {
        m_state.blink = !m_state.blink;
        m_state.blinkTimer = 0.0f;
	}

    m_state.mouseDelta = { 0, 0 };
}

void TinyGUI::OnEvent(InputEvent ev) {
    switch (ev.type) {
        case InputEvent::Type::MouseDown: {
            m_state.mouseDown = true;
            m_state.dragging = true;
            m_state.dragStart = ev.mousePos;
        } break;
        case InputEvent::Type::MouseUp: {
			m_state.mouseDown = false;
            m_state.dragging = false;
		} break;
        case InputEvent::Type::MouseMove: {
            m_state.mouseDelta = ev.mousePos - m_state.mousePos;
			m_state.mousePos = ev.mousePos;

            if (m_state.dragging) {
                m_state.dragOffset = m_state.mousePos - m_state.dragStart;
            }
		} break;
        case InputEvent::Type::TextInput: {
            if (m_state.textInputActive) {
                m_state.textInput.insert(m_state.textInput.begin() + m_state.textInputCursor, ev.keyChar);
                m_state.textInputCursor++;
            }
        } break;
        case InputEvent::Type::Backspace: {
            auto textBeforeCursor = m_state.textInput.substr(0, m_state.textInputCursor);
            if (m_state.textInputActive && m_state.textInputCursor > 0 && !textBeforeCursor.empty()) {
                m_state.textInput.erase(m_state.textInput.begin() + m_state.textInputCursor - 1);
                m_state.textInputCursor--;
			}
        } break;
        case InputEvent::Type::Delete: {
			auto textAfterCursor = m_state.textInput.substr(m_state.textInputCursor);
            if (m_state.textInputActive && m_state.textInputCursor < m_state.textInput.size() && !textAfterCursor.empty()) {
                m_state.textInput.erase(m_state.textInput.begin() + m_state.textInputCursor);
            }
        } break;
        case InputEvent::Type::Left: {
			if (m_state.textInputActive && m_state.textInputCursor > 0) {
				m_state.textInputCursor--;
			}
		} break;
        case InputEvent::Type::Right: {
            if (m_state.textInputActive && m_state.textInputCursor < m_state.textInput.size()) {
                m_state.textInputCursor++;
            }
        } break;
        case InputEvent::Type::Home: {
			if (m_state.textInputActive) {
				m_state.textInputCursor = 0;
			}
		} break;
        case InputEvent::Type::End: {
			if (m_state.textInputActive) {
				m_state.textInputCursor = m_state.textInput.size();
			}
		} break;
    }
}

void TinyGUI::BeginFrame(
    const std::string& name,
    const std::string& title,
    const Vector2i& position,
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
    fram.insertId = m_renderer.GetDrawCommandCount();
    fram.collapsible = collapsible;
    fram.fixed = fixed;

    auto [tw, th] = m_renderer.GetTextSize(title).AsPair();

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

Rect TinyGUI::EndFrame() {
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

    auto [tw, th] = m_renderer.GetTextSize(frame.title).AsPair();
    m_renderer.DrawText(
        frame.title, light,
        Rect{ frameBounds.x + 6, frameBounds.y + 2 + (FrameTitleHeight / 2 - th / 2), frameBounds.width - 4, FrameTitleHeight },
        m_state.targetLayer,
        frame.insertId
    );

    m_renderer.DrawFillRect(
        titleBgColor,
        titleBounds,
        m_state.targetLayer,
        frame.insertId
    );

    m_renderer.DrawStyle9Patch(
        GuiMapSprite::Frame,
        baseColor,
        frameBounds,
        m_state.targetLayer,
        0xFF,
        frame.insertId
    );

    m_renderer.DrawStyle9Patch(
        GuiMapSprite::Shadow,
        baseColor,
        Rect{ frameBounds.x + 3, frameBounds.y + 3, frameBounds.width, frameBounds.height },
        m_state.targetLayer,
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
        m_renderer.DrawStyleSprite(
            frame.collapsed ? GuiMapSprite::ArrowDown : GuiMapSprite::ArrowUp,
            GetBestForegroundColor(),
            Rect{ collapseButtonBounds.x + centerOff - 1, collapseButtonBounds.y + centerOff + 1, 8, 8 },
            m_state.targetLayer
        );
        m_state.ignoreCollapsed = false;
    }

    PopRect();
    m_frameStack.pop_back();

    frame.bounds = frameBounds;
    
    // moving logic
    if (frame.dragging && !frame.fixed && IsDragging()) {
        frame.positionOffset = GetDragPosition();
    }

    SetTargetLayer(m_widgetsLayer);

    return frameBounds;
}

void TinyGUI::PushRect(Rect rect) {
    if (CurrentFrameIsCollapsed()) return;
	m_rectStack.push_back(rect);
}

Rect& TinyGUI::PeekRect() {
	return m_rectStack.back();
}

void TinyGUI::PopRect() {
    if (CurrentFrameIsCollapsed()) return;
	m_rectStack.pop_back();
}

Rect TinyGUI::RectCutLeft(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
    Rect& orig = PeekRect();
    Rect rec{ orig.x, orig.y, amount, orig.height };
    orig.x += amount;
    orig.width -= amount;
    return rec;
}

Rect TinyGUI::RectCutRight(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x + orig.width - amount, orig.y, amount, orig.height };
	orig.width -= amount;
	return rec;
}

Rect TinyGUI::RectCutTop(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x, orig.y, orig.width, amount };
	orig.y += amount;
	orig.height -= amount;
	return rec;
}

Rect TinyGUI::RectCutBottom(int amount) {
    if (CurrentFrameIsCollapsed()) return Rect{};
	Rect& orig = PeekRect();
	Rect rec{ orig.x, orig.y + orig.height - amount, orig.width, amount };
	orig.height -= amount;
	return rec;
}

void TinyGUI::AddDockingArea(const std::string& name, const Rect& rect) {
    m_dockingAreas[utils::GetIDFromName(name)] = rect;
}

void TinyGUI::AddDockingAreaLeft(const std::string& name, int size) {
    PushRect(RectCutLeft(size));
    AddDockingArea(name, PeekRect());
    PopRect();
}

void TinyGUI::AddDockingAreaRight(const std::string& name, int size) {
    PushRect(RectCutRight(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void TinyGUI::AddDockingAreaTop(const std::string& name, int size) {
    PushRect(RectCutTop(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void TinyGUI::AddDockingAreaBottom(const std::string& name, int size) {
    PushRect(RectCutBottom(size));
	AddDockingArea(name, PeekRect());
	PopRect();
}

void TinyGUI::AddDockingAreaRemainingSpace(const std::string& name) {
    AddDockingArea(name, PeekRect());
}

TinyGUI::Widget& TinyGUI::GetWidget(const std::string& name, Rect bounds, bool blockInputByPopup) {
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

void TinyGUI::PrepareDrag(Vector2i elementPosition) {
    m_state.dragStart = m_state.mousePos;
    m_state.dragOffset = { 0, 0 };
    m_state.dragCorrection = m_state.mousePos - elementPosition;
}

TinyGUI::Widget& TinyGUI::GetWidgetByName(const std::string& name) {
    auto id = std::hash<std::string>()(name);
    auto pos = m_widgets.find(id);
    if (pos == m_widgets.end()) {
        m_widgets[id] = Widget{};
        pos = m_widgets.find(id);
    }
    return pos->second;
}

Color TinyGUI::PixelBrightness(Color color, float amount) {
    auto fnPerc = [amount](float value) {
        return std::clamp(value * amount, 0.0f, 1.0f);
    };

    const float r = float(color.r) / 255.0f;
    const float g = float(color.g) / 255.0f;
    const float b = float(color.b) / 255.0f;
    const float a = float(color.a) / 255.0f;
    return Color::FromFloat(fnPerc(r), fnPerc(g), fnPerc(b), a);
}

GuiMapSprite TinyGUI::WidgetStateToSprite(WidgetState state) {
    switch (state) {
		case WidgetState::Hovered: return GuiMapSprite::ButtonHovered;
		case WidgetState::Active:
		case WidgetState::Clicked: return GuiMapSprite::ButtonActive;
		default: return GuiMapSprite::ButtonIdle;
	}
}

Color TinyGUI::GetBestForegroundColor(const std::optional<Color>& bgColor) {
    Color bg = bgColor.value_or(baseColor);
    return utils::Luma(bg) > 0.5f ? Color{ 0, 0, 0, 255 } : Color{ 255, 255, 255, 255 };
}

size_t TinyGUI::NearestDockingArea(const Rect& bounds) {
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

bool TinyGUI::IsDockingAreaFree(size_t id) {
    for (auto&& [fid, frame] : m_frames) {
        if (frame.dockId == id) return false;
    }
    return true;
}

void TinyGUI::SetTargetLayer(uint32_t layer) {
    m_state.targetLayer = layer;
}

void TinyGUI::DrawPopups() {
    const int paddingX = 8;
    const int paddingY = 5;

#ifdef TINYGUI_PGEX
    m_pge->SetDrawTarget(nullptr);
#endif

    for (auto&& [wid, popup] : m_popups) {
        if (m_state.openPopup != wid) continue;

        int width = 0, height = 0;
        for (size_t i = 0; i < popup.items.size(); i++) {
            auto item = popup.items[i];
            auto [tw, th] = m_renderer.GetTextSize(item).AsPair();

            width = std::max(width, tw);

            if (item.find_first_not_of('-') == std::string::npos) {
                height += PopupItemHeight / 2;
            }
            else {
                height += PopupItemHeight;
            }
        }

        Rect bounds{ popup.position.x, popup.position.y, width + paddingX * 2, height + paddingY * 2 };

        m_renderer.DrawStyle9Patch(
            GuiMapSprite::Shadow,
            Color{ 255, 255, 255, 255 },
            Rect{ bounds.x + 3, bounds.y + 3, bounds.width, bounds.height },
            0,
            0xFF
        );
        m_renderer.DrawStyle9Patch(
            GuiMapSprite::Panel,
            Color{ 255, 255, 255, 255 },
            bounds,
            0,
            0xFF
        );

        const auto light = PixelBrightness(baseColor, 2.5f);
        const auto dark = PixelBrightness(baseColor, 0.15f);

        int y = bounds.y + paddingY;
        for (size_t i = 0; i < popup.items.size(); i++) {
            auto item = popup.items[i];

            if (item.find_first_not_of('-') == std::string::npos) {
                m_renderer.DrawLine(
                    PixelBrightness(baseColor, 0.5f),
                    Vector2i{ (bounds.x + 3), (y + PopupItemHeight / 4) },
                    Vector2i{ (bounds.x + bounds.width - 3), (y + PopupItemHeight / 4) },
                    0
                );
                y += PopupItemHeight / 2;
                continue;
            }

            Rect wdBounds{ bounds.x, y, bounds.width, PopupItemHeight };
            auto wd = GetWidgetByName(item + popup.name);
            
            Color fgColor = dark;
            switch (wd.state) {
                case WidgetState::Hovered:
                case WidgetState::Active:
                case WidgetState::Clicked:
                    fgColor = light;
                    m_renderer.DrawFillRect(dark, wdBounds, 0);
                    break;
                default: break;
            }

            auto [tw, th] = m_renderer.GetTextSize(item).AsPair();
            m_renderer.DrawText(
                item,
                fgColor,
				{ bounds.x + paddingX, y + PopupItemHeight / 2 - th / 2, bounds.width, bounds.height },
                0
            );

            y += PopupItemHeight;
        }
    }
}

#ifdef TINYGUI_PGEX
void olcPGEX_TinyGUI::OnBeforeUserCreate() {
    SetPGE(this->pge);
    OnCreate();
}

bool olcPGEX_TinyGUI::OnBeforeUserUpdate(float& fElapsedTime) {
    // input handling
    
    if (pge->GetMouse(0).bHeld) {
        InputEvent ev;
		ev.type = InputEvent::Type::MouseDown;
		ev.mousePos = { pge->GetMouseX(), pge->GetMouseY() };
		OnEvent(ev);
        m_mouseWasDown = true;
    }
    else {
        if (m_mouseWasDown) {
            InputEvent ev;
			ev.type = InputEvent::Type::MouseUp;
			ev.mousePos = { pge->GetMouseX(), pge->GetMouseY() };
			OnEvent(ev);
            m_mouseWasDown = false;
        }
    }
    
    auto mousePos = pge->GetMousePos();
    if (mousePos - m_prevMousePos != olc::vi2d{ 0, 0 }) {
        InputEvent ev;
        ev.type = InputEvent::Type::MouseMove;
        ev.mousePos = { pge->GetMouseX(), pge->GetMouseY() };
        OnEvent(ev);
    }

    bool textEdited = false;
    if (pge->GetKey(olc::Key::BACK).bPressed) {
		InputEvent ev;
		ev.type = InputEvent::Type::Backspace;
		OnEvent(ev);
        textEdited = true;
	} else if (pge->GetKey(olc::Key::DEL).bPressed) {
        InputEvent ev;
        ev.type = InputEvent::Type::Delete;
        OnEvent(ev);
        textEdited = true;
    } else if (pge->GetKey(olc::Key::LEFT).bPressed) {
        InputEvent ev;
		ev.type = InputEvent::Type::Left;
		OnEvent(ev);
        textEdited = true;
	} else if (pge->GetKey(olc::Key::RIGHT).bPressed) {
		InputEvent ev;
		ev.type = InputEvent::Type::Right;
		OnEvent(ev);
        textEdited = true;
	} else if (pge->GetKey(olc::Key::HOME).bPressed) {
		InputEvent ev;
		ev.type = InputEvent::Type::Home;
		OnEvent(ev);
        textEdited = true;
	} else if (pge->GetKey(olc::Key::END).bPressed) {
		InputEvent ev;
		ev.type = InputEvent::Type::End;
		OnEvent(ev);
        textEdited = true;
	}

    // text input
    if (m_state.textInputActive && !pge->IsTextEntryEnabled()) {
        pge->TextEntryEnable(true, m_state.textInput);
    }
    else if (!m_state.textInputActive && pge->IsTextEntryEnabled()) {
		pge->TextEntryEnable(false);
	}

    m_state.textInputCursor = pge->TextEntryGetCursor();
    m_state.textInput = pge->TextEntryGetString();

    m_prevMousePos = mousePos;
    return OnUpdate(fElapsedTime);
}

void olcPGEX_TinyGUI::OnAfterUserUpdate(float fElapsedTime) {
    OnFinalize(fElapsedTime);
}
#endif

float utils::Luma(const Color& color) {
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

uint32_t utils::GetCodepoint(const std::string& text, uint32_t pos, uint32_t& out) {
    char c1 = text[pos];

    // is high surrogate?
    if ((c1 & 0xFC00) == 0xD800 && pos + 1 < text.size()) {
        char c2 = text[pos + 1];
        // is low surrogate?
        if ((c2 & 0xFC00) == 0xDC00) {
            out = uint32_t(c1) << 10 + uint32_t(c2) - 0x35FDC00;
            return 2;
		}
    }

    out = uint32_t(c1);
    return 1;
}

#endif
