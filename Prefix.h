/*
 * Prefix.h
 * Created by Alexander Strange on 7/9/09.
 *
 * This file is part of Perian.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <tgmath.h>

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#ifdef _cplusplus
#include <new>
#include <vector>
#include <string>
#include "matroska/KaxBlock.h"
#endif

#ifndef __LP64__
#include <QuickTime/QuickTime.h>
#endif
#include <Carbon/Carbon.h>
