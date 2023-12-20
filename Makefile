OS := $(shell uname)

build: clean create compile Libraries



ifeq ($(OS),Linux)



create:
	@mkdir ./linux/library
	@mkdir ./linux/builds
	@mkdir ./linux/objects
	@mkdir ./linux/receipts
	@echo "Creating Directories for Linux"
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

clean:
	@rm -rf ./linux/objects/ ./linux/library/ ./linux/builds/ ./linux/receipts/
	@echo "Refreshing Directories for Linux"

run:
	@gcc -o ./linux/builds/Linux ./linux/Main.c -I./linux/header -L./linux/library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@echo "Linking Libraries"
	@echo "Running for Linux"
	@clear
	@cd ./linux/builds && ./Linux







else ifeq ($(OS),Darwin)
create:
	@mkdir ./unix/library
	@mkdir ./unix/builds
	@mkdir ./unix/objects
	@mkdir ./unix/receipts
	@echo "Creating Directories for Unix"
IO:
	@gcc -c ./unix/source/FileIO/menu.c -o ./unix/objects/menu.o
	@gcc -c ./unix/source/Interactions/Interactions.c -o ./unix/objects/Interactions.o
	@gcc -c ./unix/source/FileIO/writer.c -o ./unix/objects/writer.o
	@echo "Compiling IO Files"

Customizations:
	@gcc -c ./unix/source/Customizations/Customize.c -o ./unix/objects/Customize.o
	@gcc -c ./unix/source/Customizations/IO.c -o ./unix/objects/IO.o
	@gcc -c ./unix/source/Customizations/List.c -o ./unix/objects/List.o
	@echo "Compiling Customization Files"
Basket:
	@gcc -c ./unix/source/Basket/insert.c -o ./unix/objects/insert.o
	@gcc -c ./unix/source/Basket/payment.c -o ./unix/objects/payment.o
	@echo "Compiling Payment Files"

compile: IO Customizations Basket

Libraries:
	@ar rcs ./unix/library/lib_IO.dylib ./unix/objects/menu.o ./unix/objects/Interactions.o ./unix/objects/writer.o
	@ar rcs ./unix/library/lib_CUSTOMIZE.dylib ./unix/objects/Customize.o ./unix/objects/IO.o ./unix/objects/List.o
	@ar rcs ./unix/library/lib_BASKET.dylib ./unix/objects/insert.o
	@ar rcs ./unix/library/lib_PAYMENT.dylib ./unix/objects/payment.o
	@echo "Creating Libraries"
	@echo "Ready to Run"
	@echo "To start, type make run."

clean:
	@rm -rf ./unix/objects/ ./unix/library/ ./unix/builds/ ./unix/receipts/
	@echo "Refreshing Directories for Unix"

run:
	@gcc -o ./unix/builds/unix ./unix/Main.c -I./unix/header -L./unix/library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	@echo "Linking Libraries"
	@echo "Running for Unix"
	@clear
	@cd ./unix/builds && ./unix
endif

