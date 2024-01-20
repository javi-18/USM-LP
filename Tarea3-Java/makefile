#MAKEFILE JAVA

all: default run clean

JFLAGS = -g
JC = javac
JVM = java
MAIN = JavaHack
FILE = 

.SUFFIXES: .java .class

.java.class: 
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	JavaHack.java \
	Equipamiento.java \
	Item.java \
	Jugador.java \
	Personaje.java \
	Visible.java \
	Vacia.java \
	Mundo.java \
	Arma.java 


default: classes

classes: $(CLASSES:.java=.class)

run: $(MAIN).class
	$(JVM) $(MAIN) 

clean: 
	$(RM) *.class