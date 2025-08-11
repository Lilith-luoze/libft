#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_list
{
	void *content;       // the data you store (any type via void*)
	struct s_list *next; // pointer to the next node, or NULL at the end
}				t_list;

static int		ft_isupper(int);
static int		ft_islower(int);
int				ft_isalpha(int);
int				ft_isdigit(int);
int				ft_isalnum(int);
int				ft_isascii(int);
int				ft_isprint(int);
size_t			ft_strlen(const char *);
void			*ft_memset(void *, int, size_t);
void			ft_bzero(void *, size_t);
void			*ft_memcpy(void *, const void *, size_t);
static void		ft_backward_cp(unsigned char *, const unsigned char *, size_t);
static void		ft_forward_cp(unsigned char *, const unsigned char *, size_t);
void			*ft_memmove(void *, const void *, size_t);
size_t			ft_strlcpy(char *, const char *, size_t);
size_t			ft_strlcat(char *, const char *, size_t);
int				ft_toupper(int);
int				ft_tolower(int);
char			*ft_strchr(const char *, int);
char			*ft_strrchr(const char *, int);
int				ft_strncmp(const char *, const char *, size_t);
void			*ft_memchr(const void *, int, size_t);
int				ft_memcmp(const void *, const void *, size_t);
char			*ft_strnstr(const char *, const char *, size_t);
int				ft_atoi(const char *);
void			*ft_calloc(size_t, size_t);
char			*ft_strdup(const char *);
char			*ft_strjoin(char const *, char const *);
char			*ft_strtrim(char const *, char const *);
static size_t	ft_itoa_len(int);
char			*ft_itoa(int);
char			*ft_substr(char const *, unsigned int, size_t);
static size_t	ft_word_count(char const *, char);
static void		*ft_free_split(void **, size_t);
static size_t	ft_wordlen(char const *, char);
static void		ft_init_vars(size_t *, size_t *, size_t *, char ***);
char			**ft_split(char const *, char);
char			*ft_strmapi(char const *, char (*)(unsigned int, char));

void ft_striteri(char *s, void (*f)(unsigned int, char *));

void ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

#endif /// HOME/LILITH/LIBFT/PART_1_REVIEW_OLD_FUNCTION_H