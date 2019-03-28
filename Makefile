##
## EPITECH PROJECT, 2019
## dante star
## File description:
## makefile
##

END     =   \033[0m
BOLD    =   \033[1m
IRED	=	\x1b[41m

all:
	@echo -e "$(BOLD)$(IRED)Make generator $(END)"
	@make -s -C generator/
	@echo -e "$(BOLD)$(IRED)Make solver $(END)"
	@make -s -C solver/

re:
	@echo -e "$(BOLD)$(IRED)Make generator $(END)"
	@make re -s -C generator/
	@echo -e "$(BOLD)$(IRED)Make solver $(END)"
	@make re -s -C solver/
