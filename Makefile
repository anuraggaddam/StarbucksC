OS := $(shell uname)

build: create compile Libraries



ifeq ($(OS),Linux)
	

create:
	@mkdir ./linux/library
	@mkdir ./linux/builds
	@mkdir ./linux/objects
	@mkdir ./linux/receipts
	@echo "Creating Directories"
IO:
	@gcc -c ./linux/source/FileIO/menu.c -o ./linux/objects/menu.o
	@gcc -c ./linux/source/Interactions/Interactions.c -o ./linux/objects/Interactions.o
	@gcc -c ./linux/source/FileIO/writer.c -o ./linux/objects/writer.o
	@echo "Compiling IO Files"

Customizations:
	@gcc -c ./linux/source/Customizations/Customize.c -o ./linux/objects/Customize.o
	@gcc -c ./linux/source/Customizations/IO.c -o ./linux/objects/IO.o
	@gcc -c ./linux/source/Customizations/List.c -o ./linux/objects/List.o
	@echo "Compiling Customization Files"
Basket:
	@gcc -c ./linux/source/Basket/insert.c -o ./linux/objects/insert.o
	@gcc -c ./linux/source/Basket/payment.c -o ./linux/objects/payment.o
	@echo "Compiling Payment Files"

compile: IO Customizations Basket

Libraries:
	@ar rcs ./linux/library/lib_IO.a ./linux/objects/menu.o ./linux/objects/Interactions.o ./linux/objects/writer.o
	@ar rcs ./linux/library/lib_CUSTOMIZE.a ./linux/objects/Customize.o ./linux/objects/IO.o ./linux/objects/List.o
	@ar rcs ./linux/library/lib_BASKET.a ./linux/objects/insert.o
	@ar rcs ./linux/library/lib_PAYMENT.a ./linux/objects/payment.o
	@echo "Creating Libraries"
	@echo "Ready to Run"
	@echo "To start, type make run."
	@echo "At anytime, type make clean to delete directories"

clean:
	@rm -rf ./linux/objects/ ./linux/library/ ./linux/builds/ ./linux/receipts/
	@echo "Deleting Directories. Source files still available."

run:
	@gcc -o ./linux/builds/Linux ./linux/Main.c -I./linux/header -L./linux/library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@echo "Linking Libraries"
	@clear
	@cd ./linux/builds && ./Linux
else ifeq ($(OS),Darwin)
	@gcc -o ./builds/Mac Main.c -Iheader -Llibrary -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@echo "Linking Libraries"
	@clear
	@cd builds && ./Mac
endif

