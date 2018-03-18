PROG=	mvpins
SRCS=	mvpins.c \
	pinctrl-armada-cp110.c \
	pinctrl-armada-ap806.c \
	pinctrl-armada-38x.c

CPPFLAGS+= -I${.CURDIR}

NOMAN=

.include <bsd.prog.mk>
