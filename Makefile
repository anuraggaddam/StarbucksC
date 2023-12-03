OS := $(shell uname)

build: compile Libraries


IO:
	@gcc -c ./source/FileIO/menu.c -o ./objects/menu.o
	@gcc -c ./source/Interactions/Interactions.c -o ./objects/Interactions.o

Customizations:
	@gcc -c ./source/Customizations/Customize.c -o ./objects/Customize.o


compile: IO Customizations
	@echo "Compiling Files"

Libraries:
	@echo "Creating Libraries"
	@ar rcs ./library/lib_IO.a ./objects/menu.o ./objects/Interactions.o
	@ar rcs ./library/lib_CUSTOMIZE.a ./objects/Customize.o

clean:
	@rm -rf ./objects/* ./library/* ./builds/*


run:
ifeq ($(OS),Linux)
	@gcc -o ./builds/Linux Main.c -Iheader -Llibrary -l_IO -l_CUSTOMIZE
	@cd builds && ./Linux
else ifeq ($(OS),Darwin)
	@gcc -o ./builds/Mac Main.c -Iheader -Llibrary -l_IO -l_CUSTOMIZE
	@cd builds && ./Mac
endif

