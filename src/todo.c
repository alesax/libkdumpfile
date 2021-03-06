/* TODO items - formats which are not yet supported.
   Copyright (C) 2014 Petr Tesarik <ptesarik@suse.cz>

   This file is free software; you can redistribute it and/or modify
   it under the terms of either

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at
       your option) any later version

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at
       your option) any later version

   or both in parallel, as here.

   libkdumpfile is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see <http://www.gnu.org/licenses/>.
*/

#define _GNU_SOURCE

#include "kdumpfile-priv.h"

#include <string.h>

static kdump_status
kvm_probe(kdump_ctx *ctx)
{
	static const char magic[] =
		{ 'Q', 'E', 'V', 'M' };

	if (memcmp(ctx->buffer, magic, sizeof magic))
		return kdump_unsupported;

	/* KVM dump not yet implemented */
	ctx->format = "KVM";
	return kdump_unsupported;
}

const struct format_ops kvm_ops = {
	.probe = kvm_probe,
};

static kdump_status
libvirt_probe(kdump_ctx *ctx)
{
	static const char magic[] =
		{ 'L', 'i', 'b', 'v' };

	if (memcmp(ctx->buffer, magic, sizeof magic))
		return kdump_unsupported;

	/* Libvirt dump not yet implemented */
	ctx->format = "Libvirt";
	return kdump_unsupported;
}

const struct format_ops libvirt_ops = {
	.probe = libvirt_probe,
};

static kdump_status
xc_save_probe(kdump_ctx *ctx)
{
	static const char magic[] =
		{ 'L', 'i', 'n', 'u', 'x', 'G', 'u', 'e',
		  's', 't', 'R', 'e', 'c', 'o', 'r', 'd' };

	if (memcmp(ctx->buffer, magic, sizeof magic))
		return kdump_unsupported;

	/* Xen xc_save not yet implemented */
	ctx->format = "Xen xc_save";
	return kdump_unsupported;
}

const struct format_ops xc_save_ops = {
	.probe = xc_save_probe,
};

static kdump_status
xc_core_probe(kdump_ctx *ctx)
{
	static const char magic[] =
		{ 0xeb, 0x0f, 0xf0 };
	unsigned char firstbyte;

	if (memcmp(ctx->buffer + 1, magic, sizeof magic))
		return kdump_unsupported;

	firstbyte = *(unsigned char*)ctx->buffer;
	if (firstbyte == 0xed)
		ctx->format = "Xen xc_core";
	else if (firstbyte == 0xee)
		ctx->format = "Xen xc_core hvm";
	else
		return kdump_unsupported;

	/* Xen xc_core not yet implemented */
	return kdump_unsupported;
}

const struct format_ops xc_core_ops = {
	.probe = xc_core_probe,
};

static kdump_status
mclxcd_probe(kdump_ctx *ctx)
{
	static const char magic[] =
		{ 0xdd, 0xcc, 0x8b, 0x9a };

	if (memcmp(ctx->buffer, magic, sizeof magic))
		return kdump_unsupported;

	/* MCLXCD dump not yet implemented */
	ctx->format = "MCLXCD";
	return kdump_unsupported;
}

const struct format_ops mclxcd_ops = {
	.probe = mclxcd_probe,
};
