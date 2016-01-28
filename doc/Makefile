all: diags texArtificialIntelligence mvdoc pseudoclean

toggle:
	sed -i 's/Rapport/Pré-Rapport/g; s/Pré-Pré-//g' src/ressources/vocabulaire/vocabulaire.sty

diags:
	java -jar src/diagrams/plantuml.jar src/diagrams/**.uml

texArtificialIntelligence:
	cd src; pdflatex ArtificialIntelligence.tex;pdflatex ArtificialIntelligence.tex; cd ..

mvdoc:
	mv src/*.pdf doc/

pseudoclean:
	rm -rf src/*.log src/*.aux src/*.toc src/*.out

clean: pseudoclean
	rm -rf doc/*.pdf 
