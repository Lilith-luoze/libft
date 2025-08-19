# ---- project
NAME    := libft.a

# ---- tools & flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f

# ---- headers
HDRS    := libft.h
INCLUDES:= -I .

# ---- sources
MSRCS := \
	ft_alloc.c \
	ft_convert.c \
	ft_ctype1.c \
	ft_ctype2.c \
	ft_fd.c \
	ft_mem.c \
	ft_memmove.c \
	ft_split.c \
	ft_str_basic.c \
	ft_str_more.c \
	ft_strbuild.c \
	ft_strlen.c

BSRCS := \
	ft_lst_basic_bonus.c \
	ft_lst_map_bonus.c \
	ft_lst_ops_bonus.c

# ---- derived object lists
MOBJS  := $(MSRCS:.c=.o)
BOBJS := $(BSRCS:.c=.o)
.DEFAULT_GOAL := all
# ---- rules (highlights mandatory ones: all NAME clean fclean re)
.PHONY: all bonus clean fclean re 
# rule 1: all . build the MANDATORY library
all: $(NAME)

$(NAME): $(MOBJS)
	$(AR) $(ARFLAGS) $(NAME) $(MOBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# rule 2: bonus . build the bonus functions into the library
bonus: $(BOBJS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BOBJS)

# rule 3: clean . clean all object files
clean:
	$(RM) $(MOBJS) $(BOBJS)

# rule 4: fclean . clean all object files and the library
fclean: clean
	$(RM) $(NAME)

# rule 5: re . rebuild the MANDATORY library
re: fclean all