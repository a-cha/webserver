# Compilation
CC= clang++
CFLAGS= -g -Wall -Wextra -Werror

# Directories
SRC_DIR= ./src/
SRC_SUBDIRS= $(shell ls -1p $(SRC_DIR) )
SRC_FULL_DIRS := $(addsuffix :, $(addprefix $(SRC_DIR), $(SRC_SUBDIRS)))
HPP_DIRS= $(addprefix $(SRC_DIR), $(SRC_SUBDIRS))
OBJ_DIR= ./obj/

# Sources
NAME= webserv
SRC_FILES= $(shell ls -R -1 $(SRC_DIR) | grep \.cpp )
HPP_FILES= $(shell ls -R -1 $(HPP_DIRS) | grep \.hpp )

OBJ= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
DEP= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.d))

LINK= $(addprefix -I, $(HPP_DIRS))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(LINK) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

VPATH = $(SRC_FULL_DIRS)

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) $(LINK) -c $< -o $@ -MMD

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME);

re: fclean all

deb:
	@echo "SRC_SUBDIRS " $(SRC_SUBDIRS) "\n"
	@echo "HPP_DIRS " $(HPP_DIRS) "\n"
	@echo "SRC_FILES " $(SRC_FILES) "\n"
	@echo "HPP_FILES " $(HPP_FILES) "\n"
	@echo "OBJ" $(OBJ) "\n"
	@echo "DEP" $(DEP) "\n"

.PHONY: all clean fclean re
