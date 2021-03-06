dnl Process this file with autoconf to produce a configure script.
dnl Configure input file for elfutils.
dnl
dnl Copyright (C) 2014 Petr Tesarik <ptesarik@suse.cz>
dnl
dnl This file is part of libkdumpfile.
dnl
dnl  This file is free software; you can redistribute it and/or modify
dnl  it under the terms of the GNU General Public License as published by
dnl  the Free Software Foundation; either version 3 of the License, or
dnl  (at your option) any later version.
dnl
dnl  libkdumpfile is distributed in the hope that it will be useful, but
dnl  WITHOUT ANY WARRANTY; without even the implied warranty of
dnl  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl  GNU General Public License for more details.
dnl
dnl  You should have received a copy of the GNU General Public License
dnl  along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_INIT([Library for reading kernel core dumps],
        [0.1.7],[ptesarik@suse.cz],[libkdumpfile])

AC_CONFIG_SRCDIR([src/diskdump.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([foreign dist-bzip2 -Wall])

AC_PROG_CC
AM_PROG_AR

LT_INIT

AC_SUBST(REQUIRES_PRIVATE)
AC_SUBST(LIBS_PRIVATE)

dnl This makes sure pkg.m4 is available.
m4_pattern_forbid([^_?PKG_[A-Z_]+$],[*** pkg.m4 missing, please install pkg-config])

kdump_COMPRESSION(zlib, ZLIB, z, uncompress)
kdump_COMPRESSION(lzo, LZO, lzo2, lzo1x_decompress_safe)
kdump_COMPRESSION(snappy, SNAPPY, snappy, snappy_uncompress)

AC_CONFIG_FILES([
	Makefile
	doc/Makefile
	examples/Makefile
	src/Makefile
	libkdumpfile.pc
])

AC_OUTPUT
