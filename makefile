# Make file for compiling the game
GPP = g++

CPPLIBS  = -lSDL -lSDL_image
CPPFILES = main.cpp Mol/*.cpp Mol/Nave/*.cpp Mol/Hud/*.cpp

# Executable name
TARGET = jogo_nave

all: $(TARGET)

$(TARGET): main.cpp
	$(GPP) $(CPPFILES) -o $(TARGET) $(CPPLIBS)

clean:
	$(RM) $(TARGET)
