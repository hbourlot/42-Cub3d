/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:19:52 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 22:13:52 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

#define NORTH "NO"
#define SOUTH "SO"
#define WEST "WE"
#define EAST "EA"
#define CMP_OK 0
#define IMG_WIDTH 256
#define IMG_HEIGHT 256
#define MAP_HEIGHT 768
#define MAP_WIDTH 1024
#define VPL "NSWE" // valid player location
#define IPL " \t\n\v\f\r\a\b" // Ingnore player location

#define  PI 3.1415926535
#define P2 PI / 2
#define P3 3 * PI / 2
#define DR 0.0174533 // one degree in radians

// SCREEN VARS
#define SCREEN_SCALE 3
#define SCREEN_WIDTH 320 * SCREEN_SCALE
#define SCREEN_HEIGHT 200 * SCREEN_SCALE

// PLANE VARS
#define GAME_SCALE 2 * SCREEN_SCALE
#define GAME_WIDTH SCREEN_WIDTH / GAME_SCALE
#define GAME_HEIGHT SCREEN_HEIGHT / GAME_SCALE

// OTHER PLANE VARS
#define FOV PI / 3
#define CANT_RAYS GAME_WIDTH / 4
#define ANGLE_PER_RAY  FOV / CANT_RAYS
#define RENDER_LINE_WIDTH GAME_WIDTH / CANT_RAYS
#define HORIZON  GAME_HEIGHT / 2

#define SPEED 2.0
#define ROT_SPEED DR * 5

// world vars
#define TILE_SIZE 16
#define WALL_SIZE 16
#define PLAYER_SIZE WALL_SIZE - 2

// others
#define EPSILON 0.000001
