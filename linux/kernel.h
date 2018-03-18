#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define __iomem

#define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)

#define BIT(x) (1 << (x))

#define devm_kzalloc(x, y, z) calloc((y), 1)
