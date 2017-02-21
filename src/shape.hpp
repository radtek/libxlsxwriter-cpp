#ifndef __LXW_SHAPE_H__
#define __LXW_SHAPE_H__

#include "common.hpp"
#include <stdint.h>
#include "format.hpp"

namespace xlsxwriter {

enum lxw_dash_types {
    LXW_DASH_SOLID,
    LXW_DASH_ROUND_BOT,
    LXW_DASH_SQUARE_DOT,
    LXW_DASH_DASH,
    LXW_DASH_DASH_DOT,
    LXW_DASH_LONG_DASH,
    LXW_DASH_LONG_DASH_DOT,
    LXW_DASH_LONG_DASH_DOT_DOT,
    LXW_DASH_DOT,
    LXW_DASH_SYSTEM_DASH_DOT,
    LXW_DASH_SYSTEM_DASH_DOT_DOT
};

enum lxw_shape_pattern_types {
    LXW_SHAPE_PATTERN_PERCENT_5,
    LXW_SHAPE_PATTERN_PERCENT_10,
    LXW_SHAPE_PATTERN_PERCENT_20,
    LXW_SHAPE_PATTERN_PERCENT_25,
    LXW_SHAPE_PATTERN_PERCENT_30,
    LXW_SHAPE_PATTERN_PERCENT_40,
    LXW_SHAPE_PATTERN_PERCENT_50,
    LXW_SHAPE_PATTERN_PERCENT_60,
    LXW_SHAPE_PATTERN_PERCENT_70,
    LXW_SHAPE_PATTERN_PERCENT_75,
    LXW_SHAPE_PATTERN_PERCENT_80,
    LXW_SHAPE_PATTERN_PERCENT_90,
    LXW_SHAPE_PATTERN_LIGHT_DOWNWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_LIGHT_UPWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_DARK_DOWNWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_DARK_UPWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_WIDE_DOWNWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_WIDE_UPWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_LIGHT_VERTICAL,
    LXW_SHAPE_PATTERN_LIGHT_HORIZONTAL,
    LXW_SHAPE_PATTERN_NARROW_VERTICAL,
    LXW_SHAPE_PATTERN_NARROW_HORIZONTAL,
    LXW_SHAPE_PATTERN_DARK_VERTICAL,
    LXW_SHAPE_PATTERN_DARK_HORIZONTAL,
    LXW_SHAPE_PATTERN_DASHED_DOWNWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_DASHED_UPWARD_DIAGONAL,
    LXW_SHAPE_PATTERN_DASHED_HORIZONTAL,
    LXW_SHAPE_PATTERN_DASHED_VERTICAL,
    LXW_SHAPE_PATTERN_SMALL_CONFETTI,
    LXW_SHAPE_PATTERN_LARGE_CONFETTI,
    LXW_SHAPE_PATTERN_ZIGZAG,
    LXW_SHAPE_PATTERN_WAVE,
    LXW_SHAPE_PATTERN_DIAGONAL_BRICK,
    LXW_SHAPE_PATTERN_HORIZONTAL_BRICK,
    LXW_SHAPE_PATTERN_WEAVE,
    LXW_SHAPE_PATTERN_PLAID,
    LXW_SHAPE_PATTERN_DIVOT,
    LXW_SHAPE_PATTERN_DOTTED_GRID,
    LXW_SHAPE_PATTERN_DOTTED_DIAMON,
    LXW_SHAPE_PATTERN_SHINGLE,
    LXW_SHAPE_PATTERN_TRELLIS,
    LXW_SHAPE_PATTERN_SPHERE,
    LXW_SHAPE_PATTERN_SMALL_GRID,
    LXW_SHAPE_PATTERN_LARGE_GRID,
    LXW_SHAPE_PATTERN_SMALL_CHECK,
    LXW_SHAPE_PATTERN_LARGE_CHECK,
    LXW_SHAPE_PATTERN_OUTLINED_DIAMOND,
    LXW_SHAPE_PATTERN_SOLID_DIAMON
};

typedef struct lxw_pattern {
    uint8_t defined;
    uint8_t pattern;
    lxw_color_t fg_color;
    lxw_color_t bg_color;
} lxw_pattern;

typedef struct lxw_line {
    uint8_t defined;
    uint8_t none;
    uint8_t dash_type;
    lxw_color_t color;
    double transparency;
} lxw_line;

typedef struct lxw_shape_fill {
    uint8_t defined;
    uint8_t none;
    lxw_color_t color;
    double transparency;
} lxw_shape_fill;

typedef struct lxw_shape_properties {
    struct lxw_shape_fill fill;
    struct lxw_line line;
    struct lxw_pattern pattern;
} lxw_shape_properties;

} // namespace xlsxwriter

#endif
