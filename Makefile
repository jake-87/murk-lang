CC='clang'
CFLAGS= -Wall -g
TARGET='murk'
CORE != ls *.core
BUILDFILES != ls src/*.c
build :
	$(CC) $(CFLAGS) $(BUILDFILES) -o $(TARGET)
clean:
	rm -f $(TARGET) $(CORE)
tests:
	./$(TARGET) compile tests/test1.murk
