QMAKE=qmake

all:
		cd src && $(QMAKE) -o Makefile && make
		mv src/blockeditor ./blockeditor



run: all
		cd src
		./blockeditor


doxygen:
		-mkdir doc
		doxygen Doxyfile

pack:
		zip xkocij01-xzubal04.zip src/* Doxyfile Makefile README.md

clean:
		rm -f src/Makefile
		rm -f src/blockeditor
		rm -f src/*.o
		rm doc/* -rf
		rm -f src/moc_blockscene.cpp
		rm -f src/moc_mainwindow.cpp
		rm -f src/moc_textblock.cpp
