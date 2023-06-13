/*
 * Copyright (c) 2016 by Solar Designer.  See LICENSE.
 */

#ifdef _MSC_VER
#include <windows.h>
#else
#include <string.h>
#endif

static void memzero(void *buf, size_t len)
{
#ifdef _MSC_VER
	SecureZeroMemory(buf, len);
#elif defined __FreeBSD__ || defined __OpenBSD__
	/* explicit_bzero() will not be removed by a compiler's dead store optimization pass. */
	explicit_bzero(buf, len);
#else
	memset(buf, 0, len);
#endif
}

void (*_passwdqc_memzero)(void *, size_t) = memzero;
