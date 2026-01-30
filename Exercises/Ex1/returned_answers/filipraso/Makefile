TEX      = pdflatex
BIB      = bibtex
MAIN     = main
TEXFLAGS = -interaction=nonstopmode -halt-on-error

all: $(MAIN).pdf

$(MAIN).pdf: $(MAIN).tex refs.bib
	$(TEX) $(TEXFLAGS) $(MAIN).tex
	$(BIB) $(MAIN)
	$(TEX) $(TEXFLAGS) $(MAIN).tex
	$(TEX) $(TEXFLAGS) $(MAIN).tex

clean:
	rm -f *.aux *.bbl *.blg *.log *.out *.toc *.lof *.lot

distclean: clean
	rm -f $(MAIN).pdf

.PHONY: all clean distclean
