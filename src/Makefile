BD=../build/
QMAKE=$(BD)
CFLAGS=-c# -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./
SRC=data_storage.cpp network.cpp s21_matrix_oop.cpp
OBJ=$(addprefix $(BD),$(SRC:.cpp=.o))
EXE=$(QMAKE)MLP.app/Contents/MacOS/MLP
APP=$(QMAKE)MLP.app
APPDIR=$(HOME)/Applications/MLP/
APP_EXE=$(APPDIR)MLP.app/Contents/MacOS/MLP
CC=g++

all: install
	$(APP_EXE)

build: $(BD)qmake.pro
	cd $(QMAKE); qmake qmake.pro
	make -C $(QMAKE)

arrange:
	rm -f $(QMAKE)qmake.*
	cd $(QMAKE); qmake -project ../src/; mv build.pro ../src/qmake.pro

./$(BD)qmake.pro:
	cp qmake.pro $(QMAKE)

./$(BD)%.o: */%.cpp
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

install: build 
	@mkdir $(APPDIR) || echo "Directory already exists. Skip."
	cp -rf bmp/ $(APPDIR)bmp/
	cp -rf resources/ $(APPDIR)resources/
	cp -rf weights/ $(APPDIR)weights/
	cp -rf datasets/ $(APPDIR)datasets/
	cp -rf manual/ $(APPDIR)manual/
	cp -rf $(APP) $(APPDIR)
	make clean

uninstall:
	rm -rf $(APPDIR)
	rm -rf $(HOME)/Applications/MLP.tar.gz

dvi:
	@open $(APPDIR)manual/manual.html || echo "Please, install application first!"

dist:
	tar -cvf $(APPDIR)../MLP.tar $(APPDIR)
	gzip $(APPDIR)../MLP.tar

#### TEST #####
test: clean $(BD)main_test_exe
	./$(BD)main_test_exe

./$(BD)main_test_exe: $(OBJ) $(BD)main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS)

#### GCOV #####
gcov_report: gcov_build $(BD)main_test.o
	$(CC) $(LDFLAGS) $(LCOVFLAGS) $(OBJ) $(BD)main_test.o -o $(BD)main_gcov_exe $(GTESTFLAGS)
	./$(BD)main_gcov_exe
	# mv *.gcda *.gcno ./$(BD)
	lcov -t "gcov_report" -o $(BD)gcov_report.info -c -d ./$(BD)
	genhtml -o $(BD)report $(BD)gcov_report.info
	open $(BD)report/$(PWD)/model/index.html

gcov_build:
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/data_storage.cpp -o $(BD)dataStorage.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/s21_matrix_oop.cpp -o $(BD)s21_matrix_oop.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/network.cpp -o $(BD)network.o

clean:
	rm -rf ./$(BD)*.o ./$(BD)*_exe ./$(BD)*.dSYM ./$(BD)report
	rm -rf ./$(BD)*.gcno ./$(BD)*.gcda ./$(BD)*.info report/
	test -f $(QMAKE)Makefile && make distclean -C $(QMAKE) || printf ""
	rm -f ./$(BD)qmake.pro

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

cpplint:
	cp ../materials/linters/CPPLINT.cfg . && python3 ../materials/linters/cpplint.py --filter=-runtime/references,-build/c++11 --exclude=view/qcustomplot.h --exclude=view/qcustomplot.cpp --extensions=cpp */*.cpp */*.h; rm -f CPPLINT.cfg

leaks:
	leaks --atExit -- ./$(BD)main_test_exe

valgrind:
	valgrind --undef-value-errors=no --log-file=valgrind-out.txt ./$(BD)main_test_exe
