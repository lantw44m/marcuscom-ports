/*-
 * Copyright (c) 2008 Joe Marcus Clarke <marcus@FreeBSD.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/param.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ttyent.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
	int debug;
	char *debugstr;
	struct ttyent *t;
	char ttydev[PATH_MAX];
	int res, ret;

	ret = 0;

	debugstr = getenv("VTY_CHECKER_DEBUG");
	if (debugstr != NULL) {
		debug = atoi(debugstr);
	} else {
		debug = 0;
	}

	res = setttyent();
	if (res == 0) {
		/* We cannot get a list of VTYs.  Return TRUE, and let the
		 * caller sort things out.
		 */
		if (debug) {
			(void)fprintf(stderr, "Failed to get TTY entries: %s\n",
				strerror(errno));
		}
		return (0);
	}

	(void)sprintf(ttydev, "/dev/");

	while ((t = getttyent()) != NULL) {
		if (t->ty_status & TTY_ON && strncmp(t->ty_name, "ttyv", 4) == 0) {
			char *ty_devptr;
			int fd;

			ty_devptr = ttydev + 6;
			(void)strlcat(ty_devptr, t->ty_name, PATH_MAX);

			if ((fd = open(ttydev, O_RDONLY | O_NOCTTY)) < 0) {
				if (debug) {
					(void)fprintf(stderr,
						"Failed to open %s: %s\n",
						ttydev, strerror(errno));
				}
				ret = 1;
				break;
			}
			(void)close(fd);
		}
	}

	endttyent();

	return (ret);
}
