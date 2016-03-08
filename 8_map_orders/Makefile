#CXX=g++
#CXXFLAGS= -Wall -Werror -std=c++11 -O3

all: freqtable2

freqtable2: ../7_map/frequency.h frequency_v2.h main.cpp
	$(CXX) $(CXXFLAGS) -DMAP_TEST_OPERATORS_SENSITIVE main.cpp -o freqtable2;

freqtable_mos: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_OPERATORS_SENSITIVE main.cpp -o freqtable2;

freqtable_moi: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_OPERATORS_INSENSITIVE main.cpp -o freqtable2;

freqtable_uos: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_OPERATORS_SENSITIVE main.cpp -o freqtable2;

freqtable_uoi: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_OPERATORS_INSENSITIVE main.cpp -o freqtable2;

freqtable_mls: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_LAMBDAS_SENSITIVE main.cpp -o freqtable2;

freqtable_mli: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_LAMBDAS_INSENSITIVE main.cpp -o freqtable2;

freqtable_uls: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_LAMBDAS_SENSITIVE main.cpp -o freqtable2;

freqtable_uli: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_LAMBDAS_INSENSITIVE main.cpp -o freqtable2;

freqtable_mfs: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_FPOINTERS_SENSITIVE main.cpp -o freqtable2;

freqtable_mfi: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DMAP_TEST_FPOINTERS_INSENSITIVE main.cpp -o freqtable2;

freqtable_ufs: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_FPOINTERS_SENSITIVE main.cpp -o freqtable2;

freqtable_ufi: clean ../7_map/frequency.h frequency_v2.h main.cpp
	@$(CXX) $(CXXFLAGS) -DHASH_MAP_TEST_FPOINTERS_INSENSITIVE main.cpp -o freqtable2;

tests:
	@make freqtable_uos test > /dev/null;
	@make freqtable_uls test > /dev/null;
	@make freqtable_ufs test > /dev/null;
	@make freqtable_uoi test > /dev/null;
	@make freqtable_uli test > /dev/null;
	@make freqtable_ufi test > /dev/null;
	@make freqtable_mos test > /dev/null;
	@make freqtable_mls test > /dev/null;
	@make freqtable_mfs test > /dev/null;
	@make freqtable_moi test > /dev/null;
	@make freqtable_mli test > /dev/null;
	@make freqtable_mfi test > /dev/null;
	@echo "Done";

test:
	@./freqtable2 	../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					../5_stl/1.html ../5_stl/1.html ../5_stl/1.html ../5_stl/1.html \
					> /dev/null

clean:
	-rm -f freqtable2;
