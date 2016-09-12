SUBDIRS = src tests

.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS):
	        $(MAKE) -C $@

tests: src

clean:
	rm -f src/*.{o,a} tests/*.o tests/check_roman

check:
	tests/check_roman
