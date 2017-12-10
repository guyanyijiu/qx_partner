/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_qx_partner.h"

/* If you declare any globals in php_qx_partner.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(qx_partner)
*/

/* True global resources - no need for thread safety here */
static int le_qx_partner;

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    PHP_INI_ENTRY("qx_partner.id",      "0", PHP_INI_ALL, NULL)
    PHP_INI_ENTRY("qx_partner.mark", "default", PHP_INI_ALL, NULL)
PHP_INI_END()
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_qx_partner_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_qx_partner_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "qx_partner", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_qx_partner_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_qx_partner_init_globals(zend_qx_partner_globals *qx_partner_globals)
{
	qx_partner_globals->global_value = 0;
	qx_partner_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(qx_partner)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(qx_partner)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(qx_partner)
{
#if defined(COMPILE_DL_QX_PARTNER) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(qx_partner)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(qx_partner)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "qx_partner support", "enabled");
    php_info_print_table_row(2, "version", PHP_QX_PARTNER_VERSION);
    php_info_print_table_row(2, "author", PHP_QX_PARTNER_AUTHOR);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ qx_partner_functions[]
 *
 * Every user visible function must have an entry in qx_partner_functions[].
 */
const zend_function_entry qx_partner_functions[] = {
	PHP_FE(confirm_qx_partner_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in qx_partner_functions[] */
};
/* }}} */

/* {{{ qx_partner_module_entry
 */
zend_module_entry qx_partner_module_entry = {
	STANDARD_MODULE_HEADER,
	"qx_partner",
	qx_partner_functions,
	PHP_MINIT(qx_partner),
	PHP_MSHUTDOWN(qx_partner),
	PHP_RINIT(qx_partner),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(qx_partner),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(qx_partner),
	PHP_QX_PARTNER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_QX_PARTNER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(qx_partner)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
