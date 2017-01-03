CCDIR = c:\Program Files (x86)\Mita-Teknik\Development Toolbox\mingw-4.5.0\bin
RMDIR = C:/Program Files (x86)/Mita-Teknik/Development Toolbox/tools

CC = $(CCDIR)/gcc
RM = $(RMDIR)/rm

obj = wind_turbine.o

all: $(obj)
	@echo --- making ModelTest ---
	$(CC) -o wind_turbine $(obj)

build_o: $(obj)
	
wind_turbine.o: wind_turbine.h wind_turbine.cpp
	$(CC) -c wind_turbine.cpp
	
.PHONY : clean

clean:
	-$(RM) wind_turbine $(obj)