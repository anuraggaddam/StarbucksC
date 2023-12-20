#!/bin/bash
os=$(uname -s)


if [ "$os" == "Linux" ]; then
	echo "building project"
	rm -rf ./linux/objects/ ./linux/library/ ./linux/builds/ ./linux/receipts/
	echo "clearing directories"
	mkdir ./linux/library
	mkdir ./linux/builds
	mkdir ./linux/objects
	mkdir ./linux/receipts
	echo "creating directories"

	gcc -c ./linux/source/FileIO/menu.c -o ./linux/objects/menu.o
	gcc -c ./linux/source/Interactions/Interactions.c -o ./linux/objects/Interactions.o
	gcc -c ./linux/source/FileIO/writer.c -o ./linux/objects/writer.o
	echo "compiling FileIO components"

	gcc -c ./linux/source/Customizations/Customize.c -o ./linux/objects/Customize.o
	gcc -c ./linux/source/Customizations/IO.c -o ./linux/objects/IO.o
	gcc -c ./linux/source/Customizations/List.c -o ./linux/objects/List.o
	echo "compiling customizations components"

	gcc -c ./linux/source/Basket/insert.c -o ./linux/objects/insert.o
	gcc -c ./linux/source/Basket/payment.c -o ./linux/objects/payment.o
	echo "compiling payment components"

	ar rcs ./linux/library/lib_IO.a ./linux/objects/menu.o ./linux/objects/Interactions.o ./linux/objects/writer.o
	ar rcs ./linux/library/lib_CUSTOMIZE.a ./linux/objects/Customize.o ./linux/objects/IO.o ./linux/objects/List.o
	ar rcs ./linux/library/lib_BASKET.a ./linux/objects/insert.o
	ar rcs ./linux/library/lib_PAYMENT.a ./linux/objects/payment.o
	echo "creating libraries"
	echo "ready to run"

	gcc -o ./linux/builds/Linux ./linux/Main.c -I./linux/header -L./linux/library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	echo "Linking Libraries"
	echo "Running for Linux"
	clear
	cd ./linux/builds && ./Linux
	
elif [ "$os" == "Darwin" ]; then
	rm -rf ./unix/objects/ ./unix/library/ ./unix/builds/ ./unix/receipts/
	echo "clearing directories"

	mkdir ./unix/library
	mkdir ./unix/builds
	mkdir ./unix/objects
	mkdir ./unix/receipts
	echo "creating Directories"

	gcc -c ./unix/source/FileIO/menu.c -o ./unix/objects/menu.o
	gcc -c ./unix/source/Interactions/Interactions.c -o ./unix/objects/Interactions.o
	gcc -c ./unix/source/FileIO/writer.c -o ./unix/objects/writer.o
	echo "Compiling IO Files"

	gcc -c ./unix/source/Customizations/Customize.c -o ./unix/objects/Customize.o
	gcc -c ./unix/source/Customizations/IO.c -o ./unix/objects/IO.o
	gcc -c ./unix/source/Customizations/List.c -o ./unix/objects/List.o
	echo "Compiling Customization Files"

	gcc -c ./unix/source/Basket/insert.c -o ./unix/objects/insert.o
	gcc -c ./unix/source/Basket/payment.c -o ./unix/objects/payment.o
	echo "Compiling Payment Files"

	ar rcs ./unix/library/lib_IO.dylib ./unix/objects/menu.o ./unix/objects/Interactions.o ./unix/objects/writer.o
	ar rcs ./unix/library/lib_CUSTOMIZE.dylib ./unix/objects/Customize.o ./unix/objects/IO.o ./unix/objects/List.o
	ar rcs ./unix/library/lib_BASKET.dylib ./unix/objects/insert.o
	ar rcs ./unix/library/lib_PAYMENT.dylib ./unix/objects/payment.o
	echo "Creating Libraries"
	echo "Ready to Run"

	gcc -o ./unix/builds/unix ./unix/Main.c -I./unix/header -L./unix/library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	echo "Linking Libraries"
	echo "Running for Unix"
	clear
	cd ./unix/builds && ./unix
fi