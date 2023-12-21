


cd windows
Remove-Item -Path ".\receipts" -Recurse 
Remove-Item -Path ".\library" -Recurse 
Remove-Item -Path ".\builds" -Recurse 
Remove-Item -Path ".\objects" -Recurse 
Write-Host "deleting directories"


mkdir receipts
mkdir library
mkdir builds
mkdir objects
Write-Host "Creating directories"





	gcc -c .\source\FileIO\menu.c -o .\objects\menu.o
	gcc -c .\source\Interactions\Interactions.c -o .\objects\Interactions.o
	gcc -c .\source\FileIO\writer.c -o .\objects\writer.o
	echo "compiling FileIO components"

	gcc -c .\source\Customizations\Customize.c -o .\objects\Customize.o
	gcc -c .\source\Customizations\IO.c -o .\objects\IO.o
	gcc -c .\source\Customizations\List.c -o .\objects\List.o
	echo "compiling customizations components"

	gcc -c .\source\Basket\insert.c -o .\objects\insert.o
	gcc -c .\source\Basket\payment.c -o .\objects\payment.o
	echo "compiling payment components"

	ar rcs .\library\lib_IO.a .\objects\menu.o .\objects\Interactions.o .\objects\writer.o
	ar rcs .\library\lib_CUSTOMIZE.a .\objects\Customize.o .\objects\IO.o .\objects\List.o
	ar rcs .\library\lib_BASKET.a .\objects\insert.o
	ar rcs .\library\lib_PAYMENT.a .\objects\payment.o
	echo "creating libraries"
	echo "ready to run"

	gcc -o .\builds\Windows.exe .\Main.c -I.\header -L.\library -l_IO -l_CUSTOMIZE -l_BASKET -l_PAYMENT
	echo "Linking Libraries"
	echo "Running for Windows"
	
	cd .\builds ; .\Windows.exe

	cd ..\..\
