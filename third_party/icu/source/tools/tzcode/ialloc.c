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

char *
icatalloc(char *const old, const char *const new)
{
	register char *	result;
	register int	oldsize, newsize;

	newsize = (new == NULL) ? 0 : strlen(new);
	if (old == NULL)
		oldsize = 0;
	else if (newsize == 0)
		return old;
	else	oldsize = strlen(old);
	if ((result = realloc(old, oldsize + newsize + 1)) != NULL)
		if (new != NULL)
			(void) strcpy(result + oldsize, new);
	return result;
}

char *
icpyalloc(const char *const string)
{
	return icatalloc(NULL, string);
}
