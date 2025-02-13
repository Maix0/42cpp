# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 13:20:01 by maiboyer          #+#    #+#              #
#    Updated: 2025/02/11 16:43:24 by maiboyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS_ADDITIONAL ?= -g

SUBJECT_URL		=	https://cdn.intra.42.fr/pdf/pdf/149679/en.subject.pdf

BUILD_DIR		?=	./build
SRC_DIR			=	.
INCLUDE_DIR		=	.

BASE_PATH		?=	$(shell pwd)
NAME			=	mutant

TARGET			=	./$(NAME)
CXX				=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -MMD -std=c++98
CXXFLAGS		+=	$(CXXFLAGS_ADDITIONAL)

-include 			./Filelist.mk

OBJ				=	$(addsuffix .o,$(addprefix $(BUILD_DIR)/,$(SRC_FILES)))
DEPS			=	$(addsuffix .d,$(addprefix $(BUILD_DIR)/,$(SRC_FILES)))

INCLUDES		=	$(addprefix -I,$(foreach P,$(INCLUDE_DIR), $(realpath $(P))))
COL_BOLD		=	\033[1m
COL_GOLD		=	\033[93m
COL_RED			=	\033[31m
COL_GRAY		=	\033[90m
COL_GREEN		=	\033[32m
COL_RESET		=	\033[0m
COL_WHITE		=	\033[37m


.PHONY = all bonus clean re subject filelist

all: $(NAME)

#$(NAME): $(TARGET)

$(TARGET): $(OBJ)
	@echo -e '$(COL_GRAY) Linking \t $(COL_GOLD)$(TARGET)$(COL_RESET)'
	@$(CXX) $(INCLUDES) $(OBJ) $(CXXFLAGS) -o $(NAME)
	@#ar rcs $(BUILD_DIR)/$(NAME) $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -e '$(COL_GRAY) Building\t $(COL_GREEN)$<$(COL_RESET)'
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e '$(COL_GRAY) Removing\t $(COL_RED)$(BUILD_DIR)$(COL_RESET)'
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo -e '$(COL_GRAY) Removing\t $(COL_RED)$(NAME)$(COL_RESET)'
	@rm -f $(NAME)

re: fclean all

subject: subject.txt
	@bat --plain ./subject.txt

subject.txt:
	@curl $(SUBJECT_URL) | pdftotext -layout -nopgbrk -q - subject.txt


filelist:
	@rm -f Filelist.mk
	@printf '%-78s\\\n' "SRC_FILES =" > Filelist.mk
	@tree $(SRC_DIR) -ifF | rg '$(SRC_DIR)/(.*)\.cpp$$' --replace '$$1' | sed -re 's/^(.*)_([0-9]+)$$/\1|\2/g' | sort -t'|' --key=1,1 --key=2,2n | sed -e's/|/_/' | xargs printf '%-78s\\\n' >> Filelist.mk
	@echo "" >> Filelist.mk

%.h: ;

-include $(DEPS)
