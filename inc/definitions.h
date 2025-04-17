/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:19:52 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/17 15:02:34 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

#define NORTH "NO"
#define SOUTH "SO"
#define WEST "WE"
#define EAST "EA"
#define CMP_OK 0

#define VPL "NSWE"            // valid player location
#define IPL " \t\n\v\f\r\a\b" // Ingnore player location

#define PI 3.1415926535
// #define P2 (PI / 2)
// #define P3 (3 * PI / 2)
// #define FOV PI / 3
#define DR 0.0174533 // one degree in radians

#define S_WIDTH 1280
#define S_HEIGHT 900

#define SPEED 2.0
// #define KEY_ROT_SPEED DR * 5
// #define MOUSE_ROT_SPEED DR * 1.5
#define KEY_ROT_SPEED DR
#define MOUSE_ROT_SPEED DR

#define TILE_SIZE 16

#define KEY_SIGNAL 1
#define MOUSE_SIGNAL 2
