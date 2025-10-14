//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//

/*
** This file is in the public domain, so clarified as of
** 2006-07-17 by Arthur David Olson.
*/

/*LINTLIBRARY*/

#include "private.h"

const char *
scheck(const char *const string, const char *const format)
{
	register char *		fbuf;
	register const char *	fp;
	register char *		tp;
	register int		c;
	register const char *	result;
	char			dummy;

	result = "";
	if (string == NULL || format == NULL)
		return result;
	fbuf = malloc(2 * strlen(format) + 4);
	if (fbuf == NULL)
		return result;
	fp = format;
	tp = fbuf;

	/*
	** Copy directives, suppressing each conversion that is not
	** already suppressed.  Scansets containing '%' are not
	** supported; e.g., the conversion specification "%[%]" is not
	** supported.  Also, multibyte characters containing a
	** non-leading '%' byte are not supported.
	*/
	while ((*tp++ = c = *fp++) != '\0') {
		if (c != '%')
			continue;
		if (is_digit(*fp)) {
			char const *f = fp;
			char *t = tp;
			do {
				*t++ = c = *f++;
			} while (is_digit(c));
			if (c == '$') {
				fp = f;
				tp = t;
			}
		}
		*tp++ = '*';
		if (*fp == '*')
			++fp;
		if ((*tp++ = *fp++) == '\0')
			break;
	}

	*(tp - 1) = '%';
	*tp++ = 'c';
	*tp = '\0';
	if (sscanf(string, fbuf, &dummy) != 1)
		result = format;
	free(fbuf);
	return result;
}
