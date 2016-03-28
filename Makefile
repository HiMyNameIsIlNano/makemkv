# New ports collection makefile for:	makemkv
# Date created:				05 Mar 2012
# Date Updated:				11 January 2016
# Whom:					kappei84
#
# $FreeBSD$
#

PORTNAME=	makemkv
PORTVERSION=	1.9.9
CATEGORIES=	multimedia
DISTNAME=	${PORTNAME}-oss-${PORTVERSION}${EXTRACT_SUFFIX}
MASTER_SITES=	http://www.makemkv.com/download/

LIB_DEPENDS=	libmatroska.so:${PORTSDIR}/multimedia/libmatroska

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Make MKV from Blu-ray and DVD

MAKEFILE=	Makefile.in
USES= gmake
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake gui svg webkit xml moc uic rcc imageformats

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${PORTNAME} ${PREFIX}/bin
.for i in libdriveio.so.0 libmakemkv.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/out/${i} ${PREFIX}/lib
.endfor
	@ cd ${PREFIX}/lib ; \
	${LN} -sf libdriveio.so.0 libdriveio.so ; \
	${LN} -sf libmakemkv.so.1 libmakemkv.so

.include <bsd.port.mk>
