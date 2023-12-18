OS := $(shell uname)

build: compile Libraries


IO:
	@gcc -c ./source/FileIO/menu.c -o ./objects/menu.o
	@gcc -c ./source/Interactions/Interactions.c -o ./objects/Interactions.o

Customizations:
	@gcc -c ./source/Customizations/Customize.c -o ./objects/Customize.o
	@gcc -c ./source/Customizations/IO.c -o ./objects/IO.o
	@gcc -c ./source/Customizations/List.c -o ./objects/List.o
Basket:
	@gcc -c ./source/Basket/insert.c -o ./objects/insert.o
	@gcc -c ./source/Basket/payment.c -o ./objects/payment.o

compile: IO Customizations Basket

Libraries:
	@ar rcs ./library/lib_IO.a ./objects/menu.o ./objects/Interactions.o
	@ar rcs ./library/lib_CUSTOMIZE.a ./objects/Customize.o ./objects/IO.o ./objects/List.o
	@ar rcs ./library/lib_BASKET.a ./objects/insert.o
	@ar rcs ./library/lib_PAYMENT.a ./objects/payment.o
	@echo "Ready to Run"

clean:
	@rm -rf ./objects/* ./library/* ./builds/*


run:
ifeq ($(OS),Linux)
	@gcc -o ./builds/Linux Main.c -Iheader -Llibrary -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@cd builds && ./Linux
else ifeq ($(OS),Darwin)
	@gcc -o ./builds/Mac Main.c -Iheader -Llibrary -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@cd builds && ./Mac
endif

