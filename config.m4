dnl $Id$
dnl config.m4 for extension qx_partner

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(qx_partner, for qx_partner support,
Make sure that the comment is aligned:
[  --with-qx_partner             Include qx_partner support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(qx_partner, whether to enable qx_partner support,
dnl Make sure that the comment is aligned:
dnl [  --enable-qx_partner           Enable qx_partner support])

if test "$PHP_QX_PARTNER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-qx_partner -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/qx_partner.h"  # you most likely want to change this
  dnl if test -r $PHP_QX_PARTNER/$SEARCH_FOR; then # path given as parameter
  dnl   QX_PARTNER_DIR=$PHP_QX_PARTNER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for qx_partner files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       QX_PARTNER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$QX_PARTNER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the qx_partner distribution])
  dnl fi

  dnl # --with-qx_partner -> add include path
  dnl PHP_ADD_INCLUDE($QX_PARTNER_DIR/include)

  dnl # --with-qx_partner -> check for lib and symbol presence
  dnl LIBNAME=qx_partner # you may want to change this
  dnl LIBSYMBOL=qx_partner # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $QX_PARTNER_DIR/$PHP_LIBDIR, QX_PARTNER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_QX_PARTNERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong qx_partner lib version or lib not found])
  dnl ],[
  dnl   -L$QX_PARTNER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(QX_PARTNER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(qx_partner, qx_partner.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
