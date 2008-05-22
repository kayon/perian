/*
 *  Codecprintf.c
 *  Perian
 *
 *  Created by Augie Fackler on 7/16/06.
 *  Copyright 2006 Perian Project. All rights reserved.
 *
 */

#include "Codecprintf.h"
#include <stdio.h>
#include <stdarg.h>
#include "log.h"

#ifdef DEBUG_BUILD
#define CODEC_HEADER			"Perian Codec: "
#define FILELOG

static int Codecvprintf(FILE *fileLog, const char *format, va_list va, int print_header)
{
	int ret;
	
#ifdef FILELOG
	if(fileLog)
	{
		if(print_header)
			fprintf(fileLog, CODEC_HEADER);
		ret = vfprintf(fileLog, format, va);
		fflush(fileLog);
	}
	else
	{
#endif
		if(print_header)
			printf(CODEC_HEADER);
		
		ret = vprintf(format, va);
#ifdef FILELOG
	}
#endif
	
	return ret;
}

int Codecprintf(FILE *fileLog, const char *format, ...)
{
	int ret;
	va_list va;
	va_start(va, format);
	ret = Codecvprintf(fileLog, format, va, !fileLog);
	va_end(va);
	return ret;
}

const char *FourCCString(FourCharCode c)
{
    static unsigned char fourcc[5] = {0};
    int i;
    
    for (i = 0; i < 4; i++) fourcc[i] = c >> 8*(3-i);
    
    return (char*)fourcc;
}

void FourCCprintf (char *string, FourCharCode a)
{
    Codecprintf(NULL, "%s%s\n", string, FourCCString(a));
}

#else
#define Codecvprintf(file, fmt, va, print_header) /**/
#endif

void FFMpegCodecprintf(void* ptr, int level, const char* fmt, va_list vl)
{
    static int print_prefix=1;
	int print_header = 1;
    AVClass* avc= ptr ? *(AVClass**)ptr : NULL;
    if(level>av_log_level)
        return;

    if(print_prefix && avc) {
		Codecprintf(NULL, "[%s @ %p]", avc->item_name(ptr), avc);
		print_header = 0;
    }
	
    print_prefix= strstr(fmt, "\n") != NULL;
	
	Codecvprintf(NULL, fmt, vl, print_header);
}