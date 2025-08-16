# ---- project
NAME    := libft.a

# ---- tools & flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f

# ---- headers (add more if you really have them)
HDRS    := libft.h
INCLUDES:= -I .

# ---- sources (your actual files)
SRCS := \
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
OBJS  := $(SRCS:.c=.o)
BOBJS := $(BSRCS:.c=.o)

# ---- rules (highlights mandatory ones: all NAME clean fclean re)
.PHONY: all bonus clean fclean re 
# rule 1: all . build the library
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# rule 2: bonus . build the bonus functions into the library
# once make bonus, archive keeps bonus members until fclean
bonus: OBJS += $(BOBJS) 
bonus: $(NAME)

# rule 3: clean . clean all object files
clean:
	$(RM) $(OBJS) $(BOBJS)

# rule 4: fclean . clean all object files and the library
fclean: clean
	$(RM) $(NAME)

# rule 5: re . rebuild the library
re: fclean all