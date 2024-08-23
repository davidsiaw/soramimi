INCDIRS:=
LIBDIRS:=

REQUIRED_TARGETS:=
CLEAN_TARGETS:=

INCLUDE_FLAGS:=
LIBRARY_FLAGS:=
LINKER_FLAGS:=$(shell sdl2-config --libs --cflags) -lSDL2_image

SOURCES:=$(shell find src -type f -name '*.cpp')
OBJECTS:=$(patsubst src/%.cpp,obj/%.o,$(SOURCES))

MORECFLAGS:=-Wall -Werror -Wpedantic -g
MORECPPFLAGS:=$(MORECFLAGS)  -std=c++11

CFLAGS:=$(CFLAGS) $(MORECFLAGS)
CXXFLAGS:=$(CPPFLAGS) $(MORECPPFLAGS)

OUTPUTFILE:=main

all: bin/$(OUTPUTFILE)

bin:
	mkdir -p bin

obj:
	mkdir -p obj

lib:
	mkdir -p lib

bin/$(OUTPUTFILE): bin $(OBJECTS) $(REQUIRED_TARGETS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(INCLUDE_FLAGS) $(LIBRARY_FLAGS) $(LINKER_FLAGS)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

obj/%.o: src/%.cpp $(REQUIRED_TARGETS)
	@mkdir -p obj
	$(CXX) $(CFLAGS) -c $(INCLUDE_FLAGS) $< -o $@
	@# generate dependency info that can be used next time
	@$(CXX) $(CXXFLAGS) -MM -MT $@ $(INCLUDE_FLAGS) $< > obj/$*.d
	@mv -f obj/$*.d obj/$*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < obj/$*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> obj/$*.d
	@rm -f obj/$*.d.tmp

clean: $(CLEAN_TARGETS)
	rm -rf bin
	rm -rf obj

.PHONY: clean run
