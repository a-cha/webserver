# Compilation
CC= clang++
CFLAGS= -g -Wall -Wextra -Werror

# Directories
SRC_DIR= ./src/
SRC_SUBDIRS= $(shell ls -1d $(SRC_DIR)*/*/ ) $(shell ls -1d $(SRC_DIR)*/ )
HPP_DIRS= $(SRC_SUBDIRS)
OBJ_DIR= ./obj/

# Sources
NAME= webserv
SRC_FILES= $(shell ls -R -1 $(SRC_DIR) | grep \.cpp )
HPP_FILES= $(shell ls -R -1 $(HPP_DIRS) | grep \.hpp )

OBJ= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
DEP= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.d))

LINK= $(addprefix -I, $(HPP_DIRS))

# Colors
BOLD= \033[1m
GREEN= \033[32m
RED= \033[31m
BLUE= \033[36m
STD= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LINK) -o $@ $^

-include $(DEP)

VPATH = $(addsuffix :, $(SRC_SUBDIRS))

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LINK) -c $< -o $@ -MMD

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)Object files$(RED) deleted$(STD)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)Binary $(BLUE)$(NAME)$(RED) deleted$(STD)"

re: fclean all

d:
	@echo $(addsuffix :, $(SRC_SUBDIRS))

deb:
	mkdir -p deb
	@echo "SRC_SUBDIRS " $(SRC_SUBDIRS) > deb/SRC_SUBDIRS "\n"
	@echo "HPP_DIRS " $(HPP_DIRS) > deb/HPP_DIRS "\n"
	@echo "SRC_FILES " $(SRC_FILES) > deb/SRC_FILES "\n"
	@echo "HPP_FILES " $(HPP_FILES) > deb/HPP_FILES "\n"
	@echo "OBJ" $(OBJ) > deb/OBJ "\n"
	@echo "DEP" $(DEP) > deb/DEP "\n"

.PHONY: all clean fclean re
