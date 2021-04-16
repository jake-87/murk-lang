CC='clang'
CFLAGS= -Wall
TARGET='murk'
BUILDFILES != ls src/*.c
build :
	$(CC) $(CFLAGS) $(BUILDFILES) -o $(TARGET)
clean:
	rm -f $(TARGET)