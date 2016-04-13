# New ports collection makefile for:	makemkv
# Date created:				05 Mar 2012
# Date Updated:				10 April 2016
# Whom:					kappei84
#
# $FreeBSD$
#

PORTNAME=	makemkv
PORTVERSION=	1.9.9
CATEGORIES=	multimedia
DISTNAME=	${PORTNAME}-oss-${PORTVERSION}${EXTRACT_SUFFIX}
MASTER_SITES=	http://www.makemkv.com/download/

# Prefix for the pkp-plist
#PLIST_SUB=	DATADIR=${PREFIX}

MAINTAINER=	
COMMENT=	Make MKV from Blu-ray and DVD

GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	GUI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--enable-gui
USE_QT4=	qmake gui svg webkit xml moc uic rcc 
USE_QT4+=	imageformats
.else # qt4 dependency check in case the port is built with gui support
CONFIGURE_ARGS+=	--disable-gui
.endif # GUI

# flags for the configure script
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

MAKEFILE=	Makefile
USES= gmake
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

do-install:
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${PORTNAME} ${PREFIX}/bin
.endif
.for i in libdriveio.so.0 libmakemkv.so.1 libmmbd.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/out/${i} ${PREFIX}/lib
.endfor
	@ cd ${PREFIX}/lib ; \
	${LN} -sf libdriveio.so.0 libdriveio.so ; \
	${LN} -sf libmakemkv.so.1 libmakemkv.so ; \
	${LN} -sf libmmbd.so.0 libmmbd.so

.include <bsd.port.mk>
