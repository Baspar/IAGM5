# !/bin/bash
function pseudoClean(){
    rm -rf src/*.log src/*.aux src/*.toc src/*.out
}

rm -rf doc/*.pdf src/diagrams/*.png
[[ "$1" == "clean" ]] && echo "Supression fichier OK" && exit

echo "Generation png"
for i in src/diagrams/*.uml
do
    echo "Generation de $i"
    #java -jar src/diagrams/plantuml.jar $i
done
echo "Latex"
cd src
pdflatex ArtificialIntelligence.tex
pdflatex ArtificialIntelligence.tex
cd ..
mv src/*.pdf doc/

pseudoClean
