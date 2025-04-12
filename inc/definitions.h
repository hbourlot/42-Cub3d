/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:19:52 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 21:35:00 by hbourlot         ###   ########.fr       */
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
#define VPL "NSWE"            // valid player location
#define IPL " \t\n\v\f\r\a\b" // Ingnore player location

#define  PI 3.1415926535
#define P2 PI / 2
#define P3 3 * PI / 2
#define DR 0.0174533 // one degree in radians

#define S_WIDTH 1280
#define S_HEIGHT 900

#define FOV PI / 3


#define SPEED 2.0
#define KEY_ROT_SPEED DR * 5
#define MOUSE_ROT_SPEED DR * 1.5

// world vars
#define TILE_SIZE 16
#define WALL_SIZE 64

// others
#define EPSILON 0.000001

//
#define KEY_SIGNAL 1
#define MOUSE_SIGNAL 2

