UML=$(wildcard src/diagrams/*.uml)
PNG=$(UML:.uml=.png)

all: $(PNG) texArtificialIntelligence mvdoc pseudoclean

toggle:
	sed -i 's/Rapport/Pré-Rapport/g; s/Pré-Pré-//g' src/ressources/vocabulaire/vocabulaire.sty

%.png: %.uml
	java -jar src/diagrams/plantuml.jar $<

texArtificialIntelligence:
	cd src; pdflatex ArtificialIntelligence.tex;pdflatex ArtificialIntelligence.tex; cd ..

mvdoc:
	mv src/*.pdf doc/

pseudoclean:
	rm -rf src/*.log src/*.aux src/*.toc src/*.out

clean: pseudoclean
	rm -rf doc/*.pdf src/diagrams/*.png
