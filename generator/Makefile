##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard $(addprefix source/, *).c)
NOM		=	$(basename $(notdir $(SRC)))
OBJ     =   $(addprefix object/, $(addsuffix .o, $(NOM)))

LNAME	=	libmy.a
LIB		=	my
LIB-PATH	=	./lib/my
SRC-LIB	=	$(wildcard $(addprefix $(LIB-PATH)/, *).c)
NOM-LIB	=	$(basename $(notdir $(SRC-LIB)))
OBJ-LIB	=	$(addprefix object/, $(addsuffix .o, $(NOM-LIB)))

HEADP	=	./include/

NAME	=	generator

END		=	\033[0m
BOLD	=	\033[1m
GREEN	=	\033[32m
RED		=	\033[31m
CYAN	=	\033[36m

.PHONY: re clean lib

all: lib $(OBJ)
	@echo -e "$(BOLD)OBJ.o generation$(END)"
	@echo -e "$(BOLD)$(NAME) generation$(END)"
	@gcc -o $(NAME) $(OBJ) -L $(LIB-PATH) -l$(LIB)
	@echo -e "$(GREEN)* * * * * COMPLETED * * * * *$(END)"

clear:
	@echo -e "$(BOLD)Deleting junks files$(END)"
	@rm -fv source/*~
	@rm -fv *~
	@rm -fv include/*~
	@rm -fv vgcore.*
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

lib: $(OBJ-LIB)
	@echo -e "$(GREEN)Generating$(BOLD) $(LNAME)$(END)"
	@ar rc $(addprefix $(LIB-PATH)/, $(LNAME)) $(OBJ-LIB)
	@echo -e "$(GREEN)* * * * * LIBRARY COMPLETED * * * * *$(END)"

clean:
	@echo -e "$(BOLD)Deleting OBJ.o files$(END)"
	@rm -f $(OBJ)
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

lclean:
	@echo -e "$(BOLD)Deleting $(LNAME)$(END)"
	@rm -f $(OBJ-LIB)
	@echo -e "$(CYAN)* * * * * LIBRARY REMOVED * * * * *$(END)"

fclean: clean
	@echo -e "$(BOLD)Deleting $(NAME)$(END)"
	@rm -f $(NAME)
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

re:	clear fclean lclean lib all

object/%.o: source/%.c
	@gcc -Wall -Wextra -fPIC -fno-builtin -c -o $@ $<	\
    && echo -e "$(GREEN)[OK]$(BOLD)" $< "$(END)"		\
    || echo -e "$(RED)[KO]$(BOLD)" $< "$(END)"

object/%.o: $(LIB-PATH)/%.c
	@gcc -Wall -I $(HEADP) -Wextra -fPIC -fno-builtin -c -o $@ $<	\
    && echo -e "$(GREEN)[OK]$(BOLD)" $< "$(END)"		\
    || echo -e "$(RED)[KO]$(BOLD)" $< "$(END)"
