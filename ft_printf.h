#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC "sSpdDioOuUxXcC"
# define ABS(n) ((n < 0) ? -n : n)

# include <stdarg.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>


typedef enum    e_size
{
    hh = 0,
    h = 1,
    l = 2,
    ll = 3,
    j = 4,
    z = 5
}               t_size;

typedef struct  s_spec
{
    int         plus;
    int         minus;
    int         space;
    int         hesh;
    int         zero;
    int         width;
    int         precision;
    t_size      size;
    char        type;
    int         ln_search;
    int         ln_text;
    int         result;
}               t_spec;

//Общие функции в отдельных файлах

int     ft_printf(char *format, ...);
void    ft_search(char *format, t_spec *spec);

void    ft_print_c(char c, t_spec *spec);
int     ft_print_s(char *s, t_spec spec);
int     ft_print_d_i_D(va_list ap, t_spec spec);
int     ft_print_u_U(va_list ap, t_spec spec);
int     ft_print_o_O(va_list ap, t_spec spec);
int     ft_print_x_X_p(va_list ap, t_spec spec);

void    ft_initialization(t_spec *spec);
char	*ft_itoa_base(uintmax_t n, int base);


//Функции с ft_search.2.c

void    ft_not_valid_type(char c, t_spec *spec);
void    ft_search_flag(char *str_search, t_spec *spec);
void    ft_search_width_precision(char **str_search, t_spec *spec);
void    ft_search_size(char **str_search, t_spec *spec);
char    *ft_search_spec_type(char *format);



//Функции ft_left_right.c

char    *ft_left(char *s, int width, int precision, char c);
char    *ft_right(char *s, int width, int precision, char c);


//Функции ft_print_d_i_D_2.c
//Функции ft_print_u_U_2.c

char *ft_string_formation_d(char *s, t_spec spec, int ln, intmax_t n);
char *ft_string_formation_u(char *s, t_spec spec, int ln, uintmax_t n);
char *ft_string_formation_o(char *s, t_spec spec, int ln, uintmax_t n);
char *ft_string_formation_x(char *s, t_spec spec, int ln, uintmax_t n);
char *ft_string_formation_p(char *s, t_spec spec, char *ox, uintmax_t n);

//libft

size_t	ft_strlen(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(intmax_t n);
int		ft_isdigit(int c);
int	    ft_atoi(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *str);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *b, size_t length);
void	*ft_memset(void *dst, int c, size_t n);
void	ft_putstr(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_toupper(int c);

#endif

