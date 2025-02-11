# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 13:20:01 by maiboyer          #+#    #+#              #
#    Updated: 2025/02/11 16:47:19 by maiboyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBJECT_URL		=	https://cdn.intra.42.fr/pdf/pdf/149679/en.subject.pdf
EXERCISES		=	./ex00 ./ex01 ./ex02

.PHONY = all clean re subject filelist $(EXERCISES)

all: $(EXERCISES)

$(EXERCISES):
	$(MAKE) -C $@ all

clean:
	$(foreach ex,$(EXERCISES),$(MAKE) -C $(ex) clean;)

fclean:
	$(foreach ex,$(EXERCISES),$(MAKE) -C $(ex) fclean;)

re:
	$(foreach ex,$(EXERCISES),$(MAKE) -C $(ex) re;)

subject: subject.txt
	@bat --plain ./subject.txt

subject.txt:
	@curl $(SUBJECT_URL) | pdftotext -layout -nopgbrk -q - subject.txt


filelist:
	@$(foreach ex,$(EXERCISES),@$(MAKE) -C $(ex) filelist)
