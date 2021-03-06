SUBDIR   = external Toolbox RootTools PlotTools Example Tools lib

all: $(SUBDIR)
	for DIR in $(SUBDIR); do \
		$(MAKE) $(MFLAGS) -C $$DIR || exit 1; \
	done

install: $(SUBDIR)
	for DIR in $(SUBDIR); do \
		$(MAKE) $(MFLAGS) -C $$DIR install || exit 1; \
	done

clean: $(SUBDIR)
	for DIR in $(SUBDIR); do \
		$(MAKE) $(MFLAGS) -C $$DIR clean || exit 1; \
	done

doc:
	doxygen doxygen.cfg
