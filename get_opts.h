#ifndef INC_GET_OPTS_H
#define INC_GET_OPTS_H

extern int   try_opt();
extern int   get_opts();
extern void  opt_free();
extern void *new_list();
extern char  opt_strcmp();
extern int   gather_opt();
extern int   get_opts_errormatic();

typedef struct stringlist_elem {
	char **sl;
	unsigned int n;
} sl_elem;

typedef struct charlist_elem {
	char *cl;
	unsigned int n;
} cl_elem;

typedef struct intlist_elem {
	int *il;
	unsigned int n;
} il_elem;

typedef char           opt_bool_t;
typedef char           opt_char_t;
typedef char           opt_type_t;
typedef char *         opt_string_t;
typedef int            opt_int_t;
typedef long           opt_long_t;
typedef short          opt_short_t;
typedef unsigned int   opt_uint_t;
typedef unsigned long  opt_ulong_t;
typedef unsigned short opt_ushort_t;
typedef char           opt_toggle_t;
typedef int            opt_increment_t;
typedef sl_elem *      opt_stringlist_t;
typedef cl_elem *      opt_charlist_t;
typedef il_elem *      opt_intlist_t;
typedef void *         opt_ptr_t;


typedef union _opt_value {
	opt_bool_t       opt_bool;
	opt_char_t       opt_char;
	opt_string_t     opt_string;
	opt_int_t        opt_int;
	opt_long_t       opt_long;
	opt_short_t      opt_short;
	opt_uint_t       opt_uint;
	opt_ulong_t      opt_ulong;
	opt_ushort_t     opt_ushort;
	opt_toggle_t     opt_toggle;
	opt_increment_t  opt_increment;
	opt_stringlist_t opt_stringlist;
	opt_charlist_t   opt_charlist;
	opt_intlist_t    opt_intlist;
	opt_ptr_t        opt_ptr;
} opt_value;

typedef struct _opt {
	opt_bool_t   i_opt; /* should be 1 for all real options */
	opt_string_t s_opt;
	opt_string_t l_opt;
	opt_type_t   t_opt;
	opt_value    v_opt;
	int          (*f_opt)();
} opt;


#define OPT_BOOL       0x00
#define OPT_CHAR       0x01
#define OPT_STRING     0x02
#define OPT_INT        0x03
#define OPT_LONG       0x04
#define OPT_SHORT      0x05
#define OPT_UINT       0x06
#define OPT_ULONG      0x07
#define OPT_USHORT     0x08
#define OPT_TOGGLE     0x09
#define OPT_INCREMENT  0x0A
#define OPT_STRINGLIST 0x0B
#define OPT_CHARLIST   0x0C
#define OPT_INTLIST    0x0D
#define OPT_PTR        0x0E


#define I_END          0x00
#define I_OPT          0x01

#define OPT_DELIM '-'

/* special variables */
extern opt o_end;

/* special preprocessor functions */
#define add_opt(name,s,l,t,v,f) opt name = {I_OPT,s,l,t,(opt_value)v,f}
#define put_opts(optionlist,opts...) opt *optionlist[] = { ##opts , &o_end}

#endif /* !INC_GET_OPTS_H */
