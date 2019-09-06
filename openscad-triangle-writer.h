/*
 * Copyright 2019 Assaf Gordon <assafgordon@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 */
#ifndef __OPENSCAD_TRIANGLE_WRITER__
#define __OPENSCAD_TRIANGLE_WRITER__

void write_faces_scad (const Face_vector& faces);

void write_triangles_ascii_stl(const Face_vector& faces);

void write_triangle_scad(const Face_vector& faces);


#endif
