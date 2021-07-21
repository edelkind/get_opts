#ifndef _GET_OPTS_GET_OPTS_HPP
# define _GET_OPTS_GET_OPTS_HPP

template <typename T>
optx add_optx(  const char *short_opt,
                const char *long_opt,
                opt_type_t otype,
                T *dest,
                int (*f_opt)(T*),
                const char *help)
{
    optx tmp = { I_OPT, short_opt, long_opt, otype, dest, f_opt, help };
    return tmp;
}

#define add_optx(type,name,s,l,t,v,f,h) opt name = add_opt<type>(s, l, t, v, f, h);


#endif /* _GET_OPTS_GET_OPTS_HPP */
