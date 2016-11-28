OUTFILE := fileCounter

SDIR=src
ODIR=obj

CPP_FILES := $(wildcard $(SDIR)/*.cpp)
OBJ_FILES := $(addprefix $(ODIR)/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lpthread
CC_FLAGS :=

$(OUTFILE): $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	g++ $(CC_FLAGS) -c -o $@ $<


.PHONY: clean
clean:
	rm -f obj/*.o $(OUTFILE)
