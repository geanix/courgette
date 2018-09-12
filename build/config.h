#pragma once

#define NO_TCMALLOC
#define __libc_malloc(x) malloc(x)
