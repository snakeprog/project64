/***************************************************************************
*                                                                          *
* Project64-video - A Nintendo 64 gfx plugin.                              *
* http://www.pj64-emu.com/                                                 *
* Copyright (C) 2017 Project64. All rights reserved.                       *
* Copyright (C) 2003-2009  Sergey 'Gonetz' Lipski                          *
* Copyright (C) 2002 Dave2001                                              *
*                                                                          *
* License:                                                                 *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                       *
* version 2 of the License, or (at your option) any later version.         *
*                                                                          *
****************************************************************************/

#pragma once
#include <Common/stdtypes.h>

typedef uint8_t gfxAlpha_t;
typedef uint32_t gfxCCUColor_t;
typedef uint32_t gfxACUColor_t;
typedef uint32_t gfxTCCUColor_t;
typedef uint32_t gfxTACUColor_t;

enum gfxCombineMode_t
{
    GFX_FUNC_MODE_ZERO = 0x00,
    GFX_FUNC_MODE_X = 0x01,
    GFX_FUNC_MODE_ONE_MINUS_X = 0x02,
    GFX_FUNC_MODE_NEGATIVE_X = 0x03,
    GFX_FUNC_MODE_X_MINUS_HALF = 0x04,
};

enum gfxLOD_t
{
    GFX_LOD_LOG2_1 = 0x0,
    GFX_LOD_LOG2_2 = 0x1,
    GFX_LOD_LOG2_4 = 0x2,
    GFX_LOD_LOG2_8 = 0x3,
    GFX_LOD_LOG2_16 = 0x4,
    GFX_LOD_LOG2_32 = 0x5,
    GFX_LOD_LOG2_64 = 0x6,
    GFX_LOD_LOG2_128 = 0x7,
    GFX_LOD_LOG2_256 = 0x8,
    GFX_LOD_LOG2_512 = 0x9,
    GFX_LOD_LOG2_1024 = 0xa,
    GFX_LOD_LOG2_2048 = 0xb,
};

enum gfxBuffer_t
{
    GFX_BUFFER_FRONTBUFFER = 0x0,
    GFX_BUFFER_BACKBUFFER = 0x1,
    GFX_BUFFER_AUXBUFFER = 0x2,
    GFX_BUFFER_DEPTHBUFFER = 0x3,
    GFX_BUFFER_ALPHABUFFER = 0x4,
    GFX_BUFFER_TRIPLEBUFFER = 0x5,
    GFX_BUFFER_TEXTUREBUFFER_EXT = 0x6,
    GFX_BUFFER_TEXTUREAUXBUFFER_EXT = 0x7,
};

enum gfxTextureFormat_t
{
    GFX_TEXFMT_8BIT = 0x0,
    GFX_TEXFMT_RGB_332 = GFX_TEXFMT_8BIT,
    GFX_TEXFMT_YIQ_422 = 0x1,
    GFX_TEXFMT_ALPHA_8 = 0x2, /* (0..0xFF) alpha     */
    GFX_TEXFMT_INTENSITY_8 = 0x3, /* (0..0xFF) intensity */
    GFX_TEXFMT_ALPHA_INTENSITY_44 = 0x4,
    GFX_TEXFMT_P_8 = 0x5, /* 8-bit palette */
    GFX_TEXFMT_RSVD0 = 0x6, /* GFX_TEXFMT_P_8_RGBA */
    GFX_TEXFMT_P_8_6666 = GFX_TEXFMT_RSVD0,
    GFX_TEXFMT_P_8_6666_EXT = GFX_TEXFMT_RSVD0,
    GFX_TEXFMT_RSVD1 = 0x7,
    GFX_TEXFMT_16BIT = 0x8,
    GFX_TEXFMT_ARGB_8332 = GFX_TEXFMT_16BIT,
    GFX_TEXFMT_AYIQ_8422 = 0x9,
    GFX_TEXFMT_RGB_565 = 0xa,
    GFX_TEXFMT_ARGB_1555 = 0xb,
    GFX_TEXFMT_ARGB_4444 = 0xc,
    GFX_TEXFMT_ALPHA_INTENSITY_88 = 0xd,
    GFX_TEXFMT_AP_88 = 0xe, /* 8-bit alpha 8-bit palette */
    GFX_TEXFMT_RSVD2 = 0xf,
    GFX_TEXFMT_RSVD4 = GFX_TEXFMT_RSVD2,
    GFX_TEXFMT_ARGB_CMP_FXT1 = 0x11,
    GFX_TEXFMT_ARGB_8888 = 0x12,
    GFX_TEXFMT_YUYV_422 = 0x13,
    GFX_TEXFMT_UYVY_422 = 0x14,
    GFX_TEXFMT_AYUV_444 = 0x15,
    GFX_TEXFMT_ARGB_CMP_DXT1 = 0x16,
    GFX_TEXFMT_ARGB_CMP_DXT2 = 0x17,
    GFX_TEXFMT_ARGB_CMP_DXT3 = 0x18,
    GFX_TEXFMT_ARGB_CMP_DXT4 = 0x19,
    GFX_TEXFMT_ARGB_CMP_DXT5 = 0x1A,
    GFX_TEXFMT_RGB_888 = 0xFF,
    GFX_TEXFMT_GZ = 0x8000,
};

enum GFX_CMBX
{
    GFX_CMBX_ZERO = 0x00,
    GFX_CMBX_TEXTURE_ALPHA = 0x01,
    GFX_CMBX_ALOCAL = 0x02,
    GFX_CMBX_AOTHER = 0x03,
    GFX_CMBX_B = 0x04,
    GFX_CMBX_CONSTANT_ALPHA = 0x05,
    GFX_CMBX_CONSTANT_COLOR = 0x06,
    GFX_CMBX_DETAIL_FACTOR = 0x07,
    GFX_CMBX_ITALPHA = 0x08,
    GFX_CMBX_ITRGB = 0x09,
    GFX_CMBX_LOCAL_TEXTURE_ALPHA = 0x0a,
    GFX_CMBX_LOCAL_TEXTURE_RGB = 0x0b,
    GFX_CMBX_LOD_FRAC = 0x0c,
    GFX_CMBX_OTHER_TEXTURE_ALPHA = 0x0d,
    GFX_CMBX_OTHER_TEXTURE_RGB = 0x0e,
    GFX_CMBX_TEXTURE_RGB = 0x0f,
    GFX_CMBX_TMU_CALPHA = 0x10,
    GFX_CMBX_TMU_CCOLOR = 0x11,
};

